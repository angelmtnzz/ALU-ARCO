#include "division.h"
#include <limits>

Division::Division()
{

}
QString Division::div(DataConvert num1, DataConvert num2){

    DataConvert::Code output;

    //Obtenemos las mantisas:
    Mantisa1=num1.toBinary(num1.getPartFrac());
    Mantisa2=num2.toBinary(num2.getPartFrac());


    //Obtenemos el signo y los exponentes
    Signo1 = num1.getSigno();
    Exponente1 = num1.getExponente();
    Signo2 = num2.getSigno();
    Exponente2 = num2.getExponente();

    //Creación de las mantisas
    Mantisa1.insert(Mantisa1.begin(),1);
    Mantisa2.insert(Mantisa2.begin(),1);

    //Si exp > 254, numero no representable.
    if((Exponente2==0 && num2.getPartFrac()==0) || Exponente2>254)
        return "NaN"; // anything/0 adjustment
    else if(Exponente1>254)
        return "infinite";
    else if(Exponente1>254){
        return "NaN";
    }

    //Escalamos los numeros
    A=num1.BinaryToDecimal(num1.toBinary(num1.getPartFrac()));
    B=num2.BinaryToDecimal(num2.toBinary(num2.getPartFrac()));

    for(int i=1;i<24;i++){
        A+=(Mantisa1[i]*pow(2,-i));
        B+=(Mantisa2[i]*pow(2,-i));
    }

    if(B >= 1 && B < 1.25){
        bPrima=1;
    } else if (B >= 1.25 && B < 2){
        bPrima=0.8;
    }

    X0=multi.multiply(A,bPrima).toFloat();
    Y0=multi.multiply(B,bPrima).toFloat();

    std::vector<float> x;
    std::vector<float> y;

    x.push_back(X0);
    y.push_back(Y0);

    int okay=1;

    do{

        r=suma.Addicion(2, -y.at(y.size()-1)).toFloat();
        y.push_back(multi.multiply(y.at(y.size()-1), r).toFloat());
        x.push_back(multi.multiply(x.at(x.size()-1), r).toFloat());

        if(fabs(r+3e35)>std::numeric_limits<float>::max())
            okay=0;

    }while(okay==1 && abs(suma.Addicion(x.at(x.size()-1),-x.at(x.size()-2)).toFloat())>0.0001);

    x.at(x.size()-1) = A * 1 / B;

    DataConvert finalXNum(x.at(x.size()-1));
    std::vector<int> ieeeNumX(3);
    ieeeNumX.at(0)=finalXNum.getSigno();
    ieeeNumX.at(1)=finalXNum.getExponente();
    ieeeNumX.at(2)=finalXNum.getPartFrac();

    SignoDivision= Signo1^Signo2;

    ExpDivision = 0;

    SignoDivision=suma.Addicion(Exponente1,-Exponente2).toFloat();
    SignoDivision=suma.Addicion(ExpDivision,ieeeNumX.at(1)).toFloat();

    //Comprobacion desbordamiento (if expDiv > 254 -> expDiv = infinite)
    if(ExpDivision>254){
        if(SignoDivision==0)
            return "infinite";
        else
            return "-infinitive";
    }

    output.bitfields.Exponente=ExpDivision;
    output.bitfields.Signo=SignoDivision;
    output.bitfields.partFrac=ieeeNumX.at(2);
    return QString::number(output.Numero);

}
