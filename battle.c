
#include "function.h"
#include "struct.h"
#include "basic.h"

void boss_state(Player* boss)
{
	gotoxy(80, 6);
	printf("�� BOSS ��");
	gotoxy(80, 8);
	printf("HP : %d\n", boss->hp);
}

void boss_attack(Player* me, Player* boss)
{
	int i;
	gotoxy(70, 10);
	printf("BOSS�� �⸻��� ����!!");

	for (i = 0; i < 10; i++)
	{
		gotoxy(75 - (3 * i), 12);
		printf(" ��");
		Sleep(100);
	}
	me->hp -= boss->power;
	Sleep(100);
	clean_view();
}

void use_potion(Player* me)
{
	int i;

	if (me->potionList->effect != 0)
	{
		clean_view();
		gotoxy(5, 20);
		printf("   �סס� ���ǻ�� �סס�");

		for (i = 0; i < 7; i++)
		{
			gotoxy(15, 18 - i);
			printf("�ܡܡ�");
			Sleep(100);
		}
		me->hp += me->potionList->effect; //ȸ����Ų ��,
		me->potionList = (me->potionList->link);
	}
	else
	{
		gotoxy(5, 18);
		printf("����� �� �ִ� ������ �����ϴ�.\n");
		Sleep(1000);
	}
}



void battle(Player* me, Player* boss)
{
	int n, i;
	int potion = 300;
	clean_view();
	basic_view1("BATTLE");
	basic_view2(me);
	gotoxy(1, 20);
	printf("�������� ��Ʋ�� �����Ѵ٢�");

	while (1)
	{
		boss_state(boss);
		gotoxy(0, 22);
		printf("  1. �����ϱ�\n");
		printf("  2. ���ǻ��\n"); //��ũ����Ʈ�� ����
		printf("   1 or 2 ===> "); scanf("%d", &n);
		if (n == 1)
		{
			clean_view();
			gotoxy(5, 20);
			printf("  �����ð��� �۶����� Z z z\n\n");
			gotoxy(15, 23);
			for (i = 0; i < 10; i++)
			{
				printf("�� ");
				Sleep(100);
			}
			boss->hp -= me->power;
			boss_state(boss);
			Sleep(1500);
			if (boss->hp <= 0)
			{
				clean_view();
				basic_view1("BATTLE");
				basic_view2(me);
				gotoxy(35, 15);
				printf("�ڡڡڡڡ� PLAYER WIN �ڡڡڡڡ�");
				break;
			}
			else
			{
				boss_attack(me, boss);
				basic_view1("BATTLE");
				basic_view2(me);
				Sleep(700);
				if (me->hp <= 0)
				{
					clean_view();
					gotoxy(35, 15);
					printf("====== PLAYER LOOSE ======");
					exit(1);
				}
			}
		}
		else if (n == 2)
		{
			use_potion(me);
			Sleep(200);
			clean_view();
			basic_view1("BATTLE");
			basic_view2(me);
		}
		else
			printf("�ٽ��Է��ϼ���.");
		continue;
	}
	getch();
}