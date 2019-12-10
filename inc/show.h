#ifndef show_h
#define show_h

#include <SI_EFM8BB2_Register_Enums.h>

#include "line.h"
#include "smartaudio.h"
void delay(unsigned char n);


void flight_window(unsigned short line);
void set_window(unsigned short line);
void pid_window(unsigned short line);
void motor_window(unsigned short line);
void receiver_window(unsigned short line);
void sa_window(unsigned short line);
void init_window(unsigned short line);
void switch_channel(unsigned char index);

void display_window(unsigned short line);

#endif