/*
 * Copyright (c) 1996-2011 Barton P. Miller
 * 
 * We provide the Paradyn Parallel Performance Tools (below
 * described as "Paradyn") on an AS IS basis, and do not warrant its
 * validity or performance.  We reserve the right to update, modify,
 * or discontinue this software at any time.  We shall have no
 * obligation to supply such updates or modifications or any other
 * form of support to you.
 * 
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

// $Id: linux-power.h,v 1.4 2007/08/09 18:22:21 ssuen Exp $

#if !defined(os_linux) || !defined(arch_power)
#error "invalid architecture-os inclusion"
#endif

#ifndef LINUX_POWER_HDR
#define LINUX_POWER_HDR

#include <asm/ptrace.h>

// fields within ptrace() pt_regs structure
#define PTRACE_REG_FP gpr[1] // frame pointer
#define PTRACE_REG_IP nip    // next instruction pointer

struct dyn_saved_regs
{
   struct pt_regs gprs;      // 32 general purpose registers plus most SPRs
   struct fp_regs {
     double        fpr[32];  // 32 floating point registers
     unsigned long fpscr;    // floating point status and control register
   }              fprs;
};


#include "dyninstAPI/src/inst.h"

// floor of inferior malloc address range within a single branch of x
// for 32-bit ELF PowerPC mutatees
extern Address region_lo(const Address x);

// floor of inferior malloc address range within a single branch of x
// for 64-bit ELF PowerPC mutatees
extern Address region_lo_64(const Address x);

// ceiling of inferior malloc address range within a single branch of x
// for 32-bit ELF PowerPC mutatees
extern Address region_hi(const Address x);

// ceiling of inferior malloc address range within a single branch of x
// for 64-bit ELF PowerPC mutatees
extern Address region_hi_64(const Address x);


#endif
