#include "list.h"
#include <stdio.h>

int main(void)
{
  linked_list ls;

  new_linked_list(&ls);

  ll_push_end(&ls, 1);
  ll_push_end(&ls, 12);
  ll_push_start(&ls, 15);

  printf("ls size: %d\n", ls.size);

  int s = ls.size;
  for (int i = 0; i < s; i++)
    printf("ls[%d]: %d\n", i, ll_pop_start(&ls));

  printf("ls size: %d\n", ls.size);

  return 0;
}

