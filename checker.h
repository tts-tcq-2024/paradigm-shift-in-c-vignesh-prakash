#include <stdio.h>

#define FREEZING_POINT_MIN 0
#define FREEZING_POINT_MAX 2.25
#define PEAK_TEMPERATURE_MIN 42.75
#define PEAK_TEMPERATURE_MAX 45

#define SOC_LOW_MIN 20
#define SOC_LOW_MAX 24
#define SOC_HIGH_MIN 76
#define SOC_HIGH_MAX 80

#define CHARGE_RATE_PEAK_MIN 0.76
#define CHARGE_RATE_PEAK_MAX 0.8

extern int IsTemperatureInRange(float temperature);
extern int IsSOCInRange(float soc);
extern int IsChargeRateInRange(float chargeRate);
extern int IsTemperatureOk(float temperature);
extern int IsSOCOk(float soc);
extern int IsChargeRateOk(float chargeRate);
extern int batteryIsOk(float temperature, float soc, float chargeRate);
