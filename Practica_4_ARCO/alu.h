#ifndef ALU_H
#define ALU_H

#include <iostream>
#include "Suma.h"
#include "Multiplicacion.h"
#include "division.h"
#include "dataConvert.h"
#include <QString>

class Alu
{
    public:
       Alu();
       ~Alu();

       void Operaciones(DataConvert Op1, DataConvert Op2, int Opcion);
       QString Resultado();
    private:
       QString resultado;
};

#endif // ALU_H
