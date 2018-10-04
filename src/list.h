#ifndef _LIST_H
#define _LIST_H

typedef struct ll_node
{
  void *val;
  struct ll_node *next;
} ll_node;

typedef struct linked_list
{
  ll_node *head;
  ll_node *last;
  int size;
} linked_list;

linked_list * new_linked_list(linked_list *ls);

void destroy_linked_list(linked_list *ls);

void ll_add(linked_list *ls, const int idx, void *val);

void ll_push(linked_list *ls, void *val);

void * ll_get(linked_list *ls, const int i);

void ll_remove(linked_list *ls, const int i);

#endif

