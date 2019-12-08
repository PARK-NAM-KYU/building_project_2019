#include "basic.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define BLUE 10
#define GREEN 11
#define RED 13

void game1_start();


void game1(Player* player, int* floor) {
	//여기에서 game1_view 호출
	
	
	game1_start();

}
void game1_view() {

}
void game1_start() {

	int t;
	gotoxy(42, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("[ 벽 돌 깨 기 ]");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	gotoxy(42, 15);
	printf("제한시간 : 1분");
	gotoxy(37, 17);
	printf("벽돌을 모두 파괴하세요 !");
	Sleep(5000);


	//5초 뒤에 시작
	for (t = 5;t > 0;t--) {
		gotoxy(49, 15);
		printf("%d", t);
		Sleep(1000);
	}

}

//완성되면 금요일까지올릴께용..............아직 미완성이라