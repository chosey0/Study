#include <stdio.h>

struct new
{
  int data;
  struct new *link;
};
typedef struct new new;

int main()
{
  new L;

  return 0;
}