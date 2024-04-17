#include "STUDENT.h"
STUDENT::STUDENT(std::ifstream& file)
{
	file.getline(FIO, m);
	file >> course >> group;
	for (int i{}; i < 5; ++i)
		file >> marks[i];
	file.ignore();
	if (!file.eof())
	{
		char delim_line[255];
		file.getline(delim_line, 255);
	}
}
void STUDENT::print() {
	std::cout << FIO << '\n';
	std::cout << course << ' ' << group << '\n';
	for (int i{}; i < 5; ++i)
		std::cout << marks[i] << ' ';
	std::cout << '\n';
	std::cout << "-------------\n";
}

int STUDENT::compare(const STUDENT& student)
{
	int result{ -1 };
	if (course > student.course || course == student.course && group > student.group ||
		course > student.course || course == student.course && group == student.group && strcmp(FIO, student.FIO))
		result = 1;
	else
		if (course == student.course && group == student.group && strcmp(FIO, student.FIO) == 0)
			result = 0;
	return result;
}
int STUDENT::kind()
{
	int min{ marks[0] };
	for (int i{ 1 }; i < 5; ++i)
		if (marks[i] < min)
			min = marks[i];
	return min;
}