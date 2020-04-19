#ifndef EPDIF_H
#define EPDIF_H

#include <Arduino.h>
#include <SPI.h>
#include "imagedata.h"

// ESP32 config example, please do not set it here but using build_flags like explained in the README file
// Pin definition
//#define RST_PIN         -1
//#define DC_PIN          27
//#define CS_PIN          32
//#define BUSY_PIN        -1
//#define CLK_PIN         18
//#define SDI_PIN         23

class EpdIf {
public:
    EpdIf(void);
    ~EpdIf(void);

    static int  IfInit(void);
    static void DigitalWrite(int pin, int value); 
    static int  DigitalRead(int pin);
    static void DelayMs(unsigned int delaytime);
    static void SpiTransfer(unsigned char data);
};

#endif
