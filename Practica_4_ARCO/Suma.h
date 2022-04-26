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
        QString add(DataConvert numA, DataConvert numB);

    private:

        int signoA = 0;
        long expoA = 0;

        int signoB = 0;
        long expoB = 0;

        std::vector<int>MantisaA;
        std::vector<int>MantisaB;

        int Guardado = 0;
        int Redondeado = 0;
        int Sticky = 0;
        int MantisaBits = 24;

        bool op_changed = false;
        bool complemt_p = false;


};

#endif // SUMA_H
