#include <iostream>
#include <cstdlib>
#include <ctime>

// ��ǻ�Ϳ� ���������� ��� - �����Լ� �̿�
using namespace std;
int main()
{
	int i = 1, j = 1, sum = 0;
	int win = 0, draw = 0, lose = 0;
	string name;

	cout << "\n      ����������������������������������������������������������������������������������" << endl;
	cout << "      ��       ��:3��    ��:1��    ��:0��      ��" << endl;
	cout << "      ����������������������������������������������������������������������������������" << endl;

	while (j == 1)
	{
		while (i < 6)
		{
			srand((unsigned)time(NULL));
			int user, com;

			cout << "\n==============<��ǻ�Ϳ� ���������� ���>==============" << endl;
			cout << "\n[" << i << "��° �����Դϴ�]" << endl << endl;
			cout << "1.����\n2.����\n3.��" << endl << endl;
			do {
				cout << "��ȣ�� �Է��ϼ��� : ";
				cin >> user;
			} while (user < 1 || user>3);

			com = rand() % 3 + 1;

			// ����� ���� ���� �Ǻ�
			if (((user == 1) && (com == 3)) || ((user == 3) && (com == 1)))
				if (user == 1) {
					cout << "\n�̰���ϴ�!" << endl << endl;
					win += 1;
				}
				else {
					cout << "\n�����ϴ�!" << endl << endl;
					lose += 1;
				}

			else if (user == com) {
				cout << "\n���º��Դϴ�!" << endl << endl;
				draw += 1;
			}

			else
				if (user > com) {
					cout << "\n�̰���ϴ�!" << endl << endl;
					win += 1;
				}
				else {
					cout << "\n�����ϴ�!" << endl << endl;
					lose += 1;
				}

			// ����� ���������� ���
			switch (user)
			{
			case 1:
				cout << "����� ������ �½��ϴ�" << endl;
				break;
			case 2:
				cout << "����� ������ �½��ϴ�" << endl;
				break;
			case 3:
				cout << "����� ���� �½��ϴ�" << endl;
				break;
			}

			// ��ǻ�� ���������� ���
			switch (com)
			{
			case 1:
				cout << "��ǻ�ʹ� ������ �½��ϴ�" << endl;
				break;
			case 2:
				cout << "��ǻ�ʹ� ������ �½��ϴ�" << endl;
				break;
			case 3:
				cout << "��ǻ�ʹ� ���� �½��ϴ�" << endl;
				break;
			}
			i += 1;
			cout << "\n���� ���: " << win << "�� " << draw << "�� " << lose << "�� " << endl;

		}

		cout << "\n======================================================" << endl << endl;
		cout << "�̸��� �Է��ϼ���: ";
		cin >> name;
		cout << endl << endl;
		cout << "\n\n                  < ������� >" << endl << endl;
		cout << "                  " << win << "�� " << draw << "�� " << lose << "�� " << endl << endl;
		cout << "      " << name << "���� ������ " << win * 3 + draw << "�Դϴ�." << endl << endl;
		cout << "\n1.�ѹ� �� �ϱ�\n2.�ߴ��ϱ�\n\n��ȣ�� �Է��ϼ��� : ";
		cin >> j;

		i = 1;
		win = 0, draw = 0, lose = 0;

	}



	return 0;
}