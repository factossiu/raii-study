#include "../include/file_operator_read.hpp"

#include <iostream>

using namespace std;

FileOperatorRead::FileOperatorRead() = default;

FileOperatorRead::FileOperatorRead(const string &filepath) {
    file.open(filepath);
}

FileOperatorRead::~FileOperatorRead() {
    if (file.is_open()) {
        file.close();
    }
}

bool FileOperatorRead::open_success() const {
    return file.is_open();
}

void FileOperatorRead::read_data() {
    if (open_success()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    } else {
        cerr << "Open failed" << endl;
    }
}

ifstream &FileOperatorRead::get_file() {
    return file;
}

void ReadControl(const string &filepath) {
    FileOperatorRead read_file_object(filepath);
    read_file_object.read_data();
}
