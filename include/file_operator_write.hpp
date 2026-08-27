#pragma once

#include <fstream>
#include <string>
#include "error_handler.hpp"


class FileOperatorWrite {
    std::ofstream file;
public:
    FileOperatorWrite(const std::string &file_path, WriteMode open_mode);
    FileOperatorWrite();
    ~FileOperatorWrite();

    bool open_success() const;
    const std::ofstream &get_file() const;
    FileError write_data(const std::string &data);
};
