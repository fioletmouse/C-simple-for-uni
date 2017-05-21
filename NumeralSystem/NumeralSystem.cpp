// NumeralSystem.cpp: main - точка входа в программу

// файл с подключенными стандартными модлями
#include "stdafx.h"

// файл с настройками
#include "Settings.h"

using namespace std;


string DecToAny1(size_t number, const char *base_symbols = k_base_symbols) {

	size_t a_number = number;
	string result;
	int string_size = 0;
	do {
		result = base_symbols[a_number % base] + result;
		a_number /= base;
	} while (a_number != 0);


	return result;
}

string Mantisa(double right )
{
	string bin;
	for (int i = 0; i < 20; i++) {
		right = right * base - (int)right * base;
		bin = bin + to_string((int)right);
		if (right == 1.0) {
			break;
		}
	}
	return bin;
}

void ValidateInputValue(char s_input[])
{
	// заголовок о начале проверки
	cout << endl  << endl << p_check_the_value;

	// поиск ошибок
	list<string> errors = checkInputValue(s_input);

	// вывод ошибок или сообщения о успешной проверке
	if (errors.size() > 0)
	{
		cout << endl << p_validation_fail << endl;
		for (auto c : errors)
			cout << c << endl;
	}
	else
	{
		cout << p_validation_done;
	}
}

list<string> checkInputValue(char s_input[])
{
	list<string> result;

	for (int i = 0; s_input[i] != string_end; i++)
	{
		if (!isdigit(s_input[i]))
		{
			// если знак минус или плюс стоят не на первом месте
			bool is_sign_place_incorrect = i != 0 && (s_input[i] == negative || s_input[i] == positive);

			if (s_input[i] != delimiter_e ||		// знак - не разделитель
				is_sign_place_incorrect == true)	// знак числа не на первом месте
			{
				result.push_front(invalid + to_string(i + 1)); // позиция числа начинается с 1. Если нужно с 0 - убрать + 1
			}
		}
	}

	return result;
}

int main()
{
	// поддержка русского языка в консоли
	// если включать, то нужно вводить цифры с разделителем запятой и поменять в функции 
	// валидации проверку с запяток на точку как некорректный символ
	// setlocale(LC_ALL, "Russian");

	// Выводим данные о программе.
	cout << p_header << endl << endl;
	
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

	// проверка введенного значения на корректность и перчать ошибок, если есть
	ValidateInputValue(input_array);

	double fff =  atof(input_array);
	double ff1f = strtod(input_array, nullptr);

	//cout << DecToAny1(floor(fff)) << endl << endl;
	//cout << endl << endl << "mantisa: " << Mantisa(fff - floor(fff));
	// перевод строки
	cout << endl;
	// "Для продолжения нажмите любую клавишу". Паузу, чтобы консоль не закрывалась
	system("pause");

	/*if (getch() == 49)
		main();*/
	return 0;
}


