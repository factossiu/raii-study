#pragma once

#include <fstream>
#include <string>

class FileOperatorRead {
    std::ifstream file;
public:
    FileOperatorRead();
    explicit FileOperatorRead(const std::string &filepath);
    ~FileOperatorRead();

    bool open_success() const;
    void read_data();
    std::ifstream &get_file();
};

void ReadControl(const std::string &filepath);
