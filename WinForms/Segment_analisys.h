#pragma once

#include "Namespaces.h"
#include "Simple_mes.h"

// ��������� ���������������� ������(������-����� ���������, ���)
bool segment_correct(double& start_digit, double& end_digit, double& step, String^& some_start_digit, String^& some_end_digit, String^& some_step, const int number_func)
{
    if (some_start_digit != "")
    {
        for (int i = 0; i < some_start_digit->Length; i++)
        {
            if (isalpha(some_start_digit[i]))
            {
                MyMess("����������� ������� ������ ��������� � ������� �" + (char)number_func, "������ ���������� ���������");
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
                MyMess("����������� ������ ����� ���������� ������� �" + (char)number_func, "������ ���������� ���������");
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
                MyMess("����������� ������ ��� � ������� �" + (char)number_func, "������ ���������� ���������");
                return true;
            }
        }
        step = Convert::ToDouble(some_step);
    }

    return false; // ���� �� ��������� �������
}