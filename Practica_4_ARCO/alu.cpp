
#include "alu.h"

Alu::Alu(){


}

Alu::~Alu(){


}

void Alu::Operaciones(DataConvert op1, DataConvert op2, int option){

    if(option == 0){

        Suma suma;
        resultado = suma.Addicion(op1, op2);

    }else if(option == 1){

        Multiplicacion multi;
        resultado = multi.multiply(op1, op2);

    }else{

        Division divi;
        resultado = divi.div(op1, op2);
    }
}


QString Alu::Resultado(){

    return resultado;
}


