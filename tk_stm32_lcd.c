#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "tk_stm32_lcd.h"
#include "stdio.h"
const uint16_t charR[2][12]={{0b0, 0b11111110000, 0b11111110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b11001110000, 0b11111100000, 0b01111000000, 0b0}, {0b0, 0b01111111000, 0b01111111000, 0b00000011000, 0b00000111000, 0b00001111000, 0b00011101000, 0b00111001000, 0b01110001000, 0b01100000000, 0b01100000000, 0b0}};
const uint16_t charP[2][12]={{0b0, 0b11111110000, 0b11111110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b11001110000, 0b11111100000, 0b01111000000, 0b0}, {0b0, 0b01111111000, 0b01111111000, 0b00000001000, 0b00000001000, 0b00000001000, 0b00000001000, 0b00000001000, 0b00000001000, 0b0,           0b0,           0b0}};
const uint16_t charM[2][12]={{0b0, 0b11111110000, 0b11111110000, 0b00111100000, 0b01110000000, 0b11100000000, 0b11100000000, 0b01110000000, 0b00111100000, 0b11111110000, 0b11111110000, 0b0}, {0b0, 0b01111111000, 0b01111111000, 0b0,           0b0,           0b00000001000, 0b00000001000, 0b0,           0b0,           0b01111111000, 0b01111111000, 0b0}};
const uint16_t charN[2][12]={{0b0, 0b11111110000, 0b11111110000, 0b01111100000, 0b11111000000, 0b11100000000, 0b11000000000, 0b0,           0b0,           0b11111110000, 0b11111110000, 0b0}, {0b0, 0b01111111000, 0b01111111000, 0b0000000,     0b0000000,     0b00000011000, 0b00000111000, 0b00011111000, 0b00111110000, 0b01111111000, 0b01111111000, 0b0}};
const uint16_t charG[2][12]={{0b0, 0b11111000000, 0b11111110000, 0b00001110000, 0b00000110000, 0b00000110000, 0b00000110000, 0b00000110000, 0b00001110000, 0b00011100000, 0b00011000000, 0b0}, {0b0, 0b00001111000, 0b00011111000, 0b00111000000, 0b01110000000, 0b01100000000, 0b01100011000, 0b01100011000, 0b01110011000, 0b00111111000, 0b00011111000, 0b0}};
const uint16_t charD[2][12]={{0b0, 0b11111110000, 0b11111110000, 0b00000110000, 0b00000110000, 0b00000110000, 0b00001110000, 0b00011110000, 0b00111100000, 0b11111000000, 0b11110000000, 0b0}, {0b0, 0b01111111000, 0b01111111000, 0b01100000000, 0b01100000000, 0b01100000000, 0b01110000000, 0b01111000000, 0b00111100000, 0b00011111000, 0b00001111000, 0b0}};
const uint16_t charS[2][12]={{0b0, 0b01111000000, 0b11111100000, 0b11001110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b00000110000, 0b00001110000, 0b00001100000, 0b00001000000, 0b0}, {0b0, 0b00011000000, 0b00111000000, 0b0110001000,  0b01100001000, 0b01100001000, 0b01100011000, 0b01100011000, 0b01110111000, 0b00111110000, 0b00011100000, 0b0}};
const uint16_t charT[2][12]={{0b0, 0b00000110000, 0b00000110000, 0b00000110000, 0b00000110000, 0b11111110000, 0b11111110000, 0b00000110000, 0b00000110000, 0b00000110000, 0b00000110000, 0b0}, {0b0, 0b0,           0b0,           0b0,           0b0,           0b01111111000, 0b01111111000, 0b0,           0b0,           0b0,           0b0,           0b0}};
const uint16_t charF[2][12]={{0b0, 0b11111110000, 0b11111110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b0}, {0b0, 0b01111111000, 0b01111111000, 0b00000001000, 0b00000001000, 0b00000001000, 0b00000001000, 0b00000001000, 0b00000001000, 0b00000001000, 0b00000001000, 0b0}};
const uint16_t charK[2][12]={{0b0, 0b11111110000, 0b11111110000, 0b11000000000, 0b11100000000, 0b01111000000, 0b00111000000, 0b00011100000, 0b00001110000, 0b00000110000, 0b00000010000, 0b0}, {0b0, 0b01111111000, 0b01111111000, 0b00000011000, 0b00000111000, 0b00001110000, 0b00011100000, 0b00111000000, 0b01110000000, 0b01100000000, 0b01000000000, 0b0}};

const uint16_t num0[2][12]={{0b0, 0b11100000000, 0b11111000000, 0b00011100000, 0b00001110000, 0b00000110000, 0b00000110000, 0b00001110000, 0b00011100000, 0b11111000000,  0b11100000000, 0b0}, {0b0, 0b00000111000, 0b00011111000, 0b00111000000, 0b01110000000, 0b01100000000, 0b01100000000, 0b01110000000, 0b00111000000, 0b00011111000, 0b00000111000, 0b0}};
const uint16_t num1[2][12]={{0b0, 0b00010000000, 0b00011000000, 0b00001100000, 0b00000110000, 0b11111110000, 0b11111110000, 0b0,           0b0,           0b0,           0b0,           0b0}, {0b0, 0b01100000000, 0b01100000000, 0b01100000000, 0b01100000000, 0b01111111000, 0b01111111000, 0b01100000000, 0b01100000000, 0b01100000000, 0b01100000000, 0b0}};
const uint16_t num2[2][12]={{0b0, 0b00011000000, 0b00011100000, 0b00001110000, 0b00000110000, 0b00000110000, 0b10000110000, 0b11000110000, 0b11101110000, 0b01111100000, 0b00111000000, 0b0}, {0b0, 0b01110000000, 0b01111000000, 0b01111100000, 0b01101110000, 0b01100111000, 0b01100011000, 0b01100001000, 0b01100000000, 0b01100000000, 0b01100000000, 0b0}};
const uint16_t num3[2][12]={{0b0, 0b00000110000, 0b00000110000, 0b00000110000, 0b00000110000, 0b10000110000, 0b11000110000, 0b11100110000, 0b10110110000, 0b00011110000, 0b00001110000, 0b0}, {0b0, 0b00110000000, 0b01110000000, 0b01110000000, 0b01100000000, 0b01100001000, 0b01100001000, 0b01100001000, 0b01110011000, 0b00111111000, 0b00011110000, 0b0}};
const uint16_t num4[2][12]={{0b0, 0b10000000000, 0b11000000000, 0b11100000000, 0b01110000000, 0b00111000000, 0b00011100000, 0b00001110000, 0b11111110000, 0b11111110000, 0b00000000000, 0b0}, {0b0, 0b00000011000, 0b00000011000, 0b00000011000, 0b00000011000, 0b00000011000, 0b00000011000, 0b00000011000, 0b01111111000, 0b01111111000, 0b00000011000, 0b0}};
const uint16_t num5[2][12]={{0b0, 0b11111110000, 0b11111110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b00000110000, 0b00000110000, 0b0}, {0b0, 0b01100001000, 0b01100001000, 0b01100001000, 0b01100001000, 0b01100001000, 0b01100001000, 0b01100001000, 0b01110011000, 0b00111111000, 0b00011110000, 0b0}};
const uint16_t num6[2][12]={{0b0, 0b11111000000, 0b11111100000, 0b10001110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10001110000, 0b00011100000, 0b00011000000, 0b0}, {0b0, 0b00011111000, 0b00111111000, 0b01110001000, 0b01100001000, 0b01100001000, 0b01100001000, 0b01100001000, 0b01110011000, 0b00111111000, 0b00011110000, 0b0}};
const uint16_t num7[2][12]={{0b0, 0b00011110000, 0b00011110000, 0b00000110000, 0b00000110000, 0b00000110000, 0b00000110000, 0b10000110000, 0b11000110000, 0b11111110000, 0b01111110000, 0b0}, {0b0, 0b0,           0b0,           0b0,           0b0,           0b01111110000, 0b01111111000, 0b00000011000, 0b00000001000, 0b0,           0b0,           0b0}};
const uint16_t num8[2][12]={{0b0, 0b01111000000, 0b11111100000, 0b11001110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b11001110000, 0b11111100000, 0b01111000000, 0b0}, {0b0, 0b00011110000, 0b00111111000, 0b01110011000, 0b01100001000, 0b01100001000, 0b01100001000, 0b01100001000, 0b01110011000, 0b00111111000, 0b00011110000, 0b0}};
const uint16_t num9[2][12]={{0b0, 0b01111000000, 0b11111100000, 0b11001110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10000110000, 0b10001110000, 0b11111100000, 0b11111000000, 0b0}, {0b0, 0b00011000000, 0b00111000000, 0b01110000000, 0b01100001000, 0b01100001000, 0b01100001000, 0b01100001000, 0b01110001000, 0b00111111000, 0b00011111000, 0b0}};
const uint16_t rom3[2][12]={{0b0, 0b11111110000, 0b11111110000, 0b0,           0b0,           0b11111110000, 0b11111110000, 0b0,           0b0,           0b11111110000, 0b11111110000, 0b0}, {0b0, 0b01111111000, 0b01111111000, 0b0,           0b0,           0b01111111000, 0b01111111000, 0b0,           0b0,           0b01111111000, 0b01111111000, 0b0}};
const uint16_t space[2][12]={{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
const uint16_t logotl[64]={0,0,0,0,0,0,0,0,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0b11000000000,0,0,0,0,0b10000000000,0b11000000000,0b11000000000,0b10000000000,0,0,0,0,0,0b11000000000,0b11000000000,0b10000000000,0,0,0,0,0,0,0,0b10000000000,0b11000000000,0b11000000000,0,0,0,0b11000011000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b11000111000};
const uint16_t logotr[64]={0b11000000000,0b11001000000,0b11001100000,0b11001110000,0b01001111000,0b00001111000,0b00001111000,0b00000111000,0b00000011000,0b00000001000,0,0b10000000000,0b11000000000,0b11000000000,0b11001000000,0b11001100000,0b11001110000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b11001000000,0,0,0,0b10001000000,0b11001110000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b01001110000,0b00001100000,0,0b00001100000,0b00001111000,0b00001111000,0b10001111000,0b11001111000,0b11001111000,0b11001111000,0b11001111000,0b01001111000,0b00001111000,0b00001111000,0b00001111000,0b00001111000,0b00000011000,0,0,0,0,0,0,0};
const uint16_t logobl[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0b11111111000,0b11111111000,0,0,0,0,0,0b11111111000,0b11111111000,0b11001100000,0b11001100000,0b11001100000,0b11001100000,0b11001100000,0b11001100000,0b11001100000,0b11000000000,0b11110000000,0b01111100000,0b00011111000,0b00000111000,0b00000001000,0b00000001000,0b00000111000,0b00011111000,0b01111100000,0b11110000000,0b11000000000,0,0b11111111000,0b11111111000,0b00000111000,0b00001110000,0b00111100000,0b11110000000,0b11000000000,0b11110000000,0b00111100000,0b00001110000,0b00000111000,0b11111111000,0b11111111000,0,0b11000000000,0b11111100000,0b11111111000,0b11111111000,0b11111111000,0b00011111000,0b00000011000,0b00001111000};
const uint16_t logobr[64]={0b01111111000,0b11111111000,0b11111111000,0b11111100000,0b11110000000,0b11000000000,0b11000000000,0b11100000000,0b11110000000,0b11111100000,0b11111110000,0b11111111000,0b01111111000,0b00011111000,0b00001111000,0b00000011000,0b00000011000,0b00000011000,0b00000011000,0b00111111000,0b11111111000,0b11111111000,0b11111111000,0b11111110000,0b11000000000,0b11111000000,0b11111111000,0b11111111000,0b11111111000,0b00111111000,0b00000011000,0b00000011000,0b00000011000,0b00000011000,0b11100011000,0b11111111000,0b11111111000,0b11111111000,0b01111111000,0b00001100000,0,0,0,0,0,0b11110000000,0b11111111000,0b11111111000,0b11111111000,0b01111111000,0b00000011000,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint16_t counter[8]={0x0,0x0008,0x0010,0x0018,0x0020,0x0028,0x0030,0x0038};
uint16_t Ycount[8]={0b1000000,0b010000000,0b11000000,0b100000000,0b101000000,0b110000000,0b111000000};
uint16_t trackY=0;
void comparechar(char A,  uint16_t Page)
{
	switch(A){
	case '1': Displaycont(num1,Page);
		break;
	case '2': Displaycont(num2,Page);
		break;
	case '3': Displaycont(num3,Page);
		break;
	case '4': Displaycont(num4,Page);
		break;
	case '5': Displaycont(num5,Page);
		break;
	case '6': Displaycont(num6,Page);
		break;
	case '7': Displaycont(num7,Page);
		break;
	case '8': Displaycont(num8,Page);
		break;
	case '9': Displaycont(num9,Page);
		break;
	case '0': Displaycont(num0,Page);
		break;
}
}
void delay()
{
	int i;
	for(i=0;i<100;i++)
	{
	}
}
void initializeLED()
{
	GPIO_InitTypeDef GPIO_InitStruct;

	    /* Clock for GPIOD */
	    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	    /* Set pins */
	    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4 | GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9 | GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;
	    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	    GPIO_Init(GPIOE, &GPIO_InitStruct);
	    GPIO_SetBits(GPIOE,GPIO_Pin_13);
}
void DisplayOn()
{
    GPIO_SetBits(GPIOE, GPIO_Pin_3);
    GPIO_SetBits(GPIOE, GPIO_Pin_4);
    GPIO_SetBits(GPIOE, GPIO_Pin_5);
    GPIO_SetBits(GPIOE, GPIO_Pin_6);
    GPIO_SetBits(GPIOE, GPIO_Pin_7);
    GPIO_SetBits(GPIOE, GPIO_Pin_8);

    GPIO_SetBits(GPIOE, GPIO_Pin_2);
  delay();					//Display On

    GPIO_ResetBits(GPIOE,GPIO_Pin_2);
    delay();
    GPIO_ResetBits(GPIOE,GPIO_Pin_3);
    GPIO_ResetBits(GPIOE,GPIO_Pin_4);
    GPIO_ResetBits(GPIOE,GPIO_Pin_5);
    GPIO_ResetBits(GPIOE,GPIO_Pin_6);
    GPIO_ResetBits(GPIOE,GPIO_Pin_7);
    GPIO_ResetBits(GPIOE,GPIO_Pin_8);
}
void clearscr(int n)
{
	int i,k;
	chipselect(n);
	DisplayOn();
	SetY(0);
	for(k=0;k<8;k++)
	{
	SetPage(counter[k]);

	//StartLine(0);
	for(i=0;i<64;i++)
	{
	DisplayData(0);
	}
	}
}
void chipselect(int n){
	switch(n){
	case 1: GPIO_SetBits(GPIOE,GPIO_Pin_11);
			GPIO_ResetBits(GPIOE,GPIO_Pin_12);
			break;
	case 2: GPIO_SetBits(GPIOE,GPIO_Pin_12);
			GPIO_ResetBits(GPIOE,GPIO_Pin_11);
			break;
	case 3: GPIO_SetBits(GPIOE,GPIO_Pin_11);
	GPIO_SetBits(GPIOE,GPIO_Pin_12);
	break;
}
}
void SetY(uint16_t Ypin)  // Default 14
{
	trackY=Ypin;
	GPIO_SetBits(GPIOE, GPIO_Pin_9);
 if(Ypin >0 )
 {
 GPIO_SetBits(GPIOE, Ypin);}
 else {
 GPIO_ResetBits(GPIOE,GPIO_Pin_3);
 GPIO_ResetBits(GPIOE,GPIO_Pin_4);
 GPIO_ResetBits(GPIOE,GPIO_Pin_5);
 GPIO_ResetBits(GPIOE,GPIO_Pin_6);
 GPIO_ResetBits(GPIOE,GPIO_Pin_7);
 GPIO_ResetBits(GPIOE,GPIO_Pin_8);
 }
 GPIO_SetBits(GPIOE, GPIO_Pin_2);
delay();
     GPIO_ResetBits(GPIOE,GPIO_Pin_2);
 delay();

	if(Ypin>0){
	GPIO_ResetBits(GPIOE, Ypin);}
	GPIO_ResetBits(GPIOE,GPIO_Pin_9);
}
void SetPage(uint16_t Pagepins)
{
	GPIO_SetBits(GPIOE, GPIO_Pin_6);
		    GPIO_SetBits(GPIOE, GPIO_Pin_7);
		    GPIO_SetBits(GPIOE, GPIO_Pin_8);
		    GPIO_SetBits(GPIOE, GPIO_Pin_10);
		    if(Pagepins >0 )
		    {
		    GPIO_SetBits(GPIOE, Pagepins);}
		    else {
		    GPIO_ResetBits(GPIOE,GPIO_Pin_3);
		    GPIO_ResetBits(GPIOE,GPIO_Pin_4);
		    GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		    }
		    GPIO_SetBits(GPIOE, GPIO_Pin_2);
		    delay();
		        GPIO_ResetBits(GPIOE,GPIO_Pin_2);
		   delay();

			if (Pagepins >0){
			GPIO_ResetBits(GPIOE,Pagepins);}
			GPIO_ResetBits(GPIOE,GPIO_Pin_6);
			GPIO_ResetBits(GPIOE,GPIO_Pin_7);
			GPIO_ResetBits(GPIOE,GPIO_Pin_8);
			GPIO_ResetBits(GPIOE,GPIO_Pin_10);
}
void StartLine(uint16_t StartPins)
{
	GPIO_SetBits(GPIOE, GPIO_Pin_9);
						GPIO_SetBits(GPIOE, GPIO_Pin_10);
						if(StartPins >0 ){
						GPIO_SetBits(GPIOE, StartPins);}
						else {
							  GPIO_ResetBits(GPIOE,GPIO_Pin_3);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_4);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_5);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_6);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_7);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_8);
						}
						GPIO_SetBits(GPIOE, GPIO_Pin_2);
						delay();
						    GPIO_ResetBits(GPIOE,GPIO_Pin_2);
						    delay();

						if (StartPins >0){
						GPIO_ResetBits(GPIOE, StartPins);}
						GPIO_ResetBits(GPIOE,GPIO_Pin_9);
						GPIO_ResetBits(GPIOE,GPIO_Pin_10);
}
void DisplayData(uint16_t DisplayPins)
{

						if(DisplayPins >0){
						GPIO_SetBits(GPIOE,DisplayPins);}
						else {
							  GPIO_ResetBits(GPIOE,GPIO_Pin_3);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_4);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_5);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_6);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_7);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_8);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_9);
								        GPIO_ResetBits(GPIOE,GPIO_Pin_10);
						}
						GPIO_SetBits(GPIOE,GPIO_Pin_0);
						GPIO_SetBits(GPIOE, GPIO_Pin_2);
						delay();
						    GPIO_ResetBits(GPIOE,GPIO_Pin_2);
						    delay();
						GPIO_ResetBits(GPIOE,GPIO_Pin_0);
						if(DisplayPins>0){
						GPIO_ResetBits(GPIOE,DisplayPins);}

}
void Displaychar(const uint16_t CharDisplay[][12], uint16_t Page, uint16_t setY)
{
int i;
SetY(setY);
StartLine(0);
SetPage(Page);
for(i=0;i<12;i++)
{
	DisplayData(CharDisplay[0][i]);
	delay();
}
SetY(setY);
StartLine(0);
SetPage(Page+8);
for(i=0;i<12;i++)
{
	DisplayData(CharDisplay[1][i]);
	delay();
}
}
void Displaycont(const uint16_t CharDisplay[][12], uint16_t Page)
{
	int i;
	StartLine(0);
	SetPage(Page);
	for(i=0;i<12;i++)
	{
		DisplayData(CharDisplay[0][i]);
		delay();
	}
	SetY(trackY);
	trackY=trackY+0b1100000;
	SetPage(Page+8);
	for(i=0;i<12;i++)
	{
		DisplayData(CharDisplay[1][i]);
		delay();
	}
}
void Mode1setup()
{

	chipselect(1);
	Displaychar(charR,0,0);
	Displaychar(charP,0,0b1100000);
	Displaychar(charM,0,0b11000000);
	Displaychar(charS,16,0);
	Displaychar(charP,16,0b1100000);
	Displaychar(charD,16,0b11000000);
	Displaychar(charG,32,0);
	Displaychar(charT,48,0);
	chipselect(2);

	Displaychar(charF,48,0);
}
void ModeLogo()
{
	int i;
	chipselect(1);
	SetPage(24);
	for(i=0;i<64;i++)
		{
			DisplayData(logotl[i]);
			delay();
		}
	SetPage(32);
	for(i=0;i<64;i++)
			{
				DisplayData(logobl[i]);
				delay();
			}

	chipselect(2);
	SetPage(24);
	for(i=0;i<64;i++)
			{
				DisplayData(logotr[i]);
				delay();
			}
	SetPage(32);
	for(i=0;i<64;i++)
			{
				DisplayData(logobr[i]);
				delay();
			}
	for(i=0;i<1000000;i++)
	 {}
chipselect(1);
Displaychar(charK,48,0b110010000);
chipselect(2);
Displaychar(num3,48,0);
for(i=0;i<10000000/5;i++)
 {}

}
void printrpm(uint16_t rpm)
{
	int j;
	char str[5];
	sprintf(str,"%5d",rpm);
	chipselect(2);
	SetY(0b0);
	SetPage(8);
	for(j=0;j<5;j++)
	{
		comparechar(str[j],8);
	}
	SetY(0b0);
	SetPage(0b0);
	int i;
	for(i=0;i<rpm;i=i+256)
		DisplayData(0b11111111000);
	for(i=rpm;i<16384;i=i+256)
		DisplayData(0b0);
}
void printfuel(uint16_t fuel)
{
	chipselect(2);
	SetY(0b1100000);
	SetPage(56);
	int i;
	for(i=0;i<fuel;i=i+1024)
			DisplayData(0b11111111000);
		for(i=fuel;i<52*1024;i=i+1024)
			DisplayData(0b0);
}
void printspd(uint16_t spd)
{
	int j;
		char str[2];
		sprintf(str,"%2d",spd);
		chipselect(1);
		SetY(0b100100000);
		SetPage(16);
		for(j=0;j<2;j++)
		{
			comparechar(str[j],16);
		}
}
void printtemp(uint16_t tmp)
{
	int j;
			char str[2];
			sprintf(str,"%2d",tmp);
			chipselect(1);
			SetY(0b11000000);
			SetPage(48);
			for(j=0;j<2;j++)
			{
				comparechar(str[j],48);
			}
}
void printgear(uint16_t gear)
{
char g[1];
sprintf(g,"%1d",gear);
chipselect(1);
SetY(0b100100000);
SetPage(32);
comparechar(g[0],32);
if(g[0]==0)
{
	chipselect(2);
	Displaychar(charN,32,0b110000000);
}
}