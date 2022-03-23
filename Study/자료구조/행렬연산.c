#include <stdio.h>

int main(void)
{
  // * 행렬 a,   행렬 b,  a의 전치 행렬을 저장할 배열
  int a[3][4], b[4][2];

  // * 반복문에 사용될 변수 i,j
  int i, j;

  // * 행렬에 들어갈 난수 생성
  int rand(void);
  int number;

  // * 행렬 a를 난수로 채우기
  printf("행렬 a\n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      number = rand() % 50;
      a[i][j] = number;
    }
  }

  // * 행렬 a에 들어간 난수 확인
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }

  // * 행렬 a의 전치 행렬 만들기
  int a_transposition_matrix[4][3];
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 3; j++)
    {
      // * a의 i번째 열 j번째 행의 값을 전치행렬 j번째 행,i번째 열에 값을 대입
      a_transposition_matrix[i][j] = a[j][i];
    }
  }

  printf("a의 전치행렬\n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("%d\t", a_transposition_matrix[i][j]);
    }
    printf("\n");
  }
  // // * a행렬과 aa행렬의 덧셈을 저장할 행렬
  // int a_aa_matrix_addition[3][4];

  // for (i = 0; i < 3; i++)
  // {
  // }
  // * a행렬과 b행렬의 곱을 저장할 행렬
  int a_b_matrix_multiplication[3][2];

  return 0;
}