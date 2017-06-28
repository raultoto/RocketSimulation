#ifndef MENU_H
#define MENU_H
//include .h
#include "earth.h"
#include "vector.h"
#include "rocket.h"
#include "environment.h"
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

};

#endif // MENU_H
