#pragma once

//불리언
typedef enum _boolean {
	false,
	true
}bool;

//링크드 리스트로 구현
typedef struct potion{
	int effect;
	struct potion * link;
}Potion;

typedef struct {
	char* name;
	int hp;
	int power;
	Potion* potionList;
}Player;

typedef struct {
	void(*func)(Player* player, int* floor); //방 화면을 넣음, 화면 안에다 로직 함수 구현
	int reward; //0이면 선물 안주는방, 1이면 선물주는방
}Building;
