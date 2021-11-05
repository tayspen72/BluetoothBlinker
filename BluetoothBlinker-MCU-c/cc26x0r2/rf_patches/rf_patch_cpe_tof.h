/******************************************************************************
*  Filename:       rf_patch_cpe_tof.h
*  Revised:        $Date: 2019-08-14 13:58:58 +0200 (Wed, 14 Aug 2019) $
*  Revision:       $Revision: 19122 $
*
*  Description: RF core patch for supporting time-of-flight radio measurements in CC2640R2F
*
*  Copyright (c) 2015-2019, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/
#ifndef _RF_PATCH_CPE_TOF_H
#define _RF_PATCH_CPE_TOF_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <string.h>

#ifndef CPE_PATCH_TYPE
#define CPE_PATCH_TYPE static const uint32_t
#endif

#ifndef SYS_PATCH_TYPE
#define SYS_PATCH_TYPE static const uint32_t
#endif

#ifndef PATCH_FUN_SPEC
#define PATCH_FUN_SPEC static inline
#endif

#ifndef _APPLY_PATCH_TAB
#define _APPLY_PATCH_TAB
#endif


CPE_PATCH_TYPE patchImageTof[] = {
   0x21000dcd,
   0x21000df5,
   0x4803b510,
   0x30106800,
   0xfa73f000,
   0x47084901,
   0x210000ec,
   0x00008e13,
   0x01c0b570,
   0x47204c00,
   0x000046d5,
   0x230048ff,
   0x48ff6143,
   0x07c96ac1,
   0x49fed0fc,
   0x07d26a0a,
   0x2205d101,
   0x6a0a60ca,
   0xd0fc07d2,
   0x60812101,
   0x60836003,
   0x384048f7,
   0x60036081,
   0x47706083,
   0x210048f3,
   0x210162c1,
   0x47706201,
   0x49f2b510,
   0x780b2200,
   0x2b006889,
   0x798bd003,
   0xd0002b01,
   0x68cc2201,
   0x2c000840,
   0x8ccbd002,
   0xd3014298,
   0xd0132a00,
   0x08cb79c9,
   0x19044358,
   0xd0022a00,
   0x34184ce5,
   0x20002304,
   0xe00549e2,
   0x07926b8a,
   0x6a8ad5fc,
   0x1c405422,
   0xdbf74298,
   0xb5f3bd10,
   0xb0812400,
   0x940049dd,
   0x46224627,
   0x46254623,
   0xe013684e,
   0x6aca49d6,
   0x684949d8,
   0x42811b89,
   0x2701d900,
   0x6b0949d6,
   0xd0074299,
   0x684648d3,
   0x20ff4bd4,
   0x3091681b,
   0x460bb29d,
   0xd0e9433a,
   0x6a304ecc,
   0x0fc706c0,
   0x06806a30,
   0x28010fc0,
   0x9802d10e,
   0xd1062802,
   0x684148c8,
   0x688048c6,
   0x20016141,
   0x98029000,
   0xffa0f7ff,
   0xd00b2f01,
   0x60f02005,
   0xff94f7ff,
   0x684048c0,
   0x61304ebe,
   0x29029902,
   0xe007d002,
   0xe7f52401,
   0x2c0168b1,
   0xd0078d89,
   0x60f01a40,
   0x202568b7,
   0x28025dc0,
   0xe018d003,
   0x30f01a40,
   0x48b6e7f5,
   0x0a2a6800,
   0x0a08b281,
   0xb2c91880,
   0x1889b2ea,
   0x10491040,
   0xb24ab240,
   0x23ff1811,
   0x1a103301,
   0x02001a59,
   0xfc40f000,
   0x98026170,
   0xd1012802,
   0x80702000,
   0x88738dba,
   0x68f06931,
   0x1a0918d5,
   0xd20342a9,
   0x684949a2,
   0xe7f86131,
   0x21009d02,
   0xd0052d02,
   0xd1032c01,
   0x1a086931,
   0x1ac11a80,
   0x1a406930,
   0x2c0160f0,
   0x9800d004,
   0xd0032800,
   0xbdfe2001,
   0xbdfe2000,
   0x43c02000,
   0xb530bdfe,
   0x69594b8f,
   0x24024d95,
   0xb2892201,
   0xd0042800,
   0x61e84893,
   0x43214391,
   0x4891e004,
   0x61e83812,
   0x43a14311,
   0x498d6159,
   0x6bc83940,
   0x40184b8d,
   0x43032303,
   0x431063cb,
   0xbd3063c8,
   0x20024982,
   0x60483940,
   0x68804881,
   0x487f7981,
   0xd0022902,
   0x60c12103,
   0x21044770,
   0x487ae7fb,
   0x62c12100,
   0x62012108,
   0xb5f84770,
   0x21ff4a78,
   0x4f7e6895,
   0x2e0068ae,
   0x0842d01a,
   0x42828ce8,
   0x79e8d216,
   0x434a08c1,
   0x1931b2d4,
   0x780b784a,
   0x43190211,
   0xd0022808,
   0xd0022820,
   0x5d31e008,
   0x1c60e006,
   0xf0001830,
   0x0201fbb1,
   0x43015d30,
   0x78004867,
   0xd0042800,
   0x280179a8,
   0x6c28d101,
   0x60396881,
   0xb570bdf8,
   0x08444b61,
   0x4a626899,
   0x42ac8ccd,
   0x79c9d202,
   0xe0000049,
   0x62d12120,
   0x29007819,
   0x2140d001,
   0xf7ff62d1,
   0x4857ffbe,
   0x38402103,
   0x60416001,
   0x20014953,
   0x60486008,
   0x21074852,
   0x495a6101,
   0x21006181,
   0xbd706201,
   0x4604b510,
   0xffd7f7ff,
   0xffa1f7ff,
   0xff90f7ff,
   0xf7ff2000,
   0x484aff6e,
   0x68822c02,
   0xd1006810,
   0x46218dd0,
   0xfecff7ff,
   0xb5f3bd10,
   0x4945460e,
   0x684a2000,
   0x4605b081,
   0x46944607,
   0x493ee015,
   0x49406acd,
   0x46626849,
   0x99011a8a,
   0xd900428a,
   0x493d2701,
   0x42846b0c,
   0x2c00d007,
   0x2001d001,
   0x2000e000,
   0xff45f7ff,
   0x433d4620,
   0x4a33d0e7,
   0x4d336a10,
   0x0fc006c0,
   0xd1032e00,
   0x68494931,
   0x615968ab,
   0xd0012f00,
   0xd0092800,
   0x46302401,
   0xfe70f7ff,
   0x302068a8,
   0x28027940,
   0xe014d006,
   0x60d02005,
   0xfe60f7ff,
   0xe00e2400,
   0x68004827,
   0x120123ff,
   0xb240b249,
   0x33011842,
   0x1a9a1a40,
   0x46110200,
   0xfb2af000,
   0x4a1e6168,
   0x61286850,
   0xd1122e00,
   0x798b68a9,
   0xd0042b00,
   0x1a408d89,
   0x300530ff,
   0x2300e008,
   0x8d89806b,
   0xd0022c00,
   0x30f01a40,
   0x1a40e000,
   0x68a860e8,
   0x8d87886b,
   0x692968ea,
   0x1a8918f8,
   0xd2034281,
   0x6849490d,
   0xe7f86129,
   0x2e002000,
   0x2c00d005,
   0x6928d003,
   0x1bc01a80,
   0x69291ac0,
   0x60e81a08,
   0xd0192c00,
   0xbdfe2000,
   0x40041100,
   0x40046000,
   0x40045040,
   0x21000ea0,
   0x40043000,
   0x40045280,
   0x40045180,
   0x40044040,
   0x0001f879,
   0xfff000ff,
   0x210087f8,
   0x0000aaaa,
   0x43c02000,
   0xb510e7e3,
   0xf7ff4604,
   0xf7ffff22,
   0xf7fffeec,
   0x2000fedb,
   0xfeb9f7ff,
   0x2c0048ff,
   0x68106882,
   0x8dd0d100,
   0xf7ff4621,
   0xbd10ff4c,
   0x4604b510,
   0xff0df7ff,
   0x210048f9,
   0x210662c1,
   0x49f86201,
   0x60c82002,
   0xf7ff2001,
   0x48f3fea0,
   0x68804621,
   0xf7ff6800,
   0xbd10ff36,
   0x00c9b510,
   0x0c1c5843,
   0x33c04bef,
   0x5844615c,
   0x1808619c,
   0x0c096841,
   0x684160d9,
   0x2a406119,
   0x6881d10e,
   0x49e90c0a,
   0x6882608a,
   0x68c160ca,
   0x0c094ae6,
   0x635132c0,
   0x68c049e4,
   0x60483940,
   0xb5f0bd10,
   0xb662b08d,
   0x684949e1,
   0xd47e02c9,
   0x21004cdb,
   0x910260a0,
   0x69819101,
   0x69059105,
   0x49dc204f,
   0x478800c0,
   0x43c02000,
   0x48da61a0,
   0x68a04780,
   0x5c0a2124,
   0x318049d2,
   0x3040618a,
   0x794049d1,
   0x60c83140,
   0x900c2000,
   0x688849cc,
   0x7c403020,
   0x94062400,
   0x940a9409,
   0x46269003,
   0xe1f1808c,
   0x270048c6,
   0x70076147,
   0x478048cb,
   0x614748cb,
   0x7ac148cb,
   0x07c97ac0,
   0x22020fc9,
   0x43014010,
   0x48c8d002,
   0xbdf0b00d,
   0x200049bc,
   0x08608048,
   0x68889001,
   0x30409000,
   0x28017900,
   0xd0119801,
   0xb2820040,
   0x1c42920b,
   0xb2801c80,
   0xb2929f00,
   0x92079008,
   0x7cf93720,
   0xf0009801,
   0x2900fa33,
   0xe017d003,
   0x18800042,
   0x9806e7eb,
   0xd01142a0,
   0x28009803,
   0x9903d04e,
   0x084907c0,
   0x91030fc0,
   0xd0022800,
   0x40487cb8,
   0x7c399003,
   0xf0009803,
   0x460efa19,
   0x94069800,
   0x00f16b40,
   0x5a429104,
   0x4f9e990c,
   0xd024428a,
   0xe05de000,
   0x1d899904,
   0x99045a43,
   0x1d099300,
   0x99045c43,
   0x5c421c89,
   0x1cc99904,
   0x200e5c41,
   0xfa02f000,
   0x220168b8,
   0x98046b41,
   0x5a082300,
   0x04004611,
   0xf9fef000,
   0xfa02f000,
   0x78014898,
   0xd1fc2903,
   0x8f0968b9,
   0x488a8079,
   0x98046887,
   0x5a086b79,
   0x6a38900c,
   0xd00e2800,
   0x90000041,
   0xf0004620,
   0x2900f9db,
   0xe020d00a,
   0x7c381c76,
   0x42b0b2f6,
   0x2600d8ba,
   0x2240e7b8,
   0xe0364621,
   0xd0122c00,
   0x30204638,
   0x07d37fc2,
   0x2301d018,
   0x439a7783,
   0x6c3877c2,
   0xd0022800,
   0x69924a75,
   0x200160c2,
   0x02c04a7b,
   0x69b86090,
   0x98009005,
   0xd1174281,
   0x30204638,
   0x4b6e7fc1,
   0xd401078a,
   0xe75b4878,
   0x77822202,
   0x401122fd,
   0x6c3877c1,
   0xd0012800,
   0x60c16999,
   0x496e2001,
   0x608802c0,
   0x900569f8,
   0x99004620,
   0xf998f000,
   0x98052240,
   0xfee0f7ff,
   0xd1042c00,
   0x6880485e,
   0x28027980,
   0x485cd00b,
   0x6c076880,
   0xd0192f00,
   0x46208a39,
   0xf984f000,
   0xd0062902,
   0x9806e012,
   0x1c802402,
   0x9006b280,
   0x4853e10a,
   0x88827cb9,
   0xd9074291,
   0x21002220,
   0xf7ff4638,
   0x484efebd,
   0x70012101,
   0x2000990b,
   0x008f43c0,
   0x484a51e8,
   0x79806880,
   0xd0042801,
   0xd0322800,
   0xd05f2802,
   0x4620e057,
   0xfe92f7ff,
   0x90024944,
   0x6a483180,
   0x04004a42,
   0x69923240,
   0x0c120612,
   0x9a074310,
   0x00924330,
   0x4a3c50a8,
   0x30406890,
   0x28017900,
   0x483cd109,
   0x6a803080,
   0x04006a09,
   0x4308b289,
   0x00899908,
   0x98025068,
   0xd1302800,
   0x38804835,
   0x02016b80,
   0x68804610,
   0x69006952,
   0x51c11889,
   0x4620e025,
   0xfe4df7ff,
   0x482c9002,
   0x6a413080,
   0x04094a2a,
   0x69923240,
   0x0c120612,
   0x9a074311,
   0x00924331,
   0x492450a9,
   0x31406889,
   0x29017909,
   0x4924d109,
   0x6a893180,
   0x06096a00,
   0x4301b280,
   0x00809808,
   0x98025029,
   0xd1002800,
   0xf7ff51e8,
   0x4919fc0d,
   0x688a2001,
   0x2a027992,
   0xe04fd04f,
   0xf7ff4620,
   0x4b15fd69,
   0x33809002,
   0x49136a58,
   0x31400400,
   0x4a106989,
   0x0c090609,
   0x99074308,
   0x00894330,
   0x68905068,
   0x79003040,
   0xd10e2801,
   0x3880480c,
   0x490b6bc0,
   0x31800600,
   0x04096a89,
   0x6a194308,
   0x4308b289,
   0x00899908,
   0x98025068,
   0xd1212800,
   0xe0194803,
   0x21000ea0,
   0x40046000,
   0x40045040,
   0x400451c0,
   0x40091040,
   0x00003fd1,
   0x00007b73,
   0x00000c2d,
   0x40041100,
   0x2100010c,
   0x04040003,
   0x2100028c,
   0x04060003,
   0x6b803880,
   0x02006951,
   0x51e81840,
   0xfbd2f7ff,
   0x2002e7a7,
   0x2a00780a,
   0x2200d007,
   0x51ea43d2,
   0xd9024284,
   0x1c52888a,
   0x9a02808a,
   0xd0161c52,
   0xb2a41ca4,
   0x9909688f,
   0x42888d38,
   0x8d7ad303,
   0x428a990a,
   0x4920d218,
   0xd1024288,
   0x42888d78,
   0x2101d012,
   0x0449481d,
   0x481d6081,
   0x4284e63a,
   0x1ca4d906,
   0xb2a49809,
   0xb2801c40,
   0xe7e19009,
   0x1c40980a,
   0xe7dd900a,
   0x98018fb9,
   0xf87af000,
   0xd1072900,
   0x28009801,
   0x8778d004,
   0x480f2101,
   0x608103c9,
   0x6881480f,
   0x42a18889,
   0xe607d900,
   0x480a2101,
   0x60810409,
   0x1e49480a,
   0x8d026880,
   0xd103428a,
   0x42888d40,
   0xe5edd100,
   0x98014905,
   0x87486889,
   0xe6052000,
   0x0000ffff,
   0x40041100,
   0x04030003,
   0x21000ea0,
   0x49068800,
   0xd1064288,
   0x21004805,
   0x49058501,
   0x20016241,
   0x20824770,
   0x00004770,
   0x00006801,
   0x210000ec,
   0x21000451,
   0x480db510,
   0x6b406b84,
   0x04e00141,
   0x43010ec0,
   0x4b0ab672,
   0xb2826818,
   0x43101558,
   0x48086018,
   0x601a6880,
   0x4a07b662,
   0x22907953,
   0x07224353,
   0xf7ff0f12,
   0xbd10fb1f,
   0x40045080,
   0x40040000,
   0x40044000,
   0x21000280,
   0x07810882,
   0x0ec90092,
   0x78c0ca0c,
   0x424940ca,
   0x408b3120,
   0x0211431a,
   0x06000a09,
   0x47704308,
   0x4801b403,
   0xbd019001,
   0x00007d3b,
   0x4801b403,
   0xbd019001,
   0x00007d1f,
   0x4801b403,
   0xbd019001,
   0x00007467,
   0x4801b403,
   0xbd019001,
   0x000044a3,
   0x4801b403,
   0xbd019001,
   0x000046ab,
   0x0001f879,
   0x0001f867,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
};
#define _NWORD_PATCHIMAGE_TOF 669

#define _NWORD_PATCHSYS_TOF 0



#ifndef _TOF_SYSRAM_START
#define _TOF_SYSRAM_START 0x20000000
#endif

#ifndef _TOF_CPERAM_START
#define _TOF_CPERAM_START 0x21000000
#endif

#define _TOF_SYS_PATCH_FIXED_ADDR 0x20000000

#define _TOF_PARSER_PATCH_TAB_OFFSET 0x0350
#define _TOF_PATCH_TAB_OFFSET 0x0358
#define _TOF_IRQPATCH_OFFSET 0x03E8
#define _TOF_PATCH_VEC_OFFSET 0x0448

PATCH_FUN_SPEC void enterTofCpePatch(void)
{
#if (_NWORD_PATCHIMAGE_TOF > 0)
   uint32_t *pPatchVec = (uint32_t *) (_TOF_CPERAM_START + _TOF_PATCH_VEC_OFFSET);

   memcpy(pPatchVec, patchImageTof, sizeof(patchImageTof));
#endif
}

PATCH_FUN_SPEC void enterTofSysPatch(void)
{
}

PATCH_FUN_SPEC void configureTofPatch(void)
{
   uint8_t *pParserPatchTab = (uint8_t *) (_TOF_CPERAM_START + _TOF_PARSER_PATCH_TAB_OFFSET);
   uint8_t *pPatchTab = (uint8_t *) (_TOF_CPERAM_START + _TOF_PATCH_TAB_OFFSET);


   pParserPatchTab[6] = 0;
   pPatchTab[64] = 1;
}

PATCH_FUN_SPEC void applyTofPatch(void)
{
   enterTofSysPatch();
   enterTofCpePatch();
   configureTofPatch();
}

PATCH_FUN_SPEC void refreshTofPatch(void)
{
   enterTofCpePatch();
   configureTofPatch();
}

PATCH_FUN_SPEC void rf_patch_cpe_tof(void)
{
   applyTofPatch();
}


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  _RF_PATCH_CPE_TOF_H
