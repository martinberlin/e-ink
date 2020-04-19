# Fork of original Heltec library

**With the mission to:**

1. Make configuration simpler
2. Add a way to configure the library without touching the .pio/libdeps folder itself
3. Explain briefly and to the point the steps to get it running (In a human way and not like the original library did)

## Configuring this using build_flags using Platformio

Let's try to make a modern configuration without touching the library, but just using build flags that are inserted as #define in the build process. Just as a reference, in the original includes I left commented the #define statements: [PIN config epdif.h](https://github.com/martinberlin/e-ink/blob/master/src/epdif.h) & [Display model eink.h](https://github.com/martinberlin/e-ink/blob/master/src/e_ink.h)

This is an example platformio.ini file for ESP32 but it can be used for ESP8266. Just copy and modify it for your project:

    ; Please visit documentation for the other options and examples:
    ; https://docs.platformio.org/page/projectconf.html
    [platformio]
    ; espressif8266  OR  lolin_d32
    default_envs = lolin_d32 
    [env:lolin_d32]
    platform = https://github.com/platformio/platform-espressif32.git
    board = lolin_d32
    framework = arduino
    monitor_speed = 115200
    build_flags =
      -DUSE_154_BW_GREEN=1
      -DRST_PIN=-1
      -DDC_PIN=27
      -DCS_PIN=32
      -DBUSY_PIN=-1
      -DCLK_PIN=18
      -DSDI_PIN=23
    
    lib_deps =
       https://github.com/martinberlin/e-ink.git

Please note that the display I used to test is: USE_154_BW_GREEN
Replace that for your own model to fit your needs. Make sure that the build variables need a value when are inserted like this so even if it should be empty use:

-DMYDEFINE=1

NOTE: In the file [select.h](https://github.com/martinberlin/e-ink/blob/master/src/select.h#L25) I noticed that there was an #if construction that was not letting my use my 1.54 display so I modified it and removed the part that was flawed, leaving it on the comments. If you use one of the displays that where left out, just arrange it to use the right Display_picture function or leave me a message and I will try to correct it. ( twitter: @martinfasani / www.cale.es )

## Contents

- [The Overview](#the-overview)
- [Installing](#installing)
- [Features](#features)

## The Overview
--------
- Arduino library for E-Ink display(1.54, 2.3, 2.9) made by HelTec Automation(TM)
- Now this library allows three sizes of e-ink to run on the "AVR" , "ESP32" , "ESP8266" development board.
- **Display size definition in "imagedata.h"**.

## Installing

Just add this line into your **platformio.ini** lib_deps variable: 

    lib_deps =
       https://github.com/martinberlin/e-ink.git



## Features

- Arduino library for E-Ink display(1.54, 2.3, 2.9).
- Consumes power only during refresh, power consumption as low as 24-30mW.
- Support for partial refresh, only takes 0.3s.

Please reference the [original Heltec library]((https://github.com/HelTecAutomation/e-ink) for pictures and buy links. This is just my intention to make a better job explaining how it works than Heltec did, hence I will try to display minimal information and just cover the parts that I felt where lacking explanations and make a more modern way to set it up.
As a developer I always felt frustrated when you need to touch the libraries itself to configure something. The role of a library is to do it's job and get out of the way. Configuration should be external, not touching the lib itself in the "Arduino old way" style. Welcome to 2020 dear Heltec, here I will try to bring the users of your Eink, a more detailed explanation of how to configurate and try your Einks since you did a bad job and this is open source so it's my right to do it.
 
## Issue/Bug report template

Before reporting an issue, make sure you've searched for similar one that was already created. Also make sure to go through all the issues labelled as [for reference](https://github.com/HelTecAutomation/e-ink/issues).     
