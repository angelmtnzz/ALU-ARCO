#ifndef DATACONVERT_H
#define DATACONVERT_H

#include <iostream>
#include <bitset> /* Array de bits */
#include <vector>
#include "limits.h"
#include <iostream>

class DataConvert{

    public:

        DataConvert(float num);
        ~DataConvert();

        unsigned int BinaryToDecimal(std::vector<int> binV);
        unsigned int getSigno();
        unsigned int getExponente();
        unsigned int getPartFrac();
        unsigned int getNumHexa();

        std::vector<int> change001(std::vector<int> Mantisa);
        std::vector<int> complement_2(std::vector<int> Mantisa);
        std::string getBinary32();
        std::vector<int> toBinary(int n);

        union Code {
            struct{
                unsigned int partFrac : 23;
                unsigned int Exponente : 8;
                unsigned int Signo : 1;
            }bitfields;

            float Numero;
            unsigned int NumHexa;
        };
        Code unionIEEE;

    private:

};


#endif // DATACONVERT_H
