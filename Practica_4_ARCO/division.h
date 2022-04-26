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
        QString div(DataConvert numA, DataConvert numB);

    private:
        int signoA = 0;
        int expoA = 0;

        int signoB = 0;
        int expoB = 0;

        std::vector<int>MantisaA;
        std::vector<int>MantisaB;

        int Guardado = 0;
        int Redondeado = 0;
        int Sticky = 0;
        int mantisaBits = 24;

        bool op_changed = false;
        bool complemt_p = false;

        Suma suma;
        Multiplicacion multi;
};

#endif // DIVISION_H
