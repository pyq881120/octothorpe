/*
 *             _        _   _                           
 *            | |      | | | |                          
 *   ___   ___| |_ ___ | |_| |__   ___  _ __ _ __   ___ 
 *  / _ \ / __| __/ _ \| __| '_ \ / _ \| '__| '_ \ / _ \
 * | (_) | (__| || (_) | |_| | | | (_) | |  | |_) |  __/
 *  \___/ \___|\__\___/ \__|_| |_|\___/|_|  | .__/ \___|
 *                                          | |         
 *                                          |_|
 *
 * Written by Dennis Yurichev <dennis(a)yurichev.com>, 2013
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/3.0/.
 *
 */

#pragma once

#include "datatypes.h"

#ifdef  __cplusplus
extern "C" {
#endif

double cvt80to64 (const byte *p);
void cvt64to80 (double in, byte *out);

// if you will have to use FPU_stuff_MSVC.asm...
#if 0
double __cdecl cvt80to64 (const byte *p);
void __cdecl cvt64to80 (double in, byte *out);
#endif

#ifdef  __cplusplus
}
#endif

/* vim: set expandtab ts=4 sw=4 : */
