#include "../include/file_operator_write.hpp"

#include <iostream>
#include <limits>

using namespace std;

FileOperatorWrite::FileOperatorWrite(const string &file_path, int open_mode) {
    if (open_mode == 1) {
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
    cout << "File closed" << endl;
}

bool FileOperatorWrite::open_success() const {
    return file.is_open();
}

ofstream &FileOperatorWrite::get_file() {
    return file;
}

void FileOperatorWrite::write_data() {
    string str;
    cout << "Please enter content to write:" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, str);
    file << str;
    cout << "Write complete" << endl;
}

void WriteControl(const string &filepath) {
    int open_mode;
    cout << "1 for overwrite mode, 2 for append mode" << endl;
    cin >> open_mode;
    if (open_mode > 2 || open_mode < 1) {
        cout << "Invalid input" << endl;
        return;
    }

    FileOperatorWrite write_file_object(filepath, open_mode);
    if (!write_file_object.open_success()) {
        cout << "Open failed" << endl;
    } else {
        write_file_object.write_data();
    }
}
