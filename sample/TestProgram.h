#ifndef BUZ_H
#define BUZ_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif
#endif /* BUZ_H */
#define DO5 956
#define RE5 851
#define MI5 758
#define FA5 716
#define _XTAL_FREQ 4000000
#define M(tone,time,mute) {\
int t;\
for(t=0;t<(time-mute)*10;t+=tone/100*2)\
{PORTAbits.RA6=1;\
__delay_us(tone);\
PORTAbits.RA6=0;\
__delay_us(tone);}\
__delay_ms(mute);\
}
#define GON {PORTBbits.RB4=0;}
#define GOFF {PORTBbits.RB4=1;}
#define YON {PORTBbits.RB5=0;}
#define YOFF {PORTBbits.RB5=1;}
#define RON {PORTBbits.RB6=0;}
#define ROFF {PORTBbits.RB6=1;}
#define BON {PORTBbits.RB7=0;}
#define BOFF {PORTBbits.RB7=1;}