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

ll_node * ll_get_node(const linked_list *ls, const int i)
{
  ll_node *cursor = ls->head;
  int j = 0;

  while (cursor != NULL && j++ < i)
    cursor = cursor->next;

  return cursor;
}

void ll_add(linked_list *ls, const int i, void *val)
{
  ll_node *node = new_ll_node(NULL, val);

  if (i == 0)
  {
    node->next = ls->head;

    ls->head = node;
    if (ls->last == NULL)
      ls->last = node;
  }
  else
  {
    ll_node *prev_node = ll_get_node(ls, i - 1);

    if (prev_node->next == NULL)
      ls->last = node;

    node->next = prev_node->next;
    prev_node->next = node;
  }

  ls->size += 1;
}

void ll_push_start(linked_list *ls, void *val)
{
  ll_add(ls, 0, val);
}

void ll_push_end(linked_list *ls, void *val)
{
  ll_add(ls, ls->size, val);
}

void * ll_get(const linked_list *ls, const int i)
{
  ll_node *cursor = ll_get_node(ls, i);

  return cursor != NULL ? cursor->val : NULL;
}

void ll_remove(linked_list *ls, const int i)
{
  if (ls->size < i + 1)
    return;

  ll_node *prev = i == 0 ? NULL : ll_get_node(ls, i - 1);
  ll_node *node = prev != NULL ? prev->next : ls->head;

  if (prev != NULL)
    prev->next = node->next;

  if (node == ls->last)
    ls->last = NULL;

  if (node == ls->head)
    ls->head = node->next;

  ls->size -= 1;
  destroy_ll_node(node);
}

void * ll_pop_start(linked_list *ls)
{
  void *result = ll_get(ls, 0);
  ll_remove(ls, 0);
  return result;
}

void * ll_pop_end(linked_list *ls)
{
  int i = ls->size - 1;
  void *result = ll_get(ls, i);
  ll_remove(ls, i);
  return result;
}

void ll_destroy(linked_list *ls)
{
  
}
