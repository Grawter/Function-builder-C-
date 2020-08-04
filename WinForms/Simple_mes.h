#pragma once
#include "LibsAndNamespace.h"

DialogResult MyMess(String^ text, String^ head="Ошибка ввода функции") {

	return MessageBox::Show(text, head, MessageBoxButtons::OK, MessageBoxIcon::Error);
}