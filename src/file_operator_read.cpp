#include "../include/file_operator_read.hpp"

using namespace std;

FileOperatorRead::FileOperatorRead() = default;

FileOperatorRead::FileOperatorRead(const string &filepath) {
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

FileError FileOperatorRead::read_all(vector<string> &lines) {
    if (!file.is_open()) {
        return FileError::ReadFailed;
    }
    lines.clear();
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    if (file.bad()) {
        return FileError::ReadFailed;
    }
    return FileError::Success;
}

const std::ifstream &FileOperatorRead::get_file() const {
    return file;
}
