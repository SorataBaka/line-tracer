#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "buz.h"
#include "interface.h"

#pragma config FOSC=INTOSCIO //内部クロック、RA6,7 は IO
#pragma config WDTE=OFF
#pragma config PWRTE=OFF
#pragma config MCLRE=OFF
#pragma config BOREN=OFF
#pragma config LVP=OFF
#pragma config CPD=ON
#pragma config CP=ON
int main(int argc, char** argv) {
    OSCF=1;
    CMCON=0b00000111;//portA の 0～3 はデジタル入力
    PORTA=0b00000000;//portA の初期化（全て LOW)
    TRISA=0b00111111;//portA の 0～5 を入力
    PORTB=0b00000000;//出力ピンの初期化（全て LOW）
    TRISB=0b00000000;//全て出力に割り当てる
    while(1){
        
    }
    return (EXIT_SUCCESS);
}