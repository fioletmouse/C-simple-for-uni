#pragma once

// �� ������ ��� ������ ���� �� 5, �� � ������ �������� ��� �����
static const char *k_base_symbols = "0123456789";

// ��������� ������� ��� ��������
static const short base = 6;

// ���� ����������� - ������� ��� ������� ������, ����� ��� ����������. 
// ���� �� ��� ������ ���� ������ ��� ������������ � ���������
static const char delimiter_e = '.';
static const char delimiter_r = ',';
static const char negative = '-';
static const char positive = '-';

// ����� ������ 
static const char *invalid = "The invalid character is found. Position: ";
static const char *null_input = "There is no input value";

// ���� ��������� ������
static const char string_end = '\0';

// ���������� �������� ��� ����������� ����� �� ��������� ������� �����
static const float difference = 0.00000001;

// ���������� ������ ����� ������� � ����� �������
static const float precision = 8;

// ��������� �������
static const char *p_ask_to_enter_a_number = "Please Enter Dec Number: ";
static const char *p_check_the_value = "Checking the value ... ";
static const char *p_validation_fail  = "Found errors: ";
static const char *p_validation_done = "Done!";
static const char *p_result= "The result: ";