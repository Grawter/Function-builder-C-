#pragma once
#include "Namespaces.h"

DialogResult MyMess(String^ text, String^ head = "Ошибка ввода функции") { // шаблон частоиспользуемого мессаджбокса

	return MessageBox::Show(text, head, MessageBoxButtons::OK, MessageBoxIcon::Error);
}