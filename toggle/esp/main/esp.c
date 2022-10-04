#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "../../fsm/rising_edge_fsm.h"
#include "../../fsm/toggle_fsm.h"
#include "../../fsm/debounce_fsm.h"

// input di pin 18
#define GPIO_INPUT_0 GPIO_NUM_19
#define GPIO_INPUT_PIN_SEL (1ULL << GPIO_INPUT_0)

// output di pin 2
#define GPIO_OUTPUT_0 GPIO_NUM_2
#define GPIO_OUTPUT_PIN_SEL (1ULL << GPIO_OUTPUT_0)

void ReadButtonTask(void *pvParam)
{
    int led_state = 0;

    int toggle_fsm_state = TOGGLE_OFF_STATE;
    int rising_edge_fsm_state = LOW_STATE;
    int debounce_fsm_state = IDLE_STATE;

    int debounce_fsm_output = 0;
    int debounce_counter = 0;
    int rising_edge_fsm_output = 0;

    int input;

    while (1)
    {
        // debouncing
        input = gpio_get_level(GPIO_INPUT_0);
        debounce_fsm(&debounce_fsm_state, &debounce_counter, input, &debounce_fsm_output);

        // toggling
        rising_edge_fsm(&rising_edge_fsm_state, debounce_fsm_output, &rising_edge_fsm_output);
        toggle_fsm(&toggle_fsm_state, rising_edge_fsm_output, &led_state);

        // led control
        gpio_set_level(GPIO_OUTPUT_0, led_state);

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
    gpio_config_t io_conf;

    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pull_down_en = GPIO_PULLDOWN_ENABLE;
    gpio_config(&io_conf);

    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    io_conf.mode = GPIO_MODE_OUTPUT;
    gpio_config(&io_conf);

    xTaskCreatePinnedToCore(ReadButtonTask, "Read Button Task", 2048, NULL, 1, NULL, 0);
}