#include <stdbool.h>
#include "driver/gpio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led.h"

static const char *TAG = "LED";
static bool led_initialized = false;
static bool led_state = false;

// GPIO pin for LED (can be changed based on your board)
#define LED_GPIO_PIN GPIO_NUM_2

void led_init(void)
{
    ESP_LOGI(TAG, "Initializing LED module");
    
    // Configure GPIO pin
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << LED_GPIO_PIN),
        .pull_down_en = 0,
        .pull_up_en = 0,
    };
    
    esp_err_t err = gpio_config(&io_conf);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to configure GPIO: %s", esp_err_to_name(err));
        return;
    }
    
    // Initialize LED to OFF state
    gpio_set_level(LED_GPIO_PIN, 0);
    led_state = false;
    led_initialized = true;
    
    ESP_LOGI(TAG, "LED module initialized successfully on GPIO %d", LED_GPIO_PIN);
}

void led_turn_on(void)
{
    if (!led_initialized) {
        ESP_LOGE(TAG, "LED not initialized");
        return;
    }
    
    gpio_set_level(LED_GPIO_PIN, 1);
    led_state = true;
    ESP_LOGD(TAG, "LED turned ON");
}

void led_turn_off(void)
{
    if (!led_initialized) {
        ESP_LOGE(TAG, "LED not initialized");
        return;
    }
    
    gpio_set_level(LED_GPIO_PIN, 0);
    led_state = false;
    ESP_LOGD(TAG, "LED turned OFF");
}

void led_toggle(void)
{
    if (!led_initialized) {
        ESP_LOGE(TAG, "LED not initialized");
        return;
    }
    
    if (led_state) {
        led_turn_off();
    } else {
        led_turn_on();
    }
}

bool led_get_state(void)
{
    return led_state;
}

void led_blink(int blink_count, int delay_ms)
{
    if (!led_initialized) {
        ESP_LOGE(TAG, "LED not initialized");
        return;
    }
    
    ESP_LOGI(TAG, "Blinking LED %d times with %d ms delay", blink_count, delay_ms);
    
    for (int i = 0; i < blink_count; i++) {
        led_turn_on();
        vTaskDelay(pdMS_TO_TICKS(delay_ms));
        led_turn_off();
        vTaskDelay(pdMS_TO_TICKS(delay_ms));
    }
}