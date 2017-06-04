

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jun 02 14:04:48 2017
 */
/* Compiler settings for CudaControl.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "CudaControl_i.h"

#define TYPE_FORMAT_STRING_SIZE   1029                              
#define PROC_FORMAT_STRING_SIZE   207                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _CudaControl_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } CudaControl_MIDL_TYPE_FORMAT_STRING;

typedef struct _CudaControl_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } CudaControl_MIDL_PROC_FORMAT_STRING;

typedef struct _CudaControl_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } CudaControl_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const CudaControl_MIDL_TYPE_FORMAT_STRING CudaControl__MIDL_TypeFormatString;
extern const CudaControl_MIDL_PROC_FORMAT_STRING CudaControl__MIDL_ProcFormatString;
extern const CudaControl_MIDL_EXPR_FORMAT_STRING CudaControl__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICudaKernel_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ICudaKernel_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const CudaControl_MIDL_PROC_FORMAT_STRING CudaControl__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Load */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x1 ),	/* 1 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrCudaDLLName */

/* 26 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 28 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 32 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RunFloat */

/* 38 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 40 */	NdrFcLong( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x8 ),	/* 8 */
/* 46 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 48 */	NdrFcShort( 0x10 ),	/* 16 */
/* 50 */	NdrFcShort( 0x8 ),	/* 8 */
/* 52 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 54 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 56 */	NdrFcShort( 0x1 ),	/* 1 */
/* 58 */	NdrFcShort( 0x1 ),	/* 1 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lKernelIdx */

/* 64 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 66 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 68 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lFunctionIdx */

/* 70 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 72 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgInput */

/* 76 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 78 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 80 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Parameter prgOutput */

/* 82 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 84 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 86 */	NdrFcShort( 0x3fa ),	/* Type Offset=1018 */

	/* Return value */

/* 88 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 90 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 92 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RunDouble */

/* 94 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 96 */	NdrFcLong( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x9 ),	/* 9 */
/* 102 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 104 */	NdrFcShort( 0x10 ),	/* 16 */
/* 106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 108 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 110 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 112 */	NdrFcShort( 0x1 ),	/* 1 */
/* 114 */	NdrFcShort( 0x1 ),	/* 1 */
/* 116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lKernelIdx */

/* 120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 122 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lFunctionIdx */

/* 126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 128 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgInput */

/* 132 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 134 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 136 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Parameter prgOutput */

/* 138 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 140 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 142 */	NdrFcShort( 0x3fa ),	/* Type Offset=1018 */

	/* Return value */

/* 144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 146 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryString */

/* 150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0xa ),	/* 10 */
/* 158 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 160 */	NdrFcShort( 0x10 ),	/* 16 */
/* 162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 164 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 166 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 168 */	NdrFcShort( 0x1 ),	/* 1 */
/* 170 */	NdrFcShort( 0x1 ),	/* 1 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lKernelIdx */

/* 176 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 178 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lFunctionIdx */

/* 182 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 184 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter __MIDL__ICudaKernel0000 */

/* 188 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 190 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 192 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Parameter prgOutput */

/* 194 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 196 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 198 */	NdrFcShort( 0x3fa ),	/* Type Offset=1018 */

	/* Return value */

/* 200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 202 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const CudaControl_MIDL_TYPE_FORMAT_STRING CudaControl__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x12, 0x0,	/* FC_UP */
/*  4 */	NdrFcShort( 0xe ),	/* Offset= 14 (18) */
/*  6 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/*  8 */	NdrFcShort( 0x2 ),	/* 2 */
/* 10 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 12 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 14 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 16 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 18 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 20 */	NdrFcShort( 0x8 ),	/* 8 */
/* 22 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (6) */
/* 24 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 26 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 28 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0x8 ),	/* 8 */
/* 34 */	NdrFcShort( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0xffde ),	/* Offset= -34 (2) */
/* 38 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 40 */	NdrFcShort( 0x2 ),	/* Offset= 2 (42) */
/* 42 */	
			0x12, 0x0,	/* FC_UP */
/* 44 */	NdrFcShort( 0x3a6 ),	/* Offset= 934 (978) */
/* 46 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x89,		/* 137 */
/* 48 */	NdrFcShort( 0x20 ),	/* 32 */
/* 50 */	NdrFcShort( 0xa ),	/* 10 */
/* 52 */	NdrFcLong( 0x8 ),	/* 8 */
/* 56 */	NdrFcShort( 0x50 ),	/* Offset= 80 (136) */
/* 58 */	NdrFcLong( 0xd ),	/* 13 */
/* 62 */	NdrFcShort( 0x82 ),	/* Offset= 130 (192) */
/* 64 */	NdrFcLong( 0x9 ),	/* 9 */
/* 68 */	NdrFcShort( 0xb4 ),	/* Offset= 180 (248) */
/* 70 */	NdrFcLong( 0xc ),	/* 12 */
/* 74 */	NdrFcShort( 0x2a4 ),	/* Offset= 676 (750) */
/* 76 */	NdrFcLong( 0x24 ),	/* 36 */
/* 80 */	NdrFcShort( 0x2c4 ),	/* Offset= 708 (788) */
/* 82 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 86 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (822) */
/* 88 */	NdrFcLong( 0x10 ),	/* 16 */
/* 92 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (854) */
/* 94 */	NdrFcLong( 0x2 ),	/* 2 */
/* 98 */	NdrFcShort( 0x310 ),	/* Offset= 784 (882) */
/* 100 */	NdrFcLong( 0x3 ),	/* 3 */
/* 104 */	NdrFcShort( 0x326 ),	/* Offset= 806 (910) */
/* 106 */	NdrFcLong( 0x14 ),	/* 20 */
/* 110 */	NdrFcShort( 0x33c ),	/* Offset= 828 (938) */
/* 112 */	NdrFcShort( 0xffff ),	/* Offset= -1 (111) */
/* 114 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 118 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 124 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 128 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 130 */	
			0x12, 0x0,	/* FC_UP */
/* 132 */	NdrFcShort( 0xff8e ),	/* Offset= -114 (18) */
/* 134 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 136 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 138 */	NdrFcShort( 0x10 ),	/* 16 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x6 ),	/* Offset= 6 (148) */
/* 144 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 146 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 148 */	
			0x11, 0x0,	/* FC_RP */
/* 150 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (114) */
/* 152 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 162 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 164 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 166 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 168 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 170 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 180 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 184 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 186 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 188 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (152) */
/* 190 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 192 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 194 */	NdrFcShort( 0x10 ),	/* 16 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x6 ),	/* Offset= 6 (204) */
/* 200 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 202 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 204 */	
			0x11, 0x0,	/* FC_RP */
/* 206 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (170) */
/* 208 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 210 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 218 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 220 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 222 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 224 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 226 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 230 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 236 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 240 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 242 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 244 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (208) */
/* 246 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 248 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 250 */	NdrFcShort( 0x10 ),	/* 16 */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 254 */	NdrFcShort( 0x6 ),	/* Offset= 6 (260) */
/* 256 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 258 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 260 */	
			0x11, 0x0,	/* FC_RP */
/* 262 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (226) */
/* 264 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 266 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 268 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 270 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 272 */	NdrFcShort( 0x2 ),	/* Offset= 2 (274) */
/* 274 */	NdrFcShort( 0x10 ),	/* 16 */
/* 276 */	NdrFcShort( 0x2f ),	/* 47 */
/* 278 */	NdrFcLong( 0x14 ),	/* 20 */
/* 282 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 284 */	NdrFcLong( 0x3 ),	/* 3 */
/* 288 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 290 */	NdrFcLong( 0x11 ),	/* 17 */
/* 294 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 296 */	NdrFcLong( 0x2 ),	/* 2 */
/* 300 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 302 */	NdrFcLong( 0x4 ),	/* 4 */
/* 306 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 308 */	NdrFcLong( 0x5 ),	/* 5 */
/* 312 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 314 */	NdrFcLong( 0xb ),	/* 11 */
/* 318 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 320 */	NdrFcLong( 0xa ),	/* 10 */
/* 324 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 326 */	NdrFcLong( 0x6 ),	/* 6 */
/* 330 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (562) */
/* 332 */	NdrFcLong( 0x7 ),	/* 7 */
/* 336 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 338 */	NdrFcLong( 0x8 ),	/* 8 */
/* 342 */	NdrFcShort( 0xfeac ),	/* Offset= -340 (2) */
/* 344 */	NdrFcLong( 0xd ),	/* 13 */
/* 348 */	NdrFcShort( 0xff3c ),	/* Offset= -196 (152) */
/* 350 */	NdrFcLong( 0x9 ),	/* 9 */
/* 354 */	NdrFcShort( 0xff6e ),	/* Offset= -146 (208) */
/* 356 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 360 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (568) */
/* 362 */	NdrFcLong( 0x24 ),	/* 36 */
/* 366 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (576) */
/* 368 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 372 */	NdrFcShort( 0xcc ),	/* Offset= 204 (576) */
/* 374 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 378 */	NdrFcShort( 0xfc ),	/* Offset= 252 (630) */
/* 380 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 384 */	NdrFcShort( 0xfa ),	/* Offset= 250 (634) */
/* 386 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 390 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (638) */
/* 392 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 396 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (642) */
/* 398 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 402 */	NdrFcShort( 0xf4 ),	/* Offset= 244 (646) */
/* 404 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 408 */	NdrFcShort( 0xf2 ),	/* Offset= 242 (650) */
/* 410 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 414 */	NdrFcShort( 0xdc ),	/* Offset= 220 (634) */
/* 416 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 420 */	NdrFcShort( 0xda ),	/* Offset= 218 (638) */
/* 422 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 426 */	NdrFcShort( 0xe4 ),	/* Offset= 228 (654) */
/* 428 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 432 */	NdrFcShort( 0xda ),	/* Offset= 218 (650) */
/* 434 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 438 */	NdrFcShort( 0xdc ),	/* Offset= 220 (658) */
/* 440 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 444 */	NdrFcShort( 0xda ),	/* Offset= 218 (662) */
/* 446 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 450 */	NdrFcShort( 0xd8 ),	/* Offset= 216 (666) */
/* 452 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 456 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (670) */
/* 458 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 462 */	NdrFcShort( 0xdc ),	/* Offset= 220 (682) */
/* 464 */	NdrFcLong( 0x10 ),	/* 16 */
/* 468 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 470 */	NdrFcLong( 0x12 ),	/* 18 */
/* 474 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 476 */	NdrFcLong( 0x13 ),	/* 19 */
/* 480 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 482 */	NdrFcLong( 0x15 ),	/* 21 */
/* 486 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 488 */	NdrFcLong( 0x16 ),	/* 22 */
/* 492 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 494 */	NdrFcLong( 0x17 ),	/* 23 */
/* 498 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 500 */	NdrFcLong( 0xe ),	/* 14 */
/* 504 */	NdrFcShort( 0xba ),	/* Offset= 186 (690) */
/* 506 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 510 */	NdrFcShort( 0xbe ),	/* Offset= 190 (700) */
/* 512 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 516 */	NdrFcShort( 0xbc ),	/* Offset= 188 (704) */
/* 518 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 522 */	NdrFcShort( 0x70 ),	/* Offset= 112 (634) */
/* 524 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 528 */	NdrFcShort( 0x6e ),	/* Offset= 110 (638) */
/* 530 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 534 */	NdrFcShort( 0x6c ),	/* Offset= 108 (642) */
/* 536 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 540 */	NdrFcShort( 0x62 ),	/* Offset= 98 (638) */
/* 542 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 546 */	NdrFcShort( 0x5c ),	/* Offset= 92 (638) */
/* 548 */	NdrFcLong( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x0 ),	/* Offset= 0 (552) */
/* 554 */	NdrFcLong( 0x1 ),	/* 1 */
/* 558 */	NdrFcShort( 0x0 ),	/* Offset= 0 (558) */
/* 560 */	NdrFcShort( 0xffff ),	/* Offset= -1 (559) */
/* 562 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 566 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 568 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 570 */	NdrFcShort( 0x2 ),	/* Offset= 2 (572) */
/* 572 */	
			0x12, 0x0,	/* FC_UP */
/* 574 */	NdrFcShort( 0x194 ),	/* Offset= 404 (978) */
/* 576 */	
			0x12, 0x0,	/* FC_UP */
/* 578 */	NdrFcShort( 0x20 ),	/* Offset= 32 (610) */
/* 580 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 582 */	NdrFcLong( 0x2f ),	/* 47 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 592 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 594 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 596 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 598 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 600 */	NdrFcShort( 0x1 ),	/* 1 */
/* 602 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 604 */	NdrFcShort( 0x4 ),	/* 4 */
/* 606 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 608 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 610 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 612 */	NdrFcShort( 0x18 ),	/* 24 */
/* 614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 616 */	NdrFcShort( 0xa ),	/* Offset= 10 (626) */
/* 618 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 620 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 622 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (580) */
/* 624 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 626 */	
			0x12, 0x0,	/* FC_UP */
/* 628 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (598) */
/* 630 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 632 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 634 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 636 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 638 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 640 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 642 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 644 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 646 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 648 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 650 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 652 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 654 */	
			0x12, 0x0,	/* FC_UP */
/* 656 */	NdrFcShort( 0xffa2 ),	/* Offset= -94 (562) */
/* 658 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 660 */	NdrFcShort( 0xfd6e ),	/* Offset= -658 (2) */
/* 662 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 664 */	NdrFcShort( 0xfe00 ),	/* Offset= -512 (152) */
/* 666 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 668 */	NdrFcShort( 0xfe34 ),	/* Offset= -460 (208) */
/* 670 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 672 */	NdrFcShort( 0x2 ),	/* Offset= 2 (674) */
/* 674 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 676 */	NdrFcShort( 0x2 ),	/* Offset= 2 (678) */
/* 678 */	
			0x12, 0x0,	/* FC_UP */
/* 680 */	NdrFcShort( 0x12a ),	/* Offset= 298 (978) */
/* 682 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 684 */	NdrFcShort( 0x2 ),	/* Offset= 2 (686) */
/* 686 */	
			0x12, 0x0,	/* FC_UP */
/* 688 */	NdrFcShort( 0x14 ),	/* Offset= 20 (708) */
/* 690 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 692 */	NdrFcShort( 0x10 ),	/* 16 */
/* 694 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 696 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 698 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 700 */	
			0x12, 0x0,	/* FC_UP */
/* 702 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (690) */
/* 704 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 706 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 708 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 710 */	NdrFcShort( 0x20 ),	/* 32 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 714 */	NdrFcShort( 0x0 ),	/* Offset= 0 (714) */
/* 716 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 718 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 720 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 722 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 724 */	NdrFcShort( 0xfe34 ),	/* Offset= -460 (264) */
/* 726 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 728 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 738 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 742 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 744 */	
			0x12, 0x0,	/* FC_UP */
/* 746 */	NdrFcShort( 0xffda ),	/* Offset= -38 (708) */
/* 748 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 750 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 752 */	NdrFcShort( 0x10 ),	/* 16 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x6 ),	/* Offset= 6 (762) */
/* 758 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 760 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 762 */	
			0x11, 0x0,	/* FC_RP */
/* 764 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (728) */
/* 766 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 770 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 776 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 780 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 782 */	
			0x12, 0x0,	/* FC_UP */
/* 784 */	NdrFcShort( 0xff52 ),	/* Offset= -174 (610) */
/* 786 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 788 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 790 */	NdrFcShort( 0x10 ),	/* 16 */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x6 ),	/* Offset= 6 (800) */
/* 796 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 798 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 800 */	
			0x11, 0x0,	/* FC_RP */
/* 802 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (766) */
/* 804 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 806 */	NdrFcShort( 0x8 ),	/* 8 */
/* 808 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 810 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 812 */	NdrFcShort( 0x10 ),	/* 16 */
/* 814 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 816 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 818 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (804) */
			0x5b,		/* FC_END */
/* 822 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 824 */	NdrFcShort( 0x20 ),	/* 32 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 828 */	NdrFcShort( 0xa ),	/* Offset= 10 (838) */
/* 830 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 832 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 834 */	0x0,		/* 0 */
			NdrFcShort( 0xffe7 ),	/* Offset= -25 (810) */
			0x5b,		/* FC_END */
/* 838 */	
			0x11, 0x0,	/* FC_RP */
/* 840 */	NdrFcShort( 0xfd62 ),	/* Offset= -670 (170) */
/* 842 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 844 */	NdrFcShort( 0x1 ),	/* 1 */
/* 846 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 850 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 852 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 854 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 856 */	NdrFcShort( 0x10 ),	/* 16 */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x6 ),	/* Offset= 6 (866) */
/* 862 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 864 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 866 */	
			0x12, 0x0,	/* FC_UP */
/* 868 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (842) */
/* 870 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 872 */	NdrFcShort( 0x2 ),	/* 2 */
/* 874 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 878 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 880 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 882 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 884 */	NdrFcShort( 0x10 ),	/* 16 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0x6 ),	/* Offset= 6 (894) */
/* 890 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 892 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 894 */	
			0x12, 0x0,	/* FC_UP */
/* 896 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (870) */
/* 898 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 900 */	NdrFcShort( 0x4 ),	/* 4 */
/* 902 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 908 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 910 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 912 */	NdrFcShort( 0x10 ),	/* 16 */
/* 914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 916 */	NdrFcShort( 0x6 ),	/* Offset= 6 (922) */
/* 918 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 920 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 922 */	
			0x12, 0x0,	/* FC_UP */
/* 924 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (898) */
/* 926 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 928 */	NdrFcShort( 0x8 ),	/* 8 */
/* 930 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 936 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 938 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 940 */	NdrFcShort( 0x10 ),	/* 16 */
/* 942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 944 */	NdrFcShort( 0x6 ),	/* Offset= 6 (950) */
/* 946 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 948 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 950 */	
			0x12, 0x0,	/* FC_UP */
/* 952 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (926) */
/* 954 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 956 */	NdrFcShort( 0x8 ),	/* 8 */
/* 958 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 960 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 962 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 966 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 968 */	NdrFcShort( 0xffc8 ),	/* -56 */
/* 970 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 972 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 974 */	NdrFcShort( 0xffec ),	/* Offset= -20 (954) */
/* 976 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 978 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 980 */	NdrFcShort( 0x38 ),	/* 56 */
/* 982 */	NdrFcShort( 0xffec ),	/* Offset= -20 (962) */
/* 984 */	NdrFcShort( 0x0 ),	/* Offset= 0 (984) */
/* 986 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 988 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 990 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 992 */	0x0,		/* 0 */
			NdrFcShort( 0xfc4d ),	/* Offset= -947 (46) */
			0x5b,		/* FC_END */
/* 996 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 998 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0xfc3a ),	/* Offset= -966 (38) */
/* 1006 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1008 */	NdrFcShort( 0xa ),	/* Offset= 10 (1018) */
/* 1010 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1012 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1014) */
/* 1014 */	
			0x13, 0x0,	/* FC_OP */
/* 1016 */	NdrFcShort( 0xffda ),	/* Offset= -38 (978) */
/* 1018 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1020 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1026 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (1010) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ICudaKernel, ver. 0.0,
   GUID={0x04177BC8,0x4ED8,0x4F5D,{0x97,0xEA,0x18,0xC7,0x5C,0x10,0x39,0xE1}} */

#pragma code_seg(".orpc")
static const unsigned short ICudaKernel_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    38,
    94,
    150
    };

static const MIDL_STUBLESS_PROXY_INFO ICudaKernel_ProxyInfo =
    {
    &Object_StubDesc,
    CudaControl__MIDL_ProcFormatString.Format,
    &ICudaKernel_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ICudaKernel_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    CudaControl__MIDL_ProcFormatString.Format,
    &ICudaKernel_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _ICudaKernelProxyVtbl = 
{
    &ICudaKernel_ProxyInfo,
    &IID_ICudaKernel,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ICudaKernel::Load */ ,
    (void *) (INT_PTR) -1 /* ICudaKernel::RunFloat */ ,
    (void *) (INT_PTR) -1 /* ICudaKernel::RunDouble */ ,
    (void *) (INT_PTR) -1 /* ICudaKernel::QueryString */
};


static const PRPC_STUB_FUNCTION ICudaKernel_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ICudaKernelStubVtbl =
{
    &IID_ICudaKernel,
    &ICudaKernel_ServerInfo,
    11,
    &ICudaKernel_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    CudaControl__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x800025b, /* MIDL Version 8.0.603 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _CudaControl_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ICudaKernelProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _CudaControl_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ICudaKernelStubVtbl,
    0
};

PCInterfaceName const _CudaControl_InterfaceNamesList[] = 
{
    "ICudaKernel",
    0
};

const IID *  const _CudaControl_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _CudaControl_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _CudaControl, pIID, n)

int __stdcall _CudaControl_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_CudaControl_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo CudaControl_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _CudaControl_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _CudaControl_StubVtblList,
    (const PCInterfaceName * ) & _CudaControl_InterfaceNamesList,
    (const IID ** ) & _CudaControl_BaseIIDList,
    & _CudaControl_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

