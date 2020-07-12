#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

// обработка пользовательских данных(Начало-конец интервала, шаг)
bool user_data(double& start_digit, double& end_digit, double& step, String^& some_start_digit, String^& some_end_digit, String^& some_step)
{
    start_digit = -5;
    if (some_start_digit != "")
    {
        for (int i = 0; i < some_start_digit->Length; i++)
        {
            if (isalpha(some_start_digit[i]))
            {             
                MessageBox::Show("Некорректно указано начало интервала", "Ошибка");
                return 1;
            }
        }
        start_digit = Convert::ToDouble(some_start_digit);
    }

    end_digit = 5;
    if (some_end_digit != "")
    {
        for (int i = 0; i < some_end_digit->Length; i++)
        {
            if (isalpha(some_end_digit[i]))
            {
                MessageBox::Show("Некорректно указан конец интервала", "Ошибка");
                return 1;
            }
        }
        end_digit = Convert::ToDouble(some_end_digit);
    }

    step = 1;
    if (some_step != "")
    {
        for (int i = 0; i < some_step->Length; i++)
        {
            if (isalpha(some_step[i]))
            {
                MessageBox::Show("Некорректно указан шаг", "Ошибка");
                return 1;
            }
        }
        step = Convert::ToDouble(some_step);
    }
}

bool correct_function(String^ function, int f) // Корректно ли введена функция
{
    int l1 = 0, l2=0, r1 = 0, r2=0;
    bool arg = 0;
    if (function == "") // если функция пустая
    {
        MessageBox::Show("Функция не задана. Задайте функцию", "Ошибка в функции");
        return 1;
    }

    for (int i = 0; i < function->Length; i++) { // подсчёт открывающих и закрывающих скобок 
        if (function[i] == '(')
            ++l1;
        else if (function[i] == '[')
            ++l2;
        else if (function[i] == ')')
            ++r1;
        else if (function[i] == ']')
            ++r2;
    }

    if (l1 != r1 || l2 != r2) { // если количество открывающих скобок не равно количеству закрывающих 
        MessageBox::Show("Количество открывающихся скобок не равно количеству закрывающихся", "Ошибка в функции");
        return 1;
    }  
            
    for (int i = 0; i < function->Length; i++) // проверка все символов функции
    {
        switch (function[i])
        {
        case 's': // проверка ввода sin
            if (function[i + 1] != 'i' || function[i + 2] != 'n' || function[i+3] != '(') 
            {
                MessageBox::Show("Использован неизвестный символ или не указан аргумент в функции №" + char(f), "Ошибка в функции"); 
                return 1;
            }
 
            for (int i = 3; i < function->Length; i++) { // проверка аргумента для функции
                if (function[i] == 'x' || function[i] == 'y' || function[i] == 'z' || isdigit(function[i]))
                    arg = 1;
            }
            if (!arg){            
                MessageBox::Show("Использован неизвестный символ или не указан аргумент в функции №" + char(f), "Ошибка в функции");
                return 1;
            }

            arg = 0;
            i += 3;
            continue;
            break;

        case 'c': // проверка ввода cos
            if ((function[i + 1] != 'o' || function[i + 2] != 's' || function[i + 3] != '('))
            {
                MessageBox::Show("Использован неизвестный символ в функции №" + char(f), "Ошибка в функции");
                return 1;
            }

            for (int i = 3; i < function->Length; i++) { // проверка аргумента для функции
                if (function[i] == 'x' || function[i] == 'y' || function[i] == 'z' || isdigit(function[i]))
                    arg = 1;
            }
            if (!arg) {
                MessageBox::Show("Использован неизвестный символ или не указан аргумент в функции №" + char(f), "Ошибка в функции");
                return 1;
            }

            arg = 0;
            i += 3;
            continue;
            break;

        case 't': // проверка ввода tan
            if ((function[i + 1] != 'a' && function[i + 2] != 'n' && function[i + 3] != '('))
            {
                MessageBox::Show("Использован неизвестный символ в функции №" + char(f), "Ошибка в функции");
                return 1;
            }

            for (int i = 3; i < function->Length; i++) { // проверка аргумента для функции
                if (function[i] == 'x' || function[i] == 'y' || function[i] == 'z' || isdigit(function[i]))
                    arg = 1;
            }
            if (!arg) {
                MessageBox::Show("Использован неизвестный символ или не указан аргумент в функции №" + char(f), "Ошибка в функции");
                return 1;
            }

            arg = 0;
            i += 3;
            continue;
            break;
        case 'a': 
            switch (function[i+1])
            {
            case 's': // проверка ввода asin
                if ((function[i + 2] != 'i' && function[i + 3] != 'n' && function[i + 4] != '('))
                {
                    MessageBox::Show("Использован неизвестный символ в функции №" + char(f), "Ошибка в функции");
                    return 1;
                }
                
                for (int i = 4; i < function->Length; i++) { // проверка аргумента для функции
                    if (function[i] == 'x' || function[i] == 'y' || function[i] == 'z' || isdigit(function[i]))
                        arg = 1;
                }
                if (!arg) {
                    MessageBox::Show("Использован неизвестный символ или не указан аргумент в функции №" + char(f), "Ошибка в функции");
                    return 1;
                }

                arg = 0;
                i += 4;
                continue;
                break;

            case 'c': // проверка ввода acos
                if ((function[i + 2] != 'o' && function[i + 3] != 's' && function[i + 4] != '('))
                {
                    MessageBox::Show("Использован неизвестный символ в функции №" + char(f), "Ошибка в функции");
                    return 1;
                }

                for (int i = 4; i < function->Length; i++) { // проверка аргумента для функции
                    if (function[i] == 'x' || function[i] == 'y' || function[i] == 'z' || isdigit(function[i]))
                        arg = 1;
                }
                if (!arg) {
                    MessageBox::Show("Использован неизвестный символ или не указан аргумент в функции №" + char(f), "Ошибка в функции");
                    return 1;
                }

                arg = 0;
                i += 4;
                continue;
                break;

            case 't': // проверка ввода atan
                if ((function[i + 2] != 'a' && function[i + 3] != 'n' && function[i + 4] != '('))
                {
                    MessageBox::Show("Использован неизвестный символ в функции №" + char(f), "Ошибка в функции");
                    return 1;
                }

                for (int i = 4; i < function->Length; i++) { // проверка аргумента для функции
                    if (function[i] == 'x' || function[i] == 'y' || function[i] == 'z' || isdigit(function[i]))
                        arg = 1;
                }
                if (!arg) {
                    MessageBox::Show("Использован неизвестный символ или не указан аргумент в функции №" + char(f), "Ошибка в функции");
                    return 1;
                }

                arg = 0;
                i += 4;
                continue;
                break;
            }
        }

        switch (f)
        {
        case 1:
            if (!isdigit(function[i]) &&
                function[i] != 'x' &&
                function[i] != '+' && function[i] != '-' && function[i] != '*' && function[i] != '/' && function[i] != '^' &&
                function[i] != '(' && function[i] != ')' && function[i] != '[' && function[i] != ']' && function[i] != ',' && function[i] != '.' && function[i] != ' ') {
                MessageBox::Show("Использован неизвестный символ в функции №" + char(f), "Ошибка в функции");
                return 1;
            }
            break;
        case 2:
            if (!isdigit(function[i]) &&
                function[i] != 'y' &&
                function[i] != '+' && function[i] != '-' && function[i] != '*' && function[i] != '/' && function[i] != '^' &&
                function[i] != '(' && function[i] != ')' && function[i] != '[' && function[i] != ']' && function[i] != ',' && function[i] != '.' && function[i] != ' ') {
                MessageBox::Show("Использован неизвестный символ в функции №" + char(f), "Ошибка в функции");
                return 1;
            }
            break;
        case 3:
            if (!isdigit(function[i]) &&
                function[i] != 'z' &&
                function[i] != '+' && function[i] != '-' && function[i] != '*' && function[i] != '/' && function[i] != '^' &&
                function[i] != '(' && function[i] != ')' && function[i] != '[' && function[i] != ']' && function[i] != ',' && function[i] != '.' && function[i] != ' ') {
                MessageBox::Show("Использован неизвестный символ в функции №" + char(f), "Ошибка в функции");
                return 1;
            }
        }
    }    
    return 0;
}

void clear_str(std::string& var_dig, String^& p) // очищаем строки при новом расчёте значения (для 1-ой функции)
{
    if (var_dig[0] == 'x')
        var_dig = "x=";
    else if (var_dig[0] == 'y')
        var_dig = "y=";
    else if (var_dig[0] == 'z')
        var_dig = "z=";
    p = "";
}