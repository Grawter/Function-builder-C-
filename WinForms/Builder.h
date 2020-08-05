#pragma once

#include "Namespaces.h"
#include "Function_analisys.h"
#include "Segment_analisys.h"
#include "Parser.h"
#include <algorithm>
#include <vector>

class Builder {
private:

	tokens texpr1, pexpr1; // ����� - ��� ��������� ��������������� ������� � ���������, ��������, ���������, ��� ���������� ��� ��������
	Variables expvars1; // ������ ����������
	Massives expmasvars1; // ������ �������� ��� ��� ����� (������� � �.�.)

	int number_func; // ����� �������
	std::string copy_func; // ����� ������������ ������� � ������� std::string
	double start_digit1 = -5, end_digit1 = 5, step1 = 1; // ��������� ����� ���������, �������� ����� ���������, ���. (������ ��-���������)

	std::string var_dig; // ����������� ����������, ����������� �������� � ���������� � �������
	std::vector<double> masX; // ������ �������� �
	std::vector<double> masY; // ������ �������� �

	void set_dot() { // ������ "," �� "."  ��� ���������� ������
		while (find(var_dig.begin(), var_dig.end(), ',') != var_dig.end()) { // ���� ���� �����, ��� ������������ �������
			std::string::iterator it1 = find(var_dig.begin(), var_dig.end(), ','); // ������� �����, ��� ������������ �������
			*it1 = '.'; // �������� ��� ����� �� ����
		};
	}

	void clear_str(std::string& var_dig) // �������� ������ ��� ����� ������� ��������
	{
		if (var_dig[0] == 'x')
			var_dig = "x=";
		else if (var_dig[0] == 'y')
			var_dig = "y=";
		else if (var_dig[0] == 'z')
			var_dig = "z=";
	}

public:

	Builder(String^ origin_func, const int num) { // �����������
		MarshalStringToString(origin_func, copy_func); // ��������������� �� String^ � std::string
		number_func = num;

		switch (number_func) // ����� ���� ����������� ����������
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

	bool test_function(String^ f) { // ����������� ��������� �� ������� �������
		return function_correct(f, number_func);
	}

	bool test_segment(String^& some_start_digit, String^& some_end_digit, String^& some_step) { // ���������� ��������� �� ������� ���. �������
		return segment_correct(start_digit1, end_digit1, step1,
			some_start_digit, some_end_digit, some_step, number_func);
	}

	std::vector<std::vector<double>> result() { // ���������� ��������� �������
		for (double i = start_digit1; i < end_digit1 + step1; i += step1)
		{
			masX.push_back(i); // ���������� ������� �������� �
			var_dig += std::to_string(i); // ��������� �������� ����������� ����������
			set_dot(); // ������ "," �� "."  ��� ���������� ������

			ReadExpressionFromStream(copy_func, var_dig, expvars1, expmasvars1); // ��������� �������
			CreateTokensFromExpression(copy_func, texpr1); // ��������� �� ������
			CreatePostfixFromTokens(texpr1, pexpr1); // ��������������� � ����������� ������

			masY.push_back(ResultExpr(pexpr1, expvars1, expmasvars1)); // // ���������� ������� �������� �

			clear_el(expvars1, expmasvars1, texpr1, pexpr1); // ������� ��������� �������
			clear_str(var_dig); // ������� ��������������� �����
		}

		std::vector<std::vector<double>> res{ masX,masY }; // �������� � ������������� ������� �������� �� ���������� � � �
		return res;
	}
};