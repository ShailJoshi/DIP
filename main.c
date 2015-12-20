#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "tk_usart.h"
#include "tm_stm32f4_adc.h"
#include "stdio.h"
#include "tk_lcd.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_disco.h"
#include "tm_stm32f4_fatfs.h"
#include <string.h>
#include <fatfs_sd_sdio.h>
int main(void)
{
	char str[25];
 GPIOInitialize();
 UART_Initialize();
 //NVICInitialize();
 USART_puts("sup man this is awesome\n\r");
 initializeLED();
 DisplayOn();
 clearscr(3);
 chipselect(3);
 ModeLogo();
 Mode1setup();
 //Fatfs object
 		    FATFS FatFs;
 		    //File object
 		    FIL fil;
 		    //Free and total space
 		    uint32_t total, free;
 		    TM_DISCO_LedInit();
 		  // Initialize_everything(str);
 			TM_DISCO_ButtonInit();
 			if (f_mount(&FatFs, "", 1) == FR_OK) {
 			        //Mounted OK, turn on RED LED
 			        TM_DISCO_LedOn(LED_RED);

 			        //Try to open file
 			        if (f_open(&fil, "1stfile.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) == FR_OK) {
 			            //File opened, turn off RED and turn on GREEN led
 			            TM_DISCO_LedOn(LED_GREEN);
 			            TM_DISCO_LedOff(LED_RED);

 			            //If we put more than 0 characters (everything OK)
 			            if (f_puts("First string in my file\n", &fil) > 0) {
 			                if (TM_FATFS_DriveSize(&total, &free) == FR_OK) {
 			                    //Data for drive size are valid
 			                }
 			                //Turn on both leds
 			                TM_DISCO_LedOn(LED_GREEN | LED_RED);
 			            }
 			        }
 			    }

 TM_ADC_Init(ADC1, ADC_Channel_0);
 TM_ADC_Init(ADC1, ADC_Channel_1);
 TM_ADC_Init(ADC1, ADC_Channel_2);
 TM_ADC_Init(ADC1, ADC_Channel_3);
 TM_ADC_Init(ADC1, ADC_Channel_4);

 while (1) {
	 sprintf(str, "%4d: %4d %4d %4d %4d \n \r", TM_ADC_Read(ADC1, ADC_Channel_0),TM_ADC_Read(ADC1, ADC_Channel_1),TM_ADC_Read(ADC1, ADC_Channel_2), TM_ADC_Read(ADC1, ADC_Channel_3),TM_ADC_Read(ADC1, ADC_Channel_4));
	 USART_puts(str);
	 printrpm(TM_ADC_Read(ADC1, ADC_Channel_0));
	 printspd(TM_ADC_Read(ADC1, ADC_Channel_1));
	 printtemp(TM_ADC_Read(ADC1, ADC_Channel_3));
	 printgear(TM_ADC_Read(ADC1, ADC_Channel_2));
	 printfuel(TM_ADC_Read(ADC1, ADC_Channel_4));
	 f_puts(str, &fil);
	        Delayms(1000);
	        if(TM_DISCO_ButtonOnPressed())
	       //Close file, don't forget this!
	        f_close(&fil);
	        f_mount(0, "", 1);//Unmount drive, don't forget this!
 }
}
