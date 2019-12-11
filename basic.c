#include "struct.h"
#include "windows.h"

#define SIZE 100

void setcursortype()
{
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void gotoxy(int x, int y) {
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Potion * addPotion(int eff) {
	Potion * p = (Potion *)malloc(sizeof(Potion));
	memset(p, 0x0, sizeof(Potion));
	p->effect = eff;
	return p;
}
int cnt_potion(Potion * potion) {
	int cnt = 1;
	Potion * current = potion;
	while (current->link != NULL) {
		cnt++;
		current = current->link;
	}
	return cnt;
}

void basic_view1(char * title) {
	int i;
	gotoxy(0, 0);
	printf("�ߡ�1���ޡ�\n");
	printf("����ȭ�� : %s\n\n",title);
	for (i = 0; i < 50;i++)printf("��");
}

void basic_view2(Player* player) {
	int i;
	gotoxy(0, 26);
	for (i = 0; i < 50; i++)printf("��");
	printf("\n<�÷��̾��� ����>\n");
	printf("hp : %d\n", player->hp);
	if (player->potionList->effect == 0)printf("������ ����");
	else {
		printf("������ ���� ���� : %d    ", cnt_potion(player->potionList));
		printf("���� ������ ȿ�� : %d", player->potionList->effect);
	}
}
void clean_view()
{
	int i, j;
	for (i = 0; i < 50; i++)
	{
		gotoxy(0, 100);
		for (j = 0; j < 100; j++)
			printf(" ");
	}
}

