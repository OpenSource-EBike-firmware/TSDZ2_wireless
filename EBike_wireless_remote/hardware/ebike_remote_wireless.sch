EESchema Schematic File Version 4
EELAYER 30 0
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
NoConn ~ 3800 8100
$Comp
L Switch:SW_Push button_1
U 1 1 5F4A3714
P 2650 3000
F 0 "button_1" H 2650 3200 50  0000 C CNN
F 1 "UP" H 2650 3300 50  0000 C CNB
F 2 "" H 2650 3200 50  0001 C CNN
F 3 "~" H 2650 3200 50  0001 C CNN
	1    2650 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 3000 2450 3000
Wire Wire Line
	3150 3900 4050 3900
Connection ~ 2300 4000
Wire Wire Line
	2300 4000 2450 4000
$Comp
L Switch:SW_Push button_3
U 1 1 5F4A4B3B
P 2650 4000
F 0 "button_3" H 2650 4200 50  0000 C CNN
F 1 "ENTER" H 2650 4300 50  0000 C CNB
F 2 "" H 2650 4200 50  0001 C CNN
F 3 "~" H 2650 4200 50  0001 C CNN
	1    2650 4000
	1    0    0    -1  
$EndComp
Connection ~ 2300 3500
Wire Wire Line
	2300 4000 2300 3500
Wire Wire Line
	2300 3500 2300 3000
Wire Wire Line
	2300 3500 2450 3500
$Comp
L Switch:SW_Push button_2
U 1 1 5F4A3F33
P 2650 3500
F 0 "button_2" H 2650 3700 50  0000 C CNN
F 1 "DOWN" H 2650 3800 50  0000 C CNB
F 2 "" H 2650 3700 50  0001 C CNN
F 3 "~" H 2650 3700 50  0001 C CNN
	1    2650 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 4000 3000 4000
Wire Wire Line
	3000 4000 3000 3800
Wire Wire Line
	3000 3800 4050 3800
Wire Wire Line
	4050 3700 3000 3700
Wire Wire Line
	3000 3700 3000 3500
Wire Wire Line
	3000 3500 2850 3500
Wire Wire Line
	2850 3000 3150 3000
Wire Wire Line
	3150 3000 3150 3600
Wire Wire Line
	3150 3600 4050 3600
Wire Notes Line
	2150 2550 3500 2550
Wire Notes Line
	3500 2550 3500 4800
Wire Notes Line
	3500 4800 2150 4800
Wire Notes Line
	2150 2550 2150 4800
Text Notes 4250 2900 0    79   ~ 0
(wireless board)
Text Notes 7550 3450 0    79   ~ 0
Connector to flash the bootloader.\nYou will need it only once, so you\ncan remove the wires after flashing.
Text Notes 2350 2500 0    79   ~ 0
VLCD5 handlebar\nremote keypad
$Comp
L Wireless_eBike:Nordic_nRF52840_USB_Dongle U?
U 1 1 600AD575
P 4750 3950
F 0 "U?" H 4750 4987 60  0001 C CNN
F 1 "Nordic nRF52840 USB Dongle" H 4750 4900 60  0000 C CNN
F 2 "" H 4600 3800 60  0000 C CNN
F 3 "" H 4600 3800 60  0000 C CNN
	1    4750 3950
	1    0    0    -1  
$EndComp
Wire Notes Line
	6000 4050 6000 3400
Wire Notes Line
	6000 3400 6750 3400
Text Notes 5900 3350 0    79   ~ 0
should work for\nat least 2 years
$Comp
L Device:Battery_Cell coincell
U 1 1 600B4826
P 6450 3800
F 0 "coincell" V 6300 3850 50  0001 C CNN
F 1 "CR2032 coin cell" H 6380 4130 50  0000 C CNN
F 2 "" V 6450 3860 50  0001 C CNN
F 3 "~" V 6450 3860 50  0001 C CNN
	1    6450 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 4500 3150 4500
Wire Wire Line
	2300 4500 2300 4000
Wire Wire Line
	3150 4500 3150 3900
Wire Wire Line
	2450 4500 2300 4500
$Comp
L Switch:SW_Push button_4
U 1 1 5F4A4B45
P 2650 4500
F 0 "button_4" H 2650 4700 50  0000 C CNN
F 1 "POWER" H 2650 4800 50  0000 C CNB
F 2 "" H 2650 4700 50  0001 C CNN
F 3 "~" H 2650 4700 50  0001 C CNN
	1    2650 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 4500 2300 4650
Wire Wire Line
	2300 4650 3350 4650
Wire Wire Line
	3350 4650 3350 4500
Wire Wire Line
	3350 4500 4050 4500
Connection ~ 2300 4500
Wire Notes Line
	6750 3400 6750 4050
Wire Notes Line
	6000 4050 6750 4050
NoConn ~ 4050 4000
NoConn ~ 4050 4100
NoConn ~ 4050 4200
NoConn ~ 4050 4300
NoConn ~ 4050 4400
NoConn ~ 5450 4400
NoConn ~ 5450 4300
NoConn ~ 5450 4200
NoConn ~ 5450 4100
NoConn ~ 5450 4000
NoConn ~ 5450 3900
Text Label 7550 3700 0    60   ~ 0
GND
Text Label 7550 3900 0    60   ~ 0
SWDIO
Text Label 7550 3800 0    60   ~ 0
SWDCLK
Text Label 5750 3450 2    60   ~ 0
SWDCLK
Text Label 5750 4500 2    60   ~ 0
GND
Text Label 3850 3450 0    60   ~ 0
SWDIO
Wire Notes Line style solid rgb(255, 114, 0)
	4200 3450 3850 3450
Wire Notes Line style solid rgb(255, 114, 0)
	5750 3450 5300 3450
Wire Notes Line style solid rgb(255, 114, 0)
	5750 4500 5450 4500
Wire Notes Line style solid rgb(255, 114, 0)
	7950 3700 7550 3700
Wire Notes Line style solid rgb(255, 114, 0)
	7950 3800 7550 3800
Wire Notes Line style solid rgb(255, 114, 0)
	7950 3900 7550 3900
Wire Wire Line
	5450 3800 6250 3800
Wire Wire Line
	6250 3700 6250 3550
Wire Wire Line
	6250 3550 6450 3550
Wire Wire Line
	6450 3550 6450 3600
Wire Wire Line
	5450 3700 6250 3700
Wire Wire Line
	6250 3800 6250 3950
Wire Wire Line
	6250 3950 6450 3950
Wire Wire Line
	6450 3950 6450 3900
$Comp
L Connector_Generic:Conn_01x03 J?
U 1 1 600C2D4C
P 8150 3800
F 0 "J?" H 8230 3842 50  0001 L CNN
F 1 "Bootloader flash" V 8300 3450 50  0000 L CNN
F 2 "" H 8150 3800 50  0001 C CNN
F 3 "~" H 8150 3800 50  0001 C CNN
	1    8150 3800
	1    0    0    -1  
$EndComp
NoConn ~ 5450 3600
$EndSCHEMATC
