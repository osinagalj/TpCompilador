#ifndef COMPILADOR_TABLADESIMBOLOS_H
#define COMPILADOR_TABLADESIMBOLOS_H

#include <iostream>
#include <map>
using namespace std;
class TablaDeSimbolos {

    public:
            TablaDeSimbolos();
            struct Registro{
                int id;
                //En un futuro agregar el tipo
            };
            void agregarSimbolo(string key, Registro registro);
            bool existeSimbolo(string key, Registro reg);
            Registro getID(string key, Registro reg);
            void imprimir();

            int serial = 0;
    private:
            map<string,Registro> tablaDeSimbolos ; // String es la clave, por ejemplo el identifcador hola
          //map<
          /*
           IDENTIFICADORES
           Constantes
           CADENAS


           */
};

#endif //COMPILADOR_TABLADESIMBOLOS_H
