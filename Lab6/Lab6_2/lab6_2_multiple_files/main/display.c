#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "display.h"

static const char *TAG = "DISPLAY";
static bool display_initialized = false;

void display_init(void)
{
    ESP_LOGI(TAG, "Initializing display module");
    
    // Simulate display initialization
    vTaskDelay(pdMS_TO_TICKS(50));
    
    display_initialized = true;
    ESP_LOGI(TAG, "Display module initialized successfully");
    
    // Show welcome message
    display_show_message("Lab6_2 Ready!");
}

void display_show_data(float temperature, int humidity)
{
    if (!display_initialized) {
        ESP_LOGE(TAG, "Display not initialized");
        return;
    }
    
    ESP_LOGI(TAG, "=== SENSOR DATA ===");
    ESP_LOGI(TAG, "Temperature: %.2f°C", temperature);
    ESP_LOGI(TAG, "Humidity: %d%%", humidity);
    ESP_LOGI(TAG, "==================");
}

void display_clear(void)
{
    if (!display_initialized) {
        ESP_LOGE(TAG, "Display not initialized");
        return;
    }
    
    ESP_LOGD(TAG, "Display cleared");
}

void display_show_message(const char *message)
{
    if (!display_initialized) {
        ESP_LOGE(TAG, "Display not initialized");
        return;
    }
    
    if (message == NULL) {
        ESP_LOGE(TAG, "Message is NULL");
        return;
    }
    
    ESP_LOGI(TAG, "MSG: %s", message);
}