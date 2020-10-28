#ifndef freq_h
#define freq_h

// CHANNEL
#define C_A_1 { \
				SPI0DAT = letters[ _a+(temp)]; \
				SPI0DAT = numbers[ 8+(temp)]; \
		}
#define C_A_2 { \
				SPI0DAT = letters[ _a+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
		}
#define C_A_3 { \
				SPI0DAT = letters[ _a+(temp)]; \
				SPI0DAT = numbers[ 24+(temp)]; \
		}
#define C_A_4 { \
				SPI0DAT = letters[ _a+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
		}
#define C_A_5 { \
				SPI0DAT = letters[ _a+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define C_A_6 { \
				SPI0DAT = letters[ _a+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
		}
#define C_A_7 { \
				SPI0DAT = letters[ _a+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
		}
#define C_A_8 { \
				SPI0DAT = letters[ _a+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
		}

#define C_B_1 { \
				SPI0DAT = letters[ _b+(temp)]; \
				SPI0DAT = numbers[ 8+(temp)]; \
		}
#define C_B_2 { \
				SPI0DAT = letters[ _b+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
		}
#define C_B_3 { \
				SPI0DAT = letters[ _b+(temp)]; \
				SPI0DAT = numbers[ 24+(temp)]; \
		}
#define C_B_4 { \
				SPI0DAT = letters[ _b+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
		}
#define C_B_5 { \
				SPI0DAT = letters[ _b+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define C_B_6 { \
				SPI0DAT = letters[ _b+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
		}
#define C_B_7 { \
				SPI0DAT = letters[ _b+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
		}
#define C_B_8 { \
				SPI0DAT = letters[ _b+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
		}		
		
#define C_C_1 { \
				SPI0DAT = letters[ _c+(temp)]; \
				SPI0DAT = numbers[ 8+(temp)]; \
		}
#define C_C_2 { \
				SPI0DAT = letters[ _c+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
		}
#define C_C_3 { \
				SPI0DAT = letters[ _c+(temp)]; \
				SPI0DAT = numbers[ 24+(temp)]; \
		}
#define C_C_4 { \
				SPI0DAT = letters[ _c+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
		}
#define C_C_5 { \
				SPI0DAT = letters[ _c+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define C_C_6 { \
				SPI0DAT = letters[ _c+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
		}
#define C_C_7 { \
				SPI0DAT = letters[ _c+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
		}
#define C_C_8 { \
				SPI0DAT = letters[ _c+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
		}		
		
#define C_D_1 { \
				SPI0DAT = letters[ _d+(temp)]; \
				SPI0DAT = numbers[ 8+(temp)]; \
		}
#define C_D_2 { \
				SPI0DAT = letters[ _d+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
		}
#define C_D_3 { \
				SPI0DAT = letters[ _d+(temp)]; \
				SPI0DAT = numbers[ 24+(temp)]; \
		}
#define C_D_4 { \
				SPI0DAT = letters[ _d+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
		}
#define C_D_5 { \
				SPI0DAT = letters[ _d+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define C_D_6 { \
				SPI0DAT = letters[ _d+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
		}
#define C_D_7 { \
				SPI0DAT = letters[ _d+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
		}
#define C_D_8 { \
				SPI0DAT = letters[ _d+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
		}

#define C_E_1 { \
				SPI0DAT = letters[ _e+(temp)]; \
				SPI0DAT = numbers[ 8+(temp)]; \
		}
#define C_E_2 { \
				SPI0DAT = letters[ _e+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
		}
#define C_E_3 { \
				SPI0DAT = letters[ _e+(temp)]; \
				SPI0DAT = numbers[ 24+(temp)]; \
		}
#define C_E_4 { \
				SPI0DAT = letters[ _e+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
		}
#define C_E_5 { \
				SPI0DAT = letters[ _e+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define C_E_6 { \
				SPI0DAT = letters[ _e+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
		}
#define C_E_7 { \
				SPI0DAT = letters[ _e+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
		}
#define C_E_8 { \
				SPI0DAT = letters[ _e+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
		}		
		
			
		
//FREQ		
#define A_1   { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_2 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
		
#define A_3 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_4 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_5 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_6 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_7 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_8 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}

#define B_1 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 24+(temp)]; \
				SPI0DAT = numbers[ 24+(temp)]; \
		}
#define B_2 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
		}
#define B_3 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 8+(temp)]; \
		}
#define B_4 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 72+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
		}
#define B_5 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
				SPI0DAT = numbers[ 72+(temp)]; \
		}
#define B_6 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define B_7 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
		}
#define B_8 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
		}

#define E_1 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_2 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_3 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_4 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_5 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_6 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 72+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_7 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 72+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_8 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 72+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}

#define Air_1 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_2 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_3 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_4 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_5 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_6 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_7 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_8 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
		}

#define Race_1 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
		}
#define Race_2 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 72+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
		}
#define Race_3 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 24+(temp)]; \
				SPI0DAT = numbers[ 16+(temp)]; \
		}
#define Race_4 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
				SPI0DAT = numbers[ 72+(temp)]; \
		}
#define Race_5 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
				SPI0DAT = numbers[ 48+(temp)]; \
		}
#define Race_6 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 32+(temp)]; \
				SPI0DAT = numbers[ 24+(temp)]; \
		}
#define Race_7 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 64+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Race_8 { \
				SPI0DAT = numbers[ 40+(temp)]; \
				SPI0DAT = numbers[ 72+(temp)]; \
				SPI0DAT = numbers[ 8+(temp)]; \
				SPI0DAT = numbers[ 56+(temp)]; \
		}



#endif