#include <stdio.h>
#include <string.h>

int main()
{
  // 문자열은 선언과 동시에 초기화를 동시에 해야함

  // 각 글자마다 선언 및 초기화
  char month[0] = 'M';
  char month[1] = 'a';
  char month[2] = 'r';
  char month[3] = 'c';
  char month[4] = 'h';
  char month[5] = '\0';

  month = "April"; // 허용되지 않음

  // strcpy()랴는 함수를 사용하면 예외 가능;
  strcpy(month, "April");
}