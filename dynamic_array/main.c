#include <stdio.h>

#include "dynamic_array.h"

int main() {
  dynamic_array_t *dynarr = dynarr_init();

  printf("index\tvalue\tcapacity\n");
  for (int i = 0; i < 10; i++) {
    dynarr_append(dynarr, i * 2);
    printf("%d\t%d\t%d\t\n", i, dynarr_get(dynarr, i), dynarr->capacity);
  }

  printf("size\tcapacity\n");
  for (int i = 0; i < 10; i++) {
    dynarr_remove(dynarr, 0);
    printf("%d\t%d\n", dynarr->logical_size, dynarr->capacity);
  }
  dynarr_free(dynarr);
}
