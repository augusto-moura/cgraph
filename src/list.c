#include <stdlib.h>
#define ALLOC(a) malloc(sizeof(a))
#include "list.h"

ll_node * new_ll_node(ll_node *node, void *val)
{
  if (node == NULL)
    node = ALLOC(ll_node);

  node->val = val;
  node->next = NULL;

  return node;
}

void destroy_ll_node(ll_node *node)
{
  free(node);
}


linked_list * new_linked_list(linked_list *ls)
{
  if (ls == NULL)
    ls = ALLOC(linked_list);

  ls->head = NULL;
  ls->last = NULL;
  ls->size = 0;

  return ls;
}

void ll_push(linked_list *ls, void *val)
{
  ll_node *node = new_ll_node(NULL, val);

  if (ls->head == NULL)
    ls->head = node;

  if (ls->last != NULL)
    ls->last->next = node;

  ls->last = node;
  ls->size += 1;
}

void * ll_get(linked_list *ls, const int i)
{
  ll_node *cursor = ls->head;
  int j = 0;

  while (cursor != NULL && j++ < i)
    cursor = cursor->next;

  return cursor->val;
}

void ll_remove(linked_list *ls, const int i)
{
  ll_node *previous = NULL;
  ll_node *current = ls->head;
  int j = 0;

  while (current != NULL && j++ < i)
  {
    previous = current;
    current = current->next;
  }

  if (current != NULL)
  {
    if (ls->last == current)
      ls->last = previous;

    if (ls->head == current)
      ls->head = NULL;

    if (previous != NULL)
      previous->next = current->next;

    destroy_ll_node(current);
    ls->size -= 1;
  }
}
