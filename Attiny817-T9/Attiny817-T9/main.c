#include <atmel_start.h>

extern volatile uint8_t measurement_done_touch;

uint8_t keyStatus = 0;

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	cpu_irq_enable(); /* Global Interrupt Enable */

	/* Replace with your application code */
	while (1) {
		touch_process();
		if (measurement_done_touch == 1) {
			measurement_done_touch = 0;
			keyStatus = get_sensor_state(0) & KEY_TOUCHED_MASK;
			if (0u != keyStatus) {
				LED1_set_level(false);
				} else {
				LED1_set_level(true);
			}
			keyStatus = get_sensor_state(1) & KEY_TOUCHED_MASK;
			if (0u != keyStatus) {
				LED2_set_level(false);
				} else {
				LED2_set_level(true);
			}
			keyStatus = get_sensor_state(2) & KEY_TOUCHED_MASK;
			if (0u != keyStatus) {
				LED3_set_level(false);
				} else {
				LED3_set_level(true);
			}
			keyStatus = get_sensor_state(3) & KEY_TOUCHED_MASK;
			if (0u != keyStatus) {
				LED4_set_level(false);
				} else {
				LED4_set_level(true);
			}
		}
	}
}
