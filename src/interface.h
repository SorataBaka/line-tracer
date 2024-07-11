/* 
 * File:   interface.h
 * Author: p234071
 *
 * Created on 2024/07/11, 11:39
 */

#ifndef INTERFACE_H
#define	INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif
#endif	/* INTERFACE_H */

#define _XTAL_FREQ 4000000

//Define possible notes to be used with the buzzer

#define noteD 294
#define noteFSharp 369
#define noteG 392
#define noteA 440
#define noteB 494
#define noteE 330
#define noteCSharp 554

#define GreenON {PORTBbits.RB4=0;}
#define GreenOFF {PORTBbits.RB4=1;}
#define YellowON {PORTBbits.RB5=0;}
#define YellowOFF {PORTBbits.RB5=1;}
#define RedON {PORTBbits.RB6=0;}
#define RedOFF {PORTBbits.RB6=1;}
#define BlueON {PORTBbits.RB7=0;}
#define BlueOFF {PORTBbits.RB7=1;}

#define RightMotorA PORTBbits.RB0
#define RightMotorB PORTBbits.RB1
#define LeftMotorA PORTBbits.RB3
#define LeftMotorB PORTBbits.RB2

#define GreenLED  PORTBbits.RB4
#define YellowLED PORTBbits.RB5
#define RedLED PORTBbits.RB6
#define BlueLED PORTBbits.RB7

#define LightSensorRight PORTAbits.RA0
#define LightSensorLeft PORTAbits.RA1
#define Button1 PORTAbits.RA2
#define Button2 PORTAbits.RA3
#define Buzzer PORTAbits.RA6

#define wait(time) {__delay_ms(time);}

#define soundBuzzer(tone,time,mute) {\
    for(int t = 0; t < (time - mute) * 10; t += tone/100*2){\
        PORTAbits.RA6=0;\
        __delay_us(tone);\
        PORTAbits.RA6=1;\
        __delay_us(tone);\
    }\
    __delay_ms(mute);\
}
#define Forward(ratio,wait) {\
    for(int t = 0; t < 10; t++){\
        LeftMotorA = 0;\
        LeftMotorB = 1;\
        RightMotorA = 0;\
        RightMotorB = 1:\
        __delay_ms(ratio);\
        \
        PORTBbits.RB1=0;\
        PORTBbits.RB2=0;\
        __delay_ms(wait);\
    }\
}