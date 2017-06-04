// dllmain.h : Declaration of module class.

class CCudaControlModule : public CAtlDllModuleT< CCudaControlModule >
{
public :
	DECLARE_LIBID(LIBID_CudaControlLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CUDACONTROL, "{014CF512-3007-4C8A-BC8F-9121227734DD}")
};

extern class CCudaControlModule _AtlModule;
