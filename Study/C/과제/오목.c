#include <ncurses.h>
#include <locale.h>
#include <string.h>

// * 판 크기 및 위치 구조체
struct Point_2D
{
  int w; // 너비
  int h; // 높이
  int x; // stdscr위에서의 x좌표
  int y; // stdscr위에서의 y좌표
} sub;

// * 좌표 변수 구조체
struct Active_P
{
  int Ac_x; // x
  int Ac_y; // y
} Ac_P;

struct Active_P Ac_P = {
    2,
    1};

int key_press;

int turn = 0;

void win_start(void);

void moving(void);
void Active(void);

int stone(void);
void restart(void);
void ends(void);
void key_function(void);

WINDOW *place_win;

int main(void)
{

  // todo 현재 커서의 좌표값
  win_start();

  // todo getch() value에 따른 기능 실행 함수 집합
  key_function();

  return 0;
}

/*
  * * * * * * * * * * * * * * *
  *                           *
  *                           *
      todo 여기서부터 기능 함수들
  *                           *
  *                           *
  * * * * * * * * * * * * * * *
 */

// todo window 생성 함수
void win_start(void)
{

  setlocale(2, "ko_KR.utf-8");

  initscr();
  cbreak(); // * 라인 버퍼 미사용
  noecho(); // * 사용자 입력 x

  refresh();

  // * 터미널 크기에 비례하여 정사각형의 판 생성
  /*   sub_h = getmaxy(stdscr);
    sub_w = getmaxy(stdscr) * 2;
    sub_y = (getmaxy(stdscr) / 2) - (sub_h / 2);
    sub_x = (getmaxx(stdscr) / 2 ) - (sub_w / 2); */

  struct Point_2D sub = {
      getmaxy(stdscr) * 2,                 // * w
      getmaxy(stdscr),                     // * h
      (getmaxx(stdscr) / 2) - (sub.w / 2), // * x
      (getmaxy(stdscr) / 2) - (sub.h / 2)  // * y
  };

  place_win = newwin(sub.h, sub.w, sub.y, sub.x);

  // * 특수 키 사용
  keypad(stdscr, TRUE);
  keypad(place_win, TRUE);

  // * 테두리 설정
  box(place_win, 0, 0);

  // * 시작 좌표 설정
  Active();
}

// todo getch() 값에 따른 기능 실행 함수
void key_function(void)

{
  while (1)
  {
    key_press = getch();

    // todo 커서 이동 함수 / 분리
    moving();

    // todo 찐막 돌 놓기 / 분리
    stone();

    // todo 판 새로고침 함수 / 분리
    restart();

    // todo 종료
    ends();
  }
}

// todo  커서 이동 함수
void moving(void)
{
  /*
  todo 각 방향 코드 구조 설명
  *  if ( 입력 키 값 검증 )
  *   {
  *     1. 커서 이동 실행 코드
  *
  *         if ( 커서가 테두리를 넘어가는지 검증 )
  *         {
  *           2. 커서 좌표 값 감소 및 증가 코드
  *         }
  *   }
  *
  * 내부 if문 코드가 먼저 실행되었을 때 안되던 이유는
  * 이동 전에 검증하는 것은 의미가 없음
  * 이동 후에 검증해서 넘어갔다 싶으면 다시 돌아오게 하는거
  */

  // todo 상
  if (key_press == KEY_UP)
  {

    Ac_P.Ac_y--;
    Active();

    if (Ac_P.Ac_y <= 0)
    {
      Ac_P.Ac_y = 1;
      Active();
    }
  }

  // todo 하
  else if (key_press == KEY_DOWN)
  {

    Ac_P.Ac_y++;
    Active();

    if (Ac_P.Ac_y >= (getmaxy(place_win) - 1))
    {
      Ac_P.Ac_y--;
      Active();
    }
  }

  //     todo 좌
  else if (key_press == KEY_LEFT)
  {

    Ac_P.Ac_x = Ac_P.Ac_x - 2;
    Active();

    if (Ac_P.Ac_x <= 0)
    {
      Ac_P.Ac_x = 2;
      Active();
    }
  }

  // todo 우
  else if (key_press == KEY_RIGHT)
  {
    Ac_P.Ac_x = Ac_P.Ac_x + 2;
    Active();

    if (Ac_P.Ac_x >= getmaxx(place_win))
    {
      Ac_P.Ac_x = (getmaxx(place_win) - 2);
      Active();
    }
  }
}

// todo 돌 놓기 함수
int stone(void)
{
  /*
    todo 코드 구조 설명
    * if ( 스페이스바를 눌렀는지 검증 )
    *    {
    *
    *      if ( turn == 0 ) // ? 턴 검증
    *         {
    *             if ( 커서의 위치가 테두리에 닿았는지 검증 )
    *                 {
    *                      닿았을 때 띄어쓰기 미 포함 돌 입력
    *                 }
    *             else
    *                 {
    *                      닿지않았을 때 띄어쓰기 포함 돌 입력
    *                 }
    *
    *             돌의 좌표를 2차원 배열에 집어넣기
    *
    *             돌 입력 후 커서 이동 ;
    *             판 새로고침;
    *             턴 넘기기;
    *         }
    *
    *       else if ( turn == 1)  // ? 턴 검증
    *         }
    *             if ( 커서의 위치가 테두리에 닿았는지 검증 )
    *                 {
    *                      닿았을 때 띄어쓰기 미 포함 돌 입력
    *                 }
    *             else
    *                 {
    *                      닿지않았을 때 띄어쓰기 포함 돌 입력
    *                 }
    *
    * *           돌의 좌표를 2차원 배열에 집어넣기
    *
    *             돌 입력 후 커서 이동 ;
    *             판 새로고침;
    *             턴 넘기기;
    *         }
  */

  // * 돌의 좌표 기록 배열 구조체
  int B_turn;
  int W_turn;
  struct Stone_arr
  {
    int black[300][2];
    int white[300][2];
    int B_turn; // black index
    int W_turn; // white index

    int *Bx_p; // 검은 돌 x 좌표 포인터
    int *By_p; // 검은 돌 y 좌표 포인터
    int *Wx_p; // 흰 돌 x 좌표 포인터
    int *Wy_p; // 흰 돌 y 좌표 포인터
  };

  struct Stone_arr Stone_P = {
      {Ac_P.Ac_x, Ac_P.Ac_y},
      {Ac_P.Ac_x, Ac_P.Ac_y},
      0,
      0,

      &Stone_P.black[Stone_P.B_turn][0],
      &Stone_P.black[Stone_P.B_turn][1],

      &Stone_P.white[Stone_P.W_turn][0],
      &Stone_P.white[Stone_P.W_turn][1],
  };

  if (key_press == ' ')
  {

    if (turn == 0)
    {
      if (Ac_P.Ac_x >= (getmaxx(place_win) - 2))
      {
        wprintw(place_win, "%s", "●");
      }

      else
      {
        wprintw(place_win, "%s", "● ");
      }

      // todo 인덱스로 배열 요소에 접근
      Stone_P.black[Stone_P.B_turn][0] = Ac_P.Ac_x;
      Stone_P.black[Stone_P.B_turn][1] = Ac_P.Ac_y;
      printw("x : %d y : %d\n", Ac_P.Ac_x / 2, Ac_P.Ac_y);

      // todo 포인터로 배열 요소에 접근
      printw("%d, %d, %lu, %lu\n", *Stone_P.Bx_p / 2, *Stone_P.By_p, Stone_P.Bx_p, Stone_P.Bx_p);
      Stone_P.B_turn++;

      Ac_P.Ac_x = Ac_P.Ac_x + 2;
      wrefresh(place_win);
      turn++;

      if (Ac_P.Ac_x >= getmaxx(place_win))
      {
        Ac_P.Ac_x = Ac_P.Ac_x - 2;
        Active();
      }
    }

    else if (turn == 1)
    {
      if (Ac_P.Ac_x >= (getmaxx(place_win) - 2))
      {
        wprintw(place_win, "%s", "○");
      }
      else
      {
        wprintw(place_win, "%s", "○ ");
      }

      Stone_P.white[Stone_P.W_turn][0] = Ac_P.Ac_x;
      Stone_P.white[Stone_P.W_turn][1] = Ac_P.Ac_y;
      printw("x : %d y : %d\n", Ac_P.Ac_x / 2, Ac_P.Ac_y);

      // 1. x 2. y 3. 첫번째 턴 메모리 주소 4. 두번째 턴 메모리 주소
      printw("%d, %d, %lu, %lu, %lu, %lu\n", *Stone_P.Wx_p / 2, *Stone_P.Wy_p, &Stone_P.Wx_p, &Stone_P.Wy_p, &Stone_P.white[100][0], &Stone_P.white[1][1]); // 포인터로 배열 구조체 요소에 접근
      Stone_P.W_turn++;

      Ac_P.Ac_x = Ac_P.Ac_x + 2;
      wrefresh(place_win);
      turn--;

      if (Ac_P.Ac_x >= getmaxx(place_win))
      {
        Ac_P.Ac_x = Ac_P.Ac_x - 2;
        Active();
      }
    }
  }
  return 0;
}

// todo restart 함수
void restart(void)
{
  if (key_press == 'r')
  {
    endwin();    // * 윈도우 종료
    win_start(); // * 재시작

    // * 커서 좌표 초기화
    Ac_P.Ac_x = 0;
    Ac_P.Ac_y = 0;
  }
}

// todo 종료
void ends(void)
{
  if (key_press == 'x')
  {
    endwin();
  }
}

// todo 좌표 이동 함수
void Active(void)
{
  wmove(place_win, Ac_P.Ac_y, Ac_P.Ac_x);
  wrefresh(place_win);
}
