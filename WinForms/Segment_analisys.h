#pragma once

#include "Simple_mes.h"
using namespace System::Windows::Forms;

// обработка пользовательских данных(Начало-конец интервала, шаг)
bool segment_correct(double& start_digit, double& end_digit, double& step, String^& some_start_digit, String^& some_end_digit, String^& some_step)
{
    start_digit = -5;
    if (some_start_digit != "")
    {
        for (int i = 0; i < some_start_digit->Length; i++)
        {
            if (isalpha(some_start_digit[i]))
            {
                MyMess("Некорректно указано начало интервала", "Ошибка параметров интервала");
                return true;
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
                MyMess("Некорректно указан конец интервала", "Ошибка параметров интервала");
                return true;
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
                MyMess("Некорректно указан шаг", "Ошибка параметров интервала");
                return true;
            }
        }
        step = Convert::ToDouble(some_step);
    }

    return false;
}