#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  // * 배열 a,  배열 a의 전치 행렬을 저장할 배열
  int a[3][4], a_transposition_matrix[4][3];

  // * 반복문에 사용될 변수 i,j
  int i, j;

  // * 실행할 때 마다 서로 다른 난수를 생성하는 시드 설정 == 실행마다 전에 실행하여 대입된 난수 초기화?
  srand(time(0));

  // * a 배열에 들어갈 난수를 만들기 위한 변수 선언;
  int rand(void);
  int number;

  // * 배열 a를 난수로 채우기
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      // * 빈 배열에 순서대로 난수 값을 대입
      number = rand() % 10;
      a[i][j] = number;
    }
  }

  // * 배열 a 확인
  printf("행렬 a\n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }

  // * 배열 a의 전치 행렬 만들기
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 3; j++)
    {
      // * a의 i번째 열 j번째 행의 값을 전치행렬 j번째 행,i번째 열에 값을 대입
      a_transposition_matrix[i][j] = a[j][i];
    }
  }

  // * 배열 a의 전치 행렬 확인
  printf("\na의 전치 행렬\n");
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("%d\t", a_transposition_matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}