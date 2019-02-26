/******************************************************************************
 * Copyright (c) 2014 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// retargetserial.h
/////////////////////////////////////////////////////////////////////////////

#ifndef RETARGETSERIAL_H_
#define RETARGETSERIAL_H_

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

#if defined __ICC8051__
#include <pgmspace.h>
#endif

/////////////////////////////////////////////////////////////////////////////
// Definitions
/////////////////////////////////////////////////////////////////////////////

#if defined __C51__

#define RETARGET_PRINTF         printf
#define RETARGET_SCANF          scanf
#define RETARGET_SPRINTF        sprintf

#define RETARGET_PRINTF_MEM     printf
#define RETARGET_SCANF_MEM      scanf
#define RETARGET_SPRINTF_MEM    sprintf

#elif defined __ICC8051__

// IAR requires printf_P(), which specifies that the string format
// must be defined in CODE, which is the case when constants and strings
// are set to "CODE memory" (default for SDK example projects)
//
// In the unusual case that the string format is stored elsewhere,
// call printf() as usual
#define RETARGET_PRINTF         printf_P
#define RETARGET_SCANF          scanf_P
#define RETARGET_SPRINTF        sprintf_P

// Use these variants of printf when the format string is located in memory
// and not in CODE
#define RETARGET_PRINTF_MEM     printf
#define RETARGET_SCANF_MEM      scanf
#define RETARGET_SPRINTF_MEM    sprintf

// Notes:
// printf/scanf allowed format specifiers are controlled by library options
//
// printf:
// large  - full support (all C89 format directives)
// medium - no float (ie %f will give a runtime error)
// small  - supports %%, %d, %o, %c, %s, and %x int objects
//          no field width or precision
//
// printf formatter linker command line flags:
// -e_large_write=_formatted_write
// -e_medium_write=_formatted_write
// -e_small_write=_formatted_write
//
// printf_P formatter linker command line flags:
// NA (large default)
// -e_medium_write_P=_formatted_write_P
// -e_small_write_P=_formatted_write_P (default for SDK example projects)
//
// See EW8051 Compiler Reference for full details

#endif

/////////////////////////////////////////////////////////////////////////////
// Functions
/////////////////////////////////////////////////////////////////////////////

#if defined __C51__
char RETARGET_ReadChar(void);
char RETARGET_WriteChar(char c);

#elif defined __ICC8051__
int RETARGET_ReadChar(void);
int RETARGET_WriteChar(int c);

#endif

#endif // RETARGETSERIAL_H_
