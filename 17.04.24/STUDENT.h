#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using MARKS = int[5];
const int m = 35;

struct STUDENT {
private:
    char FIO[m];
    int group;
    MARKS marks;
public:
    STUDENT() {}
    STUDENT(std::ifstream& file);
    void print();
    int compare(const STUDENT& student);
    int getter_group() const { return group; }
    const char* getter_FIO() const { return FIO; }
    const int* getter_marks() const { return marks; }
    int kind();
    friend std::ostream& operator<<(std::ostream& out, const STUDENT& student);
};
