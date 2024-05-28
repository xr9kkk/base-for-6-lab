#include "STUDENT.h"

STUDENT::STUDENT(std::ifstream& file) {
    file.getline(FIO, m);
    file >> group;
    for (int i = 0; i < 5; ++i)
        file >> marks[i];
    file.ignore();
    if (!file.eof()) {
        char delim_line[255];
        file.getline(delim_line, 255);
    }
}

void STUDENT::print() {
    std::cout << FIO << '\n';
    std::cout << group << '\n';
    for (int i = 0; i < 5; ++i)
        std::cout << marks[i] << ' ';
    std::cout << '\n';
    std::cout << "-------------\n";
}

int STUDENT::compare( STUDENT& student) {
    int result = -1;
    if (group > student.group || (group == student.group && strcmp(FIO, student.FIO) > 0))
        result = 1;
    else if (group == student.group && strcmp(FIO, student.FIO) == 0)
        result = 0;
    return result;
}

double STUDENT::getter_average()  {
    double sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += marks[i];
    }
    return sum / 5.0; 
}

int STUDENT::kind() {
    int min = marks[0];
    for (int i = 1; i < 5; ++i)
        if (marks[i] < min)
            min = marks[i];
    return min;
}

std::ostream& operator<<(std::ostream& out, const STUDENT& student) {
    out << student.FIO << '\n';
    out << student.group << '\n';
    for (int i = 0; i < 5; ++i)
        out << student.marks[i] << ' ';
    out << '\n';
    out << "-------------\n";
    return out;
}
