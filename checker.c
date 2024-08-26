#include <stdio.h>
#include <assert.h>

int IstemperatureOk(float temperature) {
    if(temperature < 0 || temperature > 45) {
        printf("Temperature out of range!\n");
        return 0;
    }
        return 1;
}

int IssocOk(float soc) {
    if(soc < 20 || soc > 80) {
        printf("State of Charge out of range!\n");
        return 0;
    }
        return 1;
}

int IschargeRateOk(float chargeRate) {
    if(chargeRate > 0.8) {
        printf("Charge Rate out of range!\n");
        return 0;
    }
        return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return IstemperatureOk(temperature) && IssocOk(soc) && IschargeRateOk(chargeRate);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
