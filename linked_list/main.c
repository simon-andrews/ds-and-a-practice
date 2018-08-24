#include <stddef.h>

#include "linked_list.h"

int main() {
  linked_list_t *list = NULL;
  ll_init(&list);
  ll_append(list, 0);
  ll_append(list, 1);
  ll_print_all(list);
  ll_free(list);
}
