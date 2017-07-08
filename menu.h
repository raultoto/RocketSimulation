#ifndef MENU_H
#define MENU_H
//header files
//include .hude "environment.h"
#include "rocket.h"
#include "rocketinterface.h"
#include "earthinterface.h"
#include "showdata.h"
#include "background.h"
#include "button.h"
#include "movementheight.h"
//qt includes
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsTextItem>
class Menu:public QGraphicsView
{
    Q_OBJECT
public://menber function
    Menu(QWidget *parent=0);
    void displayMainMenu();
    void finishSimulation();
    //create objects
    QGraphicsScene *scene;//create a new scene
    Rocket<int> *rocket;// rocket object
    Earth<int> *earth;//earth object
    RocketInterface *rocketInterface;
    EarthInterface *earthInterface;
    ShowData *showData;
    BackGround *backGround;
    MovementHeight *move;
public slots:
    void start();
    void callMovementHeight();
    //void callGraphData();
};

#endif // MENU_H
