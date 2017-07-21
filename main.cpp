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

    double latitud=40.7127837 ,altitud=23 ,longitud=-74.00594130000002
            ,dlatitud=2,temperatura=20,densidad=123,presion=2000
            ,dtemperatura=10,daltitud=4,ddensidad=1,dpresion=2
            ,lenght_tip=150,v=20;
    string primer_file="HxX.csv";
    string segundo_file="PxD.csv";
    string tercer_file="XxY.csv";
    open(primer_file);
    open(segundo_file);
    open(tercer_file);
    double td=12;
    Rocket<double> primer_experimento(altitud,v,latitud,longitud,td);
    for(int i=0;i<20;i++)
    {
     /*   Environment<double> ambiente(densidad,presion,temperatura,dlatitud);
        double densidadnow=ambiente.getdensitybyLm();
        double presionnow=ambiente.getpresionbyLm();
        cout<<"densidad"<<ambiente.getdensitybyLm();
        cout<<"presion"<<ambiente.getpresionbyLm()<<endl;
        Guardar(densidadnow,presionnow,"DxP.csv");
        Guardar(altitud,densidadnow,"AxD.csv");
        */
        primer_experimento.movimiento();

        Guardar(primer_experimento.height,primer_experimento.posicion.getX(),primer_file);
        primer_experimento.height+=primer_experimento.ambiente.dif_altitud();//cambiando
        primer_experimento.update_var();
        primer_experimento.v=primer_experimento.v+primer_experimento.dif_velocity();


        Guardar(primer_experimento.ambiente.getpresionbyLm(),primer_experimento.ambiente.getdensitybyLm(),"PxD.csv");
        qDebug()<<primer_experimento.height;
        primer_experimento.setlatitud_longitud(latitud,longitud,primer_experimento.height);
        Guardar(primer_experimento.posicion.getX(),primer_experimento.posicion.getY(),tercer_file);
        //primer_experimento.velocity();
        densidad+=ddensidad;
        temperatura+=dtemperatura;
        presion+=dpresion;
    }
return a.exec();


}
