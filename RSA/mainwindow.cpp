#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <gmpxx.h>
#include "ifunc.h"
#include <string>
#include <QFile>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

}

MainWindow::~MainWindow()
{ delete ui; }

void MainWindow::on_pnqButton_clicked()
{
    this->on_textoSinCifrar_textChanged();
    ui->statusBar->showMessage("Procesando numero P ...");
    QString numeroP = ui->pValor->text();
    bool ok;
    mpz_class p = numeroP.toInt(&ok);
    mpz_class q;
    if(!ok) { QMessageBox::warning(this,"Nope","P no es un numero"); }
    else
    {
        if(numeroP.length() < 8)
        {
            if(!isPrimo(p))
            {
                mpz_class pAux = p;
                while(!isPrimo(pAux))
                { pAux++; }
                p=pAux;
                ui->pValor->setText( QString::fromStdString(p.get_str(10)));
                QMessageBox::information(this,"ayuda","El numero P se cambio al numero primo mayor mas proximo.");
            }
        }
        else
        {
            if(!isPrimo(p))
            {
                QMessageBox::warning(this,"Nope","P no es un numero primo");
                ok = false;
            }
        }
    }
    //==================================================
    if(ok)
    {
        ui->statusBar->showMessage("Procesando numero Q ...");
        QString numeroQ = ui->qValor->text();
        q = numeroQ.toInt(&ok);
        if(!ok) { QMessageBox::warning(this,"Nope","Q no es un numero","ok"); }
        else
        {
            if(numeroQ.length())
            {
                if(!isPrimo(q)||p<5)
                {
                    mpz_class qAux = q;
                    while(( qAux==p ) || (!isPrimo(qAux)))
                    { qAux++; }
                    q=qAux;
                    ui->qValor->setText( QString::fromStdString(q.get_str(10)));
                    QMessageBox::information(this,"ayuda","El numero Q se cambio al numero primo mayor mas proximo.");
                }
            }
            else
            {
                if(!isPrimo(q))
                {
                    QMessageBox::warning(this,"Nope","Q no es un numero primo");
                    ok = false;
                }
            }
        }
    }
    if(ok)
    {
        ui->statusBar->showMessage("Procesando numero n...");
        mpz_class n = p*q;
        ui->nValor->setPlainText(QString::fromStdString(n.get_str(10)));
        ui->statusBar->showMessage("Procesando numero m...");
        mpz_class m = (p-1)*(q-1);
        ui->mValor->setPlainText(QString::fromStdString(m.get_str(10)));
        ui->statusBar->showMessage("Procesando numero e...");
        mpz_class e(3);
        while(gcd(m,e)!=1)
        { e++; }
        ui->eValor->setPlainText(QString::fromStdString(e.get_str(10)));
        ui->statusBar->showMessage("Procesando numero d...");
        mpz_class d;
        mpz_class y=1;
        while( ((m*y+1)% e) != 0 )
        { y++; }
        d = ((m*y+1)/e);
        ui->dValor->setPlainText(QString::fromStdString(d.get_str(10)));
        this->puedeCifrar=true;
    }
    ui->statusBar->showMessage("");
}

void MainWindow::on_textoSinCifrar_textChanged()
{
    QString a = ui->textoSinCifrar->toPlainText();
    QString b;
    QChar c;
    int z;
    for(int i=0; i < a.length(); i++)
    {
        c = a.at(i);
        z = ltoNumber(c.toLatin1());
        b+= QString::number(z) + " ";
    }
    ui->textoNumerico->setPlainText(b);
}

void MainWindow::on_cifrarButton_clicked()
{
    if(this->puedeCifrar)
    {
        string stdaux;
        mpz_class numero;

        QString nE = ui->eValor->toPlainText();
        stdaux = nE.toStdString();
        mpz_class e(stdaux,10);

        QString nN = ui->nValor->toPlainText();
        stdaux = nN.toStdString();
        mpz_class n(stdaux,10);

        mpz_class c;

        QString a = ui->textoSinCifrar->toPlainText();
        QString b;
        QChar caract;
        int z;
        for(int i=0; i < a.length(); i++)
        {
            caract = a.at(i);
            z = ltoNumber(caract.toLatin1());
            stdaux = (QString::number(z)).toStdString();
            numero = stdaux;
            mpz_powm(c.get_mpz_t(),numero.get_mpz_t(),e.get_mpz_t(),n.get_mpz_t());
            b += QString::fromStdString(c.get_str(10)) + " ";
        }
        ui->textoCifrado->setPlainText(b);

        QString stdDescifrar = ui->textoCifrado->toPlainText();
        QString stdDescifrado;
        QStringList listDescifrar = stdDescifrar.split(" ",QString::SkipEmptyParts);
        QString nD = ui->dValor->toPlainText();
        stdaux = nD.toStdString();
        mpz_class d(stdaux,10);
        mpz_class auxi;
        mpz_class x;
        for(unsigned int i = 0; i < (unsigned int)listDescifrar.size();i++)
        {
            auxi = listDescifrar.at(i).toLocal8Bit().constData();
            mpz_powm(x.get_mpz_t(),auxi.get_mpz_t(),d.get_mpz_t(),n.get_mpz_t());
            stdDescifrado += ntoLetter(x.get_d());
            //stdDescifrado += QString::fromStdString(x.get_str(10)) + " ";
        }
        ui->textoDescifrado->setPlainText(stdDescifrado);
    }
    else
    { QMessageBox::warning(this,"Nope","Elige p y q satisfactoriamente primero!"); }
}

void MainWindow::on_actionCargar_triggered()
{
    QFile archivo("normal.txt");
    if(!archivo.open(QFile::ReadOnly))
    {
        QMessageBox::warning(this,"ERROR","No se encontro el archivo!");
    }
    else
    {
        QTextStream leer(&archivo);
        QString cadena = leer.readAll();
        ui->textoSinCifrar->setPlainText(cadena);
        archivo.close();
    }

}

void MainWindow::on_actionGuardar_triggered()
{
    QFile archivo("cifrado.txt");
    if(!archivo.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"ERROR","No se encontro el archivo.");
    }
    else
    {
        QTextStream escribir(&archivo);
        escribir << ui->textoCifrado->toPlainText();
        archivo.flush();
        archivo.close();
    }
}

void MainWindow::on_actionCCOB_triggered()
{
    QMessageBox::information(this,"Info del alumno",
                             " Alumno:    Cervantes Candelario Oscar Baltazar\
                             Materia:   Seminario de Solución de Problemas de Métodos Matemáticos I\
                             Seccion:   D12");
}
