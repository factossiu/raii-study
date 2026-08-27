#pragma once

// 导出/导入宏定义
#ifdef LOGDLL_EXPORTS
    #define LOGDLL_API __declspec(dllexport)
#else
    #define LOGDLL_API __declspec(dllimport)
#endif

extern "C" {
    LOGDLL_API void print_log_message(const char* message);
}


class LOGDLL_API Logger {
    public:
        Logger();
        ~Logger();

        void log(const char* message);

        

};