#include"basic.h"
#include"function.h"

void event(Player* player, int* floor) {
	int X = 10;
	int Y = 5;

	gotoxy(X, Y + 0);
	printf("����������������������������������������������������������������������������������������  ");
	gotoxy(X, Y + 1);
	printf("��              EVENT �� �߰�               ��  ");
	gotoxy(X, Y + 2);
	printf("��                                          ��  ");
	gotoxy(X, Y + 3);
	printf("��         �� �� ���� �ö󰡽ÿ�            ��  ");
	gotoxy(X, Y + 4);
	printf("��                                          ��  ");
	gotoxy(X, Y + 5);
	printf("��                                          ��  ");
	gotoxy(X, Y + 6);
	printf("��                                          ��  ");
	gotoxy(X, Y + 7);
	printf("��                                          ��  ");
	gotoxy(X, Y + 8);
	printf("���������������������������������������������������������������������������������������� \n");
	
	(*floor)++;
	Sleep(300);
	getchar();
	system("cls");

}