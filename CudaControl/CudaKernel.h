// CudaKernel.h : Declaration of the CCudaKernel

#pragma once
#include "resource.h"       // main symbols

#include "CudaControl_i.h"
#include "_ICudaKernelEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


const DWORD MAX_ERROR = 1023;

const LONG CUDA_DLL_FREEMEM = -1;
const LONG CUDA_DLL_INITIALIZE = -2;
const LONG CUDA_DLL_CLEANUP = -3;

#define SZDLL_INVOKEFLOAT "DLL_InvokeFloat"
#define SZDLL_INVOKEDOUBLE "DLL_InvokeDouble"
#define SZDLL_QUERYSTRING "DLL_QueryString"

typedef LONG (WINAPI *LPFNDLLINVOKEFLOAT)(LONG lKernelIdx,
	                                      LONG lFunctionIdx,
								     float* pInput, LONG lInput,
									 float** ppOutput, LONG* plOutput,
									 LPTSTR szErr, LONG lszErrMax);
typedef LONG (WINAPI *LPFNDLLINVOKEDOUBLE)(LONG lKernelIdx,
	                                       LONG lFunctionIdx,
								     double* pInput, LONG lInput,
									 double** ppOutput, LONG* plOutput,
									 LPTSTR szErr, LONG lszErrMax);
typedef LONG (WINAPI *LPFNDLLQUERYSTRING)(LONG lKernelIdx,
	                                       LONG lFunctionIdx,
								     LONG* pInput, LONG lInput,
									 LPTSTR* ppOutput,
									 LPTSTR szErr, LONG lszErrMax);

// CCudaKernel

class ATL_NO_VTABLE CCudaKernel :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CCudaKernel, &CLSID_CudaKernel>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CCudaKernel>,
	public CProxy_ICudaKernelEvents<CCudaKernel>,
	public IDispatchImpl<ICudaKernel, &IID_ICudaKernel, &LIBID_CudaControlLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCudaKernel()
	{
		m_hCudaDLL = NULL;
		m_pfnInvokeFloat = NULL;
		m_pfnInvokeDouble = NULL;
		m_pfnQueryString = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CUDAKERNEL)


BEGIN_COM_MAP(CCudaKernel)
	COM_INTERFACE_ENTRY(ICudaKernel)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CCudaKernel)
	CONNECTION_POINT_ENTRY(__uuidof(_ICudaKernelEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct();
	void FinalRelease();

	HMODULE m_hCudaDLL;
	LPFNDLLINVOKEFLOAT m_pfnInvokeFloat;
	LPFNDLLINVOKEDOUBLE m_pfnInvokeDouble;
	LPFNDLLQUERYSTRING m_pfnQueryString;

public:

	STDMETHOD(Load)(BSTR bstrCudaDLLName);
	STDMETHOD(RunFloat)(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY * rgInput, SAFEARRAY ** prgOutput);
	STDMETHOD(RunDouble)(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY * rgInput, SAFEARRAY ** prgOutput);
	STDMETHOD(QueryString)(LONG lKernelIdx, LONG lFunctionIdx, SAFEARRAY * rgInput, SAFEARRAY ** prgOutput);
};

OBJECT_ENTRY_AUTO(__uuidof(CudaKernel), CCudaKernel)
