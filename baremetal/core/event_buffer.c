#include "event_buffer.h"

static arm_event_t buffer[EVENT_BUFFER_SIZE];
static volatile uint32_t head = 0;
static volatile uint32_t tail = 0;
static volatile uint32_t timestamp = 0;

void event_buffer_init(void)
{
    head = tail = 0;
    timestamp = 0;
}

void event_log(uint8_t source, uint8_t severity)
{
    uint32_t next = (head + 1) % EVENT_BUFFER_SIZE;

    if (next == tail) {
        // Buffer full → drop oldest
        tail = (tail + 1) % EVENT_BUFFER_SIZE;
    }

    buffer[head].timestamp = timestamp++;
    buffer[head].source    = source;
    buffer[head].severity  = severity;

    head = next;
}

int event_read(arm_event_t *evt)
{
    if (tail == head)
        return -1;

    *evt = buffer[tail];
    tail = (tail + 1) % EVENT_BUFFER_SIZE;

    return 0;
}
