# Fork of original Heltec library

**With the mission to:**

1. Make configuration simpler
2. Add a way to configure the library without touching the .pio/libdeps folder itself
3. Explain briefly and to the point the steps to get it running

This fork is inteded to be used as a library in Platformio projects. Check [Heltec Epaper product page](https://heltec.org/proudct_center/e_inkpaper/) as a reference to find your display Tech specs.

## Configuring this using build_flags using Platformio

Let's try to make a modern configuration without touching the library, but just using build flags that are inserted as #define in the build process. Just as a reference, in the original includes I left commented the #define statements: [PIN config epdif.h](https://github.com/martinberlin/e-ink-platformio/blob/master/src/epdif.h) & [Display model eink.h](https://github.com/martinberlin/e-ink-platformio/blob/master/src/e_ink.h)

This is an example platformio.ini file for ESP32 but it can be used for ESP8266. Just copy and modify it for your project:

```
; Please visit documentation for the other options and examples:
; https://docs.platformio.org/page/projectconf.html
[platformio]
; espressif8266  OR  esp32
default_envs = esp32 
[env:esp32]
platform = https://github.com/platformio/platform-espressif32.git
board = lolin_d32
framework = arduino
monitor_speed = 115200
build_flags =
  -D USE_154_BW_GREEN=1
  -D DC_PIN=5
  -D CS_PIN=21
  -D CLK_PIN=18
  -D SDI_PIN=23
  -D RST_PIN=-1
  -D BUSY_PIN=22

lib_deps =
   https://github.com/martinberlin/e-ink-platformio.git
```

Please note that the display I used to test is: USE_154_BW_GREEN
Replace that for your own model to fit your needs. Make sure that the build variables need a value when are inserted like this so even if it should be empty use:

-DMYDEFINE=1

For ESP8266 just change the default_envs to the board you use and find out what GPIOs are the right ones. Do not use D8 and so on defines! This is a bad way to refence the GPIO numbers and wont work like this in build_flags, check your ESP8266 board documentation and use the GPIO number itself. On ESP32 the default MOSI pin is 23 and the CLOCK pin is on 18. RST and BUSY are -1 since they don't seem to do anything (BUSY is on some Einks but in this case I tried to use it wired/unwired and does not make any difference)

Contact. Twitter: @martinfasani / www.cale.es

## Contents

- [The Overview](#the-overview)
- [Installing](#installing)
- [Features](#features)

## The Overview
--------
- Arduino library for E-Ink display(1.54, 2.3, 2.9) made by HelTec Automation(TM)
- Now this library allows three sizes of e-ink to run on the "AVR" , "ESP32" , "ESP8266" development board.
- **Check the provided platformio.ini configuration file and adapt it to your needs**

## Installing

Just add this line into your **platformio.ini** lib_deps variable: 

    lib_deps =
       https://github.com/martinberlin/e-ink.git



## Features

- Arduino library for E-Ink display(1.54, 2.3, 2.9).
- Consumes power only during refresh, power consumption as low as 24-30mW.
- Support for partial refresh, only takes 0.3s.

Please reference the [original Heltec library](https://github.com/HelTecAutomation/e-ink) for pictures and buy links. This is just my intention to make a better job explaining how it works than Heltec did, hence I will try to display minimal information and just cover the parts that I felt where lacking explanations and make a more modern way to set it up.
As a developer I always felt frustrated when you need to touch the libraries itself to configure something. The role of a library is to do it's job and get out of the way. Configuration should be external, not touching the lib itself in the "Arduino old way" style.
 
## Issue/Bug report template

Before reporting an issue, make sure you've searched for similar one that was already created. Also make sure to go through all the issues labelled as [for reference](https://github.com/HelTecAutomation/e-ink/issues).     
