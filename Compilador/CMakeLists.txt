cmake_minimum_required(VERSION 3.17)
project(Compilador)

set(CMAKE_CXX_STANDARD 14)

add_executable(Compilador Lexico/yylex.cpp Lexico/AccionesSemanticas.cpp Lexico/AccionesSemanticas.h Lexico/A.cpp Lexico/A.h main.cpp)