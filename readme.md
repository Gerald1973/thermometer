# Thermometer

## Description

This time, I developed an application for the micro controller Raspberry Pi Pico RP2040.  During this little development, thanks to the documentation provided by the Raspberry foundation, I didn't encounter any problem.  I  had only one problem with the deployment on the micro controller, because the combination line breadboard can give some trouble during the communication between the computer and the controller. So, I directly plugged the line from the debugging port to the Raspberry  Pi400.  And the problem was solved, used with Microsoft Visual Studio Code, it's a very good and efficient couple ;-).

This application as suggested by its name is a thermometer with the temperature displayed on the 7 segments panel 5641 BS, a set of 4 7 segments with decimal point. As this electronic component is an anode common component, we need to reverse the voltage on the output of the display, else we will have no potential difference so no light.  The code is very simple to understand.

### Prerequisite

The Raspberry PI Pico C/C++ SDK:  
<https://datasheets.raspberrypi.org/pico/raspberry-pi-pico-c-sdk.pdf>  
<https://github.com/raspberrypi/pico-sdk>

### Documentation

### View log debug

```bash
sudo minicom -b 115200 -o -D /dev/ttyACM0
```

### Reminder debug pins connection to the raspberry

***If you experience some connection problem, verify that your Raspberry Pi Pico is connected directly to your Raspberry Pi, not the breadboard.***

| Raspberry Pi     | Raspberry Pi Pico |
|------------------|-------------------|
| GND (pin 20)     | SWD GND           |
| GPIO 24 (pin 18) | SWDIO             |
| GPIO 25 (pin 22) | SWCLK             |

#### Connection from 7 segments to the Raspberry Pi Pico

| 7 segments (pin) | LED      | GPIO on the RP2040 |
|-----------------:|----------|-------------------:|
|   1              |  E       |  4                 |
|   2              |  D       |  5                 |
|   3              |  DP      |  6                 |
|   4              |  C       |  7                 |
|   5              |  G       |  8                 |
|   6              |  Digit 4 |  0                 |
|   7              |  B       |  9                 |
|   8              |  Digit 3 |  1                 |
|   9              |  Digit 2 |  2                 |
|  10              |  F       | 10                 |
|  11              |  A       | 11                 |
|  12              |  Digit 1 | 12                 |

#### One led description

```led
       A
     #####
    #     #
    #     #
    #F    #B
    #     #
    #  G  #
     #####
    #     #
    #     #
    #E    #C
    #     #
    #  D  #
     #####  #DP
```

The resistance between every LED and the GPIO is 220 Ohms.  
For more information look for the data sheet of the 5641 BS, for example:  
<https://datasheetspdf.com/pdf/1258365/FORYARD/FYQ-5641BS-21/1>
