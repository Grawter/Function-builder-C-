#pragma once

#include "Namespaces.h"
using namespace Runtime::InteropServices;

void MarshalStringToConstChar(String^ s, const char*& res) { // конвертирование из String^ в const char*
    res = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    Marshal::FreeHGlobal(IntPtr((void*)res));
}

void MarshalStringToString(String^ s, std::string& res) { // конвертирование из String^ в string*
    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    res = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}