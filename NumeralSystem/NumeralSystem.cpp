// NumeralSystem.cpp: main - ����� ����� � ���������

// ���� � ������������� ������������ �������
#include "stdafx.h"

// ���� � �����������
#include "Settings.h"

// ����� � �����
#include "Convertion.h"
#include "Validation.h"

using namespace std;

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

		// ���� ������ ��� - ������������
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
