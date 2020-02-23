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
	cout << "Добро пожаловать!\n";
	while (exit)
	{
		cout << "Выберите пункт меню.\n"
			<< "1-Создать динамический массив\n"
			<< "2-Добавить элемент в массив\n"
			<< "3-Удалить элемент из массива\n"
			<< "4-Вставить элемент\n"
			<< "5-Отсортировать массив\n"
			<< "6-Линейный поиск элемента\n"
			<< "7-Бинарный поиск элемента\n"
			<< "0-Выход\n";
		cin >> number;
		switch (number)
		{
		case(ArrayGet): //Создание массива
			system("cls");
			bool key = true;
			do
			{
				int len;
				cout << "Введите количество элементов: ";
				cin >> len;
				set->length = 0;
				cout << "1- Заполнить массив случайными числами\n"
					<< "2- Заполнить массив вручную\n";
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
						cout << "\tВыбран не правильный пункт в меню!\n";
						break;
				}
		}
			while (key = true);
			ArrayShow(set);
			isArrayCreated = true;
			break;
		case(addElement): // Добавление элемента
			if (isArrayCreated == false)
			{
				cout << "Массив не создан! Создайте массив. (Пункт меню 1)";
				break;
			}
			int index;
			key = true;
			system("cls");
			ArrayShow(set);
			do
			{
				int value;
				cout << "Введите новый элемент: ";
				cin >> value;
				cout << "\n1-Добавить элемент в начало\n"
					<< "2-Добавить элемент после определённого элемента\n"
					<< "3-Добавить элемент в конец\n";
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
					cout << "Введите номер элемента, после которого нужно вставить введенный элемент : ";
					cin >> index;
					if (index < 0 || index > set->length)
					{
						cout << "\nОшибка добавления\n" << endl;
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
					cout << "Неправильный пункт меню\n";
					break;
				}
			} while (key = true);
			cout << "Изменённый массив:\n";
			ArrayShow(set);
			break;
		case(deleteElement): //Удаление элемента
			system("cls");
			if (isArrayCreated == false)
			{
				cout << "\t Создайте массив\n";
				break;
			}
			ArrayShow(set);
			cout << "Укажите номер элемента массива, который необходимо удалить : ";
			cin >> index;
			if (index < 0 || index > set->length)
			{
				cout << "\nОшибка удаления\n" << endl;
			}
			else
				DeleteElement(set, index);

			cout << "Изменённый массив: \n";

			ArrayShow(set);
			break;

		case(pushElement): //Вставка элемента
			system("cls");
			if (isArrayCreated == false)
			{
				cout << "\t Создайте массив\n";
				break;
			}
			ArrayShow(set);
			key = true;
			int value;
			do
			{
				cout << "1-Вставка элемента в начало\n"
					<< "2-Вставка элемента после определённого элемента\n"
					<< "3-Вставка элемента в конец";
				int choose = _getch();
				switch (choose)
				{
				case(1):
					key = false;
					cout << "\nВведите новый элемент : ";
					cin >> value;
					index = 0;
					GetElement(set, value, index);
					cout << "\nИзменённый массив:\n";
					ArrayShow(set);
					break;
				case(2):
					key = false;
					cout << "\nВведите новый элемент : ";
					cin >> value;
					cout << "\nВведите номер элемента, после которого нужно вставить введенный элемент : ";
					cin >> index;
					if (index < 0 || index > set->length)
					{
						cout << "\nОшибка вставки\n";
					}
					else
						GetElement(set, value, index);
					cout << "Изменённый массив:\n";
					ArrayShow(set);
					break;
				case(3):
					key = false;
					cout << "\nВведите новый элемент : ";
					cin >> value;
					index = set->length;
					GetElement(set, value, index);
					cout << "Изменённый массив:\n";
					ArrayShow(set);
					break;
				default:
					cout << "Ошибка. Неправильный пункт меню.\n";
					break;
				}
			} while (key = true);
		case(sort):
			if (isArrayCreated == false)
			{
				cout << "\t Создайте массив\n\n";
				break;
			}
			system("cls");
			cout << "Массив до сортировки:\n";
			ArrayShow(set);
			isArraySorted = true;
			BubbleSort(set);
			cout << "\nМассив после сортировки:\n";
			ArrayShow(set);
			break;
		case(linearySearch):
			if (isArrayCreated == false)
			{
				cout << "\t Создайте массив\n\n";
				break;
			}
			system("cls");
			cout << "Введите элемент : ";
			cin >> value;
			cout << (Search(set, value) ? "Элемент найден\n" : "Элемент не найден\n");
			ArrayShow(set);
			break;
		case(binarySearch):
			if (isArrayCreated == false)
			{
				cout << "\t Создайте массив\n\n";
				break;
			}

			if (isArraySorted == false)
			{
				cout << "\t Отсортируйте массив для работы с бинарным поиском!\n";
				break;
			}
			system("cls");
			cout << "Введите элемент : ";
			cin >> value;
			cout << (BinarySearch(set, value) ? "Элемент найден\n" : "Элемент не найден\n");
			ArrayShow(set);
			break;
		case(Quit):
			exit = false;
			break;

		default:
			cout << "Неправильный пункт меню\n";
			break;
		}
	}

}