#ifndef smartaudio_h
#define smartaudio_h


//POWER
#define P_0 { \
				SPI0DAT = numbers[ 0+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
                SPI0DAT = letters[ _m+(temp)]; \
                SPI0DAT = letters[ _w+(temp)]; \
		}
#define P_1 { \
				SPI0DAT = numbers[ 16+(temp)]; \
				SPI0DAT = numbers[ 40+(temp)]; \
                SPI0DAT = letters[ _m+(temp)]; \
                SPI0DAT = letters[ _w+(temp)]; \
		}
#define P_2 { \
				SPI0DAT = numbers[ 16+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
				SPI0DAT = numbers[ 0+(temp)]; \
                SPI0DAT = letters[ _m+(temp)]; \
                SPI0DAT = letters[ _w+(temp)]; \
		}


//channel		
#define A_1   { \
            SPI0DAT = letters[ _a+(temp)]; \
            SPI0DAT = numbers[ 8+(temp)];  \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_2 { \
            SPI0DAT = letters[ _a+(temp)]; \
            SPI0DAT = numbers[ 16+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 32+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
		
#define A_3 { \
            SPI0DAT = letters[ _a+(temp)]; \
			SPI0DAT = numbers[ 24+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 16+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_4 { \
            SPI0DAT = letters[ _a+(temp)]; \
			SPI0DAT = numbers[ 32+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 0+(temp)];  \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_5 { \
            SPI0DAT = letters[ _a+(temp)]; \
			SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_6 { \
            SPI0DAT = letters[ _a+(temp)]; \
			SPI0DAT = numbers[ 48+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_7 { \
            SPI0DAT = letters[ _a+(temp)]; \
			SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 32+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define A_8 { \
            SPI0DAT = letters[ _a+(temp)]; \
			SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 16+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}

#define B_1 { \
            SPI0DAT = letters[ _b+(temp)]; \
			SPI0DAT = numbers[ 8+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 24+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 24+(temp)]; \
		}
#define B_2 { \
            SPI0DAT = letters[ _b+(temp)]; \
			SPI0DAT = numbers[ 16+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 40+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 16+(temp)]; \
		}
#define B_3 { \
            SPI0DAT = letters[ _b+(temp)]; \
			SPI0DAT = numbers[ 24+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 8+(temp)];  \
		}
#define B_4 { \
            SPI0DAT = letters[ _b+(temp)]; \
			SPI0DAT = numbers[ 32+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 72+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 0+(temp)]; \
		}
#define B_5 { \
            SPI0DAT = letters[ _b+(temp)]; \
			SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 0+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 72+(temp)]; \
		}
#define B_6 { \
            SPI0DAT = letters[ _b+(temp)]; \
			SPI0DAT = numbers[ 48+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 16+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define B_7 { \
            SPI0DAT = letters[ _b+(temp)]; \
			SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 32+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 56+(temp)]; \
		}
#define B_8 { \
            SPI0DAT = letters[ _b+(temp)]; \
			SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 48+(temp)]; \
		}

#define E_1 { \
            SPI0DAT = letters[ _c+(temp)]; \
			SPI0DAT = numbers[ 8+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 0+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_2 { \
            SPI0DAT = letters[ _c+(temp)]; \
			SPI0DAT = numbers[ 16+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_3 { \
            SPI0DAT = letters[ _c+(temp)]; \
			SPI0DAT = numbers[ 24+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_4 { \
            SPI0DAT = letters[ _c+(temp)]; \
			SPI0DAT = numbers[ 32+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            SPI0DAT = numbers[ 32+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_5 { \
            SPI0DAT = letters[ _c+(temp)]; \
			SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_6 { \
            SPI0DAT = letters[ _c+(temp)]; \
			SPI0DAT = numbers[ 48+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 72+(temp)]; \
            SPI0DAT = numbers[ 0+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_7 { \
            SPI0DAT = letters[ _c+(temp)]; \
			SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 72+(temp)]; \
            SPI0DAT = numbers[ 16+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define E_8 { \
            SPI0DAT = letters[ _c+(temp)]; \
			SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 72+(temp)]; \
            SPI0DAT = numbers[ 32+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}

#define Air_1 { \
            SPI0DAT = letters[ _d+(temp)]; \
			SPI0DAT = numbers[ 8+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 32+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_2 { \
            SPI0DAT = letters[ _d+(temp)]; \
			SPI0DAT = numbers[ 16+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_3 { \
            SPI0DAT = letters[ _d+(temp)]; \
			SPI0DAT = numbers[ 24+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_4 { \
            SPI0DAT = letters[ _d+(temp)]; \
			SPI0DAT = numbers[ 32+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 0+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_5 { \
            SPI0DAT = letters[ _d+(temp)]; \
			SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 16+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_6 { \
            SPI0DAT = letters[ _d+(temp)]; \
			SPI0DAT = numbers[ 48+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 32+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_7 { \
            SPI0DAT = letters[ _d+(temp)]; \
			SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Air_8 { \
            SPI0DAT = letters[ _d+(temp)]; \
			SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 0+(temp)]; \
		}

#define Race_1 { \
            SPI0DAT = letters[ _e+(temp)]; \
			SPI0DAT = numbers[ 8+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            SPI0DAT = numbers[ 40+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 48+(temp)]; \
		}
#define Race_2 { \
            SPI0DAT = letters[ _e+(temp)]; \
			SPI0DAT = numbers[ 16+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            SPI0DAT = numbers[ 72+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 40+(temp)]; \
		}
#define Race_3 { \
            SPI0DAT = letters[ _e+(temp)]; \
			SPI0DAT = numbers[ 24+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 24+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 16+(temp)]; \
		}
#define Race_4 { \
            SPI0DAT = letters[ _e+(temp)]; \
			SPI0DAT = numbers[ 32+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = numbers[ 48+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 72+(temp)]; \
		}
#define Race_5 { \
            SPI0DAT = letters[ _e+(temp)]; \
			SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 0+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 48+(temp)]; \
		}
#define Race_6 { \
            SPI0DAT = letters[ _e+(temp)]; \
			SPI0DAT = numbers[ 48+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 32+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 24+(temp)]; \
		}
#define Race_7 { \
            SPI0DAT = letters[ _e+(temp)]; \
			SPI0DAT = numbers[ 56+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = numbers[ 64+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 0+(temp)]; \
		}
#define Race_8 { \
            SPI0DAT = letters[ _e+(temp)]; \
			SPI0DAT = numbers[ 64+(temp)]; \
            SPI0DAT = letters[0+(temp)];   \
            SPI0DAT = numbers[ 40+(temp)]; \
            SPI0DAT = numbers[ 72+(temp)]; \
            SPI0DAT = numbers[ 8+(temp)]; \
            delay(1);                      \
            SPI0DAT = numbers[ 56+(temp)]; \
		}

#endif