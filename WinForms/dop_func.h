#pragma once
#include "Easy_mes.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void MarshalString(String^ s, const char*& os) {
    using namespace Runtime::InteropServices;
    os = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
}

bool correct_function(String^ function, int f) // Корректно ли введена функция
{
    const char* trf;

    MarshalString(function, trf);

    
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
       
    std::vector<char> values{ 'x','y','z',
        '0','1','2','3','4','5','6','7','8','9',
        '+', '-', '*', '/', '^',
            '(', ')', '[', ']',
            ',', '.',' ' };

    int s_col = 1;

    for (int i = 0; i < function->Length; i++) // проверка все символов функции
    {
        change:
        switch (function[i])
        {
        case 's': // проверка ввода sin
            if (function[i + 1] != 'i' || function[i + 2] != 'n' || function[i+3] != '(') 
            {
                MessageBox::Show("Использован неизвестный символ или не указан аргумент в функции №" + char(f), "Ошибка в функции"); 
                return true;
            }
 
            for (int j = 3*s_col+(s_col-1); j < function->Length; j++) { // проверка аргумента для функции
                if (!(find(values.begin(), values.end(), trf[j]) != values.end())) {
                    
                    if (trf[j] == 's' || trf[j] == 'c' || trf[j] == 't') {
                        s_col += 1;
                        i = j;
                        goto change;
                    }
                        
                    MessageBox::Show("Использован неизвестный символ или не указан аргумент в функции №" + char(f), "Ошибка в функции");
                    return true;
                 }                       
            }
           
            i = (3*s_col+(s_col-1));
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
                MessageBox::Show("Использован неизвестный символ в функции №" + char(f), "!Ошибка в функции");
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