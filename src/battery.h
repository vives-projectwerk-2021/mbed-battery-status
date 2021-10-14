#pragma once

#include "mbed.h"

#define V_REF_PLUS_CHAR 3.0
#define FULL_SCALE 4095

class Battery {
    private:
        AnalogIn adc_vref;
        AnalogIn adc_vbat;
        uint16_t v_ref_cal;
    public:
        Battery();
        float voltage();
};