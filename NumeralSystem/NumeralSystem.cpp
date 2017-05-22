// NumeralSystem.cpp: main - точка входа в программу

// файл с подключенными стандартными модлями
#include "stdafx.h"

// файл с настройками
#include "Settings.h"
using namespace std;


string DecToNewSystem(size_t number, const char *base_symbols = k_base_symbols) 
{
	size_t a_number = number;
	string result;

	do 
	{
		result = base_symbols[a_number % base] + result;
		a_number /= base;
	} 
	while (a_number != 0);

	return result;
}

string DecimalPartToNewSystem(double right)
{
	string result;
	for (int i = 0; i < precision; i++) 
	{
		right = right * base - (int)right * base;
		result = result + to_string((int)right);
		if (right == 1.0) 
		{
			break; // выходим раньше окончания цикла если перевелось полностью
		}
	}
	return result;
}

bool isEmpty(char _char)
{
	// не введено значение
	if (_char == string_end)
	{
		return true;
	}
	return false;
}

list<string> checkInputValue(char s_input[])
{
	list<string> result;

	// не введено значение
	if(isEmpty(s_input[0])) result.push_front(null_input);

	for (int i = 0; s_input[i] != string_end; i++)
	{
		// символ - знак минус или плюс и стоят на 1 месте
		bool is_sign_place_right = i == 0 && (s_input[i] == negative || s_input[i] == positive);

		if (!isdigit(s_input[i]) &&			// не цифра
			s_input[i] != delimiter_e &&	// не разделитель
			!is_sign_place_right)			// не знак
		{
			result.push_front(invalid + to_string(i + 1)); // позиция числа начинается с 1. Если нужно с 0 - убрать + 1
		}
	}

	return result;
}

bool ValidateInputValue(char s_input[])
{
	// заголовок о начале проверки
	cout << endl  << endl << p_check_the_value;

	// поиск ошибок
	list<string> errors = checkInputValue(s_input);

	// вывод ошибок или сообщения о успешной проверке
	if (errors.size() > 0)
	{
		cout << endl << endl << p_validation_fail << endl;
		for (auto c : errors)
		{
			cout << c << endl;
		}
		cout << endl;
		return false;
	}
	else
	{
		cout << p_validation_done;
		cout << endl;
		return true;
	}
}

string GetNumberInNewSystem(char s_input[])
{
	// переводим массив в число
	double number = atof(s_input);
	bool negative = false;

	// переводим отрицательное число в положительное на время преобразования
	if (number < 0)
	{
		negative = true;
		number = number *-1;
	}

	// получаем целую часть
	double main_number_part = floor(number); 

	// переводим целую часть в новую систему счисления
	string result = DecToNewSystem(main_number_part); 

	// возвращаем знак отрицательным числам
	if (negative)
	{
		result = "-" + result;
	}

	// если нужно - вычсляем дробную часть и сразу плюсуем к целой через разделитель
	if ((number - main_number_part) > difference) 
	{
		result = result + delimiter_e + DecimalPartToNewSystem(number - main_number_part);
	}

	return result;
}


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


// тесты
// перенести в файлы
