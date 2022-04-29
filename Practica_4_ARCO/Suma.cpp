#include "Suma.h"
#include "dataConvert.h"

Suma::Suma(){

}

Suma::~Suma(){

}
QString Suma::Addicion(DataConvert num1, DataConvert num2){

    int aux;
    int ExponenteSum;
    int diferencia = 0;
    int carriage=0;
    int signSum;

    std::vector<int> posicion;
    std::vector<int>v_mantisaSum;
    std::vector<int>*v_sum=new std::vector<int>(24);

    DataConvert::Code output;

    //Obtenemos las mantisas
    Mantisa1=num1.toBinary(num1.getPartFrac());
    Mantisa2=num2.toBinary(num2.getPartFrac());

    //Obtenemos el signo y los exponentes
    Signo1 = num1.getSigno();
    Exponente1 = num1.getExponente();
    Signo2 = num2.getSigno();
    Exponente2 = num2.getExponente();

    //Si exp > 254, numero no representable.
    if(Exponente1>254 || Exponente2>254){
        return "infinite";
    }
    //Suma de dos numeros opuestos = 0
    if(((Signo1!=Signo2) && (Exponente1==Exponente2) && (num1.getPartFrac()==num2.getPartFrac()))){
        return "0";
    }

    //Suma de dos ceros(0+0) = 0
    if(Exponente1==0 && Exponente2==0 && num1.getPartFrac()==0 && num2.getPartFrac()==0){
        return "0";
    }
    //Comprobacion numero de normal
    if(Exponente1==0){
        Mantisa1.insert(Mantisa1.begin(),0);
        Exponente1=1;
    } else {
        Mantisa1.insert(Mantisa1.begin(),1);
    }
    if(Exponente2==0){
        Mantisa2.insert(Mantisa2.begin(),0);
        Exponente2=1;
    } else {
        Mantisa2.insert(Mantisa2.begin(),1);
    }

    //Paso 1
    if(Exponente1 < Exponente2){

        aux = Exponente1;
        Exponente1 = Exponente2;
        Exponente2 = aux;
        aux = Signo1;
        Signo1 = Signo2;
        Signo2 = aux;
        std::vector<int> auxVec = Mantisa1;
        Mantisa1 = Mantisa2;
        Mantisa2 = auxVec;
        op_changed = true;
    }

    //Paso 2
    ExponenteSum = Exponente1;
    diferencia = Exponente1 - Exponente2;
    if(diferencia<0){
        throw "Error: d is negative";
    }

    //Paso 3
    if(Signo1 != Signo2){
        Mantisa2 = num1.complement_2(Mantisa2);
    }

    //Paso 4
    posicion=Mantisa2;

    //Paso 5
    if(diferencia==1){
        Guardado=posicion.at(posicion.size()-1);
    } else if(diferencia==2){
        Guardado=posicion.at(posicion.size()-2);
        Redondeado=posicion.at(posicion.size()-1);
    } else if(diferencia>2 && diferencia<24){
        Guardado=posicion.at(posicion.size()-diferencia);
        Redondeado=posicion.at(posicion.size()-diferencia+1);
        for(int i=posicion.size()-diferencia+2;i<(int)posicion.size();i++){
            Sticky=(Sticky | posicion.at(i));
        }
    }

    //Paso 6
    if(Signo1!=Signo2){
        for(int i=0; i<diferencia; i++){
            posicion.insert(posicion.begin(),1);
        }
        for(int i=0;i<diferencia;i++){
            posicion.pop_back();
        }

    }else{

        for(int i=0; i<diferencia; i++){
            posicion.insert(posicion.begin(),0);
            posicion.pop_back();
        }
    }

    //Paso 7
    for(int i=23; i>=0 ;i--){
        if(carriage==0){

            if(Mantisa1.at(i) & posicion.at(i)){
                carriage=1;
                v_sum->at(i)=0;

            } else {
                v_sum->at(i)=Mantisa1.at(i)+posicion.at(i);
            }

        } else {

            if(Mantisa1.at(i) & posicion.at(i)){
                carriage=1;
                v_sum->at(i)=1;
            } else if((Mantisa1.at(i) | posicion.at(i))==0){
                v_sum->at(i)=1;
                carriage=0;
            }else{
                v_sum->at(i)=0;
                carriage=1;
            }
        }
    }
    posicion=*v_sum;

    //Paso 8
    if((Signo1 != Signo2) && (posicion.at(0)==1 && carriage==0)){
        posicion = num1.complement_2(posicion);
        complemt_p=true;
    }

    //Paso 9
    if((Signo1==Signo2) && carriage==1){
        Sticky=(Guardado | Redondeado | Sticky);
        Redondeado=posicion.at(23);
        posicion.insert(posicion.begin(),carriage);
        posicion.pop_back();
        ExponenteSum+=1;
    } else {
        int k=0;
        while(posicion.at(k)!=1 && k < 23){
            k++;
        }
        if(k>1){
            Redondeado=0;
            Sticky=0;
        }
        if(k==0){
            Sticky=(Redondeado|Sticky);
            Redondeado=Guardado;
        }
        for(int i=0;i<k;i++){
            posicion.erase(posicion.begin());
            posicion.push_back(Guardado);
        }
        ExponenteSum-=k;
    }

    //Paso 10
    if((Redondeado==1 && Sticky==1)||(Redondeado==1 && Sticky==0 && posicion.at(23)==1)){

        int carriage_2, sum=0, i=posicion.size()-1;

        do{
            carriage_2=0;
            sum=posicion.at(i)+1; /* sum = posicion[i]+1 */
            if(sum>1){
                carriage_2=1;
                posicion.at(i)=0;
            }
            i--;
        }while(carriage_2!=0);
        posicion.at(i+1)=1;

        if(carriage_2==1){
            posicion.insert(posicion.begin(),carriage_2);
            posicion.pop_back();
            ExponenteSum+=1;
        }
    }

    v_mantisaSum=posicion;

    //Paso 11
    if(op_changed==false && complemt_p==true){
        signSum=Signo2;
    } else {
        signSum=Signo1;
    }

    //Paso 12
    if(ExponenteSum<1){
        ExponenteSum=1;
    }

    output.bitfields.Exponente=ExponenteSum;
    output.bitfields.Signo=signSum;
    v_mantisaSum.erase(v_mantisaSum.begin());
    output.bitfields.partFrac=num1.BinaryToDecimal(v_mantisaSum);
    return QString::number(output.Numero);

}

/* Paso 1.
* Si el exponente del num1 < exponente de num2, se intercambian
* los campos (signo exponente y mantisa) de num1 por los de num2,
* porque en el siguiente paso queremos sacar diferencia que es la resta
* de Exponente1 (del exponente del primero) - Exponente2 (exponente del segundo)
* y no nos puede dar un  numero negativo
*
* Paso 2
* Guardamos en "exponenteSum" el exponente del primer numero (Exponente1),
* que es el mayor exponente porque lo garantizamos en el
* paso anterior.
* Guardamos en diferencia, la diferencia entre Exponente1 - Exponente2
*
* Paso 3
* Si el Signo1 != Signo2, transformamos la mantisa 2 a complemento
* a 2
*
* Paso 4
* Guardamos en el vector posicion, la mantisa de 2.

* Paso 5
* Calculamos el bit de guardado, el bit de redondeo y el bit
* sticky, requeridos por el algoridmo para poder hacer los
* calculos correctamente.
*
* Tenemos varios casos:
*
* Caso 1:
* distacia=1 -> Guardado=posicion[distancia-1] -> Guardado=posicion[0]
* En este caso, el bit de redondeo y sticky no existen por
* lo que les dejaremos con su valor inicial, cero(0).
*
* Caso 2:
* distancia=2 -> Guardado=posicion[distancia-1] -> guardado=posicion[1] y Redondeo=posicion[distancia-2] -> Redondeo=posicion[0]
* En este caso, solo el bit sticky no existe, porque distancia-3=-1,
* este caso no se puede dar, porque posicion[-1] no existe, por lo
* que el sticky conserva su valor inicial, 0.
*
* Caso 3:
* distancia=3 -> Guardado=posicion[distancia-1] -> Guardado=posicion[2], Redondeo=posicion[distancia-2] -> Redondeo=posicion[1] y Stinky=posicion[distancia-3] -> Stinky=posicion[0]
* En este caso, si distancia >= 3, vamos a tener los tres bits Guardado,
* Redondeo y Stinky
*
* Para calcular el sticky cogemos el bit en la posicion posicion[distancia-3] y
* hacemos un for recorriendo el vector desde la posicion posicion[distancia-3],
* hasta posicion[0] si hay algun uno por el camino, Sticky
* va a valer 1, sino, vale 0
*
* Paso 6
* Si Signo1 != Signo2, desplazamos posicion a la derecha distancia tantos bits introduciendo
* unos por izquierda del vector.
* Si no, desplazamos posicion a la derecha introducionedo ceros por la izquierda
*
* Paso 7
* Calculamos la mantisa y la almacenamos en el vector posicion.
* Para calcular el valor de la mantisa, tenemos que sumar la mantisa1
* mas posicion, que es la mantisa de 2 modificada en el paso 6, desplazando
* bits a la derecha introduciendo ceros o unos por la izquierda
*
* Paso 8
* Si Signo1 != Signo2 y posicion[n-1]=1 y carriage=0, entonces hacemos
* el complemento_2 a posicion, para aplicarselo.
* Tambien asignamos complementada_P(complemt_p) a true
*
* Paso 9
* Si el signo de 1 y de 2 son iguales y hay acarreo, entonces
*
* Reasignamos Redondeo y Sticky:
* sticky = OR(guardado, redondeo, sticky) = (guardado | Redondeo | Sticky)
* Redondeo = posicion[23] (el bit menos significativo, primer bit a la derecha)
*
* Desplazamos un bit a la derecha el vector posicion, introduciendo al
* principio del mismo el acarreo=1 y borramos el bit menos
* significativo de posicion, el primero a la derecha, con:
* "posicion.pop_back();"
*
* Ajustamos el exponente de la suma sumandole 1
*
* Sino:
* Calculamos los 'k' bits necesarios para desplazar el vector
* posicion para obtener una mantisa normalizada (24 bits y posicion[23] = 1)
* Para ello en un bucle while, recorro el vector de izquierda a
* derecha hasta encontrar un cero o llegar al limite de este
* (23 bits) y se guarda el numero de bits recorridos en "k".
*
* Si k=0:
* Sticky = resultado de hacer un or entre Redondeo y Sticky
* (dara un cero si los dos son cero y 1 en caso contrario)
* Redondeo = Guardado
*
* Si k=1:
* Redondeo = 0
* Sticky = 0
* Desplazo posicion a la izquierda 'k' bits, para ello borro los
* k bits por la izquierda y relleno por la derecha con el
* valor de Guardado
*
* Ajustamos el exponente de la suma restandole el valor de 'k'
*
* Paso 10
* Redondear el vector posicion:
* Si Redondeo=1 y Sticky=1, o Redondeo=1, Sticky=0 y posicion[0]=posicion[23]=1:
*
* Creamos una segunda variable para el acarreo (carriage_2)
* posicion=posicion+1 -> sumamos uno al vector posicion, para ello utilizaremos un bucle
* do while, para tratar de hacer el proceso mas optimo.
* En el bucle inicializamos el acarreo(carriage_2) a cero con cada
* iteracion, guardamos en la variable "sum" el resultado de sumar
* el valor de posicion, en la posicion 'i' (0 o 1) y 1 -> sum = 1 o 2
* Si es un 2, hay acarreo, se inserta un uno en posicion en la posicion
* 'i' y se sigue el proceso DE DERECHA A IZQUIERDA, como se indica.
*
* A la salida del bucle tenemos "posicion.at(i+1)=1", para concluir con la
* suma.
*
* Si al final de la operacion el acarreo vale 1, desplazamos un bit
* a la derecha el vector posicion y almacenamos en la primera posicion
* del vector, el bit del acarreo y borramos el ultimo bit del vector,
* el primero por la derecha.
*
* Ajustamos el exponente de la suma sumandole 1: ExponenteSum = ExponenteSum+1
*
* Usamos un nuevo vector llamado "v_mantisaSum" y almacenamos en el,
* el valor del vector posicion.
*
* Paso 11
* Calculamos el signo del resultado:
* Si op_changed(operandos intercambiados) = falso y
* complemento_p(complemt_p) = true -> SignoSum = Signo2
*
* Sino, SignoSum = Signo1
*
* Paso 12
* En caso de que el exponente de la suma sea menor que 1, esto significa
* que tenemos un numero DENORMAL y le asignamos un "ExponenteSum = 1", para
* poder calcular una aproximacion de este.
*
* Creamos una estructura de tipo "Code" perteneciente a la clase
* "DataConvert", para meter el signo el exponente y la mantisa en
* sus correspondiente campos dentro de la union para formar el
* numero.
*
* Para la mantisa eliminamos el bit al principio del vector y
* la transformamos de binario a decimal para guardarla en la
* parte fraccionaria que es de tipo "unsignedint".
*
* FINALMENTE(GRACIAS A DIOS)!!!
* Retornamos el numero resultante despues de todo este churro.
*/
