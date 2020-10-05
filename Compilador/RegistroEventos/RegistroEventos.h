//
// Created by Nicolás on 04/10/2020.
//

#ifndef COMPILADOR_REGISTROEVENTOS_H
#define COMPILADOR_REGISTROEVENTOS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class RegistroEventos {
    public:
    RegistroEventos();
       void agregarEvento(string path,int line, string evento);
    private:
        ofstream archivoEvento;
};


#endif //COMPILADOR_REGISTROEVENTOS_H
