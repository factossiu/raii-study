#pragma once

#include <string>
#include "common_func.h"
#include "../include/file_operator_write.hpp"
#include "../include/file_operator_read.hpp"
#include "../include/error_handler.hpp"

void WriteControl(const std::string &filepath);
void ReadControl(const std::string &filepath);
