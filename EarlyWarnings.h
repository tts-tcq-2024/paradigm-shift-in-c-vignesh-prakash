#include <stdio.h>

extern void WarnApproachingFreezing(float temperature);
extern void WarnApproachingPeakTemperature(float temperature);
extern void GenerateTemperatureWarning(float temperature);
extern void WarnApproachingDischarge(float soc);
extern void WarnApproachingChargePeak(float soc);
extern void GenerateSOCWarning(float soc);
extern void GenerateChargeRateWarning(float chargeRate);
