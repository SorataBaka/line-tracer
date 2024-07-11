/* 
 * File:   BUZ.c
 * Author: menta
 *
 * Created on 2021/10/07, 13:39
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "buz.h"
#pragma config FOSC=INTOSCIO
#pragma config WDTE=OFF
#pragma config PWRTE=OFF
#pragma config MCLRE=OFF
#pragma config BOREN=OFF
#pragma config LVP=OFF
#pragma config CPD=ON
#pragma config CP=ON
/*
 * 
 */
int main(int argc, char** argv) {
    OSCF=1;
    CMCON=0b00000111;
    PORTA=0b00000000;
    TRISA=0b00111111;
    PORTB=0b00000000;
    TRISB=0b00000000;
    while(1){
        if(!PORTAbits.RA0){
            RON
            M(MI5,400,100);
        }else ROFF
        if(!PORTAbits.RA1){
            GON
            M(DO5,400,100);
        }else GOFF
        if(!PORTAbits.RA2){
            YON
            M(RE5,400,100);
        }else YOFF
        if(!PORTAbits.RA3){
            BON
            M(FA5,600,100);
        }else BOFF;
    }
    
    return (EXIT_SUCCESS);
}




