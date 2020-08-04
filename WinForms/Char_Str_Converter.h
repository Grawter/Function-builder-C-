#pragma once
#include "LibsAndNamespace.h"

void MarshalStringToConstChar(String^ s, const char*& res) {
    using namespace Runtime::InteropServices;
    res = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
}

void MarshalStringToString(String^ s, std::string& res) {
    using namespace Runtime::InteropServices;
    const char* chars =(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    res = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}