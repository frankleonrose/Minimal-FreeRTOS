#include <FreeRTOS.h>
#include "task.h"

#if defined(ENV_1BITSY)
	/* Set GPIO8 (in GPIO port A) to 'output push-pull'. */
  #define LED_INIT() {                                             \
  	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;	/* Enable PortA clock */ \
	  GPIOA->MODER |= GPIO_MODER_MODER8_0;	/* Port A.08 output */   \
  }
  #define LED_OFF() { GPIOA->BSRR = (1 << 8); }
  #define LED_ON() { GPIOA->BSRR = (1 << (8 + 16)); }
#elif defined(ENV_SAML21_XPRO)
  #define LED_INIT() { REG_PORT_DIR1 |= PORT_PB10; }
  #define LED_OFF() { REG_PORT_OUT1 |= PORT_PB10; }
  #define LED_ON() { REG_PORT_OUT1 &= PORT_PB10; }
#elif  defined(ENV_FEATHER_M0)
  #define LED_INIT() { REG_PORT_DIR0|= PORT_PA17; }
  #define LED_OFF() { REG_PORT_OUT0 |= PORT_PA17; }
  #define LED_ON() { REG_PORT_OUT0 &= PORT_PA17; }
#else
#error Unknown build environment. Please define an ENV_XYZ flag and LED control macros.
#endif

void toggleLED() {
  static bool led = false;
  led = !led;

  if (led) {
    LED_ON();
  }
  else {
    LED_OFF();
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

  LED_INIT();
}

int main() {
  init();

  toggleLED();

  setupTasks();

  vTaskStartScheduler();

  for( ;; ) {
  }
}
