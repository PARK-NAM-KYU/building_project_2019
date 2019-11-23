#pragma once
typedef struct {
	void(*func)(Position * position, Player * player, int* floor); //방 화면을 넣음, 화면 안에다 로직 함수 구현
	char * reward; //무기나 치유템 중 하나
}Building;

typedef struct {
	int weapon;
	int item_count;
}Equipment;

typedef struct {
	char* name;
	int hp;
	Equipment equipment;
}Player;

typedef struct {
	int x;
	int y;
}Position;
