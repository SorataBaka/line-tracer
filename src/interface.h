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

//Define possible notes to be used with the buzzer

#define DO5 956
#define RE5 851
#define MI5 758
#define FA5 716
#define SOL5 638
#define LA5 568
#define SI5 506

#define GON {PORTBbits.RB4=0;}
#define GOFF {PORTBbits.RB4=1;}
#define YON {PORTBbits.RB5=0;}
#define YOFF {PORTBbits.RB5=1;}
#define RON {PORTBbits.RB6=0;}
#define ROFF {PORTBbits.RB6=1;}
#define BON {PORTBbits.RB7=0;}
#define BOFF {PORTBbits.RB7=1;}

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