#ifndef DIVISION_H
#define DIVISION_H

#include <iostream>
#include <vector>
#include <math.h>
#include <QString>
#include "dataConvert.h"
#include "Suma.h"
#include "Multiplicacion.h"

class Division
{
    public:
        Division();
        ~Division();
        QString div(DataConvert num1, DataConvert num2);

    private:
        int Signo1 = 0;
        int Exponente1 = 0;

        int Signo2 = 0;
        int Exponente2 = 0;

        int A = 0;
        int B = 0;
        double bPrima = 0;
        int SignoDivision = 0;
        int ExpDivision = 0;
        int Exp = 0;
        int Xo = 0;
        int Yo = 0;

        int Guardado = 0;
        int Redondeado = 0;
        int Sticky = 0;
        int mantisaBits = 24;

        std::vector<int>Mantisa1;
        std::vector<int>Mantisa2;

        bool op_changed = false;
        bool complemt_p = false;

        Suma suma;
        Multiplicacion multi;
};

#endif // DIVISION_H
