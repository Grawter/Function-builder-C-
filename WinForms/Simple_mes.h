#pragma once
#include "Namespaces.h"

DialogResult MyMess(String^ text, String^ head = "������ ����� �������") { // ������ ������������������ ������������

	return MessageBox::Show(text, head, MessageBoxButtons::OK, MessageBoxIcon::Error);
}