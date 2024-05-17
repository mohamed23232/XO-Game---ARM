#ifndef PORTS_H
#define PORTS_H

#include "Ports_cfg.h" // Including the configuration file for ports

// Function to enable interrupts
void EnableInterrupts(void);
// Enumeration for return types of GPIO functions
typedef enum Gpio_Ret_e{
  GPIO_RET_OK,    // Return OK status
  GPIO_RET_ERROR, // Return error status
} Gpio_Ret_t;

// Enumeration for GPIO port numbers
typedef enum Gpio_port_e{
  GPIO_PORT_A = 0,
  GPIO_PORT_B,
  GPIO_PORT_C,
  GPIO_PORT_D,
  GPIO_PORT_E,
  GPIO_PORT_F,
} Gpio_port_t;

// Enumeration for GPIO pin numbers
typedef enum Gpio_pin_e{
  GPIO_PIN_0 = 0,
  GPIO_PIN_1,
  GPIO_PIN_2,
  GPIO_PIN_3,
  GPIO_PIN_4,
  GPIO_PIN_5,
  GPIO_PIN_6,
  GPIO_PIN_7,
} Gpio_pin_t;

// Enumeration for GPIO pin directions
typedef enum Gpio_direction_e{
  GPIO_DIRECTION_INPUT = 0,
  GPIO_DIRECTION_OUTPUT,
} Gpio_direction_t;

// Enumeration for GPIO digital/analog mode
typedef enum Gpio_DigitalAnalog_e{
  GPIO_MODE_DIGITAL = 0,
  GPIO_MODE_ANALOG,
} Gpio_DigitalAnalog_t;

// Enumeration for GPIO enable/disable
typedef enum Gpio_Enable_e{
  GPIO_DISABLE = 0,
  GPIO_ENABLE,
} Gpio_Enable_t;

// Enumeration for GPIO interrupt sensing mode
typedef enum Gpio_InterruptSense_e{
  GPIO_EDGE = 0,
  GPIO_LEVEL,
} Gpio_InterruptSense_t;

// Enumeration for GPIO interrupt edge mode
typedef enum Gpio_Interrupt_Edge_e{
  GPIO_SINGLE_EDGE = 0,
  GPIO_BOTH_EDGES,
} Gpio_Interrupt_Edge_t;

// Enumeration for GPIO interrupt level mode
typedef enum Gpio_Interrupt_Level_e{
  GPIO_FALLING_EDGE = 0,
  GPIO_RISING_EDGE,
} Gpio_Interrupt_Level_t;

// Enumeration for GPIO interrupt masking
typedef enum Gpio_Interrupt_Mask_e{
  GPIO_MASKED = 0,
  GPIO_NOT_MASKED,
} Gpio_Interrupt_Mask_t;

// Enumeration for GPIO port enable/disable
typedef enum Gpio_portEnable_e{
  GPIO_PORT_ENABLE = 0,
  GPIO_PORT_DISABLE
} Gpio_portEnable_t;

// Structure for GPIO pin configuration
typedef struct Gpio_pinConfig_s{
  Gpio_DigitalAnalog_t digitalAnalogSelector; // Digital or analog mode
  Gpio_direction_t pinDirection;              // Input or output direction
  Gpio_Enable_t pullUp;                       // Enable or disable pull-up resistor
  Gpio_Enable_t pullDown;                     // Enable or disable pull-down resistor
  Gpio_Enable_t alternateFunction;            // Enable or disable alternate function
  Gpio_Enable_t interrupts;                   // Enable or disable interrupts
  Gpio_InterruptSense_t sense;                // Interrupt sensing mode (edge or level)
  Gpio_Interrupt_Edge_t edge;                 // Interrupt edge mode (single or both edges)
  Gpio_Interrupt_Level_t level;               // Interrupt level mode (falling or rising)
  Gpio_Interrupt_Mask_t mask;                 // Interrupt mask status
} Gpio_pinConfig_t;

// Structure for GPIO port configuration
typedef struct Gpio_portConfig_s{
  Gpio_pinConfig_t pinsCfgs[PIN_MAX_NUM]; // Array of pin configurations
  Gpio_portEnable_t portEnable;           // Port enable/disable status
} Gpio_portConfig_t;

// Structure for GPIO configuration
typedef struct Gpio_config_s{
    Gpio_portConfig_t portsCfgs[PORT_MAX_NUM]; // Array of port configurations
} Gpio_config_t;
extern Gpio_config_t portCfg;

// Function prototypes
Gpio_Ret_t PORT_init(Gpio_config_t *config, Gpio_port_t portNum);
Gpio_Ret_t Gpio_setDirection(Gpio_port_t port, Gpio_pin_t pin, Gpio_direction_t direction);
Gpio_Ret_t Gpio_DigitalAnalogSelector(Gpio_port_t port, Gpio_pin_t pin, Gpio_DigitalAnalog_t digitalAnalogSelector);
void GPIOPortB_Handler(void);
void PortB_Init(Gpio_config_t *config, Gpio_port_t portNum);

#endif // PORTS_H
