#include "battery.h"

Battery::Battery():
    adc_vref(ADC_VREF),
    adc_vbat(ADC_VBAT)
{
    // constructor
}

float Battery::voltage()
{
    // get voltage
    float vref = adc_vref.read();
    float vbat = adc_vbat.read() * 3;

    return V_REFINT * (vbat/vref);
}