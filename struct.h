#pragma once
typedef struct {
	void(*func)(Position * position, Player * player, int* floor); //�� ȭ���� ����, ȭ�� �ȿ��� ���� �Լ� ����
	char * reward; //���⳪ ġ���� �� �ϳ�
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
