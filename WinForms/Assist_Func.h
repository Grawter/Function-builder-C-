#pragma once
#include "LibsAndNamespace.h"
#include <string>

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