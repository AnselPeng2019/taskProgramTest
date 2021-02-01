#include "stdio.h"
#include "stdint.h"

struct i2c_driver {
	unsigned int class;
    int addr;
};

static struct i2c_driver mcp4725_driver = {

	.class		= 0x00,
	.addr		= 12345,
};

typedef struct{
uint8_t addr;//设备地址
void (*Initial)(void);//初始化函数
void (*OutputVoltage)(uint16_t);//输出电压
void (*SaveDefaultVoltage)(uint16_t);//存储默认电压值
int* (*Getmax)(int*);
}MCP4726DeviceDef_t;

static void MCP4726Initial(void);
static void MCP4726OutVoltage(uint16_t);
static void MCP4726SaveDefaultVoltage(uint16_t);
static int* GetMaxValue(int *a);
MCP4726DeviceDef_t mcp4726a0_1 = {
.addr = 0x60,//mcp4726a0 address,1100000
.Initial = MCP4726Initial,
.Getmax = GetMaxValue,
};

