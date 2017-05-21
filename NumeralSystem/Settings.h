#pragma once

// ну вообще тут должно быть до 5, но я решила оставить все цифры
static const char *k_base_symbols = "0123456789";

// основание системы для варианта
static const short base = 6;

// знак разделитель - запятая для русской локали, точка для английской. 
// Один из них должен быть указан как некорректный в валидации
static const char delimiter_e = '.';
static const char delimiter_r = ',';
static const char negative = '-';
static const char positive = '-';

// текст ошикби 
static const char *invalid = "The invalid character is found. Position: ";

// флаг окончания строки
static const char string_end = '\0';

// сообщения консоли
static const char *p_header = "D.Il'in, task number 5";
static const char *p_ask_to_enter_a_number = "Please Enter Dec Number: ";
static const char *p_check_the_value = "Checking the value ... ";
static const char *p_validation_fail  = "Found errors: ";
static const char *p_validation_done = "Done!";
