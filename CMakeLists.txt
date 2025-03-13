cmake_minimum_required(VERSION 3.16)
project(C++_InterviewFeature)

# 让 CMake 生成一个解决方案
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加子项目
add_subdirectory(${PROJECT_SOURCE_DIR}/source/constructor)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/copy_constructor)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/move_constructor)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/virtualFunction)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/constReference)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/template)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/template_argument_deduction)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/template_advanced)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/auto)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/lambda)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/log)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/oop)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/shared_ptr)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/separating_Axis_Theorem)

add_subdirectory(${PROJECT_SOURCE_DIR}/source/singleInlineAllocator)