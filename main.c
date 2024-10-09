#include "types.h"
#include <libetc.h>
#include <libgpu.h>
#include <libgte.h>
#include <libgs.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
//#include <setjmp.h>
//#include <unistd.h>
//#include <sys/syscall.h>

__attribute__((naked)) //common function given by the decompiler just attempting to define it here
void syscall(int param) {
    __asm__ volatile (
        "jal 0x0"
    );
}

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*(a)))
// Global variable declarations
extern uint8_t DAT_80116c56;
extern uint32_t DAT_80116c54; // changed from 8 to 32

char FUN_800946ac(uint8_t param_1)
{
    char cVar1;
  
    cVar1 = DAT_80116c56;
    DAT_80116c56 = param_1;
    if (param_1 != 0) {
        printf("SetGraphDebug:level:%d,type:%d reverse:%d\n", 
               (unsigned int)param_1, 
               (unsigned int)DAT_80116c54, 
               0);
    }
    return cVar1;
}

// Assuming these are global variables defined elsewhere
extern uint32_t DAT_80137140[];
extern uint32_t DAT_801371cc[];
extern uint32_t DAT_80137218[];
extern uint32_t DAT_801373d8[];

void FUN_800a1e38(void)
{
    int iVar1, iVar2, iVar5;
    uint32_t *puVar3, *puVar4;
    uint32_t local_1c[4] = {0, 0, 0, 0};
    uint16_t local_c = 0;
    uint16_t local_a = 0;
    uint8_t local_8 = 0;
    uint8_t local_7 = 0;
    ushort local_6 = 0xffff;
    ushort local_4 = 0xffff;

    for (iVar1 = 0, iVar2 = 0; iVar1 < 5; iVar1++, iVar2 += 0x1c) {
        puVar3 = (uint32_t *)((uintptr_t)&DAT_80137140 + iVar2);
        puVar4 = local_1c;
        for (iVar5 = 7; iVar5 > 0; iVar5--) {
            *puVar3++ = *puVar4++;
        }
    }
    for (iVar1 = 0, iVar2 = 0; iVar1 < 5; iVar1++, iVar2 += 4) {
        *(uint32_t *)((uintptr_t)&DAT_801371cc + iVar2) = 0;
    }
    for (iVar1 = 0, iVar2 = 0; iVar1 < 0x10; iVar1++, iVar2 += 0x1c) {
        puVar3 = (uint32_t *)((uintptr_t)&DAT_80137218 + iVar2);
        puVar4 = local_1c;
        for (iVar5 = 7; iVar5 > 0; iVar5--) {
            *puVar3++ = *puVar4++;
        }
    }
    for (iVar1 = 0, iVar2 = 0; iVar1 < 0x10; iVar1++, iVar2 += 4) {
        *(uint32_t *)((uintptr_t)&DAT_801373d8 + iVar2) = 0;
    }
}
// Assuming these are global variables defined elsewhere
extern uint16_t DAT_80137418[];
extern uint16_t DAT_8013741a[];
extern uint32_t DAT_8013741c[];
extern uint32_t DAT_80137420[];

void FUN_800a2ef8(void)
{
    int iVar1, iVar2;
  
    for (iVar1 = 0, iVar2 = 0; iVar1 < 0x80; iVar1++, iVar2 += 0xc) {
        *(uint16_t*)((uintptr_t)&DAT_80137418 + iVar2) = 0xffff;
        *(uint16_t*)((uintptr_t)&DAT_8013741a + iVar2) = 0xffff;
        *(uint32_t*)((uintptr_t)&DAT_8013741c + iVar2) = 0;
        *(uint32_t*)((uintptr_t)&DAT_80137420 + iVar2) = 0;
    }
}
// Assuming these are global variables defined elsewhere
extern uint32_t DAT_80122584[];
extern uint32_t DAT_80137a24[];

void FUN_800a3b20(void)
{
    bool bVar1;
    int iVar2, iVar3, iVar6;
    uint32_t *puVar4, *puVar5;
    uint32_t local_1c[7];

    // Copy data from DAT_80122584 to local_1c
    puVar5 = DAT_80122584;
    for (iVar6 = 0; iVar6 < 7; iVar6++) {
        local_1c[iVar6] = *puVar5++;
    }

    iVar2 = 0;
    iVar3 = 0;
    bVar1 = true;
    while (bVar1) {
        puVar4 = (uint32_t*)((uintptr_t)&DAT_80137a24 + iVar3);
        for (iVar6 = 0; iVar6 < 7; iVar6++) {
            *puVar4++ = local_1c[iVar6];
        }
        iVar2++;
        iVar3 += 0x1c;
        bVar1 = iVar2 < 0x10;
    }
}

// Assuming these are memory-mapped registers or specific memory locations
volatile uint32_t* const pRamffff9180 = (uint32_t*)0xffff9180;
volatile uint16_t* const pRamffff9182 = (uint16_t*)0xffff9182;
volatile uint16_t* const pRamffff9184 = (uint16_t*)0xffff9184;
volatile uint16_t* const pRamffff9186 = (uint16_t*)0xffff9186;
volatile uint8_t* const pRamffff9188 = (uint8_t*)0xffff9188;
volatile uint8_t* const pRamffff9189 = (uint8_t*)0xffff9189;
volatile uint32_t* const pRamffff918c = (uint32_t*)0xffff918c;

void initializeHardwareRegisters(void)
{
    *pRamffff9180 = 0;
    *pRamffff9184 = 0;
    *pRamffff9182 = 0;
    *pRamffff9186 = 0;
    *pRamffff9188 = 0;
    *pRamffff9189 = 2;
    *pRamffff918c = 0;
}
// Assuming this is a global variable defined elsewhere
extern uint16_t DAT_8013d3a0[];

void FUN_800c2838(void)
{
    int iVar1, iVar2;
  
    for (iVar1 = 0, iVar2 = 0; iVar1 < 6; iVar1++, iVar2 += 0x24) {
        *(uint16_t*)((uintptr_t)&DAT_8013d3a0 + iVar2) = 0;
        *(uint16_t*)((uintptr_t)&DAT_8013d3a0 + iVar2 + 2) = 0;
    }
}
// Assuming these are global variables defined elsewhere
extern uint16_t uRamffff93dc;
extern uint16_t uRamffff92f2;
extern uint32_t DAT_80150c8c;
extern uint16_t DAT_80150c90;
extern uint16_t DAT_80150c92;
extern uint8_t DAT_80150c94;
extern uint16_t uRamffff93d6;
extern uint16_t uRamffff93d8;
extern uint16_t uRamffff9390;
extern int16_t sRamffff9392;
extern uint16_t uRamffff93d4;
extern uint16_t uRamffff93d2;
extern uint16_t uRamffff93d0;
extern uint16_t uRamffff92f0;
extern uint8_t DAT_80150c96;
extern uint32_t DAT_80150c98;
extern uint16_t DAT_80150c9c;
extern uint16_t DAT_80150c9e;
extern uint8_t DAT_80150c9a;
extern uint8_t DAT_80150c9b;
extern uint8_t DAT_80150ca2;
extern uint8_t DAT_80150ca1;
extern uint8_t DAT_80150ca0;
extern uint16_t DAT_80150ca4;
extern uint16_t DAT_80150ca6;
extern uint16_t DAT_80150caa;
extern uint16_t DAT_80150ca8;
extern uint32_t DAT_80150cac;
extern uint16_t uRamffff92f4;

// Function prototype
extern uint32_t FUN_80092a80(int, int, int, int);

void FUN_800dce04(void)
{
    uRamffff93dc = 0x2580;
    uRamffff92f2 = 0xff79;
    DAT_80150c8c = 0;
    DAT_80150c90 = 0xff90;
    DAT_80150c92 = 0xffbe;
    DAT_80150c94 = 8;
    uRamffff93d6 = 0;
    uRamffff93d8 = 0;
    uRamffff9390 = 8;
    sRamffff9392 = 0;
    uRamffff93d4 = 0;
    uRamffff93d2 = 0;
    uRamffff93d0 = 0;
    uRamffff92f0 = 0;
    DAT_80150c96 = 0x10;
    DAT_80150c98 = FUN_80092a80(0, 0, 0x380, 0x1c0);
    DAT_80150c9c = 0x100;
    DAT_80150c9e = 499;
    DAT_80150c9a = 0x78;
    DAT_80150c9b = 0xc0;
    DAT_80150ca2 = 0x80;
    DAT_80150ca1 = 0x80;
    DAT_80150ca0 = 0x80;
    DAT_80150ca4 = 3;
    DAT_80150ca6 = 0xd;
    DAT_80150caa = 0x1000;
    DAT_80150ca8 = 0x1000;
    DAT_80150cac = sRamffff9392 * 0x6000;
    uRamffff92f4 = 1;
}
void FUN_80092328(uint32_t *param_1, int param_2)
{
    int iVar1;
  
    iVar1 = param_2 - 1;
    if (param_2 != 0) {
        do {
            *param_1 = 0;
            iVar1 = iVar1 - 1;
            param_1 = param_1 + 1;
        } while (iVar1 != -1);
    }
}

void FUN_80092500(uint32_t *param_1, int param_2)
{
    int iVar1;
  
    iVar1 = param_2 - 1;
    if (param_2 != 0) {
        do {
            *param_1 = 0;
            iVar1 = iVar1 - 1;
            param_1 = param_1 + 1;
        } while (iVar1 != -1);
    }
}
// Assuming these are global variables defined elsewhere
extern uint16_t I_MASK;
extern uint32_t DAT_80115a5c;
extern uint16_t DAT_80115a8c;
extern int DAT_80115a60[];

int FUN_800920c8(unsigned int param_1, int param_2)
{
    uint16_t uVar1;
    int *piVar2;
    uint16_t wVar3;
    int iVar4;
  
    wVar3 = I_MASK;
    piVar2 = &DAT_80115a60[param_1];
    iVar4 = *piVar2;
    if ((param_2 != iVar4) && (DAT_80115a5c != 0)) {
        I_MASK = 0;
        if (param_2 == 0) {
            uVar1 = ~(uint16_t)(1 << (param_1 & 0x1f));
            *piVar2 = 0;
            wVar3 = wVar3 & uVar1;
            DAT_80115a8c = DAT_80115a8c & uVar1;
        }
        else {
            *piVar2 = param_2;
            uVar1 = (uint16_t)(1 << (param_1 & 0x1f));
            wVar3 = wVar3 | uVar1;
            DAT_80115a8c = DAT_80115a8c | uVar1;
        }
        /**if (param_1 == 0) {
            ChangeClearPAD(param_2 == 0);
            ChangeClearRCnt(3, param_2 == 0);
        }
        if (param_1 == 4) {
            ChangeClearRCnt(0, param_2 == 0);
        }
        if (param_1 == 5) {
            ChangeClearRCnt(1, param_2 == 0);
        }
        if (param_1 == 6) {
            ChangeClearRCnt(2, param_2 == 0);
        }**/
    }
    I_MASK = wVar3;
    return iVar4;
}
// Assuming these are global variables defined elsewhere
extern uint32_t TMR_HRETRACE_MODE;
extern uint32_t DAT_80116b30;
extern uint32_t DAT_80116b04;

// Labels (assuming they are function pointers)
extern void LAB_80092468(void);
extern void LAB_800924d4(void);

void* FUN_80092530(void)
{
    TMR_HRETRACE_MODE = 0x107;
    DAT_80116b30 = 0;
    FUN_80092500(&DAT_80116b04, 8);
    //FUN_800920c8(0, &LAB_80092468);//FUN_8009237c(0, &LAB_80092468);
    return &LAB_800924d4;
}

void FUN_800927b4(uint32_t *param_1, int param_2)
{
    int iVar1;
  
    iVar1 = param_2 - 1;
    if (param_2 != 0) {
        do {
            *param_1 = 0;
            iVar1 = iVar1 - 1;
            param_1 = param_1 + 1;
        } while (iVar1 != -1);
    }
}

// Assuming these are global variables defined elsewhere
extern uint32_t DMA_DICR;
extern uint32_t DAT_80116b38;//[];
extern uint32_t DMA_MDEC_IN_MADR[];

void LAB_80092588(void)
{
    int iVar1, iVar2;
    uint32_t uVar3;
    uint32_t *puVar4;
  
    uVar3 = (DMA_DICR >> 0x18) & 0x7f;
    if (uVar3 != 0) {
        do {
            puVar4 = &DAT_80116b38;
            for (iVar1 = 0; (uVar3 != 0 && iVar1 < 7); iVar1++) {
                if ((uVar3 & 1) != 0) {
                    DMA_DICR = DMA_DICR & ((1 << ((iVar1 + 0x18U) & 0x1f)) | 0xffffffU);
                    if (*puVar4 != 0) {
                        ((void (*)())*puVar4)();
                    }
                }
                puVar4++;
                uVar3 >>= 1;
            }
            uVar3 = (DMA_DICR >> 0x18) & 0x7f;
        } while (uVar3 != 0);
    }
    if (((DMA_DICR & 0xff000000) == 0x80000000) || ((DMA_DICR & 0x8000) != 0)) {
        printf("DMA bus error: code=%08x\n", DMA_DICR);
        for (iVar1 = 0; iVar1 < 7; iVar1++) {
            printf("MADR[%d]=%08x\n", iVar1, DMA_MDEC_IN_MADR[iVar1 * 4]);
        }
    }
}

// Assuming these are global variables defined elsewhere
extern uint32_t DMA_DICR;

int LAB_80092708(int param_1, int param_2)
{
    uint32_t *piVar1;
    int iVar2;
  
    piVar1 = &DAT_80116b38;//[param_1];
    iVar2 = *piVar1;
    if (param_2 != iVar2) {
        if (param_2 == 0) {
            *piVar1 = 0;
            DMA_DICR = (DMA_DICR & 0xffffff | 0x800000) & ~(1 << ((param_1 + 0x10U) & 0x1f));
        }
        else {
            *piVar1 = param_2;
            DMA_DICR = (DMA_DICR & 0xffffff) | (1 << ((param_1 + 0x10U) & 0x1f)) | 0x800000U;
        }
    }
    return iVar2;
}
// Assuming these are global variables defined elsewhere
extern uint32_t DMA_DICR;
// Labels (assuming they are function pointers)

void* FUN_800927dc(void)
{
    //FUN_800927b4(&DAT_80116b38, 8);
    DMA_DICR = 0;
    //FUN_800920c8(3, &LAB_80092588); //
    return &LAB_80092708;
}

// Assuming these are global variables defined elsewhere
extern uint32_t I_STAT;
extern uint32_t DMA_DPCR;
//extern jmp_buf DAT_80115a94;
extern void* DAT_80115a98;
extern void* DAT_80116ad8;
extern void* DAT_80116ac8;
extern uint16_t DAT_80116a74;


uint16_t* FUN_80091e20(void)
{
    uint16_t* puVar1 = NULL;
    int iVar2;
  
    if (DAT_80115a5c == 0) {
        I_MASK = 0;
        I_STAT = 0;
        DMA_DPCR = 0x33333333;
        FUN_80092328(&DAT_80115a5c, 0x41a);
        /**iVar2 = setjmp(DAT_80115a94);
        if (iVar2 != 0) {
            FUN_80091ef8();
        }**/
        DAT_80115a98 = &DAT_80116a74;
        //HookEntryInt(&DAT_80115a94);
        DAT_80115a5c = 1;
        DAT_80116ad8 = FUN_80092530();
        DAT_80116ac8 = FUN_800927dc();
        //FUN_80090830(); // Ghidra didnt define
        puVar1 = (uint16_t*)&DAT_80115a5c;
        //syscall(0);//FUN_80090948();
    }
    return puVar1;
}

// Assuming these are global variables defined elsewhere
extern uint32_t DAT_80128094;
extern uint32_t DAT_80128528;
extern uint32_t DAT_80128524;
extern char* DAT_8012852c;

// Function prototype
extern long S_M_INIT_OBJ_4C(void);

long SpuInitMalloc(long num, char *top)
{
    uint32_t uVar1;
    long lVar2;
  
    uVar1 = DAT_80128094;
    if (num < 1) {
        lVar2 = S_M_INIT_OBJ_4C();
        return lVar2;
    }
    
    top[0] = 0x10;
    top[1] = 0x10;
    top[2] = 0x00;
    top[3] = 0x40;
    
    DAT_80128528 = 0;
    DAT_80128524 = num;
    DAT_8012852c = top;
    
    *(int32_t *)(top + 4) = (0x10000 << (uVar1 & 0x1f)) - 0x1010;
    
    return num;
}

// Assuming these are defined elsewhere
extern uint16_t DAT_801280e0[];
extern uint16_t VOICE_00_ADPCM_SAMPLE_RATE[];
extern uint16_t VOICE_00_LEFT_RIGHT[];
extern uint16_t VOICE_00_ADSR_ATT_DEC_SUS_REL[];
extern uint16_t DAT_1f801c0a[];

// Function prototypes
extern uint16_t FUN_800c9398(uint8_t, uint8_t, uint8_t, uint8_t);
extern void FUN_800c7048(uint32_t, uint32_t);
extern void S_SVA_OBJ_1A0(uint16_t, uint8_t);
extern void S_SVA_OBJ_280(uint16_t, uint8_t);
extern void S_SVA_OBJ_480(void);
extern void S_SVA_OBJ_5C0(void);

typedef struct {
    uint32_t mask;
    uint32_t voice;
    uint16_t pitch;
    uint16_t sample_note;
    uint16_t note;
    struct {
        int16_t left;
        int16_t right;
    } volume;
    struct {
        uint16_t left;
        uint16_t right;
    } volmode;
    uint32_t addr;
    uint32_t loop_addr;
    uint16_t adsr1;
    uint16_t adsr2;
    uint8_t ar;
    uint8_t dr;
    uint8_t sr;
    uint8_t rr;
    uint8_t sl;
    uint8_t a_mode;
    uint8_t s_mode;
    uint8_t r_mode;
} SpuVoiceAttr;

/**typedef struct {
    uint32_t mask;
    uint32_t voice;
    uint16_t pitch;
    uint32_t addr;
    uint16_t adsr1;
    struct {
        uint16_t left;
        uint16_t right;
    } volume;
    uint16_t adsr2;
} SpuVoiceAttr;**/

void SpuSetVoiceAttr(SpuVoiceAttr *arg)
{
    bool bVar2 = arg->mask == 0;
    uint32_t uVar9 = arg->mask;
    uint16_t *puVar11 = DAT_801280e0;

    for (uint32_t uVar10 = 0; uVar10 <= 0x17; uVar10++) {
        if ((arg->voice & (1 << (uVar10 & 0x1f))) != 0) {
            if (bVar2 || (uVar9 & 0x10)) {
                VOICE_00_ADPCM_SAMPLE_RATE[uVar10 * 8] = arg->pitch;
            }
            if (bVar2 || (uVar9 & 0x40)) {
                puVar11[uVar10] = arg->sample_note;
            }
            if (bVar2 || (uVar9 & 0x20)) {
                uint16_t wVar3 = FUN_800c9398(puVar11[uVar10] >> 8, puVar11[uVar10] & 0xff, arg->note >> 8, arg->note & 0xff);
                VOICE_00_ADPCM_SAMPLE_RATE[uVar10 * 8] = wVar3;
            }
            if (bVar2 || (uVar9 & 1)) {
                uint16_t uVar6 = 0;
                uint16_t uVar5 = arg->volume.left & 0x7fff;
                if (bVar2 || (uVar9 & 4)) {
                    switch(arg->volmode.left - 1) {
                        case 0: uVar6 = 0x8000; break;
                        case 1: uVar6 = 0x9000; break;
                        case 2: uVar6 = 0xa000; break;
                        case 3: uVar6 = 0xb000; break;
                        case 4: uVar6 = 0xc000; break;
                        case 5: uVar6 = 0xd000; break;
                        case 6: uVar6 = 0xe000; break;
                    }
                }
                if (uVar6 != 0) {
                    if (arg->volume.left > 0x7f) {
                        S_SVA_OBJ_1A0(uVar6, 0x7f);
                        return;
                    }
                    if (arg->volume.left < 0) {
                        uVar5 = 0;
                    }
                }
                VOICE_00_LEFT_RIGHT[uVar10 * 2] = uVar5 | uVar6;
            }
            // ... (similar code for right volume)
            if (bVar2 || (uVar9 & 0x80)) {
                FUN_800c7048(uVar10 << 3 | 3, arg->addr);
            }
            if (bVar2 || (uVar9 & 0x10000)) {
                FUN_800c7048(uVar10 << 3 | 7, arg->loop_addr);
            }
            if (bVar2 || (uVar9 & 0x20000)) {
                VOICE_00_ADSR_ATT_DEC_SUS_REL[uVar10 * 8] = arg->adsr1;
            }
            if (bVar2 || (uVar9 & 0x40000)) {
                DAT_1f801c0a[uVar10 * 8] = arg->adsr2;
            }
            // ... (similar code for other attributes)
        }
    }
    S_SVA_OBJ_5C0();
}

// Assuming these are global variables defined elsewhere
extern uint16_t DAT_8014edfa;
extern uint16_t DAT_8014e715[];
extern uint16_t DAT_8014e6fc[];
extern uint8_t DAT_8014e6f8[];
extern uint16_t DAT_8014ec08;
extern uint16_t DAT_8014ec0a;
extern uint16_t DAT_8014ec0c;
extern uint16_t DAT_8014ec0e;

void FUN_800d1428(void)
{
    uint32_t uVar1 = DAT_8014edfa;
    uint16_t uVar2, uVar3;
  
    if (uVar1 < 0x10) {
        uVar3 = (uint16_t)(1 << (uVar1 & 0x1f));
        uVar2 = 0;
    }
    else {
        uVar3 = 0;
        uVar2 = (uint16_t)(1 << ((uVar1 - 0x10) & 0x1f));
    }
  
    DAT_8014e715[uVar1 * 0x36] = 0;
    DAT_8014e6fc[uVar1 * 0x1b] = 0;
    DAT_8014e6f8[uVar1 * 0x1b] = 0;
  
    DAT_8014ec08 |= uVar3;
    DAT_8014ec0a &= ~DAT_8014ec08;
    DAT_8014ec0c |= uVar2;
    DAT_8014ec0e &= ~DAT_8014ec0c;
}
// Assuming this is defined elsewhere
extern int16_t VOICE_00_ADSR_CURR_VOLUME[];

void SpuGetVoiceEnvelope(int vNum, int16_t *envx)
{
    *envx = VOICE_00_ADSR_CURR_VOLUME[vNum * 8];
}
uint S_SAV_OBJ_2AC(void)

{
  uint in_t2;
  
  return in_t2 & 0xffffff;
}
uint S_SAV_OBJ_2A4(void){
  uint in_v0;
  uint in_t0;
  
  return in_t0 & (in_v0 | 0xffff) & 0xffffff;
}
uint S_SAV_OBJ_2B4(void){
  uint in_v0;
  uint in_t2;
  
  return in_t2 & in_v0;
}
// Assuming these are defined elsewhere
extern uint16_t DAT_80128510;
extern uint16_t DAT_8014dbec[];
extern uint32_t DAT_801280dc;
extern uint16_t VOICE_00_LEFT_RIGHT[];


uint32_t _SpuSetAnyVoice(int param_1, uint32_t param_2, int param_3, int param_4)
{
    uint16_t uVar5 = (uint16_t)param_2;
    uint16_t uVar1 = (uint16_t)(param_2 >> 16);

    switch (param_1) {
        case 1:
            if (DAT_80128510 & 1) {
                DAT_8014dbec[param_3] |= uVar5;
                DAT_8014dbec[param_4] |= uVar1 & 0xff;
                DAT_801280dc |= 1 << ((param_3 - 0xc6) >> 1 & 0x1f);
                return S_SAV_OBJ_2AC();//S_SAV_OBJ_130();
            } else {
                VOICE_00_LEFT_RIGHT[param_3] |= uVar5;
                VOICE_00_LEFT_RIGHT[param_4] |= uVar1 & 0xff;
                return S_SAV_OBJ_2AC();
            }

        case 8:
            if (DAT_80128510 & 1) {
                DAT_8014dbec[param_3] = uVar5;
                DAT_8014dbec[param_4] = uVar1 & 0xff;
                DAT_801280dc |= 1 << ((param_3 - 0xc6) >> 1 & 0x1f);
                return S_SAV_OBJ_2A4();
            } else {
                VOICE_00_LEFT_RIGHT[param_3] = uVar5;
                VOICE_00_LEFT_RIGHT[param_4] = uVar1 & 0xff;
                return param_2 & 0xffffff;
            }

        case 0:
            if (DAT_80128510 & 1) {
                DAT_8014dbec[param_3] &= ~uVar5;
                DAT_8014dbec[param_4] &= ~(uVar1 & 0xff);
                DAT_801280dc |= 1 << ((param_3 - 0xc6) >> 1 & 0x1f);
                return S_SAV_OBJ_2AC();//S_SAV_OBJ_200();
            } else {
                VOICE_00_LEFT_RIGHT[param_3] &= ~uVar5;
                VOICE_00_LEFT_RIGHT[param_4] &= ~(uVar1 & 0xff);
                return S_SAV_OBJ_2AC();
            }

        default:
            return S_SAV_OBJ_2B4();
    }
}
// Assuming this is defined elsewhere
extern uint32_t DAT_801280b0;

void S_SK_OBJ_1AC(void)
{
    // Get the value from v0 register
    uint32_t in_v0;
    asm("move %0, $v0" : "=r" (in_v0));

    // Assign the value to DAT_801280b0
    DAT_801280b0 = in_v0;
}


// Assuming these are defined elsewhere
extern uint16_t DAT_80128510;
extern uint32_t DAT_801280b0;
extern uint32_t DAT_801280dc;
extern uint32_t DAT_801280d8;
extern uint16_t DAT_8014dd74;
extern uint16_t DAT_8014dd76;
extern uint16_t DAT_8014dd78;
extern uint16_t DAT_8014dd7a;

// SPU registers (assuming these are memory-mapped)
extern struct {
    uint16_t _0_2_;
    uint16_t _2_2_;
} SPU_VOICE_KEY_OFF;

extern struct {
    uint16_t _0_2_;
    uint16_t _2_2_;
} SPU_VOICE_KEY_ON;

void SpuSetKey(long on_off, uint32_t voice_bit) //this function seems like it will act weird
{
    uint32_t uVar2 = voice_bit & 0xffffff;
    uint16_t uVar1 = (uint16_t)uVar2;
    uint16_t uVar3 = (uint16_t)(uVar2 >> 16);

    if (on_off == 0) {
        if ((DAT_80128510 & 1) == 0) {
            DAT_801280b0 &= ~uVar2;
            SPU_VOICE_KEY_OFF._0_2_ = uVar1;
            SPU_VOICE_KEY_OFF._2_2_ = uVar3;
        }
        else {
            DAT_801280dc |= 1;
            DAT_801280d8 &= ~uVar2;
            if ((DAT_8014dd74 & uVar2) != 0) {
                DAT_8014dd74 &= (uint16_t)~uVar2;
            }
            DAT_8014dd78 = uVar1;
            DAT_8014dd7a = uVar3;
            if ((DAT_8014dd76 & uVar3) != 0) {
                DAT_8014dd76 &= ~uVar3;
                //return;//S_SK_OBJ_1B4(); // fucntion that does nothing
            }
        }
    }
    else if (on_off == 1) {
        if ((DAT_80128510 & 1) == 0) {
            SPU_VOICE_KEY_ON._0_2_ = uVar1;
            SPU_VOICE_KEY_ON._2_2_ = uVar3;
            S_SK_OBJ_1AC();
            return;
        }
        else {
            DAT_801280dc |= 1;
            DAT_801280d8 |= uVar2;
            if ((DAT_8014dd78 & uVar2) != 0) {
                DAT_8014dd78 &= ~uVar1;
            }
            DAT_8014dd74 = uVar1;
            DAT_8014dd76 = uVar3;
            if ((DAT_8014dd7a & uVar3) != 0) {
                DAT_8014dd7a &= ~uVar3;
                //return;//S_SK_OBJ_1B4();
            }
        }
    }
    return;
}

// Assuming these are defined elsewhere
extern uint8_t DAT_8014e6b4;
extern uint32_t DAT_8014e6b8[];
extern uint8_t DAT_8014edd8;
extern short DAT_8014e6fe[];
extern uint16_t DAT_8014ee02;
extern uint16_t DAT_8014ec08;
extern uint16_t DAT_8014ec0a;
extern uint16_t DAT_8014ec0c;
extern uint16_t DAT_8014ec0e;
extern void (*DAT_8014ec10)(int);
extern void (*DAT_8014ec14)(int);
extern uint8_t DAT_8014ec18[];
extern int16_t DAT_8014ec30[];
extern uint16_t DAT_8014ec34[];
extern uint16_t DAT_8014ec36[];
extern uint16_t DAT_8014ec38[];
extern uint16_t DAT_8014ec3a[];
extern uint16_t DAT_8014e716[];
//extern short DAT_8014e6fe[];
extern int DAT_8014e722[];
extern uint16_t DAT_8014e6ae;
extern uint16_t DAT_8014e6ac;
extern uint16_t DAT_8014e6b0;
extern uint16_t DAT_8014e6b2;


void FUN_800cfc00(void)
{
    DAT_8014e6b4 = (DAT_8014e6b4 + 1) & 0xf;
    DAT_8014e6b8[DAT_8014e6b4] = 0;

    for (uint32_t uVar4 = 0; uVar4 < DAT_8014edd8; uVar4++) {
        SpuGetVoiceEnvelope(uVar4, &DAT_8014e6fe[uVar4 * 0x1b]);
        if (DAT_8014e6fe[uVar4 * 0x1b] == 0) {
            DAT_8014e6b8[DAT_8014e6b4] |= 1 << (uVar4 & 0x1f);
        }
    }

    if (DAT_8014ee02 == 0) {
        uint32_t uVar4 = 0xFFFFFFFF;
        for (int i = 0; i < 15; i++) {
            uVar4 &= DAT_8014e6b8[i];
        }

        for (uint32_t uVar5 = 0; uVar5 < DAT_8014edd8; uVar5++) {
            uint32_t uVar3 = 1 << (uVar5 & 0x1f);
            if ((uVar4 & uVar3) != 0) {
                if (DAT_8014e715[uVar5 * 0x36] == 2) {
                    uint32_t uVar1 = (uVar5 < 16) ? uVar3 : (1 << ((uVar5 - 16) & 0x1f));
                    _SpuSetAnyVoice(0, (uVar1 & 0xff) << 16 | (uint16_t)uVar3,0xca,0xcb);//FUN_800c7e98(0, (uVar1 & 0xff) << 16 | (uint16_t)uVar3);
                }
                DAT_8014e715[uVar5 * 0x36] = 0;
            }
        }
    }

    DAT_8014ec0a &= ~DAT_8014ec08;
    DAT_8014ec0e &= ~DAT_8014ec0c;

    /**for (int iVar6 = 0; iVar6 < 24; iVar6++) {
        if (*(int16_t*)(&DAT_8014e716 + iVar6 * 0x36) != 0) {
            DAT_8014ec10(iVar6);
        }
        if (*(int16_t*)(&DAT_8014e722 + iVar6 * 0x36) != 0) {
            DAT_8014ec14(iVar6);
        }
    }**/ //figure this out later

    for (uint32_t uVar4 = 0; uVar4 < 24; uVar4++) {
        SpuVoiceAttr local_68 = {0};
        local_68.voice = 1 << (uVar4 & 0x1f);

        if (DAT_8014ec18[uVar4] & 1) {
            local_68.mask |= 3;
            local_68.volume.left = DAT_8014ec30[uVar4 * 8];
            local_68.volume.right = DAT_8014ec30[uVar4 * 8 + 1];
        }
        if (DAT_8014ec18[uVar4] & 4) {
            local_68.mask |= 0x10;
            local_68.pitch = DAT_8014ec34[uVar4 * 8];
        }
        if (DAT_8014ec18[uVar4] & 8) {
            local_68.mask |= 0x80;
            local_68.addr = (uint32_t)DAT_8014ec36[uVar4 * 8] << 3;
        }
        if (DAT_8014ec18[uVar4] & 0x10) {
            local_68.mask |= 0x60000;
            local_68.adsr1 = DAT_8014ec38[uVar4 * 8];
            local_68.adsr2 = DAT_8014ec3a[uVar4 * 8];
        }

        if (local_68.mask != 0) {
            SpuSetVoiceAttr(&local_68);
        }

        DAT_8014ec18[uVar4] = 0;
    }

    SpuSetKey(0, ((uint32_t)DAT_8014ec0c << 16) | DAT_8014ec08);
    SpuSetKey(1, ((uint32_t)DAT_8014ec0e << 16) | DAT_8014ec0a);
    _SpuSetAnyVoice(8, ((uint32_t)DAT_8014e6ac << 16) | DAT_8014e6ae,0xcc,0xcd);//FUN_800c8a18(8, ((uint32_t)DAT_8014e6ac << 16) | DAT_8014e6ae);
    _SpuSetAnyVoice(8, ((uint32_t)DAT_8014e6b0 << 16) | DAT_8014e6b2,0xca,0xcb);//FUN_800c7e98(8, ((uint32_t)DAT_8014e6b0 << 16) | DAT_8014e6b2);

    DAT_8014ec08 = 0;
    DAT_8014ec0c = 0;
    DAT_8014ec0a = 0;
    DAT_8014ec0e = 0;
    DAT_8014e6b2 = 0;
    DAT_8014e6b0 = 0;
}
// Assuming these are global variables defined elsewhere
extern uint32_t DAT_8014ee00;
extern char DAT_8014ef58;
//extern uint8_t DAT_8014ec30[];
extern uint8_t DAT_8014ec18[];
extern uint16_t DAT_8014edda;
extern uint8_t DAT_8014edc8[];
extern uint8_t DAT_8014edd8;
extern uint16_t DAT_8014e6fa[];
extern uint8_t DAT_8014e6f8[];
extern uint16_t DAT_8014e715[];
extern uint16_t DAT_8014e6fc[];
extern uint16_t DAT_8014e708[];
extern uint16_t DAT_8014e70a[];
extern uint16_t DAT_8014e70c[];
extern uint8_t DAT_8014e70e[];
extern uint16_t DAT_8014e700[];
extern uint16_t DAT_8014e704[];
extern uint8_t DAT_8014e702[];
extern uint16_t DAT_8014e718[];
extern uint16_t DAT_8014e71a[];
extern uint16_t DAT_8014e71c[];
extern uint16_t DAT_8014e724[];
extern uint16_t DAT_8014e726[];
extern uint16_t DAT_8014e728[];
extern uint16_t DAT_8014e72a[];
extern uint16_t DAT_8014e71e[];
extern uint16_t DAT_8014edfa;
extern uint32_t DAT_8014edb4;
extern uint16_t DAT_8014edbc;
extern uint16_t DAT_8014edbe;
extern uint32_t DAT_8014edb8;
extern uint16_t DAT_8014ec0a;
extern uint16_t DAT_8014ec0e;
extern uint16_t DAT_8014e6ae;
extern uint16_t DAT_8014e6ac;
extern uint16_t DAT_8014e6b2;
extern uint16_t DAT_8014e6b0;
extern uint16_t DAT_8014ee02;
extern uint32_t DAT_8014edb0;
extern uint8_t DAT_8014eddc;
extern uint32_t DAT_801280a0;



void FUN_800d0090(uint8_t param_1)
{
    uint32_t uVar1, uVar2;
    uint16_t uVar3;
    SpuVoiceAttr local_60;
  
    DAT_801280a0 = (param_1 != 1);//FUN_800c8fd8(0);
    DAT_8014ee00 = 0;
    SpuInitMalloc(0x20, &DAT_8014ef58);

    for (uVar3 = 0; uVar3 < 0xc0; uVar3++) {
        DAT_8014ec30[uVar3] = 0;
    }

    for (uVar3 = 0; uVar3 < 0x18; uVar3++) {
        DAT_8014ec18[uVar3] = 0;
    }

    DAT_8014edda = 0;

    for (uVar3 = 0; uVar3 < 0x10; uVar3++) {
        DAT_8014edc8[uVar3] = 0;
    }

    DAT_8014edd8 = param_1;
    if (param_1 > 0x17) {
        DAT_8014edd8 = 0x18;
    }

    local_60.mask = 0x60093;
    local_60.pitch = 0x1000;
    local_60.addr = 0x1000;
    local_60.adsr1 = 0x80ff;
    local_60.volume.left = 0;
    local_60.volume.right = 0;
    local_60.adsr2 = 0x4000;

    for (uVar1 = 0; uVar1 < DAT_8014edd8; uVar1++) {
        uVar2 = uVar1 & 0xffff;
        local_60.voice = 1 << (uVar1 & 0x1f);
        DAT_8014e6fa[uVar2 * 0x1b] = 0x18;
        DAT_8014e6f8[uVar2 * 0x1b] = 0xff;
        DAT_8014e715[uVar2 * 0x1b] = 0;
        DAT_8014e6fc[uVar2 * 0x1b] = 0;
        DAT_8014e6fe[uVar2 * 0x1b] = 0;
        DAT_8014e708[uVar2 * 0x1b] = 0xffff;
        DAT_8014e70a[uVar2 * 0x1b] = 0;
        DAT_8014e70c[uVar2 * 0x1b] = 0;
        DAT_8014e70e[uVar2 * 0x1b] = 0xff;
        DAT_8014e700[uVar2 * 0x1b] = 0;
        DAT_8014e704[uVar2 * 0x1b] = 0;
        DAT_8014e702[uVar2 * 0x1b] = 0x40;
        DAT_8014e716[uVar2 * 0x1b] = 0;
        DAT_8014e718[uVar2 * 0x1b] = 0;
        DAT_8014e71a[uVar2 * 0x1b] = 0;
        DAT_8014e71c[uVar2 * 0x1b] = 0;
        DAT_8014e722[uVar2 * 0x1b] = 0;
        DAT_8014e724[uVar2 * 0x1b] = 0;
        DAT_8014e726[uVar2 * 0x1b] = 0;
        DAT_8014e728[uVar2 * 0x1b] = 0;
        DAT_8014e72a[uVar2 * 0x1b] = 0;
        DAT_8014e71e[uVar2 * 0x1b] = 0;
        SpuSetVoiceAttr(&local_60);
        DAT_8014edfa = (uint16_t)uVar1;
        FUN_800d1428();
    }

    DAT_8014edb4 = 0;
    DAT_8014edbc = 0x3fff;
    DAT_8014edbe = 0x3fff;
    DAT_8014edb8 = 0;
    DAT_8014ec0a = 0;
    DAT_8014ec0e = 0;
    DAT_8014ec08 = 0;
    DAT_8014e6ae = 0;
    DAT_8014e6ac = 0;
    DAT_8014e6b2 = 0;
    DAT_8014e6b0 = 0;
    DAT_8014ee02 = 0;
    DAT_8014edb0 = 0;
    DAT_8014eddc = 0x80;
    FUN_800cfc00();
}

// Assuming these are global variables defined elsewhere
extern uint16_t VOICE_00_LEFT_RIGHT[];
extern uint16_t DAT_8012880c[];
extern uint16_t SPU_MAIN_VOL_L[];
extern uint16_t DAT_8012881c[];
extern uint8_t UNK_8014dd88[];
extern uint32_t DAT_8014e588;
extern uint32_t DAT_8014e58c;
extern uint32_t DAT_8014e590;

void FUN_800cd37c(void)
{
    uint16_t uVar1;
    uint16_t wVar2;
    uint32_t *puVar3;
    uint16_t *puVar4;
    uint16_t *pwVar5;
    uint8_t *puVar6;
    int iVar7, iVar8;
    uint32_t *pdVar9;
    uint16_t *pwVar10;
  
    pdVar9 = (uint32_t*)VOICE_00_LEFT_RIGHT;
    for (iVar7 = 0; iVar7 < 0x18; iVar7++) {
        puVar4 = DAT_8012880c;
        for (iVar8 = 0; iVar8 < 8; iVar8++) {
            uVar1 = *puVar4++;
            *(uint16_t*)pdVar9 = uVar1;
            pdVar9 = (uint32_t*)((uintptr_t)pdVar9 + 2);
        }
    }

    pwVar10 = SPU_MAIN_VOL_L;
    pwVar5 = DAT_8012881c;
    for (iVar7 = 0; iVar7 < 0x10; iVar7++) {
        wVar2 = *pwVar5++;
        *pwVar10++ = wVar2;
    }

    FUN_800d0090(0x18);

    puVar6 = UNK_8014dd88;
    for (iVar7 = 0; iVar7 < 0x20; iVar7++) {
        puVar3 = (uint32_t*)(puVar6 + 0x3c);
        for (iVar8 = 0xf; iVar8 >= 0; iVar8--) {
            *puVar3-- = 0;
        }
        puVar6 += 0x40;
    }

    DAT_8014e588 = 0x3c;
    DAT_8014e58c = 0;
    DAT_8014e590 = 0;
}

void FUN_80094508(uint32_t *param_1, uint32_t param_2, int param_3)
{
    int iVar1;
  
    iVar1 = param_3 - 1;
    if (param_3 != 0) {
        do {
            *param_1 = param_2;
            iVar1 = iVar1 - 1;
            param_1 = param_1 + 1;
        } while (iVar1 != -1);
    }
}
// Assuming these are defined elsewhere
extern uint32_t GPU_REG1;
extern uint32_t DAT_801354ac[]; // has been changed from 8 to 32

void FUN_80093a18(uint32_t param_1)
{
    GPU_REG1 = param_1;
    DAT_801354ac[param_1 >> 24] = (uint8_t)param_1;
}
// Assuming these are defined elsewhere
extern uint32_t DAT_80116cc0;

void FUN_80094718(int param_1)
{
    uint32_t uVar1;
  
    if (DAT_80116c56 > 1) {
        printf("SetDispMask(%d)...\n", param_1);
    }
  
    if (param_1 == 0) {
        FUN_80094508(&DAT_80116cc0, 0xffffffff, 0x14);
    }
  
    uVar1 = (param_1 != 0) ? 0x3000000 : 0x3000001;
    
    FUN_80093a18(uVar1);
}
extern uint16_t I_MASK;

uint16_t FUN_80092450(uint32_t param_1)
{
    uint16_t wVar1;
  
    wVar1 = I_MASK;
    I_MASK = param_1;
    return wVar1;
}

// Assuming these are defined elsewhere
extern uint32_t GPU_REG0;
extern uint32_t GPU_REG1;

// Function to concatenate two 32-bit values into a 64-bit value
uint64_t CONCAT44(uint32_t high, uint32_t low) {
    return ((uint64_t)high << 32) | low;
}

uint64_t FUN_80094440(uint32_t param_1)
{
    uint32_t uVar1;
    uint32_t* pdVar2;
  
    GPU_REG1 = 0x10000007;
    pdVar2 = (uint32_t*)0xe1000000;

    if ((GPU_REG0 & 0xffffff) == 2) {
        if ((param_1 & 8) == 0) {
            uVar1 = 1;
        }
        else {
            pdVar2 = &GPU_REG1;
            uVar1 = 2;
            GPU_REG1 = 0x9000001;
        }
    }
    else {
        pdVar2 = (uint32_t*)0xe1001007;
        uVar1 = 0;
        GPU_REG0 = (uint32_t)pdVar2;
    }

    return CONCAT44((uint32_t)pdVar2, uVar1);
}
// Assuming these are defined elsewhere
extern uint32_t DAT_80116c38;
extern uint32_t DAT_80116cd8;
extern uint32_t DAT_80116cd4;
extern uint32_t DMA_GPU_CHCR;
extern uint32_t DMA_DPCR;
extern uint32_t GPU_REG1;
//extern uint32_t DAT_801354ac[];
extern uint32_t DAT_801355b4[]; // has been changed from 8 to 32

uint32_t FUN_8009403c(uint32_t param_1)
{
    uint32_t uVar1;
    uint32_t uVar2;
  
    DAT_80116c38 = FUN_80092450(0);
    DAT_80116cd8 = 0;
    DAT_80116cd4 = 0;
    uVar2 = param_1 & 7;

    if (uVar2 == 1 || uVar2 == 3) {
        DMA_GPU_CHCR = 0x401;
        DMA_DPCR |= 0x800;
        GPU_REG1 = 0x1000000;
    }
    else if (uVar2 == 0 || uVar2 == 5) {
        DMA_GPU_CHCR = 0x401;
        DMA_DPCR |= 0x800;
        GPU_REG1 = 0;
        FUN_80094508(DAT_801354ac, 0, 0x100);
        FUN_80094508(DAT_801355b4, 0, 0x1800);
    }

    FUN_80092450(DAT_80116c38);

    uVar1 = 0;
    if (uVar2 == 0) {
        uVar1 = FUN_80094440(param_1);
    }

    return uVar1;
}
// Assuming these are defined elsewhere
//extern char* PTR_s_$Id;_sys.c;
extern uint32_t v_1_135_1997_09_02_13_80116b74;
//extern uint8_t DAT_80116c54;
extern uint8_t DAT_80116c55;
//extern uint16_t DAT_80116c56;
extern uint16_t DAT_80116c58;
extern uint16_t DAT_80116c5a;
extern uint16_t DAT_80116bb8[];
extern uint16_t DAT_80116bc4[];
extern uint32_t DAT_80116c64;
//extern uint32_t DAT_80116cc0;

uint32_t FUN_80094538(uint32_t param_1)
{
    uint32_t uVar1 = param_1 & 7;
    
    if (uVar1 == 3 || uVar1 == 0) {
        //printf("ResetGraph:jtb=%08x,env=%08x\n", &PTR_s_$Id:_sys.c, &v_1_135_1997_09_02_13_80116b74, &DAT_80116c54);
        goto LAB_800945a0;
    }
    else if (uVar1 == 5) {
        goto LAB_800945a0;
    }
    else {
        if (DAT_80116c56 > 1) {
            printf("ResetGraph(%d)...\n", param_1);
        }
        return FUN_8009403c(1);
    }

LAB_800945a0:
    FUN_80094508(&DAT_80116c54, 0, 0x80);
    FUN_80091e20();//FUN_8009234c();
    //GPU_cw(0x116b74); function dead ends
    DAT_80116c54 = FUN_8009403c(param_1);
    DAT_80116c55 = 1;
    DAT_80116c58 = DAT_80116bb8[DAT_80116c54];
    DAT_80116c5a = DAT_80116bc4[DAT_80116c54];
    FUN_80094508(&DAT_80116c64, 0xffffffff, 0x5c);
    FUN_80094508(&DAT_80116cc0, 0xffffffff, 0x14);
    return DAT_80116c54;
}

// Assuming these are defined elsewhere
extern uint16_t DAT_80116c58;
extern uint16_t DAT_80116c5a;

uint32_t FUN_80093068(uint32_t param_1, uint32_t param_2)
{
    uint32_t uVar1, uVar2;
  
    // Handle param_1 (X coordinate)
    if ((int16_t)param_1 < 0) {
        uVar1 = 0;
    } else if ((int16_t)param_1 <= (int16_t)(DAT_80116c58 - 1)) {
        uVar1 = param_1;
    } else {
        uVar1 = DAT_80116c58 - 1;
    }
    uVar1 &= 0x3ff;  // Ensure it's within 10 bits

    // Handle param_2 (Y coordinate)
    if ((int16_t)param_2 < 0) {
        uVar2 = 0;
    } else if ((int16_t)param_2 <= (int16_t)(DAT_80116c5a - 1)) {
        uVar2 = param_2;
    } else {
        uVar2 = DAT_80116c5a - 1;
    }
    uVar2 &= 0x3ff;  // Ensure it's within 10 bits

    // Combine results
    return (uVar2 << 10) | uVar1 | 0xe3000000;
}
// Assuming these are defined elsewhere
extern uint16_t DAT_80116c58;
extern uint16_t DAT_80116c5a;

uint32_t FUN_80093100(uint32_t param_1, uint32_t param_2)
{
    uint32_t uVar1, uVar2;
  
    // Handle param_1 (X coordinate)
    if ((int16_t)param_1 < 0) {
        uVar1 = 0;
    } else if ((int16_t)param_1 <= (int16_t)(DAT_80116c58 - 1)) {
        uVar1 = param_1;
    } else {
        uVar1 = DAT_80116c58 - 1;
    }
    uVar1 &= 0x3ff;  // Ensure it's within 10 bits

    // Handle param_2 (Y coordinate)
    if ((int16_t)param_2 < 0) {
        uVar2 = 0;
    } else if ((int16_t)param_2 <= (int16_t)(DAT_80116c5a - 1)) {
        uVar2 = param_2;
    } else {
        uVar2 = DAT_80116c5a - 1;
    }
    uVar2 &= 0x3ff;  // Ensure it's within 10 bits

    // Combine results
    return (uVar2 << 10) | uVar1 | 0xe4000000;
}
uint32_t FUN_80093198(uint32_t param_1, uint32_t param_2)
{
    return ((param_2 & 0x7ff) << 11) | (param_1 & 0x7ff) | 0xe5000000;
}
#include <stdint.h>

uint32_t FUN_80093048(int param_1, int param_2, uint32_t param_3)
{
    uint32_t uVar1 = 0xe1000000;
    
    if (param_2 != 0) {
        uVar1 = 0xe1000200;
    }
    
    param_3 = param_3 & 0x9ff;
    
    if (param_1 != 0) {
        param_3 = param_3 | 0x400;
    }
    
    return uVar1 | param_3;
}
uint32_t FUN_800931b4(const uint8_t *param_1)
{
    if (param_1 == NULL) {
        return 0;
    }
    
    uint32_t uVar1 = 0xe2000000;  // Base command
    
    // Extract and position the first three components
    uVar1 |= (uint32_t)(param_1[2] >> 3) << 15;  // Third byte, shifted right by 3, then left by 15
    uVar1 |= (uint32_t)(param_1[0] >> 3) << 10;  // First byte, shifted right by 3, then left by 10
    
    // Handle the last two components (shorts at offsets 6 and 4)
    int16_t component4 = *(int16_t*)(param_1 + 6);
    int16_t component5 = *(int16_t*)(param_1 + 4);
    
    uVar1 |= ((uint32_t)(-component4 & 0xFF) >> 3) << 5;  // Negate, mask, shift right by 3, then left by 5
    uVar1 |= (uint32_t)(-component5 & 0xFF) >> 3;         // Negate, mask, shift right by 3
    
    return uVar1;
}

// Assuming these are defined elsewhere
extern uint16_t DAT_80116c58;
extern uint16_t DAT_80116c5a;


typedef struct {
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
    uint16_t offset_x;
    uint16_t offset_y;
    uint16_t color_params[5];
    uint8_t draw_mode;
    uint8_t dither;
    uint8_t draw_to_display;
    uint8_t texture_disable;
    uint8_t texture_window_x;
    uint8_t texture_window_y;
} DrawEnvInput;

typedef struct {
    uint32_t padding;
    uint32_t clip_start;
    uint32_t clip_end;
    uint32_t offset;
    uint32_t draw_mode;
    uint32_t texture_params;
    uint32_t draw_area_cmd;
    uint32_t draw_area_start;
    uint32_t draw_area_end;
    int8_t count;
} DrawEnvOutput;

void FUN_80092dd8(DrawEnvOutput* output, const DrawEnvInput* input)
{
    output->clip_start = FUN_80093068(input->x, input->y);
    output->clip_end = FUN_80093100(input->x + input->width - 1, input->y + input->height - 1);
    output->offset = FUN_80093198(input->offset_x, input->offset_y);
    output->draw_mode = FUN_80093048(input->texture_disable, input->dither, input->draw_mode);
    output->texture_params = FUN_800931b4((const uint8_t*)&input->color_params);
    output->draw_area_cmd = 0xe6000000;

    output->count = 6;

    if (input->draw_to_display != 0) {
        uint16_t end_x = input->width;
        uint16_t end_y = input->height;

        if (end_x > DAT_80116c58) end_x = DAT_80116c58;
        if (end_y > DAT_80116c5a) end_y = DAT_80116c5a;

        if ((input->x & 0x3f) == 0 && (end_x & 0x3f) == 0) {
            output->count = 9;
            output->draw_area_start = 0x2000000 | 
                                      (input->texture_window_y << 16) | 
                                      (input->draw_to_display << 8) | 
                                      input->texture_window_x;
            output->draw_area_end = *(uint32_t*)&input->x;
        } else {
            output->count = 9;
            uint32_t local_18 = ((input->y - input->offset_y) << 16) | (input->x - input->offset_x);
            output->draw_area_start = 0x60000000 | 
                                      (input->texture_window_y << 16) | 
                                      (input->draw_to_display << 8) | 
                                      input->texture_window_x;
            output->draw_area_end = local_18;
        }
    }
}
// Assuming these are defined elsewhere
extern uint16_t DAT_80116c58;
extern uint16_t DAT_80116c5a;

/**void FUN_80092dd8(int32_t param_1, uint16_t *param_2)
{
    uint16_t uVar1, uVar2, uVar3;
    uint32_t uVar4;
    int8_t cVar5;
    uint32_t local_18, local_14;
  
    *(uint32_t *)(param_1 + 4) = FUN_80093068(*param_2, param_2[1]);
    *(uint32_t *)(param_1 + 8) = FUN_80093100(((param_2[2] + *param_2 - 1) * 0x10000) >> 0x10,
                                              ((param_2[1] + param_2[3] - 1) * 0x10000) >> 0x10);
    *(uint32_t *)(param_1 + 0xc) = FUN_80093198(param_2[4], param_2[5]);
    *(uint32_t *)(param_1 + 0x10) = FUN_80093048(*(uint8_t *)((int32_t)param_2 + 0x17),
                                                 *(uint8_t *)(param_2 + 0xb), param_2[10]);
    *(uint32_t *)(param_1 + 0x14) = FUN_800931b4(param_2 + 6);
    *(uint32_t *)(param_1 + 0x18) = 0xe6000000;

    cVar5 = 7;
    if (*(int8_t *)(param_2 + 0xc) != 0) {
        uVar4 = *(uint32_t *)param_2;
        uVar3 = param_2[2];
        uVar1 = param_2[3];
        uVar2 = 0;

        if (((int16_t)uVar3 >= 0) && ((int16_t)uVar3 <= DAT_80116c58 - 1)) {
            uVar2 = uVar3;
        } else {
            uVar2 = DAT_80116c58 - 1;
        }

        if ((int16_t)uVar1 < 0) {
            uVar3 = 0;
        } else if ((int16_t)uVar1 <= DAT_80116c5a - 1) {
            uVar3 = uVar1;
        } else {
            uVar3 = DAT_80116c5a - 1;
        }

        local_14 = (uVar3 << 16) | uVar2;

        if ((*param_2 & 0x3f) == 0 && (uVar2 & 0x3f) == 0) {
            cVar5 = 10;
            *(uint32_t *)(param_1 + 0x1c) =
                (*(uint8_t *)((int32_t)param_2 + 0x1b) << 0x10) |
                (*(uint8_t *)(param_2 + 0xd) << 8) |
                0x2000000 |
                *(uint8_t *)((int32_t)param_2 + 0x19);
            *(uint32_t *)(param_1 + 0x20) = uVar4;
            *(uint32_t *)(param_1 + 0x24) = local_14;
        } else {
            cVar5 = 10;
            local_18 = ((param_2[1] - param_2[5]) << 16) | (*param_2 - param_2[4]);
            *(uint32_t *)(param_1 + 0x1c) =
                (*(uint8_t *)((int32_t)param_2 + 0x1b) << 0x10) |
                (*(uint8_t *)(param_2 + 0xd) << 8) |
                0x60000000 |
                *(uint8_t *)((int32_t)param_2 + 0x19);
            *(uint32_t *)(param_1 + 0x20) = local_18;
            *(uint32_t *)(param_1 + 0x24) = local_14;
        }
    }

    *(int8_t *)(param_1 + 3) = cVar5 - 1;
}**/

#include <stdint.h>
#include <stdbool.h>

// Assuming these are defined elsewhere
extern uint32_t DAT_80116b30;

void FUN_80091c10(int param_1, int param_2)
{
    int32_t timeout = param_2 << 15;  // Multiply param_2 by 32768
    
    while (true) {
        if (param_1 <= DAT_80116b30) {
            return;  // Condition met, exit function
        }
        
        timeout--;
        if (timeout < 0) {
            break;  // Timeout occurred
        }
    }
    
    // Timeout handling
    //FUN_80091184("VSync: timeout\n"); dead end in decompiler
    //ChangeClearPAD(0);
    //ChangeClearRCnt(3, 0); all dead ends
}

// Assuming these are defined elsewhere
extern uint16_t TMR_HRETRACE_VAL;
extern uint16_t DAT_80115a58;
extern uint32_t DAT_80116b30;
extern uint32_t DAT_80115a4c;
extern uint32_t GPU_REG1;


uint32_t FUN_80091ca8(int32_t param_1)
{
    uint32_t currentHRetrace = TMR_HRETRACE_VAL;
    uint32_t elapsedHRetrace = (currentHRetrace - DAT_80115a58) & 0xFFFF;
    uint32_t result = DAT_80116b30;

    if (param_1 >= 0 && param_1 != 1) {
        result = elapsedHRetrace;

        uint32_t targetValue = (param_1 > 0) ? DAT_80115a4c + param_1 - 1 : DAT_80115a4c;
        int32_t waitCount = (param_1 > 0) ? param_1 - 1 : 0;

        FUN_80091c10(targetValue, waitCount);

        uint32_t initialGpuState = GPU_REG1;
        FUN_80091c10(DAT_80116b30 + 1, 1);

        if ((initialGpuState & 0x400000) != 0 && (int32_t)(initialGpuState ^ GPU_REG1) >= 0) {
            while (((initialGpuState ^ GPU_REG1) & 0x80000000) == 0) {
                // Wait for GPU state change
            }
        }

        DAT_80115a4c = DAT_80116b30;
        DAT_80115a58 = currentHRetrace;
    }

    return result;
}

// Assuming these are defined elsewhere
extern int32_t DAT_80116c3c;
extern int32_t DAT_80116c40;


void FUN_800942c8(void)
{
    int32_t iVar1;
  
    iVar1 = FUN_80091ca8(0xffffffff);
    DAT_80116c3c = iVar1 + 0xf0;
    DAT_80116c40 = 0;
}
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

// Assuming these are defined elsewhere
extern int32_t DAT_80116c3c;
extern int32_t DAT_80116c40;
//extern uint8_t DAT_80116cd4;
//extern uint8_t DAT_80116cd8;
extern uint32_t DAT_80116c38;
extern uint32_t GPU_REG1;
extern uint32_t DMA_GPU_CHCR;
extern uint32_t DMA_GPU_MADR;
extern uint32_t DMA_DPCR;

#define GPU_QUEUE_MASK 0x3F
#define GPU_TIMEOUT_THRESHOLD 0xF0000
#define GPU_RESET_CMD 0x1000000
#define DMA_RESET_CMD 0x401
#define DMA_ENABLE_BIT 0x800

int32_t FUN_800942fc(void)
{
    int32_t currentTime = FUN_80091ca8(-1);
    
    if (currentTime > DAT_80116c3c || ++DAT_80116c40 > GPU_TIMEOUT_THRESHOLD) {
        // GPU timeout occurred
        uint32_t queuedCommands = (DAT_80116cd4 - DAT_80116cd8) & GPU_QUEUE_MASK;
        
        printf("GPU timeout:que=%d,stat=%08x,chcr=%08x,madr=%08x,",
               queuedCommands, GPU_REG1, DMA_GPU_CHCR, DMA_GPU_MADR);
        
        // Save current state
        DAT_80116c38 = FUN_80092450(0);
        
        // Reset GPU state
        DAT_80116cd8 = 0;
        DAT_80116cd4 = 0;
        DMA_GPU_CHCR = DMA_RESET_CMD;
        DMA_DPCR |= DMA_ENABLE_BIT;
        GPU_REG1 = GPU_RESET_CMD;
        
        // Restore saved state
        FUN_80092450(DAT_80116c38);
        
        return -1;  // Indicate timeout occurred
    }
    
    return 0;  // No timeout
}
/**void FUN_800923ac(void)
{
    if (DAT_80116ac8 != NULL) {
        DAT_80116ac8();
    }
}**/
// Assuming these are defined elsewhere
extern uint32_t DMA_GPU_CHCR;
extern uint32_t GPU_REG1;
extern uint32_t DAT_80116c34;
//extern uint8_t DAT_80116cd4;
//extern uint8_t DAT_80116cd8;
//extern uint32_t* DAT_801355b4;
extern uint32_t* DAT_801355b8;
extern uint32_t* DAT_801355bc;

#define GPU_QUEUE_SIZE 64
//#define GPU_QUEUE_MASK (GPU_QUEUE_SIZE - 1)
#define DMA_BUSY_BIT 0x1000000
#define GPU_READY_BIT 0x4000000

typedef void (*GPUCommand)(uint32_t*, uint32_t);

uint32_t FUN_80093ddc(void)
{
    if (DMA_GPU_CHCR & DMA_BUSY_BIT) {
        return 1;
    }

    DAT_80116c34 = FUN_80092450(0);  // Save interrupt mask

    while (DAT_80116cd4 != DAT_80116cd8) {
        if (DMA_GPU_CHCR & DMA_BUSY_BIT) {
            break;
        }

        if (((DAT_80116cd8 + 1) & GPU_QUEUE_MASK) == DAT_80116cd4) {
            //FUN_800923ac(2, NULL);  // Possibly disabling an interrupt dead end in decompiler
        }

        while ((GPU_REG1 & GPU_READY_BIT) == 0) {
            // Wait for GPU to be ready
        }

        // Execute the GPU command
        GPUCommand cmd = (GPUCommand)DAT_801355b4[DAT_80116cd8 * 24];
        uint32_t* params = (uint32_t*)DAT_801355b8[DAT_80116cd8 * 24];
        uint32_t extraParam = DAT_801355bc[DAT_80116cd8 * 15];
        cmd(params, extraParam);

        DAT_80116cd8 = (DAT_80116cd8 + 1) & GPU_QUEUE_MASK;
    }

    FUN_80092450(DAT_80116c34);  // Restore interrupt mask

    return (DAT_80116cd4 - DAT_80116cd8) & GPU_QUEUE_MASK;
}

// Assuming these are defined elsewhere
//extern uint8_t DAT_80116cd4;
//extern uint8_t DAT_80116cd8;
extern uint32_t DAT_80116c30;
extern uint8_t DAT_80116c5c;
extern uint8_t DAT_80116c55;
extern uint32_t DMA_GPU_CHCR;
extern uint32_t GPU_REG1;
extern uint32_t* DAT_801355b8;
extern uint32_t* DAT_801355bc;
//extern uint32_t* DAT_801355b4;

typedef void (*GPUCommand)(uint32_t*, uint32_t);

uint32_t FUN_80093b2c(GPUCommand cmd, uint32_t* params, int paramCount, uint32_t extraParam)
{
    FUN_800942c8();

    while (true) {
        uint8_t nextIndex = (DAT_80116cd4 + 1) & 0x3F;
        if (nextIndex == DAT_80116cd8) {
            if (FUN_800942fc() != 0) {
                return 0xFFFFFFFF;
            }
            FUN_80093ddc();
            continue;
        }

        DAT_80116c30 = FUN_80092450(0);
        DAT_80116c5c = 1;

        if (DAT_80116c55 == 0 || (DAT_80116cd4 == DAT_80116cd8 && (DMA_GPU_CHCR & 0x1000000) == 0)) {
            while ((GPU_REG1 & 0x4000000) == 0) {}
            cmd(params, extraParam);
            FUN_80092450(DAT_80116c30);
            return 0;
        } else {
            //FUN_800923ac(2, FUN_80093ddc); dead ebd in decompiler

            if (paramCount == 0) {
                DAT_801355b8[DAT_80116cd4 * 24] = (uint32_t)params;
            } else {
                int copyCount = (paramCount + 3) / 4;
                uint32_t* dest = (uint32_t*)&DAT_801355b8[DAT_80116cd4 * 24 + 2];
                for (int i = 0; i < copyCount; i++) {
                    dest[i] = params[i];
                }
                DAT_801355b8[DAT_80116cd4 * 24] = (uint32_t)dest;
            }

            DAT_801355bc[DAT_80116cd4 * 15] = extraParam;
            DAT_801355b4[DAT_80116cd4 * 24] = (uint32_t)cmd;

            DAT_80116cd4 = (DAT_80116cd4 + 1) & 0x3F;
            FUN_80092450(DAT_80116c30);
            FUN_80093ddc();

            return (DAT_80116cd4 - DAT_80116cd8) & 0x3F;
        }
    }
}
// Assuming these are defined elsewhere
extern uint32_t GPU_REG1;
extern uint32_t DMA_GPU_MADR;
extern uint32_t DMA_GPU_BCR;
extern uint32_t DMA_GPU_CHCR;

#define GPU_DMA_COMMAND 0x4000002
#define DMA_CONTROL_COMMAND 0x1000401

void FUN_80093a90(uint32_t memoryAddress)
{
    GPU_REG1 = GPU_DMA_COMMAND;
    DMA_GPU_MADR = memoryAddress;
    DMA_GPU_BCR = 0;
    DMA_GPU_CHCR = DMA_CONTROL_COMMAND;
}

// Assuming these are defined elsewhere
//extern uint16_t DAT_80116c56;

uint8_t* FUN_80094b3c(uint8_t* param_1)
{
    if (DAT_80116c56 > 1) {
        printf("PutDrawEnv(%08x)...\n", (uintptr_t)param_1);
    }

    //FUN_80092dd8(param_1 + 0x1c, param_1); // parameter issues

    *(uint32_t*)(param_1 + 0x1c) |= 0xffffff;

    //FUN_80093b2c(FUN_80093a90, param_1 + 0x1c, 0x40, 0);

    //memcpy("", param_1, 0x5c); issues with parameter input and the function they reference

    return param_1;
}
// Assuming these are defined elsewhere
//extern uint16_t DAT_80116c56;
void FUN_80093a18(uint32_t);
char FUN_80092828(void);

// Define constants for clarity
#define DISPLAY_AREA_CMD 0x5000000
#define HORIZONTAL_RANGE_CMD 0x6000000
#define VERTICAL_RANGE_CMD 0x7000000
#define DISPLAY_MODE_CMD 0x8000000

uint16_t* FUN_80094bfc(uint16_t* param_1)
{
    uint32_t uVar9 = DISPLAY_MODE_CMD;
    
    if (DAT_80116c56 > 1) {
        printf("PutDispEnv(%08x)...\n", (uintptr_t)param_1);
    }

    // Set display area
    FUN_80093a18(DISPLAY_AREA_CMD | ((param_1[1] & 0x3ff) << 10) | (*param_1 & 0x3ff));

    // Check if display range needs to be set
    if (param_1[4] == 0 && param_1[5] == 0 && param_1[6] == 0 && param_1[7] == 0) {
        goto SetDisplayMode;
    }

    // Get and store some value (possibly related to interlacing)
    char cVar3 = FUN_80092828();
    param_1[9] = (uint16_t)cVar3;

    // Calculate horizontal range
    uint32_t uVar5 = param_1[4] * 10 + 0x260;
    uint32_t uVar7 = param_1[5] + (cVar3 == 0 ? 0x10 : 0x13);
    uint32_t uVar6 = (param_1[6] == 0) ? (param_1[4] * 10 + 0xc60) : (uVar5 + param_1[6] * 10);
    uint32_t uVar8 = (param_1[7] == 0) ? (uVar7 + 0xf0) : (uVar7 + param_1[7]);

    // Clamp horizontal range
    uint32_t uVar4 = (uVar5 > 499 && uVar5 < 0xcdb) ? uVar5 : (uVar5 <= 499 ? 500 : 0xcda);
    uVar5 = (uVar6 >= uVar4 + 0x50 && uVar6 < 0xcdb) ? uVar6 : 0xcda;

    // Clamp vertical range
    uVar7 = (uVar7 < 0x10) ? 0x10 : uVar7;
    uint32_t maxV = (cVar3 == 0) ? 0x100 : 0x136;
    if (uVar7 > maxV) uVar7 = maxV;

    uVar6 = uVar7 + 2;
    if (uVar8 > uVar6) {
        uVar6 = (uVar8 <= maxV + 2) ? uVar8 : (maxV + 2);
    }

    // Set horizontal and vertical ranges
    FUN_80093a18(HORIZONTAL_RANGE_CMD | ((uVar5 & 0xfff) << 12) | (uVar4 & 0xfff));
    FUN_80093a18(VERTICAL_RANGE_CMD | ((uVar6 & 0x3ff) << 10) | (uVar7 & 0x3ff));

SetDisplayMode:
    // Set display mode if necessary
    if (*(int*)(param_1 + 8) != 0 || *param_1 != 0 || param_1[1] != 0 || param_1[2] != 0 || param_1[3] != 0) {
        cVar3 = FUN_80092828();
        param_1[9] = (uint16_t)cVar3;

        if (cVar3 == 1) uVar9 |= 0x8;
        if (*(char*)((int)param_1 + 0x11) != 0) uVar9 |= 0x10;
        if (*(char*)(param_1 + 8) != 0) uVar9 |= 0x20;

        // Set resolution mode
        uint16_t width = param_1[2];
        if (width > 0x118) {
            if (width < 0x161) uVar9 |= 1;
            else if (width < 0x191) uVar9 |= 0x40;
            else if (width < 0x231) uVar9 |= 2;
            else uVar9 |= 3;
        }

        // Set interlace mode
        uint16_t height = param_1[3];
        uint16_t heightThreshold = (cVar3 == 0) ? 0x101 : 0x121;
        if (height >= heightThreshold) uVar9 |= 0x24;

        FUN_80093a18(uVar9);
    }

    // Copy settings to some global location
    //memcpy("", (unsigned char*)param_1, 0x14); issues with parameters

    return param_1;
}
// Assuming these are defined elsewhere
extern uint16_t DAT_80136e1a, DAT_80136e18, DAT_80136e22, DAT_80136e20;
extern uint16_t DAT_80136e1e, DAT_80136e1c, DAT_80136e24, DAT_80136e27;
extern uint16_t DAT_80136e28, DAT_80136e26;
extern uint16_t DAT_80136e6c, DAT_80136e6e, DAT_80136e74, DAT_80136e76;
extern uint16_t DAT_80136e78, DAT_80136e7a, DAT_80136e70, DAT_80136e72;
extern uint16_t DAT_80136e7e;
extern uint8_t DAT_80136e7c, DAT_80136e7d;
extern uint16_t DAT_80136e80;
extern uint8_t DAT_80136e10;

void FUN_80097610(uint16_t param_1, uint16_t param_2, uint32_t param_3, uint8_t param_4, uint8_t param_5)
{
    int iVar1;
    uint32_t uVar2 = 0;
  
    if ((param_3 >> 4 & 3) == 3) {
        uVar2 = 3;
    }
    FUN_80094538(uVar2);

    DAT_80136e1a = 0;
    DAT_80136e18 = 0;
    DAT_80136e22 = 0;
    DAT_80136e20 = 0;
    DAT_80136e1e = 0;
    DAT_80136e1c = 0;
    DAT_80136e24 = 0;
    DAT_80136e27 = 0;
    DAT_80136e28 = 0;
    DAT_80136e26 = param_4;

    FUN_80094b3c(&DAT_80136e10);

    DAT_80136e6c = 0;
    DAT_80136e6e = 0;
    DAT_80136e74 = 0;
    DAT_80136e76 = 0;
    DAT_80136e78 = 0;
    DAT_80136e7a = 0;
    DAT_80136e70 = param_1;
    DAT_80136e72 = param_2;

    iVar1 = 0; //FUN_80092828();
    if (iVar1 == 1) {
        DAT_80136e76 = 0x18;
        DAT_80136e7e = 1;
    }

    DAT_80136e7c = param_3 & 1;
    DAT_80136e80 = param_3 & 4;
    DAT_80136e7d = param_5;

    //FUN_80094bfc(); parameter issue
}
#include <stdint.h>
#include <stdbool.h>

// Assuming these are defined elsewhere
extern uint32_t DAT_80137130;
extern int DAT_800a07b8[];
extern int DAT_800a07d0[];
extern int UNK_800a07e8;

// Assuming this is a function pointer type
typedef int (*CodeFunc)(void);

void FUN_800a07ec(void)
{
    int iVar1;
    int *piVar2;
    int *piVar3;
    int *piVar4;
    int iVar5;
    
    // Store return address
    DAT_80137130 = (uint32_t)__builtin_return_address(0);
    
    // Call some initialization function
    //syscall(0);//FUN_80090938();
    
    // Call a function via function pointer and get a result
    CodeFunc codeFunc = (CodeFunc)0xb0;
    iVar1 = codeFunc();
    
    // Set up pointers for memory comparison and copy
    piVar2 = (int *)(*(int *)(iVar1 + 0x18) + 0x28);
    piVar3 = DAT_800a07b8;
    piVar4 = piVar2;
    
    // Compare memory regions
    do {
        iVar1 = *piVar3;
        iVar5 = *piVar4;
        piVar3++;
        piVar4++;
        if (iVar1 != iVar5) goto LAB_800a0874;
    } while (piVar3 != DAT_800a07d0);
    
    // Copy memory if comparison was successful
    piVar4 = DAT_800a07d0;
    do {
        *piVar2 = *piVar4;
        piVar4++;
        piVar2++;
    } while (piVar4 != (int *)&UNK_800a07e8);
    
LAB_800a0874:
    // Flush the cache
    //FlushCache(); dead end
    
    // Call some finalization function
    //syscall(0);FUN_80090948();
    return; // put here to solve an error
}

// Assuming these are defined elsewhere
extern uint32_t DAT_8011766c;
extern uint32_t Status;
// GTE Status bit
#define GTE_STATUS_BIT 0x40000000

uint32_t FUN_8009a788(void)
{
    // Store the return address
    DAT_8011766c = (uint32_t)__builtin_return_address(0);

    // Call some initialization function
    FUN_800a07ec();

    // Set the GTE's Status register, enabling bit 30 (0x40000000)
    uint32_t newStatus = Status | GTE_STATUS_BIT;
    /**setCopReg(0, Status, newStatus, 0);

    // Set various GTE registers
    gte_ldZSF3(0x155);    // Z Scale Factor 3
    gte_ldZSF4(0x100);    // Z Scale Factor 4
    gte_ldH(1000);        // Projection Plane Distance
    gte_ldDQA(0xFFFFEF9E);// Depth Queueing A (for fog)
    gte_ldDQB(0x1400000); // Depth Queueing B (for fog)
    gte_ldOFX(0);         // Screen Offset X
    gte_ldOFY(0);         // Screen Offset Y
    **/ //all dead ends or internal function 
    // Return the new Status value
    return newStatus;
}
void FUN_8009b340(int param_1, int param_2)
{
  //gte_ldOFX(param_1 << 0x10); needs to be put into assembly
  //gte_ldOFY(param_2 << 0x10);
  return;
}
// Assuming these are defined elsewhere
extern uint16_t DAT_80136e8e;
extern uint16_t DAT_80136e8c;

// Renamed function to reflect its likely purpose
void gte_init(void)
{
    // Initialize some aspect of the GTE
    FUN_8009a788();

    // Set the far color to black (used for depth cueing or fog)
    SetFarColor(0, 0, 0);

    // Set some other GTE-related parameters
    FUN_8009b340(0, 0);

    // Initialize two global variables, possibly related to GTE state
    DAT_80136e8e = 0;
    DAT_80136e8c = 0;
}
#include <stdint.h>

// Assuming these are defined elsewhere
extern uint32_t DAT_80136f10, DAT_80136f14;
extern uint32_t DAT_80136f68, DAT_80136f70, DAT_80136f80, DAT_80136f7c, DAT_80136f78;
extern uint32_t DAT_80136f64, DAT_80136f6c;
extern uint32_t DAT_80136f74;
extern uint32_t DAT_80136fc4, DAT_80136fc8, DAT_80136fd0, DAT_80136fd4;
extern uint32_t DAT_80136fd8, DAT_80136fdc, DAT_80136fe0;
extern uint32_t DAT_80136f28, DAT_80136f30, DAT_80136f38, DAT_80136f3c, DAT_80136f40;
extern uint32_t DAT_80136f34, DAT_80136f2c, DAT_80136f24;
extern uint32_t DAT_80136f44, DAT_80136f48, DAT_80136f4c, DAT_80136f50, DAT_80136f54;
extern uint32_t DAT_80136f58, DAT_80136f5c, DAT_80136f60;
extern uint16_t DAT_80136df4, DAT_80136df6, DAT_80136df8, DAT_80136dfa, DAT_80136dfe, DAT_80136dfc, DAT_80136e02;
extern uint32_t _DAT_80136fcc;
extern uint16_t DAT_80136e00, DAT_80136dd7, DAT_80136ddb, DAT_80136de7, DAT_80136deb, DAT_80136e08, DAT_80136e04, DAT_80136e06;

#define SCALE_FACTOR 0x1000

void FUN_8009772c(uint16_t param_1, uint16_t param_2)
{
    // Set main parameters
    DAT_80136f10 = param_1;
    DAT_80136f14 = param_2;

    // Error checking
    if (DAT_80136f10 == 0) {
        __builtin_trap();  // Equivalent to trap(0x1c00)
    }
    if (DAT_80136f10 == 0xFFFFFFFF && DAT_80136f14 == 0x20000) {
        __builtin_trap();  // Equivalent to trap(0x1800)
    }

    // Initialize various parameters to 0
    DAT_80136f68 = DAT_80136f70 = DAT_80136f80 = DAT_80136f7c = DAT_80136f78 = 0;

    // Set scale factors
    DAT_80136f64 = DAT_80136f6c = SCALE_FACTOR;
    DAT_80136f74 = (DAT_80136f74 & 0xFFFF0000) | SCALE_FACTOR;
    DAT_80136fc4 = SCALE_FACTOR;

    // Initialize more parameters
    DAT_80136fc8 = DAT_80136fd0 = 0;
    DAT_80136fd4 = DAT_80136f74;
    DAT_80136fd8 = DAT_80136fdc = DAT_80136fe0 = 0;
    DAT_80136f28 = DAT_80136f30 = DAT_80136f38 = DAT_80136f3c = DAT_80136f40 = 0;

    // Set up some kind of offset or scaling value
    DAT_80136f34 = (uint32_t)(DAT_80136f74 >> 16) << 16;
    DAT_80136f2c = DAT_80136f24 = 0;
    DAT_80136f44 = DAT_80136f48 = DAT_80136f4c = DAT_80136f50 = 0;
    DAT_80136f54 = DAT_80136f34;
    DAT_80136f58 = DAT_80136f5c = DAT_80136f60 = 0;

    // Clear some 16-bit values
    DAT_80136df4 = DAT_80136df6 = DAT_80136df8 = DAT_80136dfa = DAT_80136dfe = DAT_80136dfc = DAT_80136e02 = 0;

    // Complex calculation, possibly for scaling or aspect ratio
    uint32_t scaledHeight = (DAT_80136f14 << 14) / DAT_80136f10;
    _DAT_80136fcc = (uint16_t)(((uint64_t)scaledHeight * 0x55555556) >> 32);

    // Set final parameters
    DAT_80136e00 = 0;
    DAT_80136dd7 = 3;
    DAT_80136ddb = 2;
    DAT_80136de7 = 3;
    DAT_80136deb = 2;
    DAT_80136e08 = 1;
    DAT_80136e04 = param_1;
    DAT_80136e06 = param_2;
}
// Assuming these are defined elsewhere
extern uint8_t DAT_80116c56;
//extern int16_t DAT_80116c58;
//extern int16_t DAT_80116c5a;

typedef struct {
    int16_t x;
    int16_t y;
    int16_t width;
    int16_t height;
} Rect;

void FUN_80092cbc(const char* param_1, Rect* param_2)
{
    if (DAT_80116c56 == 1) {
        int right = param_2->x + param_2->width;
        int bottom = param_2->y + param_2->height;

        bool isValidX = (param_2->x <= DAT_80116c58) && (right <= DAT_80116c58);
        bool isValidY = (param_2->y <= DAT_80116c5a) && (bottom <= DAT_80116c5a);
        bool isPositive = (param_2->width > 0) && (param_2->height > 0);
        bool isNonNegative = (param_2->x >= 0) && (param_2->y >= 0);

        if (isValidX && isValidY && isPositive && isNonNegative) {
            return;  // Rectangle is valid, no need to print
        }

        printf("%s:bad RECT", param_1);
    }
    else if (DAT_80116c56 == 2) {
        printf("%s:", param_1);
    }
    else {
        return;  // Do nothing if DAT_80116c56 is not 1 or 2
    }

    // Print rectangle information
    printf("(%d,%d)-(%d,%d)\n", 
           param_2->x, param_2->y, 
           param_2->x + param_2->width, param_2->y + param_2->height);
}
// Assuming these are defined elsewhere
extern uint32_t DAT_80136e0c;

void FUN_8009794c(uint16_t param_1, uint16_t param_2, uint16_t param_3, uint16_t param_4, uint16_t param_5)
{
    FUN_80097610(param_1, param_2, param_3, param_4, param_5);
    gte_init();
    DAT_80136e0c = 0;
    FUN_8009772c(param_1, param_2);
    GsSetDrawBuffClip();
    GsSetDrawBuffOffset();
}
uint FUN_80093ad8(uint param_1)

{
  GPU_REG1 = param_1 | 0x10000000;
  return GPU_REG0 & 0xffffff;
}

// Assuming these are defined elsewhere
extern uint16_t DAT_80116c58;
extern uint16_t DAT_80116c5a;
extern uint32_t GPU_REG1;
extern uint32_t DAT_80135464, DAT_80135468, DAT_8013546c, DAT_80135470, DAT_80135474, DAT_80135478;
extern uint32_t DAT_8013547c, DAT_80135480, DAT_80135484, DAT_8013548c, DAT_80135490, DAT_80135494, DAT_80135498;


uint32_t LAB_8009332c(Rect* param_1, uint32_t param_2)
{
    // Clamp width
    if (param_1->width < 0) {
        param_1->width = 0;
    } else if (param_1->width > DAT_80116c58 - 1) {
        param_1->width = DAT_80116c58 - 1;
    }

    // Clamp height
    if (param_1->height < 0) {
        param_1->height = 0;
    } else if (param_1->height > DAT_80116c5a - 1) {
        param_1->height = DAT_80116c5a - 1;
    }

    if ((param_1->x & 0x3f) == 0 && (param_1->width & 0x3f) == 0) {
        // Aligned case
        DAT_80135464 = 0x5ffffff;
        DAT_80135468 = 0xe6000000;
        DAT_80135470 = (param_2 & 0xffffff) | 0x2000000;
        DAT_8013546c = (GPU_REG1 & 0x7ff) | ((param_2 >> 31) << 10) | 0xe1000000;
        DAT_80135474 = *(uint32_t*)&param_1->x;
        DAT_80135478 = *(uint32_t*)&param_1->width;
    } else {
        // Unaligned case
        DAT_80135464 = 0x813548c;
        DAT_8013547c = (param_2 & 0xffffff) | 0x60000000;
        DAT_80135474 = 0xe6000000;
        DAT_80135468 = 0xe3000000;
        DAT_8013546c = 0xe4ffffff;
        DAT_80135470 = 0xe5000000;
        DAT_80135478 = (GPU_REG1 & 0x7ff) | ((param_2 >> 31) << 10) | 0xe1000000;
        DAT_80135480 = *(uint32_t*)&param_1->x;
        DAT_80135484 = *(uint32_t*)&param_1->width;
        DAT_8013548c = 0x3ffffff;
        DAT_80135490 = FUN_80093ad8(3) | 0xe3000000;
        DAT_80135494 = FUN_80093ad8(4) | 0xe4000000;
        DAT_80135498 = FUN_80093ad8(5) | 0xe5000000;
    }

    FUN_80093a90(DAT_80135464);
    return 0;
}

void FUN_80094818(void* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    // Log or debug print the function name and parameter
    FUN_80092cbc("ClearImage", param_1);

    // Construct the color value from individual components
    uint32_t color = ((param_4 & 0xFF) << 16) | ((param_3 & 0xFF) << 8) | (param_2 & 0xFF);

    // Call the function to clear the image
    //FUN_80093b2c(LAB_8009332c, param_1, 8, color);
}
// Assuming this is the structure we're working with
typedef struct {
    // We don't know what the first 3 bytes are used for
    uint8_t unknown[3];
    uint8_t type;
    uint32_t position;
    uint32_t unknown2;
} SomeObject;

void FUN_80095030(SomeObject* obj, const int16_t* coordinates)
{
    obj->type = 2;
    obj->position = FUN_80093198(coordinates[0], coordinates[1]);
    obj->unknown2 = 0;
}
// Assuming these are defined elsewhere
extern uint16_t uRamffff89b0;
extern uint16_t uRamffff89b2;
extern uint16_t uRamffff89b4;
extern uint16_t uRamffff89b6;
extern uint16_t uRamffff9394;
extern uint16_t uRamffff9398;
extern uint16_t uRamffff939c;
extern uint32_t DAT_8015db68;
extern uint32_t* DAT_8015db6c;
extern uint32_t DAT_8015db7c;
extern uint32_t* DAT_8015db80;
extern SomeObject DAT_8015db90;
extern SomeObject DAT_8015db9c;

void FUN_800eec14(void)
{
    uint16_t local_10, local_e, local_c, local_a;
    uint16_t local_8, local_6, local_4, local_2;
  
    local_10 = uRamffff89b0;
    local_e = uRamffff89b2;
    local_c = uRamffff89b4;
    local_a = uRamffff89b6;

    FUN_80094718(0);
    FUN_8009794c(0x140, 0xf0, 4, 0, 0);
    GsDefDispBuff(0, 0, 0, 0xf0);

    local_8 = 0;
    local_6 = 0;
    local_4 = 0x140;
    local_2 = 0x1e0;

    FUN_80094818(&local_8, 0, 0, 0);

    DAT_8015db68 = 0xc;
    DAT_8015db6c = &DAT_8015db68; // = &DAT_80159b68;
    DAT_8015db7c = 0xc;
    DAT_8015db80 = &DAT_8015db68;

    GsInit3D();

    uRamffff9394 = 0xa0;
    uRamffff9398 = 0x78;

    FUN_80095030(&DAT_8015db90, (const int16_t*)&local_c);
    FUN_80095030(&DAT_8015db9c, (const int16_t*)&local_10);

    uRamffff939c = 1;

    //FUN_80094718(); potentially uneccessary 
}
/* Possible SSINIT_H.OBJ/SsInitHot */
void FUN_800cd46c(void){
  FUN_80091e20();//FUN_8009234c();
  //SsUtReverbOff(); calls the function _SpuInit(); which has no equvalent in c
  FUN_800cd37c();
  return;
}


typedef enum {
    INIT_FAILED = 0,
    INIT_SUCCESS = 1
} InitResult;
/**
InitResult FUN_800afed4(int param_1)
{
    if (param_1 == 2) {
        FUN_800b17a8();
        return INIT_SUCCESS;
    }
    
    if (FUN_800b17f4() != 0) {
        return INIT_FAILED;
    }
    
    if (param_1 != 1) {
        return INIT_SUCCESS;
    }
    
    if (FUN_800b16b8() != 0) {
        return INIT_FAILED;
    }
    
    return INIT_SUCCESS;
}
**/
// External declaration for the global variable
extern void (*DAT_8012371c)(void);

void* FUN_800affe8(void* param_1)
{
    void* previousValue = DAT_8012371c;
    DAT_8012371c = param_1;
    return previousValue;
}
/**
unsigned int FUN_800afe24(void)
{
    int result;
    int attempts = 4;

    do {
        result = FUN_800afed4(1);
        attempts--;

        if (result == 1) {
            FUN_800affe8(&LAB_800afda8);
            FUN_800afffc(&LAB_800afdd0);
            FUN_800b2d7c(&LAB_800afdf8);
            FUN_800b2d90(0);
            return 1;
        }
    } while (attempts >= 0);

    printf("CdInit: Init failed\n");
    return 0;
}**/


// External declarations
extern uint32_t* DAT_80135424;

// Assuming this is a function pointer type for the system call
typedef int (*SystemCall)(void);

void _remove_ChgclrPAD(void)
{
    // Store the return address
    DAT_80135424 = __builtin_return_address(0);
    
    // Disable interrupts
    syscall(0);//FUN_80090938();
    
    // Perform system call
    SystemCall sysCall = (SystemCall)0xB0;
    int sysCallResult = sysCall();
    
    // Clear 9 words (36 bytes) of memory
    uint32_t* clearStart = (uint32_t*)(*(uint32_t*)(sysCallResult + 0x16C) + 0x62C);
    for (int i = 0; i < 9; i++) {
        clearStart[i] = 0;
    }
    
    // Flush the cache
    //FlushCache(); dead end in compiler
    
    // Re-enable interrupts
    syscall(0); //FUN_80090948();
}
// External declarations
extern bool DAT_80115a14;

// External declarations
uint32_t* DAT_801353f8 = (uint32_t*)0x801353f8;  // Memory region 2
extern uint32_t DAT_801353fc;
extern uint32_t DAT_80135400;

// System call function pointer type
typedef int (*SystemCall)(void);

// Define the system call number
#define SYS_GET_KERNEL_STRUCT 0xB0

void _patch_pad(void)
{
    // Store the return address
    DAT_801353f8 = (uint32_t*)__builtin_return_address(0); // maybe this is about putting a value into a pointer
    
    // Disable interrupts
    syscall(0);//FUN_80090938();
    
    // Perform system call to get kernel structure
    SystemCall getKernelStruct = (SystemCall)SYS_GET_KERNEL_STRUCT;
    int kernelStructAddr = getKernelStruct();
    
    // Get the base address for pad-related structures
    uint32_t padBaseAddr = *(uint32_t*)(kernelStructAddr + 0x16C);
    
    // Store some addresses for later use
    DAT_801353fc = padBaseAddr + 0x884;
    DAT_80135400 = padBaseAddr + 0x894;
    
    // Clear 11 words (44 bytes) of memory
    uint32_t* clearStart = (uint32_t*)(padBaseAddr + 0x594);
    memset(clearStart, 0, 11 * sizeof(uint32_t));
    
    // Flush the cache
    //FlushCache(); // dead end in decompiler
}

// Assuming JOY_MCD_CTRL is a memory-mapped I/O register
volatile uint32_t* JOY_MCD_CTRL = (volatile uint32_t*)0x1F801040;  // Address is an example

uint32_t LAB_80090c84(void)
{
    *JOY_MCD_CTRL = 0;  // Reset the controller control register
    
    // Simple delay loop
    for (int i = 9; i >= 0; i--) {
        // Do nothing, just wait
    }
    
    return 0;
}

// Assuming these are memory-mapped I/O registers
//volatile uint32_t* const I_MASK1 = (volatile uint32_t*)0x1F801074;  // Interrupt mask register
//volatile uint32_t* const I_STAT = (volatile uint32_t*)0x1F801070;  // Interrupt status register

#define CONTROLLER_INT_BIT 0x01  // Bit 0 corresponds to the controller interrupt

bool LAB_80090cec(void) // function most likely wont behave like it should
{
    // Check if the controller interrupt is enabled (masked)
    if (I_MASK & CONTROLLER_INT_BIT) {
        // Check if the controller interrupt is not pending
        if (!(I_STAT & CONTROLLER_INT_BIT)) {
            return true;
        }
    }
    return false;
}
// External declarations
extern uint32_t DAT_80135408;
extern uint32_t DAT_8013540c;
extern uint32_t DAT_80135404;
extern uint32_t DAT_80135410;



uint32_t FUN_80090bd4(void)
{
    syscall(0);//FUN_80090938();  // Likely disables interrupts
    
    DAT_80135408 = (uint32_t)&LAB_80090c84;
    DAT_8013540c = (uint32_t)&LAB_80090cec;
    DAT_80135404 = 0;
    DAT_80135410 = 0;
    
    //SysDeqIntRP(1, &DAT_80135404); dead end in decompiler
    //SysEnqIntRP(1, &DAT_80135404); dead end in decompiler
    
    syscall(0);//FUN_80090948();  // Likely re-enables interrupts
    
    return 1;
}
// Define hardware registers
#define CDROM_REG0 (*(volatile uint8_t*)0x1F801800)
#define CDROM_REG2 (*(volatile uint8_t*)0x1F801802)
#define CDROM_REG3 (*(volatile uint8_t*)0x1F801803)

// External declarations
extern uint8_t DAT_80123739;
extern uint32_t DAT_80123728;
extern uint32_t DAT_8012372c;
extern uint32_t DAT_80123730;
extern uint8_t DAT_801236e4;
extern uint8_t DAT_801236e5;
extern uint8_t DAT_801236e6;
extern uint8_t DAT_80139bdc[];
extern uint8_t DAT_80139be4[];
extern uint8_t DAT_80139bec[];
extern uint32_t DAT_801235cc[];
extern uint32_t DAT_801234cc[];


uint32_t FUN_800b05d4(void)
{
    uint8_t interruptStatus;
    uint8_t statusBuffer[8] = {0};
    uint32_t result = 0;
    uint32_t errorFlags = 0;

    CDROM_REG0 = 1;
    
    if ((CDROM_REG3 & 7) == 0) {
        return 0;
    }

    interruptStatus = CDROM_REG3 & 7;

    CDROM_REG0 = 1;
    CDROM_REG3 = 7;
    CDROM_REG2 = 7;

    if (interruptStatus != 3 || DAT_801235cc[DAT_80123739] != 0) {
        if ((DAT_80123728 & 0x10) == 0 && (statusBuffer[0] & 0x10) != 0) {
            DAT_80123730++;
        }
        DAT_80123728 = statusBuffer[0];
        DAT_8012372c = statusBuffer[1];
        errorFlags = DAT_80123728 & 0x1d;
    }

    switch(interruptStatus) {
        case 1:
            DAT_801236e5 = errorFlags ? 5 : 1;
            memcpy(DAT_80139be4, statusBuffer, 8);
            CDROM_REG0 = 0;
            CDROM_REG3 = 0;
            result = 4;
            break;

        case 2:
            DAT_801236e4 = errorFlags ? 5 : 2;
            memcpy(DAT_80139bdc, statusBuffer, 8);
            result = 2;
            break;

        case 3:
            if (errorFlags == 0) {
                if (DAT_801234cc[DAT_80123739] == 0) {
                    DAT_801236e4 = 2;
                    memcpy(DAT_80139bdc, statusBuffer, 8);
                    result = 2;
                } else {
                    DAT_801236e4 = 3;
                    memcpy(DAT_80139bdc, statusBuffer, 8);
                    result = 1;
                }
            } else {
                DAT_801236e4 = 5;
                memcpy(DAT_80139bdc, statusBuffer, 8);
                result = 2;
            }
            break;

        case 4:
            DAT_801236e6 = 4;
            DAT_801236e5 = 4;
            memcpy(DAT_80139bec, statusBuffer, 8);
            memcpy(DAT_80139be4, statusBuffer, 8);
            result = 4;
            break;

        case 5:
            DAT_801236e5 = 5;
            DAT_801236e4 = 5;
            memcpy(DAT_80139bdc, statusBuffer, 8);
            memcpy(DAT_80139be4, statusBuffer, 8);
            result = 6;
            break;

        default:
            //FUN_80091184("CDROM: unknown intr"); // dead end in decomp
            printf("(%d)\n", interruptStatus);
            result = 0;
    }

    return result;
}

// External declarations
extern uint32_t DAT_80135414;
extern uint32_t DAT_80135418;
extern uint32_t DAT_80090e9c[];
extern uint32_t UNK_80090eac;

// System call function pointer type
typedef int (*SystemCall)(void);

#define SYS_GET_KERNEL_STRUCT 0xB0

int FUN_80090e10(void)
{
    DAT_80135414 = (uint32_t)__builtin_return_address(0);
    
    syscall(0); //FUN_80090938();  // Likely disables interrupts
    
    // Get kernel structure
    SystemCall getKernelStruct = (SystemCall)SYS_GET_KERNEL_STRUCT;
    int kernelStructAddr = getKernelStruct();
    
    uint32_t* baseAddr = (uint32_t*)(*(uint32_t*)(kernelStructAddr + 0x16C));
    DAT_80135418 = (uint32_t)(baseAddr + 0x1E8);  // 0x7A0 / 4 = 0x1E8
    
    uint32_t* src = DAT_80090e9c;
    uint32_t* dest1 = baseAddr + 0xF6;  // 0x3D8 / 4 = 0xF6
    uint32_t* dest2 = baseAddr + 0x138;  // 0x4E0 / 4 = 0x138
    
    while ((uintptr_t)src < (uintptr_t)&UNK_80090eac) {
        *dest1++ = *dest2++ = *src++;
    }
    
    //FlushCache(); dead end in decompiler
    syscall(0);//FUN_80090948();  // Likely re-enables interrupts
    
    return DAT_80135418;
}
void FUN_80090d40(uint32_t param_1, uint32_t* param_2) //, uint32_t param_3, uint32_t param_4)
{
    _remove_ChgclrPAD();
    syscall(0);//FUN_80090938();
    _patch_pad();
    syscall(0);//FUN_80090948();
    //ChangeClearPAD(0); dead end in decompiler
    FUN_80090bd4();
    //PAD_init2(param_1, param_2, param_3, param_4); dead end in code
    FUN_80090e10();
    DAT_80115a14 = true;
}
// External declarations
extern uint32_t DAT_80135450; // issue with varible type
extern uint32_t DAT_80135460;

void FUN_80091b9c(uint32_t param_1)
{
    DAT_80135450 = -1;  // 0xffffffff
    DAT_80135460 = param_1;
    
    FUN_80091e20(); //FUN_8009234c();
    FUN_80090d40(0x20000001, &DAT_80135450); // parameter issue temporary fix with culling part of the function
    
    //ChangeClearPAD(0); dead end in code
}

// Hardware register
#define CDROM_REG0 (*(volatile uint8_t*)0x1F801800)

// Function prototypes

// Callback function pointers
/**extern void (*DAT_80123720)(uint8_t, void*);
extern void (*DAT_8012371c)(uint8_t, void*);

// Global variables
extern uint8_t DAT_801236e5;
extern uint8_t DAT_801236e4;
extern void* DAT_80139be4;
extern void* DAT_80139bdc;

void LAB_800b0b30(void)
{
    uint8_t originalReg0Value = CDROM_REG0 & 0x3;
    
    while (true) {
        uint32_t status = FUN_800b05d4();
        if (status == 0) break;
        
        if ((status & 0x4) && DAT_80123720) {
            DAT_80123720(DAT_801236e5, &DAT_80139be4);
        }
        
        if ((status & 0x2) && DAT_8012371c) {
            DAT_8012371c(DAT_801236e4, &DAT_80139bdc);
        }
    }
    
    CDROM_REG0 = originalReg0Value;
}**/

// External declarations for global variables
extern uint32_t DAT_80123720;
//extern uint32_t DAT_8012371c;



void FUN_800b17a8(void)
{
    // Reset global variables
    DAT_80123720 = 0;
    DAT_8012371c = 0;
    DAT_8012372c = 0;
    DAT_80123728 = 0;

    // Call some initialization function
    FUN_80091e20();//FUN_8009234c();

    // Set up an interrupt handler
      //FUN_800920c8(2, &LAB_800b0b30); //FUN_8009237c(2, &LAB_800b0b30); so FUN_800920c8(); originally called a void function that didnt send parameters
}

// Define hardware registers
#define CDROM_REG0 (*(volatile uint8_t*)0x1F801800)
#define CDROM_REG3 (*(volatile uint8_t*)0x1F801803)
#define COMMON_DELAY (*(volatile uint16_t*)0x1F801020)

// External declarations
extern uint8_t DAT_801236e6;
extern uint8_t DAT_801236e5;
extern uint8_t DAT_801236e4;

// Constants
#define CDROM_STATUS_MASK 0x07
#define CDROM_READY_STATE 2
#define DELAY_VALUE 0x1325

void FUN_800b15e4(void)
{
    // Wait for CD-ROM controller to be ready
    while ((CDROM_REG3 & CDROM_STATUS_MASK) != 0) {
        // Busy wait
    }

    // Reset status flags
    DAT_801236e6 = 0;
    DAT_801236e5 = 0;
    DAT_801236e4 = CDROM_READY_STATE;

    // Clear CD-ROM registers
    CDROM_REG0 = 0;
    CDROM_REG3 = 0;

    // Set delay value
    COMMON_DELAY = DELAY_VALUE;
}
// Define constants
#define TIMEOUT_INCREMENT 0x3c0
#define MAX_TIMEOUT_COUNT 0x3c0000
//#define CDROM_STATUS_MASK 3
#define CDROM_READY_STATE 2
#define CDROM_ERROR_STATE 5
#define RESULT_BUFFER_SIZE 8

// External declarations
extern uint32_t DAT_80139bf4;
extern uint32_t DAT_80139bf8;
extern const char* DAT_80139bfc;
extern uint8_t DAT_80123739;
extern uint8_t DAT_801236e4;
extern uint8_t DAT_801236e5;
extern uint8_t DAT_80115a5e;
extern uint8_t DAT_80139bdc[];
extern uint8_t DAT_80139be4[];
//extern void (*DAT_80123720)(uint8_t, uint8_t*);
//extern void (*DAT_8012371c)(uint8_t, uint8_t*);
extern const char* PTR_s_CdlSync_80123740[];
extern const char* PTR_s_NoIntr_801237c0[];

// Define hardware registers
#define CDROM_REG0 (*(volatile uint8_t*)0x1F801800)

uint32_t FUN_800b0c08(int32_t param_1, uint8_t* param_2)
{
    uint8_t uVar1;
    bool bVar2;
    int32_t iVar3;
    uint32_t uVar4;
    uint8_t* puVar5;
    uint8_t bVar6;
  
    iVar3 = FUN_80091ca8(-1);
    DAT_80139bf4 = iVar3 + TIMEOUT_INCREMENT;
    DAT_80139bf8 = 0;
    DAT_80139bfc = "CD_sync";
    
    while (true) {
        iVar3 = FUN_80091ca8(-1);
        if ((DAT_80139bf4 < iVar3) ||
            (iVar3 = DAT_80139bf8 + 1, bVar2 = MAX_TIMEOUT_COUNT < DAT_80139bf8, DAT_80139bf8 = iVar3, bVar2)) {
            //FUN_80091184("CD timeout: "); // dead end in decomp
            printf("%s:(%s) Sync=%s, Ready=%s\n",
                   DAT_80139bfc,
                   PTR_s_CdlSync_80123740[DAT_80123739],
                   PTR_s_NoIntr_801237c0[DAT_801236e4],
                   PTR_s_NoIntr_801237c0[DAT_801236e5]);
            FUN_800b15e4();
            iVar3 = -1;
        }
        else {
            iVar3 = 0;
        }
        if (iVar3 != 0) {
            return 0xffffffff;
        }
        iVar3 = DAT_80115a5e; //FUN_80092440();
        bVar6 = CDROM_REG0;
        if (iVar3 != 0) {
            bVar6 = CDROM_REG0 & CDROM_STATUS_MASK;
            while (true) {
                uVar4 = FUN_800b05d4();
                if (uVar4 == 0) break;
                if (((uVar4 & 4) != 0) && (DAT_80123720 != NULL)) {
                    //(*DAT_80123720)(DAT_801236e5, DAT_80139be4); //some weird expression
                }
                if (((uVar4 & 2) != 0) && (DAT_8012371c != NULL)) {
                    //(*DAT_8012371c)(DAT_801236e4, DAT_80139bdc); //some weird expression
                }
            }
        }
        CDROM_REG0 = bVar6;
        uVar4 = (uint32_t)DAT_801236e4;
        if ((uVar4 == CDROM_READY_STATE) || (uVar4 == CDROM_ERROR_STATE)) break;
        if (param_1 != 0) {
            return 0;
        }
    }
    DAT_801236e4 = CDROM_READY_STATE;
    puVar5 = DAT_80139bdc;
    iVar3 = RESULT_BUFFER_SIZE - 1;
    if (param_2 == NULL) {
        DAT_801236e4 = CDROM_READY_STATE;
        return uVar4;
    }
    do {
        uVar1 = *puVar5;
        puVar5++;
        iVar3--;
        *param_2 = uVar1;
        param_2++;
    } while (iVar3 != -1);
    return uVar4;
}

// Define hardware registers
#define CDROM_REG0 (*(volatile uint8_t*)0x1F801800)
#define CDROM_REG1 (*(volatile uint8_t*)0x1F801801)
#define CDROM_REG2 (*(volatile uint8_t*)0x1F801802)

// External declarations
extern uint32_t DAT_8012364c[];
extern uint32_t DAT_8012354c[];
extern uint8_t DAT_80123734[];
extern uint8_t DAT_80123738;
extern uint8_t DAT_801236e4;
extern uint8_t DAT_801236e5;
extern uint8_t DAT_80123739;
extern uint32_t DAT_80139bf4;
extern uint32_t DAT_80139bf8;
extern const char* DAT_80139bfc;
extern uint8_t DAT_80139bdc[];
extern uint8_t DAT_80139be4[];
//extern void (*DAT_80123720)(uint8_t, uint8_t*);
//extern void (*DAT_8012371c)(uint8_t, uint8_t*);
extern const char* PTR_s_CdlSync_80123740[];
extern const char* PTR_s_NoIntr_801237c0[];

int32_t FUN_800b1150(uint8_t command, uint8_t* params, uint8_t* result, int32_t syncMode)
{
    if (DAT_8012364c[command] == 0 && params == NULL) {
        return -2;
    }

    FUN_800b0c08(0, 0);

    if (command == 2) {
        memcpy(DAT_80123734, params, 4);
    }

    if (command == 0xE) {
        DAT_80123738 = *params;
    }

    DAT_801236e4 = 0;
    if (DAT_8012354c[command] != 0) {
        DAT_801236e5 = 0;
    }

    CDROM_REG0 = 0;
    for (int i = 0; i < DAT_8012364c[command]; i++) {
        CDROM_REG2 = params[i];
    }

    DAT_80123739 = command;
    CDROM_REG1 = command;

    if (syncMode == 0) {
        int32_t startTime = FUN_80091ca8(-1);
        DAT_80139bf4 = startTime + 0x3C0;
        DAT_80139bf8 = 0;
        DAT_80139bfc = "CD_cw";

        uint8_t reg0Status;
        do {
            reg0Status = CDROM_REG0;
            CDROM_REG0 = reg0Status;

            int32_t currentTime = FUN_80091ca8(-1);
            if (currentTime > DAT_80139bf4 || ++DAT_80139bf8 > 0x3C0000) {
                //FUN_80091184("CD timeout: "); DEID
                printf("%s:(%s) Sync=%s, Ready=%s\n", 
                       DAT_80139bfc, 
                       PTR_s_CdlSync_80123740[DAT_80123739],
                       PTR_s_NoIntr_801237c0[DAT_801236e4],
                       PTR_s_NoIntr_801237c0[DAT_801236e5]);
                FUN_800b15e4();
                return -1;
            }

            if (DAT_80115a5e != 0) { //FUN_80092440() != 0) {
                reg0Status = CDROM_REG0 & 3;
                while (true) {
                    uint32_t interruptFlags = FUN_800b05d4();
                    if (interruptFlags == 0) break;

                    if ((interruptFlags & 4) && DAT_80123720) {
                        //DAT_80123720(DAT_801236e5, DAT_80139be4); // wierd expression
                    }
                    if ((interruptFlags & 2) && DAT_8012371c) {
                        //DAT_8012371c(DAT_801236e4, DAT_80139bdc); // wierd expression
                    }
                }
            }
        } while (DAT_801236e4 == 0);

        if (result != NULL) {
            memcpy(result, DAT_80139bdc, 8);
        }

        return (DAT_801236e4 == 5) ? -1 : 0;
    }

    return 0;
}
// External declarations
/**extern void* PTR_DAT_801236e8;
extern uint8_t DAT_80123739, DAT_80123738;
extern void (*DAT_80123720)(void);
extern void (*DAT_8012371c)(void);
extern uint32_t DAT_8012372c, DAT_80123728;
extern uint8_t DAT_801236e6, DAT_801236e5, DAT_801236e4;

// Hardware registers
#define CDROM_REG0 (*(volatile uint8_t*)0x1F801800)
#define CDROM_REG3 (*(volatile uint8_t*)0x1F801803)
#define COMMON_DELAY (*(volatile uint16_t*)0x1F801020)

bool initializeCDROM(void)
{
    FUN_80091184("CD_init:");
    printf("addr=%08x\n", &PTR_DAT_801236e8);

    // Reset global variables
    DAT_80123739 = DAT_80123738 = 0;
    DAT_80123720 = DAT_8012371c = NULL;
    DAT_8012372c = DAT_80123728 = 0;

    // Set up interrupt handling
    FUN_8009234c();
    FUN_8009237c(2, &LAB_800b0b30);

    // Check CDROM_REG3 status
    if ((CDROM_REG3 & 7) != 0) {
        while(1); // Infinite loop if error condition
    }

    // Initialize more variables
    DAT_801236e6 = 0;
    DAT_801236e5 = 0;
    DAT_801236e4 = 2;

    // Reset CDROM registers
    CDROM_REG0 = 0;
    CDROM_REG3 = 0;
    COMMON_DELAY = 0x1325;

    // Send commands to CD-ROM
    FUN_800b1150(1, 0, 0, 0);
    if ((DAT_80123728 & 0x10) != 0) {
        FUN_800b1150(1, 0, 0, 0);
    }

    if (FUN_800b1150(10, 0, 0, 0) != 0) {
        return false;
    }

    if (FUN_800b1150(12, 0, 0, 0) != 0) {
        return false;
    }

    return (FUN_800b0c08(0, 0) == 2);
}
typedef enum {
    INIT_MODE_NORMAL = 1,
    INIT_MODE_RESET = 2
} InitMode;

bool FUN_800afed4(InitMode mode)
{
    switch (mode) {
        case INIT_MODE_RESET:
            FUN_800b17a8();
            return true;
        
        case INIT_MODE_NORMAL:
            if (FUN_800b17f4() == 0) {
                if (FUN_800b16b8() == 0) {
                    return true;
                }
            }
            return false;
        
        default:
            return FUN_800b17f4() == 0;
    }
}

#define MAX_INIT_ATTEMPTS 5

bool initializeCDROM(void)
{
    for (int attempts = 0; attempts < MAX_INIT_ATTEMPTS; attempts++) {
        if (FUN_800afed4(1)) {
            // Initialization successful, set up callbacks
            FUN_800affe8(&LAB_800afda8);
            FUN_800afffc(&LAB_800afdd0);
            FUN_800b2d7c(&LAB_800afdf8);
            FUN_800b2d90(0);
            return true;
        }
    }

    // Initialization failed after all attempts
    printf("CdInit: Init failed\n");
    return false;
}**/

#define MAX_TIMERS 0x80


typedef struct {
    int16_t duration;
    int16_t priority;
    uint32_t data;
    uint32_t (*callback)(void);
} TimerEntry;

// External declarations
extern TimerEntry g_timerEntries[MAX_TIMERS];
extern int16_t DAT_80137a18;

bool FUN_800a2f64(int16_t param1, int16_t param2, uint32_t param3, uint32_t param4)
{
    DAT_80137a18 = -1;  // 0xFFFF

    // Find the first free slot
    int freeIndex = 0;
    while (freeIndex < MAX_TIMERS && g_timerEntries[freeIndex].duration != -1) {
        freeIndex++;
    }

    // If we found a free slot, add the new entry
    if (freeIndex < MAX_TIMERS) {
        g_timerEntries[freeIndex].duration = param1;
        g_timerEntries[freeIndex].priority = param2;
        g_timerEntries[freeIndex].data = param3;
        //g_timerEntries[freeIndex].callback = param4;
        return true;
    }

    return false;  // No free slots available
}

#define MAX_TIMERS 0x80
#define TIMER_SLOT_FREE -1

extern TimerEntry g_timerEntries[MAX_TIMERS];
extern int16_t g_lastAddedTimerIndex;

bool LAB_800d57ec(int16_t duration, int16_t priority, uint32_t data, void (*callback)(void))
{
    g_lastAddedTimerIndex = TIMER_SLOT_FREE;

    // Find the first free slot
    int freeIndex;
    for (freeIndex = 0; freeIndex < MAX_TIMERS; freeIndex++) {
        if (g_timerEntries[freeIndex].duration == TIMER_SLOT_FREE) {
            break;
        }
    }

    // If we found a free slot, add the new entry
    if (freeIndex < MAX_TIMERS) {
        g_timerEntries[freeIndex] = (TimerEntry){
            .duration = duration,
            .priority = priority,
            .data = data,
            //.callback = callback // grayed out because of unknown data type
        };
        g_lastAddedTimerIndex = freeIndex;
        return true;
    }

    return false;  // No free slots available
}
// External declarations
extern uint8_t DAT_8014f060[0x23];
extern uint32_t DAT_8014f084[0x23];
extern uint16_t DAT_8014f08c[0x23];
extern uint16_t DAT_8014f08a[0x23];
extern uint16_t DAT_8014f090[0x23];
extern uint16_t DAT_8014f08e[0x23];

// Assuming these are memory-mapped registers or variables
volatile uint8_t* const RAM_FFFF927C = (volatile uint8_t*)0xFFFF927C;
volatile uint8_t* const RAM_FFFF9270 = (volatile uint8_t*)0xFFFF9270;
volatile uint8_t* const RAM_FFFF9274 = (volatile uint8_t*)0xFFFF9274;
volatile uint8_t* const RAM_FFFF9278 = (volatile uint8_t*)0xFFFF9278;
volatile uint8_t* const RAM_FFFF9288 = (volatile uint8_t*)0xFFFF9288;


void FUN_800d56e0(void)
{
    // Initialize DAT_8014f060 array
    memset(DAT_8014f060, 0xFF, 0x23);

    // Initialize other arrays
    for (int i = 0; i < 0x23; i++) {
        DAT_8014f084[i] = 0;
        DAT_8014f08c[i] = 0;
        DAT_8014f08a[i] = 0;
        DAT_8014f090[i] = 0;
        DAT_8014f08e[i] = 0;
    }

    // Set specific memory-mapped registers or variables
    RAM_FFFF927C[0] = 0xCC;
    RAM_FFFF927C[1] = 0xCC;
    RAM_FFFF927C[2] = 9;
    RAM_FFFF927C[3] = 9;
    RAM_FFFF927C[4] = 0xFF;
    RAM_FFFF927C[5] = 0;

    RAM_FFFF9270[0] = 0x19;
    RAM_FFFF9270[1] = 0;

    RAM_FFFF927C[8] = 0;
    RAM_FFFF9274[0] = 0;

    // Call a function, possibly to set up a timer or callback
    //FUN_800a2f64(4000, 0, 0, &LAB_800d57ec); need to fix LAB_800d57ec

    RAM_FFFF9278[0] = 0;
    RAM_FFFF9288[0] = 0;
}
// External declarations
extern uint32_t DAT_0000df80[];
extern const uint32_t DAT_800ec200[];
extern const uint32_t DAT_800ec270;
void FUN_800ec39c(void)
{
    uint32_t *dest = DAT_0000df80;
    const uint32_t *src = DAT_800ec200;
    
    while (src != &DAT_800ec270) {
        *dest = *src;
        src++;
        dest++;
    }
}
#include <stdint.h>

// External declarations
extern uint32_t DAT_80155540;
extern uint32_t* _DAT_0000dffc;
//extern const uint32_t DAT_800ec270[];
extern const uint32_t DAT_800ec284;


void FUN_800ec298(void)
{
    DAT_80155540 = (uint32_t)__builtin_return_address(0);
    
    syscall(0);//FUN_80090938();
    
    int kernelStructAddr = 0;//SUB_000000b0();// dont have access to that function yet
    int* someStruct = *(int**)(kernelStructAddr + 0x18);
    uint32_t highPart = *(uint32_t*)(someStruct + 0x1C) * 0x10000;
    uint32_t lowPart = *(uint32_t*)(someStruct + 0x1D) & 0xFFFF;
    
    _DAT_0000dffc = (uint32_t*)(highPart + lowPart + 0x28);
    
    const uint32_t* src = &DAT_800ec270; // used & to make the data types match
    do {
        *_DAT_0000dffc = *src;
        src++;
        _DAT_0000dffc++;
    } while (src != &DAT_800ec284);
    
    //FlushCache(); dead end
}

// External declarations
extern uint32_t DAT_80155540;
//extern const uint32_t DAT_800ec284[];

void FUN_800ec32c(void)
{
    DAT_80155540 = (uint32_t)__builtin_return_address(0);
    
    syscall(0);//FUN_80090938();
    
    int kernelStructAddr = 0;//SUB_000000b0();// dont have access to that function yet
    uint32_t* destAddr = (uint32_t*)(*(uint32_t*)(kernelStructAddr + 0x16C) + 0x9C8);
    
    const uint32_t* src = &DAT_800ec284;
    while ((void*)src != (void*)FUN_800ec298) {
        *destAddr = *src;
        src++;
        destAddr++;
    }
    
    //FlushCache(); dead end
}

// External declarations
extern uint32_t DAT_80155540;
extern uint32_t* _DAT_0000dffc;
//extern const uint32_t DAT_800ec270[];
extern const uint32_t DAT_800ec284;

void FUN_800ec3d0(void) //int param_1) // 
{
    //ChangeClearPAD(0); // dead end in decompiler
    syscall(0);//FUN_80090938();
    
    /**if (DAT_80115a14 == 0){ //FUN_80090d30() == 0) {
        param_1 = 0;
    }**/ //ends up being useless
    
    //InitCARD2(param_1); // dead end in decompiler
    FUN_800ec39c();
    FUN_800ec298();
    FUN_800ec32c();
    syscall(0);//FUN_80090948();
}

void FUN_800ec43c(void)
{
    syscall(0);//FUN_80090938();
    //StartCARD2(); //dead end for decomp
    //ChangeClearPAD(0); // dead end for decomp
    syscall(0);//FUN_80090948();
}
uint32_t FUN_800eaae0(void)
{
    FUN_800ec3d0();
    FUN_800ec43c();
    //_bu_init(); dead end for decomp
    return 0;
}
// External declarations
extern uint32_t DAT_80155494;
extern uint32_t DAT_801554d8;

void FUN_800eb0fc(void)
{
    DAT_80155494 = 0;
    DAT_801554d8 = 0;
    FUN_800eaae0();
}
/**
 * Converts a CD time value to Minutes:Seconds:Frames format in BCD.
 *
 * This function takes a CD time value (in frames) and converts it to
 * a Minutes:Seconds:Frames format, storing each component as a BCD
 * (Binary-Coded Decimal) value in the provided buffer.
 *
 * @param cdTime The CD time value in frames (1/75th of a second).
 * @param bcdTime A pointer to a 3-byte buffer to store the BCD time.
 */
void FUN_800b0450(int param1, uint8_t* param2)
{
    int value = param1 + 150;  // 0x96 is 150 in decimal
    int seconds = value / 75;  // 0x4b is 75 in decimal
    int frames = value % 75;
    int minutes = seconds / 60;
    seconds = seconds % 60;

    param2[2] = (frames % 10) + ((frames / 10) * 6);
    param2[1] = (seconds % 10) + ((seconds / 10) * 6);
    param2[0] = (minutes % 10) + ((minutes / 10) * 6);
}
// Assuming this is the structure of the table entries
typedef struct {
    uint32_t id;
    uint32_t size;
    const char* name;
} ResourceEntry;

// External declarations
extern ResourceEntry resourceTable[];

bool FUN_800a31f8(void* buffer, const char* filename)
{
    const char* baseName = strrchr(filename, '\\');
    if (baseName != NULL) {
        baseName++; // Skip the backslash
    } else {
        baseName = filename;
    }

    for (ResourceEntry* entry = resourceTable; entry->size != 0; entry++) {
        if (strcmp(baseName, entry->name) == 0) {
            *(uint32_t*)((char*)buffer + 4) = entry->size;
            FUN_800b0450(entry->id, buffer);
            return true;
        }
    }

    //FUN_800a31f0(filename); // useless function in decomp
    return false;
}
// Define hardware registers
#define CDROM_REG0 (*(volatile uint8_t*)0x1F801800)
#define CDROM_REG3 (*(volatile uint8_t*)0x1F801803)
#define COMMON_DELAY (*(volatile uint16_t*)0x1F801020)

// External declarations
extern uint8_t DAT_801236e6;
extern uint8_t DAT_801236e5;
extern uint8_t DAT_801236e4;

/**
 * Resets the CD-ROM controller and associated status flags.
 * 
 * This function performs the following actions:
 * 1. Waits for the CD-ROM controller to be in a ready state.
 * 2. Resets various status flags.
 * 3. Clears CD-ROM registers.
 * 4. Sets a delay value, possibly for timing purposes.
 */
void resetCDROMController(void)
{
    // Wait for CD-ROM controller to be ready
    while ((CDROM_REG3 & 0x07) != 0) {
        // Busy wait
    }

    // Reset status flags
    DAT_801236e6 = 0;
    DAT_801236e5 = 0;
    DAT_801236e4 = 2;  // Set to a specific state, possibly "ready" or "reset"

    // Clear CD-ROM registers
    CDROM_REG0 = 0;
    CDROM_REG3 = 0;

    // Set delay value
    COMMON_DELAY = 0x1325;  // 4901 in decimal
}



// External declarations and constants
extern uint32_t DAT_80139bf4;
extern uint32_t DAT_80139bf8;
extern const char* DAT_80139bfc;
extern uint8_t DAT_80123739;
extern uint8_t DAT_801236e4;
extern uint8_t DAT_801236e5;
extern uint8_t DAT_80139bdc[];
extern uint8_t DAT_80139be4[];

#define CDROM_REG0 (*(volatile uint8_t*)0x1F801800)


uint32_t synchronizeCDROM(int param1, uint8_t* result)
{
    int startTime = FUN_80091ca8(-1);
    DAT_80139bf4 = startTime + 960;
    DAT_80139bf8 = 0;
    DAT_80139bfc = "CD_sync";

    while (true) {
        int currentTime = FUN_80091ca8(-1);
        if (currentTime > DAT_80139bf4 || ++DAT_80139bf8 > 0x3C0000) {
            //FUN_80091184("CD timeout: "); // dead end in decomp
            //printf("%s:(%s) Sync=%s, Ready=%s\n", DAT_80139bfc, /* command name */,/* interrupt status */, /* ready status */); 
            resetCDROMController();
            return 0xFFFFFFFF;
        }

        if (DAT_80115a5e != 0) { //FUN_80092440() != 0) {
            uint8_t status = CDROM_REG0 & 3;
            while (true) {
                uint32_t interruptFlags = FUN_800b05d4();
                if (interruptFlags == 0) break;

                if ((interruptFlags & 4) && DAT_80123720) {
                    //DAT_80123720(DAT_801236e5, DAT_80139be4); //wierd expression
                }
                if ((interruptFlags & 2) && DAT_8012371c) {
                    //DAT_8012371c(DAT_801236e4, DAT_80139bdc); //weird expression
                }
            }
            CDROM_REG0 = status;
        }

        if (DAT_801236e4 == 2 || DAT_801236e4 == 5) {
            break;
        }

        if (param1 != 0) {
            return 0;
        }
    }

    DAT_801236e4 = 2;

    if (result != NULL) {
        for (int i = 0; i < 8; i++) {
            result[i] = DAT_80139bdc[i];
        }
    }

    return DAT_801236e4;
}

// External declarations and constants
extern uint32_t DAT_8012364c[];
extern uint32_t DAT_8012354c[];
extern uint8_t DAT_80123734[];
extern uint8_t DAT_80123738;
extern uint8_t DAT_801236e4;
extern uint8_t DAT_801236e5;
extern uint8_t DAT_80123739;
extern uint32_t DAT_80139bf4;
extern uint32_t DAT_80139bf8;
extern const char* DAT_80139bfc;
extern uint8_t DAT_80139bdc[];
extern uint8_t DAT_80139be4[];
//extern void (*DAT_80123720)(uint8_t, uint8_t*); // keep getting multiply data types for these values from the ai
//extern void (*DAT_8012371c)(uint8_t, uint8_t*);

#define CDROM_REG0 (*(volatile uint8_t*)0x1F801800)
#define CDROM_REG1 (*(volatile uint8_t*)0x1F801801)
#define CDROM_REG2 (*(volatile uint8_t*)0x1F801802)

int executeCDCommand(uint8_t command, uint8_t* params, uint8_t* result, int syncMode)
{
    if (DAT_8012364c[command] == 0 && params == NULL) {
        return -2;
    }

    FUN_800b0c08(0, 0);

    if (command == 2) {
        for (int i = 0; i < 4; i++) {
            DAT_80123734[i] = params[i];
        }
    }

    if (command == 0xE) {
        DAT_80123738 = params[0];
    }

    DAT_801236e4 = 0;
    if (DAT_8012354c[command] != 0) {
        DAT_801236e5 = 0;
    }

    CDROM_REG0 = 0;
    for (int i = 0; i < DAT_8012364c[command]; i++) {
        CDROM_REG2 = params[i];
    }

    DAT_80123739 = command;
    CDROM_REG1 = command;

    if (syncMode == 0) {
        int startTime = FUN_80091ca8(-1);
        DAT_80139bf4 = startTime + 960;
        DAT_80139bf8 = 0;
        DAT_80139bfc = "CD_cw";

        while (DAT_801236e4 == 0) {
            int currentTime = FUN_80091ca8(-1);
            if (currentTime > DAT_80139bf4 || ++DAT_80139bf8 > 0x3C0000) {
                //FUN_80091184("CD timeout: "); // DEID
                //printf("%s:(%s) Sync=%s, Ready=%s\n", DAT_80139bfc,/* command name */, /* interrupt status */,/* ready status */);
                FUN_800b15e4();
                return -1;
            }

            if (DAT_80115a5e != 0) { //FUN_80092440() != 0) {
                uint8_t status = CDROM_REG0 & 3;
                while (true) {
                    uint32_t interruptFlags = FUN_800b05d4();
                    if (interruptFlags == 0) break;

                    if ((interruptFlags & 4) && DAT_80123720) {
                        //DAT_80123720(DAT_801236e5, DAT_80139be4); //wierd expression
                    }
                    if ((interruptFlags & 2) && DAT_8012371c) {
                        //DAT_8012371c(DAT_801236e4, DAT_80139bdc); //wierd expression
                    }
                }
            }
        }

        if (result) {
            for (int i = 0; i < 8; i++) {
                result[i] = DAT_80139bdc[i];
            }
        }

        return (DAT_801236e4 == 5) ? -1 : 0;
    }

    return 0;
}

// External declarations
extern void (*DAT_8012371c)(void);
//extern uint8_t DAT_80123728;
extern uint32_t DAT_8012344c[];

bool FUN_800b0010(uint8_t param1, int param2, int param3)
{
    void (*originalCallback)(void) = DAT_8012371c;
    int retryCount = 3;

    while (retryCount >= 0) {
        DAT_8012371c = NULL;

        if (param1 != 1 && (DAT_80123728 & 0x10) != 0) {
            FUN_800b1150(1, 0, 0, 0);
        }

        bool needSecondTry = (param2 == 0) || (DAT_8012344c[param1] == 0) || 
                             (FUN_800b1150(2, param2, param3, 0) == 0);

        if (needSecondTry) {
            DAT_8012371c = originalCallback;
            if (FUN_800b1150(param1, param2, param3, 0) == 0) {
                return true;
            }
        } else {
            return true;
        }

        retryCount--;
    }

    DAT_8012371c = originalCallback;
    return false;
}


// External declaration
//extern void (*DAT_80123720)(uint8_t, uint8_t*);

void* FUN_800afffc(void* newCallback)
{
    void* oldCallback = &DAT_80123720;
    DAT_80123720 = newCallback;
    return oldCallback;
}
// External declarations
extern uint16_t DAT_80123804;
extern uint32_t DAT_80123800;
extern uint32_t DAT_801237f4;
extern uint32_t DAT_801237f8;
extern uint32_t DAT_80123818;
extern uint32_t DAT_8012381c;
extern uint32_t DAT_80123824;
extern uint32_t DAT_80123820;
extern uint32_t DAT_80123810;

bool FUN_800b2bb4(uint32_t param1, uint32_t param2, uint32_t param3)
{
    // Set transfer mode
    if ((param3 & 0x30) == 0) {
        DAT_80123804 = 0x200;  // Mode 0
    } else if ((param3 & 0x30) == 0x20) {
        DAT_80123804 = 0x249;  // Mode 1
    } else {
        DAT_80123804 = 0x246;  // Mode 2
    }

    // Set transfer parameters
    DAT_80123800 = param3 | 0x20;
    DAT_801237f4 = param1;
    DAT_801237f8 = param2;

    // Initialize transfer-related variables
    DAT_80123818 = FUN_800affe8(0);
    DAT_8012381c = FUN_800afffc(0);

    // Conditional initialization
    if ((DAT_80123824 & 1) != 0) {
        DAT_80123820 = FUN_800b040c(0);
    }

    // Set start time
    DAT_80123810 = FUN_80091ca8(-1);

    // Check and handle any existing errors
    uint32_t status = FUN_800afea8();
    if ((status & 0xE0) != 0) {
        FUN_800b0280(9, 0, 0);
    }

    // Start the transfer
    int32_t result = FUN_800b29c4(0);

    return result > 0;
}
void FUN_800a3410(uint32_t param1, void* param2)
{
    uint8_t buffer[4];
    int transferSize;
    int result;
    
    result = FUN_800a31f8(buffer, param1);
    while (result != 0) {
        do {
            do {
                result = FUN_800b0010(2, buffer, 0);
            } while (result == 0);
            
            result = FUN_800b2bb4((transferSize + 0x7FF) >> 11, param2, 0x80);
        } while (result == 0);
        
        do {
            result = FUN_800b2cb4(0, 0);
        } while (result > 0);
    }
}
void FUN_800a34ac(uint32_t param_1, uint32_t param_2)
{
    GsIMAGE imageInfo;
    short x, y;
    unsigned short width, height;
    
    FUN_800a3410();
    GsGetTimInfo((uint32_t*)(param_2 + 4), &imageInfo);
    
    x = imageInfo.px;
    y = imageInfo.py;
    width = imageInfo.pw;
    height = imageInfo.ph;
    
    FUN_800948a8(&x, imageInfo.pixel);
    
    if ((imageInfo.pmode >> 3) & 1) {
        x = imageInfo.cx;
        y = imageInfo.cy;
        width = imageInfo.cw;
        height = imageInfo.ch;
        FUN_800948a8(&x, imageInfo.clut);
    }
}
// Global variable declaration
uint32_t* DAT_80115a24;
uint8_t DAT_801bfb70[0x30390];  // Assuming this is the correct size
extern int32_t iRamffff948c;  // Assuming this is an external variable
extern int32_t uRamffff89c8;  // Assuming this is an external variable

void thunk_FUN_800ee800(void){
  int iVar1;
  uint uVar2;
  
  InitHeap3((ulong *)&DAT_801bfb70,0x30390);//FUN_800eebdc();
  FUN_800cd46c();
  FUN_80091e20();//FUN_8009234c();
  FUN_80094538(0);
  FUN_800946ac(0);
  FUN_800eec14();
  FUN_80091b9c(0);
  //FUN_800afe24();
  FUN_800eb0fc();
  //FUN_800eb128();
  FUN_800a1e38();
  FUN_800a2ef8();
  //FUN_800a396c();
  //FUN_800e36c8();
  FUN_800a3b20();
  //FUN_8010cb3c();
  //FUN_800e8a00();
  initializeHardwareRegisters();
  //FUN_801059c8();
  //FUN_800f02f4();
  FUN_800c2838();
  //FUN_800f0380();
  //FUN_800f03c0();
  //FUN_800e1130();
  FUN_800dce04();
  //FUN_800a435c();
  FUN_800a34ac("\\ETCDAT\\FI_INFO.TIM",uRamffff89c8);
  /**do {
    FUN_800a34ac("\\ETCNA\\TITLE256.TIM",uRamffff89c8);
    iRamffff9384 = 0;
    while (iRamffff9384 == 0) {
      FUN_800e66b4(0,1);
      FUN_800c5fd0();
      FUN_800eed30();
      FUN_800c60d4();
    }
    FUN_800e65c0("\\ETCDAT\\ETCTIM.BIN");
    FUN_800c5fd0();
    FUN_800eefe4();
    if (cRamffff9388 == '\x02') {
      FUN_800c60d4();
      FUN_800e66b4(2,1);
      FUN_800c5fd0();
      FUN_800e65c0("\\ETCDAT\\ETCTIM.BIN");
      FUN_800a97f4(0,0,0,0,0,0,0);
      FUN_800a442c(DAT_80155670,0,0,0,0,0,0);
      FUN_800d56e0();
      FUN_800e0870();
      FUN_80105ae4(DAT_80155725);
      FUN_800ef38c();
      FUN_800dcf38();
      iVar1 = FUN_800ac050();
      if (iVar1 != 0) {
        FUN_800aa188(0);
      }
    }
    else if (cRamffff9388 == '\x01') {
      FUN_800e65c0("\\ETCDAT\\ETCTIM.BIN");
      FUN_800a97f4(0,0,0,0,0,0,0);
      FUN_800a442c(DAT_80155670,0,0,0,0,0,0);
      FUN_800d56e0();
      FUN_800e0870();
      FUN_80105ae4(DAT_80155725);
      FUN_800ef38c();
      FUN_800dcf38();
      iVar1 = FUN_800ac050();
      if (iVar1 != 0) {
        FUN_800aa188(0);
      }
    }
    else if (cRamffff9388 == '\0') {
      FUN_800ef1e0();
      FUN_800c60d4();
      FUN_800e66b4(1);
      FUN_800c5fd0();
      FUN_800e65c0("\\ETCDAT\\ETCTIM.BIN");
      FUN_800a97f4(0,0,0,0,0,0,0);**/
      iVar1 = (0xfe + iRamffff948c + 0x159);//FUN_801062e0(0xfe);
      uVar2 = 0x11;
      if (iVar1 == 0) {
        uVar2 = 3;
      }/**
      FUN_800a442c(uVar2,0,0,0,0,0,0);
      FUN_800ff7f8(uVar2);**/
      FUN_800d56e0();
      /**FUN_800e0870();
      FUN_80105ae4(0xcc);
      FUN_800dcf38();**/
      uRamffff92f4 = 0;//FUN_800dd798();
    /**}
    FUN_800ace74(0x28);
    FUN_800efa18();
    while (cRamffff9388 != '\x03') {
      FUN_800efb68();
    }
    FUN_800d96b4();
    FUN_800c60d4();
    FUN_800e66b4(3,1);
  } while( true );**/
}

uint32_t* DAT_80134c4c = (uint32_t*)0x80134c4c;  // Memory region 1
volatile uint32_t* DAT_801fff00 = (uint32_t*)0x801fff00;  // Some global address

int main(void) {
    uint32_t* memPtr1 = DAT_80134c4c;  // Pointer to first memory block
    uint32_t* memPtr2 = DAT_801353f8;  // Pointer to second memory block
    int size1 = 0x7ac;    // Size of first memory block (1964 bytes)
    int size2 = 0x8a76c;  // Size of second memory block (568308 bytes)
    int unaff_retaddr;    // Presumed return address (needs context)
  
  // Zero out the first memory region
    for (int i = 0; i < size1; i += 4) {
        *memPtr1++ = 0;
    }

    // Zero out the second memory region
    for (int i = 0; i < size2; i += 4) {
        *memPtr2++ = 0;
    }
  __asm__("mtc0 %0, $12" : : "r" (0x40000000)); //setCopReg(0,Status,Status | 0x40000000,0);
  *DAT_801fff00 = unaff_retaddr;
  //thunk_FUN_800ee800(0,0,0,0);
   //exit(1); //800a4344 4d  80  20 00      break      0x8201  ; so this function has an issue ai says that this is where the function closes most likely just a return
  return 0;
}

