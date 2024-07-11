#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "interface.h"

#pragma config FOSC=INTOSCIO //内部クロック、RA6,7 は IO
#pragma config WDTE=OFF
#pragma config PWRTE=OFF
#pragma config MCLRE=OFF
#pragma config BOREN=OFF
#pragma config LVP=OFF
#pragma config CPD=ON
#pragma config CP=ON

void Initialize(){
    GreenOFF
    YellowOFF
    RedOFF
    BlueOFF
    
    RightMotorA = RightMotorB = 0;
    LeftMotorA = LeftMotorB = 0;
}
void StartupSequence(){
    //Turn on each LED one by one
    YellowON
    wait(500);
    YellowOFF
    GreenON
    wait(500);
    GreenOFF
    RedON
    wait(500);
    RedOFF
    BlueON
    wait(500)
    BlueOFF
    
    soundBuzzer(noteD, 300, 50);
    soundBuzzer(noteFSharp, 300, 100);
    soundBuzzer(noteG, 300, 100);
    soundBuzzer(noteA, 300, 100);
    soundBuzzer(noteG, 300, 100);
    soundBuzzer(noteFSharp, 300, 100);
    soundBuzzer(noteD, 300, 100);
}

void SetleftMotor(int direction, int state){
    if(state == 0){
        LeftMotorA = 0;
        LeftMotorB = 0;
        return;
    }
    if(direction == 1){
        LeftMotorA = 0;
        LeftMotorB = 1;
        return;
    }
    LeftMotorA = 1;
    LeftMotorB = 0;
    return;
}
void SetRightMotor(int direction, int state){
    if(state == 0){
        RightMotorA = 0;
        RightMotorB = 0;
        return;
    }
    if(direction == 1){
        RightMotorA = 0;
        RightMotorB = 1;
        return;
    }
    RightMotorA = 1;
    RightMotorB = 0;
    return;
}


int main(int argc, char** argv) {
    // Initialize all values
    OSCF=1;
    CMCON=0b00000111;//portA の 0～3 はデジタル入力
    PORTA=0b00000000;//portA の初期化（全て LOW)
    TRISA=0b00111111;//portA の 0～5 を入力
    PORTB=0b00000000;//出力ピンの初期化（全て LOW）
    TRISB=0b00000000;//全て出力に割り当てる
    Initialize();
    StartupSequence();
    while(1){
        SetLeftMotor(1, 1);
        wait(2000);
        SetRightMotor(0, 1);
        wait(2000);
        SetRightMotor(0, 0);
        
        BlueON
        wait(200);
        BlueOFF
    }
    return (EXIT_SUCCESS);
}