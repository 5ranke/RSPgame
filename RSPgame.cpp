/* ��ǻ�Ϳ� ���������� ��� - �����Լ� �̿� */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int win = 0, draw = 0, lose = 0;
void winorlose(int u, int c);
void userresult(int ur);
void comresult(int cr);

int main()
{
	int times = 1, game = 1, sum = 0, j=1;
	
	string name;

	cout << "\n      ����������������������������������������������������������������������������������" << endl;
	cout << "      ��       ��:3��    ��:1��    ��:0��      ��" << endl;
	cout << "      ����������������������������������������������������������������������������������" << endl;

	while (times < 6) {
		srand((unsigned)time(NULL));
		int user, com;

		cout << "\n==============<��ǻ�Ϳ� ���������� ���>==============" << endl;
		cout << "\n[" << times << "��° �����Դϴ�]" << endl << endl;
		cout << "1.����\n2.����\n3.��" << endl << endl;

		do { //���� 1~3�� �ƴҰ�� ��� �Է¹ް���
			cout << "��ȣ�� �Է��ϼ��� : ";
			cin >> user;
		} while (user < 1 || user>3);

		com = rand() % 3 + 1;

		winorlose(user, com); //������� �¹��� �Ǻ�
		userresult(user); //������� ����
		comresult(com); //��ǻ���� ����

		times += 1;
		cout << "\n���� ���: " << win << "�� " << draw << "�� " << lose << "�� " << endl;

		if (times == 6) { //5��°�� ����
			cout << "\n======================================================" << endl << endl;
			cout << "�̸��� �Է��ϼ���: "; cin >> name;
			cout << endl << endl;
			cout << "\n\n                  < ������� >" << endl << endl;
			cout << "                  " << win << "�� " << draw << "�� " << lose << "�� " << endl << endl;
			cout << "      " << name << "���� ������ " << win * 3 + draw << "�� �Դϴ�." << endl << endl;

			cout << "\n1.�ѹ� �� �ϱ�\n2.�ߴ��ϱ�\n\n��ȣ�� �Է��ϼ��� : ";
			cin >> j;

			//���° �������� ���
			game++;

			//��Ƚ��, �¹��� �ʱ�ȭ
			times = 1, win = 0, draw = 0, lose = 0;
		}

		if (j == 2) break;
	}
	return 0;
}

void winorlose(int u, int c) { //������� �¹��� �Ǻ� �Լ�
	if (((u == 1) && (c == 3)) || ((u == 3) && (c == 1)))
		if (u == 1) { cout << "\n�̰���ϴ�!" << endl << endl; win += 1; }
		else { cout << "\n�����ϴ�!" << endl << endl; lose += 1; }

	else if (u == c) { cout << "\n���º��Դϴ�!" << endl << endl; draw += 1; }
	else
		if (u > c) { cout << "\n�̰���ϴ�!" << endl << endl; win += 1; }
		else { cout << "\n�����ϴ�!" << endl << endl; lose += 1; }
}

void userresult(int ur) { //����ڼ��� ���
	switch (ur) {
	case 1: cout << "����� ������ �½��ϴ�" << endl; break;
	case 2: cout << "����� ������ �½��ϴ�" << endl; break;
	case 3: cout << "����� ���� �½��ϴ�" << endl; break;
	}
}

void comresult(int cr) { // ��ǻ�ͼ��� ���
	switch (cr) {
	case 1: cout << "��ǻ�ʹ� ������ �½��ϴ�" << endl; break;
	case 2: cout << "��ǻ�ʹ� ������ �½��ϴ�" << endl; break;
	case 3: cout << "��ǻ�ʹ� ���� �½��ϴ�" << endl; break;
	}
}