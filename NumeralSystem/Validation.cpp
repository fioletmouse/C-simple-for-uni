#include "stdafx.h"
#include "Settings.h"
using namespace std;

bool isEmpty(char _char)
{
	// �� ������� ��������
	if (_char == string_end)
	{
		return true;
	}
	return false;
}

list<string> checkInputValue(char s_input[])
{
	list<string> result;

	// �� ������� ��������
	if (isEmpty(s_input[0])) result.push_front(null_input);

	for (int i = 0; s_input[i] != string_end; i++)
	{
		// ������ - ���� ����� ��� ���� � ����� �� 1 �����
		bool is_sign_place_right = i == 0 && (s_input[i] == negative || s_input[i] == positive);

		if (!isdigit(s_input[i]) &&			// �� �����
			s_input[i] != delimiter_e &&	// �� �����������
			!is_sign_place_right)			// �� ����
		{
			result.push_front(invalid + to_string(i + 1)); // ������� ����� ���������� � 1. ���� ����� � 0 - ������ + 1
		}
	}

	return result;
}

bool ValidateInputValue(char s_input[])
{
	// ��������� � ������ ��������
	cout << endl << endl << p_check_the_value;

	// ����� ������
	list<string> errors = checkInputValue(s_input);

	// ����� ������ ��� ��������� � �������� ��������
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