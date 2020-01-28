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
	cout << "\t\tДобро пожаловать!\n";
	while (exit==true)
	{
		cout << "\t\tВыберите пункт меню.\n" << endl
			<< "1-Создать динамический массив\n" << endl
			<< "2-Добавить элемент в массив\n" << endl
			<< "3-Удалить элемент из массива\n" << endl
			<< "4-Вставить элемент\n" << endl
			<< "5-Отсортировать массив\n" << endl
			<< "6-Линейный поиск элемента\n" << endl
			<< "7-Бинарный поиск элемента\n" << endl
			<< "0-Выход\n" << endl
			<< "Выбранный пункт: ";
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
				cout << "Введите количество элементов: ";
				lenght = InputValidation(lenght);
				dynArray->length = 0;
				cout << "1- Заполнить массив случайными числами\n" << endl
					<< "2- Заполнить массив вручную\n" << endl;
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
					cout << "Выбран не правильный пункт в меню!\n";
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
			cout << "Введите новый элемент: ";
			value=InputValidation(value);
			index = dynArray->length;
			PushElement(dynArray, value, index);
			cout << "Изменённый массив:\n";
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
			cout << "Укажите номер элемента массива, "
				<<"который необходимо удалить : ";
			cin >> index;
			if (index < 1 || index > dynArray->length)
			{
				cout << "\n\t\t\tОшибка удаления\n" << endl;
				break;
			}
			else
				DeleteElement(dynArray, index);

			cout << "Изменённый массив: \n";
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
				cout << "1-Вставка элемента в начало\n" << endl
					<< "2-Вставка элемента после определённого элемента\n"
					<<endl
					<< "3-Вставка элемента в конец"<<endl;
				int choose = _getch();
				switch (choose)
				{
				case('1'):
				{
					flag = false;
					cout << "\nВведите новый элемент : ";
					int value = 0;
					value = InputValidation(value);
					index = 0;
					PushElement(dynArray, value, index);
					cout << "\nИзменённый массив:\n";
					ArrayShow(dynArray);
					break;
				}
				case('2'):
				{
					flag = false;
					cout << "\nВведите новый элемент : ";
					int value = 0;
					value = InputValidation(value);
					int index;
					cout << "\nВведите номер элемента, после которого " 
						 <<"нужно вставить введенный элемент : ";
					cin >> index;
					if (index < 0 || index > dynArray->length)
					{
						cout << "\nОшибка вставки\n" << endl;
						break;
					}
					else
					{
						PushElement(dynArray, value, index);
						cout << "Изменённый массив:\n";
						ArrayShow(dynArray);
						break;
					}
				}
				case('3'):
				{
					flag = false;
					cout << "\nВведите новый элемент : ";
					int value = 0;
					value = InputValidation(value);
					index = dynArray->length;
					PushElement(dynArray, value, index);
					cout << "Изменённый массив:\n";
					ArrayShow(dynArray);
					break;
				}
				default:
					cout << "\t\t\tОшибка. Неправильный пункт меню.\n";
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
			cout << "Массив до сортировки:\n";
			ArrayShow(dynArray);
			isArraySorted = true;
			Sort(dynArray);
			cout << "\nМассив после сортировки:\n";
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
			cout << "Введите элемент : ";
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
				cout << "\t\t\tОтсортируйте массив!\n";
				break;
			}
			system("cls");
			int value=0;
			cout << "Введите элемент : ";
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
			cout << "\t\t\tНеправильный пункт меню\n" << endl;
			system("pause");
		break;
		}
	}
}

}