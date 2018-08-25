#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdlib.h>

typedef struct {
  int *data;
  size_t size;
  int *read_pointer;
  int *write_pointer;
} circular_buffer_t;

void cb_init(circular_buffer_t **cb, size_t size);
void cb_free(circular_buffer_t *cb);

int cb_peek(circular_buffer_t *cb);
int cb_read(circular_buffer_t *cb);
void cb_write(circular_buffer_t *cb, int value);

#endif
