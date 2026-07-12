#include <iostream>
#include <string>

#include "include/ui_controller.hpp"



int main() {
    int item;
    std::string filePath;

    std::cout << "1 write file, 2 read file" << std::endl;
    if (!(std::cin >> item) || item < 1 || item > 2) {
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }
    std::cout << "Please enter file name" << std::endl;
    if (!(std::cin >> filePath)) {
        std::cerr << "Invalid file path" << std::endl;
        return 1;
    }

    switch (item) {
    case 1:
        WriteControl(filePath);
        break;
    case 2:
        ReadControl(filePath);
        break;
    default:
        std::cerr << "Invalid option" << std::endl;
        return 1;
    }
}
