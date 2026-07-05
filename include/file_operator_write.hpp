#pragma once

#include <fstream>
#include <string>

class FileOperatorWrite {
    std::ofstream file;
public:
    FileOperatorWrite(const std::string &file_path, int open_mode);
    FileOperatorWrite();
    ~FileOperatorWrite();

    bool open_success() const;
    std::ofstream &get_file();
    void write_data();
};

void WriteControl(const std::string &filepath);
