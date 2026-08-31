#include "../include/file_operator_read.hpp"



FileOperatorRead::FileOperatorRead() = default;

FileOperatorRead::FileOperatorRead(const std::string &filepath) {
    file.open(filepath);
}

FileOperatorRead::~FileOperatorRead() {

    //析构函数显式调用 file.close() 是冗余,为了方便理解RALL故保留该文件关闭处理
    if (file.is_open()) {
        file.close();
    }
}

bool FileOperatorRead::open_success() const {
    return file.is_open();
}

FileError FileOperatorRead::read_all(std::vector<std::string> &lines) {
    if (!file.is_open()) {
        return FileError::ReadFailed;
    }
    std::vector<std::string> tmp;
    std::string line;
    while (getline(file, line)) {
        tmp.push_back(std::move(line));
    }
    if (file.bad()) {
        return FileError::ReadFailed;
    }
    lines = std::move(tmp);
    return FileError::Success;
}

const std::ifstream &FileOperatorRead::get_file() const {
    return file;
}
