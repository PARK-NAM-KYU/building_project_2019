#include "basic.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define BLUE 10
#define GREEN 11
#define RED 13

void game1_start();


void game1(Player* player, int* floor) {
	//���⿡�� game1_view ȣ��
	
	
	game1_start();

}
void game1_view() {

}
void game1_start() {

	int t;
	gotoxy(42, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("[ �� �� �� �� ]");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	gotoxy(42, 15);
	printf("���ѽð� : 1��");
	gotoxy(37, 17);
	printf("������ ��� �ı��ϼ��� !");
	Sleep(5000);


	//5�� �ڿ� ����
	for (t = 5;t > 0;t--) {
		gotoxy(49, 15);
		printf("%d", t);
		Sleep(1000);
	}

}

//�ϼ��Ǹ� �ݿ��ϱ����ø�����..............���� �̿ϼ��̶�