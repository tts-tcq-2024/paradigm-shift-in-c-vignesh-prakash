#include <stdio.h>
#include <assert.h>

int CheckWarningForTemperature(float temperature)
{
	if(temperature>=0&&temperature<=2.25)
	{
		printf("Warning : Approaching freezing point\n");
		return 1;
	}
	else if(temperature<=45&&temperature>=42.75)
	{
		printf("Warning : Approaching peak temperature\n");
		return 1;
	}
	return 0;
}

int CheckWarningForSoc(float soc)
{
	if(soc>=20&&soc<=24)
	{
		printf("Warning : Approaching discharge\n");
		return 1;
	}
	else if(soc<=80&&soc>=76)
	{
		printf("Warning : Approaching charge-peak\n");
		return 1;
	}
	return 0;
}

int CheckWarningForChargeRate(float chargeRate)
{
	if((chargeRate>=0.76)&&(chargeRate<=0.8))
	{
		printf("Warning : Approaching peak ChargeRate\n");
		return 1;
	}
	return 0;
}


int IstemperatureOk(float temperature)
{
	int result = CheckWarningForTemperature(temperature);
	if ((result!=1)&&temperature>=0&&temperature<=45)
	{

		printf("Temperature within range!\n");
		return 1;
	}
	else if(result!=1)
	{
		printf("Temperature out of range!\n");
		return 0;
	}
}

int IssocOk(float soc)
{
	int result = CheckWarningForSoc(soc);
	if ((result!=1)&&soc>=20 && soc<=80)
	{
		printf("State of Charge in range!\n");
		return 1;
	}
	else if(result!=1)
	{
		printf("State of Charge out of range!\n");
		return 0;
	}
}

int IschargeRateOk(float chargeRate)
{
    int result = CheckWarningForChargeRate(chargeRate);
	if ((result!=1)&&chargeRate<=0.8)
	{
		printf("Charge Rate in range!\n");
		return 1;
	}
	else if(result!=1)
	{
		printf("Charge Rate out of range!\n");
		return 0;
	}
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
	if((IstemperatureOk(temperature)+IssocOk(soc)+IschargeRateOk(chargeRate))==3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
  assert(batteryIsOk(0.2, 20, 0.77));
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!IschargeRateOk(0.9));
}
