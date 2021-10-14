#pragma once

#include "mbed.h"

#define V_REFINT 1.212

class Battery {
    private:
        AnalogIn adc_vref;
        AnalogIn adc_vbat;
    public:
        Battery();
        float voltage();
};