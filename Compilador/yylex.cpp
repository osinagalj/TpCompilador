#include <iostream>
#include <fstream>

using namespace std;
string esToken(string token); //llegué a estado final y ahora pregunto si es token, devuelve el tipo

int identificarToken(char carac){ //esta funcion te devuelve el numero de columna de la matriz de transicion de estado
    switch(carac) //donde opción es la variable a comparar
    {
        case '+': //Bloque de suma;

            return 1;
        case '*': //Bloque de multiplicación;
            return 1;
        case '-': //Bloque de guión;

            return 1;
        case '/': //Bloque de barra;

            return 1;
        case 'l': //Bloque de l;

            return 1;
        case 'f': //Bloque de f;

            return 1;
        case '"': //Bloque de comilla;

            return 1;
        case '<': //Bloque de menor;

            return 1;
        case '>': //Bloque de seguridad;

            return 1;
        case '=': //Bloque de igual;

            return 1;
        case '!': //Bloque de signo;

            return 1;
        case '%': //Bloque de porcentaje;

            return 1;
        case '_': //Bloque de guión bajo;

            return 1;
        case '$': //Bloque de fin de archivo;

            return 1;
        case ' ': //Bloque de espacio en blanco;

            return 1;
        case '\n': //Bloque de salto de línea;

            return 1;
        case '  ': //Bloque de tabulación

            return 1;
        case '(': //Bloque de apertura paréntesis;

            return 1;
        case ')': //Bloque de cerrar paréntesis;

            return 1;
        case ',': //Bloque de instrucciones 3;

            return 1;
        case ';': //Bloque de instrucciones 3;

            return 1;
        case '.': //Bloque de instrucciones 3;

            return 1;
        case '{': //Bloque de instrucciones 3;

            return 1;
        case '}': //Bloque de instrucciones 3;

            return 1;


            //Nótese que valor 1 2 y 3 son los valores que puede tomar la opción
            //la instrucción break es necesaria, para no ejecutar todos los casos.
        default: //Bloque de instrucciones por defecto;
            //default, es el bloque que se ejecuta en caso de que no se de ningún caso
            if (carac<='Z' && carac>='A'){ //es mayus
                return 1;
            }
            if (carac<='z' && carac>='a'){ // es minus
                return 1;
            }
            if (carac>='0' && carac<='9'){ // es dig

                return 1;
            }
            return 0; //devuelvo numero de columna 'otro'
    }
}


int main(){




    string path= "C:\\Users\\nicol\\CLionProjects\\tpParaleloCompi\\texto.txt";
    fstream aux(path); //contiene el archivo
    string linea1;
    int cont=0;
    string token="";
    while(!aux.eof()){ //recorremos el archivo linea por linea
        cont++;
        getline(aux,linea1);
        cout<< linea1<<endl;
        for(char carac : linea1){ //concatenamos de a 1 caracter para chequear el token
            token=token+carac;
            //mandar token a autómata que va a ir analizando
            //case of :


        }
        token="";
    }
    return 0;
}

