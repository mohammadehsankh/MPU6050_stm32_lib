#ifndef _MPU6050_
#define _MPU6050_

#include "stm32f1xx_hal.h"

#define mpu_address_gnd 0xD0 // if a0 is not connect to vdd
#define mpu_address_vdd 0xD2 // if a0 is  connect to vdd

#define SELF_TEST_X 13
#define SELF_TEST_Y 14
#define SELF_TEST_Z 15
#define SELF_TEST_A 16

/*
uint8_t XA_TEST = 0;
uint8_t XG_TEST = 0;
uint8_t YA_TEST = 0;
uint8_t YG_TEST = 0;
uint8_t ZA_TEST = 0;
uint8_t ZG_TEST = 0;
*/

//Sample Rate Divider
#define SMPLRT_DIV 25
//uint8_t SMPLRT_DIVIDER = 0;

//Configuration
#define CONFIG 26
//uint8_t EXT_SYNC_SET[8] = {0, 1, 2, 3, 4, 5, 6, 7};
//uint8_t DLPF_CFG[8] = {0, 1, 2, 3, 4, 5, 6, 7};

//Gyroscope Configuration
/*This register is used to trigger gyroscope self-test and configure the gyroscopes’ full scale range.*/
#define GYRO_CONFIG 27
//uint8_t FS_SEL[4] = {0, 1, 2, 3};

//Accelerometer Configuration
/*This register is used to trigger accelerometer self test and configure the accelerometer full scale range*/
#define  ACCEL_CONFIG 28
//uint8_t AFS_SEL[4] = {0, 1, 2, 3};


//FIFO Enable
/*This register determines which sensor measurements are loaded into the FIFO buffer.*/
#define FIFO_EN 35

//I2C Master Control
/*This register configures the auxiliary I2C bus for single-master or multi-master control*/
#define I2C_MST_CTRL 36
//uint8_t I2C_MST_CLK[16]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};//Configures the I2C master clock speed divider.

//Registers 37 to 39 – I2C Slave 0 Control
/*These registers configure the data transfer sequence for Slave 0. Slaves 1, 2, and 3 also behave in a similar manner to Slave 0. 
However, Slave 4’s characteristics differ greatly from those of Slaves 0-3.*/

#define I2C_SLV0_ADDR 37
#define I2C_SLV0_REG 38
#define I2C_SLV0_CTRL 39

#define I2C_SLV1_ADDR 40
#define I2C_SLV1_REG 41
#define I2C_SLV1_CTRL 42

#define I2C_SLV2_ADDR 43
#define I2C_SLV2_REG 44
#define I2C_SLV2_CTRL 45

#define I2C_SLV3_ADDR 46
#define I2C_SLV3_REG 47
#define I2C_SLV3_CTRL 48

#define I2C_SLV4_ADDR 49
#define I2C_SLV4_REG 50
#define I2C_SLV4_DO 51
#define I2C_SLV4_CTRL 52
#define I2C_SLV4_DI 53

//I2C Master Status
/*This register shows the status of the interrupt generating signals in the I2C Master within the MPU-60X0. This register also communicates the status of the FSYNC interrupt to the host processor.
Reading this register will clear all the status bits in the register.*/
#define I2C_MST_STATUS 54

//INT Pin / Bypass Enable Configuration
/*This register configures the behavior of the interrupt signals at the INT pins. 
This register is also used to enable the FSYNC Pin to be used as an interrupt to the host application processor, 
as well as to enable Bypass Mode on the I2C Master. This bit also enables the clock output.*/
#define INT_PIN_CFG 55

//Interrupt Enable
/*This register enables interrupt generation by interrupt sources*/
#define INT_ENABLE 56


//Interrupt Status
/*This register shows the interrupt status of each interrupt generation source. Each bit will clear after the register is read.*/
#define INT_STATUS 58

//Accelerometer Measurements
/*These registers store the most recent accelerometer measurements.*/
#define ACCEL_XOUT_H 59
#define ACCEL_XOUT_L 60
#define ACCEL_YOUT_H 61 
#define ACCEL_YOUT_L 62 
#define ACCEL_ZOUT_H 63 
#define ACCEL_ZOUT_L 64

//Temperature Measurement
/*These registers store the most recent temperature sensor measurement*/
#define TEMP_OUT_H 65
#define TEMP_OUT_L 66

//Gyroscope Measurements
/*These registers store the most recent gyroscope measurements*/
#define GYRO_XOUT_H 67 
#define GYRO_XOUT_L 68
#define GYRO_YOUT_H 69
#define GYRO_YOUT_L 70
#define GYRO_ZOUT_H 71 
#define GYRO_ZOUT_L 72

//Registers 73 to 96 – External Sensor Data
/*These registers store data read from external sensors by the Slave 0, 1, 2, and 3 on the auxiliary I2C interface. 
Data read by Slave 4 is stored in I2C_SLV4_DI (Register 53).*/
#define EXT_SENS_DATA_00 73
#define EXT_SENS_DATA_01 74
#define EXT_SENS_DATA_02 75
#define EXT_SENS_DATA_03 76
#define EXT_SENS_DATA_04 77
#define EXT_SENS_DATA_05 78
#define EXT_SENS_DATA_06 79
#define EXT_SENS_DATA_07 80
#define EXT_SENS_DATA_08 81
#define EXT_SENS_DATA_09 82
#define EXT_SENS_DATA_10 83
#define EXT_SENS_DATA_11 84
#define EXT_SENS_DATA_12 85
#define EXT_SENS_DATA_13 86
#define EXT_SENS_DATA_14 87
#define EXT_SENS_DATA_15 88
#define EXT_SENS_DATA_16 89
#define EXT_SENS_DATA_17 90
#define EXT_SENS_DATA_18 91
#define EXT_SENS_DATA_19 92
#define EXT_SENS_DATA_20 93
#define EXT_SENS_DATA_21 94
#define EXT_SENS_DATA_22 95
#define EXT_SENS_DATA_23 96

//I2C Slave 0 Data Out
/*This register holds the output data written into Slave 0 when Slave 0 is set to write mode.*/
/*This register holds the output data written into Slave 1 when Slave 1 is set to write mode.*/
/*This register holds the output data written into Slave 2 when Slave 2 is set to write mode.*/
/*This register holds the output data written into Slave 3 when Slave 3 is set to write mode.*/
#define I2C_SLV0_DO 99
#define I2C_SLV1_DO 100
#define I2C_SLV2_DO 101
#define I2C_SLV3_DO 102

//I2C Master Delay Control
/*This register is used to specify the timing of external sensor data shadowing. 
The register is also used to decrease the access rate of slave devices relative to the Sample Rate.*/
#define I2C_MST_DELAY_CTRL 103

//Signal Path Reset
/*This register is used to reset the analog and digital signal paths of the gyroscope, accelerometer, and temperature sensors.
The reset will revert the signal path analog to digital converters and filters to their power up configurations.*/
#define SIGNAL_PATH_RESET 104

//User Control
/*This register allows the user to enable and disable the FIFO buffer, I2C Master Mode,
and primary I2C interface. The FIFO buffer, I2C Master, sensor signal paths and sensor registers can also be reset using this register.*/
#define USER_CTRL 106

//Power Management 1
/*This register allows the user to configure the power mode and clock source. 
It also provides a bit for resetting the entire device, and a bit for disabling the temperature sensor*/
#define PWR_MGMT_1 107

//Power Management 2
/*This register allows the user to configure the frequency of wake-ups in Accelerometer Only Low Power Mode.
 This register also allows the user to put individual axes of the accelerometer and gyroscope into standby mode.*/
#define PWR_MGMT_2 108

//FIFO Count Registers
/*These registers keep track of the number of samples currently in the FIFO buffer.*/
#define FIFO_COUNT_H 114
#define FIFO_COUNT_L 115

//FIFO Read Write
/*This register is used to read and write data from the FIFO buffer.*/
#define FIFO_R_W 116


//Who Am I
/*This register is used to verify the identity of the device. The contents of WHO_AM_I are the upper 6 bits of the MPU-60X0’s 7-bit I2C address. 
The least significant bit of the MPU-60X0’s I2C address is determined by the value of the AD0 pin. The value of the AD0 pin is not reflected in this register.*/
#define WHO_AM_I 117



uint8_t WHO_am_I(I2C_HandleTypeDef *hi2c);
void init_mpu(I2C_HandleTypeDef *hi2c);
void intrrupt_enable(I2C_HandleTypeDef *hi2c);
uint8_t interrupt_status(I2C_HandleTypeDef *hi2c);
uint16_t ACCEL_YOUT(I2C_HandleTypeDef *hi2c);
uint16_t ACCEL_XOUT(I2C_HandleTypeDef *hi2c);
uint16_t ACCEL_ZOUT(I2C_HandleTypeDef *hi2c);
uint16_t temp_out(I2C_HandleTypeDef *hi2c);
uint16_t GYRO_ZOUT(I2C_HandleTypeDef *hi2c);
uint16_t GYRO_XOUT(I2C_HandleTypeDef *hi2c);
uint16_t GYRO_YOUT(I2C_HandleTypeDef *hi2c);

#endif //_MPU6050_




