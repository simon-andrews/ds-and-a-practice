#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"

const size_t growth_factor = 2;

dynamic_array_t *dynarr_init() {
  dynamic_array_t *ret = malloc(sizeof(dynamic_array_t));
  ret->capacity = 1;
  ret->logical_size = 0;
  ret->data = malloc(sizeof(int) * ret->capacity);
  return ret;
}

size_t dynarr_size(dynamic_array_t *dynarr) {
  return dynarr->logical_size;
}

int dynarr_get(dynamic_array_t *dynarr, unsigned int index) {
  assert(index < dynarr_size(dynarr));
  return dynarr->data[index];
}

void dynarr_set(dynamic_array_t *dynarr, unsigned int index, int n) {
  assert(index < dynarr_size(dynarr));
  dynarr->data[index] = n;
}

void dynarr_add_cells(dynamic_array_t *dynarr, unsigned int cells) {
  dynarr->logical_size += cells;
  if (dynarr->logical_size > dynarr->capacity) {
    dynarr->capacity *= growth_factor;
    dynarr->data = realloc(dynarr->data, sizeof(int) * dynarr->capacity);
  }
}

void dynarr_append(dynamic_array_t *dynarr, int n) {
  dynarr_add_cells(dynarr, 1);
  dynarr_set(dynarr, dynarr_size(dynarr) - 1, n);
}

void dynarr_remove(dynamic_array_t *dynarr, unsigned int index) {
  assert(index < dynarr_size(dynarr));
  for (int i = index; i < dynarr_size(dynarr) - 1; i++)
    dynarr_set(dynarr, i, dynarr_get(dynarr, i + 1));
  dynarr->logical_size -= 1;
  if (dynarr->logical_size < dynarr->capacity / growth_factor) {
    dynarr->capacity /= growth_factor;
    dynarr->data = realloc(dynarr->data, sizeof(int) * dynarr->capacity);
  }
}

void dynarr_free(dynamic_array_t *dynarr) {
  free(dynarr->data);
  free(dynarr);
}
