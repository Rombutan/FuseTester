#include <stdio.h>
#include "pico/stdlib.h"
#include "ads1115.h"

#include "pico-ssd1306/ssd1306.h"
#include "pico-ssd1306/ssd1306.c"
#include <stdint.h>
#include <string.h>

#define I2C_PORT i2c0
#define I2C_FREQ 400000
#define ADS1115_I2C_ADDR 0x48
const uint8_t SDA_PIN = 20;
const uint8_t SCL_PIN = 21;

struct ads1115_adc adc;

int main() {
    stdio_init_all();

    // Initialise I2C
    i2c_init(I2C_PORT, I2C_FREQ);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    // init pin for FET
    gpio_init(22);
    gpio_set_dir(22, GPIO_OUT);
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
    gpio_put(22, 0);
    gpio_put(25, 0);

    // Initialise ADC
    ads1115_init(I2C_PORT, ADS1115_I2C_ADDR, &adc);
    
    // Modify the default configuration as needed. In this example the
    // signal will be differential, measured between pins A0 and A3,
    // and the full-scale voltage range is set to +/- 4.096 V.
    ads1115_set_input_mux(ADS1115_MUX_DIFF_0_3, &adc);
    ads1115_set_pga(ADS1115_PGA_0_256, &adc);
    ads1115_set_data_rate(ADS1115_RATE_475_SPS, &adc);

    // Write the configuration for this to have an effect.
    ads1115_write_config(&adc);

    // Data containers
    float volts;
    uint16_t adc_value;

    //display stuff
    ssd1306_t disp;
    disp.external_vcc=false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c0);
    ssd1306_poweron(&disp);
    ssd1306_contrast(&disp, 250);
    ssd1306_clear(&disp);


    while (1) {
        gpio_put(22, 1);
        gpio_put(25, 1);
        sleep_ms(10);
        // Read a value, convert to volts, and print.
        ads1115_set_input_mux(ADS1115_MUX_DIFF_0_1, &adc);
        ads1115_read_adc(&adc_value, &adc);
        float curv = adc_value*0.00000390625;
        float cur = curv/0.00200;

        //ads1115_set_input_mux(ADS1115_MUX_SINGLE_2, &adc);
        //ads1115_read_adc(&adc_value, &adc);
        //float temp = adc_value;
        ads1115_set_input_mux(ADS1115_MUX_DIFF_2_3, &adc);
        ads1115_read_adc(&adc_value, &adc);
        float fusev = adc_value*0.00000390625;

        sleep_ms(10);
        gpio_put(22, 0);
        gpio_put(25, 0);

        printf("Current:%f     Voltage Drop:%f    Calculated_mResistance:%f\n", cur, fusev, fusev / cur);
        sleep_ms(1000);
    }
}