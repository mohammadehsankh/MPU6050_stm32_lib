#include "mpu6050.h"

uint8_t WHO_am_I(I2C_HandleTypeDef *hi2c)
{

uint8_t data_add[1]={0};
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,0x75,1,data_add,1,100);
return data_add[0];

}

void init_mpu(I2C_HandleTypeDef *hi2c)
	
{

uint8_t gyro_con=0xF8;
uint8_t acc_con=0xF8;
uint8_t fifo_en=0x78;	
uint8_t i2c_mst_ct=0xD;
uint8_t pwr_mng=0x00;
uint8_t user_crl=0x40;	
uint8_t data_0=0x00;
	
HAL_I2C_Mem_Write(hi2c,mpu_address_gnd,PWR_MGMT_1,1,&pwr_mng,1,100); //wakeup sens


HAL_I2C_Mem_Write(hi2c,mpu_address_gnd,SMPLRT_DIV,1,&data_0,1,100);
	HAL_I2C_Mem_Write(hi2c,mpu_address_gnd,CONFIG,1,&data_0,1,100);
			HAL_I2C_Mem_Write(hi2c,mpu_address_gnd,GYRO_CONFIG,1,&gyro_con,1,100);
					HAL_I2C_Mem_Write(hi2c,mpu_address_gnd,ACCEL_CONFIG,1,&acc_con,1,100);
HAL_I2C_Mem_Write(hi2c,mpu_address_gnd,FIFO_EN,1,&fifo_en,1,100);
		HAL_I2C_Mem_Write(hi2c,mpu_address_gnd,I2C_MST_CTRL,1,&i2c_mst_ct,1,100);

HAL_I2C_Mem_Write(hi2c,mpu_address_gnd,USER_CTRL,1,&user_crl,1,100); // enable fifo
	
}



void intrrupt_enable(I2C_HandleTypeDef *hi2c)
{
	
uint8_t intr_con=0x68;
uint8_t intr_en=1;	

HAL_I2C_Mem_Write(hi2c,mpu_address_gnd,INT_PIN_CFG,1,&intr_con,1,100);
		HAL_I2C_Mem_Write(hi2c,mpu_address_gnd,INT_ENABLE,1,&intr_en,1,100);
		
}



uint8_t interrupt_status(I2C_HandleTypeDef *hi2c)
{

uint8_t data_it[1]={0};
	
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,INT_STATUS,1,data_it,1,100);

return data_it[0];
}



uint16_t ACCEL_YOUT(I2C_HandleTypeDef *hi2c)
{

uint8_t data_acc_y[2]={0};
uint16_t yout=0;
	
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,ACCEL_YOUT_H,1,&data_acc_y[0],1,100);
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,ACCEL_YOUT_L,1,&data_acc_y[1],1,100);

yout=(data_acc_y[0]<<8)+data_acc_y[1];

return yout;

}

uint16_t ACCEL_XOUT(I2C_HandleTypeDef *hi2c)
{

uint8_t data_acc_x[2]={0};
uint16_t xout=0;
	
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,ACCEL_XOUT_H,1,&data_acc_x[0],1,100);
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,ACCEL_XOUT_L,1,&data_acc_x[1],1,100);

xout=(data_acc_x[0]<<8)+data_acc_x[1];
return xout;

}

uint16_t ACCEL_ZOUT(I2C_HandleTypeDef *hi2c)
{

uint8_t data_acc_z[2]={0};
uint16_t zout=0;
	
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,ACCEL_ZOUT_H,1,&data_acc_z[0],1,100);
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,ACCEL_ZOUT_L,1,&data_acc_z[1],1,100);

zout=(data_acc_z[0]<<8)+data_acc_z[1];
return zout;

}


uint16_t temp_out(I2C_HandleTypeDef *hi2c)
{

uint8_t temp[2]={0};
uint16_t t=0;
	
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,TEMP_OUT_H,1,&temp[0],1,100);
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,TEMP_OUT_L,1,&temp[1],1,100);

t=(temp[0]<<8)+temp[1];
return t;

}


uint16_t GYRO_ZOUT(I2C_HandleTypeDef *hi2c)
{

uint8_t data_gyro_z[2]={0};
uint16_t zout=0;
	
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,GYRO_ZOUT_H,1,&data_gyro_z[0],1,100);
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,GYRO_ZOUT_L,1,&data_gyro_z[1],1,100);

zout=(data_gyro_z[0]<<8)+data_gyro_z[1];
return zout;

}


uint16_t GYRO_XOUT(I2C_HandleTypeDef *hi2c)
{

uint8_t data_gyro_x[2]={0};
uint16_t xout=0;
	
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,GYRO_XOUT_H,1,&data_gyro_x[0],1,100);
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,GYRO_XOUT_L,1,&data_gyro_x[1],1,100);

xout=(data_gyro_x[0]<<8)+data_gyro_x[1];
return xout;

}

uint16_t GYRO_YOUT(I2C_HandleTypeDef *hi2c)
{

uint8_t data_gyro_y[2]={0};
uint16_t yout=0;
	
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,GYRO_YOUT_H,1,&data_gyro_y[0],1,100);
HAL_I2C_Mem_Read(hi2c,mpu_address_gnd,GYRO_YOUT_L,1,&data_gyro_y[1],1,100);

yout=(data_gyro_y[0]<<8)+data_gyro_y[1];
return yout;

}



