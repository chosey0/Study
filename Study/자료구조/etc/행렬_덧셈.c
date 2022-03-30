#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // * 행렬 덧셈에 사용할 배열 a와 배열 aa, 두 행렬의 덧셈 값을 저장할 배열;
  int a[3][4], aa[3][4], a_aa_matrix_addition[3][4];

  // * 반복문에 사용될 변수 n, i, j
  int n, i, j;

  // * 실행할 때 마다 서로 다른 난수를 생성하는 시드 설정 == 실행마다 전에 실행하여 대입된 난수 초기화?
  srand(time(0));

  // * 행렬에 들어갈 난수를 만들기 위한 변수 선언;
  int rand(void);
  int number;

  
  // todo 배열 a와 aa를 난수로 채우고 a와 aa를 더한 배열 만들기
  for (n = 0; n < 3; n++)
  {
    for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 4; j++)
      {
        // * 1번째 실행시 동작
        if (n == 0)
        {
          number = rand() % 10;
          a[i][j] = number;
        }

        // * 배열 a에 값을 모두 넣으면 실행됨 == 2번째 실행시 동작
        else if (n == 1)
        {
          number = rand() % 10;
          aa[i][j] = number;
        }

        // * a 와 aa에 값을 모두 넣으면 실행됨 == 3번째 실행 시 동작
        else
        {
          a_aa_matrix_addition[i][j] = (a[i][j] + aa[i][j]);
        }
      }
    }
  }

  // * 배열 a와 배열 aa, a + aa 행렬 확인

  for (n = 0; n < 3; n++)
  {
    if (n == 0)
    {
      printf("행렬 a\n");
    }
    else if (n == 1)
    {
      printf("\n행렬 aa\n");
    }
    else
    {
      printf("\n행렬 a + 행렬 aa\n");
    }
    for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 4; j++)
      {
        if (n == 0)
        {
          printf("%d\t", a[i][j]);
        }
        else if (n == 1)
        {
          printf("%d\t", aa[i][j]);
        }
        else
        {
          printf("%d\t", a_aa_matrix_addition[i][j]);
        }
      }
      printf("\n");
    }
  }

  return 0;
}