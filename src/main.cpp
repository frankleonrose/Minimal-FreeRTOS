
#include <sam.h>
#include <FreeRTOS.h>
#include "task.h"

#define LED_PORT PORT_PA17

void toggleLED() {
  static bool led = false;
  led = !led;

  if (led) {
    REG_PORT_OUT0 &= ~LED_PORT;
  }
  else {
    REG_PORT_OUT0 |= LED_PORT;
  }
}

static void toggleLedTask( void *pvParameters ) {
  const TickType_t xDelay = 500 / portTICK_PERIOD_MS;

  for( ;; )
  {
      /* Simply toggle the LED every 500ms, blocking between each toggle. */
      toggleLED();
      vTaskDelay( xDelay );
  }
}

static void setupTasks(void) {
  const size_t xRegTestStackSize = 500U;
	xTaskCreate( 	toggleLedTask,			/* Function that implements the task. */
					"Blink", 				/* Text name of the task. */
					xRegTestStackSize,		/* Stack allocated to the task. */
					NULL, 					/* The task parameter is not used. */
					2, 		/* The priority to assign to the task. */
					NULL );					/* Don't receive a handle back, it is not needed. */
}

static void init() {
  SystemInit(); // SAM init

  REG_PORT_DIR0 |= LED_PORT;
}

int main() {
  init();

  toggleLED();

  setupTasks();

  vTaskStartScheduler();

  for( ;; ) {
  }
}

