#include "at24xx.h"

extern I2C_HandleTypeDef AT24XX_I2C;

#if (FREERTOS_IS_ENABLE == 1)
#include "cmsis_os.h"
#endif

bool AT24XX_IsConnected(void) {
    if (HAL_I2C_IsDeviceReady(&AT24XX_I2C, AT24XX_ADDRESS << 1, 1, 100) == HAL_OK)
        return true;
    else
        return false;
}

bool AT24XX_Save(uint16_t address, void *data, size_t size_of_data) {
#if ((AT24XX_SIZE_KBIT == 1) || (AT24XX_SIZE_KBIT == 2))
    if(size_of_data > 8)
        return false;
#endif
#if ((AT24XX_SIZE_KBIT == 4) || (AT24XX_SIZE_KBIT == 8) || (AT24XX_SIZE_KBIT == 16))
    if(size_of_data > 16)
        return false;
#endif
#if ((AT24XX_SIZE_KBIT == 32) || (AT24XX_SIZE_KBIT == 64) || (AT24XX_SIZE_KBIT == 128))
    if(size_of_data > 32)
        return false;
#endif

#if ((AT24XX_SIZE_KBIT == 1) || (AT24XX_SIZE_KBIT == 2))
    if(HAL_I2C_Mem_Write(&EEPROM24XX_I2C, AT24XX_ADDRESS<<1, Address, I2C_MEMADD_SIZE_8BIT, (uint8_t*)data, size_of_data, 100) == HAL_OK)
#else
    if (HAL_I2C_Mem_Write(&AT24XX_I2C, AT24XX_ADDRESS << 1, address, I2C_MEMADD_SIZE_16BIT, (uint8_t *) data,
                          size_of_data, 100) == HAL_OK)
#endif
    {
#if (FREERTOS_IS_ENABLE == 1)
        osDelay(5);
#else
        HAL_Delay(5);
#endif
        return true;
    } else
        return false;
}

bool AT24XX_Load(uint16_t address, void *data, size_t size_of_data) {
#if ((AT24XX_SIZE_KBIT == 1) || (AT24XX_SIZE_KBIT == 2))
    if(HAL_I2C_Mem_Read(&EEPROM24XX_I2C, AT24XX_ADDRESS<<1, Address, I2C_MEMADD_SIZE_8BIT, (uint8_t*)data, size_of_data, 100) == HAL_OK)
#else
    if (HAL_I2C_Mem_Read(&AT24XX_I2C, AT24XX_ADDRESS << 1, address, I2C_MEMADD_SIZE_16BIT, (uint8_t *) data,
                         size_of_data, 100) == HAL_OK)
#endif
    {
        return true;
    } else
        return false;
}

uint8_t AT24XX_Read(uint16_t address) {
    uint16_t dt[1] = {NULL};
    AT24XX_Load(address, dt, 1);
    return dt[0];
}

void AT24XX_Write(uint16_t address, uint8_t val) {
    uint8_t save[] = {val};
    AT24XX_Save(address, save, 1);
}

void AT24XX_Update(uint16_t address, uint8_t val) {
	if (AT24XX_Read(address) != val) AT24XX_Write(address, val);
}
