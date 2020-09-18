#include <iostream>
#include <fstream>

using namespace std;
string esToken(string token,int Estado){

}; //chequea si es estado final y si es token retorna el tipo
int identificarCaracter(char carac){ //esta funcion te devuelve el numero de columna de la matriz de transicion de estado
    switch(carac)
    {
        case 'l':
            return 2;

        case 'f':
            return 3;

        case '.': //Punto
            return 5;

        case '+':
            return 6;

        case '*': //Multiplicacion
            return 6;

        case '-': //Signo menos
            return 7;

        case '_': //Guion bajo
            return 8;

        case '=':
            return 9;

        case '<': //Bloque de menor;
            return 10;

        case '>': //Bloque de seguridad;
            return 11;

        case '!': //Bloque de signo;
            return 12;

        case '"': //Bloque de comilla;
            return 13;

        case '/':
            return 14;

        case '%': //Bloque de porcentaje;
            return 15;

        case '(': //Bloque de apertura paréntesis;
            return 16;

        case ')': //Bloque de cerrar paréntesis;
            return 16;

        case ',': //Bloque de instrucciones 3;
            return 16;

        case ';': //Bloque de instrucciones 3;
            return 16;

        case '{': //Bloque de instrucciones 3;
            return 16;

        case '}': //Bloque de instrucciones 3;
            return 16;

        case '$': //Bloque de fin de archivo;
            return 17;

        case ' ': //Bloque de espacio en blanco;
            return 18;

            // case '  ': //Bloque de tabulación
            //  return 18;
            //C++ detecta las tabulaciones como espacios

        case '\n': //Bloque de salto de línea;
            return 18;

            //default, es el bloque que se ejecuta en caso de que no se de ningún caso
        default:
            if (carac<='z' && carac>='a'){ // es minus
                return 0;
            }
            if (carac<='Z' && carac>='A'){ //es mayus
                return 1;
            }
            if (carac>='0' && carac<='9'){ // es dig

                return 4;
            }
            return 19; //devuelvo numero de columna 'otro'
    }
}

int main(int argc, char* argv[]){
    //inicializacion de variables
    string linea;
    string token = "";
    string path2 = "C:\\programa.txt"; //relativo
    //Path lauta
    string path = "C:\\Users\\Lautaro\\Desktop\\Facultad\\Compiladores\\TPcursada\\TpCompilador\\Compilador\\Archivos\\programa.txt";
    //Path nico
    //string path= "C:\\Users\\nicol\\CLionProjects\\tpParaleloCompi\\texto.txt";
    int linea_actual = 0;
    int caracteresAvanzados = 0;
    int estadoNuevo; //indica a que estado me estoy moviendo
    string tipo="";
    ifstream origen(path.c_str());
    if (!origen.is_open())
        cout << "No se pudo abrir el archivo: " << path << endl;
    else {
        // ESTE ELSE TENDRÍA QUE SER UNA FUNCIÓN Y HACER UN WHILE MIENTRAS NO SE ENCUENTRE TOKEN, cuando se encuentra se entrega.
        while (!origen.eof()) {
            linea_actual++;
            getline(origen,linea);
            //cout<< linea1<<endl;
            for(char carac : linea){
                token=token+carac;
                caracteresAvanzados++;
                estadoNuevo=(identificarCaracter(carac));
                tipo = esToken(token,estadoNuevo);
                if (tipo != ""){ //si es token
                    devolverToken(token,tipo);//esto sería un return token nada más si lo hacemos una función
                    //acá cambiaríamos el estado de "buscar token" a "no buscar", hasta que el parser nos lo vuelva a cambiar y arranquetodo de nuevo
                }
            }
        }
        entregarToken(token,tipo); //dar token al parser
    }
    return 0;
}


