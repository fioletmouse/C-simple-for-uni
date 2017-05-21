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

list<string> checkInputValue(char s_input[])
{
	list<string> result;

	// �� ������� ��������
	if (s_input[0] == string_end)
	{
		result.push_front(null_input);
	}

	for (int i = 0; s_input[i] != string_end; i++)
	{
		if (!isdigit(s_input[i]))
		{
			// ���� ���� ����� ��� ���� ����� �� �� ������ �����
			bool is_sign_place_incorrect = i != 0 && (s_input[i] == negative || s_input[i] == positive);

			if (s_input[i] != delimiter_e ||		// ���� - �� �����������
				is_sign_place_incorrect == true)	// ���� ����� �� �� ������ �����
			{
				result.push_front(invalid + to_string(i + 1)); // ������� ����� ���������� � 1. ���� ����� � 0 - ������ + 1
			}
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

	// �������� ����� �����
	double main_number_part = floor(number); 

	// ��������� ����� ����� � ����� ������� ���������
	string result = DecToNewSystem(main_number_part); 

	// ���� ����� - �������� ������� ����� � ����� ������� � �����
	if ((number - main_number_part) > difference) 
	{
		result = result + delimiter_e + DecimalPartToNewSystem(number - main_number_part);
	}

	return result;
}


// D.Il'in, task number 5
int main()
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
	else
	{
		main();
	}

	system("pause");
	return 0;
}


// ������� - ������������� �����
// �����
// ������ �� ������ ��� ����� �����
