/* $XFree86$ */
/* $XdotOrg: xc/programs/Xserver/hw/xfree86/drivers/sisusb/sisusb_dac.h,v 1.4 2005/07/09 03:02:56 twini Exp $ */
/*
 * DAC helper functions (Save/Restore, MemClk, etc)
 * Definitions and prototypes
 *
 * Copyright (C) 2001-2005 by Thomas Winischhofer, Vienna, Austria.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1) Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2) Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3) The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

int  SiSUSB_compute_vclk(int Clock, int *out_n, int *out_dn, int *out_div,
	     		int *out_sbit, int *out_scale);
void SISUSBDACPreInit(ScrnInfoPtr pScrn);
void SISUSBLoadPalette(ScrnInfoPtr pScrn, int numColors, int *indicies,
		        LOCO *colors, VisualPtr pVisual);
void SiSUSBCalcClock(ScrnInfoPtr pScrn, int clock, int max_VLD,
                        unsigned int *vclk);
void SiSUSBIODump(ScrnInfoPtr pScrn);
int  SiSUSBMemBandWidth(ScrnInfoPtr pScrn, Bool IsForCRT2);
int  SiSUSBMclk(SISUSBPtr pSiSUSB);
void SiSUSBRestoreBridge(ScrnInfoPtr pScrn, SISUSBRegPtr sisReg);

extern int      SiSUSBCalcVRate(DisplayModePtr mode);

/* Functions from sisusb_init.c (use its datatypes!) */
extern void     SiSUSB_DisplayOn(SiS_Private *SiS_Pr);
extern UCHAR	SiSUSB_GetSetModeID(ScrnInfoPtr pScrn, UCHAR id);
extern void	SiSUSBRegInit(SiS_Private *SiS_Pr, USHORT BaseAddr);

/* End of init.c/init301.c imports */