#include <stdio.h>
#include <assert.h>

int isBatteryInRange(float value, float min, float max) {
    return (value >= min && value <= max);
}

int IstemperatureOk(int value) {
    if (!value) {
        printf("Temperature out of range!\n");
        return 0;
    }
    else{
        return 1;
    }
}

int IssocOk(int value) {
    if (!value) {
        printf("State of Charge out of range!\n");
        return 0;
    }
    else{
        return 1;
    }
}

int IschargeRateOk(int value) {
    if (!value) {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    else{
        return 1;
    }
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int temperatureOk = isBatteryInRange(temperature, 0, 45);
    int socOk = isBatteryInRange(soc, 20, 80);
    int chargeRateOk = isBatteryInRange(chargeRate, 0, 0.8);

    int value1 = IstemperatureOk(temperatureOk);
    int value2 = IssocOk(socOk);
    int value3 = IschargeRateOk(chargeRateOk);
    
    if (!value1 || !value2 || !value3) {
        return 0;
    }
    return 1;
}



int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
