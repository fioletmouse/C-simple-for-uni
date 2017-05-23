#include "stdafx.h"
#include "Settings.h"
using namespace std;

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
	if (isEmpty(s_input[0])) result.push_front(null_input);

	for (int i = 0; s_input[i] != string_end; i++)
	{
		// символ - знак минус или плюс и сто€т на 1 месте
		bool is_sign_place_right = i == 0 && (s_input[i] == negative || s_input[i] == positive);

		if (!isdigit(s_input[i]) &&			// не цифра
			s_input[i] != delimiter_e &&	// не разделитель
			!is_sign_place_right)			// не знак
		{
			result.push_front(invalid + to_string(i + 1)); // позици€ числа начинаетс€ с 1. ≈сли нужно с 0 - убрать + 1
		}
	}

	return result;
}

bool ValidateInputValue(char s_input[])
{
	// заголовок о начале проверки
	cout << endl << endl << p_check_the_value;

	// поиск ошибок
	list<string> errors = checkInputValue(s_input);

	// вывод ошибок или сообщени€ о успешной проверке
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