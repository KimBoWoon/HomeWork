#pragma warning(disable:4996)

#include "Word.h"

#define MAX_SIZE 50

vector<Word *> dictionary(26);
vector<string> temp;

bool sizeComp(const string x, const string y) {
	return (x.size() < y.size()) ? true : false;
}

void inputBoard(char board[][MAX_SIZE], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cin >> board[i][j];
	}
}

void acrossWord(int across) {
	for (int i = 0; i < across; i++) {
		int x, y;

		cin >> x >> y;


	}
}

int main() {
	int dictionarySize, testCase, size = 0;
	freopen("input.txt", "r", stdin);

	cin >> dictionarySize;

	for (int i = 0; i < dictionarySize; i++) {
		string str;
		cin >> str;
		temp.push_back(str);
	}

	sort(temp.begin(), temp.end(), sizeComp);

	for (int i = 0; i < ALPHABET; i++)
		dictionary[i] = new Word;

	for (int i = 0; i < dictionarySize; i++) {
		int ascii = 0;
		ascii = temp[i][0] - 65;
		dictionary[ascii]->addWord(temp[i]);
	}

	cin >> testCase;

	while (testCase--) {
		int row, col, across, down;
		char board[MAX_SIZE][MAX_SIZE];

		memset(board, 0, sizeof(char) * MAX_SIZE *MAX_SIZE);

		cin >> row >> col;

		inputBoard(board, row, col);

		cin >> across >> down;

		acrossWord(across);
	}
}