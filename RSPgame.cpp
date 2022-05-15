/* ��ǻ�Ϳ� ���������� ��� - �����Լ� �̿� */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int win = 0, draw = 0, lose = 0;
string name0, name1, name2, name3, name4, name;

void winorlose(int u, int c);
void userresult(int ur);
void comresult(int cr);
string namelist(int game);

int main()
{
	int times = 1, game = 0, score[5]={0};

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
			score[game] = win * 3 + draw;
			cout << "�̸��� �Է��ϼ���: ";
			switch (game) {
			case 0: cin >> name0; break;
			case 1: cin >> name1; break;
			case 2: cin >> name2; break;
			case 3: cin >> name3; break;
			case 4: cin >> name4; break;
			}
			cout << endl << endl;
			cout << "\n\n                  < ������� >" << endl << endl;
			cout << "                  " << win << "�� " << draw << "�� " << lose << "�� " << endl << endl;
			cout << "      " << namelist(game) << "���� ������ " << score[game] << "�� �Դϴ�." << endl << endl;

			//���° �������� ���
			game++;

			//��Ƚ��, �¹��� �ʱ�ȭ
			times = 1, win = 0, draw = 0, lose = 0;
		}

		if (game == 5) break;
	}
	cout << "\n\n======================================================" << endl<<endl;
	cout << "    <��ü����> " << endl << endl;
	for (int j=0; j < 5; j++) cout << j+1<<". "<<namelist(j) << "        " << score[j] << endl;
	cout << "\n\n======================================================" << endl << endl;
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

string namelist(int game) {
	switch (game) {
	case 0: name = name0; break;
	case 1: name = name1; break;
	case 2: name = name2; break;
	case 3: name = name3; break;
	case 4: name = name4; break;
	}
	return name;
}