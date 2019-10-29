#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H

// Configuration required by CMSIS RTOS components.

/*
 * Define the Device Header File:
 */
#define CMSIS_device_header "sam.h"

// The following are selectively defined by Keil but not used in source.
// #define RTE_RTOS_FreeRTOS_CONFIG_RTOS2
// #define RTE_RTOS_FreeRTOS_CONFIG
// #define RTE_RTOS_FreeRTOS_CORE
// #define RTE_RTOS_FreeRTOS_TIMERS
// #define RTE_Compiler_EventRecorder
// #define RTE_Compiler_EventRecorder_DAP

// Define one of the following if using heap implementations 1 or 5 and CMSIS RTOS 1 or 2 functions.
// They control release of task memory on thread completion.
#define RTE_RTOS_FreeRTOS_HEAP_1        /* RTOS FreeRTOS Heap 1 */
// #define RTE_RTOS_FreeRTOS_HEAP_5        /* RTOS FreeRTOS Heap 5 */


#endif /* RTE_COMPONENTS_H */
