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
        if(0)
        {
            delay(3);
            SPI0DAT = letters[_r+(temp)];
            SPI0DAT = letters[0+(temp)];
            SPI0DAT =numbers[rx0[0]+(temp)];
            SPI0DAT =numbers[88+(temp)];
            SPI0DAT =numbers[rx0[1]+(temp)];
            delay(1);
            SPI0DAT =numbers[rx0[2]+(temp)];

            delay(3);
            SPI0DAT = letters[0+(temp)];
            SPI0DAT = letters[0+(temp)];
            delay(3);
            SPI0DAT = letters[_p+(temp)];
            delay(5);
            SPI0DAT = letters[0+(temp)];
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
        if(0)
        {
            delay(1);
            SPI0DAT = letters[_y+(temp)];
            SPI0DAT = letters[0+(temp)];
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
        if(0)
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
        if(1)
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

    case 160:
    case 161:
    case 162:
    case 163:
    case 164:
    case 165:
    case 166:
    case 167:
        temp = line - 160;
        if(0)
        {
            delay(67);
            SPI0DAT = letters[_t+(temp)];
            SPI0DAT = letters[_u+(temp)];
            SPI0DAT = letters[_r+(temp)];
            SPI0DAT = letters[_t+(temp)];
            SPI0DAT = letters[_l+(temp)];
            delay(1);
            SPI0DAT = letters[_e+(temp)];
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
        if(1)
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
        if(1)
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
        temp = line - 220;
        switch (rx_index) {
        case 0:
        case 1:
            SPI0DAT =letters[_b+(temp)];
            SPI0DAT =letters[_y+(temp)];
            delay(10);
            break;
        case 2:
            SPI0DAT =letters[_s+(temp)];
            SPI0DAT =letters[_b+(temp)];
            SPI0DAT =letters[_u+(temp)];
            SPI0DAT =letters[_s+(temp)];
            delay(2);
            break;
        case 3:
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
            SPI0DAT =letters[_i+(temp)];
            SPI0DAT =letters[_z+(temp)];
            delay(1);
            SPI0DAT =letters[_o+(temp)];
            delay(3);
            SPI0DAT =letters[_n+(temp)];
            break;
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
        delay(40);
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_n+(temp)];
        SPI0DAT = letters[_f+(temp)];
        delay(1);
        SPI0DAT = letters[_i+(temp)];
        delay(1);
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
        delay(40);
        SPI0DAT = letters[_l+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_y+(temp)];
        SPI0DAT = letters[_o+(temp)];
        delay(1);
        SPI0DAT = letters[_u+(temp)];
        delay(1);
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
        temp = line - 126;
        delay(40);
        SPI0DAT = letters[_v+(temp)];
        SPI0DAT = letters[_t+(temp)];
        SPI0DAT = letters[_x+(temp)];
        delay(69);
        SPI0DAT = numbers[ 96+(temp)];
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
        delay(40);
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
        delay(40);
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
        delay(40);
        SPI0DAT = letters[_m+(temp)];
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_d+(temp)];
        SPI0DAT = letters[_e+(temp)];
        delay(50);
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
        delay(40);
        SPI0DAT = letters[_l+(temp)];
        SPI0DAT = letters[_e+(temp)];
        SPI0DAT = letters[_d+(temp)];
        delay(50);
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_n+(temp)];
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
        delay(39);
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_l+(temp)];
        SPI0DAT = letters[_i+(temp)];
        delay(48);
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_k+(temp)];
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
        delay(39);
        SPI0DAT = letters[_r+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_t+(temp)];
        SPI0DAT = letters[_e+(temp)];
        delay(48);
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
        break;

    case 169:
    case 170:
    case 171:
    case 172:
    case 173:
    case 174:
    case 175:
    case 176:
        temp = line - 169;
        delay(39);
        SPI0DAT = letters[_r+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_t+(temp)];
        SPI0DAT = letters[_e+(temp)];
        SPI0DAT = letters[_y+(temp)];
        delay(48);
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
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
        delay(39);
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
        delay(40);
        SPI0DAT = letters[_r+(temp)];
        SPI0DAT = letters[_x+(temp)];
        delay(50);
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_n+(temp)];
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
        delay(40);
        SPI0DAT = letters[_m+(temp)];
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_d+(temp)];
        SPI0DAT = letters[_e+(temp)];
        delay(47);
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_n+(temp)];
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
        delay(40);
        SPI0DAT = letters[_v+(temp)];
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_l+(temp)];
        delay(48);
        SPI0DAT = letters[_o+(temp)];
        SPI0DAT = letters[_n+(temp)];
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
        delay(40);
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

    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
        temp = line - 86;
        delay(39);
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_u+(temp)];
        SPI0DAT = letters[_r+(temp)];
        delay(50);
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
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
        delay(39);
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_h+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_n+(temp)];
        delay(49);
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
        SPI0DAT = numbers[0+(temp)];
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
        delay(39);
        SPI0DAT = letters[_b+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_n+(temp)];
        SPI0DAT = letters[_d+(temp)];
        delay(48);
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = numbers[8+(temp)];
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
        delay(39);
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
        delay(40);
        SPI0DAT = letters[_b+(temp)];
        SPI0DAT = letters[_a+(temp)];
        SPI0DAT = letters[_c+(temp)];
        SPI0DAT = letters[_k+(temp)];
        break;

    }

}




