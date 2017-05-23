// NumeralSystem.cpp: main - точка входа в программу

// файл с подключенными стандартными модлями
#include "stdafx.h"

// файл с настройками
#include "Settings.h"

// файлы с кодом
#include "Convertion.h"
#include "Validation.h"

using namespace std;

// D.Il'in, task number 5
int main()
{
	bool end = true;
	while (end)
	{
		// поддержка русского языка в консоли
		// если включать, то нужно вводить цифры с разделителем запятой и поменять в функции 
		// валидации проверку с запяток на точку как некорректный символ
		// setlocale(LC_ALL, "Russian");

		// запрос на ввод числа
		cout << p_ask_to_enter_a_number;

		// чтения введенного числа в массив символов. Сначала считываем всю строку (255 символов), потом определяем ее 
		// физический размер - сколько реально занято. создаем новый массив нового размера и копируем туда значения.
		char *temporary = new char[255];					// на время выделяется память (с запасом) под строку 
		cin.getline(temporary, 255);						// чтение строки
		int new_length = strlen(temporary) + 1;
		char *input_array = new char[new_length];			// выделяется новая память под размер введённой строки	
		strcpy_s(input_array, new_length, temporary);		// копируется строка в новую память
		delete[] temporary;									// ненужная память освобождается

		// проверка введенного значения на корректность и печать ошибок, если есть
		bool isValidInput = ValidateInputValue(input_array);

		// если ошибок нет - конвертируем
		if (isValidInput)
		{
			cout << p_result << GetNumberInNewSystem(input_array) << endl << endl;
		}

		// Спрашиваем о выходе
		cout << p_want_to_exit;
		char *exit_value = new char[5];					
		cin.getline(exit_value, 5);

		if (exit_value[0] == 'y' || exit_value[0] == 'Y') // подтвердили выход
			end = false;
	}
	return 0;
}
