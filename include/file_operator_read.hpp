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
    FileOperatorRead(const FileOperatorRead &) = delete;
    FileOperatorRead &operator=(const FileOperatorRead &) = delete;

    FileOperatorRead(FileOperatorRead && other) noexcept;
    FileOperatorRead &operator=(FileOperatorRead && other) noexcept;


    bool open_success() const noexcept;
    FileError read_all(std::vector<std::string> &lines);
    const std::ifstream &get_file() const;


};
