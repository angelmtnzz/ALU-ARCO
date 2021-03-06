#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(773, 255);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sumButton_released()
{
    float Real1 = ui->op1R->text().toFloat();
    float Real2 = ui->op2R->text().toFloat();
    DataConvert dataA(Real1);
    DataConvert dataB(Real2);
    //Alu alu(dataA, dataB, 0);
    Alu alu;
    alu.Operaciones(dataA, dataB, 0);

    //Campos del numeroA
    ui->op1I->setText(QString::fromStdString(dataA.getBinary32()));


    QString cadena = QString::number(dataA.getNumHexa(),16);
    while(cadena.length()<8){
        cadena="0"+cadena;
    }
    ui->op1H->setText(QString::fromStdString("0x")+cadena); //base16


    //Campos del numeroB
    ui->op2I->setText(QString::fromStdString(dataB.getBinary32()));

    cadena = QString::number(dataB.getNumHexa(),16);
    while(cadena.length()<8){
        cadena="0"+cadena;
    }
    ui->op2H->setText(QString::fromStdString("0x")+cadena);

    //Campos del resultado

    QString result = alu.Resultado();
    if(result != "infinite"){
        DataConvert resultNum(result.toFloat());
        ui->R_Result->setText(result);
        ui->IE_Result->setText(QString::fromStdString(resultNum.getBinary32()));

        cadena = QString::number(resultNum.getNumHexa(),16);
        while(cadena.length()<8){
            cadena="0"+cadena;
        }
        ui->H_Result->setText(QString::fromStdString("0x")+cadena);
      }else if(result == "infinite"){
        ui->R_Result->setText(result);
        ui->IE_Result->setText(QString::fromStdString("01111111100000000000000000000000"));
        ui->H_Result->setText(QString::fromStdString("0x7f800000"));
    }

}




void MainWindow::on_prodButton_released()
{
    float Real1 = ui->op1R->text().toFloat();
    float Real2 = ui->op2R->text().toFloat();
    DataConvert dataA(Real1);
    DataConvert dataB(Real2);
    Alu alu;
    alu.Operaciones(dataA, dataB, 1);

    //Campos del numero1
    ui->op1I->setText(QString::fromStdString(dataA.getBinary32()));

    QString cadena = QString::number(dataA.getNumHexa(),16);
    while(cadena.length()<8){
        cadena="0"+cadena;
    }
    ui->op1H->setText(QString::fromStdString("0x")+cadena); //base16

    //Campos del numero2
    ui->op2I->setText(QString::fromStdString(dataB.getBinary32()));

    cadena = QString::number(dataB.getNumHexa(),16);
    while(cadena.length()<8){
        cadena="0"+cadena;
    }
    ui->op2H->setText(QString::fromStdString("0x")+cadena);

    //Campos del resultado
    QString resultado = alu.Resultado();
    if(resultado != "infinite" && resultado != "NaN"){ //NaN para la multiplicacion
        DataConvert resultNum(resultado.toFloat());
        ui->R_Result->setText(resultado);
        ui->IE_Result->setText(QString::fromStdString(resultNum.getBinary32()));

        cadena = QString::number(resultNum.getNumHexa(),16);
        while(cadena.length()<8){
            cadena="0"+cadena;
        }
        ui->H_Result->setText(QString::fromStdString("0x")+cadena);


    }else{
        float resultUltim = Real1 * Real2;
        DataConvert resultNum(resultUltim);
        ui->R_Result->setText(resultado);
        ui->IE_Result->setText(QString::fromStdString(resultNum.getBinary32()));

        cadena = QString::number(resultNum.getNumHexa(),16);
        while(cadena.length()<8){
            cadena="0"+cadena;
        }
        ui->H_Result->setText(QString::fromStdString("0x")+cadena);
    }
}

void MainWindow::on_divButton_released()
{

    float Real1 = ui->op1R->text().toFloat();
    float Real2 = ui->op2R->text().toFloat();
    DataConvert dataA(Real1);
    DataConvert dataB(Real2);
    Alu alu;
    alu.Operaciones(dataA, dataB, 2);

    //Campos del numero1
    ui->op1I->setText(QString::fromStdString(dataA.getBinary32()));

    QString cadena = QString::number(dataA.getNumHexa(),16);
    while(cadena.length()<8){
        cadena="0"+cadena;
    }
    ui->op1H->setText(QString::fromStdString("0x")+cadena); //base16
    //Campos del numero2
    ui->op2I->setText(QString::fromStdString(dataB.getBinary32()));

    cadena = QString::number(dataB.getNumHexa(),16);
    while(cadena.length()<8){
        cadena="0"+cadena;
    }
    ui->op2H->setText(QString::fromStdString("0x")+cadena);

    //Campos del resultado
    QString resultado = alu.Resultado();
    if(resultado != "infinite" && resultado != "NaN" && resultado!="-infinitive"){ //NaN para la multiplicacion
        DataConvert resultNum(resultado.toFloat());
        ui->R_Result->setText(resultado);
        ui->IE_Result->setText(QString::fromStdString(resultNum.getBinary32()));
        cadena = QString::number(resultNum.getNumHexa(),16);
        while(cadena.length()<8){
            cadena="0"+cadena;
        }
        ui->H_Result->setText(QString::fromStdString("0x")+cadena);

    //special cases for CONSTANTS infinite, minus infinitive and NaN, always the same numbers

    }else if(resultado=="infinite"){
        ui->R_Result->setText(resultado);
        ui->IE_Result->setText(QString::fromStdString("01111111100000000000000000000000"));
        ui->H_Result->setText(QString::fromStdString("0x7f800000"));

    }else if(resultado=="NaN"){
       ui->R_Result->setText(resultado);
       ui->IE_Result->setText(QString::fromStdString("00000000000000000000000000000000"));
       ui->H_Result->setText(QString::fromStdString("0x0"));

    }else if(resultado=="-infinitive"){
        ui->R_Result->setText(resultado);
        ui->IE_Result->setText(QString::fromStdString("11111111100000000000000000000000"));
        ui->H_Result->setText(QString::fromStdString("0xff800000"));

    }

}
