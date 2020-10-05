//
// Created by Nicolás on 04/10/2020.
//

#include "RegistroEventos.h"

RegistroEventos::RegistroEventos(){};

void RegistroEventos::agregarEvento(string path, int line, string evento) {
    archivoEvento.open(path,ofstream::out);
    if(archivoEvento.fail()){
        cout << "Error al abrir el archivo de código fuente" << endl;
        exit(1);
    }else
    {
        string mensaje = "Error en la linea: " + to_string(line) + "error: " + evento;
        archivoEvento << mensaje;
        archivoEvento.close();
    }
}