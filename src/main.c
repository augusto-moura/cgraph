#include "list.h"
#include <stdio.h>

int main(void)
{
  linked_list ls;

  new_linked_list(&ls);

  ll_push(&ls, (void*) 1);
  ll_push(&ls, (void*) 12);
  ll_push(&ls, (void*) 15);

  printf("ls size: %d\n", ls.size);

  ll_remove(&ls, 0);

  printf("ls size: %d\n", ls.size);

  printf("ls[0]: %d\n", (int) ll_get(&ls, 0));
  printf("ls[1]: %d\n", (int) ll_get(&ls, 1));
  printf("ls[2]: %d\n", (int) ll_get(&ls, 2));
  return 0;
}

