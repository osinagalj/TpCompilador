#ifndef COMPILADOR_TABLADESIMBOLOS_H
#define COMPILADOR_TABLADESIMBOLOS_H

#include <map>
using namespace std;
class TablaDeSimbolos {

    public:
            TablaDeSimbolos();
            void agregarSimbolo(int id, string testo);
            bool existeSimbolo(int id);
            int getSimbolo();

            struct registro{
                string tipo;
                int id;
            };
            int serial = 0;
    private:
            map<string,registro> tablaDeSimbolos;
};


#endif //COMPILADOR_TABLADESIMBOLOS_H
