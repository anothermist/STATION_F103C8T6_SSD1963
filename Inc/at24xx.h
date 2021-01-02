#ifndef    _AT24XX_H
#define    _AT24XX_H

#include "stm32f1xx_hal.h"
#include <stdbool.h>

#define        AT24XX_I2C           hi2c1
#define        AT24XX_ADDRESS       0x57 // 0x50 0x57
#define        AT24XX_SIZE_KBIT     32
#define        FREERTOS_IS_ENABLE   0

bool AT24XX_IsConnected(void);

bool AT24XX_Save(uint16_t address, void *data, size_t size_of_data);

bool AT24XX_Load(uint16_t address, void *data, size_t size_of_data);

uint8_t AT24XX_Read(uint16_t address);

void AT24XX_Write(uint16_t address, uint8_t val);

void AT24XX_Update(uint16_t address, uint8_t val);

#endif /* AT24XX_H_ */
