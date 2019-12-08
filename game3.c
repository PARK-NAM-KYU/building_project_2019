#include "basic.h"
#define PLAYERCODE 1;
#define ENEMYCODE 2;

typedef struct _bullet {
	bool exist;
	int x, y;
}bullet;

typedef struct _character{
	int health;
	int personalCode;
	int x;
	int y;
	void(*shape)(int, int);
	void(*anti_shape)(int, int);
	bullet Bullet[3];

} Character;

void key_event(Character * me, bullet Bullet[]);
void player_shape(int x, int y);
void anti_player_shape(int x, int y);
void enemy_shape(int x, int y);
void anti_enemy_shape(int x, int y);
void remove_bullet(bullet* Bullet);
void runBullet(bullet* Bullet, int k);
void enemyDeath(Character * enemy);

void game3(Character* player, int* floor) {
	int cnt = 1;
	int i, j;
	int cnt_hunt = 0;

	Character me = { 100,1, 50, 20, player_shape,anti_player_shape};
	Character eachEnemy = { 100,2, 50, 6, enemy_shape,anti_enemy_shape};
	Character enemy[3];

	basic_view1("슈팅게임");

	for (i = 0; i < 3; i++) {
		enemy[i] = eachEnemy;
		enemy[i].x = 7 + rand() % 84;
		enemy[i].y = 6 + rand() % 3;
		for (j = 0; j < 3; j++)enemy[i].Bullet[j].exist = false;
		me.Bullet[i].exist = false;
	}
	me.shape(me.x, me.y);
	while (1)
	{

		if (me.health <= 0 || cnt_hunt >= 5)break;
		if (cnt % 300 == 1) {
			gotoxy(0, 5);
			printf("              \n");
			printf("                ");
			gotoxy(0, 5);
			printf("me's hp : %d\n", me.health);
			printf("잡은 적의 수 : %d", cnt_hunt);
		}

		//총알일 적에 닿았을 때
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (me.Bullet[i].y == 1 + enemy[j].y&& me.Bullet[i].x >= enemy[j].x - 6 && me.Bullet[i].x <= enemy[j].x + 1) {
					enemy[j].health -= 50;
					remove_bullet(&me.Bullet[i]);
					if (enemy[j].health <= 0) {
						enemy[j].anti_shape(enemy[j].x, enemy[j].y);
						enemyDeath(&enemy[j]);
						cnt_hunt++;
					}
				}
			}
		}

		//내가 총에 맞으면... 
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (enemy[i].Bullet[j].y == me.y - 1 && enemy[i].Bullet[j].x >= me.x - 5 && enemy[i].Bullet[j].x <= me.x + 1) {
					me.health -= 5;
					remove_bullet(&(enemy[i].Bullet[j]));
				}
			}
		}

		//적이 지정범위를 넘어서면 없애셈
		for (j = 0; j < 3; j++)if (enemy[j].y >= 25) {
			enemy[j].anti_shape(enemy[j].x, enemy[j].y);
			enemy[j].health = 100;
			enemy[j].x = 7 + rand() % 80;
			enemy[j].y = 6;
		}

		//키입력
		if (kbhit()) {
			key_event(&me, me.Bullet);
			fflush(stdin);
		}

		//적상태 업데이트 하기
		if (cnt % 8000 == 1) {
			for (j = 0; j < 3; j++) {
				enemy[j].anti_shape(enemy[j].x, enemy[j].y);
				enemy[j].y += 1;
				enemy[j].shape(enemy[j].x, enemy[j].y);
			}
		}

		if (cnt % 3000 == 1) {
			for (j = 0; j < 3; j++) {
				for (i = 0; i < 3; i++) {
					if (enemy[j].y >= 20) {
						enemy[j].Bullet[i].exist = false;
					}
					else {
						if (enemy[j].Bullet[i].exist == false) {
							enemy[j].Bullet[i].exist = true;
							enemy[j].Bullet[i].x = enemy[j].x - 3;
							enemy[j].Bullet[i].y = enemy[j].y + 1 + 2 * i;
						}
						runBullet(&(enemy[j].Bullet[i]), 2);
					}
				}
			}
		}

		//총알상태 확인
		if (cnt % 300 == 1)for (i = 0; i < 3; i++) if (me.Bullet[i].exist == true) runBullet(&(me.Bullet[i]), 1);

		cnt++;
	}
	system("cls");
	gotoxy(47, 15);
	if (me.health > 0) {
		printf("win");
		*floor += 1;
	}
	else printf("lose");
	getch();
	system("cls");
}

//함수

void key_event(Character * me, bullet Bullet[]) {
	int i;
	int ch = getch();
	if (ch == 224) {
		me->anti_shape(me->x, me->y);
		ch = getch();
		switch (ch) {
		case 72:
			if (me->y > 6) me->y--;
			break;
		case 80:
			if (me->y < 25) me->y++;
			break;
		case 75:
			if (me->x > 8) me->x--;
			break;
		case 77:
			if (me->x < 95) me->x++;
		}
		me->shape(me->x, me->y);

	}
	else if (ch == ' ') {
		for (i = 0; i < 3; i++) {
			if (Bullet[i].exist == false) {
				Bullet[i].exist = true;
				Bullet[i].x = me->x - 3;
				Bullet[i].y = me->y - 1;
				break;
			}
		}
	}
}

void player_shape(int x, int y) {
	gotoxy(x - 5, y);
	printf("<-me->");
}

void anti_player_shape(int x, int y) {
	gotoxy(x - 5, y);
	printf("      ");

}

void enemy_shape(int x, int y) {
	gotoxy(x - 6, y);
	printf("<<-oo->>");
	gotoxy(x, y);
}

void anti_enemy_shape(int x, int y) {
	gotoxy(x - 6, y);
	printf("        ");
	gotoxy(x, y);
}

void remove_bullet(bullet* Bullet) {
	gotoxy(Bullet->x, Bullet->y);
	printf(" ");
	Bullet->x = 0;
	Bullet->y = 0;
	Bullet->exist = false;
}

void runBullet(bullet* Bullet, int k) {

	//x,y값 바꿔주고
	if (Bullet->y <= 6) {
		gotoxy(Bullet->x, Bullet->y);
		printf(" ");
		Bullet->exist = false;
		return;
	}
	else if (Bullet->y >= 25) {
		gotoxy(Bullet->x, Bullet->y);
		printf(" ");
		Bullet->exist = false;
		return;
	}
	else {
		gotoxy(Bullet->x, Bullet->y);
		printf(" ");
		if (k == 1)Bullet->y -= 1;
		else Bullet->y += 1;	
		//현재위치 출력해주고
		gotoxy(Bullet->x, Bullet->y);
		if (k == 1)printf("*");
		else printf("#");
	}
}

void enemyDeath(Character * enemy) {
	srand((unsigned int)time(NULL));
	enemy->anti_shape(enemy->x, enemy->y);
	enemy->health = 100;
	enemy->x = 7 + rand() % 80;
	enemy->y = 6;
}