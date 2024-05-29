#include <string>
#include <Windows.h>
#include "ARRAY.h"

void print_students_with_high_grades(std::ifstream& file_bin);

int main() {
    setlocale(LC_ALL, "ru");
    std::ifstream file_txt("students.txt");
    if (!file_txt.is_open()) {
        std::cout << "Unable to open students.txt" << std::endl;
        return 0;
    }

    ARRAY vector(file_txt);
    vector.print();
    vector.sorting();
    vector.print();
    vector.to_binary("students_bin.txt");

    std::ifstream file_bin("students_bin.txt", std::ios::binary);
    if (!file_bin.is_open()) {
        std::cout << "Unable to open students_bin.txt" << std::endl;
        return 0;
    }

    print_students_with_high_grades(file_bin);

    file_bin.close();
    system("pause");
    return 0;
}

void print_students_with_high_grades(std::ifstream& file_bin) {
    STUDENT student;
    const int MAX_GROUPS = 100;
    bool found = false;
    bool is_group_read = false;
    int currentGroupIndex = -1;

    while (file_bin.read((char*)(&student), sizeof(STUDENT))) {
        double average = student.getter_average();
        int groupIndex = student.getter_group() ;

        if (average >= 4.0) {
             {
                if (groupIndex != currentGroupIndex) {
                    
                    std::cout << std::endl;

                    std::cout << "Group " << (groupIndex ) << ": ";
                    currentGroupIndex = groupIndex;
                    is_group_read = false;
                }
                if (is_group_read) {
                    std::cout << ", ";
                }
                std::cout << student.getter_FIO();
                is_group_read = true;
                found = true;
            }
        }
    }

    if (found && is_group_read) {
        std::cout << std::endl;
    }
    else if (!found) {
        std::cout << "No students with an average grade >= 4.0" << std::endl;
    }
}