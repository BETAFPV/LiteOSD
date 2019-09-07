#include "show.h"
#include "ascii.h"


unsigned char  temp = 0;
extern unsigned short line;
extern unsigned char  VOT_value[3];   
extern unsigned char  min_text[2];
extern unsigned char  sec_text[2];
extern unsigned char  minute;
extern unsigned char  second;
extern unsigned char  flymode;
extern unsigned char  proto;
extern unsigned char  index;
extern unsigned char  lock;
extern unsigned char  m1;
extern unsigned char  m2;
extern unsigned char  m3;
extern unsigned char  m4;
extern unsigned char  kp[9];
extern unsigned char  ki[9];
extern unsigned char  kd[9];
extern unsigned char  showcase;
extern unsigned char  pry[4];
extern unsigned char  chn[4];
extern unsigned char  turtle;
extern unsigned char  map;
extern unsigned char  vtx_power;
extern unsigned char  channel;
extern unsigned char freq;

//roughly delay func
void delay(unsigned char n)
{
	unsigned char i;
	for(i=0;i<n;i++);
}

void flight_window(unsigned short line)
{
		if(show_centerline)
		{
				temp = line - 126;
				delay(90);
				SPI0DAT =numbers[80+(temp)];
				SPI0DAT =numbers[112+(temp)];
				SPI0DAT =numbers[80+(temp)];
		}

		if(show_lockline)
		{
				temp = line - 161;
				if(lock == 0)
				{
						delay(70);
						SPI0DAT = letters[_d+(temp)];
						SPI0DAT = letters[_i+(temp)];
						SPI0DAT = letters[_s+(temp)];
						SPI0DAT = letters[_a+(temp)];
						SPI0DAT = letters[_r+(temp)];
						SPI0DAT = letters[ _m+(temp)];
						delay(1);
						SPI0DAT = letters[ _i+(temp)];
						delay(1);
						SPI0DAT = letters[_n+(temp)];
						delay(1);
						SPI0DAT = letters[ _g+(temp)];
						delay(1);
				}
		}

		if(show_turtleline)
		{
			temp = line - 181;
			if(turtle && !lock)
			{
					delay(72);
					SPI0DAT = letters[_t+(temp)];
					SPI0DAT = letters[_u+(temp)];
					SPI0DAT = letters[_r+(temp)];
					SPI0DAT = letters[_t+(temp)];
					SPI0DAT = letters[_l+(temp)];
					SPI0DAT = letters[ _e+(temp)];
					delay(1);
			}
		}

		if(show_modeline)
		{
				temp = line - 211;
				switch (proto)
				{
					case 0:
					case 1:
						delay(4);
						SPI0DAT =letters[_b+(temp)];
						SPI0DAT =letters[_a+(temp)];
						SPI0DAT =letters[_y+(temp)];
						SPI0DAT =letters[_a+(temp)];
						SPI0DAT =letters[_n+(temp)];
						SPI0DAT =letters[_g+(temp)];
						break;
					case 2:
						delay(4);
						SPI0DAT =letters[_s+(temp)];
						SPI0DAT =letters[_b+(temp)];
						SPI0DAT =letters[_u+(temp)];
						SPI0DAT =letters[_s+(temp)];
						delay(2);
						break;
					case 3:
						delay(4);
						SPI0DAT =letters[_d+(temp)];
						SPI0DAT =letters[_s+(temp)];
						SPI0DAT =letters[_m+(temp)];
						SPI0DAT =letters[_x+(temp)];
						delay(2);
						break;
					default:
						break;
				}
				switch (flymode)
				{
					case 0:
						delay(130);
						SPI0DAT =letters[_l+(temp)];
						SPI0DAT =letters[_e+(temp)];
						SPI0DAT =letters[_v+(temp)];
						SPI0DAT =letters[_e+(temp)];
						SPI0DAT =letters[_l+(temp)];
						break;
					case 1:
						delay(130);
						SPI0DAT =letters[_a+(temp)];
						SPI0DAT =letters[_c+(temp)];
						SPI0DAT =letters[_r+(temp)];
						SPI0DAT =letters[_o+(temp)];
						break;
					case 2:
						delay(130);
						SPI0DAT =letters[_r+(temp)];
						SPI0DAT =letters[_a+(temp)];
						SPI0DAT =letters[_c+(temp)];
						SPI0DAT =letters[_e+(temp)];
						delay(1);
						SPI0DAT =numbers[144+(temp)];
						SPI0DAT =letters[_h+(temp)];
						break;
					case 3:
						delay(130);
						SPI0DAT =letters[_r+(temp)];
						SPI0DAT =letters[_a+(temp)];
						SPI0DAT =letters[_c+(temp)];
						SPI0DAT =letters[_e+(temp)];
						delay(1);
						SPI0DAT =numbers[144+(temp)];
						SPI0DAT =letters[_a+(temp)];
						break;
					case 4:
						delay(130);
						SPI0DAT =letters[_h+(temp)];
						SPI0DAT =letters[_o+(temp)];
						SPI0DAT =letters[_r+(temp)];
						SPI0DAT =letters[_i+(temp)];
						SPI0DAT =letters[_z+(temp)];
						delay(1);
						SPI0DAT =letters[_o+(temp)];
						SPI0DAT =letters[_n+(temp)];
						delay(1);
						break;
					default:
						break;
				}
		}
		if(show_timeline)
		{
				temp = line - 221;
				delay(7);
				SPI0DAT =letters[ _v+(temp)];
				SPI0DAT =letters[_o+(temp)];
				SPI0DAT =letters[_l+(temp)];

				delay(130);
				SPI0DAT =letters[_t+(temp)];
				SPI0DAT =letters[_i+(temp)];
				SPI0DAT =letters[_m+(temp)];
				SPI0DAT =letters[_e+(temp)];
		}
		if(show_time_valueline)
		{
						temp = line - 231;
						delay(4);
						SPI0DAT =numbers[VOT_value[0]+(temp)];
						SPI0DAT =numbers[88+(temp)];
						SPI0DAT =numbers[VOT_value[1]+(temp)];
						SPI0DAT =numbers[VOT_value[2]+(temp)];

						delay(130);
						SPI0DAT =numbers[ min_text[0]+(temp)];
						SPI0DAT =numbers[ min_text[1]+(temp)];
						SPI0DAT =numbers[104+(temp)];
						SPI0DAT =numbers[ sec_text[0]+(temp)];
						SPI0DAT =numbers[ sec_text[1]+(temp)];

		}
}

void set_window(unsigned short line)
{
	switch (line)
	{
		case 71:
		case 72:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
			temp = line - 71;
			delay(30);
			SPI0DAT = numbers[80+(temp)];
			SPI0DAT = letters[_m+(temp)];
			SPI0DAT = letters[_e+(temp)];
			SPI0DAT = letters[_m+(temp)];
			SPI0DAT = letters[_u+(temp)];
			delay(1);
			SPI0DAT = numbers[80+(temp)];
			break;

		case 91:
		case 92:
		case 93:
		case 94:
		case 95:
		case 96:
		case 97:
		case 98:
			temp = line - 91;
			if (index == 0){
				delay(36);
				SPI0DAT = numbers[ 96+(temp)];

			}else{
				delay(38);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_p+(temp)];
			SPI0DAT = letters[_i+(temp)];
			SPI0DAT = letters[_d+(temp)];
			delay(50);
			SPI0DAT = numbers[ 96+(temp)];
			break;

		case 106:
		case 107:
		case 108:
		case 109:
		case 110:
		case 111:
		case 112:
		case 113:
			temp = line - 106;
			if (index == 1){
				delay(35);
				SPI0DAT = numbers[ 96+(temp)];
			}else{
				delay(37);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_m+(temp)];
			SPI0DAT = letters[_o+(temp)];
			SPI0DAT = letters[_t+(temp)];
			SPI0DAT = letters[_o+(temp)];
			SPI0DAT = letters[_r+(temp)];
			delay(49);
			SPI0DAT = numbers[ 96+(temp)];
			break;

		case 121:
		case 122:
		case 123:
		case 124:
		case 125:
		case 126:
		case 127:
		case 128:
			temp = line - 121;
			if (index == 2)
			{
					delay(34);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(36);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_r+(temp)];
			SPI0DAT = letters[_e+(temp)];
			SPI0DAT = letters[_c+(temp)];
			SPI0DAT = letters[_e+(temp)];
			delay(1);
			SPI0DAT = letters[_i+(temp)];
			SPI0DAT = letters[_v+(temp)];
			delay(1);
			SPI0DAT = letters[_e+(temp)];
			delay(1);
			SPI0DAT = letters[_r+(temp)];
			delay(35);
			SPI0DAT = numbers[ 96+(temp)];
			break;
		case 136:
		case 137:
		case 138:
		case 139:
		case 140:
		case 141:
		case 142:
		case 143:
			temp = line - 136;
			if (index == 3)
			{
					delay(33);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(35);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_s+(temp)];
			SPI0DAT = letters[_m+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_r+(temp)];
			delay(1);
			SPI0DAT = letters[_t+(temp)];
			SPI0DAT = letters[_a+(temp)];
			delay(1);
			SPI0DAT = letters[_u+(temp)];
			SPI0DAT = letters[_d+(temp)];
			delay(1);
			SPI0DAT = letters[_i+(temp)];
			delay(1);
			SPI0DAT = letters[_o+(temp)];
			delay(29);
			SPI0DAT = numbers[ 96+(temp)];
			break;

		case 151:
		case 152:
		case 153:
		case 154:
		case 155:
		case 156:
		case 157:
		case 158:
			temp = line - 151;
			if (index == 4)
			{
					delay(32);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(34);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_s+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_v+(temp)];
			SPI0DAT = letters[_e+(temp)];
			break;
		case 166:
		case 167:
		case 168:
		case 169:
		case 170:
		case 171:
		case 172:
		case 173:
			temp = line - 166;
			if (index == 4)
			{
					delay(32);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(34);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_b+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_c+(temp)];
			SPI0DAT = letters[_k+(temp)];
			break;
		default:
			break;
	}
}


void pid_window(unsigned short line)
{
		switch (line)
		{
			case 71:
			case 72:
			case 73:
			case 74:
		  case 75:
			case 76:
			case 77:
			case 78:
				temp = line - 71;
				delay(30);
				SPI0DAT = numbers[80+(temp)];
				SPI0DAT = letters[_p+(temp)];
				SPI0DAT = letters[_i+(temp)];
				SPI0DAT = letters[_d+(temp)];
				SPI0DAT = numbers[80+(temp)];
				break;

			case 81:
			case 82:
			case 83:
			case 84:
		  case 85:
			case 86:
			case 87:
			case 88:
				temp = line - 81;
				delay(75);
				SPI0DAT = letters[_r+(temp)];
				delay(15);
				SPI0DAT = letters[_p+(temp)];
				delay(15);
				SPI0DAT = letters[_y+(temp)];
				break;

			case 101:
			case 102:
			case 103:
			case 104:
		  case 105:
			case 106:
			case 107:
			case 108:
				temp = line - 101;
				if (index == 0 | index == 1 | index == 2)
				{
						delay(40);
						SPI0DAT = numbers[ 96+(temp)];

				}
				else
				{
						delay(42);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_k+(temp)];
				SPI0DAT = letters[_p+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = numbers[kp[0]+(temp)];
				SPI0DAT = numbers[88+(temp)];
				delay(1);
				SPI0DAT = numbers[kp[1]+(temp)];
				delay(1);
				SPI0DAT = numbers[kp[2]+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];

				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = numbers[kp[3]+(temp)];
				delay(1);
				SPI0DAT = numbers[88+(temp)];
				delay(1);
				SPI0DAT = numbers[kp[4]+(temp)];
				SPI0DAT = numbers[kp[5]+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = numbers[kp[6]+(temp)];
				delay(1);
				SPI0DAT = numbers[88+(temp)];
				delay(1);
				SPI0DAT = numbers[kp[7]+(temp)];
				delay(1);
				SPI0DAT = numbers[kp[8]+(temp)];
				delay(1);
				break;

			case 111:
			case 112:
			case 113:
			case 114:
		  case 115:
			case 116:
			case 117:
			case 118:
				temp = line - 111;
				if ( index == 0)
				{
						delay(70);
						SPI0DAT = numbers[ 120+(temp)];
				}
				if ( index == 1)
				{
						delay(90);
						SPI0DAT = numbers[ 120+(temp)];
				}
				if ( index == 2)
				{
						delay(110);
						SPI0DAT = numbers[ 120+(temp)];
				}
				break;

			case 131:
			case 132:
			case 133:
			case 134:
		  case 135:
			case 136:
			case 137:
			case 138:
				temp = line - 131;
				if (index == 3 | index == 4 | index == 5)
				{
						delay(36);
						SPI0DAT = numbers[ 96+(temp)];
				}
				else
				{
						delay(40);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_k+(temp)];
				SPI0DAT = letters[_i+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = numbers[ki[0]+(temp)];
				delay(1);
				SPI0DAT = numbers[88+(temp)];
				delay(1);
				SPI0DAT = numbers[ki[1]+(temp)];
				delay(1);
				SPI0DAT = numbers[ki[2]+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = numbers[ki[3]+(temp)];
				delay(1);
				SPI0DAT = numbers[88+(temp)];
				delay(1);
				SPI0DAT = numbers[ki[4]+(temp)];
				delay(1);
				SPI0DAT = numbers[ki[5]+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = numbers[ki[6]+(temp)];
				delay(1);
				SPI0DAT = numbers[88+(temp)];
				delay(1);
				SPI0DAT = numbers[ki[7]+(temp)];
				delay(1);
				SPI0DAT = numbers[ki[8]+(temp)];
				break;

			case 141:
			case 142:
			case 143:
			case 144:
		  case 145:
			case 146:
			case 147:
			case 148:
				temp = line - 141;
				if ( index == 3)
				{
						delay(65);
						SPI0DAT = numbers[ 120+(temp)];
				}
				if ( index == 4)
				{
						delay(88);
						SPI0DAT = numbers[ 120+(temp)];
				}
				if ( index == 5)
				{
						delay(108);
						SPI0DAT = numbers[ 120+(temp)];
				}
				break;

			case 161:
			case 162:
			case 163:
			case 164:
		  case 165:
			case 166:
			case 167:
			case 168:
				temp = line - 161;
				if (index == 6 | index == 7 | index == 8)
				{
						delay(35);
						SPI0DAT = numbers[ 96+(temp)];
				}
				else
				{
						delay(39);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_k+(temp)];
				SPI0DAT = letters[_d+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = numbers[kd[0]+(temp)];
				delay(1);
				SPI0DAT = numbers[88+(temp)];
				delay(1);
				SPI0DAT = numbers[kd[1]+(temp)];
				delay(1);
				SPI0DAT = numbers[kd[2]+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = numbers[kd[3]+(temp)];
				delay(1);
				SPI0DAT = numbers[88+(temp)];
				delay(1);
				SPI0DAT = numbers[kd[4]+(temp)];
				delay(1);
				SPI0DAT = numbers[kd[5]+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = numbers[kd[6]+(temp)];
				delay(1);
				SPI0DAT = numbers[88+(temp)];
				delay(1);
				SPI0DAT = numbers[kd[7]+(temp)];
				delay(1);
				SPI0DAT = numbers[kd[8]+(temp)];
				break;

			case 171:
			case 172:
			case 173:
			case 174:
		  case 175:
			case 176:
			case 177:
			case 178:
				temp = line - 171;
				if ( index == 6)
				{
						delay(65);
						SPI0DAT = numbers[ 120+(temp)];
				}
				if ( index == 7)
				{
						delay(85);
						SPI0DAT = numbers[ 120+(temp)];
				}
				if ( index == 8)
				{
						delay(108);
						SPI0DAT = numbers[ 120+(temp)];
				}
				break;

			case 191:
			case 192:
			case 193:
			case 194:
		  case 195:
			case 196:
			case 197:
			case 198:
				temp = line - 191;
				if (index == 9)
				{
						delay(37);
						SPI0DAT = numbers[ 96+(temp)];
				}
				else
				{
						delay(39);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_e+(temp)];
				SPI0DAT = letters[_x+(temp)];
				SPI0DAT = letters[_i+(temp)];
				SPI0DAT = letters[_t+(temp)];
				break;
			default:
				break;
		}
}




void motor_window(unsigned short line)
{
		if(show_motor_menuline)
		{
				temp = line - 81;
				delay(30);
				SPI0DAT = numbers[80+(temp)];
				SPI0DAT = letters[_m+(temp)];
				SPI0DAT = letters[_o+(temp)];
				SPI0DAT = letters[_t+(temp)];
				SPI0DAT = letters[_o+(temp)];
				SPI0DAT = letters[_r+(temp)];
				delay(1);
				SPI0DAT = numbers[80+(temp)];
		}

		if(show_m1line)
		{
				temp = line - 101;
				if (index == 0)
				{
						delay(42);
						SPI0DAT = numbers[ 96+(temp)];
				}
				else
				{
						delay(45);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_m+(temp)];
				SPI0DAT = numbers[ 8+(temp)];
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ (m1?_n:_r)+(temp)];
		}
		if(show_m2line)
		{
				temp = line - 116;
				if (index == 1)
				{
						delay(39);
						SPI0DAT = numbers[ 96+(temp)];
				}
				else
				{
						delay(43);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_m+(temp)];
				SPI0DAT = numbers[ 16+(temp)];
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ (m2?_n:_r)+(temp)];
		}

		if(show_m3line)
		{
				temp = line - 131;
				if (index == 2)
				{
						delay(38);
						SPI0DAT = numbers[ 96+(temp)];
				}
				else
				{
						delay(41);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_m+(temp)];
				SPI0DAT = numbers[ 24+(temp)];
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ (m3?_n:_r)+(temp)];
		}

		if(show_m4line)
		{
				temp = line - 146;
				if (index == 3)
				{
						delay(35);
						SPI0DAT = numbers[ 96+(temp)];
				}
				else
				{
						delay(39);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_m+(temp)];
				SPI0DAT = numbers[ 32+(temp)];
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ (m4?_n:_r)+(temp)];
		}
		if(show_motor_exitline)
		{
				temp = line - 166;
				if (index == 4)
				{
						delay(36);
						SPI0DAT = numbers[ 96+(temp)];
				}
				else
				{
						delay(38);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_b+(temp)];
				SPI0DAT = letters[_a+(temp)];
				SPI0DAT = letters[_c+(temp)];
				SPI0DAT = letters[_k+(temp)];
		}
}

void receiver_window(unsigned short line)
{
	switch (line)
	{
		case 71:
		case 72:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
			temp = line - 71;
			delay(30);
			SPI0DAT = numbers[80+(temp)];
			SPI0DAT = letters[_r+(temp)];
			SPI0DAT = letters[_e+(temp)];
			SPI0DAT = letters[_c+(temp)];
			SPI0DAT = letters[_e+(temp)];
			delay(1);
			SPI0DAT = letters[_i+(temp)];
			SPI0DAT = letters[_v+(temp)];
			delay(1);
			SPI0DAT = letters[_e+(temp)];
			delay(1);
			SPI0DAT = letters[_r+(temp)];
			delay(1);
			SPI0DAT = numbers[80+(temp)];
			break;

		case 91:
		case 92:
		case 93:
		case 94:
		case 95:
		case 96:
		case 97:
		case 98:
			temp = line - 91;
			if (index == 0)
			{
					delay(36);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(38);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_m+(temp)];
			SPI0DAT = letters[_a+(temp)];
			delay(1);
			SPI0DAT = letters[_p+(temp)];
			delay(1);
			SPI0DAT =numbers[104+(temp)];
			delay(20);
			if(!map)
			{
				SPI0DAT = letters[_a+(temp)];
				SPI0DAT = letters[_e+(temp)];
				SPI0DAT = letters[_t+(temp)];
				SPI0DAT = letters[_r+(temp)];
			}
			else
			{
				SPI0DAT = letters[_t+(temp)];
				SPI0DAT = letters[_a+(temp)];
				SPI0DAT = letters[_e+(temp)];
				SPI0DAT = letters[_r+(temp)];
			}
			break;

		case 106:
		case 107:
		case 108:
		case 109:
		case 110:
		case 111:
		case 112:
		case 113:
			temp = line - 106;
			if (index == 1)
			{
					delay(36);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(38);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_b+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_c+(temp)];
			SPI0DAT = letters[_k+(temp)];
		break;

		case 146:
		case 147:
		case 148:
		case 149:
		case 150:
		case 151:
		case 152:
		case 153:
			temp = line - 146;
			delay(42);
			SPI0DAT = letters[_r+(temp)];
			SPI0DAT = letters[_o+(temp)];
			SPI0DAT = letters[_l+(temp)];
			SPI0DAT = numbers[ 104+(temp)];
			switch (pry[0])
			{
				case 0x0:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					break;
				case 0x1:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					break;
				case 0x2:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					delay(2);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					delay(1);
					SPI0DAT = numbers[ 128+(temp)];
					break;
				default:
					break;
			}
			break;

		case 161:
		case 162:
		case 163:
		case 164:
		case 165:
		case 166:
		case 167:
		case 168:
			temp = line - 161;
			delay(41);
			SPI0DAT = letters[_p+(temp)];
			SPI0DAT = letters[_i+(temp)];
			SPI0DAT = letters[_t+(temp)];
			SPI0DAT = numbers[ 104+(temp)];
			switch (pry[1])
			{
				case 0x0:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					break;
				case 0x1:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					break;
				case 0x2:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					delay(2);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					delay(1);
					SPI0DAT = numbers[ 128+(temp)];
					break;
				default:
					break;
			}
			break;
		case 176:
		case 177:
		case 178:
		case 179:
		case 180:
		case 181:
		case 182:
		case 183:
			temp = line - 176;
			delay(40);
			SPI0DAT = letters[_y+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_w+(temp)];
			SPI0DAT = numbers[ 104+(temp)];
			switch (pry[2])
			{
				case 0x0:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					break;
				case 0x1:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					break;
				case 0x2:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					delay(2);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					delay(1);
					SPI0DAT = numbers[ 128+(temp)];
					break;
				default:
					break;
			}
			break;

		case 191:
		case 192:
		case 193:
		case 194:
		case 195:
		case 196:
		case 197:
		case 198:
			temp = line - 191;
			delay(39);
			SPI0DAT = letters[_t+(temp)];
			SPI0DAT = letters[_r+(temp)];
			SPI0DAT = letters[_o+(temp)];
			SPI0DAT = numbers[ 104+(temp)];
			switch (pry[3])
			{
				case 0x0:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					break;
				case 0x1:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					break;
				case 0x2:
					delay(15);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					delay(2);
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					SPI0DAT = numbers[ 128+(temp)];
					delay(1);
					SPI0DAT = numbers[ 128+(temp)];
					break;
				default:
					break;
			}
			break;

		case 211:
		case 212:
		case 213:
		case 214:
		case 215:
		case 216:
		case 217:
		case 218:
			temp = line - 211;
			delay(38);
			SPI0DAT = letters[_c+(temp)];
			SPI0DAT = letters[_h+(temp)];
			SPI0DAT = letters[_n+(temp)];
			SPI0DAT = numbers[ 40+(temp)];
			SPI0DAT =numbers[80+(temp)];
			SPI0DAT = numbers[ 64+(temp)];
			delay(1);
			SPI0DAT = numbers[ 104+(temp)];
			delay(1);
			if(chn[0])
			{
					delay(15);
					SPI0DAT = numbers[ 8+(temp)];
			}
			else
			{
					delay(15);
					SPI0DAT = numbers[ 0+(temp)];
			}
			delay(4);
			SPI0DAT = numbers[ 104+(temp)];
			if(chn[1])
			{
					delay(4);
					SPI0DAT = numbers[ 8+(temp)];
			}
			else
			{
					delay(4);
					SPI0DAT = numbers[ 0+(temp)];
			}
			delay(4);
			SPI0DAT = numbers[ 104+(temp)];
			if(chn[2])
			{
					delay(4);
					SPI0DAT = numbers[ 8+(temp)];
			}
			else
			{
					delay(4);
					SPI0DAT = numbers[ 0+(temp)];
			}
			delay(4);
			SPI0DAT = numbers[ 104+(temp)];
			if(chn[3])
			{
					delay(4);
					SPI0DAT = numbers[ 8+(temp)];
			}
			else
			{
					delay(4);
					SPI0DAT = numbers[ 0+(temp)];
			}
			break;
		}
}
void sa_window(unsigned short line)
{
	switch (line)
	{
		case 71:
		case 72:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
			temp = line - 71;
			delay(30);
			SPI0DAT = numbers[80+(temp)];
			SPI0DAT = letters[_s+(temp)];
			SPI0DAT = letters[_m+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_r+(temp)];
			delay(1);
			SPI0DAT = letters[_t+(temp)];
			SPI0DAT = letters[_a+(temp)];
			delay(1);
			SPI0DAT = letters[_u+(temp)];
			SPI0DAT = letters[_d+(temp)];
			delay(1);
			SPI0DAT = letters[_i+(temp)];
			delay(1);
			SPI0DAT = letters[_o+(temp)];
			delay(1);
			SPI0DAT = numbers[80+(temp)];
			break;
		
		case 91:
		case 92:
		case 93:
		case 94:
		case 95:
		case 96:
		case 97:
		case 98:
			temp = line - 91;
			delay(45);
			C_A_1
			delay(8);
			A_1
			delay(20);
			P_1
			break;

		case 111:
		case 112:
		case 113:
		case 114:
		case 115:
		case 116:
		case 117:
		case 118:
			temp = line - 111;
			if (index == 0){
				delay(34);
				SPI0DAT = numbers[ 96+(temp)];

			}else{
				delay(38);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_c+(temp)];
			SPI0DAT = letters[_h+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_n+(temp)];
			delay(50);
			C_A_1
			break;

		case 126:
		case 127:
		case 128:
		case 129:
		case 130:
		case 131:
		case 132:
		case 133:
			temp = line - 126;
			if (index == 1){
				delay(35);
				SPI0DAT = numbers[ 96+(temp)];
			}else{
				delay(37);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_f+(temp)];
			SPI0DAT = letters[_r+(temp)];
			SPI0DAT = letters[_e+(temp)];
			SPI0DAT = letters[_q+(temp)];
			delay(47);
			A_1
			break;

		case 141:
		case 142:
		case 143:
		case 144:
		case 145:
		case 146:
		case 147:
		case 148:
			temp = line - 141;
			if (index == 2)
			{
					delay(34);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(36);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_p+(temp)];
			SPI0DAT = letters[_o+(temp)];
			SPI0DAT = letters[_w+(temp)];
			SPI0DAT = letters[_e+(temp)];
			delay(1);
			SPI0DAT = letters[_r+(temp)];
			delay(44);
			P_1
			break;
		case 156:
		case 157:
		case 158:
		case 159:
		case 160:
		case 161:
		case 162:
		case 163:
			temp = line - 156;
			if (index == 3)
			{
					delay(33);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(35);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_s+(temp)];
			SPI0DAT = letters[_e+(temp)];
			SPI0DAT = letters[_t+(temp)];
			break;
		case 171:
		case 172:
		case 173:
		case 174:
		case 175:
		case 176:
		case 177:
		case 178:
			temp = line - 171;
			if (index == 4)
			{
					delay(33);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(35);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_b+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_c+(temp)];
			SPI0DAT = letters[_k+(temp)];
			break;
		default:
			break;
	}
	
}
