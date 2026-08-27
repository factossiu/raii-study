#include <iostream>
#include <string>
#include "log_dll.h"
#include "include/ui_controller.hpp"




int main() {
    int item;
 
    std::string s_filePathName;

    std::cout << "1 write file, 2 read file" << std::endl;
    if (!(std::cin >> item) || item < 1 || item > 2) {
        send_msg_to_print("Invalid option in choosing write or read");
        return 1;
    }
    std::cout << "Please enter file name" << std::endl;
    if (!(std::cin >> s_filePathName)) {
        send_msg_to_print("Invalid input for file path name");
        return 1;
    }

    switch (item) {
    case 1:
        WriteControl(s_filePathName);
        break;
    case 2:
        ReadControl(s_filePathName);
        break;
    default:
        send_msg_to_print("Invalid option in switch statement");
        return 1;
    }
}
