#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"

/**
 * @brief mapping between the segment and the used GPIO
 * 
 */
const uint A = 11;
const uint B = 9;
const uint C = 7;
const uint D = 5;
const uint E = 4;
const uint F = 10;
const uint G = 8;
const uint DP = 6;

static inline void gpio_init_segments()
{
    gpio_init(0);
    gpio_init(1);
    gpio_init(2);
    gpio_init(3);
    gpio_init(4);
    gpio_init(5);
    gpio_init(6);
    gpio_init(7);
    gpio_init(8);
    gpio_init(9);
    gpio_init(10);
    gpio_init(11);
    gpio_set_dir(0, GPIO_OUT);
    gpio_set_dir(1, GPIO_OUT);
    gpio_set_dir(2, GPIO_OUT);
    gpio_set_dir(3, GPIO_OUT);
    gpio_set_dir(4, GPIO_OUT);
    gpio_set_dir(5, GPIO_OUT);
    gpio_set_dir(6, GPIO_OUT);
    gpio_set_dir(7, GPIO_OUT);
    gpio_set_dir(8, GPIO_OUT);
    gpio_set_dir(9, GPIO_OUT);
    gpio_set_dir(10, GPIO_OUT);
    gpio_set_dir(11, GPIO_OUT);
}

static inline void build0()
{
    gpio_put(A, 0);
    gpio_put(B, 0);
    gpio_put(C, 0);
    gpio_put(D, 0);
    gpio_put(E, 0);
    gpio_put(F, 0);
    gpio_put(G, 1);
    gpio_put(DP, 1);
}

static inline void build1()
{
    gpio_put(A, 1);
    gpio_put(B, 0);
    gpio_put(C, 0);
    gpio_put(D, 1);
    gpio_put(E, 1);
    gpio_put(F, 1);
    gpio_put(G, 1);
    gpio_put(DP, 1);
}

static inline void build2()
{
    gpio_put(A, 0);
    gpio_put(B, 0);
    gpio_put(C, 1);
    gpio_put(D, 0);
    gpio_put(E, 0);
    gpio_put(F, 1);
    gpio_put(G, 0);
    gpio_put(DP, 1);
}

static inline void build3()
{
    gpio_put(A, 0);
    gpio_put(B, 0);
    gpio_put(C, 0);
    gpio_put(D, 0);
    gpio_put(E, 1);
    gpio_put(F, 1);
    gpio_put(G, 0);
    gpio_put(DP, 1);
}

static inline void build4()
{
    gpio_put(A, 1);
    gpio_put(B, 0);
    gpio_put(C, 0);
    gpio_put(D, 1);
    gpio_put(E, 1);
    gpio_put(F, 0);
    gpio_put(G, 0);
    gpio_put(DP, 1);
}

static inline void build5()
{
    gpio_put(A, 0);
    gpio_put(B, 1);
    gpio_put(C, 0);
    gpio_put(D, 0);
    gpio_put(E, 1);
    gpio_put(F, 0);
    gpio_put(G, 0);
    gpio_put(DP, 1);
}

static inline void build6()
{
    gpio_put(A, 1);
    gpio_put(B, 1);
    gpio_put(C, 0);
    gpio_put(D, 0);
    gpio_put(E, 0);
    gpio_put(F, 0);
    gpio_put(G, 0);
    gpio_put(DP, 1);
}

static inline void build7()
{
    gpio_put(A, 0);
    gpio_put(B, 0);
    gpio_put(C, 0);
    gpio_put(D, 1);
    gpio_put(E, 1);
    gpio_put(F, 1);
    gpio_put(G, 1);
    gpio_put(DP, 1);
}

static inline void build8()
{
    gpio_put(A, 0);
    gpio_put(B, 0);
    gpio_put(C, 0);
    gpio_put(D, 0);
    gpio_put(E, 0);
    gpio_put(F, 0);
    gpio_put(G, 0);
    gpio_put(DP, 1);
}

static inline void build9()
{
    gpio_put(A, 0);
    gpio_put(B, 0);
    gpio_put(C, 0);
    gpio_put(D, 1);
    gpio_put(E, 1);
    gpio_put(F, 0);
    gpio_put(G, 0);
    gpio_put(DP, 1);
}

static inline void buildFigure(int figure, int dp)
{
    switch (figure)
    {
    case 0:
        build0();
        break;
    case 1:
        build1();
        break;
    case 2:
        build2();
        break;
    case 3:
        build3();
        break;
    case 4:
        build4();
        break;
    case 5:
        build5();
        break;
    case 6:
        build6();
        break;
    case 7:
        build7();
        break;
    case 8:
        build8();
        break;
    case 9:
        build9();
        break;
    }
    if (dp)
    {
        gpio_put(DP, 0);
    }
}

static inline float getTemperature()
{
    uint16_t raw = adc_read();
    const float conversion_factor = 3.3f / (1 << 12);
    float voltage = raw * conversion_factor;
    float result = 27 - (voltage - 0.706) / 0.001721;
    printf("Temperature : %f C\n", result);
    return result;
}

int main()
{
    stdio_init_all();
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
    //Led init
    gpio_init_segments();
    int refreshTemperature = 0;
    float temperature = getTemperature();
    int digitNumber = 3;
    int tmp = 0;
    while (1 == 1)
    {
        switch (digitNumber)
        {
        case 3:
            tmp = temperature / 10;
            gpio_put(0, 0);
            gpio_put(1, 0);
            gpio_put(2, 0);
            gpio_put(3, 1);
            buildFigure(tmp, 0);
            break;
        case 2:
            tmp = (int)temperature % 10;
            gpio_put(0, 0);
            gpio_put(1, 0);
            gpio_put(2, 1);
            gpio_put(3, 0);
            buildFigure(tmp, 1);
            break;
        case 1:
            tmp = (int)(temperature * 10) % 10;
            gpio_put(0, 0);
            gpio_put(1, 1);
            gpio_put(2, 0);
            gpio_put(3, 0);
            buildFigure(tmp, 0);
            break;
        case 0:
            tmp = (int)(temperature * 100) % 10;
            gpio_put(0, 1);
            gpio_put(1, 0);
            gpio_put(2, 0);
            gpio_put(3, 0);
            buildFigure(tmp, 0);
            break;
        }
        digitNumber--;
        refreshTemperature++;
        if (digitNumber < 0)
        {
            digitNumber = 3;
            if (refreshTemperature == 100)
            {
                temperature = getTemperature();
                refreshTemperature = 0;
            }
        }
        sleep_ms(5);
    }
    return 0;
}
