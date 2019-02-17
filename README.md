Attiny13 Servo Tester
==========

Servo tester using cheap attiny13.

## Code

Code is written in arduino language. Use Arduino IDE to `Attiny13ServoTester.ino` into your MCU.

## Schematic & PCB

Schematic and PCB are created using kicad. All files necessary for kicad are stored in `kicad` directory.

## Modes

Tester has multiple modes:

 - *Potentiometer mode* - servo position is controlled by potentiometer and leds `LED_MIN` and `LED_MAX` light up when minimal or maximal position is reached.
 - *Auto mode* - servo tester sets up position automatically from 0° to 180° and from 180° to 0°.
 - *90° mode* - position is whole time at 90°

## ToDo

 - complete all modes
 - add mode change led signalisation
 - cleanup code
