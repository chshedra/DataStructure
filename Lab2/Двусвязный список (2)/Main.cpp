#include <iostream>
#include <time.h>
#include <chrono>
#include "List.h"
#include "Node.h"
using namespace std;

int InputValidation();
void PrintList(List* list);

void main()
{
	setlocale(LC_ALL, "Russian");

	List* set = CreateList();

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
				//TODO:RSDN
			case 1:
			{
					  int value;
					  cout << " ������� �������: ";
					  value = InputValidation();
					  cout << endl;
					  InsertFront(set, value);
					  PrintList(set);
					  break;
			}
			case 2:
			{
					  int value;
					  cout << " ������� �������: ";
					  value = InputValidation();
					  cout << endl;
					  InsertEnd(set, value);
					  PrintList(set);
					  break;
			}
			case 3:
			{
					  if (set->Head == nullptr)
					  {
						  cout << "���������� ������� ������!" << endl;
						  break;
					  }
					  //TODO: ������ �����?
					  int value;
					  int index;
					  cout << "������� �������: ";
					  value = InputValidation();
					  cout << "������� ������: ";
					  index = InputValidation();
					  //TODO: �����
					  if(index < 0 || index > (set->Size - 1))
					  {
						  cout << "������ �� ������������� ������� ������!";
						  cout << endl;
						  break;
					  }
					  InsertAfter(set, value, index);
					  PrintList(set);
					  break;
			}
			case 4:
			{
					  if (set->Head == nullptr)
					  {
						  cout << "���������� ������� ������!" << endl;
						  break;
					  }

					  //TODO: ������ �����?
					  int value;
					  int index;
					  cout << "������� �������: ";
					  value = InputValidation();
					  cout << "������� ������: ";
					  index = InputValidation();
					  //TODO: �����
					  if (index < 0 || index >(set->Size - 1))
					  {
						  cout << "������ �� ������������� ������� ������!";
						  cout << endl;
						  break;
					  }
					  InsertBefore(set, value, index);
					  PrintList(set);
					  break;
			}
			case 5:
			{
					  if (set->Head == nullptr)
					  {
						  cout << "���������� ������� ������!" << endl;
						  break;
					  }
					  int index;
					  cout << "������� ������: ";
					  index = InputValidation();
					  if (index < 0 || index > (set->Size - 1))
					  {
						  cout << "������ �� ������������� ������� ������! " << endl;
						  cout << endl;
						  break;
					  }
					 
					  DeleteNode(set, index);
					  if (set->Size == 0)
					  {
						  cout << "������ ����!" << endl;
						  cout << endl;
						  break;
					  }
					  PrintList(set);
					  break;
			}
			case 6:
			{
					  if (set->Head == nullptr)
					  {
						  cout << "���������� ������� ������!" << endl;
						  break;
					  }
					  int result = 0;
					  int value;
					  int position = 0;
					  cout << "������� �������: ";
					  value = InputValidation();
					  result = LinearSearch(set, value);
					  cout<<"������� ��� �������� "<< result<<endl;
					  break;
			}
			case 7:
			{
					  if (set->Head == nullptr)
					  {
						  cout << "���������� ������� ������!" << endl;
						  break;
					  } 
					  SortList(set);
					  PrintList(set);
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


void PrintList(List *list)
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


