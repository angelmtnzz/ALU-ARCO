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

        QString FloatPointMultiply(DataConvert num1, DataConvert num2);
        std::vector<int> BinaryMultiply(std::vector<int> A, std::vector<int> B);
        int sumaBit(int bit1, int bit2);

        std::vector<int> unsignedBinaryMult(std::vector<int> auxMantisa1, std::vector<int> auxMantisa2);
        std::vector<int> pushData(std::vector<int> pass);
        std::vector<int> calculaRound(int value1, int value2, std::vector<int> pV);
        std::vector<int> denormalOperands(int *,int *,int *,int *, int ,std::vector<int> vx);

    private:
        int Signo = 0;
        int Exponente = 0;

        int Redondeado = 0;
        int Sticky = 0;

        int signoProduct;
        int expoProduct;

        std::vector<int>pf;
        std::vector<int>mantisaProducto;
        std::vector<int>mantisa1;
        std::vector<int>mantisa2;
   };

#endif // MULTIPLICACION_H
