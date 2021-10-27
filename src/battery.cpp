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

// get voltage on a specific pin
float Battery::pin_voltage(PinName pin) { 
    AnalogIn analog_pin(pin);
    uint16_t vref = adc_vref.read_u16();

    // external voltage may have spikes and drops so calculate average (10 samples)
    float avg_vpin = 0;
    for (int i = 0; i < 10; i++) {
        avg_vpin += analog_pin.read_u16();
    }
    avg_vpin /= 10;

    float vrefplus = V_REF_PLUS_CHAR * v_ref_cal / vref;
    return (vrefplus * avg_vpin) / FULL_SCALE;
}