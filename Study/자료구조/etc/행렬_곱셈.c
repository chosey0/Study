#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // * 실행할 때 마다 서로 다른 난수를 생성하는 시드 설정 == 실행마다 전에 실행하여 대입된 난수 초기화
  srand(time(0));

  // * 행렬에 들어갈 난수를 만들기 위한 변수 선언;
  int rand(void);
  int number;

  // * 행렬 덧셈에 사용할 배열 a와 배열 aa, 두 행렬의 덧셈 값을 저장할 배열;
  int l, m, n;
  l = rand() % 10; // a의 행 수

  m = rand() % 10; // a의 열 수, b의 행 수

  n = rand() % 10; // b의 열 수

  int a[l][m], b[m][n], a_b_multiple_matrix[l][n];

  // * 반복문에 사용될 변수 n, i, j
  int i, j, k;

  // * 배열 a에 랜덤한 값 넣기
  for (i = 0; i < l; i++)
  {
    for (j = 0; j < m; j++)
    {
      number = rand() % 10;
      a[i][j] = number;
    }
  }

  // * 배열 b에 랜덤한 값 넣기
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      number = rand() % 10;
      b[i][j] = number;
    }
  }

  // * 행렬 a 시각화
  printf("행렬 a\n");
  for (i = 0; i < l; i++)
  {
    for (j = 0; j < m; j++)
    {

      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }

  // * 행렬 b 시각화
  printf("행렬 b\n");
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d\t", b[i][j]);
    }
    printf("\n");
  }

  // * 행렬 a와 b의 곱하기 연산
  for (i = 0; i < l; i++)
  {
    for (j = 0; j < n; j++)
    {
      a_b_multiple_matrix[i][j] = 0;
      for (k = 0; k < m; k++)
      {
        a_b_multiple_matrix[i][j] += (a[i][k] * b[k][j]);
      }
    }
  }

  // * 행렬 a와 b의 곰셈 결과 시각화
  printf("행렬 a x b\n");
  for (i = 0; i < l; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d\t", a_b_multiple_matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}