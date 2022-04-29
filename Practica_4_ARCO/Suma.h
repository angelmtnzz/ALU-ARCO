#ifndef SUMA_H
#define SUMA_H

#include <iostream>
#include <vector>
#include <QString>
#include "dataConvert.h"

class Suma{

    public:

        Suma();
        ~Suma();
        QString Addicion(DataConvert num1, DataConvert num2);

    private:

        int Signo1 = 0;
        long Exponente1 = 0;

        int Signo2 = 0;
        long Exponente2 = 0;

        int Guardado = 0;
        int Redondeado = 0;
        int Sticky = 0;
        int MantisaBits = 24;

        std::vector<int>Mantisa1;
        std::vector<int>Mantisa2;

        bool op_changed = false;
        bool complemt_p = false;


};

#endif // SUMA_H
