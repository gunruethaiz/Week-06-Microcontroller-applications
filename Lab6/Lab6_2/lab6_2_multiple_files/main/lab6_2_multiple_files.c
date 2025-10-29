#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "sensor.h"
#include "display.h"
#include "led.h"

static const char *TAG = "LAB6_2";

void app_main(void)
{
    ESP_LOGI(TAG, "Starting Lab6_2 Multiple Files Example");
    
    // Initialize modules
    sensor_init();
    display_init();
    led_init();
    
    // Main application loop
    while (1) {
        // Read sensor data
        float temperature = sensor_read_temperature();
        int humidity = sensor_read_humidity();
        
        // Display data
        display_show_data(temperature, humidity);
        
        // Control LED based on temperature
        if (temperature > 30.0) {
            led_turn_on();
            ESP_LOGW(TAG, "High temperature detected: %.2f°C", temperature);
        } else {
            led_turn_off();
        }
        
        // Wait 2 seconds before next reading
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}