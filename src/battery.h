#pragma once

#include "mbed.h"

#ifndef STM32L4
    #error Different architecture then STM32L4xx detected
#endif

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