#include "uart.h"

uint16_t StrToInt(char *s) {
    uint16_t var = 0;
    uint16_t i = 0;
    uint16_t sign = 0;
    if (s[i] == '-') {
        sign = 1;
        i++;
    } 

    while (s[i] >= 0x30 && s[i] <= 0x39) {
        var = var + (s[i] & 0x0F);
        var = var * 10;
        i++;
    }
    var = var / 10;
    if (sign == 1)
        var = -var;
    return (var);
}

//		char str[3] = "123";		
//		test0 = StrToInt(str);

