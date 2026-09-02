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
    FileOperatorWrite(const FileOperatorWrite &) = delete;
    FileOperatorWrite &operator=(const FileOperatorWrite& other) = delete;
    FileOperatorWrite(FileOperatorWrite &&other) noexcept;
    FileOperatorWrite &operator=(FileOperatorWrite && other) noexcept;


    bool open_success() const noexcept;
    const std::ofstream &get_file() const;
    FileError write_data(const std::string &data);
};
