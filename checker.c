#include <stdio.h>
#include <assert.h>

int isBatteryInRange(float value, float min, float max) {
    return (value >= min && value <= max);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int temperatureOk = isBatteryInRange(temperature, 0, 45);
    int socOk = isBatteryInRange(soc, 20, 80);
    int chargeRateOk = isBatteryInRange(chargeRate, 0, 0.8);

    if (!temperatureOk || !socOk || !chargeRateOk) {
        if (!temperatureOk) {
            printf("Temperature out of range!\n");
        }
        if (!socOk) {
            printf("State of Charge out of range!\n");
        }
        if (!chargeRateOk) {
            printf("Charge Rate out of range!\n");
        }
        return 0;
    }
    return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
