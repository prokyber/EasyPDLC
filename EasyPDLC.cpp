#include "EasyPDLC.h"


void EasyPDLC::OutputEnableFunction(){
    digitalWrite(outputEnable, !digitalRead(outputEnable));
}

static void ticker_trigger(EasyPDLC* callback_func) {
	callback_func->OutputEnableFunction();
}

EasyPDLC::EasyPDLC(uint8_t outputEnable,uint8_t shcp, uint8_t stcp, uint8_t dsin):
        outputEnable(outputEnable),
        shcp(shcp),
        stcp(stcp),
        dsin(dsin)
        
{
    pinMode(outputEnable, OUTPUT);
    pinMode(shcp, OUTPUT);
    pinMode(stcp, OUTPUT);
    pinMode(dsin, OUTPUT);
    enableState = true;
}

void EasyPDLC::SetPDLC(uint16_t number){
    if(enableState){
        enableState = false;
        tickerInstance.attach_ms(10, ticker_trigger, this);
    }

    if(number<pow(2, 16)-1){
        uint8_t firstRegister = number & (uint16_t)0b11111111;
        uint8_t secondRegister = ((number >> 8) & (uint16_t)0b11111111) | 0b00100000;
        shiftOut(dsin, shcp, MSBFIRST, (uint8_t)(secondRegister));
        shiftOut(dsin, shcp, MSBFIRST, (uint8_t)(firstRegister));
    }
    else{
        shiftOut(dsin, shcp, MSBFIRST, (uint8_t)0);
        shiftOut(dsin, shcp, MSBFIRST, (uint8_t)0);
    }

}

void EasyPDLC::Latch(void){
    digitalWrite(stcp, LOW);
    delay(1);
    digitalWrite(stcp, HIGH);
}
