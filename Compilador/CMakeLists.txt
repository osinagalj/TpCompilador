cmake_minimum_required(VERSION 3.17)
project(Compilador)

set(CMAKE_CXX_STANDARD 14)

add_executable(Compilador Lexico/Lexico.cpp Lexico/AccionesSemanticas.cpp Lexico/AccionesSemanticas.h main.cpp TablaDeSimbolos/TablaDeSimbolos.cpp TablaDeSimbolos/TablaDeSimbolos.h Sintactico/AccionesSintactico.cpp Sintactico/AccionesSintactico.h)