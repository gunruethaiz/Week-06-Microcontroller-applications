#ifndef SENSOR_H
#define SENSOR_H

/**
 * @brief Initialize the sensor module
 */
void sensor_init(void);

/**
 * @brief Read temperature from sensor
 * @return Temperature value in Celsius
 */
float sensor_read_temperature(void);

/**
 * @brief Read humidity from sensor
 * @return Humidity value in percentage
 */
int sensor_read_humidity(void);

/**
 * @brief Get sensor status
 * @return true if sensor is ready, false otherwise
 */
bool sensor_is_ready(void);

#endif // SENSOR_H