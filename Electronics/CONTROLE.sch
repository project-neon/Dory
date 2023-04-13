EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 4
Title "PLACA DORY"
Date "23/12/2021"
Rev "V2"
Comp "PROJECT NEON"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x12_Female J1
U 1 1 61C6F4C3
P 6700 2450
F 0 "J1" H 6728 2426 50  0000 L CNN
F 1 "Left Side_ Arduino Pro mini" H 6150 1650 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical" H 6700 2450 50  0001 C CNN
F 3 "~" H 6700 2450 50  0001 C CNN
	1    6700 2450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x12_Female J4
U 1 1 61C6F4C9
P 7800 2550
F 0 "J4" H 7950 2500 50  0000 C CNN
F 1 "Right Side_ Arduino Pro mini" H 7250 3150 50  0001 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical" H 7800 2550 50  0001 C CNN
F 3 "~" H 7800 2550 50  0001 C CNN
	1    7800 2550
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x06_Female J2
U 1 1 61C6F4CF
P 7250 1850
F 0 "J2" V 7096 2098 50  0000 L CNN
F 1 "Top Side_Promini Pro" V 7350 1500 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 7250 1850 50  0001 C CNN
F 3 "~" H 7250 1850 50  0001 C CNN
	1    7250 1850
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x03_Female J3
U 1 1 61C6F4D5
P 7450 3200
F 0 "J3" V 7388 3012 50  0000 R CNN
F 1 "Conn_01x03_Female" V 7297 3012 50  0001 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 7450 3200 50  0001 C CNN
F 3 "~" H 7450 3200 50  0001 C CNN
	1    7450 3200
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Female J5
U 1 1 61C6F4DB
P 7200 4050
F 0 "J5" H 7228 4026 50  0000 L CNN
F 1 "A4 and A5" H 7228 3935 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 7200 4050 50  0001 C CNN
F 3 "~" H 7200 4050 50  0001 C CNN
	1    7200 4050
	-1   0    0    1   
$EndComp
$Comp
L arduino:Arduino_Pro_Mini-1 U1
U 1 1 61C6F4FA
P 4150 3000
F 0 "U1" H 4100 2061 50  0000 C CNN
F 1 "Arduino_Pro_Mini-1" H 4100 1970 50  0001 C CNN
F 2 "BIBLIOTECA_FOGUETE:Arduino_Pro_Mini-1" V 4250 2950 50  0001 C CNN
F 3 "" V 4150 2900 50  0001 C CNN
	1    4150 3000
	1    0    0    -1  
$EndComp
Text HLabel 4700 2300 2    50   Input ~ 0
RAW
Text HLabel 4700 2400 2    50   Input ~ 0
GND
Text HLabel 4700 2500 2    50   Input ~ 0
RESET
Text HLabel 4700 2700 2    50   Output ~ 0
SCL
Text HLabel 4700 2800 2    50   BiDi ~ 0
SDA
Text HLabel 4700 2900 2    50   Output ~ 0
XSHUT1
Text HLabel 4700 3000 2    50   Output ~ 0
XSHUT2
Text HLabel 4700 3100 2    50   Input ~ 0
A1
Text HLabel 4700 3200 2    50   Input ~ 0
A0
Text HLabel 4700 3400 2    50   Input ~ 0
D12
Text HLabel 4700 3500 2    50   Input ~ 0
D11
Text HLabel 4700 3600 2    50   Output ~ 0
PWMA
Text HLabel 3500 2450 0    50   Output ~ 0
TXO
Text HLabel 3500 2550 0    50   Input ~ 0
RXI
Text HLabel 3500 2650 0    50   Input ~ 0
RESET
Text HLabel 3500 2750 0    50   Input ~ 0
GND
Text HLabel 3500 2850 0    50   Input ~ 0
IR_SENSOR
Text HLabel 3500 2950 0    50   Output ~ 0
D3
Text HLabel 3500 3050 0    50   Output ~ 0
AIN2
Text HLabel 3500 3150 0    50   Output ~ 0
AIN1
Text HLabel 3500 3250 0    50   Output ~ 0
STBY
Text HLabel 3500 3350 0    50   Output ~ 0
BIN1
Text HLabel 3500 3450 0    50   Output ~ 0
BIN2
Text HLabel 3500 3550 0    50   Output ~ 0
PWMB
Text HLabel 4000 2000 1    50   Output ~ 0
TXO
Text HLabel 4100 2000 1    50   Input ~ 0
RXI
Text HLabel 4300 2000 1    50   Input ~ 0
GND
Text HLabel 4400 2000 1    50   Input ~ 0
GND
Text HLabel 4250 3850 3    50   Input ~ 0
GND
Text HLabel 4350 3850 3    50   Input ~ 0
A6
Text HLabel 4450 3850 3    50   Input ~ 0
A7
Text HLabel 6500 1950 0    50   Output ~ 0
TXO
Text HLabel 6500 2050 0    50   Input ~ 0
RXI
Text HLabel 6500 2150 0    50   Input ~ 0
RESET
Text HLabel 6500 2250 0    50   Input ~ 0
GND
Text HLabel 6500 2350 0    50   Input ~ 0
IR_SENSOR
Text HLabel 6500 2450 0    50   Output ~ 0
D3
Text HLabel 6500 2550 0    50   Output ~ 0
AIN2
Text HLabel 6500 2650 0    50   Output ~ 0
AIN1
Text HLabel 6500 2750 0    50   Output ~ 0
STBY
Text HLabel 6500 2850 0    50   Output ~ 0
BIN1
Text HLabel 6500 2950 0    50   Output ~ 0
BIN2
Text HLabel 6500 3050 0    50   Output ~ 0
PWMB
Text HLabel 7050 1650 1    50   Output ~ 0
TXO
Text HLabel 7150 1650 1    50   Input ~ 0
RXI
Text HLabel 7350 1650 1    50   Input ~ 0
GND
Text HLabel 7450 1650 1    50   Input ~ 0
GND
Text HLabel 7350 3400 3    50   Input ~ 0
GND
Text HLabel 7450 3400 3    50   Input ~ 0
A6
Text HLabel 7550 3400 3    50   Input ~ 0
A7
Text HLabel 8000 1950 2    50   Input ~ 0
RAW
Text HLabel 8000 2050 2    50   Input ~ 0
GND
Text HLabel 8000 2150 2    50   Input ~ 0
RESET
Text HLabel 8000 2350 2    50   Output ~ 0
XSHUT1
Text HLabel 8000 2450 2    50   Output ~ 0
XSHUT2
Text HLabel 8000 2550 2    50   Input ~ 0
A1
Text HLabel 8000 2650 2    50   Input ~ 0
A0
Text HLabel 8000 2850 2    50   Input ~ 0
D12
Text HLabel 8000 2950 2    50   Input ~ 0
D11
Text HLabel 8000 3050 2    50   Output ~ 0
PWMA
Text HLabel 7400 3950 2    50   Output ~ 0
SCL
Text HLabel 7400 4050 2    50   BiDi ~ 0
SDA
Text Notes 3650 4250 0    50   ~ 0
CONEXÕES DO ARDUINO PRO-MINI
Text Notes 6700 4400 0    50   ~ 0
CONEXÕES DOS SOQUETES DA PLACA
Text GLabel 4700 3300 2    50   Output ~ 0
LED
Text GLabel 4700 2600 2    50   Output ~ 0
VCC
Text GLabel 4200 2000 1    50   Input ~ 0
VCC
Text GLabel 3900 2000 1    50   Input ~ 0
DTR
Text GLabel 6950 1650 1    50   Input ~ 0
DTR
Text GLabel 7250 1650 1    50   Input ~ 0
VCC
Text GLabel 8000 2250 2    50   Output ~ 0
VCC
Text GLabel 8000 2750 2    50   Output ~ 0
LED
$EndSCHEMATC
