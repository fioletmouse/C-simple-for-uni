// NumeralSystem.cpp: main - ����� ����� � ���������

// ���� � ������������� ������������ �������
#include "stdafx.h"

// ���� � �����������
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
	// ��������� � ������ ��������
	cout << endl  << endl << p_check_the_value;

	// ����� ������
	list<string> errors = checkInputValue(s_input);

	// ����� ������ ��� ��������� � �������� ��������
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

int main()
{
	// ��������� �������� ����� � �������
	// ���� ��������, �� ����� ������� ����� � ������������ ������� � �������� � ������� 
	// ��������� �������� � ������� �� ����� ��� ������������ ������
	// setlocale(LC_ALL, "Russian");

	// ������� ������ � ���������.
	cout << p_header << endl << endl;
	
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

	// �������� ���������� �������� �� ������������ � ������� ������, ���� ����
	ValidateInputValue(input_array);

	double fff =  atof(input_array);
	double ff1f = strtod(input_array, nullptr);

	//cout << DecToAny1(floor(fff)) << endl << endl;
	//cout << endl << endl << "mantisa: " << Mantisa(fff - floor(fff));
	// ������� ������
	cout << endl;
	// "��� ����������� ������� ����� �������". �����, ����� ������� �� �����������
	system("pause");

	/*if (getch() == 49)
		main();*/
	return 0;
}


