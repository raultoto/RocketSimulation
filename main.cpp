#include <QApplication>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "rocket.h"
#include "earth.h"
#include "rocket.cpp"
#include "earth.cpp"
#include "environment.h"
#include "environment.cpp"
#include "menu.h"
#include<stdlib.h>
#include<fstream>

#include <QGraphicsScene>

using namespace std;
void open(string namefile)
{   FILE *Arch;
    Arch=fopen(namefile.c_str(),"w");
    string cabecera="";
    bool tp_first=false;
    /////////AxBxCxD
    for(auto valor_cabecera : namefile )
    {
        if(valor_cabecera!='x')
            cabecera=cabecera+"%c";
        else
        {
           if(!tp_first)
              cabecera=cabecera+"%c;";
           else
              cabecera=cabecera+";";
           tp_first=true;
        }
    }
    fprintf(Arch,"%c;%c \n",namefile[0],namefile[2]);
    fclose(Arch);
}

void Guardar(float l, float p,string namefile)
{   FILE *Arch;
    Arch=fopen(namefile.c_str(),"a+");
    fprintf(Arch,"%f;%f \n",l,p);
    fclose(Arch);
}
QString text;
Menu *menu;
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    menu=new Menu();
    menu->show();
    menu->displayMainMenu();

    cout<<"Todo se puede de veras";

    string segundo_file="PxD.csv";
    string primer_file="TxV.csv";
    string tercer_file="TxX.csv";
    string cuarto_file="TxY.csv";
    string quinto_file="TxZ.csv";
    string sexto_file="AxD.csv";
    string septimo_file="AxP.csv";
    string octavo_file="TxA.csv";
    string noveno_file="PxL.csv";///latitud por longitud
    string decimo_file="MxT.csv";///masa con el tiempo

    open(primer_file);
    open(segundo_file);
    open(tercer_file);
    open(cuarto_file);
    open(quinto_file);
    open(sexto_file);
    open(septimo_file);
    open(octavo_file);
    open(noveno_file);
    open(decimo_file);

    ///datos
    long double td=0.015 ;
    ///datos sobre la unsa
    long double angulo_latitud=37 ,height=1//220 //km segun el libro,
            ,angulo_longitud=53,v=9.7;//5;
    cout<<height;
    Rocket<long double> primer_experimento(height,v,angulo_latitud,angulo_longitud,td);

    bool obtenerprimer_dato=false;
    long double primer_dato=0;
    for(int i=0;primer_experimento.posicion.getY()>=0 || i<10 ;i++)
    {
        ///////aceleracion
        primer_experimento.aceleration();
        vectores<long double> dv= primer_experimento.dif_velocity();
        primer_experimento.vector_velocity.setX(dv.getX()+ primer_experimento.vector_velocity.getX() );
        primer_experimento.vector_velocity.setY(dv.getY()+ primer_experimento.vector_velocity.getY() );
        primer_experimento.vector_velocity.setZ(dv.getZ()+ primer_experimento.vector_velocity.getZ() );
        primer_experimento.position();
        if(!obtenerprimer_dato)
        {obtenerprimer_dato =primer_experimento.posicion.getY();
            obtenerprimer_dato=true;
        }
        ///////////////datos a guardar en csv
        Guardar(primer_experimento.get_tall() ,primer_experimento.v , primer_file);
        Guardar(primer_experimento.ambiente.getpresionbyLm() ,primer_experimento.ambiente.getdensitybyLm() , segundo_file);
        Guardar(primer_experimento.get_tall(),primer_experimento.posicion.getX(),tercer_file);
        Guardar(primer_experimento.get_tall(),primer_experimento.posicion.getY(),cuarto_file);
        Guardar(primer_experimento.get_tall(),primer_experimento.posicion.getZ(),quinto_file);
        Guardar(primer_experimento.height ,primer_experimento.ambiente.getdensitybyLm() , sexto_file);
        Guardar(primer_experimento.height ,primer_experimento.ambiente.getpresionbyLm() , septimo_file);
        Guardar(primer_experimento.get_tall() ,primer_experimento.height , octavo_file);
        Guardar(primer_experimento.get_phi() ,primer_experimento.get_lamnda() , noveno_file);
        Guardar(primer_experimento.get_doughtxetapa() ,primer_experimento.get_tall() , decimo_file);
        ////////////////cambios durante el vuelo del cohete
        height=primer_experimento.ambiente.get_Altitudg() + primer_experimento.dif_altitud();

        cout<<"primera parte"<<primer_experimento.ambiente.get_Altitudg()<<endl;
        cout<<"segunda parte"<<primer_experimento.dif_altitud()<<endl;

        angulo_latitud =primer_experimento.get_phi() + primer_experimento.dif_phi();
        angulo_longitud =primer_experimento.get_lamnda() + primer_experimento.dif_lamnda();
        primer_experimento.theta=primer_experimento.dif_theta();
        primer_experimento.azimut=primer_experimento.dif_azimut();
        v=primer_experimento.v;
        ////////////set variables
        primer_experimento.setlatitud_longitud(angulo_latitud,angulo_longitud,height,v);
        qDebug()<<"sal esto !!";
    }
return a.exec();
}
