#pragma once
using namespace System;
using namespace System::Windows::Forms;

DialogResult MyMess(String^ text, String^ head="Ошибка ввода функции") {

	return MessageBox::Show(text, head, MessageBoxButtons::OK, MessageBoxIcon::Error);
}