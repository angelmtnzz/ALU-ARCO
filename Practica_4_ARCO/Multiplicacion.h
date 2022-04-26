#ifndef MULTIPLICACION_H
#define MULTIPLICACION_H


#include <iostream>
#include <vector>
#include <QString>
#include "dataConvert.h"

class Multiplicacion{

    public:
        Multiplicacion();
        ~Multiplicacion();
        QString multiply(DataConvert numA, DataConvert numB);
        std::vector<int> unsignedBinaryMult(std::vector<int> auxMantisaA, std::vector<int> auxMantisaB);
        std::vector<int> pushData(std::vector<int> pass);
        std::vector<int> calculaRound(int valueA, int valueB, std::vector<int> pV);
        std::vector<int> denormalOperands(int *,int *,int *,int *, int ,std::vector<int> vx);

    private:
        int signoA = 0;
        int expoA = 0;

        int signoB = 0;
        int expoB = 0;

        std::vector<int>mantisaA;
        std::vector<int>mantisaB;

        int Redondeado = 0;
        int Sticky = 0;

        int signoProduct;
        int expoProduct;

   };

#endif // MULTIPLICACION_H
