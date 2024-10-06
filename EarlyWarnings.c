#include <stdio.h>
#include "checker.h"
#include "EarlyWarnings.h"

void WarnApproachingFreezing(float temperature) {
    if (temperature >= FREEZING_POINT_MIN && temperature <= FREEZING_POINT_MAX) {
        printf("Warning: Approaching freezing point\n");
    }
}

void WarnApproachingPeakTemperature(float temperature) {
    if (temperature >= PEAK_TEMPERATURE_MIN && temperature <= PEAK_TEMPERATURE_MAX) {
        printf("Warning: Approaching peak temperature\n");
    }
}

void GenerateTemperatureWarning(float temperature) {
    WarnApproachingFreezing(temperature);
    WarnApproachingPeakTemperature(temperature);
}

void WarnApproachingDischarge(float soc) {
    if (soc >= SOC_LOW_MIN && soc <= SOC_LOW_MAX) {
        printf("Warning: Approaching discharge\n");
    }
}

void WarnApproachingChargePeak(float soc) {
    if (soc >= SOC_HIGH_MIN && soc <= SOC_HIGH_MAX) {
        printf("Warning: Approaching charge-peak\n");
    }
}

void GenerateSOCWarning(float soc) {
    WarnApproachingDischarge(soc);
    WarnApproachingChargePeak(soc);
}

void GenerateChargeRateWarning(float chargeRate) {
    if (chargeRate >= CHARGE_RATE_PEAK_MIN && chargeRate <= CHARGE_RATE_PEAK_MAX) {
        printf("Warning: Approaching peak ChargeRate\n");
    }
}
