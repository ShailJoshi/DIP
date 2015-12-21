#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
//Pin0  RS
//Pin1  RW
//Pin2  enable
//Pin3  DB0
//Pin4  DB1
//Pin5  DB2
//Pin6  DB3
//Pin7  DB4
//Pin8  DB5
//Pin9  DB6
//Pin10 DB7
//Pin11 CS1
//Pin12  CS2
//Pin13  reset


// #define numbers and chars

void initializeLED();
void DisplayOn();
void clearscr(int n);
void chipselect(int n);
void Mode1setup();
void ModeLogo();
void delay();

void SetY(uint16_t Ypin);
void SetPage(uint16_t Pagepins);
void StartLine(uint16_t StartPins);
void DisplayData(uint16_t DisplayPins);
void Displaychar(const uint16_t CharDisplay[][12], uint16_t Page, uint16_t SetY);
void Displaycont(const uint16_t CharDisplay[][12], uint16_t Page);
void printrpm(uint16_t rpm);
void printspd(uint16_t spd);
void printgear(uint16_t gear);
void printfuel(uint16_t fuel);
void printtemp(uint16_t tmp);
