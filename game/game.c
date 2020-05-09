#define _CRT_SECURE_NO_WARNINGS
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32

#include <stdio.h>
#include <windows.h>


void SetConsoleScreen(int r, int c) {
	char str[50];
	sprintf(str, "mode con cols=%d lines=%d", r * 2, c);
	system(str);
}

void CursorView(char show)//커서숨기기
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int startKeyControl() {
	int key = getch();
	if (key == SPACE) {
		return key;
	}
	if (key == 224) {
		key = getch();
		switch (key) {
		case UP:
			return key;
		case DOWN:
			return key;
		default:
			return 0;
		}
	}
	return 0;
}

int StartMenu() {
	int x = 40;
	int y = 17;
	int n = 0;
	printf("\n\n\n\n\n\n\n\n");
	gotoxy(x, y);
	printf("> 게임시작");
	gotoxy(x + 2, y + 2);
	printf("종료");

	while (1) {
		int key = startKeyControl();
		
		if (key == SPACE) {
			return n;
		}
		if (key != 0) {
			if (key == UP) {
				gotoxy(x, y + 2);
				printf(" ");
				gotoxy(x, y);
				printf(">");
				n = 0;
			}
			else {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, y + 2);
				printf(">");
				n = 1;
			}
		}
	}
}

void gameboard() {
	int x = 20;
	int y = 12;
	int gameboard[22][14] = { 0, };
	gotoxy(x, y);

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 14; j++) {
			if (j == 0 || j == 13 || i == 21) {
				gameboard[i][j] = 1;
			}
			if (gameboard[i][j] == 1) {
				printf("■");
			}
			else {
				printf("  ");
			}
		}
		gotoxy(x, ++y);
	}

}

void game() {
	int blocks[7][4][4][4] = {
	{{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},
	 {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}},
	{{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},
	 {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
	{{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0},
	 {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}},
	{{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0},
	 {0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}},
	{{0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0},
	 {0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0}},
	{{0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0},
	 {0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},{0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0}},
	{{0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0},
	 {0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0},{0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}} };
	
	
};



int main() {
	int r = 50;
	int c = 40;
	SetConsoleScreen(r, c); //화면 크기 설정
	CursorView(0);          //커서 숨기기

	int ans = StartMenu();
	if (ans == 0) {
		system("cls");
		gameboard();
		while (1) {
			game();
		}
	}
	else {
		exit(0);
	}
	return 0;
}


