#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "sensor.h"

static const char *TAG = "MAIN";

void app_main(void)
{
    ESP_LOGI(TAG, "🚀 Lab 6.2: Multiple Source Files Demo - Step 1");
    ESP_LOGI(TAG, "📍 Main function from file: %s, line: %d", __FILE__, __LINE__);
    ESP_LOGI(TAG, "ESP-IDF Version: %s", esp_get_idf_version());
    
    // Initialize sensor
    sensor_init();
    
    int counter = 0;
    
    while (1) {
        ESP_LOGI(TAG, "=== Loop %d ===", counter++);
        
        // Read sensor data every loop
        sensor_read_data();
        
        // Check sensor status every 3 loops
        if (counter % 3 == 0) {
            sensor_check_status();
        }
        
        vTaskDelay(pdMS_TO_TICKS(2000)); // 2 seconds delay
    }
}