#ifndef MENU_H
#define MENU_H
//header files
//include .hude "environment.h"
#include "rocket.h"
#include "rocketinterface.h"
#include "earthinterface.h"
//qt includes
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
class Menu:public QGraphicsView
{
    Q_OBJECT
public:
    Menu(QWidget *parent=0);

    QGraphicsScene *scene;//create a new scene
    QGraphicsTextItem *text;
    Rocket<int> *rocket;// rocket object
    Earth<int> *earth;//earth object
    RocketInterface *rocketInterface;
    EarthInterface *earthInterface;
};

#endif // MENU_H
