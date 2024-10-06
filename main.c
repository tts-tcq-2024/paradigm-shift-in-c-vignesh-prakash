#include <stdio.h>
#include <assert.h>
#include "checker.h"

int main() {
    assert(batteryIsOk(0.2, 20, 0.77));
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(!IsChargeRateOk(0.9));
}
