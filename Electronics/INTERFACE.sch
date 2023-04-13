EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
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
L Connector:Conn_01x02_Male J11
U 1 1 61C992A7
P 5650 3850
F 0 "J11" H 5450 3800 50  0000 L CNN
F 1 "BLUETOOTH" H 5600 3650 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5650 3850 50  0001 C CNN
F 3 "~" H 5650 3850 50  0001 C CNN
	1    5650 3850
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 61C992AE
P 5250 4050
F 0 "R1" H 5320 4096 50  0000 L CNN
F 1 "1kΩ" H 5320 4005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5180 4050 50  0001 C CNN
F 3 "~" H 5250 4050 50  0001 C CNN
	1    5250 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 61C992B4
P 5250 4450
F 0 "R2" H 5320 4496 50  0000 L CNN
F 1 "2kΩ" H 5320 4405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5180 4450 50  0001 C CNN
F 3 "~" H 5250 4450 50  0001 C CNN
	1    5250 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 4250 5250 4250
Wire Wire Line
	5250 4250 5250 4300
Wire Wire Line
	5250 4200 5250 4250
Connection ~ 5250 4250
Wire Wire Line
	5250 3900 5250 3850
Wire Wire Line
	5250 3850 5450 3850
Wire Wire Line
	5250 4600 5250 4700
$Comp
L Connector:Conn_01x06_Male J12
U 1 1 61C992C7
P 5650 1100
F 0 "J12" H 5622 982 50  0000 R CNN
F 1 "Conn_01x06_Male" H 5622 1073 50  0001 R CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-06A_1x06_P2.54mm_Vertical" H 5650 1100 50  0001 C CNN
F 3 "~" H 5650 1100 50  0001 C CNN
	1    5650 1100
	-1   0    0    1   
$EndComp
NoConn ~ 5450 1200
$Comp
L Connector:Conn_01x06_Male J13
U 1 1 61C992D2
P 5650 1850
F 0 "J13" H 5622 1732 50  0000 R CNN
F 1 "Conn_01x06_Male" H 5622 1823 50  0001 R CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-06A_1x06_P2.54mm_Vertical" H 5650 1850 50  0001 C CNN
F 3 "~" H 5650 1850 50  0001 C CNN
	1    5650 1850
	-1   0    0    1   
$EndComp
NoConn ~ 5450 1950
$Comp
L Connector:Conn_01x03_Female J14
U 1 1 61C992DA
P 5650 3250
F 0 "J14" H 5678 3276 50  0000 L CNN
F 1 "Conn_01x03_Female" H 5678 3185 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 5650 3250 50  0001 C CNN
F 3 "~" H 5650 3250 50  0001 C CNN
	1    5650 3250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Male J15
U 1 1 61C992E4
P 5650 2650
F 0 "J15" H 5622 2532 50  0000 R CNN
F 1 "Conn_01x06_Male" H 5622 2623 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 5650 2650 50  0001 C CNN
F 3 "~" H 5650 2650 50  0001 C CNN
	1    5650 2650
	-1   0    0    1   
$EndComp
Text HLabel 4350 800  0    50   Input ~ 0
+5V
Text HLabel 4350 900  0    50   Input ~ 0
GND
Text HLabel 4350 1000 0    50   Input ~ 0
SCL
Text HLabel 4350 1100 0    50   BiDi ~ 0
SDA
Text HLabel 5450 1300 0    50   Input ~ 0
XSHUT2
Text HLabel 5450 2050 0    50   Input ~ 0
XSHUT1
Text HLabel 5450 2250 0    50   Output ~ 0
RESET
Text HLabel 5450 2350 0    50   Output ~ 0
D3
Text HLabel 5450 2450 0    50   Output ~ 0
A1
Text HLabel 5450 2550 0    50   Output ~ 0
A0
Text HLabel 5450 2650 0    50   Output ~ 0
D12
Text HLabel 5450 2750 0    50   Output ~ 0
D11
Text HLabel 5450 2850 0    50   Output ~ 0
A7
Text HLabel 5450 2950 0    50   Output ~ 0
A6
Text HLabel 5450 3350 0    50   Output ~ 0
IR_SENSOR
Text HLabel 5450 3750 0    50   Output ~ 0
RXI
Wire Wire Line
	5450 1000 5050 1000
Wire Wire Line
	5450 1100 4950 1100
Wire Wire Line
	5450 1750 5050 1750
Wire Wire Line
	5050 1750 5050 1000
Connection ~ 5050 1000
Wire Wire Line
	5050 1000 4350 1000
Wire Wire Line
	5450 1850 4950 1850
Wire Wire Line
	4950 1850 4950 1100
Connection ~ 4950 1100
Wire Wire Line
	4950 1100 4350 1100
Wire Wire Line
	5450 1550 4750 1550
Wire Wire Line
	4750 1550 4750 800 
Wire Wire Line
	4750 800  4350 800 
Wire Wire Line
	5450 1650 4500 1650
Wire Wire Line
	4500 1650 4500 900 
Wire Wire Line
	4500 900  4350 900 
Wire Wire Line
	5450 800  4750 800 
Connection ~ 4750 800 
Wire Wire Line
	5450 900  4500 900 
Connection ~ 4500 900 
Wire Wire Line
	5450 3150 4500 3150
Wire Wire Line
	4500 3150 4500 1650
Connection ~ 4500 1650
Wire Wire Line
	5450 3250 4750 3250
Wire Wire Line
	4750 3250 4750 1550
Connection ~ 4750 1550
Wire Wire Line
	4500 4700 4500 3150
Wire Wire Line
	4500 4700 5250 4700
Connection ~ 4500 3150
Text HLabel 5150 4250 0    50   Input ~ 0
TXO
Text Notes 5550 4250 0    50   ~ 0
COMUNICAÇÃO BLUETOOTH
Text Notes 5700 3400 0    50   ~ 0
SENSOR INFRA VERMELHO
Text Notes 5750 2750 0    50   ~ 0
CONEXÕES DO ARDUINO PRO-MINI
Text Notes 5750 1950 0    50   ~ 0
SENSOR DE DISTÂNCIA 1
Text Notes 5750 1200 0    50   ~ 0
SENSOR DE DISTÂNCIA 2
$EndSCHEMATC
