//
// Created by Lautaro on 22/10/2020.
//

#ifndef COMPILADOR_TERCETO_H
#define COMPILADOR_TERCETO_H

#include <iostream>
using namespace std;

class Terceto {

    public:
        Terceto();
        Terceto(string op, string op1, string op2);

        string getOp() ;
        string getOp1() ;
        string getOp2();
        string getOp3();

        void setOp(string op);
        void setOp1(string op1);
        void setOp2(string op2);
        void setOp3(string op3);
        static void completarTerceto(int numeroTerceto);

    private:
        //int id;
        string   op;
        string   op1;       //otro tecerto [1], un string, un numero
        string   op2;      // otro tecerto, un string, un numero
        string   op3;      // lugar del registro / variable auxiliar

};


#endif //COMPILADOR_TERCETO_H
//template class Terceto<int>;

/*
 (-,1,b)
 (+,a,b)
 (-,[1],[2])
 (+,"a",[2])

 */