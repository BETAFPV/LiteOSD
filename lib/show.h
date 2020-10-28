#ifndef show_h
#define show_h

#include <SI_EFM8BB2_Register_Enums.h>

#include "line.h"
#include "smartaudio.h"
void delay(unsigned char n);


void vtx_window(unsigned short line);


void layout_window(unsigned short line);


void config_window(unsigned short line);


void set_window(unsigned short line);


void flight_window(unsigned short line);



#endif