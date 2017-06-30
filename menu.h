#ifndef MENU_H
#define MENU_H
//include .hude "environment.h"
#include "rocket.h"
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
    Rocket<int> *rocket;
    Earth<int> *earth;
};

#endif // MENU_H
