cmake_minimum_required (VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Release")

include_directories("${PROJECT_SOURCE_DIR}/include/antlr4")

file(GLOB_RECURSE H_FILES "${PROJECT_SOURCE_DIR}/src/*.h")
file(GLOB_RECURSE CPP_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

if (UNIX)
    LINK_DIRECTORIES("${PROJECT_SOURCE_DIR}/lib/Linux/x64")
elseif(WIN32)
	LINK_DIRECTORIES("${PROJECT_SOURCE_DIR}/lib/Windows/x64")
	configure_file("${PROJECT_SOURCE_DIR}/lib/Windows/x64/antlr4-runtime.dll" "${PROJECT_SOURCE_DIR}/build/" COPYONLY)
else()
	message(STATUS "Operating system not supported")
endif()

add_executable (mjavac ${H_FILES} ${CPP_FILES})
target_link_libraries(mjavac antlr4-runtime)