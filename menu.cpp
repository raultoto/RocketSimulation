#include "menu.h"
#include <QDebug>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include "rocket.cpp"
#include "environment.cpp"
#include "earth.cpp"
//#include "vectores.cpp"
using namespace std;
Menu::Menu(QWidget *parent)
{

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,3600,1800);//make the scene
    //setBackgroundBrush(QBrush(QImage(":/images/earth.jpg")));

    setScene(scene);
    //earthInterface = new EarthInterface();
    //scene->addItem(earthInterface);

    //rocketInterface = new RocketInterface;
    //scene->addItem(rocketInterface);

    //ADd data
    //showData = new ShowData();
    //scene->addItem(showData);
    //showData->moveData();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,700);

}

void Menu::displayMainMenu()
{
    backGround = new BackGround();
    scene->addItem(backGround);
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("RocketSimulation"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(1500,700);
    scene->addItem(titleText);

    // create the start button
    Button* playButton = new Button(QString("Start"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(1725,900);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(1725,1000);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

}

void Menu::finishSimulation()
{

}

void Menu::start()
{
    scene->clear();
    //create and add Earth to the scene
    earthInterface = new EarthInterface();
    scene->addItem(earthInterface);
    //create and add Rocket to the scene
    rocketInterface = new RocketInterface;
    scene->addItem(rocketInterface);

    //create and add ShowData to the scene
    showData = new ShowData();
    scene->addItem(showData);
    //create and movementHeight to the scene
    move= new MovementHeight();
    scene->addItem(move);
    //scene->addItem(move);
}
