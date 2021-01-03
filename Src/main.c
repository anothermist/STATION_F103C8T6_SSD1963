/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <math.h>
#include "ssd1963_hal.h"
#include "xpt2046.h"
#include "uart.h"

#include "string.h"
#include "bme280.h"
#include "ds3231.h"
#include "at24xx.h"

#include "fonts/Font_3_Tiny.h"
#include "fonts/Font_3_PicoPixel.h"
#include "fonts/Font_3_TomThumb_Extended.h"
#include "fonts/Font_5_Org.h"
#include "fonts/Font_8_Sinclair.h"
#include "fonts/Font_8_Sinclair_Inverted.h"
#include "fonts/Font_8_Tiny.h"
#include "fonts/Font_8_Myke.h"
#include "fonts/Font_8_Default.h"
#include "fonts/Font_8_Retro.h"
#include "fonts/Font_9_Mono.h"
#include "fonts/Font_9_Mono_Bold.h"
#include "fonts/Font_9_Mono_Bold_Oblique.h"
#include "fonts/Font_9_Mono_Oblique.h"
#include "fonts/Font_9_Sans.h"
#include "fonts/Font_9_Sans_Bold.h"
#include "fonts/Font_9_Sans_Bold_Oblique.h"
#include "fonts/Font_9_Sans_Oblique.h"
#include "fonts/Font_9_Serif.h"
#include "fonts/Font_9_Serif_Bold.h"
#include "fonts/Font_9_Serif_Bold_Italic.h"
#include "fonts/Font_9_Serif_Italic.h"
#include "fonts/Font_12_Mono.h"
#include "fonts/Font_12_Mono_Bold.h"
#include "fonts/Font_12_Mono_Bold_Oblique.h"
#include "fonts/Font_12_Mono_Oblique.h"
#include "fonts/Font_12_Sans.h"
#include "fonts/Font_12_Sans_Bold.h"
#include "fonts/Font_12_Sans_Bold_Oblique.h"
#include "fonts/Font_12_Sans_Oblique.h"
#include "fonts/Font_12_Serif.h"
#include "fonts/Font_12_Serif_Bold.h"
#include "fonts/Font_12_Serif_Bold_Italic.h"
#include "fonts/Font_12_Serif_Italic.h"
#include "fonts/Font_16_Arial.h"
#include "fonts/Font_16_Arial_Bold.h"
#include "fonts/Font_16_Arial_Italic.h"
#include "fonts/Font_16_Default.h"
#include "fonts/Font_16_FranklinGothic.h"
#include "fonts/Font_16_Hallfetica.h"
#include "fonts/Font_16_Nadianne.h"
#include "fonts/Font_16_Sinclair.h"
#include "fonts/Font_16_Sinclair_Inverted.h"
#include "fonts/Font_16_Swiss_Outline.h"
#include "fonts/Font_16_Matrix_Full.h"
#include "fonts/Font_16_Matrix_Full_Slash.h"
#include "fonts/Font_16_Matrix_Num.h"
#include "fonts/Font_16_Arial_Round.h"
#include "fonts/Font_16_OCR.h"
#include "fonts/Font_16_Segment_16_Full.h"
#include "fonts/Font_16_Grotesk.h"
#include "fonts/Font_16_Grotesk_Bold.h"
#include "fonts/Font_16_Retro.h"
#include "fonts/Font_18_Mono.h"
#include "fonts/Font_18_Mono_Bold.h"
#include "fonts/Font_18_Mono_Bold_Oblique.h"
#include "fonts/Font_18_Mono_Oblique.h"
#include "fonts/Font_18_Sans.h"
#include "fonts/Font_18_Sans_Bold.h"
#include "fonts/Font_18_Sans_Bold_Oblique.h"
#include "fonts/Font_18_Sans_Oblique.h"
#include "fonts/Font_18_Serif.h"
#include "fonts/Font_18_Serif_Bold.h"
#include "fonts/Font_18_Serif_Bold_Italic.h"
#include "fonts/Font_18_Serif_Italic.h"
#include "fonts/Font_24_Matrix_Num.h"
#include "fonts/Font_24_Inconsola.h"
#include "fonts/Font_24_Ubuntu.h"
#include "fonts/Font_24_Ubuntu_Bold.h"
#include "fonts/Font_24_Segment_16_Full.h"
#include "fonts/Font_24_Mono.h"
#include "fonts/Font_24_Mono_Bold.h"
#include "fonts/Font_24_Mono_Bold_Oblique.h"
#include "fonts/Font_24_Mono_Oblique.h"
#include "fonts/Font_24_Grotesk.h"
#include "fonts/Font_24_Grotesk_Bold.h"
#include "fonts/Font_24_Sans.h"
#include "fonts/Font_24_Sans_Bold.h"
#include "fonts/Font_24_Sans_Bold_Oblique.h"
#include "fonts/Font_24_Sans_Oblique.h"
#include "fonts/Font_24_Serif.h"
#include "fonts/Font_24_Serif_Bold.h"
#include "fonts/Font_24_Serif_Bold_Italic.h"
#include "fonts/Font_24_SerifItalic.h"
#include "fonts/Font_32_Dingbats.h"
#include "fonts/Font_32_Special.h"
#include "fonts/Font_32_Calibri_Bold.h"
#include "fonts/Font_32_Arial_Num_Plus.h"
#include "fonts/Font_32_Matrix_Num.h"
#include "fonts/Font_32_Segment_7_Full.h"
#include "fonts/Font_32_Segment_7_Num_Plus.h"
#include "fonts/Font_32_Segment_16_Full.h"
#include "fonts/Font_32_Segment_18_Full.h"
#include "fonts/Font_32_Grotesk.h"
#include "fonts/Font_32_Grotesk_Bold.h"
#include "fonts/Font_40_Segment_16_Full.h"
#include "fonts/Font_48_Battery.h"
#include "fonts/Font_48_Segment_16_Num.h"
#include "fonts/Font_64_Segment_16_Num.h"
#include "fonts/Font_64_Segment_7_Num.h"
//#include "fonts/Font_96_Segment_7_Num.h"
//#include "fonts/Font_96_Segment_16_Num.h"
//#include "fonts/Font_128_Segment_16_Num.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

SPI_HandleTypeDef hspi1;

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_tx;
DMA_HandleTypeDef hdma_usart1_rx;

PCD_HandleTypeDef hpcd_USB_FS;

/* USER CODE BEGIN PV */
uint8_t rtcSet = 1, once = 0;
uint64_t millis, upSec, upSecLast;
uint8_t rtcSec, rtcMin, rtcHrs, rtcDay, rtcDate, rtcMonth, rtcYear,
        rtcSecA1, rtcMinA1, rtcHrsA1, rtcDayA1, rtcDateA1, rtcMinA2, rtcHrsA2, rtcDayA2, rtcDateA2;
uint8_t touchIRQ;
uint16_t touchX, touchY;
uint8_t rtcSecLast, rtcMinLast = 61, rtcHrsLast = 25, rtcLastDay, rtcDateLast, rtcMonthLast, rtcYearLast;
char rtcDateLastChar[5];
int8_t controlHumidity, controlHumidityLast;
uint16_t pressure;
double temperature, humidity, controlTemperature, controlTemperatureLast,
        temperatureRemote, temperatureRemoteLast, humidityRemote, humidityRemoteLast, rtcMoon;
uint64_t startHistory;

uint16_t barographHourly[367] = {25};
uint16_t barographDaily[367];
uint16_t barographMinimum = 0, barographMaximum = 0, barographAverage = 0;
uint8_t barographYearly = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_SPI1_Init(void);
static void MX_USB_PCD_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
double map(double x, double in_min, double in_max, double out_min, double out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint8_t rx_buffer[256];
uint8_t rx_index = 0;
uint8_t rx_data;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    uint8_t i;
    if (huart->Instance == USART1) {
        if (rx_index == 0) {
            for (i = 0; i < 255; i++) {
                rx_buffer[i] = 0;
            }
        }
        rx_buffer[rx_index++] = rx_data;
        HAL_UART_Receive_IT(&huart1, &rx_data, 1);
    }
}

void sensorRemote() {

    if (temperatureRemote != temperatureRemoteLast && temperatureRemote >= -40 && temperatureRemote <= 40) {

        char weatherPrintRemoteT[4];

        if (temperatureRemoteLast >= 10 || (temperatureRemoteLast < 0 && temperatureRemoteLast > -10)) {
            sprintf(weatherPrintRemoteT, "%.1f", temperatureRemoteLast);
            LCD_Font(505, 40, weatherPrintRemoteT, _24_Sans_Bold, 1, BLACK);
        } else if (temperatureRemoteLast < 10 && temperatureRemoteLast > 0) {
            sprintf(weatherPrintRemoteT, "%.1f", temperatureRemoteLast);
            LCD_Font(531, 40, weatherPrintRemoteT, _24_Sans_Bold, 1, BLACK);
        } else if (temperatureRemoteLast <= -10) {
            sprintf(weatherPrintRemoteT, "%2d", (int8_t) temperatureRemoteLast);
            LCD_Font(505, 40, weatherPrintRemoteT, _24_Sans_Bold, 1, BLACK);
        }

        temperatureRemoteLast = temperatureRemote;

        if (temperatureRemoteLast >= 10 || (temperatureRemoteLast < 0 && temperatureRemoteLast > -10)) {
            sprintf(weatherPrintRemoteT, "%.1f", temperatureRemoteLast);
            LCD_Font(505, 40, weatherPrintRemoteT, _24_Sans_Bold, 1, ORANGE);
        } else if (temperatureRemoteLast < 10 && temperatureRemoteLast > 0) {
            sprintf(weatherPrintRemoteT, "%.1f", temperatureRemoteLast);
            LCD_Font(531, 40, weatherPrintRemoteT, _24_Sans_Bold, 1, ORANGE);
        } else if (temperatureRemoteLast <= -10) {
            sprintf(weatherPrintRemoteT, "%2d", (int8_t) temperatureRemoteLast);
            LCD_Font(505, 40, weatherPrintRemoteT, _24_Sans_Bold, 1, ORANGE);
        }

        for (double i = 0.0; i < 400; i++) {
            if (temperatureRemoteLast + 40 > i / 5) LCD_Line(547, 470 - i, 563, 470 - i, 1, GRAY);
            else LCD_Line(547, 470 - i, 563, 470 - i, 1, 0x101010);
        }
    }

    if (humidityRemote != humidityRemoteLast && humidityRemote > 0) {

        char weatherPrintRemoteH[3];

        if (humidityRemoteLast >= 10) {
            sprintf(weatherPrintRemoteH, "%.1f", humidityRemoteLast);
            LCD_Font(405, 40, weatherPrintRemoteH, _24_Sans_Bold, 1, BLACK);
        } else if (humidityRemoteLast < 10) {
            sprintf(weatherPrintRemoteH, "%.1f", humidityRemoteLast);
            LCD_Font(431, 40, weatherPrintRemoteH, _24_Sans_Bold, 1, BLACK);
        }

        humidityRemoteLast = humidityRemote;

        if (humidityRemoteLast >= 10) {
            sprintf(weatherPrintRemoteH, "%.1f", humidityRemoteLast);
            LCD_Font(405, 40, weatherPrintRemoteH, _24_Sans_Bold, 1, CYAN);
        } else if (humidityRemoteLast < 10) {
            sprintf(weatherPrintRemoteH, "%.1f", humidityRemoteLast);
            LCD_Font(431, 40, weatherPrintRemoteH, _24_Sans_Bold, 1, CYAN);
        }

        for (double i = 0.0; i < 400; i++) {
            if (humidityRemote > i / 4) LCD_Line(447, 470 - i, 463, 470 - i, 1, GRAY);
            else LCD_Line(447, 470 - i, 463, 470 - i, 1, 0x101010);
        }
    }
}

void uartDecode() {

    if (memcmp(rx_buffer, "RS", 2) == 0) {
			
        char valT[4] = {0};

        for (uint8_t i = 0; i < 4; i++) valT[i] = rx_buffer[2 + i];

        temperatureRemote = atoi(valT);
        temperatureRemote = temperatureRemote / 10;

        char valH[3] = {0};

        for (uint8_t i = 0; i < 3; i++) valH[i] = rx_buffer[6 + i];

        humidityRemote = atoi(valH);
        humidityRemote = humidityRemote / 10;

        sensorRemote();
    }
		
		    if (memcmp(rx_buffer, "RT", 2) == 0) {
					
        char val[2];

        val[0] = rx_buffer[2];
				val[1] = rx_buffer[3];
        DS3231_setHrs(atoi(val));

        val[0] = rx_buffer[4];
				val[1] = rx_buffer[5];
        DS3231_setMin(atoi(val));

        val[0] = rx_buffer[6];
				val[1] = rx_buffer[7];
        DS3231_setSec(atoi(val));

        val[0] = rx_buffer[8];
				val[1] = rx_buffer[9];
        DS3231_setDate(atoi(val));

        val[0] = rx_buffer[10];
				val[1] = rx_buffer[11];
        DS3231_setMonth(atoi(val));

        val[0] = rx_buffer[12];
				val[1] = rx_buffer[13];
        DS3231_setYear(atoi(val));
				
				val[0] = 0;
				val[1] = rx_buffer[14];
        DS3231_setDay(atoi(val));
    }

    for (uint8_t i = 0; i < 255; i++) rx_buffer[i] = 0;
}

uint8_t byteL(uint16_t val) {
    return (val & 0xFF);
}

uint8_t byteH(uint16_t val) {
    return ((val >> 8) & 0xFF);
}

uint16_t byteS(uint8_t byteL, uint8_t byteH) {
    return (byteH << 8) | byteL;
}

void barograph(void) {
    if (barographHourly[0] != rtcHrs && pressure > 300 && pressure < 1100) {

        for (uint16_t i = 0; i < 367; i++) {
            barographHourly[i] = byteS(AT24XX_Read(i * 2 + 1000), AT24XX_Read(i * 2 + 1 + 1000));
            barographDaily[i] = byteS(AT24XX_Read(i * 2 + 2000), AT24XX_Read(i * 2 + 1 + 2000));
        }

        if (barographHourly[0] != rtcHrs) {
            barographHourly[0] = rtcHrs;

            for (uint16_t i = 1; i < 366; i++) barographHourly[i] = barographHourly[i + 1];
            barographHourly[366] = (uint16_t) pressure;

            for (uint16_t i = 0; i < 367; i++) {
                AT24XX_Update(i * 2 + 1000, byteL(barographHourly[i]));
                AT24XX_Update(i * 2 + 1 + 1000, byteH(barographHourly[i]));
            }
        }

        if (barographDaily[0] != rtcDate) {
            barographDaily[0] = rtcDate;

            uint32_t barographAverageLast24Hours = 0;
            uint16_t historyHours = 0;
            for (uint8_t i = 0; i < 24; i++) {
                if (barographHourly[366 - i] != 0) {
                    barographAverageLast24Hours = barographAverageLast24Hours + barographHourly[366 - i];
                    historyHours++;
                }
            }
            if (historyHours != 0) barographAverageLast24Hours = barographAverageLast24Hours / historyHours;

            for (uint16_t i = 1; i < 366; i++) {
                barographDaily[i] = barographDaily[i + 1];
            }
            barographDaily[366] = barographAverageLast24Hours;

            for (uint16_t i = 0; i < 367; i++) {
                AT24XX_Update(i * 2 + 2000, byteL(barographDaily[i]));
                AT24XX_Update(i * 2 + 1 + 2000, byteH(barographDaily[i]));
            }
        }

        uint32_t barographAverageLast366Days = 0;
        uint16_t historyDays = 0;
        for (uint16_t i = 0; i < 365; i++) {
            if (barographDaily[366 - i] != 0) {
                barographAverageLast366Days = barographAverageLast366Days + barographDaily[366 - i];
                historyDays++;
            }
        }
        if (historyDays != 0) barographAverage = barographAverageLast366Days / historyDays;

        barographMinimum = barographDaily[366];
        barographMaximum = barographDaily[366];

        for (uint16_t i = 1; i < 366; i++) {
            if (barographDaily[366 - i] != 0) {
                if (barographDaily[366 - i] < barographMinimum) barographMinimum = barographDaily[366 - i];
                if (barographDaily[366 - i] > barographMaximum) barographMaximum = barographDaily[366 - i];
            }
        }
    }

    for (uint16_t i = 0; i < 366; i++) {
        LCD_Line(i + 3, 350, i + 3, 478, 1, 0x050505);
        int16_t val = 0;
        if (barographYearly) val = barographDaily[i + 1];
        else val = barographHourly[i + 1];
        if (val > 0) LCD_Line(i + 3, 478 - 64 - ((val) - barographAverage), i + 3, 478, 1, RED);
    }

}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  MX_USB_PCD_Init();
  /* USER CODE BEGIN 2 */
//    HAL_TIM_Base_Start(&htim1);
//    HAL_TIM_Base_Start_IT(&htim1);

    LCD_Init();
    XPT2046_Init();
    BME280_Init();

    if (!rtcSet) {
        DS3231_setSec(0);
        DS3231_setMin(45);
        DS3231_setHrs(7);
        DS3231_setDay(1);
        DS3231_setDate(28);
        DS3231_setMonth(12);
        DS3231_setYear(20);
        rtcSet = 1;
    }

    LCD_Rect_Fill(0, 0, 800, 480, BLACK);
    LCD_Rect(1, 0, 799, 479, 1, BLUE);
//						LCD_Font(0, 200, "1234567890", _32_Segment_7_Num_Plus, 1, RED);

//    for (uint16_t i = 0; i < 4096; i++) {
//        AT24XX_Update(i, 0);
//    }

    HAL_UART_Receive_IT(&huart1, &rx_data, 1);

	uint8_t uartTransmit[] = "UART OK\r\n";
	HAL_UART_Transmit(&huart1, uartTransmit, sizeof(uartTransmit), 100);
	
	uint8_t uartTransmitDMA[] = "UART DMA OK\r\n";
  HAL_UART_Transmit_DMA(&huart1, uartTransmitDMA, sizeof(uartTransmitDMA));

//    LCD_Rect_Fill(2, 349, 368, 130, BLUE);
		LCD_Rect(0, 349, 369, 130, 1, BLUE);

    double floatPart1 = AT24XX_Read(0);
    double floatPart2 = AT24XX_Read(1);
    controlTemperature = floatPart1 + floatPart2 / 10;
    controlHumidity = AT24XX_Read(2);

    LCD_Line(400, 2, 400, 478, 1, BLUE);
    LCD_Rect(445, 70, 20, 402, 1, CYAN);
		
		LCD_Rect(745, 70, 20, 402, 1, CYAN);

		for (uint32_t i = 0; i < 41; i++) {
				char numbers[2];
				sprintf(numbers, "%02d", 40 - i);
				if (i % 5 == 0) LCD_Font(711, 77 + i * 10, numbers, _9_Sans, 1, GREEN);
				if (i % 5 == 0 && i > 30) LCD_Font(711, 77 + i * 10, "0", _9_Sans, 1, BLACK);

				if (controlTemperatureLast >= 40 - i) {

						if (i % 5 == 0) LCD_Line(735, 71 + i * 10, 745, 71 + i * 10, 1, YELLOW);
						char numbers[2];
						sprintf(numbers, "%02d", 40 - i);
						if (i % 5 == 0) LCD_Font(711, 77 + i * 10, numbers, _9_Sans, 1, GREEN);
						if (i % 5 == 0 && i > 30) LCD_Font(711, 77 + i * 10, "0", _9_Sans, 1, BLACK);
						else LCD_Line(740, 71 + i * 10, 745, 71 + i * 10, 1, YELLOW);
				} else {
						if (i % 5 == 0) LCD_Line(735, 71 + i * 10, 745, 71 + i * 10, 1, CYAN);
						else LCD_Line(740, 71 + i * 10, 745, 71 + i * 10, 1, CYAN);
				}
		}

		LCD_Rect(645, 70, 20, 402, 1, CYAN);

		for (uint8_t i = 0; i < 41; i++) {
				float n = (uint16_t) 100.0 - i * 2.5;
				if ((uint8_t) n % 10 == 0) {
						char numbers[2];
						sprintf(numbers, "%02d", (uint8_t) n);
						if (n < 100) LCD_Font(611, 77 + i * 10, numbers, _9_Sans, 1, GREEN);
						else LCD_Font(602, 77 + i * 10, numbers, _9_Sans, 1, GREEN);

						if (controlHumidityLast >= 100 - i * 2.5)
								LCD_Line(635, 71 + i * 10, 645, 71 + i * 10, 1, YELLOW);
						else LCD_Line(635, 71 + i * 10, 645, 71 + i * 10, 1, CYAN);


				} else if ((uint8_t) n % 5 == 0 && i < 40) {


						if (controlHumidityLast >= 100 - i * 2.5)
								LCD_Line(640, 71 + i * 10, 645, 71 + i * 10, 1, YELLOW);
						else LCD_Line(640, 71 + i * 10, 645, 71 + i * 10, 1, CYAN);
				}
		}
		LCD_Font(611, 477, "0", _9_Sans, 1, BLACK);

    for (uint8_t i = 0; i < 41; i++) {
        float n = (uint16_t) 100.0 - i * 2.5;
        if ((uint8_t) n % 10 == 0) {
            char numbers[2];
            sprintf(numbers, "%02d", (uint8_t) n);
            if (n < 100) LCD_Font(411, 77 + i * 10, numbers, _9_Sans, 1, GREEN);
            else LCD_Font(402, 77 + i * 10, numbers, _9_Sans, 1, GREEN);
            LCD_Line(435, 71 + i * 10, 445, 71 + i * 10, 1, CYAN);
        } else if ((uint8_t) n % 5 == 0 && i < 40)
            LCD_Line(440, 71 + i * 10, 445, 71 + i * 10, 1, CYAN);

    }
    LCD_Font(411, 477, "0", _9_Sans, 1, BLACK);

    LCD_Rect(545, 70, 20, 402, 1, CYAN);

    for (int32_t i = 0; i < 81; i++) {
        char numbers[2];
        sprintf(numbers, "%02d", 40 - i);
        if (i % 10 == 0) {
            if (40 - i >= 0) LCD_Font(511, 77 + i * 5, numbers, _9_Sans, 1, GREEN);
            else if (40 - i < 0) LCD_Font(502, 77 + i * 5, numbers, _9_Sans, 1, GREEN);
            LCD_Line(535, 71 + i * 5, 545, 71 + i * 5, 1, CYAN);
        } else if (i % 5 == 0) LCD_Line(540, 71 + i * 5, 545, 71 + i * 5, 1, CYAN);
        LCD_Font(511, 277, "0", _9_Sans, 1, BLACK);
    }

    LCD_Line(500, 2, 500, 478, 1, BLUE);
    LCD_Line(600, 2, 600, 478, 1, BLUE);
    LCD_Line(700, 2, 700, 478, 1, BLUE);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    while (1) {
        if (rx_index != 0) {
            HAL_Delay(200);
            rx_index = 0;

            uartDecode();
        }

        if (upSec != upSecLast) {
            upSec = upSecLast;
            DS3231_Update();
            rtcSec = DS3231_getSec();
            rtcMin = DS3231_getMin();
            rtcHrs = DS3231_getHrs();
            rtcDay = DS3231_getDay();
            rtcDate = DS3231_getDate();
            rtcMonth = DS3231_getMonth();
            rtcYear = DS3231_getYear();
            rtcSecA1 = DS3231_getAlarm1Sec();
            rtcMinA1 = DS3231_getAlarm1Min();
            rtcHrsA1 = DS3231_getAlarm1Hour();
            rtcDayA1 = DS3231_getAlarm1Day();
            rtcDateA1 = DS3231_getAlarm1Date();
            rtcMinA2 = DS3231_getAlarm2Min();
            rtcHrsA2 = DS3231_getAlarm2Hour();
            rtcDayA2 = DS3231_getAlarm2Day();
            rtcDateA2 = DS3231_getAlarm2Date();

            if (!once) {
                rtcDateLast = rtcDate;
                rtcMonthLast = rtcMonth;
                rtcYearLast = rtcYear;
                once = 1;
            }

            char weatherPrint[4];

            if (temperature != BME280_getTemperature(-1)) {

                if (temperature >= -40 && temperature <= 40) {

                    char weatherPrint[4];

                    if (temperature >= 10 || (temperature < 0 && temperature > -10)) {
                        sprintf(weatherPrint, "%.1f", temperature);
                        LCD_Font(705, 40, weatherPrint, _24_Sans_Bold, 1, BLACK);
                    } else if (temperature < 10 && temperature > 0) {
                        sprintf(weatherPrint, "%.1f", temperature);
                        LCD_Font(731, 40, weatherPrint, _24_Sans_Bold, 1, BLACK);
                    } else if (temperature <= -10) {
                        sprintf(weatherPrint, "%2d", (int8_t) temperature);
                        LCD_Font(705, 40, weatherPrint, _24_Sans_Bold, 1, BLACK);
                    }

                    temperature = BME280_getTemperature(-1);

                    if (temperature >= 10 || (temperature < 0 && temperature > -10)) {
                        sprintf(weatherPrint, "%.1f", temperature);
                        LCD_Font(705, 40, weatherPrint, _24_Sans_Bold, 1, ORANGE);
                    } else if (temperature < 10 && temperature > 0) {
                        sprintf(weatherPrint, "%.1f", temperature);
                        LCD_Font(731, 40, weatherPrint, _24_Sans_Bold, 1, ORANGE);
                    } else if (temperature <= -10) {
                        sprintf(weatherPrint, "%2d", (int8_t) temperature);
                        LCD_Font(705, 40, weatherPrint, _24_Sans_Bold, 1, ORANGE);
                    }


                    for (double i = 0.0; i < 400; i++) {
                        if (temperature > i / 10) LCD_Line(747, 470 - i, 763, 470 - i, 1, GRAY);
                        else LCD_Line(747, 470 - i, 763, 470 - i, 1, 0x101010);
                    }
                }
            }

            if (humidity != BME280_getHumidity(-1)) {
                sprintf(weatherPrint, "%.1f", humidity);
                if (humidity >= 10)
                    LCD_Font(605, 40, weatherPrint, _24_Sans_Bold, 1, BLACK);
                else LCD_Font(631, 40, weatherPrint, _24_Sans_Bold, 1, BLACK);

                humidity = BME280_getHumidity(-1);

                sprintf(weatherPrint, "%.1f", humidity);
                if (humidity >= 10)
                    LCD_Font(605, 40, weatherPrint, _24_Sans_Bold, 1, CYAN);
                else LCD_Font(631, 40, weatherPrint, _24_Sans_Bold, 1, CYAN);

                for (double i = 0.0; i < 400; i++) {
                    if (humidity > i / 4) LCD_Line(647, 470 - i, 663, 470 - i, 1, GRAY);
                    else LCD_Line(647, 470 - i, 663, 470 - i, 1, 0x101010);
                }
            }

            if (pressure != (uint16_t) BME280_getPressure()) {
                if (pressure >= 1000) {
                    sprintf(weatherPrint, "PRESSURE: %02d hPa", pressure);
                    LCD_Font(2, 343, weatherPrint, _12_Sans, 1, BLACK);
                } else {
                    sprintf(weatherPrint, "PRESSURE:  %02d hPa", pressure);
                    LCD_Font(2, 343, weatherPrint, _12_Sans, 1, BLACK);
                }

                pressure = (uint16_t) BME280_getPressure();

                if (pressure >= 1000) {
                    sprintf(weatherPrint, "PRESSURE: %02d hPa", pressure);
                    LCD_Font(2, 343, weatherPrint, _12_Sans, 1, RED);
                } else {
                    sprintf(weatherPrint, "PRESSURE:  %02d hPa", pressure);
                    LCD_Font(2, 343, weatherPrint, _12_Sans, 1, RED);
                }
            }

            char clockPrint[5];

            if (rtcSecLast != rtcSec) {
                rtcSecLast = rtcSec;

                if (rtcSec % 2 == 0) LCD_Font(106, 70, ":", _24_Sans, 2, WHITE);
                else LCD_Font(106, 70, ":", _24_Sans, 2, BLACK);

                if (rtcSec == 58 && controlTemperature >= temperature)
                    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
                else if (rtcSec == 1 && controlTemperature < temperature)
                    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);

                if (rtcSec == 59) {
                    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
                }

                if (rtcMinLast != rtcMin) {

                    sprintf(clockPrint, "%02d", rtcMinLast);
                    LCD_Font(130, 75, clockPrint, _24_Sans, 2, BLACK);
                    sprintf(clockPrint, "%02d", rtcMin);
                    LCD_Font(130, 75, clockPrint, _24_Sans, 2, WHITE);
                    rtcMinLast = rtcMin;

                    if (rtcHrsLast != rtcHrs) {
                        sprintf(clockPrint, "%02d", rtcHrsLast);
                        LCD_Font(2, 75, clockPrint, _24_Sans, 2, BLACK);
                        sprintf(clockPrint, "%02d", rtcHrs);
                        LCD_Font(2, 75, clockPrint, _24_Sans, 2, WHITE);
                        rtcHrsLast = rtcHrs;

                        if (rtcLastDay != rtcDay) {
                            LCD_Font(2, 135, rtcDateLastChar, _24_Sans_Bold, 1, BLACK);

                            sprintf(clockPrint, "%02d / %02d / %02d", rtcDateLast, rtcMonthLast, rtcYearLast);
                            LCD_Font(90, 130, clockPrint, _18_Sans, 1, BLACK);

                            sprintf(clockPrint, "%02d / %02d / %02d", rtcDate, rtcMonth, rtcYear);
                            LCD_Font(90, 130, clockPrint, _18_Sans, 1, MAGENTA);

                            for (uint8_t i; i < 5; i++) rtcDateLastChar[i] = clockPrint[i];

                            switch (rtcDay) {
                                case 1:
                                    LCD_Font(2, 130, "SU' ", _18_Sans, 1, BLACK);
                                    LCD_Font(2, 130, "MO' ", _18_Sans, 1, MAGENTA);
                                    break;

                                case 2:
                                    LCD_Font(2, 130, "MO' ", _18_Sans, 1, BLACK);
                                    LCD_Font(2, 130, "TU' ", _18_Sans, 1, BLUE);
                                    break;

                                case 3:
                                    LCD_Font(2, 130, "TU' ", _18_Sans, 1, BLACK);
                                    LCD_Font(2, 130, "WE' ", _18_Sans, 1, CYAN);
                                    break;

                                case 4:
                                    LCD_Font(2, 130, "WE' ", _18_Sans, 1, BLACK);
                                    LCD_Font(2, 130, "TH' ", _18_Sans, 1, GREEN);
                                    break;

                                case 5:
                                    LCD_Font(2, 130, "TH' ", _18_Sans, 1, BLACK);
                                    LCD_Font(2, 130, "FR' ", _18_Sans, 1, YELLOW);
                                    break;

                                case 6:
                                    LCD_Font(2, 130, "FR' ", _18_Sans, 1, BLACK);
                                    LCD_Font(2, 130, "SA' ", _18_Sans, 1, ORANGE);
                                    break;

                                case 7:
                                    LCD_Font(2, 130, "SA' ", _18_Sans, 1, BLACK);
                                    LCD_Font(2, 130, "SU' ", _18_Sans, 1, RED);
                                    break;
                            }
                            rtcLastDay = rtcDay;
                        }

                        rtcDateLast = rtcDate;
                        rtcMonthLast = rtcMonth;
                        rtcYearLast = rtcYear;

                        //	rtcMoon = DS3231_getMoonDay();

                    }
                    barograph();

                    char sendHrs[2];
                    char sendMin[2];
                    char sendSec[2];
                    char sendDate[2];
                    char sendMonth[2];
                    char sendYear[2];
										char sendDay[1];

                    if (rtcHrs < 10) sprintf(sendHrs, "0%d", rtcHrs); else sprintf(sendHrs, "%d", rtcHrs);
                    if (rtcMin < 10) sprintf(sendMin, "0%d", rtcMin); else sprintf(sendMin, "%d", rtcMin);
                    if (rtcSec < 10) sprintf(sendSec, "0%d", rtcSec); else sprintf(sendSec, "%d", rtcSec);
                    if (rtcDate < 10) sprintf(sendDate, "0%d", rtcDate); else sprintf(sendDate, "%d", rtcDate);
                    if (rtcMonth < 10) sprintf(sendMonth, "0%d", rtcMonth); else sprintf(sendMonth, "%d", rtcMonth);
                    sprintf(sendYear, "%d", rtcYear);
										sprintf(sendDay, "%d", rtcDay);

                    uint8_t uartTransmitTime[16] = {0};
                    snprintf((char *) uartTransmitTime, sizeof uartTransmitTime, "RT%s%s%s%s%s%s%s\r\n", sendHrs, sendMin,
                             sendSec, sendDate, sendMonth, sendYear, sendDay);
//                    HAL_UART_Transmit_DMA(&huart1, uartTransmitTime, sizeof(uartTransmitTime));
                }
            }
        }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
        if (touchIRQ) {
            touchX = getX();
            touchY = getY();

            if (touchX > 2 && touchX < 368 && touchY > 350 && touchY < 478) {

                if (barographYearly) barographYearly = 0;
                else barographYearly = 1;

                barograph();
            }

            if (touchX > 700 && touchX < 800 && touchY > 70 && touchY < 472) {
                controlTemperature = map(touchY, 71, 471, 40, 0);
                if (controlTemperature - (uint8_t) controlTemperature >= 0.5)
                    controlTemperature = (uint8_t) controlTemperature;
                else controlTemperature = (uint8_t) controlTemperature + 0.5;

                uint8_t controlTemperaturePart1 = (uint8_t) controlTemperature;
                uint8_t controlTemperaturePart2 = (controlTemperature - controlTemperaturePart1) * 10;
                AT24XX_Update(0, controlTemperaturePart1);
                AT24XX_Update(1, controlTemperaturePart2);

            }

            if (touchX > 600 && touchX < 700 && touchY > 70 && touchY < 472) {
                controlHumidity = (uint8_t) map(touchY, 71, 471, 100, 0);

                if (controlHumidity % 10 > 5) {
                    controlHumidity = (((uint8_t)(controlHumidity / 10)) * 10) + 5;
                } else controlHumidity = (((uint8_t)(controlHumidity / 10)) * 10);

                AT24XX_Update(2, controlHumidity);
            }

            if (touchX && touchY) {
                LCD_Rect_Fill(touchX, touchY, 2, 2, WHITE);
            }
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);

            touchX = 0;
            touchY = 0;
            touchIRQ = 0;
        } else {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
        }

        if (upSec % 2 == 0) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
        else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_HARD_OUTPUT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USB Initialization Function
  * @param None
  * @retval None
  */
static void MX_USB_PCD_Init(void)
{

  /* USER CODE BEGIN USB_Init 0 */

  /* USER CODE END USB_Init 0 */

  /* USER CODE BEGIN USB_Init 1 */

  /* USER CODE END USB_Init 1 */
  hpcd_USB_FS.Instance = USB;
  hpcd_USB_FS.Init.dev_endpoints = 8;
  hpcd_USB_FS.Init.speed = PCD_SPEED_FULL;
  hpcd_USB_FS.Init.low_power_enable = DISABLE;
  hpcd_USB_FS.Init.lpm_enable = DISABLE;
  hpcd_USB_FS.Init.battery_charging_enable = DISABLE;
  if (HAL_PCD_Init(&hpcd_USB_FS) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USB_Init 2 */

  /* USER CODE END USB_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
  /* DMA1_Channel5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel5_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED_Pin|LCD_DB14_Pin|LCD_DB15_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LCD_DB00_Pin|LCD_DB01_Pin|LCD_DB02_Pin|LCD_DB03_Pin
                          |LCD_DB04_Pin|LCD_DB05_Pin|LCD_DB06_Pin|LCD_DB07_Pin
                          |LCD_DB11_Pin|LCD_DB12_Pin|LCD_DB13_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LCD_CS_Pin|LCD_WR_Pin|LCD_RS_Pin|LSD_RD_Pin
                          |LCD_DB08_Pin|LCD_DB09_Pin|LCD_DB10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_Pin LCD_DB14_Pin LCD_DB15_Pin */
  GPIO_InitStruct.Pin = LED_Pin|LCD_DB14_Pin|LCD_DB15_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_DB00_Pin LCD_DB01_Pin LCD_DB02_Pin LCD_DB03_Pin
                           LCD_DB04_Pin LCD_DB05_Pin LCD_DB06_Pin LCD_DB07_Pin
                           LCD_DB11_Pin LCD_DB12_Pin LCD_DB13_Pin */
  GPIO_InitStruct.Pin = LCD_DB00_Pin|LCD_DB01_Pin|LCD_DB02_Pin|LCD_DB03_Pin
                          |LCD_DB04_Pin|LCD_DB05_Pin|LCD_DB06_Pin|LCD_DB07_Pin
                          |LCD_DB11_Pin|LCD_DB12_Pin|LCD_DB13_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_CS_Pin LCD_WR_Pin LCD_RS_Pin LSD_RD_Pin
                           LCD_DB08_Pin LCD_DB09_Pin LCD_DB10_Pin */
  GPIO_InitStruct.Pin = LCD_CS_Pin|LCD_WR_Pin|LCD_RS_Pin|LSD_RD_Pin
                          |LCD_DB08_Pin|LCD_DB09_Pin|LCD_DB10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
