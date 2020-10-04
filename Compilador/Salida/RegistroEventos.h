#ifndef COMPILADOR_REGISTROEVENTOS_H
#define COMPILADOR_REGISTROEVENTOS_H
#include <iostream>
#include <fstream>

using namespace std;

class RegistroEventos {
    public:
            RegistroEventos(string path);
            RegistroEventos(ofstream a);
            static void imprimir(string x);
            static void close();
    private:
            static ofstream archivo_salida;

};


#endif //COMPILADOR_REGISTROEVENTOS_H
