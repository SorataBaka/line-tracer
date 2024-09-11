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
    
    soundBuzzer(523, 200, 50);
    soundBuzzer(659, 200, 100);
}

void SetRightMotor(int direction, int state){
    if(state == 0){
        RightMotorA = 0;
        RightMotorB = 0;
        return;
    }
    if(direction == 1 && state == 1){
        RightMotorA = 1;
        RightMotorB = 0;
        return;
    } else if(direction == 0 && state == 1){
        RightMotorA = 0;
        RightMotorB = 1;
        return;
    }
}

void SetLeftMotor(int direction, int state){
    if(state == 0){
        LeftMotorA = 0;
        LeftMotorB = 0;
        return;
    }
    if(direction == 1 && state == 1){
        LeftMotorA = 0;
        LeftMotorB = 1;
        return;
    } else if(direction == 0 && state == 1){
        LeftMotorA = 0;
        LeftMotorB = 1;
        return;
    }
}

int main(int argc, char** argv) {
    // Initialize all values
    OSCF=1;
    CMCON=0b00000111;//portA の 0～3 はデジタル入力
    PORTA=0b00000000;//portA の初期化（全て LOW)
    TRISA=0b00111111;//portA の 0～5 を入力
    PORTB=0b00000000;//出力ピンの初期化（全て LOW）
    TRISB=0b00000000;//全て出力に割り当てる
    STARTUP:
    Initialize();
    StartupSequence();
    while(1){
        BlueON
        if(!Button1){
            BlueOFF
            soundBuzzer(523, 200, 50);
            break;
        }
    }
    while(1){
        GreenON
        if(!Button1 && !Button2){  
            GreenOFF
            RedON
            soundBuzzer(392, 2000, 100);
            break;
        }
        if(!Button2) goto STARTUP;
        //If both sensors detect white, simply go forward
        if(LightSensorLeft && LightSensorRight){
            SetLeftMotor(1, 1);
            SetRightMotor(1, 1);
            YellowON
            BlueON
        //Change these if the sensor positioning doesnt correlate to motor movement. What if want
        //is that if the left sensor detects black, we move right motor
        //if right sensor detects black, we move left motor
        }else if(LightSensorLeft && !LightSensorRight){
            SetRightMotor(1, 1);
            BlueON
        //Otherwise, if both detect black for example the ending area, stop both motors
        }else if(!LightSensorLeft && LightSensorRight){
            SetLeftMotor(1, 1);
            YellowON
        }
        wait(100);
        SetLeftMotor(0, 0);
        SetRightMotor(0, 0);
        GreenOFF
        YellowOFF
        BlueOFF        
        RedOFF
    }
    while(1){
        if(!Button2) goto STARTUP;
    }
    return (EXIT_SUCCESS);
}