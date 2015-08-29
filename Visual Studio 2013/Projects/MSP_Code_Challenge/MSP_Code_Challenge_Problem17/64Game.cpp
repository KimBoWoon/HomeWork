/*
이하 MadPlay가 코딩한 소스 코드입니다.
http://blog.naver.com/madplay 에 방문하셔서
코드 사용 여부를 반드시 밝혀주시기 바랍니다.

Copyright (C) MadPlay's SW Life.
*/



#include <iostream>
#include <string>
#include <iomanip> // setw를 위한 헤더 파일
#include <vector>
#include <conio.h>
#include <Windows.h> // Clear Screen, exit 등을 위한 헤더 파일
#include <time.h>
using namespace std;
#pragma warning(disable:4996) // 비주얼 스튜디오 secure 에러 무시



const int MAXROW = 4;
const int MAXCOL = 4;



class Game {
private:
	int bestScore; // 최고 점수 기록 변수
	int score; // 현재 점수 기록 변수
	vector<int> scoreList; // 점수 저장 변수
	int number[MAXROW][MAXCOL]; // 4x4 게임판에 숫자 출력
public:
	// 변수 초기화
	void gameInit() {
		bestScore = calcBestScore();
		score = 0;
		for (int row = 0; row < MAXROW; row++) {
			for (int col = 0; col < MAXCOL; col++) {
				number[row][col] = 0;
			}
		}
		addRandomValue(); // 초기 난수 생성
	}



	// 난수 생성
	void addRandomValue() {
		int loopCount = 0;

		for (int row = 0; row < MAXROW; row++) {
			for (int col = 0; col < MAXCOL; col++) {
				if (number[row][col] == 0)
					loopCount = 1;
			}
		}

		while (loopCount) {
			int ranRow = rand() % 4;
			int ranCol = rand() % 4;

			if (number[ranRow][ranCol] == 0) {
				number[ranRow][ranCol] = 2;
				break;
			}
		}
	}



	// 최고 점수를 계산한다.
	int calcBestScore() {
		int max = 0;
		int length = scoreList.size();
		for (int idx = 0; idx < length; idx++) {
			if (max < scoreList[idx]) max = scoreList[idx];
		}
		return max;
	}



	// 점수 출력
	void showPoint() {
		cout << "BEST : " << bestScore << endl;
		cout << "SCORE : " << score << endl;
	}



	// 안내메시지 출력
	void showKeyMessage() {
		cout << "W : 모든 숫자 위로" << endl;
		cout << "A : 모든 숫자 왼쪽으로" << endl;
		cout << "S : 모든 숫자 아래로" << endl;
		cout << "D : 모든 숫자 오른쪽으로" << endl;
		cout << "X : 게임종료" << endl;
	}



	// 게임판 출력
	void showMainGround() {
		int row = 0;
		for (int width = 0; width < 4; width++) {
			for (int height = 0; height < 41; height++) {
				if (height % 10 == 0) cout << "+";
				else cout << "-";
			}


			// 게임판 정리.... 하기...-_-
			cout << endl;
			cout << "| " << setw(10) << " | " << setw(10) << " | " << setw(10)
				<< " | " << setw(10) << " | " << endl;
			cout << "| " << setw(4) << number[row][0] << setw(6) << " | " << setw(4)
				<< number[row][1] << setw(6) << " | " << setw(4) << number[row][2] << setw(6)
				<< " | " << setw(4) << number[row][3] << setw(6) << " | " << endl;
			cout << "| " << setw(10) << " | " << setw(10) << " | " << setw(10) << " | "
				<< setw(10) << " | " << endl;
			row++;
		}
		for (int col = 0; col < 41; col++) {
			if (col % 10 == 0) cout << "+";
			else cout << "-";
		}
		cout << endl;
	}



	void playGame() {
		gameInit();
		while (true) {
			system("cls");
			showMainGround();
			showPoint();
			showKeyMessage();


			char keyInput = 'x';
			keyInput = getch(); // 키 입력
			allBlocksMove(keyInput); // 키 입력에 따른 블록 이동
			switch (keyInput) {
			case 'w': case 'a': case 's': case 'd':
				calcBlocksAddCondition(keyInput); // 더할 수 있는 블록이 있는 지 검사
				allBlocksMove(keyInput); // 검사 후 결과 반영, 블록 이동
				if (isWin()) showEndMessage(1); // 승리 조건 검사
				if (isEnd()) showEndMessage(0); // 패배 조건 검사
				break;


			case 'x': return;
			default: break;
			}
		}
	}



	// 더할 수 있는 지 계산하기!
	void calcBlocksAddCondition(char input) {
		switch (input) {
		case 'w': case 'W':
			for (int row = 0; row < MAXROW - 1; row++) {
				for (int col = 0; col < MAXCOL; col++) {
					if (number[row][col] == number[row + 1][col]) {
						number[row][col] = number[row][col] * 2;
						score = score + number[row][col]; // 점수증가
						number[row + 1][col] = 0;
					}
				}
			}
			break;



		case 'a': case 'A':
			for (int col = 0; col < MAXCOL - 1; col++) {
				for (int row = 0; row < MAXROW; row++) {
					if (number[row][col] == number[row][col + 1]){
						number[row][col] = number[row][col] * 2;
						score = score + number[row][col]; // 점수증가
						number[row][col + 1] = 0;
					}
				}
			}
			break;

		case 's': case 'S':
			for (int row = MAXROW - 1; row > 0; row--) {
				for (int col = MAXCOL - 1; col >= 0; col--) {
					if (number[row][col] == number[row - 1][col]) {
						number[row][col] = number[row][col] * 2;
						score = score + number[row][col]; // 점수증가
						number[row - 1][col] = 0;
					}
				}
			}
			break;



		case 'd': case 'D':
			for (int col = MAXCOL - 1; col > 0; col--) {
				for (int row = MAXROW - 1; row >= 0; row--) {
					if (number[row][col] == number[row][col - 1]) {
						number[row][col] = number[row][col] * 2;
						score = score + number[row][col]; // 점수증가
						number[row][col - 1] = 0;
					}
				}
			}
			break;
		}
	}



	// 블록 이동 시키기
	// 반복 이동시키는 부분은 참고하였습니다.
	void allBlocksMove(char input) {
		switch (input)
		{
		case 'w': case 'W':
			for (int loop = 0; loop < 10; loop++)
				for (int row = 0; row < MAXROW - 1; row++) {
					for (int col = 0; col < 4; col++) {
						if (number[row][col] == 0) {
							number[row][col] = number[row + 1][col];
							number[row + 1][col] = 0;
						}
					}
				}
			break;



		case 'a': case 'A':
			for (int loop = 0; loop < 10; loop++)
				for (int col = 0; col < MAXCOL - 1; col++) {
					for (int row = 0; row < MAXROW; row++) {
						if (number[row][col] == 0) {
							number[row][col] = number[row][col + 1];
							number[row][col + 1] = 0;
						}
					}
				}
			break;



		case 's': case 'S':
			for (int loop = 0; loop < 10; loop++)
				for (int row = MAXROW - 1; row > 0; row--) {
					for (int col = MAXCOL - 1; col >= 0; col--) {
						if (number[row][col] == 0) {
							number[row][col] = number[row - 1][col];
							number[row - 1][col] = 0;
						}
					}
				}
			break;



		case 'd': case 'D':
			for (int loop = 0; loop < 10; loop++)
				for (int col = MAXCOL - 1; col > 0; col--) {
					for (int row = MAXROW - 1; row >= 0; row--) {
						if (number[row][col] == 0) {
							number[row][col] = number[row][col - 1];
							number[row][col - 1] = 0;
						}
					}
				}
			break;
		}
		addRandomValue();
	}



	// 승리 조건 확인
	bool isWin() {
		for (int row = 0; row < MAXROW; row++) {
			for (int col = 0; col < MAXCOL; col++) {
				if (number[row][col] == 2048) return true;
			}
		}
		return false;
	}



	// 패배 조건 확인
	bool isEnd() {
		for (int row = 0; row < MAXROW - 1; row++) {
			for (int col = 0; col <= MAXCOL - 1; col++) {
				if (number[row][col] == number[row][col + 1]) return false;
				// 옆에 같은 숫자가 있으면 패배하지 않음
			}
		}



		for (int col = 0; col < MAXCOL - 1; col++) {
			for (int row = 0; row <= MAXROW - 1; row++) {
				if (number[row][col] == number[row + 1][col]) return false;
				// 위아래 같은 숫자가 있으면 패배하지 않음
			}
		}



		for (int row = 0; row < MAXROW; row++) {
			for (int col = 0; col < MAXCOL; col++) {
				if (number[row][col] == 0) return false;
				// 하나라도 비어 있으면 패배하지 않음
			}
		}
		return true;
	}



	// 경기 종료 후 안내 메시지 출력 및 처리
	void showEndMessage(int type) {
		system("cls");
		char choice;


		if (type) {
			scoreList.push_back(score);
			cout << "승리하였습니다. 게임을 한 번 더 하시겠습니까? (y/n) : ";
		}
		else cout << "패배하였습니다. 게임을 한 번 더 하시겠습니까? (y/n) : ";


		fflush(stdin);
		choice = getch();
		if (choice == 'y') playGame();
		else if (choice == 'n') exit(0);
		else showEndMessage(type);
	}
};

int main(void)
{
	srand((unsigned)time(NULL));
	Game game;
	game.playGame();
}