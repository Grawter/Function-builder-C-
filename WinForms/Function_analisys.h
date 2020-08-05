#pragma once

#include "Namespaces.h"
#include "Char_Str_Converter.h"
#include "Simple_mes.h"

bool function_correct(String^ function, const int number_func) // ��������� �� ������� �������
{
    std::string _function; // ����� ������� � ������� std::string
    int l1 = 0, l2 = 0, r1 = 0, r2 = 0, trigonometr_fun_col = 1;
    std::vector<char> values{ '0','1','2','3','4','5','6','7','8','9',
        '+', '-', '*', '/', '^',
         '(', ')', '[', ']',
         ',', '.',' '
    };

    MarshalStringToString(function, _function); // ��������������� �� String^ � const char*

    if (function == "") // ���� ������� ������
    {
        MyMess("������� �" + char(number_func) + "�� ������. ������� �������", "������ � �������");
        return true;
    }

    for (int i = 0; i < function->Length; i++) { // ������� ����������� � ����������� ������ 
        if (function[i] == '(')
            ++l1;
        else if (function[i] == '[')
            ++l2;
        else if (function[i] == ')')
            ++r1;
        else if (function[i] == ']')
            ++r2;
    }

    if (l1 != r1 || l2 != r2) { // ���� ���������� ����������� ������ �� ����� ���������� ����������� 
        MyMess("� ������� �" + (char)number_func + "���������� ������������� ������ �� ����� ���������� �������������", "������ � �������");
        return true;
    }

    for (int i = 0; i < function->Length; i++) // �������� ���� �������� �������
    {
    change:
        switch (function[i])
        {
        case 's': // �������� ����� sin 
            if (function[i + 1] != 'i' || function[i + 2] != 'n' || function[i + 3] != '(')
            {
                MyMess("����������� ����������� ������ � ������� �" + char(number_func));
                return true;
            }

        link1:
            for (int j = 3 * trigonometr_fun_col + (trigonometr_fun_col - 1); j < function->Length; j++) { // �������� ���������(��) ��� ������������������(��) �������(��)
                if (!((find(values.begin(), values.end(), _function[j]) != values.end()) || _function[j] == 'x' || _function[j] == 'y' || _function[j] == 'z'))
                {
                    if (_function[j] == 'a' || _function[j] == 's' || _function[j] == 'c' || _function[j] == 't') { // �������� �� ���������� (�.�., ��������,  sin(sin(x)) )
                        trigonometr_fun_col += 1;
                        i = j;
                        goto change;
                    }

                    MyMess("����������� ����������� ������ � ��������� ��� � ����� ������� �" + char(number_func));
                    return true;
                }
            }

            i = (3 * trigonometr_fun_col + (trigonometr_fun_col - 1));
            continue;
            break;

        case 'c': // �������� ����� cos ��� cot
            if ((function[i + 1] != 'o' || function[i + 2] != 's' || function[i + 3] != '('))
            {
                if ((function[i + 1] == 'o' || function[i + 2] == 't' || function[i + 3] != '(')) { // ���� ��� cot
                    DialogResult response = MessageBox::Show("� ������� \"cot\" �������� ������. ��� ����� �������� � ������ ������� �� �����. �������� ������� � ������" +
                        "�� ����� ����� ���������.\n\n�� ������ ����������?", "���� ������ �� ����� �������", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
                    if (response == DialogResult::Yes)
                        goto link1;
                    else
                        return true;
                }

                MyMess("����������� ����������� ������ � ������� �" + char(number_func));
                return true;
            }
            goto link1;
            break;

        case 't': // �������� ����� tan
            if ((function[i + 1] != 'a' && function[i + 2] != 'n' && function[i + 3] != '('))
            {
                MyMess("����������� ����������� ������ � ������� �" + char(number_func));
                return true;
            }
            goto link1;
            break;

        case 'a':
            switch (function[i + 1])
            {
            case 's': // �������� ����� asin
                if ((function[i + 2] != 'i' && function[i + 3] != 'n' && function[i + 4] != '('))
                {
                    MyMess("����������� ����������� ������ � ������� �" + char(number_func));
                    return true;
                }

            link2:
                for (int j = 4 * trigonometr_fun_col + (trigonometr_fun_col - 1); j < function->Length; j++) { // �������� ���������(��) ��� ��������(��) ��������. �������(��)
                    if (!((find(values.begin(), values.end(), _function[j]) != values.end()) || _function[j] == 'x' || _function[j] == 'y' || _function[j] == 'z'))
                    {
                        if (_function[j] == 'a' || _function[j] == 's' || _function[j] == 'c' || _function[j] == 't') { // �������� �� ���������� (�.�., ��������, sin(sin(x)) )
                            trigonometr_fun_col += 1;
                            i = j;
                            goto change;
                        }

                        MyMess("����������� ����������� ������ � ��������� ��� � ����� ������� �" + char(number_func));
                        return true;
                    }
                }

                i = (4 * trigonometr_fun_col + (trigonometr_fun_col - 1));
                continue;
                break;

            case 'c': // �������� ����� acos
                if ((function[i + 2] != 'o' && function[i + 3] != 's' && function[i + 4] != '('))
                {
                    MyMess("����������� ����������� ������ � ������� �" + char(number_func));
                    return true;
                }
                if ((function[i + 2] != 'o' || function[i + 3] != 's' || function[i + 4] != '('))
                {
                    if ((function[i + 2] == 'o' || function[i + 3] == 't' || function[i + 4] != '(')) { // ���� ��� acot
                        DialogResult response = MessageBox::Show("������� \"acot\" ���������� ���������. ������ ������ �� �����, �� �������� ������� � ������ �� �����" +
                            "����� ���������.\n\n�� ������ ����������?", "���� ������ �� ����� �������", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
                        if (response == DialogResult::Yes)
                            goto link2;
                        else
                            return true;
                    }

                    MyMess("����������� ����������� ������ � ������� �" + char(number_func));
                    return true;
                }

                goto link2;
                break;

            case 't': // �������� ����� atan
                if ((function[i + 2] != 'a' && function[i + 3] != 'n' && function[i + 4] != '('))
                {
                    MyMess("����������� ����������� ������ � ������� �" + char(number_func));
                    return true;
                }

                goto link2;
                break;
            }
        }

        switch (number_func)
        {
        case 1:
            if (!((find(values.begin(), values.end(), _function[i]) != values.end()) || _function[i] == 'x')) { // �������� �� ����������� ������� � ������ �������
                MyMess("����������� ����������� ������ � ������� �" + char(number_func));
                return true;
            }
            break;

        case 2:
            if (!((find(values.begin(), values.end(), _function[i]) != values.end()) || _function[i] == 'y')) { // �������� �� ����������� ������� �� ������ �������
                MyMess("����������� ����������� ������ � ������� �" + char(number_func));
                return true;
            }
            break;

        case 3:
            if (!((find(values.begin(), values.end(), _function[i]) != values.end()) || _function[i] == 'z')) { // �������� �� ����������� ������� � ������� ������� 
                MyMess("����������� ����������� ������ � ������� �" + char(number_func));
                return true;
            }
            break;
        }
    }
    return false; // ���� �� � ������� � ������� ������ ��� ��������� ���� ���������
}