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

list<string> checkInputValue(char s_input[])
{
	list<string> result;
	//char tab2[1000];
	//strcpy_s(tab2, s_input.c_str());

	char * ring = strchr(s_input, ',');
	if (ring)
	{
		result.push_front("��� �������� ��������� � " + to_string(ring - s_input + 1) + " ��������n");
	}

	for (int i = 0; s_input[i] != '\0'; i++) {
		if (!isdigit(s_input[i])) result.push_front("not a digit");
	}


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


	char *t = new char[255];	// �� ����� ���������� ������ (� �������) ��� ������ 
	cin.getline(t, 255);		// ������ ������
	int tdf = strlen(t) + 1;
	char *s = new char[tdf]; // ���������� ����� ������ ��� ������ �������� ������	
	strcpy_s(s, tdf, t); // ���������� ������ � ����� ������
	delete[] t; // �������� ������ �������������

	// ���� � ����������� � �������� �� ����������
	cout << endl;
	cout << "Checking the value ... ";

	/*list<string> errors = checkInputValue(s);
	if (errors.size() > 0)
	{
		cout << endl << endl << "Found errors: " << endl;
		for (auto c : errors)
			cout << c << endl;
	}
	else
	{
		cout << "Done!";
	}*/

	string str(s);
	double fff =  atof(s);
	double ff1f = strtod(s, nullptr);

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


