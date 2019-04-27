cmake_minimum_required (VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

include_directories(${PROJECT_SOURCE_DIR}/scanner ${PROJECT_SOURCE_DIR}/parser ${PROJECT_SOURCE_DIR}/semantic ${PROJECT_SOURCE_DIR}/codegen)

file(GLOB COMPILER_CPP_FILES "${PROJECT_SOURCE_DIR}/*/*.cpp")
file(GLOB COMPILER_H_FILES "${PROJECT_SOURCE_DIR}/*/*.h")

add_executable(mjavac "MiniJavaCompiler.cpp" ${COMPILER_CPP_FILES} ${COMPILER_H_FILES})