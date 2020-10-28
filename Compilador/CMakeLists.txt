cmake_minimum_required(VERSION 3.17)
project(Compilador)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc ")
set(SOURCE_FILES main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../")

add_executable(Compilador Lexical_analyzer/Lexical_analyzer.cpp Lexical_analyzer/Semantic_actions.cpp Lexical_analyzer/Semantic_actions.h main.cpp SymbolTable/Symbol_table.cpp SymbolTable/Symbol_table.h Sintactic_analyzer/Sintactic_actions.cpp Sintactic_analyzer/Sintactic_actions.h Output/Logger.cpp Output/Logger.h Lexical_analyzer/Lexical_analyzer_header.h GeneracionDeCodigoIntermedio/Terceto.cpp GeneracionDeCodigoIntermedio/Terceto.h GeneracionDeCodigoIntermedio/TercetoAbs.h GeneracionDeCodigoIntermedio/chekeosGeneracion.cpp GeneracionDeCodigoIntermedio/chekeosGeneracion.h)
#Change name of executable
set_target_properties(Compilador PROPERTIES OUTPUT_NAME Compiler_G-2)