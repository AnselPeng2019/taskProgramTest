#include <stdio.h>
#include <stdint.h>

static int32_t kf[5] = { -165,-98,-68,-57,-55 };
static int32_t bf[5] = {  460,281,209,184,181 };

/***************20C  40C  60C  80C  100C  **********/
static int Tmark[5] = { 2679,2474,2182,1830,1467 };//5 temp points for adc


/**
  * @brief  Get temperature function.
  * @retval vtemp, the ntc resistor voltage
  */
int16_t GetTemp(uint16_t vtemp)
{
	int32_t temp = 0;
	if (vtemp > Tmark[0]) {
		temp = kf[0] * vtemp + bf[0]*1000;
	}
	else if (vtemp > Tmark[1]) {
		temp = kf[1] * vtemp + bf[1]*1000;
	}
	else if (vtemp > Tmark[2]) {
		temp = kf[2] * vtemp + bf[2]*1000;
	}
	else if (vtemp > Tmark[3]) {
		temp = kf[3] * vtemp + bf[3]*1000;
	}
	else {
		temp = kf[4] * vtemp + bf[4]*1000;
	}
	temp /= 1000;

	return (int16_t)temp;

}


int main(int argc, char **argv)
{
  printf("1. Test vtemp = 2600, the TEMP = %2d \n", GetTemp(2600));
  printf("2. Test vtemp = 2455, the TEMP = %2d \n", GetTemp(2455));
  printf("3. Test vtemp = 2300, the TEMP = %2d \n", GetTemp(2300));
  return 0;
}