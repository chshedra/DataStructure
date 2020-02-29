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
			case 1:
			{
				int value;
				cout << " Введите элемент: ";
				value = InputValidation();
				cout << endl;
				InsertFront(list, value);
				PrintList(list);
				break;
			}
			case 2:
			{
				int value;
				cout << " Введите элемент: ";
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
					cout << "Необходимо создать список!" << endl;
					break;
				}
				else
				{
					cout << "Введите элемент: ";
					int value = InputValidation();
					cout << "Введите индекс: ";
					int index = InputValidation();
					//TODO: Дубль
					if (index < 0 || index >(list->Size - 1))
					{
						cout << "Индекс не соответствует размеру списка!";
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
					cout << "Необходимо создать список!" << endl;
					break;
				}
				cout << "Введите элемент: ";
				int value = InputValidation();
				cout << "Введите индекс: ";
				int index = InputValidation();
				//TODO: Дубль
				if (index < 0 || index >(list->Size - 1))
				{
					cout << "Индекс не соответствует размеру списка!";
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
					cout << "Необходимо создать список!" << endl;
					break;
				}
				int index;
				cout << "Введите индекс: ";
				index = InputValidation();
				if (index < 0 || index >(list->Size - 1))
				{
					cout << "Индекс не соответствует размеру списка! " << endl;
					cout << endl;
					break;
				}

				DeleteNode(list, index);
				if (list->Size == 0)
				{
					cout << "Список пуст!" << endl;
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
					cout << "Необходимо создать список!" << endl;
					break;
				}
				int result = 0;
				int value;
				int position = 0;
				cout << "Введите элемент: ";
				value = InputValidation();
				result = LinearSearch(list, value);
				cout << "Элемент под индексом " << result << endl;
				break;
			}
			case 7:
			{
				if (list->Head == nullptr)
				{
					cout << "Необходимо создать список!" << endl;
					break;
				}
				SortList(list);
				PrintList(list);
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


