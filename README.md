# LINE TRACER ROBOT
釧路工業高等専門学校４年情報学科プログラミング実験ライントレーサーロボットプロジェクト
担任先生：土江田先生

NOTES ABOUT THE PROGRAM
Every single input to the IC can be found within the PORTAbits object.
Within PORTAbits, can be found all the inputs from sensors, and switches.
Details of the contents of PORTAbits is as follows: 
RA0 is a light sensor. A light sensor outputs a 1 when it detects something dark.
RA1 is also a light sensor.
RA2 is a button switch
RA3 is also a button switch.
RA6 and RA7 are special pins because they act as both input and output. In this case, RA6 is connected to the buzzer.

Every single output from the IC can be found within the PORTBbits object.
Within PORTBbits, can be found all the possible outputs from the IC.
Details of the contents of PORTBbits is as follows:

RB0 and RB1 Controls the right motor (VIEW FROM THE BACK)
RB2 and RB3 Controls the left motor (VIEW FROM THE BACK)

RB0 0 + RB1 1 RIGHT FORWARD
RB0 1 + RB1 0 RIGHT BACKWARD
RB2 1 + RB3 0 LEFT FORWARD
RB2 0 + RB3 1 LEFT BACKWARD


BOTH 0 = STOP
BOTH 1 = NOT ALLOWED


RB4 is the green LED
RB5 is the yellow LED
RB6 is the red LED
RB7 is the blue LED

Based on the given header file, 