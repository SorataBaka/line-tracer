
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "buz.h"
void playSound(int frequency, int time, int mute){
    for(int i = 0; i < (time - mute) * 10; i += frequency/100 * 2){
        Buzzer = 1;
        __delay_us(frequency);
        Buzzer = 0;
        __delay_us(frequency);
        __delay_us(1000);
    }
    return;
}
