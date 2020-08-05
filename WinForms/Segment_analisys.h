#pragma once

#include "Namespaces.h"
#include "Simple_mes.h"

// обработка пользовательских данных(Начало-конец интервала, шаг)
bool segment_correct(double& start_digit, double& end_digit, double& step, String^& some_start_digit, String^& some_end_digit, String^& some_step, const int number_func)
{
    if (some_start_digit != "")
    {
        for (int i = 0; i < some_start_digit->Length; i++)
        {
            if (isalpha(some_start_digit[i]))
            {
                MyMess("Некорректно указано начало интервала в функции №" + (char)number_func, "Ошибка параметров интервала");
                return true;
            }
        }
        start_digit = Convert::ToDouble(some_start_digit);
    }

    if (some_end_digit != "")
    {
        for (int i = 0; i < some_end_digit->Length; i++)
        {
            if (isalpha(some_end_digit[i]))
            {
                MyMess("Некорректно указан конец интервалав функции №" + (char)number_func, "Ошибка параметров интервала");
                return true;
            }
        }
        end_digit = Convert::ToDouble(some_end_digit);
    }

    if (some_step != "")
    {
        for (int i = 0; i < some_step->Length; i++)
        {
            if (isalpha(some_step[i]))
            {
                MyMess("Некорректно указан шаг в функции №" + (char)number_func, "Ошибка параметров интервала");
                return true;
            }
        }
        step = Convert::ToDouble(some_step);
    }

    return false; // если всё корректно введено
}