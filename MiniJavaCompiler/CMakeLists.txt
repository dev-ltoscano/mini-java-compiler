cmake_minimum_required (VERSION 3.5)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

include_directories("${PROJECT_SOURCE_DIR}/src/include")

if (UNIX)
    LINK_DIRECTORIES("${PROJECT_SOURCE_DIR}/libs/Linux/x64")
elseif(WIN32)
	LINK_DIRECTORIES("${PROJECT_SOURCE_DIR}/libs/Windows/x64")
	configure_file("${PROJECT_SOURCE_DIR}/libs/Windows/x64/antlr4-runtime.dll" "${PROJECT_SOURCE_DIR}/build/antlr4-runtime.dll" COPYONLY)
else()
	message(STATUS "Operating system not supported")
endif()

add_executable (mjavac "${PROJECT_SOURCE_DIR}/src/lexer/MiniJavaLexer.cpp"
						"${PROJECT_SOURCE_DIR}/src/parser/MiniJavaParser.cpp"
						"${PROJECT_SOURCE_DIR}/src/semantic/MiniJavaSemantic.cpp"
						"${PROJECT_SOURCE_DIR}/src/MiniJavaCompiler.cpp"
						"${PROJECT_SOURCE_DIR}/src/semantic/visitor/TransformToAST.cpp"
						"${PROJECT_SOURCE_DIR}/src/semantic/visitor/CollectInformation.cpp"
						"${PROJECT_SOURCE_DIR}/src/semantic/visitor/ExpressionChecker.cpp"
						"${PROJECT_SOURCE_DIR}/src/structure/info/ProgramInfo.cpp")

target_link_libraries(mjavac antlr4-runtime)