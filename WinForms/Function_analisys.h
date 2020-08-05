#pragma once

#include "Namespaces.h"
#include "Char_Str_Converter.h"
#include "Simple_mes.h"

bool function_correct(String^ function, const int number_func) // Корректно ли введена функция
{
    std::string _function; // копия функции в формате std::string
    int l1 = 0, l2 = 0, r1 = 0, r2 = 0, trigonometr_fun_col = 1;
    std::vector<char> values{ '0','1','2','3','4','5','6','7','8','9',
        '+', '-', '*', '/', '^',
         '(', ')', '[', ']',
         ',', '.',' '
    };

    MarshalStringToString(function, _function); // конвертирование из String^ в const char*

    if (function == "") // если функция пустая
    {
        MyMess("Функция №" + char(number_func) + "не задана. Задайте функцию", "Ошибка в функции");
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
        MyMess("В функции №" + (char)number_func + "количество открывающихся скобок не равно количеству закрывающихся", "Ошибка в функции");
        return true;
    }

    for (int i = 0; i < function->Length; i++) // проверка всех символов функции
    {
    change:
        switch (function[i])
        {
        case 's': // проверка ввода sin 
            if (function[i + 1] != 'i' || function[i + 2] != 'n' || function[i + 3] != '(')
            {
                MyMess("Использован неизвестный символ в функции №" + char(number_func));
                return true;
            }

        link1:
            for (int j = 3 * trigonometr_fun_col + (trigonometr_fun_col - 1); j < function->Length; j++) { // проверка аргумента(ов) для тригонометрической(их) функции(ий)
                if (!((find(values.begin(), values.end(), _function[j]) != values.end()) || _function[j] == 'x' || _function[j] == 'y' || _function[j] == 'z'))
                {
                    if (_function[j] == 'a' || _function[j] == 's' || _function[j] == 'c' || _function[j] == 't') { // проверка на подфункцию (т.е., например,  sin(sin(x)) )
                        trigonometr_fun_col += 1;
                        i = j;
                        goto change;
                    }

                    MyMess("Использован неизвестный символ в аргументе или в самой функции №" + char(number_func));
                    return true;
                }
            }

            i = (3 * trigonometr_fun_col + (trigonometr_fun_col - 1));
            continue;
            break;

        case 'c': // проверка ввода cos или cot
            if ((function[i + 1] != 'o' || function[i + 2] != 's' || function[i + 3] != '('))
            {
                if ((function[i + 1] == 'o' || function[i + 2] == 't' || function[i + 3] != '(')) { // если это cot
                    DialogResult response = MessageBox::Show("У функции \"cot\" возможен разрыв. Это может привести к выходу графика из строя. Значения функции в точках" +
                        "всё равно будут вычислены.\n\nВы хотите продолжить?", "Риск выхода из строя графика", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
                    if (response == DialogResult::Yes)
                        goto link1;
                    else
                        return true;
                }

                MyMess("Использован неизвестный символ в функции №" + char(number_func));
                return true;
            }
            goto link1;
            break;

        case 't': // проверка ввода tan
            if ((function[i + 1] != 'a' && function[i + 2] != 'n' && function[i + 3] != '('))
            {
                MyMess("Использован неизвестный символ в функции №" + char(number_func));
                return true;
            }
            goto link1;
            break;

        case 'a':
            switch (function[i + 1])
            {
            case 's': // проверка ввода asin
                if ((function[i + 2] != 'i' && function[i + 3] != 'n' && function[i + 4] != '('))
                {
                    MyMess("Использован неизвестный символ в функции №" + char(number_func));
                    return true;
                }

            link2:
                for (int j = 4 * trigonometr_fun_col + (trigonometr_fun_col - 1); j < function->Length; j++) { // проверка аргумента(ов) для обратной(ых) тригоном. функции(ий)
                    if (!((find(values.begin(), values.end(), _function[j]) != values.end()) || _function[j] == 'x' || _function[j] == 'y' || _function[j] == 'z'))
                    {
                        if (_function[j] == 'a' || _function[j] == 's' || _function[j] == 'c' || _function[j] == 't') { // проверка на подфункцию (т.е., например, sin(sin(x)) )
                            trigonometr_fun_col += 1;
                            i = j;
                            goto change;
                        }

                        MyMess("Использован неизвестный символ в аргументе или в самой функции №" + char(number_func));
                        return true;
                    }
                }

                i = (4 * trigonometr_fun_col + (trigonometr_fun_col - 1));
                continue;
                break;

            case 'c': // проверка ввода acos
                if ((function[i + 2] != 'o' && function[i + 3] != 's' && function[i + 4] != '('))
                {
                    MyMess("Использован неизвестный символ в функции №" + char(number_func));
                    return true;
                }
                if ((function[i + 2] != 'o' || function[i + 3] != 's' || function[i + 4] != '('))
                {
                    if ((function[i + 2] == 'o' || function[i + 3] == 't' || function[i + 4] != '(')) { // если это acot
                        DialogResult response = MessageBox::Show("Функцию \"acot\" невозможно построить. График выйдет из строя, но значения функции в точках всё равно" +
                            "будут вычислены.\n\nВы хотите продолжить?", "Риск выхода из строя графика", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
                        if (response == DialogResult::Yes)
                            goto link2;
                        else
                            return true;
                    }

                    MyMess("Использован неизвестный символ в функции №" + char(number_func));
                    return true;
                }

                goto link2;
                break;

            case 't': // проверка ввода atan
                if ((function[i + 2] != 'a' && function[i + 3] != 'n' && function[i + 4] != '('))
                {
                    MyMess("Использован неизвестный символ в функции №" + char(number_func));
                    return true;
                }

                goto link2;
                break;
            }
        }

        switch (number_func)
        {
        case 1:
            if (!((find(values.begin(), values.end(), _function[i]) != values.end()) || _function[i] == 'x')) { // Проверка на посторонние символы в первой функции
                MyMess("Использован неизвестный символ в функции №" + char(number_func));
                return true;
            }
            break;

        case 2:
            if (!((find(values.begin(), values.end(), _function[i]) != values.end()) || _function[i] == 'y')) { // Проверка на посторонние символы во второй функции
                MyMess("Использован неизвестный символ в функции №" + char(number_func));
                return true;
            }
            break;

        case 3:
            if (!((find(values.begin(), values.end(), _function[i]) != values.end()) || _function[i] == 'z')) { // Проверка на посторонние символы в третьей функции 
                MyMess("Использован неизвестный символ в функции №" + char(number_func));
                return true;
            }
            break;
        }
    }
    return false; // если всё в порядке и функция прошла все указанные выше валидации
}