Arduino-based Telescope Focuser
===============================

This project was made by merging two existing projects and some fixes and addition.
The main project from which it is forked is https://github.com/vehnae/arduino-focuser (you will find the original readme at the end of this one)
I take inspiraton from this other project https://github.com/fehlfarbe/arduino-motorfocus in order to add button, speed control, ... who were missing in the first one.

Schematics and PCB
==================
![Schematic_AduinoFocuser_2025-03-13](https://github.com/user-attachments/assets/93ae13da-de9a-4ada-832f-a5e5766c8caf)

![PCB_PCB_AduinoFocuser_2025-03-13](https://github.com/user-attachments/assets/a2e8e61d-a2ec-4294-aa1d-167a03e866d1)

![focuser2D](https://github.com/user-attachments/assets/fb0572a7-2c08-4f53-a2cf-47d2a6e20bac)

![focuser3D](https://github.com/user-attachments/assets/ff7312c3-7a0d-4195-a551-0f0fdea0850a)

Part list
=========
The links are given for reference, feel free to order where you want

1 Arduino nano V3 : https://fr.aliexpress.com/item/1005007539665675.html

1 motor driver DRV8825 : https://fr.aliexpress.com/item/1005006478108991.html choose the DRV8825

1 Nema 17 motor

2 mini push switches : https://fr.aliexpress.com/item/1005006713190412.html

1 10 microFarad capacitor to solder between RST and GND of the arduino nano (forgot it on the pcb, so add it) . This is for ascom to properly connect https://www.astroscopic.com/blog/disable-arduinos-auto-reset-connection

1 4,7 kOhm resistor


option : 1 temperature sensor DS18B20, ideally external, ie : https://fr.aliexpress.com/item/32305869288.html


Here is the original Readme
============================
This sketch implements telescope focuser controller logic for a stepper motor and a Pololu DRV8825 stepper driver board. The serial protocol is compatible with Moonlite focusers, so their ASCOM drivers and supporting software can be used.

Main features:
- Interrupt-driven motor control for fast and accurate operation (up to 1000 steps/s)
- Microstepping up to 1/32 steps
- Persistent settings and position. Position data is saved to EEPROM after every move

To use this controller, you should first connect your Arduino to the DRV8825 board as described in the Pololu's [DRV8825 product page](https://www.pololu.com/product/2133). If you want to use microstepping or have the driver shut down focuser power when not in use then connect also the remaining pins (ENABLE, M0, M1, M2). Finally, edit `Config.h` to set your pin mapping.

![DRV8825 wiring diagram](https://a.pololu-files.com/picture/0J4232.600.png)

Note: For the Moonlite ASCOM driver to work, you must add a 100uF capacitor to your Arduino between RST and GND to prevent the Arduino from rebooting when the serial connection is opened. Otherwise the ASCOM driver will time out and not detect your controller.

Differences to the Moonlite controller
--------------------------------------

The Moonlite driver has the option for selecting the focuser speed from 250 steps/s to 16 steps/s. In order to achieve the high speed of up to 1000 steps/s these values are multiplied by four by the controller.

The driver also has a selection for setting the microstepping mode to "full" or "half". The controller supports 1/1, 1/2, 1/4, 1/8, 1/16 and 1/32 step microstepping modes. Please edit the `Config.h` to select the microstepping modes that the Moonlite "full" and "half" commands should correspond to.

Focuser hold power
------------------

The sketch supports an extension to the Moonlite protocol to enable keeping the focuser continously powered. The hold power can be enabled with the Moonlite Single Channel Controller application that allows you to send arbitrary serial commands to the controller. To enable the hold power send the `HE` command. To disable it, use `HD`. The setting is saved in EEPROM so you need to do this only once.

When the hold power is enabled, the controller keeps the focuser continuously powered. The power is turned off only after no serial traffic is detected for 30 seconds. In this case the ASCOM driver is not connected so we deduce that the controller is not being used.

When the hold power is disabled, the focuser is powered before starting a move and turned off
slightly after a move has ended.
