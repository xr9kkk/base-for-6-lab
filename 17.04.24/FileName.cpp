#include <string>
#include <Windows.h>
#include "ARRAY.h"
/*
------------------------------*/
//	std::ofstream file;
//	file.open("data_binary.txt", std::ios::out);
//это для бинарных файлов
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
	vector.to_binary("students_bin.txt");
	std::ifstream file_bin("students_bin.txt", std::ios::binary);
	/*print_binary()*/
	/*task(file_bin);
	file_bin.close(); это на будущее*/
	system("pause");
	return 0;
}
