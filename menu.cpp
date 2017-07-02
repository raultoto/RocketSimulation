#include "menu.h"
#include <QDebug>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include "rocket.cpp"
#include "environment.cpp"
#include "earth.cpp"
//#include "vector.cpp"
using namespace std;
Menu::Menu(QWidget *parent)
{

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,3600,1800);//make the scene
    setScene(scene);
    text = new QGraphicsTextItem();
    text->setPlainText(QString("Hello World"));
    text->setDefaultTextColor(Qt::blue);
    earthInterface = new EarthInterface();
    scene->addItem(earthInterface);

    scene->addItem(text);
    rocketInterface = new RocketInterface;
    scene->addItem(rocketInterface);
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,700);

}
