#include <iostream>
#include <time.h>
#include <chrono>
#include "DoubleLinkedList.h"
#include "Node.h"
using namespace std;

int InputValidation();
void PrintList(DoubleLinkedList* list);

void main()
{
	setlocale(LC_ALL, "Russian");

	DoubleLinkedList* list = CreateList();

	while (true)
	{
		int choice;
		cout << "1.������� �������� � ������\n"
			<< "2.������� �������� � �����\n"
			<< "3.������� ����� ������������� ��������\n"
			<< "4.������� ����� ����������� ��������\n"
			<< "5.�������� ��������\n"
			<< "6.�������� �����\n"
			<< "7.C��������� ������\n";
		cout << "�������� ����� � ����: ";
		choice = InputValidation();
		switch (choice)
		{
			case 1:
			{
				int value;
				cout << " ������� �������: ";
				value = InputValidation();
				cout << endl;
				InsertFront(list, value);
				PrintList(list);
				break;
			}
			case 2:
			{
				int value;
				cout << " ������� �������: ";
				value = InputValidation();
				cout << endl;
				InsertEnd(list, value);
				PrintList(list);
				break;
			}
			case 3:
			{
				if (list->Head == nullptr)
				{
					cout << "���������� ������� ������!" << endl;
					break;
				}
				else
				{
					cout << "������� �������: ";
					int value = InputValidation();
					cout << "������� ������: ";
					int index = InputValidation();
					//TODO: �����
					if (index < 0 || index >(list->Size - 1))
					{
						cout << "������ �� ������������� ������� ������!";
						cout << endl;
						break;
					}
					InsertAfter(list, value, index);
					PrintList(list);
					break;
				}
			}
			case 4:
			{
				if (list->Head == nullptr)
				{
					cout << "���������� ������� ������!" << endl;
					break;
				}
				cout << "������� �������: ";
				int value = InputValidation();
				cout << "������� ������: ";
				int index = InputValidation();
				//TODO: �����
				if (index < 0 || index >(list->Size - 1))
				{
					cout << "������ �� ������������� ������� ������!";
					cout << endl;
					break;
				}
				InsertBefore(list, value, index);
				PrintList(list);
				break;
			}
			case 5:
			{
				if (list->Head == nullptr)
				{
					cout << "���������� ������� ������!" << endl;
					break;
				}
				int index;
				cout << "������� ������: ";
				index = InputValidation();
				if (index < 0 || index >(list->Size - 1))
				{
					cout << "������ �� ������������� ������� ������! " << endl;
					cout << endl;
					break;
				}

				DeleteNode(list, index);
				if (list->Size == 0)
				{
					cout << "������ ����!" << endl;
					cout << endl;
					break;
				}
				PrintList(list);
				break;
			}
			case 6:
			{
				if (list->Head == nullptr)
				{
					cout << "���������� ������� ������!" << endl;
					break;
				}
				int result = 0;
				int value;
				int position = 0;
				cout << "������� �������: ";
				value = InputValidation();
				result = LinearSearch(list, value);
				cout << "������� ��� �������� " << result << endl;
				break;
			}
			case 7:
			{
				if (list->Head == nullptr)
				{
					cout << "���������� ������� ������!" << endl;
					break;
				}
				SortList(list);
				PrintList(list);
				break;
			}
			default:
			{
				cout << "������ �������� �����\n";
				break;
			}
		}
	}
	system("pause");
}

int InputValidation()
{
	int number = 0;

	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Try again!\n";
		}
		else
		{
			break;
		}
	}

	return number;
}


void PrintList(DoubleLinkedList *list)
{
	Node *tmp = new Node;
	tmp = list->Head;
	while (tmp != nullptr)
	{
		cout << tmp->Data << " ";
		tmp = tmp->Next;
	}
	cout << endl;
	delete tmp;
}


