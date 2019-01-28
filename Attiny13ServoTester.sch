EESchema Schematic File Version 4
LIBS:Attiny13ServoTester-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATtiny:ATtiny13A-SSU U1
U 1 1 5C40FF33
P 4150 3800
F 0 "U1" H 3620 3846 50  0000 R CNN
F 1 "ATtiny13A-SSU" H 3620 3755 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 4150 3800 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc8126.pdf" H 4150 3800 50  0001 C CNN
	1    4150 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5C4B7DF5
P 5350 3350
F 0 "D1" H 5341 3566 50  0000 C CNN
F 1 "LED" H 5341 3475 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 5350 3350 50  0001 C CNN
F 3 "~" H 5350 3350 50  0001 C CNN
	1    5350 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 3500 5200 3350
Wire Wire Line
	4750 3500 5200 3500
Wire Wire Line
	5500 3350 5500 3600
Wire Wire Line
	5500 3600 4750 3600
$EndSCHEMATC
