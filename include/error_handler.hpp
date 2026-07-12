#pragma once

#include <string>

enum class FileError {
    Success = 0,
    FileNotFound,
    PermissionDenied,
    OpenFailed,
    WriteFailed,
    ReadFailed,
    InvalidInput
};

enum class WriteMode {
    Overwrite,
    Append
};

inline std::string error_message(FileError err) {
    switch (err) {
    case FileError::Success:           return "Operation succeeded";
    case FileError::FileNotFound:      return "File not found";
    case FileError::PermissionDenied:  return "Permission denied";
    case FileError::OpenFailed:        return "Failed to open file";
    case FileError::WriteFailed:       return "Failed to write to file";
    case FileError::ReadFailed:        return "Failed to read from file";
    case FileError::InvalidInput:      return "Invalid input";
    default:                           return "Unknown error";
    }
}
