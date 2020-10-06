cmake_minimum_required(VERSION 3.17)
project(Compilador)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc ")
set(SOURCE_FILES main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Compilador Lexico/Lexical_analyzer.cpp Lexico/Semantic_actions.cpp Lexico/Semantic_actions.h main.cpp SymbolTable/SymbolTable.cpp SymbolTable/SymbolTable.h Sintactico/Sintactic_actions.cpp Sintactico/Sintactic_actions.h Salida/Logger.cpp Salida/Logger.h Lexico/Lexical_analyzer_header.h)