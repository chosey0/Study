#include <stdio.h>
#include <stdlib.h>

struct NODE
{
  int data;
  struct NODE *link;
};

typedef struct NODE NODE;

int main(void)
{
  NODE x, y, z;
  NODE *p, *q, *r, *h;

  x.data = 66;
  x.link = &y;

  y.data = 77;
  y.link = &z;

  z.data = 88;
  z.link = (NODE *)NULL;

  printf("%d %d %d\n", x.data, y.data, z.data);
  printf("%d %d %d\n", x.data, x.link->data, y.link->data);
  printf("%d %d %d\n", x.data, x.link->data, x.link->link->data);
  while (p != ((NODE *)NULL))
  {
    printf("%d ", p->data);
    p = p->link;
  }

  q = (NODE *)malloc(sizeof(NODE));
  q->data = 99;
  q->link = &z;
  y.link = q;

  p = &x;
  while (p)
  {
    printf("%d ", p->data);
    p = p->link;
  }

  p = (NODE *)NULL;
  for (int i = 0; i < 10; i++)
  {
    q = (NODE *)malloc(sizeof(NODE));
    q->data = i;
    q->link = p; // 첫 데이터의 링크는 NULL
    p = q;       // p의 링크를 q로
  }

  printf("\n");
  h = p;
  while (h != (NODE *)NULL)
  {
    printf("%d\t", h->data);
    h = h->link;
  }

  // if (x != 0) == if (x)
  // if ( x == 0) == if (!x)

  // todo 삭제
  // r = p->link->link; // 물리적인 공간은 살아있음
  // p->link->link = p->link->link->link;
  // free(r);
  // h = p;
  // while (h)
  // {
  //   printf("%d\t", h->data);
  //   h = h->link;
  // }

  // todo 삽입

  r = (NODE *)malloc(sizeof(NODE));
  r->data = 77;
  r->link = p->link;
  p->link = r;

  h = p;
  while (h)
  {
    printf("%d\t", h->data);
    h = h->link;
  }
  return 0;
}