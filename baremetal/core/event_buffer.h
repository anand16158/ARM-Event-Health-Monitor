#ifndef EVENT_BUFFER_H
#define EVENT_BUFFER_H

#include <stdint.h>

#define EVENT_BUFFER_SIZE 64

typedef enum {
    EVENT_SRC_GPIO = 1,
    EVENT_SRC_TIMER,
    EVENT_SRC_WATCHDOG,
    EVENT_SRC_FAULT
} event_source_t;

typedef struct {
    uint32_t timestamp;
    uint8_t  source;
    uint8_t  severity;
} arm_event_t;

void event_buffer_init(void);
void event_log(uint8_t source, uint8_t severity);
int  event_read(arm_event_t *evt);

#endif
