#include "../include/file_operator_write.hpp"



FileOperatorWrite::FileOperatorWrite(const std::string &file_path, WriteMode open_mode) {
    if (open_mode == WriteMode::Overwrite) {
        file.open(file_path, std::ios::out | std::ios::trunc);
    } else {
        file.open(file_path, std::ios::out | std::ios::app);
    }
}

FileOperatorWrite::FileOperatorWrite() = default;

FileOperatorWrite::~FileOperatorWrite() {

    //析构函数显式调用 file.close() 是冗余,为了方便理解RALL故保留该文件关闭处理
    if (file.is_open()) {
        file.close();
    }
}

bool FileOperatorWrite::open_success() const {
    return file.is_open();
}

const std::ofstream &FileOperatorWrite::get_file() const {
    return file;
}

FileError FileOperatorWrite::write_data(const std::string &data) {
    if (!file.is_open()) {
        return FileError::WriteFailed;
    }
    file << data;
    if (file.fail()) {
        return FileError::WriteFailed;
    }
    return FileError::Success;
}
