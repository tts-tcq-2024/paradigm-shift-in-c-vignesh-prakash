#include <stdio.h>
#include <assert.h>

int IstemperatureOk(float temperature) 
{
if (temperature>=0&&temperature<=45)
{
   printf("Temperature within range!\n");
   return 1;
}
else
{
   printf("Temperature out of range!\n");
   return 0;
}
}
int IssocOk(float soc)
{
if (soc>=20 && soc<=80)
{
    printf("State of Charge in range!\n");
   return 1;
}
else
{
    printf("State of Charge out of range!\n");
   return 0;
}
}
int IschargeRateOk(float chargeRate)
{
if (chargeRate<=0.8)
{
   printf("Charge Rate in range!\n");
   return 1;
}
else
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
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!IschargeRateOk(0.9));
}
