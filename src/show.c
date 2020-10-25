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
extern unsigned char  vtx_power;
extern unsigned char  channel;
extern unsigned char  mode;
extern unsigned char  vtx_power_index;
extern unsigned char  channel_index;
extern unsigned char  mode_index;
extern unsigned char main_version;
extern unsigned char modify_version;
extern unsigned char low_line_l;
extern unsigned char low_line_h;

extern unsigned short low_bat_l;
extern unsigned short mode_l;
extern unsigned short vol_l;
extern unsigned short turtle_l;

extern unsigned char low_bat_l_temp[2];
extern unsigned char mode_l_temp[2];
extern unsigned char vol_l_temp[2];
extern unsigned char turtle_l_temp[2];
extern unsigned char low_battery[2];

extern unsigned char   rx0[3];
extern unsigned char   rx1[3];
extern unsigned char   rx2[3];
extern unsigned char   rx3[3];

extern unsigned char rate[4];
extern unsigned char rate_yaw[4];
extern unsigned char profileAB;

void switch_channel(unsigned char index)
{
    switch(index)
    {
        case 0:
            A_1
            break;
        case 1:
            A_2
            break;
        case 2:
            A_3
            break;
        case 3:
            A_4
            break;
        case 4:
            A_5
            break;
        case 5:
            A_6
            break;
        case 6:
            A_7
            break;
        case 7:
            A_8
            break;
        case 8:
            B_1
            break;
        case 9:
            B_2
            break;
        case 10:
            B_3
            break;
        case 11:
            B_4
            break;
        case 12:
            B_5
            break;
        case 13:
            B_6
            break;
        case 14:
            B_7
            break;
        case 15:
            B_8
            break;
        case 16:
            E_1
            break;
        case 17:
            E_2
            break;
        case 18:
            E_3
            break;
        case 19:
            E_4
            break;
        case 20:
            E_5
            break;
        case 21:
            E_6
            break;
        case 22:
            E_7
            break;
        case 23:
            E_8
            break;
        case 24:
            Air_1
            break;
        case 25:
            Air_2
            break;
        case 26:
            Air_3
            break;
        case 27:
            Air_4
            break;
        case 28:
            Air_5
            break;
        case 29:
            Air_6
            break;
        case 30:
            Air_7
            break;
        case 31:
            Air_8
            break;
        case 32:
            Race_1
            break;
        case 33:
            Race_2
            break;
        case 34:
            Race_3
            break;
        case 35:
            Race_4
            break;
        case 36:
            Race_5
            break;
        case 37:
            Race_6
            break;
        case 38:
            Race_7
            break;
        case 39:
            Race_8
            break;
        default:
            break;
    }
}
void switch_power(unsigned char index)
{
    switch(index)
    {
        case 0:
            P_1
            break;
        case 1:
            P_2
            break;
        default:
            break;
    }
}


void delay(unsigned char n)
{
	unsigned char i;
	for(i=0;i<n;i++);
}


void init_window(unsigned short line)
{
     if(show_centerline)
    {
        temp = line - 120;
        delay(45);
        SPI0DAT = ULetters[0+(temp)];
        SPI0DAT = ULetters[16+(temp)];
        SPI0DAT = ULetters[32+(temp)];
        SPI0DAT = ULetters[48+(temp)];
        
        SPI0DAT = ULetters[64+(temp)];
        delay(6);
        SPI0DAT = ULetters[80+(temp)];
        delay(9);
        SPI0DAT = PLetters[16+(temp)];
        delay(10);
        SPI0DAT = PLetters[0+(temp)];
        delay(9);
        SPI0DAT = ULetters[80+(temp)];
        delay(10);
        SPI0DAT = ULetters[64+(temp)];
    }
    if(show_betafpvline)
    {
        temp = line - 160;
        delay(56);
        SPI0DAT = letters[_b+(temp)];
        SPI0DAT = letters[_e+(temp)];
        delay(2);
        SPI0DAT = letters[_t+(temp)];
        delay(3);
        SPI0DAT = letters[_a+(temp)];
        delay(3);
        SPI0DAT = letters[_f+(temp)];
        delay(3);
        SPI0DAT = letters[ _p+(temp)];
        delay(2);
        SPI0DAT = letters[ _v+(temp)];
    }
    
}

void flight_window(unsigned short line)
{
    if(low_bat_l<line && line<low_bat_l+9)
    {
        temp = line - low_bat_l;
        if((VOT_value[0]<=low_battery[0] && VOT_value[1]< low_battery[1]) || VOT_value[0]<low_battery[0])
        {
            delay(65);
            SPI0DAT = letters[_l+(temp)];
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_w+(temp)];
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[_v+(temp)];
            SPI0DAT = letters[_o+(temp)];
            delay(1);
            SPI0DAT = letters[ _l+(temp)];
            delay(1);
            SPI0DAT = letters[ _t+(temp)];
            delay(1);
            SPI0DAT = letters[_a+(temp)];
            delay(1);
            SPI0DAT = letters[ _g+(temp)];
            delay(1);
            SPI0DAT = letters[ _e+(temp)];
        }
        else if(lock == 0)
        {
            delay(65);
            SPI0DAT = letters[_d+(temp)];
            SPI0DAT = letters[_i+(temp)];
            SPI0DAT = letters[_s+(temp)];
            SPI0DAT = letters[_a+(temp)];
            SPI0DAT = letters[_r+(temp)];
            delay(1);
            SPI0DAT = letters[ _m+(temp)];
            delay(3);
            SPI0DAT = letters[ _i+(temp)];
            delay(5);
            SPI0DAT = letters[_n+(temp)];
            delay(4);
            SPI0DAT = letters[ _g+(temp)];
            delay(2);
        }
    }
//    if(turtle_l<line && line<turtle_l+9)
//    {
//        temp = line - turtle_l;
//        if(turtle && !lock)
//        {
//            delay(120);
//            SPI0DAT = letters[_t+(temp)];
//            SPI0DAT = letters[_u+(temp)];
//            SPI0DAT = letters[_r+(temp)];
//            SPI0DAT = letters[_t+(temp)];
//            SPI0DAT = letters[_l+(temp)];
//            delay(2);
//            SPI0DAT = letters[ _e+(temp)];
//            delay(1);
//        }
//    }

    if(mode_l<line && line<mode_l+9)
    {
        temp = line - mode_l;
        switch (proto)
        {
            case 0:
            case 1:
                delay(5);
                SPI0DAT =letters[_b+(temp)];
                SPI0DAT =letters[_a+(temp)];
                SPI0DAT =letters[_y+(temp)];
                SPI0DAT =letters[_a+(temp)];
                delay(1);
                SPI0DAT =letters[_n+(temp)];
                delay(3);
                SPI0DAT =letters[_g+(temp)];
                delay(4);
                break;
            case 2:
                delay(5);
                SPI0DAT =letters[_s+(temp)];
                SPI0DAT =letters[_b+(temp)];
                SPI0DAT =letters[_u+(temp)];
                SPI0DAT =letters[_s+(temp)];
                delay(2);
                break;
            case 3:
                delay(5);
                SPI0DAT =letters[_d+(temp)];
                SPI0DAT =letters[_s+(temp)];
                SPI0DAT =letters[_m+(temp)];
                SPI0DAT =letters[_x+(temp)];
                delay(2);
                break;
            case 5:
                delay(5);
                SPI0DAT =letters[_i+(temp)];
                SPI0DAT =letters[_b+(temp)];
                SPI0DAT =letters[_u+(temp)];
                SPI0DAT =letters[_s+(temp)];
                delay(2);
                break;		
        }
        switch (flymode)
        {
            case 0:
                delay(110);
                SPI0DAT =letters[_l+(temp)];
                SPI0DAT =letters[_e+(temp)];
                SPI0DAT =letters[_v+(temp)];
                SPI0DAT =letters[_e+(temp)];
                SPI0DAT =letters[_l+(temp)];
                break;
            case 1:
                delay(112);
                SPI0DAT =letters[_a+(temp)];
                SPI0DAT =letters[_c+(temp)];
                SPI0DAT =letters[_r+(temp)];
                SPI0DAT =letters[_o+(temp)];
                break;
            case 2:
                delay(110);
                SPI0DAT =letters[_r+(temp)];
                SPI0DAT =letters[_a+(temp)];
                SPI0DAT =letters[_c+(temp)];
                SPI0DAT =letters[_e+(temp)];
                delay(1);
                SPI0DAT =numbers[144+(temp)];
                SPI0DAT =letters[_h+(temp)];
                break;
            case 3:
                delay(110);
                SPI0DAT =letters[_r+(temp)];
                SPI0DAT =letters[_a+(temp)];
                SPI0DAT =letters[_c+(temp)];
                SPI0DAT =letters[_e+(temp)];
                delay(1);
                SPI0DAT =numbers[144+(temp)];
                SPI0DAT =letters[_a+(temp)];
                break;
            case 4:
                delay(110);
                SPI0DAT =letters[_h+(temp)];
                SPI0DAT =letters[_o+(temp)];
                SPI0DAT =letters[_r+(temp)];
                SPI0DAT =letters[_i+(temp)];
                SPI0DAT =letters[_z+(temp)];
                delay(1);
                SPI0DAT =letters[_o+(temp)];
                delay(3);
                SPI0DAT =letters[_n+(temp)];
                delay(1);
                break;
        }
        
    }
    if(vol_l<line && line<vol_l+9)
    {
        temp = line - vol_l;
        delay(5);
        SPI0DAT =letters[ _v+(temp)];
        SPI0DAT =numbers[VOT_value[0]+(temp)];
        SPI0DAT =numbers[88+(temp)];
        SPI0DAT =numbers[VOT_value[1]+(temp)];
        SPI0DAT =numbers[VOT_value[2]+(temp)];
        
        delay(125);
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
            delay(50);
            SPI0DAT = letters[_l+(temp)];
            SPI0DAT = letters[ _i+(temp)];
            SPI0DAT = letters[ _t+(temp)];
            SPI0DAT = letters[ _e+(temp)];
            SPI0DAT = letters[ 0+(temp)];
            SPI0DAT = numbers[8+(temp)];
            delay(1);
            SPI0DAT = letters[ _s+(temp)];
            delay(1);
            SPI0DAT = letters[ 0+(temp)];
            delay(1);
            SPI0DAT = letters[ _b+(temp)];
            delay(1);
            SPI0DAT = letters[ _h+(temp)];
            delay(1);
            SPI0DAT = letters[ 0+(temp)];
            delay(1);
            SPI0DAT =letters[ _v+(temp)];
            delay(1);
            SPI0DAT =numbers[main_version+(temp)];
            delay(1);
            SPI0DAT =numbers[88+(temp)];
            delay(1);
            SPI0DAT =numbers[modify_version+(temp)];
            break;
                 
		case 96:
		case 97:
		case 98:
		case 99:
		case 100:
		case 101:
		case 102:
		case 103:
			temp = line - 96;
			delay(30);
			SPI0DAT = numbers[80+(temp)];
			SPI0DAT = letters[_m+(temp)];
			SPI0DAT = letters[_e+(temp)];
			SPI0DAT = letters[_m+(temp)];
			SPI0DAT = letters[_u+(temp)];
			delay(1);
			SPI0DAT = numbers[80+(temp)];
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
				delay(30);
				SPI0DAT = numbers[ 96+(temp)];

			}else{
				delay(38);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_p+(temp)];
			SPI0DAT = letters[_i+(temp)];
			SPI0DAT = letters[_d+(temp)];
			delay(60);
			SPI0DAT = numbers[ 96+(temp)];
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
				delay(30);
				SPI0DAT = numbers[ 96+(temp)];
			}else{
				delay(37);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_c+(temp)];
			SPI0DAT = letters[_o+(temp)];
			SPI0DAT = letters[_n+(temp)];
			SPI0DAT = letters[_f+(temp)];
            delay(1);
			SPI0DAT = letters[_i+(temp)];
            delay(1);
			SPI0DAT = letters[_g+(temp)];
			delay(50);
			SPI0DAT = numbers[ 96+(temp)];
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
					delay(29);
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
            delay(1);
			SPI0DAT = letters[_e+(temp)];
			delay(1);
			SPI0DAT = letters[_i+(temp)];
            delay(1);
			SPI0DAT = letters[_v+(temp)];
			delay(1);
			SPI0DAT = letters[_e+(temp)];
			delay(1);
			SPI0DAT = letters[_r+(temp)];
			delay(38);
			SPI0DAT = numbers[ 96+(temp)];
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
					delay(28);
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
            delay(1);
			SPI0DAT = letters[_a+(temp)];
			delay(1);
			SPI0DAT = letters[_u+(temp)];
            delay(1);
			SPI0DAT = letters[_d+(temp)];
			delay(1);
			SPI0DAT = letters[_i+(temp)];
			delay(1);
			SPI0DAT = letters[_o+(temp)];
			delay(32);
			SPI0DAT = numbers[ 96+(temp)];
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
					delay(27);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(34);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_d+(temp)];
			SPI0DAT = letters[_i+(temp)];
			SPI0DAT = letters[_s+(temp)];
			SPI0DAT = letters[_p+(temp)];
            delay(1);
            SPI0DAT = letters[_l+(temp)];
            delay(1);
			SPI0DAT = letters[_a+(temp)];
            delay(1);
			SPI0DAT = letters[_y+(temp)];
            delay(45);
			SPI0DAT = numbers[ 96+(temp)];
			break;
            
		case 186:
		case 187:
		case 188:
		case 189:
		case 190:
		case 191:
		case 192:
		case 193:
			temp = line - 186;
			if (index == 5)
			{
					delay(27);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(34);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_r+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_t+(temp)];
            delay(1);
			SPI0DAT = letters[_e+(temp)];
            delay(3);
            SPI0DAT = letters[_s+(temp)];
            delay(47);
			SPI0DAT = numbers[ 96+(temp)];
			break;
            
		case 201:
		case 202:
		case 203:
		case 204:
		case 205:
		case 206:
		case 207:
		case 208:
			temp = line - 201;
			if (index == 6)
			{
					delay(26);
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
            delay(1);
			SPI0DAT = letters[_e+(temp)];
			break;
		case 216:
		case 217:
		case 218:
		case 219:
		case 220:
		case 221:
		case 222:
		case 223:
			temp = line - 216;
			if (index == 7)
			{
					delay(26);
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
            delay(3);
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
            delay(66);
            SPI0DAT = letters[_r+(temp)];
            delay(18);
            SPI0DAT = letters[_p+(temp)];
            delay(18);
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
                    delay(30);
                    SPI0DAT = numbers[ 96+(temp)];

            }
            else
            {
                    delay(36);
            }
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[_k+(temp)];
            SPI0DAT = letters[_p+(temp)];
            SPI0DAT = letters[ 0+(temp)];
            SPI0DAT = letters[ 0+(temp)];
            SPI0DAT = numbers[kp[0]+(temp)];
            delay(1);
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
            delay(1);
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
                    delay(65);
                    SPI0DAT = numbers[ 120+(temp)];
            }
            if ( index == 1)
            {
                    delay(84);
                    SPI0DAT = numbers[ 120+(temp)];
            }
            if ( index == 2)
            {
                    delay(102);
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
                    delay(28);
                    SPI0DAT = numbers[ 96+(temp)];
            }
            else
            {
                    delay(35);
            }
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[_k+(temp)];
            SPI0DAT = letters[_i+(temp)];
            SPI0DAT = letters[ 0+(temp)];
            SPI0DAT = letters[ 0+(temp)];
            SPI0DAT = numbers[ki[0]+(temp)];
            delay(1);
            SPI0DAT = numbers[88+(temp)];
            delay(1);
            SPI0DAT = numbers[ki[1]+(temp)];
            delay(1);
            SPI0DAT = numbers[ki[2]+(temp)];
            delay(1);
            SPI0DAT = letters[ 0+(temp)];

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
                    delay(62);
                    SPI0DAT = numbers[ 120+(temp)];
            }
            if ( index == 4)
            {
                    delay(81);
                    SPI0DAT = numbers[ 120+(temp)];
            }
            if ( index == 5)
            {
                    delay(102);
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
                    delay(28);
                    SPI0DAT = numbers[ 96+(temp)];
            }
            else
            {
                    delay(33);
            }
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[_k+(temp)];
            SPI0DAT = letters[_d+(temp)];
            SPI0DAT = letters[ 0+(temp)];
            SPI0DAT = letters[ 0+(temp)];
            SPI0DAT = numbers[kd[0]+(temp)];
            delay(1);
            SPI0DAT = numbers[88+(temp)];
            delay(1);
            SPI0DAT = numbers[kd[1]+(temp)];
            delay(1);
            SPI0DAT = numbers[kd[2]+(temp)];
            delay(1);
            SPI0DAT = letters[ 0+(temp)];

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
                    delay(62);
                    SPI0DAT = numbers[ 120+(temp)];
            }
            if ( index == 7)
            {
                    delay(81);
                    SPI0DAT = numbers[ 120+(temp)];
            }
            if ( index == 8)
            {
                    delay(102);
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
                    delay(27);
                    SPI0DAT = numbers[ 96+(temp)];
            }
            else
            {
                    delay(33);
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
				SPI0DAT = letters[_c+(temp)];
				SPI0DAT = letters[_o+(temp)];
				SPI0DAT = letters[_n+(temp)];
				SPI0DAT = letters[_f+(temp)];
                delay(1);
				SPI0DAT = letters[_i+(temp)];
                delay(1);
                SPI0DAT = letters[_g+(temp)];
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
						delay(46);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_t+(temp)];
				SPI0DAT = letters[ _o+(temp)];
				SPI0DAT = letters[ _y+(temp)];
				SPI0DAT = numbers[ 144+(temp)];
				delay(1);
				SPI0DAT = letters[ _t+(temp)];
				delay(1);
				SPI0DAT = letters[ _x+(temp)];
                delay(1);
                SPI0DAT = letters[0+(temp)];
                SPI0DAT = letters[0+(temp)];
                delay(1);
				SPI0DAT = letters[ (m1?_y:_n)+(temp)];
		}
		if(show_m2line)
		{
				temp = line - 116;
				if (index == 1)
				{
						delay(40);
						SPI0DAT = numbers[ 96+(temp)];
				}
				else
				{
						delay(44);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_m+(temp)];
				SPI0DAT = letters[ _o+(temp)];
				SPI0DAT = letters[ _d+(temp)];
				delay(1);
				SPI0DAT = letters[ _e+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
                SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = numbers[ m2+(temp)];
		}

		if(show_m3line)
		{
				temp = line - 131;
				if (index == 2)
				{
						delay(39);
						SPI0DAT = numbers[ 96+(temp)];
				}
				else
				{
						delay(42);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_r+(temp)];
				SPI0DAT = letters[ _g+(temp)];
				SPI0DAT = letters[ _b+(temp)];
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ (m3?_o:_f)+(temp)];
		}

		if(show_m4line)
		{
				temp = line - 146;
				if (index == 3)
				{
						delay(37);
						SPI0DAT = numbers[ 96+(temp)];
				}
				else
				{
						delay(40);
				}
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_t+(temp)];
				SPI0DAT = numbers[ 64+(temp)];
				SPI0DAT = letters[ _s+(temp)];
				SPI0DAT = letters[ _g+(temp)];
				delay(1);
				SPI0DAT = letters[ 0+(temp)];
                SPI0DAT = letters[ 0+(temp)];
				delay(1);
				SPI0DAT = letters[ (m4?_y:_n)+(temp)];
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
						delay(40);
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
            delay(1);
			SPI0DAT = letters[_v+(temp)];
			delay(1);
			SPI0DAT = letters[_e+(temp)];
			delay(1);
			SPI0DAT = letters[_r+(temp)];
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

            delay(38);
            SPI0DAT = letters[_c+(temp)];
			SPI0DAT = letters[_h+(temp)];
			SPI0DAT = letters[_a+(temp)];
            SPI0DAT = letters[_n+(temp)];
			SPI0DAT = letters[_n+(temp)];
			SPI0DAT = letters[_e+(temp)]; 
            delay(1);        
			SPI0DAT = letters[_l+(temp)];
            delay(1);
            SPI0DAT = letters[0+(temp)];
            delay(1);
			SPI0DAT = letters[_m+(temp)];
            delay(1);
			SPI0DAT = letters[_a+(temp)];
            delay(1);
			SPI0DAT = letters[_p+(temp)];
            delay(1);
            SPI0DAT = letters[0+(temp)];
            delay(1);
            SPI0DAT = letters[_m+(temp)];
			delay(1);
			SPI0DAT = letters[_u+(temp)];
            delay(1);
            SPI0DAT = letters[_s+(temp)];
            delay(1);
			SPI0DAT = letters[_t+(temp)];
            delay(1);
            SPI0DAT = letters[0+(temp)];
            delay(1);
			SPI0DAT = letters[_i+(temp)];
            delay(1);
			SPI0DAT = letters[_n+(temp)];
            delay(1);
			SPI0DAT = letters[0+(temp)];
            delay(1);

            SPI0DAT = letters[_a+(temp)];
            delay(1);
            SPI0DAT = letters[_e+(temp)];
            delay(1);
            SPI0DAT = letters[_t+(temp)];
            delay(1);
            SPI0DAT = letters[_r+(temp)];

			break;



		case 120:
		case 121:
		case 122:
		case 123:
		case 124:
		case 125:
		case 126:
		case 127:
			temp = line - 120;
			delay(42);
			SPI0DAT = letters[_r+(temp)];
			SPI0DAT = letters[_o+(temp)];
			SPI0DAT = letters[_l+(temp)];
			SPI0DAT = numbers[ 104+(temp)];
            SPI0DAT = letters[0+(temp)];
            delay(1);
			SPI0DAT =numbers[rx0[0]+(temp)];
            delay(1);
            SPI0DAT =numbers[88+(temp)];
            delay(1);
            SPI0DAT =numbers[rx0[1]+(temp)];
            delay(1);
            SPI0DAT =numbers[rx0[2]+(temp)];
			break;

		case 135:
		case 136:
		case 137:
		case 138:
		case 139:
		case 140:
		case 141:
		case 142:
			temp = line - 135;
			delay(41);
			SPI0DAT = letters[_p+(temp)];
			SPI0DAT = letters[_i+(temp)];
			SPI0DAT = letters[_t+(temp)];
			SPI0DAT = numbers[ 104+(temp)];

            SPI0DAT = letters[0+(temp)];
            delay(1);
			SPI0DAT =numbers[rx1[0]+(temp)];
            delay(1);
            SPI0DAT =numbers[88+(temp)];
            delay(1);
            SPI0DAT =numbers[rx1[1]+(temp)];
            delay(1);
            SPI0DAT =numbers[rx1[2]+(temp)];
			break;
		case 150:
		case 151:
		case 152:
		case 153:
		case 154:
		case 155:
		case 156:
		case 157:
			temp = line - 150;
			delay(40);
			SPI0DAT = letters[_y+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_w+(temp)];
			SPI0DAT = numbers[ 104+(temp)];

            SPI0DAT = letters[0+(temp)];
            delay(1);
			SPI0DAT =numbers[rx2[0]+(temp)];
            delay(1);
            SPI0DAT =numbers[88+(temp)];
            delay(1);
            SPI0DAT =numbers[rx2[1]+(temp)];
            delay(1);
            SPI0DAT =numbers[rx2[2]+(temp)];
			break;

		case 165:
		case 166:
		case 167:
		case 168:
		case 169:
		case 170:
		case 171:
		case 172:
			temp = line - 165;
			delay(39);
			SPI0DAT = letters[_t+(temp)];
			SPI0DAT = letters[_r+(temp)];
			SPI0DAT = letters[_o+(temp)];
			SPI0DAT = numbers[ 104+(temp)];

            SPI0DAT = letters[0+(temp)];
            delay(1);
			SPI0DAT =numbers[rx3[0]+(temp)];
            delay(1);
            SPI0DAT =numbers[88+(temp)];
            delay(1);
            SPI0DAT =numbers[rx3[1]+(temp)];
            delay(1);
            SPI0DAT =numbers[rx3[2]+(temp)];
			break;

		case 185:
		case 186:
		case 187:
		case 188:
		case 189:
		case 190:
		case 191:
		case 192:
			temp = line - 185;
			delay(38);
			SPI0DAT = letters[_c+(temp)];
			SPI0DAT = letters[_h+(temp)];
			SPI0DAT = letters[_n+(temp)];
			SPI0DAT = numbers[ 40+(temp)];
			SPI0DAT =numbers[80+(temp)];
            delay(1);
			SPI0DAT = numbers[ 64+(temp)];
			delay(1);
			SPI0DAT = numbers[ 104+(temp)];
			delay(8);
			if(chn[0])
			{
					delay(4);
					SPI0DAT = numbers[ 8+(temp)];
			}
			else
			{
					delay(4);
					SPI0DAT = numbers[ 0+(temp)];
			}
			delay(6);
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
			delay(6);
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
			delay(6);
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
            
        case 206:
		case 207:
		case 208:
		case 209:
		case 210:
		case 211:
		case 212:
		case 213:
			temp = line - 206;

            delay(24);
            SPI0DAT = numbers[ 96+(temp)];

			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_b+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_c+(temp)];
            delay(1);
			SPI0DAT = letters[_k+(temp)];
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
            delay(1);
			SPI0DAT = letters[_a+(temp)];
			delay(1);
			SPI0DAT = letters[_u+(temp)];
            delay(1);
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
			delay(35);
			switch_channel(channel);
        
			delay(10);
            SPI0DAT = letters[0+(temp)];
			switch_power(vtx_power);

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
				delay(31);
				SPI0DAT = numbers[ 96+(temp)];

			}else{
				delay(38);
			}
            SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_c+(temp)];
			SPI0DAT = letters[_h+(temp)];
			SPI0DAT = letters[_a+(temp)];
            delay(1);                  
			SPI0DAT = letters[_n+(temp)];
			delay(23);
            switch_channel(channel_index);
            
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
				delay(30);
				SPI0DAT = numbers[ 96+(temp)];
			}else{
				delay(37);
			}
            SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_p+(temp)];
			SPI0DAT = letters[_o+(temp)];
			SPI0DAT = letters[_w+(temp)];                
			SPI0DAT = letters[_e+(temp)];
			delay(1);
			SPI0DAT = letters[_r+(temp)];
            delay(23);
			switch_power(vtx_power_index);
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
					delay(29);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(36);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_s+(temp)];
			SPI0DAT = letters[_e+(temp)];
			SPI0DAT = letters[_t+(temp)];
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
					delay(29);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(36);
			}
			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_b+(temp)];
			SPI0DAT = letters[_a+(temp)];
			SPI0DAT = letters[_c+(temp)];
            delay(1);                  
			SPI0DAT = letters[_k+(temp)];
			break;
		default:
			break;
	}
}


void display_window(unsigned short line)
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
            SPI0DAT = letters[_d+(temp)];
            SPI0DAT = letters[_i+(temp)];
            SPI0DAT = letters[_s+(temp)];
            SPI0DAT = letters[_p+(temp)];
            delay(1);
            SPI0DAT = letters[_l+(temp)];
            delay(1);
            SPI0DAT = letters[_a+(temp)];
            delay(1);
            SPI0DAT = letters[_y+(temp)];
            delay(1);
            SPI0DAT = numbers[80+(temp)];
            break;
		
		case 96:
		case 97:
		case 98:
		case 99:
		case 100:
		case 101:
		case 102:
		case 103:
			temp = line - 96;
			if (index == 0){
				delay(31);
				SPI0DAT = numbers[ 96+(temp)];

			}else{
				delay(38);
			}
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[_d+(temp)];
            SPI0DAT = letters[_i+(temp)];
            SPI0DAT = letters[_s+(temp)];
            SPI0DAT = letters[_a+(temp)];
            delay(1);
            SPI0DAT = letters[_r+(temp)];
            delay(1);
            SPI0DAT = letters[_m+(temp)];
            delay(1);
            SPI0DAT = numbers[ 104+(temp)];
            delay(20);
            SPI0DAT = numbers[low_bat_l_temp[0]+(temp)];
            SPI0DAT = numbers[low_bat_l_temp[1]+(temp)];


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
			if (index == 1){
				delay(31);
				SPI0DAT = numbers[ 96+(temp)];

			}else{
				delay(38);
			}
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[_m+(temp)];
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_d+(temp)];
            delay(1);
            SPI0DAT = letters[_e+(temp)];
            delay(1);
            SPI0DAT = numbers[ 104+(temp)];

            delay(25);
            SPI0DAT = numbers[mode_l_temp[0]+(temp)];
            SPI0DAT = numbers[mode_l_temp[1]+(temp)];
            delay(1);
            
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
			if (index == 2){
				delay(30);
				SPI0DAT = numbers[ 96+(temp)];
			}else{
				delay(37);
			}
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[_v+(temp)];
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_l+(temp)];
            delay(1);
            SPI0DAT = numbers[ 104+(temp)];

            delay(25);
            SPI0DAT = numbers[vol_l_temp[0]+(temp)];
            SPI0DAT = numbers[vol_l_temp[1]+(temp)];
            delay(1);
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
			if (index == 3)
			{
					delay(28);
					SPI0DAT = numbers[ 96+(temp)];
			}
			else
			{
					delay(35);
			}

			SPI0DAT = letters[0+(temp)];
			SPI0DAT = letters[_l+(temp)];
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_w+(temp)];
            SPI0DAT = letters[_b+(temp)];
            delay(1);
            SPI0DAT = letters[_a+(temp)];
            delay(1);
            SPI0DAT = letters[_t+(temp)];
            delay(1);
            SPI0DAT = numbers[ 104+(temp)];
            delay(20);
            SPI0DAT = numbers[low_battery[0]+(temp)];
            SPI0DAT =numbers[88+(temp)];
            SPI0DAT = numbers[low_battery[1]+(temp)];
            delay(1);
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
			if (index == 4)
			{
					delay(28);
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
            delay(1);
            SPI0DAT = letters[_k+(temp)];
            
//        case 171:
//		case 172:
//		case 173:
//		case 174:
//		case 175:
//		case 176:
//		case 177:
//		case 178:
//			temp = line - 171;
//			if (index == 5)
//			{
//					delay(58);
//					SPI0DAT = numbers[ 96+(temp)];
//			}
//			else
//			{
//					delay(65);
//			}
//            SPI0DAT = letters[0+(temp)];
//			SPI0DAT = letters[_b+(temp)];
//            SPI0DAT = letters[_a+(temp)];
//            SPI0DAT = letters[_c+(temp)];
//            delay(3);
//            SPI0DAT = letters[_k+(temp)];
            
		default:
			break;
	}
    
}


void rates_window(unsigned short line)
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
            SPI0DAT = letters[_a+(temp)];
            SPI0DAT = letters[_t+(temp)];
            SPI0DAT = letters[_e+(temp)];
            delay(1);
            SPI0DAT = letters[_s+(temp)];
            delay(3);
            SPI0DAT = numbers[80+(temp)];
            break;
		
		case 96:
		case 97:
		case 98:
		case 99:
		case 100:
		case 101:
		case 102:
		case 103:
			temp = line - 96;
			if (index == 0){
				delay(31);
				SPI0DAT = numbers[ 96+(temp)];

			}else{
				delay(36);
			}
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[_r+(temp)];
            SPI0DAT = letters[_a+(temp)];
            SPI0DAT = letters[_t+(temp)];
            SPI0DAT = letters[_e+(temp)];
            delay(1);
            SPI0DAT = numbers[ 104+(temp)];
            delay(20);
            SPI0DAT = numbers[rate[0]+(temp)];
            SPI0DAT = numbers[rate[1]+(temp)];
            SPI0DAT = numbers[rate[2]+(temp)];
            SPI0DAT = numbers[rate[3]+(temp)];
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
			if (index == 1){
				delay(30);
				SPI0DAT = numbers[ 96+(temp)];

			}else{
				delay(35);
			}
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[_r+(temp)];
            SPI0DAT = letters[_a+(temp)];
            SPI0DAT = letters[_t+(temp)];
            SPI0DAT = letters[_e+(temp)];
            delay(1);
            SPI0DAT =numbers[144+(temp)];
            delay(1);
            SPI0DAT = letters[_y+(temp)];
            delay(1);
            SPI0DAT = letters[_a+(temp)];
            delay(1);
            SPI0DAT = letters[_w+(temp)];
            delay(1);
            SPI0DAT = numbers[ 104+(temp)];

            delay(20);
            SPI0DAT = numbers[rate_yaw[0]+(temp)];
            SPI0DAT = numbers[rate_yaw[1]+(temp)];
            SPI0DAT = numbers[rate_yaw[2]+(temp)];
            SPI0DAT = numbers[rate_yaw[3]+(temp)];
            delay(1);       
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
			if (index == 2){
				delay(30);
				SPI0DAT = numbers[ 96+(temp)];

			}else{
				delay(34);
			}
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[_p+(temp)];
            SPI0DAT = letters[_r+(temp)];
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_f+(temp)];
            delay(1);
            SPI0DAT = letters[_i+(temp)];
            delay(1);
            SPI0DAT = letters[_l+(temp)];
            delay(1);
            SPI0DAT = letters[_e+(temp)];
            delay(1);
            SPI0DAT = numbers[ 104+(temp)];
            delay(20);
            if(profileAB){
                SPI0DAT = letters[_b+(temp)];
            }
            else
            {
                SPI0DAT = letters[_a+(temp)];
            }
            delay(1);       
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
			if (index == 3)
			{
					delay(30);
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
            delay(1);
            SPI0DAT = letters[_k+(temp)];    
		default:
			break;
	}
    
}

