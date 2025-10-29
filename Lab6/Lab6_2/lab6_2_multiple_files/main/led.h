#ifndef LED_H
#define LED_H

#include <stdbool.h>

/**
 * @brief Initialize the LED module
 */
void led_init(void);

/**
 * @brief Turn on the LED
 */
void led_turn_on(void);

/**
 * @brief Turn off the LED
 */
void led_turn_off(void);

/**
 * @brief Toggle the LED state
 */
void led_toggle(void);

/**
 * @brief Get LED state
 * @return true if LED is on, false if off
 */
bool led_get_state(void);

/**
 * @brief Blink LED for specified duration
 * @param blink_count Number of blinks
 * @param delay_ms Delay between blinks in milliseconds
 */
void led_blink(int blink_count, int delay_ms);

#endif // LED_H