#include "stdafx.h"
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