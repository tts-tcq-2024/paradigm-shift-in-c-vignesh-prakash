#include <stdio.h>
#include "Checker.h"
#include "EarlyWarnings.h"

int IsTemperatureInRange(float temperature) {
    return temperature >= FREEZING_POINT_MIN && temperature <= PEAK_TEMPERATURE_MAX;
}

int IsSOCInRange(float soc) {
    return soc >= SOC_LOW_MIN && soc <= SOC_HIGH_MAX;
}

int IsChargeRateInRange(float chargeRate) {
    return chargeRate >= 0 && chargeRate <= CHARGE_RATE_PEAK_MAX;
}

int IsTemperatureOk(float temperature) {
    GenerateTemperatureWarning(temperature);
    int result = IsTemperatureInRange(temperature);

    if (result) {
        printf("Temperature within range!\n");
    } else {
        printf("Temperature out of range!\n");
    }

    return result;
}

int IsSOCOk(float soc) {
    GenerateSOCWarning(soc);
    int result = IsSOCInRange(soc);

    if (result) {
        printf("State of Charge in range!\n");
    } else {
        printf("State of Charge out of range!\n");
    }

    return result;
}

int IsChargeRateOk(float chargeRate) {
    GenerateChargeRateWarning(chargeRate);
    int result = IsChargeRateInRange(chargeRate);

    if (result) {
        printf("Charge Rate in range!\n");
    } else {
        printf("Charge Rate out of range!\n");
    }

    return result;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return IsTemperatureOk(temperature) && IsSOCOk(soc) && IsChargeRateOk(chargeRate);
}
