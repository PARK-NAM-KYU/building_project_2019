#include "basic.h"
#include "struct.h"
#include "function.h"

int main() {

<<<<<<< Updated upstream
<<<<<<< Updated upstream
	Player me;
=======
	Player me = { "�÷��̾�", 1000, 200,0};
	Player boss = { "����", 2000, 200,0};
>>>>>>> Stashed changes
	Building** building;
	Position position; // x,y ��ǥ
=======
	Player me = { "�÷��̾�", 100, 20, {0, 0}};
	Player boss = { "����", 200, 20, {0, 0}};
	Building** building;
	Potion* head = (Potion*)malloc(sizeof(Potion));
	Potion* potionList = (Potion*)malloc(sizeof(Potion)); //���� ���������� �����Ҵ� ��
	head->link = NULL; //head�� ��������ְ� ������ link�� NULL����
	potionList->effect = 30;
	
>>>>>>> Stashed changes
	int floor = 1; //�÷��̾��� ���� ��
	int choice; //�� ������ ������� �� ����

<<<<<<< Updated upstream
	//position �ʱ�ȭ
	position.x = 1;
	position.y = 1;
=======
	me.potionList = addPotion(300);
	currentPotion = me.potionList;
>>>>>>> Stashed changes

	//1.����ȭ�� ����ϱ�
<<<<<<< Updated upstream
	start_view(&position);
	start_logic();

=======
	basic_view2(&me);
	start_view();
>>>>>>> Stashed changes
	//2. �ϴ� �� �������� ���̵� ����
	//3. �ǹ� ����� �����ֱ�
	building = make_building();
	building_view(&position); //� Ű�� ������ �������� �Ѿ�� �Լ� ����

	building_info(&building); // ���� ���� �־��ֱ�
<<<<<<< Updated upstream

	while (floor<=5) {
		floor_view(&position); //�� �� �����ֱ�
=======
	
	basic_view2(&me);
	building_view(); //� Ű�� ������ �������� �Ѿ�� �Լ� ����
	
	/*while (floor <= 5) {
		basic_view2(me);

		floor_view(floor); //�� �� �����ֱ�
>>>>>>> Stashed changes
		choice = floor_logic(); //�� ����
		building[floor - 1][choice - 1].func(&position, &me, &floor);
	}
<<<<<<< Updated upstream

	//����ȭ��
=======
	*/
	battle(&me, &boss); //5������ ��Ʋ

	//����ȭ��
	basic_view2(&me);
>>>>>>> Stashed changes
	result_view(); // �׳� ����Ű ������ �����ִ� ������ ���� ����

}