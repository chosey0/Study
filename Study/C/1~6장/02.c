#include <stdio.h>

int main()
{
  // printf("나는 현재 %c프로그래밍 언어를 학습하고 있다.\n", "C");
  // printf("나는 지금 막 %d장을 끝냈다.\n", 2);
  // printf("나는 현재 %.1f 퍼센트 준비되어 있다.\n", 99.9);
  // printf("다음 챕터 학습을 위하여!\n");

  // todo 형식 지정자
  // * %d 정수값
  // * %f 실수로 출력
  // * %c 문자로 출력
  // * %s 문자열로 출력
  printf("빛의 속도는 %fkm/s입니다.\n", 300000);
  printf("중력 가속도는 %fm/s 제곱입니다.\n", 9.8);
  printf("나는 %d살이고 키는 %f입니다.\n", 20, 175.5);
  printf("나의 이름은 %s입니다.\n", "김철수");
  printf("나는 현재 %d장까지 학습을 끝냈습니다.\n", 4);

  // todo 사용자 값 받기 scanf()
  int userinput;
  scanf("%.6f", &userinput);
  printf("빛의 속도는 %fkm/s입니다.\n", &userinput);
  printf("중력 가속도는 %fm/s 제고버입니다.\n", 9.8);
  printf("나는 %d고 키는 %f입니다.\n", 20, 175.5);
  printf("나의 이름은 %s입니다.\n", "김철수");
  printf("나는 현재 %d장까지 학습을 끝냈습니다.\n", 4);
  return 0;
}