// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "CudaControl_i.h"
#include "dllmain.h"
#include "dlldatax.h"

CCudaControlModule _AtlModule;

class CCudaControlApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CCudaControlApp, CWinApp)
END_MESSAGE_MAP()

CCudaControlApp theApp;

BOOL CCudaControlApp::InitInstance()
{
#ifdef _MERGE_PROXYSTUB
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, NULL))
		return FALSE;
#endif
	return CWinApp::InitInstance();
}

int CCudaControlApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
