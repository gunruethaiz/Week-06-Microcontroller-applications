#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sensor.h"

static const char *TAG = "SENSOR";
static bool sensor_initialized = false;

void sensor_init(void)
{
    ESP_LOGI(TAG, "Initializing sensor module");
    
    // Simulate sensor initialization
    vTaskDelay(pdMS_TO_TICKS(100));
    
    sensor_initialized = true;
    ESP_LOGI(TAG, "Sensor module initialized successfully");
}

float sensor_read_temperature(void)
{
    if (!sensor_initialized) {
        ESP_LOGE(TAG, "Sensor not initialized");
        return 0.0;
    }
    
    // Simulate temperature reading (random value between 20-35°C)
    float temperature = 20.0 + (rand() % 1500) / 100.0;
    
    ESP_LOGD(TAG, "Temperature read: %.2f°C", temperature);
    return temperature;
}

int sensor_read_humidity(void)
{
    if (!sensor_initialized) {
        ESP_LOGE(TAG, "Sensor not initialized");
        return 0;
    }
    
    // Simulate humidity reading (random value between 30-80%)
    int humidity = 30 + (rand() % 51);
    
    ESP_LOGD(TAG, "Humidity read: %d%%", humidity);
    return humidity;
}

bool sensor_is_ready(void)
{
    return sensor_initialized;
}