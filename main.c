#include "basic.h"
#include "function.h"

int main() {

	Player me = { "�÷��̾�", 1000, 200,0 };
	Player boss = { "����", 2000, 200,0 };
	Building** building;
	Potion * currentPotion;
	int floor = 1; //�÷��̾��� ���� ��
	int choice = 0; //�� ������ ������� �� ����
	int i;

	srand((unsigned int)time(NULL));

	me.potionList = addPotion(300);
	currentPotion = me.potionList;

	system("mode con cols=100 lines=30");//�ܼ�â ����
	setcursortype(); //Ŀ�� �����ֱ�

	//1.����ȭ�� ����ϱ�
	basic_view2(&me);
	start_view();
	//2. �ϴ� �� �������� ���̵� ����
	//3. �ǹ� ����� �����ֱ�

	building = make_building();
	building_info(&building); // ���� ���� �־��ֱ�

	basic_view2(&me);
	building_view(); //� Ű�� ������ �������� �Ѿ�� �Լ� ����

	while (floor <= 5) {
		i = floor;
		basic_view2(&me);
		floor_view(floor); //�� �� �����ֱ�
		choice = floor_logic(floor); //�� ����
		system("cls");
		if (floor != 5) {
			basic_view2(&me);
			building[floor - 1][choice - 1].func(&me, &floor);
			//�̰� �̰�� �����尡 1�̸� ���ǿ������ֱ�...
		}
		else {
			battle(&me, &boss);
		}
		if (i + 1 == floor && building[floor - 1][choice - 1].reward == 1) {

			currentPotion->link = addPotion(rand() % 10 + 300);
			currentPotion = currentPotion->link;
		}
	}

	//����ȭ��
	basic_view2(&me);
	result_view(); // �׳� ����Ű ������ �����ִ� ������ ���� ����
	free(building);//�ٸ������� free�������!!
}