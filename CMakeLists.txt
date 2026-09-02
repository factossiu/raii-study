cmake_minimum_required(VERSION 3.15)

project(raii-study LANGUAGES CXX)

# 使用 C++17（向后兼容 C++11 的全部特性）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# MSVC 下强制按 UTF-8 解析源码，消除中文注释导致的 C4819 编码警告
if(MSVC)
    add_compile_options(/utf-8)
endif()

# 第三方预编译 DLL 的导入库（log_dll.dll / log_dll.lib / log_dll.h）
add_library(log_dll SHARED IMPORTED)

set_target_properties(log_dll PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/log_dll.dll"
    IMPORTED_IMPLIB   "${CMAKE_SOURCE_DIR}/log_dll.lib"
)

add_executable(main
    main.cpp
    src/file_operator_write.cpp
    src/file_operator_read.cpp
    src/ui_controller.cpp
    src/common_func.cpp
)

# 头文件搜索路径：根目录（log_dll.h）+ include/ 目录
target_include_directories(main PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(main PRIVATE log_dll)

# 构建后把 DLL 复制到可执行文件同目录，保证运行时能找到 log_dll.dll
add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/log_dll.dll"
        $<TARGET_FILE_DIR:main>
)
