// NumeralSystem.cpp: main - ����� ����� � ���������

// ���� � ������������� ������������ �������
#include "stdafx.h"

// ���� � �����������
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
			break; // ������� ������ ��������� ����� ���� ���������� ���������
		}
	}
	return result;
}

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
	if(isEmpty(s_input[0])) result.push_front(null_input);

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
	cout << endl  << endl << p_check_the_value;

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

string GetNumberInNewSystem(char s_input[])
{
	// ��������� ������ � �����
	double number = atof(s_input);
	bool negative = false;

	// ��������� ������������� ����� � ������������� �� ����� ��������������
	if (number < 0)
	{
		negative = true;
		number = number *-1;
	}

	// �������� ����� �����
	double main_number_part = floor(number); 

	// ��������� ����� ����� � ����� ������� ���������
	string result = DecToNewSystem(main_number_part); 

	// ���������� ���� ������������� ������
	if (negative)
	{
		result = "-" + result;
	}

	// ���� ����� - �������� ������� ����� � ����� ������� � ����� ����� �����������
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
		// ��������� �������� ����� � �������
		// ���� ��������, �� ����� ������� ����� � ������������ ������� � �������� � ������� 
		// ��������� �������� � ������� �� ����� ��� ������������ ������
		// setlocale(LC_ALL, "Russian");

		// ������ �� ���� �����
		cout << p_ask_to_enter_a_number;

		// ������ ���������� ����� � ������ ��������. ������� ��������� ��� ������ (255 ��������), ����� ���������� �� 
		// ���������� ������ - ������� ������� ������. ������� ����� ������ ������ ������� � �������� ���� ��������.
		char *temporary = new char[255];					// �� ����� ���������� ������ (� �������) ��� ������ 
		cin.getline(temporary, 255);						// ������ ������
		int new_length = strlen(temporary) + 1;
		char *input_array = new char[new_length];			// ���������� ����� ������ ��� ������ �������� ������	
		strcpy_s(input_array, new_length, temporary);		// ���������� ������ � ����� ������
		delete[] temporary;									// �������� ������ �������������

		// �������� ���������� �������� �� ������������ � ������ ������, ���� ����
		bool isValidInput = ValidateInputValue(input_array);

		if (isValidInput)
		{
			cout << p_result << GetNumberInNewSystem(input_array) << endl << endl;
		}

		// ���������� � ������
		cout << p_want_to_exit;
		char *exit_value = new char[5];					
		cin.getline(exit_value, 5);

		if (exit_value[0] == 'y' || exit_value[0] == 'Y') // ����������� �����
			end = false;
	}
	return 0;
}


// �����
// ��������� � �����
