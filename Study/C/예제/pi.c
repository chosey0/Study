#include <stdio.h>
#include "pi.h"

int main()
{
  printf("반지름이 %.1f인 원의 면적은 %.2f입니다.\n", radius, radius * radius * PI);

  float Radius = 5.0;
  float area;
  float Pi = 3.14;

  area = Pi * Radius * Radius;

  printf("반지름이 %.1f인 원의 면적은 %.2f입니다.\n", Radius, area);
  return 0;
}
