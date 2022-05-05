#include "division.h"

Division::Division()
{

}

Division::~Division(){

}

QString Division::div(DataConvert num1, DataConvert num2){

    DataConvert::Code output;

    //Obtenemos las mantisas:
    Mantisa1=num1.toBinary(num1.getPartFrac());
    Mantisa2=num2.toBinary(num2.getPartFrac());


    //Obtenemos el signo y los exponentes
    Signo1 = num1.getSigno();
    Exponente1 = num1.getExponente();
    Signo2 = num2.getSigno();
    Exponente2 = num2.getExponente();

    //Si exp > 254, numero no representable.
    if(Exponente1>254 || Exponente2>254){
        return "infinite";
    }

    //Escalamos los numeros
    A=num1.BinaryToDecimal(num1.toBinary(num1.getPartFrac()));
    B=num2.BinaryToDecimal(num2.toBinary(num2.getPartFrac()));

    //Calculamos b'
    if(B>=1 && B<1.25){
        bPrima = 1.00;
    }
    if(B>=1.25 && B<2){
        bPrima = 0.80;
    }

    //Calculamos Exp (A*1/B)
    Exp = (A*1/B);

    //Calculamos el signo de la division
    SignoDivision = Signo1 ^ Signo2;

    //Calculamos el exponente de la division
    ExpDivision = Exponente1 - Exponente2 + Exp;


    // (Esto último creo que no está bien)

    //Asignamos Xo, Yo y r
    //Xo = A * bPrima;
    //Yo = B * bPrima;
    //r = 2 - Yo;



}
