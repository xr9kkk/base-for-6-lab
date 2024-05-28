#pragma once
#include <iostream>
#include <fstream>
#include <cstring>

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
    int compare( STUDENT& student);
    int getter_group()  { return group; }
    const char* getter_FIO()  { return FIO; }
    const int* getter_marks()  { return marks; }
    double getter_average() ; 
    int kind();
    friend std::ostream& operator<<(std::ostream& out, const STUDENT& student);
};
