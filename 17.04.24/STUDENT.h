#pragma once//контролирует, чтобы циклические библиотеки не подключаись по 2 раза
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using MARKS = int[5];
const int m = 35;

struct STUDENT
{
private:
	char FIO[m];
	int course, group;
	MARKS marks;
public:
	STUDENT() {}//constructor(неинициализуриющий)
	STUDENT(std::ifstream& file);
	void print();
	int compare(const STUDENT& student);
	int getter_course()
	{
		return course;
	}
	void set_FIO(char FIO[])
	{
		strcpy_s(this->FIO, m, FIO);
	}
	STUDENT& operator++()
	{
		course += 1;
		return *this;
	}
	void inc_course()
	{
		course += 1;
	}
	friend std::ostream& operator << (std::ostream& out, const STUDENT& student);
	int kind();
};
std::ostream& operator << (std::ostream& out, const STUDENT& student) {
	out << student.FIO << '\n';
	out << student.course << ' ' << student.group << '\n';
	for (int i{}; i < 5; ++i)
		out << student.marks[i] << ' ';
	out << '\n';
	out << "-------------\n";
	return out;
}
