#include "Array.h"
#include <iostream>
#include <conio.h>
#include "Menu.h"

using namespace std;
enum list {Quit,ArrayGet, addElement, deleteElement, 
	pushElement, sort, linearySearch, binarySearch};

void Menu(Array* set)
{
	list item = ArrayGet;
	int number = item;
	bool exit = true;
	bool isArrayCreated = false;
	bool isArraySorted = false;
	Create(set);
	cout << "����� ����������!\n";
	while (exit)
	{
		cout << "�������� ����� ����.\n"
			<< "1-������� ������������ ������\n"
			<< "2-�������� ������� � ������\n"
			<< "3-������� ������� �� �������\n"
			<< "4-�������� �������\n"
			<< "5-������������� ������\n"
			<< "6-�������� ����� ��������\n"
			<< "7-�������� ����� ��������\n"
			<< "0-�����\n";
		cin >> number;
		switch (number)
		{
		case(ArrayGet): //�������� �������
			system("cls");
			bool key = true;
			do
			{
				int len;
				cout << "������� ���������� ���������: ";
				cin >> len;
				set->length = 0;
				cout << "1- ��������� ������ ���������� �������\n"
					<< "2- ��������� ������ �������\n";
				int choose = _getch();
				system("cls");
				switch (choose)
				{
				case(1):
						ArrayGetAuto(set, len);
						key = false;
						break;
				case(2):
						ArrayGetManually(set, len);
						key = false;
						break;

				default:
						cout << "\t������ �� ���������� ����� � ����!\n";
						break;
				}
		}
			while (key = true);
			ArrayShow(set);
			isArrayCreated = true;
			break;
		case(addElement): // ���������� ��������
			if (isArrayCreated == false)
			{
				cout << "������ �� ������! �������� ������. (����� ���� 1)";
				break;
			}
			int index;
			key = true;
			system("cls");
			ArrayShow(set);
			do
			{
				int value;
				cout << "������� ����� �������: ";
				cin >> value;
				cout << "\n1-�������� ������� � ������\n"
					<< "2-�������� ������� ����� ������������ ��������\n"
					<< "3-�������� ������� � �����\n";
				int choose = _getch();

				switch (choose)
				{
				case(1):
					key = false;
					index = 0;
					AddElement(set, value, index);
					break;
				case(2):
					key = false;
					cout << "������� ����� ��������, ����� �������� ����� �������� ��������� ������� : ";
					cin >> index;
					if (index < 0 || index > set->length)
					{
						cout << "\n������ ����������\n" << endl;
					}
					else
						AddElement(set, value, index);
					break;
				case(3):
					key = false;
					index = set->length;
					AddElement(set, value, index);
					break;
				default:
					cout << "������������ ����� ����\n";
					break;
				}
			} while (key = true);
			cout << "��������� ������:\n";
			ArrayShow(set);
			break;
		case(deleteElement): //�������� ��������
			system("cls");
			if (isArrayCreated == false)
			{
				cout << "\t �������� ������\n";
				break;
			}
			ArrayShow(set);
			cout << "������� ����� �������� �������, ������� ���������� ������� : ";
			cin >> index;
			if (index < 0 || index > set->length)
			{
				cout << "\n������ ��������\n" << endl;
			}
			else
				DeleteElement(set, index);

			cout << "��������� ������: \n";

			ArrayShow(set);
			break;

		case(pushElement): //������� ��������
			system("cls");
			if (isArrayCreated == false)
			{
				cout << "\t �������� ������\n";
				break;
			}
			ArrayShow(set);
			key = true;
			int value;
			do
			{
				cout << "1-������� �������� � ������\n"
					<< "2-������� �������� ����� ������������ ��������\n"
					<< "3-������� �������� � �����";
				int choose = _getch();
				switch (choose)
				{
				case(1):
					key = false;
					cout << "\n������� ����� ������� : ";
					cin >> value;
					index = 0;
					GetElement(set, value, index);
					cout << "\n��������� ������:\n";
					ArrayShow(set);
					break;
				case(2):
					key = false;
					cout << "\n������� ����� ������� : ";
					cin >> value;
					cout << "\n������� ����� ��������, ����� �������� ����� �������� ��������� ������� : ";
					cin >> index;
					if (index < 0 || index > set->length)
					{
						cout << "\n������ �������\n";
					}
					else
						GetElement(set, value, index);
					cout << "��������� ������:\n";
					ArrayShow(set);
					break;
				case(3):
					key = false;
					cout << "\n������� ����� ������� : ";
					cin >> value;
					index = set->length;
					GetElement(set, value, index);
					cout << "��������� ������:\n";
					ArrayShow(set);
					break;
				default:
					cout << "������. ������������ ����� ����.\n";
					break;
				}
			} while (key = true);
		case(sort):
			if (isArrayCreated == false)
			{
				cout << "\t �������� ������\n\n";
				break;
			}
			system("cls");
			cout << "������ �� ����������:\n";
			ArrayShow(set);
			isArraySorted = true;
			BubbleSort(set);
			cout << "\n������ ����� ����������:\n";
			ArrayShow(set);
			break;
		case(linearySearch):
			if (isArrayCreated == false)
			{
				cout << "\t �������� ������\n\n";
				break;
			}
			system("cls");
			cout << "������� ������� : ";
			cin >> value;
			cout << (Search(set, value) ? "������� ������\n" : "������� �� ������\n");
			ArrayShow(set);
			break;
		case(binarySearch):
			if (isArrayCreated == false)
			{
				cout << "\t �������� ������\n\n";
				break;
			}

			if (isArraySorted == false)
			{
				cout << "\t ������������ ������ ��� ������ � �������� �������!\n";
				break;
			}
			system("cls");
			cout << "������� ������� : ";
			cin >> value;
			cout << (BinarySearch(set, value) ? "������� ������\n" : "������� �� ������\n");
			ArrayShow(set);
			break;
		case(Quit):
			exit = false;
			break;

		default:
			cout << "������������ ����� ����\n";
			break;
		}
	}

}