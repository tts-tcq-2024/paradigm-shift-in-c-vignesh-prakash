#include <stdio.h>
#include <assert.h>

// Define constants for thresholds
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

// Function to generate warnings for temperature
void GenerateTemperatureWarning(float temperature) {
    if (temperature >= FREEZING_POINT_MIN && temperature <= FREEZING_POINT_MAX) {
        printf("Warning : Approaching freezing point\n");
    } else if (temperature >= PEAK_TEMPERATURE_MIN && temperature <= PEAK_TEMPERATURE_MAX) {
        printf("Warning : Approaching peak temperature\n");
    }
}

// Function to check if temperature is within range
int IsTemperatureInRange(float temperature) {
    return temperature >= FREEZING_POINT_MIN && temperature <= PEAK_TEMPERATURE_MAX;
}

// Function to check and generate warnings for state of charge (SOC)
void GenerateSOCWarning(float soc) {
    if (soc >= SOC_LOW_MIN && soc <= SOC_LOW_MAX) {
        printf("Warning : Approaching discharge\n");
    } else if (soc >= SOC_HIGH_MIN && soc <= SOC_HIGH_MAX) {
        printf("Warning : Approaching charge-peak\n");
    }
}

// Function to check if SOC is within range
int IsSOCInRange(float soc) {
    return soc >= SOC_LOW_MIN && soc <= SOC_HIGH_MAX;
}

// Function to check and generate warnings for charge rate
void GenerateChargeRateWarning(float chargeRate) {
    if (chargeRate >= CHARGE_RATE_PEAK_MIN && chargeRate <= CHARGE_RATE_PEAK_MAX) {
        printf("Warning : Approaching peak ChargeRate\n");
    }
}

// Function to check if charge rate is within range
int IsChargeRateInRange(float chargeRate) {
    return chargeRate >= 0 && chargeRate <= CHARGE_RATE_PEAK_MAX;
}

// Function to check the temperature, SOC, and charge rate, and generate warnings
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

int main() {
    assert(batteryIsOk(0.2, 20, 0.77));
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(!IsChargeRateOk(0.9));
}
