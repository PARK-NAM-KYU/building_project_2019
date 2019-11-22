#pragma once
typedef struct {
	void(*fp)(); //방 화면을 넣음(방 로직은 화면 안에다가 구현)
	char * reward; //무기나 치유템 중 하나
}Building;

typedef struct {
	int weapon;
	int item_count;
}Equipment;

typedef struct {
	int hp;
	Equipment equipment;
}Player;

typedef struct {
	int x;
	int y;
}Position;
