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

        QString multiply(DataConvert num1, DataConvert num2);

        std::vector<int> unsignedBinaryMult(std::vector<int> auxMantisa1, std::vector<int> auxMantisa2);
        std::vector<int> pushData(std::vector<int> pass);
        std::vector<int> calculaRound(int value1, int value2, std::vector<int> pV);
        std::vector<int> denormalOperands(int *,int *,int *,int *, int ,std::vector<int> vx);

    private:
        int Signo1 = 0;
        int Exponente1 = 0;

        int Signo2 = 0;
        int Exponente2 = 0;

        int Redondeado = 0;
        int Sticky = 0;

        int signoProduct;
        int expoProduct;

        std::vector<int>mantisa1;
        std::vector<int>mantisa2;
   };

#endif // MULTIPLICACION_H
