#include "Array.h"
#include <iostream>
#include <conio.h>
#include "Menu.h"

using namespace std;

enum List 
{
	Quit,
	ArrayGet, 
	Add, 
	Delete, 
	Push, 
	Sorting, 
	LinSearch, 
	BinSearch, 
};

void Menu(Dynamic* dynArray)
{
	List item = Quit;
	int number = item;
	bool exit = true;
	bool isArrayCreated = false;
	bool isArraySorted = false;
	Create(dynArray);
	cout << "\t\t����� ����������!\n";
	while (exit==true)
	{
		cout << "\t\t�������� ����� ����.\n" << endl
			<< "1-������� ������������ ������\n" << endl
			<< "2-�������� ������� � ������\n" << endl
			<< "3-������� ������� �� �������\n" << endl
			<< "4-�������� �������\n" << endl
			<< "5-������������� ������\n" << endl
			<< "6-�������� ����� ��������\n" << endl
			<< "7-�������� ����� ��������\n" << endl
			<< "0-�����\n" << endl
			<< "��������� �����: ";
		number = InputValidation(number);
		switch (number)
		{
		case(ArrayGet): 
		{
			system("cls");
			bool flag = true;
			do
			{
				int lenght=0;
				cout << "������� ���������� ���������: ";
				lenght = InputValidation(lenght);
				dynArray->length = 0;
				cout << "1- ��������� ������ ���������� �������\n" << endl
					<< "2- ��������� ������ �������\n" << endl;
				int choose = _getch();
				system("cls");
				switch (choose)
				{
					case('1'):
					{
						ArrayGetAuto(dynArray, lenght);
						flag = false;
						break;
					}
					case('2'):
					{
						ArrayGetManually(dynArray, lenght);
						flag = false;
						break; 
					}

				default:
					cout << "������ �� ���������� ����� � ����!\n";
					break;
				}
			} while (flag == true);
			ArrayShow(dynArray);
			isArrayCreated = true;
			break;
		}
		case(Add): 
		{
			system("cls");
			if (ArrayValidation(isArrayCreated)==false)
			{
				break;
			}
			int index;
			bool flag = true;
			ArrayShow(dynArray);
			int value = 0;
			cout << "������� ����� �������: ";
			value=InputValidation(value);
			index = dynArray->length;
			PushElement(dynArray, value, index);
			cout << "��������� ������:\n";
			ArrayShow(dynArray);
			break;
		}
		case(Delete): 
		{
			system("cls");
			if (ArrayValidation(isArrayCreated) == false)
			{
				break;
			}
			ArrayShow(dynArray);
			int index;
			cout << "������� ����� �������� �������, "
				<<"������� ���������� ������� : ";
			cin >> index;
			if (index < 1 || index > dynArray->length)
			{
				cout << "\n\t\t\t������ ��������\n" << endl;
				break;
			}
			else
				DeleteElement(dynArray, index);

			cout << "��������� ������: \n";
			ArrayShow(dynArray);
			break;
		}
		case(Push):
		{
			system("cls");
			if (ArrayValidation(isArrayCreated) == false)
			{
				break;
			}
			ArrayShow(dynArray);
			bool flag = true;
			int index;
			do
			{
				cout << "1-������� �������� � ������\n" << endl
					<< "2-������� �������� ����� ������������ ��������\n"
					<<endl
					<< "3-������� �������� � �����"<<endl;
				int choose = _getch();
				switch (choose)
				{
				case('1'):
				{
					flag = false;
					cout << "\n������� ����� ������� : ";
					int value = 0;
					value = InputValidation(value);
					index = 0;
					PushElement(dynArray, value, index);
					cout << "\n��������� ������:\n";
					ArrayShow(dynArray);
					break;
				}
				case('2'):
				{
					flag = false;
					cout << "\n������� ����� ������� : ";
					int value = 0;
					value = InputValidation(value);
					int index;
					cout << "\n������� ����� ��������, ����� �������� " 
						 <<"����� �������� ��������� ������� : ";
					cin >> index;
					if (index < 0 || index > dynArray->length)
					{
						cout << "\n������ �������\n" << endl;
						break;
					}
					else
					{
						PushElement(dynArray, value, index);
						cout << "��������� ������:\n";
						ArrayShow(dynArray);
						break;
					}
				}
				case('3'):
				{
					flag = false;
					cout << "\n������� ����� ������� : ";
					int value = 0;
					value = InputValidation(value);
					index = dynArray->length;
					PushElement(dynArray, value, index);
					cout << "��������� ������:\n";
					ArrayShow(dynArray);
					break;
				}
				default:
					cout << "\t\t\t������. ������������ ����� ����.\n";
					break;
				}
			} while (flag == true);
			break;
		}
		case(Sorting):
		{
			if (ArrayValidation(isArrayCreated) == false)
			{
				break;
			}
			system("cls");
			cout << "������ �� ����������:\n";
			ArrayShow(dynArray);
			isArraySorted = true;
			Sort(dynArray);
			cout << "\n������ ����� ����������:\n";
			ArrayShow(dynArray);
			break;
		}
		case(LinSearch):
		{
			if (ArrayValidation(isArrayCreated) == false)
			{
				break;
			}
			system("cls");
			int value=0;
			cout << "������� ������� : ";
			value = InputValidation(value);
			Search(dynArray, value);
			ArrayShow(dynArray);
			break;
		}
		case(BinSearch):
		{
			if (ArrayValidation(isArrayCreated) == false)
			{
				break;
			}

			if (isArraySorted == false)
			{
				cout << "\t\t\t������������ ������!\n";
				break;
			}
			system("cls");
			int value=0;
			cout << "������� ������� : ";
			value = InputValidation(value);
			BinarySearch(dynArray, value);
			ArrayShow(dynArray);
			break;
		}
		case(Quit):
			exit = false;
			break;
		default:
		{
			system("cls");
			cout << "\t\t\t������������ ����� ����\n" << endl;
			system("pause");
		break;
		}
	}
}

}