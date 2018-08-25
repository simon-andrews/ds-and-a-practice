#include <stdlib.h>

#include "circular_buffer.h"

void cb_init(circular_buffer_t **cb, size_t size) {
  *cb = malloc(sizeof(circular_buffer_t));
  (**cb).size = size;
  (**cb).data = malloc(sizeof(int) * size);
  (**cb).read_pointer = (**cb).data;
  (**cb).write_pointer = (**cb).data;
}

void cb_free(circular_buffer_t *cb) {
  free(cb->data);
  free(cb);
}

int cb_peek(circular_buffer_t *cb) {
  return *cb->read_pointer;
}

int cb_read(circular_buffer_t *cb) {
  int ret = cb_peek(cb);
  if (cb->read_pointer != &cb->data[cb->size - 1])
    cb->read_pointer++;
  else
    cb->read_pointer = cb->data;
  return ret;
}

void cb_write(circular_buffer_t *cb, int value) {
  *(cb->write_pointer) = value;
  if (cb->write_pointer != &cb->data[cb->size - 1])
    cb->write_pointer++;
  else
    cb->write_pointer = cb->data;
}
