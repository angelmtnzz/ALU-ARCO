#include "dataConvert.h"


DataConvert::DataConvert(float num)
{
    unionIEEE.Numero=num;
}


unsigned int DataConvert::getSigno(){
    return unionIEEE.bitfields.Signo;
}

unsigned int DataConvert::getExponente(){
    return unionIEEE.bitfields.Exponente;
}

unsigned int DataConvert::getPartFrac(){
    return unionIEEE.bitfields.partFrac;
}

unsigned int DataConvert::getNumHexa(){
    return unionIEEE.NumHexa;
}

std::string DataConvert::getBinary32()
{
    union
    {
         float input;
         int   output;
    }data;

    data.input = unionIEEE.Numero;

    std::bitset<sizeof(float) * CHAR_BIT>   bits(data.output);

    std::string bitsString = bits.to_string<char,
    std::char_traits<char>,
    std::allocator<char> >();

    return bitsString;
}


std::vector<int> DataConvert::toBinary(int num){

    std::vector<int> binary;
    for(int i=0;i<23;i++){
        binary.push_back(0);
    }
    int i=22;
    if (num > 0) {
        while (num > 0) {
            if (num%2 == 0) {
                binary.at(i)= 0;
            } else {
                binary.at(i)= 1;
            }
            num = (int) num/2;
            i--;
        }
    }
    return binary;
}



std::vector<int> DataConvert::change001(std::vector<int> Mantisa){

    for(int i=0; i<24 ;i++){
      if(Mantisa.at(i)==0){
        Mantisa.at(i)=1;
      }else{
        Mantisa.at(i)=0;
      }
    }
    return Mantisa;
}


std::vector<int> DataConvert::complement_2(std::vector<int> Mantisa){

    int carriage=1;
    int suma=0;
    int i=Mantisa.size()-1;

    std::vector<int> mantisa = change001(Mantisa);

    do {

      carriage=0;
      suma=mantisa.at(i)+1;

      if(suma>=2){

        carriage=1;
        mantisa.at(i)=0;

      }else{

        mantisa.at(i)=1;

      }
      i--;

    }while(carriage!=0 && i>=0);

  return mantisa;
}


unsigned int DataConvert::BinaryToDecimal(std::vector<int> binV){

    unsigned int decNumber=0;

    for(int i=binV.size()-1;i>=0; i--){
        decNumber+=(binV.at(i)<<(binV.size()-i-1));
    }
    return decNumber;
}
