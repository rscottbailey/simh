/*  front_panel.c: Intel MDS-800 Front Panel Module simulator

    Copyright (c) 2010, William A. Beech

        Permission is hereby granted, free of charge, to any person obtaining a
        copy of this software and associated documentation files (the "Software"),
        to deal in the Software without restriction, including without limitation
        the rights to use, copy, modify, merge, publish, distribute, sublicense,
        and/or sell copies of the Software, and to permit persons to whom the
        Software is furnished to do so, subject to the following conditions:

        The above copyright notice and this permission notice shall be included in
        all copies or substantial portions of the Software.

        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
        IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
        FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
        WILLIAM A. BEECH BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
        IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
        CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

        Except as contained in this notice, the name of William A. Beech shall not be
        used in advertising or otherwise to promote the sale, use or other dealings
        in this Software without prior written authorization from William A. Beech.

        This software was written by Bill Beech, Dec 2010, to allow emulation of Multibus
        Computer Systems.

    5 October 2017 - Original file.
*/

#include "system_defs.h"

/* function prototypes */

t_stat fp_reset (void);
t_stat fp_cfg(void);

/* external function prototypes */

extern uint8 EPROM_get_mbyte(uint16 addr);
extern t_stat EPROM_reset(DEVICE *dptr);
extern t_stat EPROM_cfg(uint16 base, uint16 size);

// external globals

extern UNIT EPROM_unit;                 //1702 EPROM
extern uint16 PCX;                    /* program counter */

// fp configuration

t_stat fp_cfg(void)
{
    sim_printf("Configuring MDS-800 Front Panel Module\n  Onboard Devices:\n");
    EPROM_cfg(ROM0_BASE, ROM0_SIZE);
    return SCPE_OK;
}

/*  CPU reset routine 
    put here to cause a reset of the entire IPC system */

t_stat fp_reset (void)
{    
    return SCPE_OK;
}


/* end of front_panel.c */
