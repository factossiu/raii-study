#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "error_handler.hpp"

class FileOperatorRead {
    std::ifstream file;
public:
    FileOperatorRead();
    explicit FileOperatorRead(const std::string &filepath);
    ~FileOperatorRead();

    bool open_success() const;
    FileError read_all(std::vector<std::string> &lines);
    const std::ifstream &get_file() const;
};
