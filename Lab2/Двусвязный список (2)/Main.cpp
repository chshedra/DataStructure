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
		cout << "1.Вставка элемента в начало\n"
			 << "2.Вставка элемента в конец\n"
			 << "3.Вставка после определенного элемента\n"
			 << "4.Вставка перед определённым элментом\n"
			 << "5.Удаление эдемента\n"
			 << "6.Линейный поиск\n"
			 << "7.Cортировка списка\n";
		cout << "Выберите пункт в меню: ";
		choice = InputValidation();
			switch (choice)
			{
				//TODO:RSDN
			case 1:
			{
					  int value;
					  cout << " Введите элемент: ";
					  value = InputValidation();
					  cout << endl;
					  InsertFront(set, value);
					  PrintList(set);
					  break;
			}
			case 2:
			{
					  int value;
					  cout << " Введите элемент: ";
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
						  cout << "Необходимо создать список!" << endl;
						  break;
					  }
					  //TODO: почему здесь?
					  int value;
					  int index;
					  cout << "Введите элемент: ";
					  value = InputValidation();
					  cout << "Введите индекс: ";
					  index = InputValidation();
					  //TODO: Дубль
					  if(index < 0 || index > (set->Size - 1))
					  {
						  cout << "Индекс не соответствует размеру списка!";
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
						  cout << "Необходимо создать список!" << endl;
						  break;
					  }

					  //TODO: почему здесь?
					  int value;
					  int index;
					  cout << "Введите элемент: ";
					  value = InputValidation();
					  cout << "Введите индекс: ";
					  index = InputValidation();
					  //TODO: Дубль
					  if (index < 0 || index >(set->Size - 1))
					  {
						  cout << "Индекс не соответствует размеру списка!";
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
						  cout << "Необходимо создать список!" << endl;
						  break;
					  }
					  int index;
					  cout << "Введите индекс: ";
					  index = InputValidation();
					  if (index < 0 || index > (set->Size - 1))
					  {
						  cout << "Индекс не соответствует размеру списка! " << endl;
						  cout << endl;
						  break;
					  }
					 
					  DeleteNode(set, index);
					  if (set->Size == 0)
					  {
						  cout << "Список пуст!" << endl;
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
						  cout << "Необходимо создать список!" << endl;
						  break;
					  }
					  int result = 0;
					  int value;
					  int position = 0;
					  cout << "Введите элемент: ";
					  value = InputValidation();
					  result = LinearSearch(set, value);
					  cout<<"Элемент под индексом "<< result<<endl;
					  break;
			}
			case 7:
			{
					  if (set->Head == nullptr)
					  {
						  cout << "Необходимо создать список!" << endl;
						  break;
					  } 
					  SortList(set);
					  PrintList(set);
					  break;
			}
			default:
			{
					   cout << "Выбран неверный пункт\n";
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


