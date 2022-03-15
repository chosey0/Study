#include <stdio.h>

// todo %d %s %c %s 반드시 사용
int main()
{
  printf("안녕하세요. 제 이름은 %s입니다.\n", "최석규");
  printf("나이는 %d살이며, 키는 %f입니다.\n", 24, 180.3);
  printf("전주 캠퍼스에 있는 %s에서 %d년부터 %d년까지 다니다가\n", "제약공학과", 2018, 2021);
  printf("올해 %s로 전과했습니다.\n", "컴퓨터공학과");
  return 0;
}