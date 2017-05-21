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
static const char *null_input = "There is no input value";

// флаг окончания строки
static const char string_end = '\0';

// отклонение разности для определения нужно ли вычислять дробную часть
static const float difference = 0.00000001;

// количество знаков после запятой в новой системе
static const float precision = 8;

// сообщения консоли
static const char *p_ask_to_enter_a_number = "Please Enter Dec Number: ";
static const char *p_check_the_value = "Checking the value ... ";
static const char *p_validation_fail  = "Found errors: ";
static const char *p_validation_done = "Done!";
static const char *p_result= "The result: ";