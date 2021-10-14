#pragma once

#include "mbed.h"

#define V_REFINT 1.212
AnalogIn adc_vref(ADC_VREF);
AnalogIn adc_vbat(ADC_VBAT);

class Battery {
    public:
        Battery();
        float voltage();
};