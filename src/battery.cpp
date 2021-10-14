#include "battery.h"


// constructor
Battery::Battery():
    adc_vref(ADC_VREF),
    adc_vbat(ADC_VBAT)
{
    // calibratie waarde van Vrefint (address staat in datasheet)
    v_ref_cal = *((uint16_t*)0x1FFF75AA);
}

// get voltage   
float Battery::voltage() { 
    uint16_t vref = adc_vref.read_u16();
    uint16_t vbat = adc_vbat.read_u16() * 3;

    float vrefplus = V_REF_PLUS_CHAR * v_ref_cal / vref;
    return (vrefplus * vbat) / FULL_SCALE;
}