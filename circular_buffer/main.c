#include <stdio.h>

#include "circular_buffer.h"

int main() {
  circular_buffer_t *cb = NULL;
  cb_init(&cb, 5);
  printf("Data start: %p\n", cb->data);
  printf("value\taddress\n");
  for (int i = 0; i < 20; i++) {
    cb_write(cb, i);
    printf("%d\t%p\n", cb_read(cb), cb->read_pointer);
  }
  cb_free(cb);
}
