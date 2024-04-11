

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for CudaControl.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __CudaControl_i_h__
#define __CudaControl_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __ICudaKernel_FWD_DEFINED__
#define __ICudaKernel_FWD_DEFINED__
typedef interface ICudaKernel ICudaKernel;

#endif 	/* __ICudaKernel_FWD_DEFINED__ */


#ifndef ___ICudaKernelEvents_FWD_DEFINED__
#define ___ICudaKernelEvents_FWD_DEFINED__
typedef interface _ICudaKernelEvents _ICudaKernelEvents;

#endif 	/* ___ICudaKernelEvents_FWD_DEFINED__ */


#ifndef __CudaKernel_FWD_DEFINED__
#define __CudaKernel_FWD_DEFINED__

#ifdef __cplusplus
typedef class CudaKernel CudaKernel;
#else
typedef struct CudaKernel CudaKernel;
#endif /* __cplusplus */

#endif 	/* __CudaKernel_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICudaKernel_INTERFACE_DEFINED__
#define __ICudaKernel_INTERFACE_DEFINED__

/* interface ICudaKernel */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICudaKernel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("04177BC8-4ED8-4F5D-97EA-18C75C1039E1")
    ICudaKernel : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR bstrCudaDLLName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunFloat( 
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [retval][out] */ SAFEARRAY * *prgOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunDouble( 
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [retval][out] */ SAFEARRAY * *prgOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryString( 
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0000,
            /* [retval][out] */ SAFEARRAY * *prgOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunFloatEx( 
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [in] */ BSTR bstrInput,
            /* [retval][out] */ SAFEARRAY * *prgOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunDoubleEx( 
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [in] */ BSTR bstrInput,
            /* [retval][out] */ SAFEARRAY * *prgOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunFloatEx2( 
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [in] */ SAFEARRAY * rgInput2,
            /* [retval][out] */ SAFEARRAY * *prgOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunDoubleEx2( 
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [in] */ SAFEARRAY * rgInput2,
            /* [retval][out] */ SAFEARRAY * *prgOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryBytes( 
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0001,
            /* [retval][out] */ SAFEARRAY * *prgOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetBytes( 
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0002,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0003,
            /* [retval][out] */ SAFEARRAY * *prgOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryStringFloatEx( 
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0004,
            /* [retval][out] */ SAFEARRAY * *prgOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryStringDoubleEx( 
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0005,
            /* [retval][out] */ SAFEARRAY * *prgOutput) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICudaKernelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICudaKernel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICudaKernel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICudaKernel * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICudaKernel * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICudaKernel * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICudaKernel * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICudaKernel * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ICudaKernel, Load)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            ICudaKernel * This,
            /* [in] */ BSTR bstrCudaDLLName);
        
        DECLSPEC_XFGVIRT(ICudaKernel, RunFloat)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunFloat )( 
            ICudaKernel * This,
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [retval][out] */ SAFEARRAY * *prgOutput);
        
        DECLSPEC_XFGVIRT(ICudaKernel, RunDouble)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunDouble )( 
            ICudaKernel * This,
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [retval][out] */ SAFEARRAY * *prgOutput);
        
        DECLSPEC_XFGVIRT(ICudaKernel, QueryString)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryString )( 
            ICudaKernel * This,
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0000,
            /* [retval][out] */ SAFEARRAY * *prgOutput);
        
        DECLSPEC_XFGVIRT(ICudaKernel, RunFloatEx)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunFloatEx )( 
            ICudaKernel * This,
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [in] */ BSTR bstrInput,
            /* [retval][out] */ SAFEARRAY * *prgOutput);
        
        DECLSPEC_XFGVIRT(ICudaKernel, RunDoubleEx)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunDoubleEx )( 
            ICudaKernel * This,
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [in] */ BSTR bstrInput,
            /* [retval][out] */ SAFEARRAY * *prgOutput);
        
        DECLSPEC_XFGVIRT(ICudaKernel, RunFloatEx2)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunFloatEx2 )( 
            ICudaKernel * This,
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [in] */ SAFEARRAY * rgInput2,
            /* [retval][out] */ SAFEARRAY * *prgOutput);
        
        DECLSPEC_XFGVIRT(ICudaKernel, RunDoubleEx2)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunDoubleEx2 )( 
            ICudaKernel * This,
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * rgInput,
            /* [in] */ SAFEARRAY * rgInput2,
            /* [retval][out] */ SAFEARRAY * *prgOutput);
        
        DECLSPEC_XFGVIRT(ICudaKernel, QueryBytes)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryBytes )( 
            ICudaKernel * This,
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0001,
            /* [retval][out] */ SAFEARRAY * *prgOutput);
        
        DECLSPEC_XFGVIRT(ICudaKernel, SetBytes)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetBytes )( 
            ICudaKernel * This,
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0002,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0003,
            /* [retval][out] */ SAFEARRAY * *prgOutput);
        
        DECLSPEC_XFGVIRT(ICudaKernel, QueryStringFloatEx)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryStringFloatEx )( 
            ICudaKernel * This,
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0004,
            /* [retval][out] */ SAFEARRAY * *prgOutput);
        
        DECLSPEC_XFGVIRT(ICudaKernel, QueryStringDoubleEx)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryStringDoubleEx )( 
            ICudaKernel * This,
            /* [in] */ LONG lKernelIdx,
            /* [in] */ LONG lFunctionIdx,
            /* [in] */ SAFEARRAY * __MIDL__ICudaKernel0005,
            /* [retval][out] */ SAFEARRAY * *prgOutput);
        
        END_INTERFACE
    } ICudaKernelVtbl;

    interface ICudaKernel
    {
        CONST_VTBL struct ICudaKernelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICudaKernel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICudaKernel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICudaKernel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICudaKernel_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICudaKernel_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICudaKernel_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICudaKernel_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICudaKernel_Load(This,bstrCudaDLLName)	\
    ( (This)->lpVtbl -> Load(This,bstrCudaDLLName) ) 

#define ICudaKernel_RunFloat(This,lKernelIdx,lFunctionIdx,rgInput,prgOutput)	\
    ( (This)->lpVtbl -> RunFloat(This,lKernelIdx,lFunctionIdx,rgInput,prgOutput) ) 

#define ICudaKernel_RunDouble(This,lKernelIdx,lFunctionIdx,rgInput,prgOutput)	\
    ( (This)->lpVtbl -> RunDouble(This,lKernelIdx,lFunctionIdx,rgInput,prgOutput) ) 

#define ICudaKernel_QueryString(This,lKernelIdx,lFunctionIdx,__MIDL__ICudaKernel0000,prgOutput)	\
    ( (This)->lpVtbl -> QueryString(This,lKernelIdx,lFunctionIdx,__MIDL__ICudaKernel0000,prgOutput) ) 

#define ICudaKernel_RunFloatEx(This,lKernelIdx,lFunctionIdx,rgInput,bstrInput,prgOutput)	\
    ( (This)->lpVtbl -> RunFloatEx(This,lKernelIdx,lFunctionIdx,rgInput,bstrInput,prgOutput) ) 

#define ICudaKernel_RunDoubleEx(This,lKernelIdx,lFunctionIdx,rgInput,bstrInput,prgOutput)	\
    ( (This)->lpVtbl -> RunDoubleEx(This,lKernelIdx,lFunctionIdx,rgInput,bstrInput,prgOutput) ) 

#define ICudaKernel_RunFloatEx2(This,lKernelIdx,lFunctionIdx,rgInput,rgInput2,prgOutput)	\
    ( (This)->lpVtbl -> RunFloatEx2(This,lKernelIdx,lFunctionIdx,rgInput,rgInput2,prgOutput) ) 

#define ICudaKernel_RunDoubleEx2(This,lKernelIdx,lFunctionIdx,rgInput,rgInput2,prgOutput)	\
    ( (This)->lpVtbl -> RunDoubleEx2(This,lKernelIdx,lFunctionIdx,rgInput,rgInput2,prgOutput) ) 

#define ICudaKernel_QueryBytes(This,lKernelIdx,lFunctionIdx,__MIDL__ICudaKernel0001,prgOutput)	\
    ( (This)->lpVtbl -> QueryBytes(This,lKernelIdx,lFunctionIdx,__MIDL__ICudaKernel0001,prgOutput) ) 

#define ICudaKernel_SetBytes(This,lKernelIdx,lFunctionIdx,__MIDL__ICudaKernel0002,__MIDL__ICudaKernel0003,prgOutput)	\
    ( (This)->lpVtbl -> SetBytes(This,lKernelIdx,lFunctionIdx,__MIDL__ICudaKernel0002,__MIDL__ICudaKernel0003,prgOutput) ) 

#define ICudaKernel_QueryStringFloatEx(This,lKernelIdx,lFunctionIdx,__MIDL__ICudaKernel0004,prgOutput)	\
    ( (This)->lpVtbl -> QueryStringFloatEx(This,lKernelIdx,lFunctionIdx,__MIDL__ICudaKernel0004,prgOutput) ) 

#define ICudaKernel_QueryStringDoubleEx(This,lKernelIdx,lFunctionIdx,__MIDL__ICudaKernel0005,prgOutput)	\
    ( (This)->lpVtbl -> QueryStringDoubleEx(This,lKernelIdx,lFunctionIdx,__MIDL__ICudaKernel0005,prgOutput) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICudaKernel_INTERFACE_DEFINED__ */



#ifndef __CudaControlLib_LIBRARY_DEFINED__
#define __CudaControlLib_LIBRARY_DEFINED__

/* library CudaControlLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_CudaControlLib;

#ifndef ___ICudaKernelEvents_DISPINTERFACE_DEFINED__
#define ___ICudaKernelEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ICudaKernelEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ICudaKernelEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("56A18428-AD3B-4C58-AC07-84D171953617")
    _ICudaKernelEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ICudaKernelEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ICudaKernelEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ICudaKernelEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ICudaKernelEvents * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ICudaKernelEvents * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ICudaKernelEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ICudaKernelEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ICudaKernelEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _ICudaKernelEventsVtbl;

    interface _ICudaKernelEvents
    {
        CONST_VTBL struct _ICudaKernelEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ICudaKernelEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ICudaKernelEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ICudaKernelEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ICudaKernelEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ICudaKernelEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ICudaKernelEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ICudaKernelEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ICudaKernelEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CudaKernel;

#ifdef __cplusplus

class DECLSPEC_UUID("79CD28C1-C81B-42C4-AAE1-7554A956A203")
CudaKernel;
#endif
#endif /* __CudaControlLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


