#include "Multiplicacion.h"
#include <iostream>

Multiplicacion::Multiplicacion(){

}


Multiplicacion::~Multiplicacion(){

}

QString Multiplicacion::FloatPointMultiply(DataConvert num1, DataConvert num2){

    DataConvert::Code output;

    //OBTENEMOS SIGNO Y EXPONENTE DEL PRODUCTO
    //Signo del producto = signo 1 * signo 2
    if(num1.getSigno()==num1.getSigno())
        Signo=0;
    else
        Signo=1;
    //Exponente del producto = exp 1 + exp 2
    Exponente = (num1.getExponente()-127)+(num2.getExponente()-127)+127;

    //OBTENEMOS MANTISAS DE LOS OPERANDOS
    //Mantisa = 1 bit + p.f(23 bits)
    mantisa1=num1.toBinary(num1.getPartFrac());
    mantisa2=num2.toBinary(num2.getPartFrac());

    if(num1.getNum()==0)
        mantisa1.insert(mantisa1.begin(),0);
    else
        mantisa1.insert(mantisa1.begin(),1);

    if(num2.getNum()==0)
        mantisa2.insert(mantisa2.begin(),0);
    else
        mantisa2.insert(mantisa2.begin(),1);

    //OBTENEMOS MANTISA DEL PRODUCTO
    //1.Mantisa del producto = mantisa 1 * mantisa 2 mediante el algoritmo de multiplicacion binaria sin signo
    std::vector<int> mantisaProducto = BinaryMultiply(mantisa1, mantisa2);

    //2.Si P empieza por 0 desplazar 1 bit a la izquierda, si no, sumar 1 al exponente
    if(mantisaProducto[0]==0){
        for(int i=0; i<47; i++){
                mantisaProducto[i]=mantisaProducto[i+1];
            }
            mantisaProducto[47]=0;
    }else{
        Exponente++;
    }

    //3.Obtenemos bit de redondeo
    Redondeado=mantisaProducto[25];

    //4.Obtenemos bit Sticky
    Sticky=0;
    for(int i=26; i<48; i++){
        if(mantisaProducto[i]==1)
            Sticky=1;
    }

    //5.Redondeamos
    if((Redondeado==1 && Sticky==1) || (Redondeado==1 && Sticky==0 && mantisaProducto[0]==1)){
        //sumar 1 a la primera mitad de la mantisa
        int acarreo=0;
        for(int i=23; i>0; i--){
            if(mantisaProducto[i]==1 && acarreo==1){
                mantisaProducto[i]=1;
                acarreo=1;
            }if(mantisaProducto[i]==1 && acarreo==0){
                mantisaProducto[i]=0;
                acarreo=1;
            }if(mantisaProducto[i]==0 && acarreo==1){
                mantisaProducto[i]=0;
                acarreo=1;
            }if(mantisaProducto[i]==0 && acarreo==0){
                mantisaProducto[i]=1;
                acarreo=0;
            }
        }
    }

    //COMPROBAMOS DESBORDAMIENTOS DEL PRODUCTO
    //Desbordamiento a infinito
    if(Exponente>254){
        if(Signo==0)
            return "infinite";
        if(Signo==1)
            return "-infinite";
    }

    //Desbordamiento a 0
    if(Exponente<1){
        int t = 1-Exponente;
        if(t >= 24)
            return "0";
        else{
            //Desplazar aritméticamente t bits a la derecha
            for(int i=0; i<t; i++){
                for(int i=47; i>=1 ;i--){
                    mantisaProducto[i]=mantisaProducto[i-1];
                }
                mantisaProducto[0]=mantisaProducto[1];
            }
            //Valor denormal
            output.bitfields.Exponente=1;
            output.bitfields.Signo=Signo;
            for(int i=1; i<24; i++){
                pf.push_back(mantisaProducto[i]);
            }
            output.bitfields.partFrac=num1.BinaryToDecimal(pf);
            return QString::number(output.Numero);
        }
    }


    //Resultado
    output.bitfields.Exponente=Exponente;
    output.bitfields.Signo=Signo;
    for(int i=1; i<24; i++){
        pf.push_back(mantisaProducto[i]);
    }
    output.bitfields.partFrac=num1.BinaryToDecimal(pf);
    return QString::number(output.Numero);



}

std::vector<int> Multiplicacion::BinaryMultiply(std::vector<int> A, std::vector<int> B){

    std::vector<int> producto;
    std::vector<int> P;
    int acarreo=0;

    for(int i=0; i<24 ;i++){
        P.push_back(0);
    }

    //Realiza el algoritmo de multiplicacion binaria sin signo
    for(int n=0; n<24 ;n++){
        //1.Si A termina en 1 hacer P=P+B si no, no hacer nada
        if(A.at(23)==1){
            for(int i=23; i>=0 ;i--){
                if(P[i]==1 && B[i]==1 && acarreo==1){
                    P[i]=1;
                    acarreo=1;
                }if(P[i]==1 && B[i]==1 && acarreo==0){
                    P[i]=0;
                    acarreo=1;
                }if(P[i]==0 && B[i]==0 && acarreo==1){
                    P[i]=1;
                    acarreo=0;
                }if(P[i]==0 && B[i]==0 && acarreo==0){
                    P[i]=0;
                    acarreo=0;
                }if(P[i] != B[i] && acarreo==1){
                    P[i]=0;
                    acarreo=1;
                }if(P[i] != B[i] && acarreo==0){
                    P[i]=1;
                    acarreo=0;
                }
            }
        }
        //2.Desplazar 1 bit a la derecha
        for(int i=23; i>=1 ;i--){
            A[i]=A[i-1];
        }
        A[0]=P[23];
        for(int i=23; i>=1 ;i--){
            P[i]=P[i-1];
        }
        P[0]=0;
    }
    //Fin del algorimto


    //Resultado = P y A
    for(int i=0; i<24 ;i++){
        producto.push_back(P[i]);
    }
    for(int i=0; i<24 ;i++){
        producto.push_back(A[i]);
    }
    return producto;
}


