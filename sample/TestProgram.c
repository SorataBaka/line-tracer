#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "buz.h"
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
        if(!PORTAbits.RA0){
            //PORTA の RA0 が黒を感知したか？
            RON
            M(MI5,400,100);
        } else ROFF // ALSO KNOWN AS RED OFF
                
        if(!PORTAbits.RA1){
            //PORTA の RA1 が黒を感知したか
            GON
            M(DO5,400,100);
        } else GOFF // ALSO KNOWN AS GREEN OFF
                
        if(!PORTAbits.RA2){
            //タクトスイッチが押されたか
            YON
            M(RE5,400,100);
        } else YOFF // ALSO KNOWN AS YELLOW OFF
                
        if(!PORTAbits.RA3){
            //タクトスイッチが押されたか
            BON
            M(FA5,600,100);
        } else BOFF; // ALSO KNOWN AS BLUE OFF
    }
    return (EXIT_SUCCESS);
}