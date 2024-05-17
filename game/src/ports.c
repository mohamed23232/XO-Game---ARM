// Including necessary header files for the program
#include "..\./headers/tm4c123gh6pm.h"
#include "..\./headers/ports.h"

// Declaring global variables SW1 and SW2 of type unsigned long
extern unsigned long SW1, SW2;

// Declaring a volatile unsigned long variable named 'delay'
volatile unsigned long delay;

// Function to initialize Port B

Gpio_Ret_t PORT_init(Gpio_config_t *config, Gpio_port_t portNum)
{
	int flag;
	int pinNum;
	
	

	switch(portNum){
		case 0:
			SYSCTL_RCGC2_R |= (1<<portNum);   // Enabling clock for Port B
			delay = SYSCTL_RCGCGPIO_R;      // Delaying 3-5 clock cycles
			GPIO_PORTA_LOCK_R = 0x4C4F434B; // Unlocking Port B

	for (pinNum = 0; pinNum < PIN_MAX_NUM; pinNum++)
        {
            GPIO_PORTA_CR_R |= (1 << pinNum);
					
					if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTA_DEN_R |= (1 << pinNum);
                GPIO_PORTA_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTA_DEN_R &= ~(1 << pinNum);
                GPIO_PORTA_AMSEL_R |= (1 << pinNum);
            }
					if(config->portsCfgs[portNum].pinsCfgs[pinNum].pinDirection == GPIO_DIRECTION_INPUT){
                            GPIO_PORTA_DIR_R &= ~(1 << pinNum);
    
            }
            else{
														GPIO_PORTA_DIR_R |= (1 << pinNum);

            }
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].alternateFunction == GPIO_ENABLE)
            {
                GPIO_PORTA_AFSEL_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTA_AFSEL_R &= ~(1 << pinNum);
            }
						 if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTA_DEN_R |= (1 << pinNum);
                GPIO_PORTA_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTA_DEN_R &= ~(1 << pinNum);
                GPIO_PORTA_AMSEL_R |= (1 << pinNum);
            }
						if (config->portsCfgs[portNum].pinsCfgs[pinNum].pullUp == GPIO_ENABLE){
                GPIO_PORTA_PUR_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTA_PUR_R &= ~(1 << pinNum);
            }
if (config->portsCfgs[portNum].pinsCfgs[pinNum].interrupts == GPIO_ENABLE){
                flag = 1;
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].sense == GPIO_EDGE) {
                    GPIO_PORTA_IS_R &= ~(1 << pinNum);
                }
                else {
                    GPIO_PORTA_IS_R |= (1 << pinNum);
                }
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].edge == GPIO_SINGLE_EDGE){
                    GPIO_PORTA_IBE_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTA_IBE_R |= (1 << pinNum);
                }
                if(config->portsCfgs[portNum].pinsCfgs[pinNum].level == GPIO_FALLING_EDGE){
                    GPIO_PORTA_IEV_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTA_IEV_R |= (1 << pinNum);
                }
                GPIO_PORTA_ICR_R |= (1 << pinNum);
                GPIO_PORTA_IM_R |= (1 << pinNum);
            }
						GPIO_PORTA_PCTL_R &= (1 << pinNum);
				}
				break;
		case 1:
			SYSCTL_RCGC2_R |= (1<<portNum);   // Enabling clock for Port B
			delay = SYSCTL_RCGCGPIO_R;      // Delaying 3-5 clock cycles
				GPIO_PORTB_LOCK_R = 0x4C4F434B; // Unlocking Port B

	for (pinNum = 0; pinNum < PIN_MAX_NUM; pinNum++)
        {
            GPIO_PORTB_CR_R |= (1 << pinNum);
					
					if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTB_DEN_R |= (1 << pinNum);
                GPIO_PORTB_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTB_DEN_R &= ~(1 << pinNum);
                GPIO_PORTB_AMSEL_R |= (1 << pinNum);
            }
					if(config->portsCfgs[portNum].pinsCfgs[pinNum].pinDirection == GPIO_DIRECTION_INPUT){
                            GPIO_PORTB_DIR_R &= ~(1 << pinNum);
    
            }
            else{
														GPIO_PORTB_DIR_R |= (1 << pinNum);

            }
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].alternateFunction == GPIO_ENABLE)
            {
                GPIO_PORTB_AFSEL_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTB_AFSEL_R &= ~(1 << pinNum);
            }
						 if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTB_DEN_R |= (1 << pinNum);
                GPIO_PORTB_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTB_DEN_R &= ~(1 << pinNum);
                GPIO_PORTB_AMSEL_R |= (1 << pinNum);
            }
						if (config->portsCfgs[portNum].pinsCfgs[pinNum].pullUp == GPIO_ENABLE){
                GPIO_PORTB_PUR_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTB_PUR_R &= ~(1 << pinNum);
            }
if (config->portsCfgs[portNum].pinsCfgs[pinNum].interrupts == GPIO_ENABLE){
                flag = 1;
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].sense == GPIO_EDGE) {
                    GPIO_PORTB_IS_R &= ~(1 << pinNum);
                }
                else {
                    GPIO_PORTB_IS_R |= (1 << pinNum);
                }
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].edge == GPIO_SINGLE_EDGE){
                    GPIO_PORTB_IBE_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTB_IBE_R |= (1 << pinNum);
                }
                if(config->portsCfgs[portNum].pinsCfgs[pinNum].level == GPIO_FALLING_EDGE){
                    GPIO_PORTB_IEV_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTB_IEV_R |= (1 << pinNum);
                }
                GPIO_PORTB_ICR_R |= (1 << pinNum);
                GPIO_PORTB_IM_R |= (1 << pinNum);
            }
						GPIO_PORTB_PCTL_R &= (1 << pinNum);
				}
				break;
		case 2:
			SYSCTL_RCGC2_R |= (1<<portNum);   // Enabling clock for Port B
			delay = SYSCTL_RCGCGPIO_R;      // Delaying 3-5 clock cycles
			GPIO_PORTC_LOCK_R = 0x4C4F434B; // Unlocking Port B

	for (pinNum = 0; pinNum < PIN_MAX_NUM; pinNum++)
        {
            GPIO_PORTC_CR_R |= (1 << pinNum);
					
					if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTC_DEN_R |= (1 << pinNum);
                GPIO_PORTC_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTC_DEN_R &= ~(1 << pinNum);
                GPIO_PORTC_AMSEL_R |= (1 << pinNum);
            }
					if(config->portsCfgs[portNum].pinsCfgs[pinNum].pinDirection == GPIO_DIRECTION_INPUT){
                            GPIO_PORTC_DIR_R &= ~(1 << pinNum);
    
            }
            else{
														GPIO_PORTC_DIR_R |= (1 << pinNum);

            }
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].alternateFunction == GPIO_ENABLE)
            {
                GPIO_PORTC_AFSEL_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTC_AFSEL_R &= ~(1 << pinNum);
            }
						 if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTC_DEN_R |= (1 << pinNum);
                GPIO_PORTC_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTC_DEN_R &= ~(1 << pinNum);
                GPIO_PORTC_AMSEL_R |= (1 << pinNum);
            }
						if (config->portsCfgs[portNum].pinsCfgs[pinNum].pullUp == GPIO_ENABLE){
                GPIO_PORTC_PUR_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTC_PUR_R &= ~(1 << pinNum);
            }
if (config->portsCfgs[portNum].pinsCfgs[pinNum].interrupts == GPIO_ENABLE){
                flag = 1;
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].sense == GPIO_EDGE) {
                    GPIO_PORTC_IS_R &= ~(1 << pinNum);
                }
                else {
                    GPIO_PORTC_IS_R |= (1 << pinNum);
                }
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].edge == GPIO_SINGLE_EDGE){
                    GPIO_PORTC_IBE_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTC_IBE_R |= (1 << pinNum);
                }
                if(config->portsCfgs[portNum].pinsCfgs[pinNum].level == GPIO_FALLING_EDGE){
                    GPIO_PORTC_IEV_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTC_IEV_R |= (1 << pinNum);
                }
                GPIO_PORTC_ICR_R |= (1 << pinNum);
                GPIO_PORTC_IM_R |= (1 << pinNum);
            }
						GPIO_PORTC_PCTL_R &= (1 << pinNum);
				}
		case 3: break;
		case 4: break;
		case 5: break;
	}
	
	GPIO_PORTB_LOCK_R = 0x4C4F434B; // Unlocking Port B

	for (pinNum = 0; pinNum < PIN_MAX_NUM; pinNum++)
        {
            GPIO_PORTB_CR_R |= (1 << pinNum);
					
					if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTB_DEN_R |= (1 << pinNum);
                GPIO_PORTB_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTB_DEN_R &= ~(1 << pinNum);
                GPIO_PORTB_AMSEL_R |= (1 << pinNum);
            }
					if(config->portsCfgs[portNum].pinsCfgs[pinNum].pinDirection == GPIO_DIRECTION_INPUT){
                            GPIO_PORTB_DIR_R &= ~(1 << pinNum);
    
            }
            else{
														GPIO_PORTB_DIR_R |= (1 << pinNum);

            }
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].alternateFunction == GPIO_ENABLE)
            {
                GPIO_PORTB_AFSEL_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTB_AFSEL_R &= ~(1 << pinNum);
            }
						 if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTB_DEN_R |= (1 << pinNum);
                GPIO_PORTB_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTB_DEN_R &= ~(1 << pinNum);
                GPIO_PORTB_AMSEL_R |= (1 << pinNum);
            }
						if (config->portsCfgs[portNum].pinsCfgs[pinNum].pullUp == GPIO_ENABLE){
                GPIO_PORTB_PUR_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTB_PUR_R &= ~(1 << pinNum);
            }
if (config->portsCfgs[portNum].pinsCfgs[pinNum].interrupts == GPIO_ENABLE){
                flag = 1;
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].sense == GPIO_EDGE) {
                    GPIO_PORTB_IS_R &= ~(1 << pinNum);
                }
                else {
                    GPIO_PORTB_IS_R |= (1 << pinNum);
                }
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].edge == GPIO_SINGLE_EDGE){
                    GPIO_PORTB_IBE_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTB_IBE_R |= (1 << pinNum);
                }
                if(config->portsCfgs[portNum].pinsCfgs[pinNum].level == GPIO_FALLING_EDGE){
                    GPIO_PORTB_IEV_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTB_IEV_R |= (1 << pinNum);
                }
                GPIO_PORTB_ICR_R |= (1 << pinNum);
                GPIO_PORTB_IM_R |= (1 << pinNum);
            }
						GPIO_PORTB_PCTL_R &= (1 << pinNum);
				}

	// Configuring the priority of the interrupt handlers
	NVIC_PRI0_R = (NVIC_PRI0_R & 0xffff8fff) | 0x00000000;	// Preority = 0 best heighest one 

	// Enabling interrupts for Port B in NVIC register			// IRQ = 1
	NVIC_EN0_R = 0x00000002;

	// Enabling global interrupts
	EnableInterrupts();
	return GPIO_RET_OK;
}





// Interrupt handler for Port B
void GPIOPortB_Handler(void)
{	
	if (GPIO_PORTB_MIS_R & (1 << GPIO_PIN_4))   	// Checking if interrupt is caused by PB4
	{

			GPIO_PORTB_ICR_R |= (1 << GPIO_PIN_4); 	// Clearing the interrupt flag for PB4
			Delay100ms(2);        
			SW1 = 1;                		// Setting SW1 to 1 
			SW2 = 0;                		// Setting SW2 to 0 
		//}
	}
	else if (GPIO_PORTB_MIS_R & (1 << GPIO_PIN_0)) // Checking if interrupt is caused by PB0
	{

		
			GPIO_PORTB_ICR_R |= (1 << GPIO_PIN_0);   	// Clearing the interrupt flag for PB0
			Delay100ms(2);            		
			SW1 = 0;                  		// Setting SW1 to 0 
			SW2 = 1;                  		// Setting SW2 to 1 
		//}
	}	
}
