#include <string>
#include <Windows.h>
#include "ARRAY.h"
/*
------------------------------*/
//	std::ofstream file;
//	file.open("data_binary.txt", std::ios::out);
//��� ��� �������� ������
//------------------------------------

int main() {
	setlocale(LC_ALL, "RU");
	STUDENT st;
	st.inc_course();
	++st;
	std::ifstream file_txt("students.txt");
	ARRAY vector(file_txt);
	vector.print();
	vector.sorting();
	vector.print();
	system("pause");
	return 0;
}
