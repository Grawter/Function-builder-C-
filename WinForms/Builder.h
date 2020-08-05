#pragma once

#include "Namespaces.h"
#include "Function_analisys.h"
#include "Segment_analisys.h"
#include "Parser.h"
#include <algorithm>
#include <vector>

class Builder {
private:

	tokens texpr1, pexpr1; // Токен - это отдельная самостоятельная единица в выражении, например, константа, имя переменной или операция
	Variables expvars1; // Массив переменных
	Massives expmasvars1; // Массив массивов под доп нужны (функции и т.д.)

	int number_func; // номер функции
	std::string copy_func; // копия оригинальной функции в формате std::string
	double start_digit1 = -5, end_digit1 = 5, step1 = 1; // начальная точка интервала, конечная точка интервала, шаг. (Заданы по-умолчанию)

	std::string var_dig; // вариативная переменная, указывающая значение у переменной в функции
	std::vector<double> masX; // вектор значений Х
	std::vector<double> masY; // вектор значений У

	void set_dot() { // замена "," на "."  для корректной работы
		while (find(var_dig.begin(), var_dig.end(), ',') != var_dig.end()) { // пока есть место, где присутствует запятая
			std::string::iterator it1 = find(var_dig.begin(), var_dig.end(), ','); // выбрать место, где присутствует запятая
			*it1 = '.'; // заменить это место на точу
		};
	}

	void clear_str(std::string& var_dig) // очищение строки при новом расчёте значения
	{
		if (var_dig[0] == 'x')
			var_dig = "x=";
		else if (var_dig[0] == 'y')
			var_dig = "y=";
		else if (var_dig[0] == 'z')
			var_dig = "z=";
	}

public:

	Builder(String^ origin_func, const int num) { // Конструктор
		MarshalStringToString(origin_func, copy_func); // конвертирование из String^ в std::string
		number_func = num;

		switch (number_func) // выбор типа вариативной переменной
		{
		case 1:
			var_dig = "x=";
			break;
		case 2:
			var_dig = "y=";
			break;
		case 3:
			var_dig = "z=";
			break;
		}
	}

	bool test_function(String^ f) { // проверяется корректно ли введена функция
		return function_correct(f, number_func);
	}

	bool test_segment(String^& some_start_digit, String^& some_end_digit, String^& some_step) { // проверется корректно ли введены доп. условия
		return segment_correct(start_digit1, end_digit1, step1,
			some_start_digit, some_end_digit, some_step, number_func);
	}

	std::vector<std::vector<double>> result() { // вычисление указанной функции
		for (double i = start_digit1; i < end_digit1 + step1; i += step1)
		{
			masX.push_back(i); // заполнение массива значений Х
			var_dig += std::to_string(i); // установка значения вариативной переменной
			set_dot(); // замена "," на "."  для корректной работы

			ReadExpressionFromStream(copy_func, var_dig, expvars1, expmasvars1); // считываем функцию
			CreateTokensFromExpression(copy_func, texpr1); // разбиваем на токены
			CreatePostfixFromTokens(texpr1, pexpr1); // преобразовываем в постфиксную запись

			masY.push_back(ResultExpr(pexpr1, expvars1, expmasvars1)); // // заполнение массива значений У

			clear_el(expvars1, expmasvars1, texpr1, pexpr1); // очистка элементов парсера
			clear_str(var_dig); // очистка вспомогательных строк
		}

		std::vector<std::vector<double>> res{ masX,masY }; // Создание и инициализация вектора векторов со значениями Х и У
		return res;
	}
};