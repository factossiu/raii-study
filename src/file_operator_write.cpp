#include "../include/file_operator_write.hpp"

using namespace std;

FileOperatorWrite::FileOperatorWrite(const string &file_path, WriteMode open_mode) {
    if (open_mode == WriteMode::Overwrite) {
        file.open(file_path, ios::out | ios::trunc);
    } else {
        file.open(file_path, ios::out | ios::app);
    }
}

FileOperatorWrite::FileOperatorWrite() = default;

FileOperatorWrite::~FileOperatorWrite() {
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

FileError FileOperatorWrite::write_data(const string &data) {
    if (!file.is_open()) {
        return FileError::WriteFailed;
    }
    file << data;
    if (file.fail()) {
        return FileError::WriteFailed;
    }
    return FileError::Success;
}
