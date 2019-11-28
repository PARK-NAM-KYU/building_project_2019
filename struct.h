#pragma once

//링크드 리스트로 구현
typedef struct Potion{
	int effect;
	struct Potion *link;
}Potion;

typedef struct {
	int weapon;
	Potion potionList;//링크드리스트로 구현!
}Equipment;

typedef struct {
	char* name;
	int hp;
	Equipment equipment;
}Player;

typedef struct {
	void(*func)(Player* player, int* floor); //방 화면을 넣음, 화면 안에다 로직 함수 구현
	int reward; //무기나 치유템 중 하나
}Building;
