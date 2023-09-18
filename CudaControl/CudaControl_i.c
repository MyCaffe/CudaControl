

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ICudaKernel,0x04177BC8,0x4ED8,0x4F5D,0x97,0xEA,0x18,0xC7,0x5C,0x10,0x39,0xE1);


MIDL_DEFINE_GUID(IID, LIBID_CudaControlLib,0xDAAB1D4F,0x6487,0x47E7,0x80,0x6F,0xC0,0xFC,0x70,0xA9,0x42,0xEC);


MIDL_DEFINE_GUID(IID, DIID__ICudaKernelEvents,0x56A18428,0xAD3B,0x4C58,0xAC,0x07,0x84,0xD1,0x71,0x95,0x36,0x17);


MIDL_DEFINE_GUID(CLSID, CLSID_CudaKernel,0x79CD28C1,0xC81B,0x42C4,0xAA,0xE1,0x75,0x54,0xA9,0x56,0xA2,0x03);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



