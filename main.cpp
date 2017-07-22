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
    ///datos sobre la unsa
    /*double latitud=-71.534722 ,altitud=50,longitud=-71.534722
                ,v=20;*/
    string primer_file="AxD.csv";
    string segundo_file="AxP.csv";
    string tercer_file="XxY.csv";
    open(primer_file);
    open(segundo_file);
    open(tercer_file);
    double td=12;
    //Rocket<double> primer_experimento(altitud,v,latitud,longitud,td);
    double altitud = 1;
    Environment<double> prueba_enviroment(altitud);
    double h;
    for(int i=0;h<=80;i++)
    {

        double daltitudg=prueba_enviroment.dif_altitud();
        cout<<"diferencial"<<daltitudg;
        qDebug()<<prueba_enviroment.getspeedsound();
        Guardar(prueba_enviroment.get_Altitudg(),prueba_enviroment.getdensitybyLm(),primer_file);
        Guardar(prueba_enviroment.get_Altitudg(),prueba_enviroment.getpresionbyLm(),segundo_file);
        h=prueba_enviroment.get_Altitudg()+ daltitudg;
        prueba_enviroment.setvar(h);
        cout<<"Que extraño qt tengo";
        /*primer_experimento.movimiento();

        Guardar(primer_experimento.height,primer_experimento.posicion.getX(),primer_file);
        primer_experimento.height+=primer_experimento.ambiente.dif_altitud();//cambiando

        primer_experimento.v=primer_experimento.v+primer_experimento.dif_velocity();
        Guardar(primer_experimento.ambiente.getpresionbyLm(),primer_experimento.ambiente.getdensitybyLm(),"PxD.csv");
        primer_experimento.setlatitud_longitud(latitud,longitud,primer_experimento.height);
        Guardar(primer_experimento.posicion.getX(),primer_experimento.posicion.getY(),tercer_file);*/
    }
return a.exec();


}
