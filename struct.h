#pragma once

//��ũ�� ����Ʈ�� ����
typedef struct Potion{
	int effect;
	struct Potion *link;
}Potion;

typedef struct {
	int weapon;
	Potion potionList;//��ũ�帮��Ʈ�� ����!
}Equipment;

typedef struct {
	char* name;
	int hp;
	Equipment equipment;
}Player;

typedef struct {
	void(*func)(Player* player, int* floor); //�� ȭ���� ����, ȭ�� �ȿ��� ���� �Լ� ����
	int reward; //���⳪ ġ���� �� �ϳ�
}Building;
