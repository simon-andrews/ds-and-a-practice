#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void ll_init_node(linked_list_node_t **node, int value) {
  *node = malloc(sizeof(linked_list_node_t));
  (**node).previous = NULL;
  (**node).next = NULL;
  (**node).data = value;
}

void ll_init(linked_list_t **list) {
  *list = malloc(sizeof(linked_list_t));
  (**list).first = NULL;
  (**list).last = NULL;
  (**list).size = 0;
}

linked_list_node_t *ll_get_node(linked_list_t *list, unsigned int index) {
  assert(index < list->size);
  assert(list->first != NULL);
  linked_list_node_t *current_node = list->first;
  for (int i = 0; i <= index; i++) {
    if (i == index)
      return current_node;
    else
      current_node = current_node->next;
  }
}

void ll_set(linked_list_t *list, unsigned int index, int value) {
  linked_list_node_t *node = ll_get_node(list, index);
  node->data = value;
}

void ll_append(linked_list_t *list, int value) {
  linked_list_node_t *node = NULL;
  ll_init_node(&node, value);
  if (list->last == NULL) {
    list->first = node;
    list->last = node;
  }
  else {
    list->last->next = node;
    node->previous = list->last;
    list->last = node;
  }
  list->size += 1;
}

void ll_print_all_helper(linked_list_node_t *node) {
  printf("%d\t%p\n", node->data, node);
  if (node->next != NULL)
    ll_print_all_helper(node->next);
}

void ll_print_all(linked_list_t *list) {
  printf("# of elements: %d\n", list->size);
  printf("value\taddress\n");
  ll_print_all_helper(list->first);
}

void ll_free_node_and_children(linked_list_node_t *node) {
  if (node->next != NULL)
    ll_free_node_and_children(node->next);
  free(node);
}

void ll_free(linked_list_t *list) {
  ll_free_node_and_children(list->first);
  free(list);
}
