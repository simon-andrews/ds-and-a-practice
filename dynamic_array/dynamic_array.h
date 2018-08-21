#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct {
  size_t capacity;
  size_t logical_size;
  int *data;
} dynamic_array_t;

dynamic_array_t *dynarr_init();
void dynarr_free(dynamic_array_t *dynarr);

size_t dynarr_size(dynamic_array_t *dynarr);

int dynarr_get(dynamic_array_t *dynarr, unsigned int index);
void dynarr_set(dynamic_array_t *dynarr, unsigned int index, int n);

void dynarr_append(dynamic_array_t *dynarr, int n);
void dynarr_remove(dynamic_array_t *dynarr, unsigned int index);

#endif
