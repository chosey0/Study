#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // * 행렬 덧셈에 사용할 배열 a와 배열 aa, 두 행렬의 덧셈 값을 저장할 배열;
  int a[3][4], aa[3][4], a_aa_matrix_addition[3][4];

  // * 반복문에 사용될 변수 n, i, j
  int i, j;
  // * 실행할 때 마다 서로 다른 난수를 생성하는 시드 설정 == 실행마다 전에 실행하여 대입된 난수 초기화?
  srand(time(0));
  // * 행렬에 들어갈 난수를 만들기 위한 변수 선언;
  int rand(void);
  int number;

  printf("행렬 a\n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      number = rand() % 4;
      a[i][j] = number;
    }
  }

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }

  printf("\n행렬 aa\n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      number = rand() % 10;
      aa[i][j] = number;
    }
  }

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      printf("%d\t", aa[i][j]);
    }
    printf("\n");
  }

  printf("\n행렬 a + aa\n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      a_aa_matrix_addition[i][j] = (a[i][j] + aa[i][j]);
    }
  }

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      printf("%d\t", a_aa_matrix_addition[i][j]);
    }
    printf("\n");
  }
  return 0;
}