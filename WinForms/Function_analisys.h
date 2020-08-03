#pragma once
#include "Simple_mes.h"

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

bool function_correct(String^ function, int f) // Корректно ли введена функция
{
    const char* trf;

    MarshalString(function, trf);

    std::vector<char> values{ 'x','y','z',
        '0','1','2','3','4','5','6','7','8','9',
        '+', '-', '*', '/', '^',
            '(', ')', '[', ']',
            ',', '.',' ' };

    int trigonometr_fun_col = 1;
    
    int l1 = 0, l2=0, r1 = 0, r2=0;
    bool arg = 0;
    ///////////////////
    if (function == "") // если функция пустая
    {
        MyMess("Функция не задана.Задайте функцию", "Ошибка в функции");
        return true;
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
        MyMess("Количество открывающихся скобок не равно количеству закрывающихся", "Ошибка в функции");
        return true;
    }  
           

    for (int i = 0; i < function->Length; i++) // проверка всех символов функции
    {
        change:
        switch (function[i])
        {
        case 's': // проверка ввода sin
            if (function[i + 1] != 'i' || function[i + 2] != 'n' || function[i+3] != '(') 
            {
                MyMess("Использован неизвестный символ в функции №" + char(f));
                return true;
            }
 
            for (int j = 3*trigonometr_fun_col+(trigonometr_fun_col - 1); j < function->Length; j++) { // проверка аргумента(ов) для функции(ий)
                if (!(find(values.begin(), values.end(), trf[j]) != values.end())) {
                    
                    if (trf[j] == 's' || trf[j] == 'c' || trf[j] == 't') {
                        trigonometr_fun_col += 1;
                        i = j;
                        goto change;
                    }
                    
                    MyMess("Использован неизвестный символ в аргументе в функции №" + char(f));
                    return true;
                 }                       
            }
           
            i = (3* trigonometr_fun_col +(trigonometr_fun_col - 1));
            continue;
            break;

        case 'c': // проверка ввода cos или cot
            if ((function[i + 1] != 'o' || function[i + 2] != 's' || function[i + 3] != '('))
            {
                if ((function[i + 1] == 'o' || function[i + 2] == 't' || function[i + 3] != '(')) // если это cot
                    goto here;

                MyMess("Использован неизвестный символ в функции №" + char(f));
                return true;
            }

        here:

            for (int j = 3 * trigonometr_fun_col + (trigonometr_fun_col - 1); j < function->Length; j++) { // проверка аргумента(ов) для функции(ий)
                if (!(find(values.begin(), values.end(), trf[j]) != values.end())) {

                    if (trf[j] == 's' || trf[j] == 'c' || trf[j] == 't') {
                        trigonometr_fun_col += 1;
                        i = j;
                        goto change;
                    }

                    MyMess("Использован неизвестный символ в аргументе в функции №" + char(f));
                    return true;
                }
            }

            i = (3 * trigonometr_fun_col + (trigonometr_fun_col - 1));
            continue;
            break;

        case 't': // проверка ввода tan
            if ((function[i + 1] != 'a' && function[i + 2] != 'n' && function[i + 3] != '('))
            {
                MyMess("Использован неизвестный символ в функции №" + char(f));
                return true;
            }

            for (int j = 3 * trigonometr_fun_col + (trigonometr_fun_col - 1); j < function->Length; j++) { // проверка аргумента(ов) для функции(ий)
                if (!(find(values.begin(), values.end(), trf[j]) != values.end())) {

                    if (trf[j] == 's' || trf[j] == 'c' || trf[j] == 't') {
                        trigonometr_fun_col += 1;
                        i = j;
                        goto change;
                    }

                    MyMess("Использован неизвестный символ в аргументе в функции №" + char(f));
                    return true;
                }
            }

            i = (3 * trigonometr_fun_col + (trigonometr_fun_col - 1));
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
            if ( !( (find(values.begin(), values.end(), trf[i]) != values.end() ) || trf[i]=='x') ) {
                MessageBox::Show("Использован неизвестный символ в функции №" + char(f), "!Ошибка в функции");
                return 1;
            }

            /*if (!isdigit(function[i]) &&
                function[i] != 'x' &&
                function[i] != '+' && function[i] != '-' && function[i] != '*' && function[i] != '/' && function[i] != '^' &&
                function[i] != '(' && function[i] != ')' && function[i] != '[' && function[i] != ']' && function[i] != ',' && function[i] != '.' && function[i] != ' ') {
                MessageBox::Show("Использован неизвестный символ в функции №" + char(f), "!Ошибка в функции");
                return 1;
            }*/
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

void clear_str(std::string& var_dig, String^& p) // очищаем строки при новом расчёте значения
{
    if (var_dig[0] == 'x')
        var_dig = "x=";
    else if (var_dig[0] == 'y')
        var_dig = "y=";
    else if (var_dig[0] == 'z')
        var_dig = "z=";
    p = "";
}