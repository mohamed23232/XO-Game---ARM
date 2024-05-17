#include "ports.h"

// Configuration structure for GPIO port B
Gpio_config_t portCfg = {
    .portsCfgs[GPIO_PORT_B] = {
        .portEnable = GPIO_PORT_ENABLE,   // Enable GPIO port B
        .pinsCfgs[GPIO_PIN_0] = {
            .digitalAnalogSelector = GPIO_MODE_DIGITAL, // Set pin 0 to digital mode
            .pinDirection = GPIO_DIRECTION_INPUT,      // Configure pin 0 as input
            .pullUp = GPIO_ENABLE,                     // Enable pull-up resistor for pin 0
            .pullDown = GPIO_DISABLE,                  // Disable pull-down resistor for pin 0
            .alternateFunction = GPIO_DISABLE,         // Disable alternate function for pin 0
            .interrupts = GPIO_ENABLE,                 // Enable interrupts for pin 0
            .sense = GPIO_EDGE,                        // Set interrupt to be edge-sensitive
            .edge = GPIO_SINGLE_EDGE,                  // Configure for single edge detection
            .level = GPIO_FALLING_EDGE,                // Trigger interrupt on falling edge
            .mask = GPIO_NOT_MASKED,                   // Do not mask the pin 0 interrupt
        },
        .pinsCfgs[GPIO_PIN_1] = {
            .digitalAnalogSelector = GPIO_MODE_DIGITAL, // Set pin 1 to digital mode
            .pinDirection = GPIO_DIRECTION_OUTPUT,     // Configure pin 1 as output
            .pullUp = GPIO_DISABLE,                    // Disable pull-up resistor for pin 1
            .pullDown = GPIO_DISABLE,                  // Disable pull-down resistor for pin 1
            .alternateFunction = GPIO_DISABLE,         // Disable alternate function for pin 1
        },
        .pinsCfgs[GPIO_PIN_2] = {
            .digitalAnalogSelector = GPIO_MODE_DIGITAL, // Set pin 2 to digital mode
            .pinDirection = GPIO_DIRECTION_OUTPUT,     // Configure pin 2 as output
            .pullUp = GPIO_DISABLE,                    // Disable pull-up resistor for pin 2
            .pullDown = GPIO_DISABLE,                  // Disable pull-down resistor for pin 2
            .alternateFunction = GPIO_DISABLE,         // Disable alternate function for pin 2
        },
        .pinsCfgs[GPIO_PIN_3] = {
            .digitalAnalogSelector = GPIO_MODE_DIGITAL, // Set pin 3 to digital mode
            .pinDirection = GPIO_DIRECTION_OUTPUT,     // Configure pin 3 as output
            .pullUp = GPIO_DISABLE,                    // Disable pull-up resistor for pin 3
            .pullDown = GPIO_DISABLE,                  // Disable pull-down resistor for pin 3
            .alternateFunction = GPIO_DISABLE,         // Disable alternate function for pin 3
        },
        .pinsCfgs[GPIO_PIN_4] = {
            .digitalAnalogSelector = GPIO_MODE_DIGITAL, // Set pin 4 to digital mode
            .pinDirection = GPIO_DIRECTION_INPUT,      // Configure pin 4 as input
            .pullUp = GPIO_ENABLE,                     // Enable pull-up resistor for pin 4
            .pullDown = GPIO_DISABLE,                  // Disable pull-down resistor for pin 4
            .alternateFunction = GPIO_DISABLE,         // Disable alternate function for pin 4
            .interrupts = GPIO_ENABLE,                 // Enable interrupts for pin 4
            .sense = GPIO_EDGE,                        // Set interrupt to be edge-sensitive
            .edge = GPIO_SINGLE_EDGE,                  // Configure for single edge detection
            .level = GPIO_FALLING_EDGE,                // Trigger interrupt on falling edge
            .mask = GPIO_NOT_MASKED,                   // Do not mask the pin 4 interrupt
        },
        .pinsCfgs[GPIO_PIN_5] = {
            .digitalAnalogSelector = GPIO_MODE_DIGITAL, // Set pin 5 to digital mode
            .pinDirection = GPIO_DIRECTION_OUTPUT,     // Configure pin 5 as output
            .pullUp = GPIO_DISABLE,                    // Disable pull-up resistor for pin 5
            .pullDown = GPIO_DISABLE,                  // Disable pull-down resistor for pin 5
            .alternateFunction = GPIO_DISABLE,         // Disable alternate function for pin 5
        },
        .pinsCfgs[GPIO_PIN_6] = {
            .digitalAnalogSelector = GPIO_MODE_DIGITAL, // Set pin 6 to digital mode
            .pinDirection = GPIO_DIRECTION_OUTPUT,     // Configure pin 6 as output
            .pullUp = GPIO_DISABLE,                    // Disable pull-up resistor for pin 6
            .pullDown = GPIO_DISABLE,                  // Disable pull-down resistor for pin 6
            .alternateFunction = GPIO_DISABLE,         // Disable alternate function for pin 6
        },
        .pinsCfgs[GPIO_PIN_7] = {
            .digitalAnalogSelector = GPIO_MODE_DIGITAL, // Set pin 7 to digital mode
            .pinDirection = GPIO_DIRECTION_OUTPUT,     // Configure pin 7 as output
            .pullUp = GPIO_DISABLE,                    // Disable pull-up resistor for pin 7
            .pullDown = GPIO_DISABLE,                  // Disable pull-down resistor for pin 7
            .alternateFunction = GPIO_DISABLE,         // Disable alternate function for pin 7
        },
    },
};
