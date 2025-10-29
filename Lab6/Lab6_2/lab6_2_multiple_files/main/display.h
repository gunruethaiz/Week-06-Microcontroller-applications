#ifndef DISPLAY_H
#define DISPLAY_H

/**
 * @brief Initialize the display module
 */
void display_init(void);

/**
 * @brief Show sensor data on display
 * @param temperature Temperature value to display
 * @param humidity Humidity value to display
 */
void display_show_data(float temperature, int humidity);

/**
 * @brief Clear the display
 */
void display_clear(void);

/**
 * @brief Show a message on display
 * @param message Message string to display
 */
void display_show_message(const char *message);

#endif // DISPLAY_H