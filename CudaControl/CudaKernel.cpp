// CudaKernel.cpp : Implementation of CCudaKernel

#include "stdafx.h"
#include "CudaKernel.h"
#include <winerror.h>
#include <float.h>
#include <comutil.h>

#define MAX_OUTPUT 16

HRESULT CCudaKernel::FinalConstruct()
{
	return S_OK;
}

void CCudaKernel::FinalRelease()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	float fFinalRelease = 1.0;
	double dfFinalRelease = 1.0;

	if (m_pfnInvokeFloat != NULL)
		(*m_pfnInvokeFloat)(0, CUDA_DLL_CLEANUP, &fFinalRelease, 1, NULL, 0, NULL, 0);

	if (m_pfnInvokeDouble != NULL)
		(*m_pfnInvokeDouble)(0, CUDA_DLL_CLEANUP, &dfFinalRelease, 1, NULL, 0, NULL, 0);

	if (m_hCudaDLL != NULL)
	{
		Sleep(0);
		FreeLibrary(m_hCudaDLL);
		m_hCudaDLL = NULL;
	}

	m_pfnInvokeFloat = NULL;
	m_pfnInvokeDouble = NULL;
	m_pfnInvokeFloatEx = NULL;
	m_pfnInvokeDoubleEx = NULL;
	m_pfnQueryString = NULL;
	m_pfnQueryBytes = NULL;
	m_pfnSetBytes = NULL;
	m_pfnQueryStringFloatEx = NULL;
	m_pfnQueryStringDoubleEx = NULL;	
}


// CCudaKernel

STDMETHODIMP CCudaKernel::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ICudaKernel
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CCudaKernel::Load(BSTR bstrKernelDLLName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString strDLL = bstrKernelDLLName;

	TRY
	{
		if (m_hCudaDLL != NULL)
		{
			if (m_pfnInvokeFloat != NULL)
				m_pfnInvokeFloat(0, CUDA_DLL_CLEANUP, NULL, 0, NULL, 0, NULL, 0);

			if (m_pfnInvokeDouble != NULL)
				m_pfnInvokeDouble(0, CUDA_DLL_CLEANUP, NULL, 0, NULL, 0, NULL, 0);

			FreeLibrary(m_hCudaDLL);
			m_hCudaDLL = NULL;
		}

		m_hCudaDLL = LoadLibrary(strDLL);
		if (m_hCudaDLL == NULL)
		{
			DWORD dwErr = GetLastError();
			AfxThrowOleException(HRESULT_FROM_WIN32(dwErr));
		}

		m_pfnInvokeFloat = (LPFNDLLINVOKEFLOAT)GetProcAddress(m_hCudaDLL, SZDLL_INVOKEFLOAT);
		if (m_pfnInvokeFloat == NULL)
			AfxThrowOleException(HRESULT_FROM_WIN32(GetLastError()));

		m_pfnInvokeDouble = (LPFNDLLINVOKEDOUBLE)GetProcAddress(m_hCudaDLL, SZDLL_INVOKEDOUBLE);
		if (m_pfnInvokeDouble == NULL)
			AfxThrowOleException(HRESULT_FROM_WIN32(GetLastError()));

		m_pfnInvokeFloatEx = (LPFNDLLINVOKEFLOATEX)GetProcAddress(m_hCudaDLL, SZDLL_INVOKEFLOATEX);
		m_pfnInvokeDoubleEx = (LPFNDLLINVOKEDOUBLEEX)GetProcAddress(m_hCudaDLL, SZDLL_INVOKEDOUBLEEX);
		m_pfnInvokeFloatEx2 = (LPFNDLLINVOKEFLOATEX2)GetProcAddress(m_hCudaDLL, SZDLL_INVOKEFLOATEX2);
		m_pfnInvokeDoubleEx2 = (LPFNDLLINVOKEDOUBLEEX2)GetProcAddress(m_hCudaDLL, SZDLL_INVOKEDOUBLEEX2);

		m_pfnQueryString = (LPFNDLLQUERYSTRING)GetProcAddress(m_hCudaDLL, SZDLL_QUERYSTRING);
		if (m_pfnQueryString == NULL)
			AfxThrowOleException(HRESULT_FROM_WIN32(GetLastError()));

		m_pfnQueryBytes = (LPFNDLLQUERYBYTES)GetProcAddress(m_hCudaDLL, SZDLL_QUERYBYTES);
		m_pfnSetBytes = (LPFNDLLSETBYTES)GetProcAddress(m_hCudaDLL, SZDLL_SETBYTES);

		m_pfnQueryStringFloatEx = (LPFNDLLQUERYSTRINGFLOATEX)GetProcAddress(m_hCudaDLL, SZDLL_QUERYSTRINGFLOATEX);
		m_pfnQueryStringDoubleEx = (LPFNDLLQUERYSTRINGDOUBLEEX)GetProcAddress(m_hCudaDLL, SZDLL_QUERYSTRINGDOUBLEEX);
	}
	CATCH_ALL(e)
	{
		if (m_hCudaDLL != NULL)
		{
			FreeLibrary(m_hCudaDLL);
			m_hCudaDLL = NULL;
		}

		m_pfnInvokeFloat = NULL;
		m_pfnInvokeDouble = NULL;
		m_pfnInvokeFloatEx = NULL;
		m_pfnInvokeDoubleEx = NULL;
		m_pfnInvokeFloatEx2 = NULL;
		m_pfnInvokeDoubleEx2 = NULL;
		m_pfnQueryString = NULL;
		m_pfnQueryBytes = NULL;
		m_pfnSetBytes = NULL;

		CComBSTR str;

		str = "Failed to load '";
		str += bstrKernelDLLName;
		str += "'!";

		return Error(str, IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CCudaKernel::RunFloat(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY * rgInput, SAFEARRAY ** prgOutput)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	float rgOutput1[MAX_OUTPUT];
	float *pfInput = NULL;
	LONG lInput = 0;
	float *pfOutput = NULL;
	LONG lOutput = 0;
	LONG lLBound = 0;
	LONG lUBound = 0;
	LONG lErr = 0;
	TCHAR szErr[MAX_ERROR + 1];
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		memset(szErr, 0, sizeof(TCHAR) * (MAX_ERROR + 1));

	//---------------------------------------
	//	Verify the state and parameters.
	//---------------------------------------

	if (m_pfnInvokeFloat == NULL)
		AfxThrowOleException(HRESULT_FROM_WIN32(ERROR_BAD_DLL_ENTRYPOINT));


	//---------------------------------------
	//	If there is input data, extract it
	//	from the input safearray.
	//---------------------------------------

	if (rgInput != NULL)
	{
		hr = SafeArrayAccessData(rgInput, (LPVOID*)&pfInput);
		if (FAILED(hr))
			AfxThrowOleException(hr);

		hr = SafeArrayGetLBound(rgInput, 1, &lLBound);
		if (FAILED(hr))
			AfxThrowOleException(hr);

		hr = SafeArrayGetUBound(rgInput, 1, &lUBound);
		if (FAILED(hr))
			AfxThrowOleException(hr);

		lInput = lUBound - lLBound + 1;
	}

	//---------------------------------------
	//	Call the kernel DLL.
	//---------------------------------------

	rgOutput1[0] = FLT_MAX - 1;
	pfOutput = rgOutput1;
	lOutput = MAX_OUTPUT;

	szErr[MAX_ERROR] = (TCHAR)NULL;
	lErr = (*m_pfnInvokeFloat)(lKernelIdx, lFunctionIdx, pfInput, lInput, &pfOutput, &lOutput, szErr, MAX_ERROR);
	if (lErr != 0)
		AfxThrowOleDispatchException((WORD)lErr, szErr);

	//---------------------------------------
	//	Release the input data.
	//---------------------------------------

	if (pfInput != NULL && rgInput != NULL)
	{
		SafeArrayUnaccessData(rgInput);
		pfInput = NULL;
	}

	//---------------------------------------
	//	Convert the output data into a new
	//	safearray.
	//---------------------------------------

	if (lOutput > 0 && (pfOutput != rgOutput1 || rgOutput1[0] != FLT_MAX - 1))
	{
		rgOutput = SafeArrayCreateVector(VT_R4, 0, lOutput);

		if (rgOutput == NULL)
			AfxThrowMemoryException();

		for (LONG lIdx = 0; lIdx<lOutput; lIdx++)
		{
			float fVal = pfOutput[lIdx];

			hr = SafeArrayPutElement(rgOutput, &lIdx, &fVal);
			if (FAILED(hr))
				AfxThrowOleException(hr);
		}
	}

	*prgOutput = rgOutput;
	rgOutput = NULL;

	if (pfOutput != NULL && pfOutput != rgOutput1)
	{
		(*m_pfnInvokeFloat)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
		pfOutput = NULL;
	}
	}
	CATCH(COleDispatchException, e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeFloat)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_ICudaKernel, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeFloat)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Running CUDA Kernel Function", IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

		return S_OK;
}

STDMETHODIMP CCudaKernel::RunFloatEx(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY * rgInput, BSTR bstrInput, SAFEARRAY ** prgOutput)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	float rgOutput1[MAX_OUTPUT];
	float *pfInput = NULL;
	LONG lInput = 0;
	float *pfOutput = NULL;
	LONG lOutput = 0;
	LONG lLBound = 0;
	LONG lUBound = 0;
	LONG lErr = 0;
	TCHAR szErr[MAX_ERROR+1];
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		memset(szErr, 0, sizeof(TCHAR) * (MAX_ERROR+1));

		//---------------------------------------
		//	Verify the state and parameters.
		//---------------------------------------

		if (m_pfnInvokeFloatEx == NULL)
			AfxThrowOleException(HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED));


		//---------------------------------------
		//	If there is input data, extract it
		//	from the input safearray.
		//---------------------------------------

		if (rgInput != NULL)
		{
			hr = SafeArrayAccessData(rgInput, (LPVOID*)&pfInput);
			if (FAILED( hr ))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rgInput, 1, &lLBound);
			if (FAILED( hr ))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rgInput, 1, &lUBound);
			if (FAILED( hr ))
				AfxThrowOleException(hr);

			lInput = lUBound - lLBound + 1;
		}

		//---------------------------------------
		//	If there is a string input specified
		//	convert it to an LPTSTR.
		//---------------------------------------

		LPTSTR pszInput = NULL;
		_bstr_t* pbstr = NULL;

		if (bstrInput != NULL)
		{
			pbstr = new _bstr_t(bstrInput);
			pszInput = *pbstr;
		}

		//---------------------------------------
		//	Call the kernel DLL.
		//---------------------------------------

		rgOutput1[0] = FLT_MAX - 1;
		pfOutput = rgOutput1;
		lOutput = MAX_OUTPUT;

		szErr[MAX_ERROR] = (TCHAR)NULL;
		lErr = (*m_pfnInvokeFloatEx)(lKernelIdx, lFunctionIdx, pfInput, lInput, pszInput, &pfOutput, &lOutput, szErr, MAX_ERROR);

		if (pbstr != NULL)
			free(pbstr);

		if (lErr != 0)
			AfxThrowOleDispatchException((WORD)lErr, szErr);

		//---------------------------------------
		//	Release the input data.
		//---------------------------------------

		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		//---------------------------------------
		//	Convert the output data into a new
		//	safearray.
		//---------------------------------------

		if (lOutput > 0 && (pfOutput != rgOutput1 || rgOutput1[0] != FLT_MAX - 1))
		{
			rgOutput = SafeArrayCreateVector(VT_R4, 0, lOutput);

			if (rgOutput == NULL)
				AfxThrowMemoryException();

			for (LONG lIdx = 0; lIdx<lOutput; lIdx++)
			{
				float fVal = pfOutput[lIdx];

				hr = SafeArrayPutElement(rgOutput, &lIdx, &fVal);
				if (FAILED( hr ))
					AfxThrowOleException(hr);
			}
		}

		*prgOutput = rgOutput;
		rgOutput = NULL;

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeFloat)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}
	}
	CATCH(COleDispatchException, e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeFloat)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_ICudaKernel, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeFloat)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Running CUDA Kernel Function", IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CCudaKernel::RunFloatEx2(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY* rgInput, SAFEARRAY* rglInput, SAFEARRAY** prgOutput)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	float rgOutput1[MAX_OUTPUT];
	float* pfInput = NULL;
	LONG lInput = 0;
	LONGLONG* plInput = NULL;
	LONG llInput = 0;
	float* pfOutput = NULL;
	LONG lOutput = 0;
	LONG lLBound = 0;
	LONG lUBound = 0;
	LONG llLBound = 0;
	LONG llUBound = 0;
	LONG lErr = 0;
	TCHAR szErr[MAX_ERROR + 1];
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		memset(szErr, 0, sizeof(TCHAR) * (MAX_ERROR + 1));

		//---------------------------------------
		//	Verify the state and parameters.
		//---------------------------------------

		if (m_pfnInvokeFloatEx2 == NULL)
			AfxThrowOleException(HRESULT_FROM_WIN32(ERROR_BAD_DLL_ENTRYPOINT));


		//---------------------------------------
		//	If there is input data, extract it
		//	from the input safearray.
		//---------------------------------------

		if (rgInput != NULL)
		{
			hr = SafeArrayAccessData(rgInput, (LPVOID*)&pfInput);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rgInput, 1, &lLBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rgInput, 1, &lUBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			lInput = lUBound - lLBound + 1;
		}

		if (rglInput != NULL)
		{
			hr = SafeArrayAccessData(rglInput, (LPVOID*)&plInput);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rglInput, 1, &llLBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rglInput, 1, &llUBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			llInput = llUBound - llLBound + 1;
		}

		//---------------------------------------
		//	Call the kernel DLL.
		//---------------------------------------

		rgOutput1[0] = FLT_MAX - 1;
		pfOutput = rgOutput1;
		lOutput = MAX_OUTPUT;

		szErr[MAX_ERROR] = (TCHAR)NULL;
		lErr = (*m_pfnInvokeFloatEx2)(lKernelIdx, lFunctionIdx, pfInput, lInput, plInput, llInput, &pfOutput, &lOutput, szErr, MAX_ERROR);
		if (lErr != 0)
			AfxThrowOleDispatchException((WORD)lErr, szErr);

		//---------------------------------------
		//	Release the input data.
		//---------------------------------------

		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (plInput != NULL && rglInput != NULL)
		{
			SafeArrayUnaccessData(rglInput);
			plInput = NULL;
		}

		//---------------------------------------
		//	Convert the output data into a new
		//	safearray.
		//---------------------------------------

		if (lOutput > 0 && (pfOutput != rgOutput1 || rgOutput1[0] != FLT_MAX - 1))
		{
			rgOutput = SafeArrayCreateVector(VT_R4, 0, lOutput);

			if (rgOutput == NULL)
				AfxThrowMemoryException();

			for (LONG lIdx = 0; lIdx < lOutput; lIdx++)
			{
				float fVal = pfOutput[lIdx];

				hr = SafeArrayPutElement(rgOutput, &lIdx, &fVal);
				if (FAILED(hr))
					AfxThrowOleException(hr);
			}
		}

		*prgOutput = rgOutput;
		rgOutput = NULL;

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeFloat)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}
	}
	CATCH(COleDispatchException, e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (plInput != NULL && rglInput != NULL)
		{
			SafeArrayUnaccessData(rglInput);
			plInput = NULL;
		}

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeFloat)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_ICudaKernel, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (plInput != NULL && rglInput != NULL)
		{
			SafeArrayUnaccessData(rglInput);
			plInput = NULL;
		}

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeFloat)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Running CUDA Kernel Function", IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}


STDMETHODIMP CCudaKernel::RunDouble(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY * rgInput, SAFEARRAY ** prgOutput)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	double rgOutput1[MAX_OUTPUT];
	double *pfInput = NULL;
	LONG lInput = 0;
	double *pfOutput = NULL;
	LONG lOutput = 0;
	LONG lLBound = 0;
	LONG lUBound = 0;
	LONG lErr = 0;
	TCHAR szErr[MAX_ERROR+1];
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		memset(szErr, 0, sizeof(TCHAR) * (MAX_ERROR+1));

		//---------------------------------------
		//	Verify the state and parameters.
		//---------------------------------------

		if (m_pfnInvokeDouble == NULL)
			AfxThrowOleException(HRESULT_FROM_WIN32(ERROR_BAD_DLL_ENTRYPOINT));


		//---------------------------------------
		//	If there is input data, extract it
		//	from the input safearray.
		//---------------------------------------

		if (rgInput != NULL)
		{
			hr = SafeArrayAccessData(rgInput, (LPVOID*)&pfInput);
			if (FAILED( hr ))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rgInput, 1, &lLBound);
			if (FAILED( hr ))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rgInput, 1, &lUBound);
			if (FAILED( hr ))
				AfxThrowOleException(hr);

			lInput = lUBound - lLBound + 1;
		}

		//---------------------------------------
		//	Call the kernel DLL.
		//---------------------------------------

		rgOutput1[0] = DBL_MAX - 1;
		pfOutput = rgOutput1;
		lOutput = MAX_OUTPUT;

		szErr[MAX_ERROR] = (TCHAR)NULL;
		lErr = (*m_pfnInvokeDouble)(lKernelIdx, lFunctionIdx, pfInput, lInput, &pfOutput, &lOutput, szErr, MAX_ERROR);
		if (lErr != 0)
			AfxThrowOleDispatchException((WORD)lErr, szErr);

		//---------------------------------------
		//	Release the input data.
		//---------------------------------------

		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		//---------------------------------------
		//	Convert the output data into a new
		//	safearray.
		//---------------------------------------

		if (lOutput > 0 && (pfOutput != rgOutput1 || rgOutput1[0] != DBL_MAX - 1))
		{
			rgOutput = SafeArrayCreateVector(VT_R8, 0, lOutput);

			if (rgOutput == NULL)
				AfxThrowMemoryException();

			for (LONG lIdx = 0; lIdx<lOutput; lIdx++)
			{
				double fVal = pfOutput[lIdx];

				hr = SafeArrayPutElement(rgOutput, &lIdx, &fVal);
				if (FAILED( hr ))
					AfxThrowOleException(hr);
			}
		}

		*prgOutput = rgOutput;
		rgOutput = NULL;

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeDouble)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}
	}
	CATCH(COleDispatchException, e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeDouble)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_ICudaKernel, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeDouble)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Running CUDA Kernel Function", IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CCudaKernel::RunDoubleEx(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY * rgInput, BSTR bstrInput, SAFEARRAY ** prgOutput)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	double rgOutput1[MAX_OUTPUT];
	double *pfInput = NULL;
	LONG lInput = 0;
	double *pfOutput = NULL;
	LONG lOutput = 0;
	LONG lLBound = 0;
	LONG lUBound = 0;
	LONG lErr = 0;
	TCHAR szErr[MAX_ERROR + 1];
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		memset(szErr, 0, sizeof(TCHAR) * (MAX_ERROR + 1));

		//---------------------------------------
		//	Verify the state and parameters.
		//---------------------------------------

		if (m_pfnInvokeDoubleEx == NULL)
			AfxThrowOleException(HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED));


		//---------------------------------------
		//	If there is input data, extract it
		//	from the input safearray.
		//---------------------------------------

		if (rgInput != NULL)
		{
			hr = SafeArrayAccessData(rgInput, (LPVOID*)&pfInput);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rgInput, 1, &lLBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rgInput, 1, &lUBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			lInput = lUBound - lLBound + 1;
		}


		//---------------------------------------
		//	If there is a string input specified
		//	convert it to an LPTSTR.
		//---------------------------------------

		LPTSTR pszInput = NULL;
		_bstr_t* pbstr = NULL;

		if (bstrInput != NULL)
		{
			pbstr = new _bstr_t(bstrInput);
			pszInput = *pbstr;
		}

		//---------------------------------------
		//	Call the kernel DLL.
		//---------------------------------------

		rgOutput1[0] = DBL_MAX - 1;
		pfOutput = rgOutput1;
		lOutput = MAX_OUTPUT;

		szErr[MAX_ERROR] = (TCHAR)NULL;
		lErr = (*m_pfnInvokeDoubleEx)(lKernelIdx, lFunctionIdx, pfInput, lInput, pszInput, &pfOutput, &lOutput, szErr, MAX_ERROR);

		if (pbstr != NULL)
			free(pbstr);

		if (lErr != 0)
			AfxThrowOleDispatchException((WORD)lErr, szErr);

		//---------------------------------------
		//	Release the input data.
		//---------------------------------------

		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		//---------------------------------------
		//	Convert the output data into a new
		//	safearray.
		//---------------------------------------

		if (lOutput > 0 && (pfOutput != rgOutput1 || rgOutput1[0] != DBL_MAX - 1))
		{
			rgOutput = SafeArrayCreateVector(VT_R8, 0, lOutput);

			if (rgOutput == NULL)
				AfxThrowMemoryException();

			for (LONG lIdx = 0; lIdx<lOutput; lIdx++)
			{
				double fVal = pfOutput[lIdx];

				hr = SafeArrayPutElement(rgOutput, &lIdx, &fVal);
				if (FAILED(hr))
					AfxThrowOleException(hr);
			}
		}

		*prgOutput = rgOutput;
		rgOutput = NULL;

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeDouble)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}
	}
	CATCH(COleDispatchException, e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeDouble)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_ICudaKernel, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}
		
		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeDouble)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Running CUDA Kernel Function", IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CCudaKernel::RunDoubleEx2(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY* rgInput, SAFEARRAY* rglInput, SAFEARRAY** prgOutput)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	double rgOutput1[MAX_OUTPUT];
	double* pfInput = NULL;
	LONG lInput = 0;
	LONGLONG* plInput = NULL;
	LONG llInput = 0;
	double* pfOutput = NULL;
	LONG lOutput = 0;
	LONG lLBound = 0;
	LONG lUBound = 0;
	LONG llLBound = 0;
	LONG llUBound = 0;
	LONG lErr = 0;
	TCHAR szErr[MAX_ERROR + 1];
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		memset(szErr, 0, sizeof(TCHAR) * (MAX_ERROR + 1));

		//---------------------------------------
		//	Verify the state and parameters.
		//---------------------------------------

		if (m_pfnInvokeDoubleEx2 == NULL)
			AfxThrowOleException(HRESULT_FROM_WIN32(ERROR_BAD_DLL_ENTRYPOINT));


		//---------------------------------------
		//	If there is input data, extract it
		//	from the input safearray.
		//---------------------------------------

		if (rgInput != NULL)
		{
			hr = SafeArrayAccessData(rgInput, (LPVOID*)&pfInput);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rgInput, 1, &lLBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rgInput, 1, &lUBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			lInput = lUBound - lLBound + 1;
		}

		if (rglInput != NULL)
		{
			hr = SafeArrayAccessData(rglInput, (LPVOID*)&plInput);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rglInput, 1, &llLBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rglInput, 1, &llUBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			llInput = llUBound - llLBound + 1;
		}

		//---------------------------------------
		//	Call the kernel DLL.
		//---------------------------------------

		rgOutput1[0] = DBL_MAX - 1;
		pfOutput = rgOutput1;
		lOutput = MAX_OUTPUT;

		szErr[MAX_ERROR] = (TCHAR)NULL;
		lErr = (*m_pfnInvokeDoubleEx2)(lKernelIdx, lFunctionIdx, pfInput, lInput, plInput, llInput, &pfOutput, &lOutput, szErr, MAX_ERROR);
		if (lErr != 0)
			AfxThrowOleDispatchException((WORD)lErr, szErr);

		//---------------------------------------
		//	Release the input data.
		//---------------------------------------

		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (plInput != NULL && rglInput != NULL)
		{
			SafeArrayUnaccessData(rglInput);
			plInput = NULL;
		}

		//---------------------------------------
		//	Convert the output data into a new
		//	safearray.
		//---------------------------------------

		if (lOutput > 0 && (pfOutput != rgOutput1 || rgOutput1[0] != DBL_MAX - 1))
		{
			rgOutput = SafeArrayCreateVector(VT_R8, 0, lOutput);

			if (rgOutput == NULL)
				AfxThrowMemoryException();

			for (LONG lIdx = 0; lIdx < lOutput; lIdx++)
			{
				double fVal = pfOutput[lIdx];

				hr = SafeArrayPutElement(rgOutput, &lIdx, &fVal);
				if (FAILED(hr))
					AfxThrowOleException(hr);
			}
		}

		*prgOutput = rgOutput;
		rgOutput = NULL;

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeDouble)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}
	}
	CATCH(COleDispatchException, e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeDouble)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_ICudaKernel, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (pfInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pfInput = NULL;
		}

		if (pfOutput != NULL && pfOutput != rgOutput1)
		{
			(*m_pfnInvokeDouble)(lKernelIdx, CUDA_DLL_FREEMEM, pfOutput, 0, NULL, NULL, szErr, MAX_ERROR);
			pfOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Running CUDA Kernel Function", IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

		return S_OK;
}


STDMETHODIMP CCudaKernel::QueryString(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY * rgInput, SAFEARRAY ** prgOutput)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	LONG *plInput = NULL;
	LONG lInput = 0;
	LPTSTR pstrOutput = NULL;
	LONG lOutput = 1;
	LONG lLBound = 0;
	LONG lUBound = 0;
	LONG lErr = 0;
	TCHAR szErr[MAX_ERROR+1];
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		memset(szErr, 0, sizeof(TCHAR) * (MAX_ERROR+1));

		//---------------------------------------
		//	Verify the state and parameters.
		//---------------------------------------

		if (m_pfnQueryString == NULL)
			AfxThrowOleException(HRESULT_FROM_WIN32(ERROR_BAD_DLL_ENTRYPOINT));


		//---------------------------------------
		//	If there is input data, extract it
		//	from the input safearray.
		//---------------------------------------

		if (rgInput != NULL)
		{
			hr = SafeArrayAccessData(rgInput, (LPVOID*)&plInput);
			if (FAILED( hr ))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rgInput, 1, &lLBound);
			if (FAILED( hr ))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rgInput, 1, &lUBound);
			if (FAILED( hr ))
				AfxThrowOleException(hr);

			lInput = lUBound - lLBound + 1;
		}

		//---------------------------------------
		//	Call the kernel DLL.
		//---------------------------------------

		szErr[MAX_ERROR] = (TCHAR)NULL;
		lErr = (*m_pfnQueryString)(lKernelIdx, lFunctionIdx, plInput, lInput, &pstrOutput, szErr, MAX_ERROR);
		if (lErr != 0)
			AfxThrowOleDispatchException((WORD)lErr, szErr);

		//---------------------------------------
		//	Release the input data.
		//---------------------------------------

		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		//---------------------------------------
		//	Convert the output data into a new
		//	safearray.
		//---------------------------------------

		rgOutput = SafeArrayCreateVector(VT_BSTR, 0, 1);

		if (rgOutput == NULL)
			AfxThrowMemoryException();

		BSTR bstr = SysAllocString(pstrOutput);
		LONG lIdx = 0;

		hr = SafeArrayPutElement(rgOutput, &lIdx, bstr);
		SysFreeString(bstr);

		if (FAILED( hr ))
			AfxThrowOleException(hr);

		*prgOutput = rgOutput;
		rgOutput = NULL;

		if (pstrOutput != NULL)
		{
			(*m_pfnQueryString)(lKernelIdx, CUDA_DLL_FREEMEM, NULL, NULL, &pstrOutput, szErr, MAX_ERROR);
			pstrOutput = NULL;
		}
	}
	CATCH(COleDispatchException, e)
	{
		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		if (pstrOutput != NULL)
		{
			(*m_pfnQueryString)(lKernelIdx, CUDA_DLL_FREEMEM, NULL, NULL, &pstrOutput, szErr, MAX_ERROR);
			pstrOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_ICudaKernel, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		if (pstrOutput != NULL)
		{
			(*m_pfnQueryString)(lKernelIdx, CUDA_DLL_FREEMEM, NULL, NULL, &pstrOutput, szErr, MAX_ERROR);
			pstrOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Running CUDA Kernel Function", IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CCudaKernel::QueryStringFloatEx(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY* rgInput, SAFEARRAY** prgOutput)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	LONG* plInput = NULL;
	LONG lInput = 0;
	LPTSTR pstrOutput = NULL;
	LONG lOutput = 1;
	LONG lLBound = 0;
	LONG lUBound = 0;
	LONG lErr = 0;
	TCHAR szErr[MAX_ERROR + 1];
	TCHAR szOutput[MAX_BUFFER + 1];
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		memset(szErr, 0, sizeof(TCHAR) * (MAX_ERROR + 1));
		memset(szOutput, 0, sizeof(TCHAR) * (MAX_BUFFER + 1));	

		//---------------------------------------
		//	Verify the state and parameters.
		//---------------------------------------

		if (m_pfnQueryStringFloatEx == NULL)
			AfxThrowOleException(HRESULT_FROM_WIN32(ERROR_BAD_DLL_ENTRYPOINT));


		//---------------------------------------
		//	If there is input data, extract it
		//	from the input safearray.
		//---------------------------------------

		if (rgInput != NULL)
		{
			hr = SafeArrayAccessData(rgInput, (LPVOID*)&plInput);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rgInput, 1, &lLBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rgInput, 1, &lUBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			lInput = lUBound - lLBound + 1;
		}

		//---------------------------------------
		//	Call the kernel DLL.
		//---------------------------------------

		szErr[MAX_ERROR] = (TCHAR)NULL;
		szOutput[MAX_BUFFER] = (TCHAR)NULL;
		lErr = (*m_pfnQueryStringFloatEx)(lKernelIdx, lFunctionIdx, plInput, lInput, szOutput, MAX_BUFFER, szErr, MAX_ERROR);
		if (lErr != 0)
			AfxThrowOleDispatchException((WORD)lErr, szErr);

		//---------------------------------------
		//	Release the input data.
		//---------------------------------------

		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		//---------------------------------------
		//	Convert the output data into a new
		//	safearray.
		//---------------------------------------

		rgOutput = SafeArrayCreateVector(VT_BSTR, 0, 1);

		if (rgOutput == NULL)
			AfxThrowMemoryException();

		szOutput[MAX_BUFFER] = (TCHAR)NULL;
		BSTR bstr = SysAllocString(szOutput);
		LONG lIdx = 0;

		hr = SafeArrayPutElement(rgOutput, &lIdx, bstr);
		SysFreeString(bstr);

		if (FAILED(hr))
			AfxThrowOleException(hr);

		*prgOutput = rgOutput;
		rgOutput = NULL;
	}
	CATCH(COleDispatchException, e)
	{
		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_ICudaKernel, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Running CUDA Kernel Function", IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CCudaKernel::QueryStringDoubleEx(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY* rgInput, SAFEARRAY** prgOutput)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	LONG* plInput = NULL;
	LONG lInput = 0;
	LPTSTR pstrOutput = NULL;
	LONG lOutput = 1;
	LONG lLBound = 0;
	LONG lUBound = 0;
	LONG lErr = 0;
	TCHAR szErr[MAX_ERROR + 1];
	TCHAR szOutput[MAX_BUFFER + 1];
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		memset(szErr, 0, sizeof(TCHAR) * (MAX_ERROR + 1));
		memset(szOutput, 0, sizeof(TCHAR) * (MAX_BUFFER + 1));

		//---------------------------------------
		//	Verify the state and parameters.
		//---------------------------------------

		if (m_pfnQueryStringDoubleEx == NULL)
			AfxThrowOleException(HRESULT_FROM_WIN32(ERROR_BAD_DLL_ENTRYPOINT));


		//---------------------------------------
		//	If there is input data, extract it
		//	from the input safearray.
		//---------------------------------------

		if (rgInput != NULL)
		{
			hr = SafeArrayAccessData(rgInput, (LPVOID*)&plInput);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rgInput, 1, &lLBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rgInput, 1, &lUBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			lInput = lUBound - lLBound + 1;
		}

		//---------------------------------------
		//	Call the kernel DLL.
		//---------------------------------------

		szErr[MAX_ERROR] = (TCHAR)NULL;
		szOutput[MAX_BUFFER] = (TCHAR)NULL;
		lErr = (*m_pfnQueryStringDoubleEx)(lKernelIdx, lFunctionIdx, plInput, lInput, szOutput, MAX_BUFFER, szErr, MAX_ERROR);
		if (lErr != 0)
			AfxThrowOleDispatchException((WORD)lErr, szErr);

		//---------------------------------------
		//	Release the input data.
		//---------------------------------------

		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		//---------------------------------------
		//	Convert the output data into a new
		//	safearray.
		//---------------------------------------

		rgOutput = SafeArrayCreateVector(VT_BSTR, 0, 1);
		if (rgOutput == NULL)
			AfxThrowMemoryException();

		szOutput[MAX_BUFFER] = (TCHAR)NULL;
		BSTR bstr = SysAllocString(szOutput);
		LONG lIdx = 0;

		hr = SafeArrayPutElement(rgOutput, &lIdx, bstr);
		SysFreeString(bstr);

		if (FAILED(hr))
			AfxThrowOleException(hr);

		*prgOutput = rgOutput;
		rgOutput = NULL;
	}
	CATCH(COleDispatchException, e)
	{
		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_ICudaKernel, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Running CUDA Kernel Function", IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

		return S_OK;
}


STDMETHODIMP CCudaKernel::SetBytes(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY* rgInput, SAFEARRAY* rgbInput, SAFEARRAY** prgOutput)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	LONG* pInput = NULL;
	BYTE* pbInput = NULL;
	LONG lInput = 0;
	LONG lbInput = 0;
	LONG* plOutput = NULL;
	LONG lOutput = 1;
	LONG lLBound = 0;
	LONG lUBound = 0;
	LONG lbOutput = 1;
	LONG lbLBound = 0;
	LONG lbUBound = 0;
	LONG lErr = 0;
	TCHAR szErr[MAX_ERROR + 1];
	SAFEARRAY* rgOutput = NULL;
	LONG hHandle = 0;

	TRY
	{
		if (m_pfnSetBytes == NULL)
			return ERROR_CALL_NOT_IMPLEMENTED;

		memset(szErr, 0, sizeof(TCHAR) * (MAX_ERROR + 1));

		//---------------------------------------
		//	If there is input data, extract it
		//	from the input safearray.
		//---------------------------------------

		if (rgInput != NULL)
		{
			hr = SafeArrayAccessData(rgInput, (LPVOID*)&pInput);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rgInput, 1, &lLBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rgInput, 1, &lUBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			lInput = lUBound - lLBound + 1;
		}


		//---------------------------------------
		//	If there is byte input data, extract it
		//	from the byte input safearray.
		//---------------------------------------

		if (rgbInput != NULL)
		{
			hr = SafeArrayAccessData(rgbInput, (LPVOID*)&pbInput);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rgbInput, 1, &lbLBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rgbInput, 1, &lbUBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			lbInput = lbUBound - lbLBound + 1;
		}

		//---------------------------------------
		//	Call the kernel DLL.
		//---------------------------------------

		szErr[MAX_ERROR] = (TCHAR)NULL;
		lErr = (*m_pfnSetBytes)(lKernelIdx, lFunctionIdx, pInput, lInput, pbInput, lbInput, &plOutput, &lOutput, szErr, MAX_ERROR);
		if (lErr != 0)
			AfxThrowOleDispatchException((WORD)lErr, szErr);

		//---------------------------------------
		//	Release the input data.
		//---------------------------------------

		if (pInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pInput = NULL;
		}

		//---------------------------------------
		//	Release the byte input data.
		//---------------------------------------

		if (pbInput != NULL && rgbInput != NULL)
		{
			SafeArrayUnaccessData(rgbInput);
			pbInput = NULL;
		}

		//---------------------------------------
		//	Convert the output data into a new
		//	safearray.
		//---------------------------------------

		rgOutput = SafeArrayCreateVector(VT_I4, 0, lOutput);
		if (rgOutput == NULL)
			AfxThrowMemoryException();

		LONG* plOutput1 = NULL;
		hr = SafeArrayAccessData(rgOutput, (VOID**)&plOutput1);
		if (FAILED(hr))
			AfxThrowOleException(hr);

		memcpy(plOutput1, plOutput, (DWORD)lOutput);

		hr = SafeArrayUnaccessData(rgOutput);
		if (FAILED(hr))
			AfxThrowOleException(hr);

		*prgOutput = rgOutput;
		rgOutput = NULL;

		(*m_pfnSetBytes)(lKernelIdx, CUDA_DLL_FREEMEM, plOutput, lOutput, NULL, NULL, NULL, NULL, szErr, MAX_ERROR);
		plOutput = NULL;
	}
	CATCH(COleDispatchException, e)
	{
		if (pInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pInput = NULL;
		}

		if (pbInput != NULL && rgbInput != NULL)
		{
			SafeArrayUnaccessData(rgbInput);
			pbInput = NULL;
		}

		if (plOutput != NULL)
		{
			(*m_pfnSetBytes)(lKernelIdx, CUDA_DLL_FREEMEM, plOutput, lOutput, NULL, NULL, NULL, NULL, szErr, MAX_ERROR);
			plOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_ICudaKernel, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (pInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			pInput = NULL;
		}

		if (pbInput != NULL && rgbInput != NULL)
		{
			SafeArrayUnaccessData(rgbInput);
			pbInput = NULL;
		}

		if (plOutput != NULL)
		{
			(*m_pfnSetBytes)(lKernelIdx, CUDA_DLL_FREEMEM, plOutput, lOutput, NULL, NULL, NULL, NULL, szErr, MAX_ERROR);
			plOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Running CUDA Kernel Function", IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

		return S_OK;
}

STDMETHODIMP CCudaKernel::QueryBytes(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY* rgInput, SAFEARRAY** prgOutput)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	LONG* plInput = NULL;
	LONG lInput = 0;
	BYTE* pbOutput = NULL;
	LONG lOutput = 1;
	LONG lLBound = 0;
	LONG lUBound = 0;
	LONG lErr = 0;
	TCHAR szErr[MAX_ERROR + 1];
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		if (m_pfnQueryBytes == NULL)
			return ERROR_CALL_NOT_IMPLEMENTED;

		memset(szErr, 0, sizeof(TCHAR) * (MAX_ERROR + 1));


		//---------------------------------------
		//	If there is input data, extract it
		//	from the input safearray.
		//---------------------------------------

		if (rgInput != NULL)
		{
			hr = SafeArrayAccessData(rgInput, (LPVOID*)&plInput);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetLBound(rgInput, 1, &lLBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			hr = SafeArrayGetUBound(rgInput, 1, &lUBound);
			if (FAILED(hr))
				AfxThrowOleException(hr);

			lInput = lUBound - lLBound + 1;
		}

		//---------------------------------------
		//	Call the kernel DLL.
		//---------------------------------------

		szErr[MAX_ERROR] = (TCHAR)NULL;
		lErr = (*m_pfnQueryBytes)(lKernelIdx, lFunctionIdx, plInput, lInput, &pbOutput, &lOutput, szErr, MAX_ERROR);
		if (lErr != 0)
			AfxThrowOleDispatchException((WORD)lErr, szErr);

		//---------------------------------------
		//	Release the input data.
		//---------------------------------------

		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		//---------------------------------------
		//	Convert the output data into a new
		//	safearray.
		//---------------------------------------

		rgOutput = SafeArrayCreateVector(VT_UI1, 0, lOutput);
		if (rgOutput == NULL)
			AfxThrowMemoryException();

		BYTE* pbOutput1 = NULL;
		hr = SafeArrayAccessData(rgOutput, (VOID**)&pbOutput1);
		if (FAILED(hr))
			AfxThrowOleException(hr);

		memcpy(pbOutput1, pbOutput, (DWORD)lOutput);

		hr = SafeArrayUnaccessData(rgOutput);
		if (FAILED(hr))
			AfxThrowOleException(hr);

		*prgOutput = rgOutput;
		rgOutput = NULL;

		(*m_pfnQueryBytes)(lKernelIdx, CUDA_DLL_FREEMEM, NULL, NULL, &pbOutput, &lOutput, szErr, MAX_ERROR);
		pbOutput = NULL;
	}
	CATCH(COleDispatchException, e)
	{
		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		if (pbOutput != NULL)
		{
			(*m_pfnQueryBytes)(lKernelIdx, CUDA_DLL_FREEMEM, NULL, NULL, &pbOutput, &lOutput, szErr, MAX_ERROR);
			pbOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_ICudaKernel, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (plInput != NULL && rgInput != NULL)
		{
			SafeArrayUnaccessData(rgInput);
			plInput = NULL;
		}

		if (pbOutput != NULL)
		{
			(*m_pfnQueryBytes)(lKernelIdx, CUDA_DLL_FREEMEM, NULL, NULL, &pbOutput, &lOutput, szErr, MAX_ERROR);
			pbOutput = NULL;
		}

		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Running CUDA Kernel Function", IID_ICudaKernel, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}
