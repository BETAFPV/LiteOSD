#include "show.h"
#include "ascii.h"



unsigned short rx0_l=70;
unsigned short rx1_l=85;
unsigned short rx2_l=105;
unsigned short lock_l=150;
unsigned short rxloss_l=185;
unsigned short low_bat_l=200;
unsigned short mode_l=220;
unsigned short vol_l=235;

unsigned char  temp = 0;


extern unsigned char cur_index;
extern unsigned char turtlemode;
extern unsigned char failsafe;
extern unsigned short line;
extern unsigned char  VOT_value[3];
extern unsigned char  min_text[2];
extern unsigned char  sec_text[2];
extern unsigned char  rx_index ;
extern unsigned char  flymode ;
extern unsigned char   rx0[3];
extern unsigned char   rx1[3];
extern unsigned char   rx2[3];
extern unsigned char   rx3[3];
extern unsigned char   chn[4];
extern unsigned char  lock;
extern unsigned char  low_vol;
extern unsigned char  acc_cali;
extern unsigned char rgb_led;
extern unsigned char rate[4];
extern unsigned char rate_yaw[4];
extern unsigned char  mode;
extern unsigned char rx_show;
extern unsigned char mode_show;
extern unsigned char vol_show;
extern unsigned char   ochn[4];
extern unsigned char vtx_index;
extern unsigned char band_index;


void switch_channel(unsigned char index)
{
    switch(index) {
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
    default
            :
        break;
    }
}



void switch_band(unsigned char index)
{
    switch(index)
    {
        case 0:
            SPI0DAT = letters[ _a+(temp)]; \
            SPI0DAT = numbers[ 8+(temp)];
            break;
        
        case 1:
            SPI0DAT = letters[ _b+(temp)]; \
            SPI0DAT = numbers[ 8+(temp)];
            break;
        
        case 2:
            SPI0DAT = letters[ _c+(temp)]; \
            SPI0DAT = numbers[ 8+(temp)];
            break;
        
        case 3:
            SPI0DAT = letters[ _d+(temp)]; \
            SPI0DAT = numbers[ 8+(temp)];
            break;
        
        case 4:
            SPI0DAT = letters[ _e+(temp)]; \
            SPI0DAT = numbers[ 8+(temp)];
            break;
    }
}



void delay(unsigned char n)
{
    unsigned char i;
    for(i=0; i<n; i++)
        ;
}


void flight_window(unsigned short line)
{
    switch (line)
    {
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
        temp = line - 66;
        if(rx_show)
        {
            delay(3);
            SPI0DAT = letters[_r+(temp)];
            
            if(ochn[0])
            {
                SPI0DAT =numbers[152+(temp)];
            }
            else
            {
                SPI0DAT = letters[0+(temp)];
            }
            SPI0DAT =numbers[rx0[0]+(temp)];
            SPI0DAT =numbers[88+(temp)];
            SPI0DAT =numbers[rx0[1]+(temp)];
            delay(2);
            SPI0DAT =numbers[rx0[2]+(temp)];

            delay(3);
                        
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[0+(temp)];

            delay(3);
                        
            SPI0DAT = letters[_p+(temp)];
            delay(5);
            if(ochn[1])
            {
                SPI0DAT =numbers[152+(temp)];
            }
            else
            {
                SPI0DAT = letters[0+(temp)];
            }
            delay(5);
            SPI0DAT =numbers[rx1[0]+(temp)];
            delay(4);
            SPI0DAT =numbers[88+(temp)];
            delay(5);
            SPI0DAT =numbers[rx1[1]+(temp)];
            delay(6);
            SPI0DAT =numbers[rx1[2]+(temp)];
        }
        break;
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
        temp = line - 83;
        if(rx_show)
        {
            delay(1);
            SPI0DAT = letters[_y+(temp)];
            if(ochn[2])
            {
                SPI0DAT =numbers[152+(temp)];
            }
            else
            {
                SPI0DAT = letters[0+(temp)];
            }
            SPI0DAT =numbers[rx2[0]+(temp)];
            SPI0DAT =numbers[88+(temp)];
            SPI0DAT =numbers[rx2[1]+(temp)];
            delay(1);
            SPI0DAT =numbers[rx2[2]+(temp)];

            delay(3);
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[0+(temp)];
            delay(3);
            SPI0DAT = letters[_t+(temp)];
            delay(5);
            SPI0DAT = letters[0+(temp)];
            delay(5);
            SPI0DAT =numbers[rx3[0]+(temp)];
            delay(4);
            SPI0DAT =numbers[88+(temp)];
            delay(5);
            SPI0DAT =numbers[rx3[1]+(temp)];
            delay(6);
            SPI0DAT =numbers[rx3[2]+(temp)];
        }
        break;

    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
        temp = line - 100;
        if(rx_show)
        {
            delay(1);
            SPI0DAT = letters[_c+(temp)];
            SPI0DAT = letters[_h+(temp)];

            delay(5);
            SPI0DAT = letters[0+(temp)];
            SPI0DAT =numbers[chn[0]+(temp)];
            delay(4);
            SPI0DAT = letters[0+(temp)];
            SPI0DAT =numbers[chn[1]+(temp)];
            delay(5);
            SPI0DAT = letters[0+(temp)];
            SPI0DAT =numbers[chn[2]+(temp)];
            delay(6);
            SPI0DAT = letters[0+(temp)];
            SPI0DAT =numbers[chn[3]+(temp)];
        }
        break;

    case 140:
    case 141:
    case 142:
    case 143:
    case 144:
    case 145:
    case 146:
    case 147:
        temp = line - 140;
        if(!lock)
        {
            delay(67);
            SPI0DAT = letters[_d+(temp)];
            SPI0DAT = letters[_i+(temp)];
            SPI0DAT = letters[_s+(temp)];
            SPI0DAT = letters[_a+(temp)];
            SPI0DAT = letters[_r+(temp)];
            delay(1);
            SPI0DAT = letters[ _m+(temp)];
        }
        break;

    case 180:
    case 181:
    case 182:
    case 183:
    case 184:
    case 185:
    case 186:
    case 187:
        temp = line - 180;
        if(failsafe)
        {
            delay(65);
            SPI0DAT = letters[_r+(temp)];
            SPI0DAT = letters[_x+(temp)];
            SPI0DAT = letters[0+(temp)];

            SPI0DAT = letters[_l+(temp)];
            SPI0DAT = letters[_o+(temp)];
            delay(1);
            SPI0DAT = letters[_s+(temp)];
            delay(4);
            SPI0DAT = letters[ _s+(temp)];
        }
        break;

    case 200:
    case 201:
    case 202:
    case 203:
    case 204:
    case 205:
    case 206:
    case 207:
        temp = line - 200;
        if(low_vol)
        {
            delay(64);
            SPI0DAT = letters[_l+(temp)];
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_w+(temp)];
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[_v+(temp)];
            delay(1);
            SPI0DAT = letters[_o+(temp)];
            delay(4);
            SPI0DAT = letters[ _l+(temp)];
        }
        break;

    case 220:
    case 221:
    case 222:
    case 223:
    case 224:
    case 225:
    case 226:
    case 227:
        if(mode_show)
        {
            temp = line - 220;
            switch (rx_index) {
            case 0:
            case 1:
                delay(1);
                SPI0DAT =letters[_b+(temp)];
                SPI0DAT =letters[_y+(temp)];
                delay(10);
                break;
            case 2:
                delay(1);
                SPI0DAT =letters[_s+(temp)];
                SPI0DAT =letters[_b+(temp)];
                SPI0DAT =letters[_u+(temp)];
                SPI0DAT =letters[_s+(temp)];
                delay(2);
                break;
            case 3:
                delay(1);
                SPI0DAT =letters[_d+(temp)];
                SPI0DAT =letters[_s+(temp)];
                SPI0DAT =letters[_m+(temp)];
                SPI0DAT =letters[_x+(temp)];
                delay(2);
                break;
            }
            switch (flymode) {
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
                break;
            }
        }
        break;

    case 235:
    case 236:
    case 237:
    case 238:
    case 239:
    case 240:
    case 241:
    case 242:
        if(vol_show)
        {
            temp = line - 235;
            delay(1);
            SPI0DAT =letters[ _v+(temp)];
            SPI0DAT =numbers[VOT_value[0]+(temp)];
            SPI0DAT =numbers[88+(temp)];
            SPI0DAT =numbers[VOT_value[1]+(temp)];
            SPI0DAT =numbers[VOT_value[2]+(temp)];

            delay(120);
            SPI0DAT =numbers[ min_text[0]+(temp)];
            SPI0DAT =numbers[ min_text[1]+(temp)];
            SPI0DAT =numbers[104+(temp)];
            SPI0DAT =numbers[ sec_text[0]+(temp)];
            SPI0DAT =numbers[ sec_text[1]+(temp)];
        }
        break;
    }
}


void set_window(unsigned short line)
{
    switch (line)
    {
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
        temp = line - 66;
        delay(30);
        SPI0DAT = numbers[80+(temp)];
        SPI0DAT = letters[_m+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_i+(temp)];
        SPI0DAT = letters[_n+(temp)];
        delay(1);
        SPI0DAT = numbers[80+(temp)];
        break;

    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
        temp = line - 86;
        if (cur_index == 0) {
            delay(32);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(38);
        }
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_n+(temp)];
        SPI0DAT = letters[_f+(temp)];
        delay(1);
        SPI0DAT = letters[_i+(temp)];
        delay(2);
        SPI0DAT = letters[_g+(temp)];
        delay(60);
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
        if (cur_index == 1) {
            delay(32);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(38);
        }
        SPI0DAT = letters[_l+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_y+(temp)];
        SPI0DAT = letters[_o+(temp)];
        delay(1);
        SPI0DAT = letters[_u+(temp)];
        delay(2);
        SPI0DAT = letters[_t+(temp)];
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
        if(mode)
        {
            temp = line - 126;
            if (cur_index == 2) {
                delay(32);
                SPI0DAT = numbers[ 96+(temp)];

            } else {
                delay(38);
            }
            SPI0DAT = letters[_v+(temp)];
            SPI0DAT = letters[_t+(temp)];
            SPI0DAT = letters[_x+(temp)];
            delay(69);
            SPI0DAT = numbers[ 96+(temp)];
        }
        break;

    case 159:
    case 160:
    case 161:
    case 162:
    case 163:
    case 164:
    case 165:
    case 166:
        temp = line - 159;
        if (cur_index == 3) {
            delay(32);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(38);
        }
        SPI0DAT = letters[_s+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_v+(temp)];
        SPI0DAT = letters[_e+(temp)];
        break;

    case 179:
    case 180:
    case 181:
    case 182:
    case 183:
    case 184:
    case 185:
    case 186:
        temp = line - 179;
        if (cur_index == 4) {
            delay(32);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(38);
        }
        SPI0DAT = letters[_e+(temp)];
        SPI0DAT = letters[_x+(temp)];
        SPI0DAT = letters[_i+(temp)];
        SPI0DAT = letters[_t+(temp)];
        break;

    }
}



void config_window(unsigned short line)
{
    switch (line)
    {
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
        temp = line - 66;
        delay(30);
        SPI0DAT = numbers[80+(temp)];
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_n+(temp)];
        SPI0DAT = letters[_f+(temp)];
        delay(1);
        SPI0DAT = letters[_i+(temp)];
        delay(3);
        SPI0DAT = letters[_g+(temp)];
        delay(4);
        SPI0DAT = numbers[80+(temp)];
        break;

    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
        temp = line - 86;
        if (cur_index == 0) {
            delay(34);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(40);
        }
        SPI0DAT = letters[_m+(temp)];
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_d+(temp)];
        SPI0DAT = letters[_e+(temp)];
        delay(50);
        
        if(mode)
        {
            SPI0DAT = letters[_a+(temp)];
            SPI0DAT = letters[_d+(temp)];
            SPI0DAT = letters[_v+(temp)];
            SPI0DAT = letters[_a+(temp)];
            delay(1);
            SPI0DAT = letters[_n+(temp)];
            delay(1);
            SPI0DAT = letters[_c+(temp)];
            delay(1);
            SPI0DAT = letters[_e+(temp)];
            delay(3);
            SPI0DAT = letters[_d+(temp)];
        }
        else
        {
            SPI0DAT = letters[_s+(temp)];
            SPI0DAT = letters[_t+(temp)];
            SPI0DAT = letters[_a+(temp)];
            SPI0DAT = letters[_r+(temp)];
            delay(1);
            SPI0DAT = letters[_t+(temp)];
            delay(1);
            SPI0DAT = letters[_e+(temp)];
            delay(1);
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
        if (cur_index == 1) {
            delay(32);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(40);
        }
        SPI0DAT = letters[_l+(temp)];
        SPI0DAT = letters[_e+(temp)];
        SPI0DAT = letters[_d+(temp)];
        delay(50);
        if(rgb_led)
        {
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_n+(temp)];
        }
        else
        {
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_f+(temp)];
            SPI0DAT = letters[_f+(temp)];
        }
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
        if (cur_index == 2) {
            delay(32);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(38);
        }
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_l+(temp)];
        SPI0DAT = letters[_i+(temp)];
        delay(48);
        if(acc_cali)
        {
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_k+(temp)];
        }
        break;

    case 149:
    case 150:
    case 151:
    case 152:
    case 153:
    case 154:
    case 155:
    case 156:
        if(mode)
        {
            temp = line - 149;
            if (cur_index == 3) {
                delay(32);
                SPI0DAT = numbers[ 96+(temp)];

            } else {
                delay(38);
            }
            SPI0DAT = letters[_r+(temp)];
            SPI0DAT = letters[_a+(temp)];
            SPI0DAT = letters[_t+(temp)];
            SPI0DAT = letters[_e+(temp)];
            delay(48);
            SPI0DAT = numbers[rate[0]+(temp)];
            SPI0DAT = numbers[rate[1]+(temp)];
            SPI0DAT = numbers[rate[2]+(temp)];
            SPI0DAT = numbers[rate[3]+(temp)];
        }
        break;

    case 169:
    case 170:
    case 171:
    case 172:
    case 173:
    case 174:
    case 175:
    case 176:
        if(mode)
        {
            temp = line - 169;
            if (cur_index == 4) {
                delay(30);
                SPI0DAT = numbers[ 96+(temp)];

            } else {
                delay(38);
            }
            SPI0DAT = letters[_r+(temp)];
            SPI0DAT = letters[_a+(temp)];
            SPI0DAT = letters[_t+(temp)];
            SPI0DAT = letters[_e+(temp)];
            delay(2);
            SPI0DAT = letters[_y+(temp)];
            delay(48);
            SPI0DAT = numbers[rate_yaw[0]+(temp)];
            SPI0DAT = numbers[rate_yaw[1]+(temp)];
            SPI0DAT = numbers[rate_yaw[2]+(temp)];
            SPI0DAT = numbers[rate_yaw[3]+(temp)];
        }
        break;

    case 202:
    case 203:
    case 204:
    case 205:
    case 206:
    case 207:
    case 208:
    case 209:
        temp = line - 202;
        if (cur_index == 5) {
            delay(32);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(38);
        }
        SPI0DAT = letters[_b+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_k+(temp)];
        break;

    }
}


void layout_window(unsigned short line)
{
    switch (line)
    {
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
        temp = line - 66;
        delay(30);
        SPI0DAT = numbers[80+(temp)];
        SPI0DAT = letters[_l+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_y+(temp)];
        SPI0DAT = letters[_o+(temp)];
        delay(1);
        SPI0DAT = letters[_u+(temp)];
        delay(3);
        SPI0DAT = letters[_t+(temp)];
        delay(4);
        SPI0DAT = numbers[80+(temp)];
        break;

    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
        temp = line - 86;
        if (cur_index == 0) {
            delay(34);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(40);
        }
        SPI0DAT = letters[_r+(temp)];
        SPI0DAT = letters[_x+(temp)];
        delay(50);
        if(rx_show)
        {
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_n+(temp)];
        }
        else
        {
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_f+(temp)];
            SPI0DAT = letters[_f+(temp)];
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
        if (cur_index == 1) {
            delay(34);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(40);
        }
        SPI0DAT = letters[_m+(temp)];
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_d+(temp)];
        SPI0DAT = letters[_e+(temp)];
        delay(47);
        if(mode_show)
        {
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_n+(temp)];
        }
        else
        {
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_f+(temp)];
            SPI0DAT = letters[_f+(temp)];
        }
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
        if (cur_index == 2) {
            delay(34);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(40);
        }
        SPI0DAT = letters[_v+(temp)];
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_l+(temp)];
        delay(48);
        if(vol_show)
        {
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_n+(temp)];
        }
        else
        {
            SPI0DAT = letters[_o+(temp)];
            SPI0DAT = letters[_f+(temp)];
            SPI0DAT = letters[_f+(temp)];
        }
        break;

    case 159:
    case 160:
    case 161:
    case 162:
    case 163:
    case 164:
    case 165:
    case 166:
        temp = line - 159;
        if (cur_index == 3) {
            delay(34);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(40);
        }
        SPI0DAT = letters[_b+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_k+(temp)];
        break;

    }
}


void vtx_window(unsigned short line)
{
    switch (line)
    {
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
        temp = line - 66;
        delay(30);
        SPI0DAT = numbers[80+(temp)];
        SPI0DAT = letters[_v+(temp)];
        SPI0DAT = letters[_t+(temp)];
        SPI0DAT = letters[_x+(temp)];
        delay(1);
        SPI0DAT = numbers[80+(temp)];
        break;

//    case 86:
//    case 87:
//    case 88:
//    case 89:
//    case 90:
//    case 91:
//    case 92:
//    case 93:
//        temp = line - 86;
//        delay(39);
//        SPI0DAT = letters[_c+(temp)];
//        SPI0DAT = letters[_u+(temp)];
//        SPI0DAT = letters[_r+(temp)];
//        delay(50);
//        SPI0DAT = numbers[0+(temp)];
//        SPI0DAT = numbers[0+(temp)];
//        SPI0DAT = numbers[0+(temp)];
//        SPI0DAT = numbers[0+(temp)];
//        break;

    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
        temp = line - 106;
        if (cur_index == 0) {
            delay(34);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(40);
        }
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_h+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_n+(temp)];
        delay(49);
        switch_channel(vtx_index);
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
        if (cur_index == 1) {
            delay(34);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(40);
        }
        SPI0DAT = letters[_b+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_n+(temp)];
        SPI0DAT = letters[_d+(temp)];
        delay(48);
        switch_band(band_index);
        break;

    case 149:
    case 150:
    case 151:
    case 152:
    case 153:
    case 154:
    case 155:
    case 156:
        temp = line - 149;
        if (cur_index == 2) {
            delay(34);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(40);
        }
        SPI0DAT = letters[_s+(temp)];
        SPI0DAT = letters[_e+(temp)];
        SPI0DAT = letters[_t+(temp)];
        break;

    case 182:
    case 183:
    case 184:
    case 185:
    case 186:
    case 187:
    case 188:
    case 189:
        temp = line - 182;
        if (cur_index == 3) {
            delay(34);
            SPI0DAT = numbers[ 96+(temp)];

        } else {
            delay(40);
        }
        SPI0DAT = letters[_b+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_k+(temp)];
        break;

    }

}




