#ifndef config_h
#define config_h

#define show_centerline (125 < line && line < 135)
#define show_lockline (160 < line && line < 169)
#define show_turtleline (180 < line && line < 189)
#define show_modeline (210 < line && line < 219)
#define show_timeline (220 < line && line < 229)
#define show_time_valueline (230 < line && line < 239)
#define show_menuline (70 < line && line < 79)
#define show_pid_setline (90 < line && line < 99)
#define show_motor_line (105 < line && line < 115)
#define show_saveline (120 < line && line < 129)
#define show_menu_exitline (135 < line && line < 145)
#define show_pid_menuline (70 < line && line < 79)
#define show_rpyline (80 < line && line < 89)
#define show_kpline (100 < line && line < 109)
#define show_kiline (130 < line && line < 139)
#define show_kdline (160 < line && line < 169)
#define show_kp_indexline (110 < line && line < 119)
#define show_ki_indexline (140 < line && line < 149)
#define show_kd_indexline (170 < line && line < 179)
#define show_pid_exitline (190 < line && line < 199)
#define show_motor_menuline (80 < line && line < 89)
#define show_m1line (100 < line && line < 109)
#define show_m2line (115 < line && line < 125)
#define show_m3line (130 < line && line < 139)
#define show_m4line (145 < line && line < 155)
#define show_motor_exitline (165 < line && line < 175)




//#define delay15 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay14 ("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
//#define delay13 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
//#define delay12 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
//#define delay11 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay10 ("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
//#define delay9  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
//#define delay8  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
//#define delay7  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
//#define delay6  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay5  ("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
//#define delay4  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
//#define delay3  __asm__("nop\n\t""nop\n\t""nop\n\t"); 
//#define delay2  __asm__("nop\n\t""nop\n\t"); 
#define delay1  ("nop\n\t"); 



#endif
