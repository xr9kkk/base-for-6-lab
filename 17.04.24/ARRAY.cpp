#include "ARRAY.h"

ARRAY::ARRAY(std::ifstream& file) {
    file >> size;
    file.ignore();
    arr = new ptrSTUDENT[size];
    for (size_t i = 0; i < size; ++i)
        arr[i] = new STUDENT(file);
    file.close();
}

void ARRAY::print() {
    for (size_t i = 0; i < size; ++i)
        arr[i]->print();
    /*std::cout << *arr[i];*/
}

void ARRAY::sorting() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j]->compare(*arr[j + 1]) > 0) {
                ptrSTUDENT temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool ARRAY::to_binary(const char* file_name) {
    bool result = true;
    std::ofstream file_bin(file_name, std::ios::binary);
    if (!file_bin.is_open())
        result = false;
    else {
        
        for (size_t i = 0; i < size; ++i)
            file_bin.write((char*)arr[i], sizeof(STUDENT));
        file_bin.close();
    }
    return result;
}
