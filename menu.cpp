#include "menu.h"
#include <QDebug>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
using namespace std;
Menu::Menu(QWidget *parent)
{
    //create a menu
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);//make the scene
    setScene(scene);
    text = new QGraphicsTextItem();
    text->setPlainText(QString("Hello World"));
    text->setDefaultTextColor(Qt::blue);
    scene->addItem(text);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

}
