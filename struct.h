#pragma once

//�Ҹ���
typedef enum _boolean {
	false,
	true
}bool;

//��ũ�� ����Ʈ�� ����
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
	void(*func)(Player* player, int* floor); //�� ȭ���� ����, ȭ�� �ȿ��� ���� �Լ� ����
	int reward; //0�̸� ���� ���ִ¹�, 1�̸� �����ִ¹�
}Building;
