#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list_node_t {
  struct linked_list_node_t *previous;
  struct linked_list_node_t *next;
  int data;
} linked_list_node_t;

typedef struct {
  linked_list_node_t *first;
  linked_list_node_t *last;
  size_t size;
} linked_list_t;

void ll_init(linked_list_t **list);
void ll_free(linked_list_t *list);

linked_list_node_t *ll_get_node(linked_list_t *list, unsigned int index);
void ll_set(linked_list_t *list, unsigned int index, int value);
void ll_append(linked_list_t *list, int value);

void ll_print_all(linked_list_t *list);

#endif
