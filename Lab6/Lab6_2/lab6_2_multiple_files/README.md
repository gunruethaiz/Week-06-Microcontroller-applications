# Lab6_2 Multiple Files Example

This project demonstrates how to organize ESP32 code into multiple source files and modules.

## Project Structure

```
lab6_2_multiple_files/
├── CMakeLists.txt          # Project configuration
├── .gitignore              # Git ignore file
├── main/
│   ├── CMakeLists.txt      # Main component configuration
│   ├── lab6_2_multiple_files.c # Main application file
│   ├── sensor.c            # Sensor module implementation
│   ├── sensor.h            # Sensor module header
│   ├── display.c           # Display module implementation
│   ├── display.h           # Display module header
│   ├── led.c               # LED module implementation
│   └── led.h               # LED module header
├── build/                  # Build output directory
└── README.md               # This file
```

## Features

- **Modular Design**: Code is organized into separate modules for better maintainability
- **Sensor Module**: Simulates temperature and humidity readings
- **Display Module**: Handles data display functionality
- **LED Module**: Controls LED based on sensor readings
- **Main Application**: Orchestrates all modules

## Building the Project

### Using ESP-IDF directly:
```bash
idf.py build
idf.py flash monitor
```

### Using Docker:
```bash
docker-compose up -d
docker exec -it esp32-dev bash
idf.py build
```

## Module Description

### Sensor Module (`sensor.c`, `sensor.h`)
- Initializes sensor hardware
- Provides temperature and humidity readings
- Includes error handling and status checking

### Display Module (`display.c`, `display.h`)
- Handles display initialization
- Shows sensor data in formatted output
- Supports custom messages

### LED Module (`led.c`, `led.h`)
- Controls GPIO-connected LED
- Supports on/off/toggle operations
- Includes blinking functionality

### Main Application (`lab6_2_multiple_files.c`)
- Initializes all modules
- Implements main application loop
- Coordinates data flow between modules

## Hardware Requirements

- ESP32 development board
- LED connected to GPIO2 (configurable in `led.c`)
- Optional: Temperature/humidity sensor (DHT22, etc.)

## Configuration

- LED GPIO pin can be changed in `led.c` by modifying `LED_GPIO_PIN`
- Sensor simulation parameters can be adjusted in `sensor.c`
- Log levels can be configured through ESP-IDF menuconfig

## Learning Objectives

1. Understanding ESP-IDF project structure
2. Creating modular C code
3. Managing header files and dependencies
4. Using CMake build system with ESP-IDF
5. Implementing hardware abstraction layers