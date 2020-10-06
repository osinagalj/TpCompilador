cmake_minimum_required(VERSION 3.17)
project(Compilador)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc ")
set(SOURCE_FILES main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../")
add_executable(Compilador Lexico/Lexical_analyzer.cpp Lexico/Semantic_actions.cpp Lexico/Semantic_actions.h main.cpp SymbolTable/Symbol_table.cpp SymbolTable/Symbol_table.h Sintactico/Sintactic_actions.cpp Sintactico/Sintactic_actions.h Output/Logger.cpp Output/Logger.h Lexico/Lexical_analyzer_header.h)