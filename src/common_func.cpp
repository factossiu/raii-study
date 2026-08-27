#include "common_func.h"


void send_msg_to_print(const std::string &message)
{
       std::string s_log = message;
       print_log_message(s_log.c_str());
}