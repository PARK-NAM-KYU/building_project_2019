#include "basic.h"
#include "function.h"

int main() {

	Player me;
	Building** building;
	Position position; // x,y ��ǥ
	int floor = 1; //�÷��̾��� ���� ��
	int choice; //�� ������ ������� �� ����

	//position �ʱ�ȭ
	position.x = 1;
	position.y = 1;

	//1.����ȭ�� ����ϱ�
	start_view(&position);
	start_logic();

	//2. �ϴ� �� �������� ���̵� ����
	//3. �ǹ� ����� �����ֱ�
	building = make_building();
	building_view(&position); //� Ű�� ������ �������� �Ѿ�� �Լ� ����

	building_info(&building); // ���� ���� �־��ֱ�

	while (floor <= 5) {
		floor_view(&position); //�� �� �����ֱ�
		choice = floor_logic(); //�� ����
		building[floor - 1][choice - 1].func(&position, &me, &floor);
	}

	//����ȭ��
	result_view(&position); // �׳� ����Ű ������ �����ִ� ������ ���� ����

}