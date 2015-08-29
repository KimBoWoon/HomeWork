/****************************
*							*
*	학번 : 20113259			*
*	이름 : 김보운			*
*							*
****************************/
#include "Tetris_Game.h"
#include "Tetris_Key.h"
#include "Tetris_Block.h"
#include "Tetris_Interface.h"

void main(int argc, char* argv[])
{
	std::ifstream inStream;//파일사용을 위해 파일 함수 선언
	initscr();//pdcurses mode 사용
	bool isGameOver = false;//gameover를 나타낼 변수
	char cur_key = NULL, name[10] = { NULL };//키값을 받아올 변수 이름을 입력받을 배열
	int seed;//시드값
	//클래스를 사용하기위해 선언
	Interface Interface;
	GamePlay gameplay;
	KeySet keyset;

	keypad(stdscr, TRUE);//특수키를 사용할 수 있게 설정한다
	start_color();//색사용
	resize_term(25, 50);//가로 50, 세로 25인 터미널 크기 설정

	if (argc > 1)//파일이 입력되었을때 파일을 개방한다
	{
		inStream.open(argv[1]);
		inStream >> name >> seed;//파일안에 있는 유저 이름과 시드값을 초기화
		srand(seed);//시드값으로 난수를 만든다
	}
	else
	{
		mvprintw(0, 0, "테트리스 게임을 시작합니다.\n");
		mvprintw(2, 0, "당신의 이름을 입력하세요.\n");
		mvprintw(4, 0, "이름 : ");
		scanw("%s", name);
		srand(time(NULL));//시드값으로 현재시간을 이용한다
		noecho();//화면에 입력한값을 표시하지않도록 설정
		clear();//화면을 다지운다
	}

	gameplay.Setrandomnumber(rand() % 7);//0~6사이의 난수를 만든다
	curs_set(0);//화면에 커서를 없앤다
	border('|', '|', '-', '-', '+', '+', '+', '+');//스크린 경계선 설정
	refresh();//화면 출력
	init_pair(1, COLOR_GREEN, COLOR_BLACK);//게임화면 색을 나타낼 팔레트
	init_pair(2, COLOR_BLUE, COLOR_BLACK);//블럭의 색을 나타낼 팔레트
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);//인터페이스 글자색을 나타낼 팔레트
	//블럭색을 나타내기위한 팔레트
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
	init_pair(9, COLOR_GREEN, COLOR_BLACK);

	Interface.PlayInterface(Interface.Getwin1());//게임 화면 표시 함수 호출
	Interface.ScoreInterface(Interface.Getwin2());//점수 표시 화면 함수 호출
	Interface.UsernameInterface(Interface.Getwin3(), name);//player이름 표시 화면 함수 호출
	wrefresh(Interface.Getwin1());//게임 표시 화면을 출력
	wrefresh(Interface.Getwin2());//점수 표시 화면을 출력
	wrefresh(Interface.Getwin3());//player 표시 화면을 출력

	while (!isGameOver)
	{
		gameplay.display(Interface.Getwin1(), gameplay.GetX(), gameplay.GetY());//현재화면을 표현
		if (argc > 1)//파일이 입력되었으면 파일에서 키값을 읽어온다
			inStream >> cur_key;
		else//파일이 입력되지 않으면 사용자가 키값을 입력한다
			cur_key = keyset.input_key();
		isGameOver = gameplay.gameplay(Interface.Getwin1(), Interface.Getwin2(), cur_key); // 입력 받은 키 처리를 담당한다.
		wrefresh(Interface.Getwin1());//게임 표시 화면을 출력
		wrefresh(Interface.Getwin2());//점수 표시 화면을 출력
	}
	getch();//사용자가 키를 입력할때까지 기다림
	inStream.close();//파일의 종결
	endwin();//pdcurses mode 종료
}