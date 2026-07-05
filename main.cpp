#include <iostream>
#include <string>

#include "include/file_operator_write.hpp"
#include "include/file_operator_read.hpp"

using namespace std;

int main() {
    int item;
    string filePath;

    cout << "1 write file, 2 read file" << endl;
    cin >> item;
    cout << "Please enter file name" << endl;
    cin >> filePath;

    switch (item) {
    case 1:
        WriteControl(filePath);
        break;
    case 2:
        ReadControl(filePath);
        break;
    default:
        break;
    }
}
