#include "../include/ui_controller.hpp"



#include <iostream>
#include <limits>
#include <vector>



void WriteControl(const std::string &filepath) {
    int open_mode;
    std::cout << "1 for overwrite mode, 2 for append mode" << std::endl;
    if(!(std::cin >> open_mode)) {
        send_msg_to_print("Invalid input for open mode");
        return;
    }
    if (open_mode > 2 || open_mode < 1) {
        std::cerr << error_message(FileError::InvalidInput) << std::endl;
        send_msg_to_print(error_message(FileError::InvalidInput));
        return;
    }

    WriteMode write_mode = (open_mode == 1) ? WriteMode::Overwrite : WriteMode::Append;
    FileOperatorWrite writer(filepath, write_mode);
    if (!writer.open_success()) {
        std::cerr << error_message(FileError::OpenFailed) << std::endl;
        send_msg_to_print(error_message(FileError::OpenFailed));
        return;
    }

    std::string data;
    std::cout << "Please enter content to write:" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, data);

    FileError result = writer.write_data(data);
    if (result == FileError::Success) {
        std::cout << "Write complete" << std::endl;
    } else {
        std::cerr << error_message(result) << std::endl;
        send_msg_to_print(error_message(result));
    }
}

void ReadControl(const std::string &filepath) {
    FileOperatorRead reader(filepath);
    if (!reader.open_success()) {
        std::cerr << error_message(FileError::OpenFailed) << std::endl;
        send_msg_to_print(error_message(FileError::OpenFailed));
        return;
    }

    std::vector<std::string> lines;
    FileError result = reader.read_all(lines);
    if (result != FileError::Success) {
        std::cerr << error_message(result) << std::endl;
        send_msg_to_print(error_message(result));
        return;
    }

    for (const auto &line : lines) {
        std::cout << line << std::endl;
    }
}
