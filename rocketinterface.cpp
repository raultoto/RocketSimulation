#include "rocketinterface.h"
#include "menu.h"
#include "rockettrajectory.h"
#include <QGraphicsScene>
#include <QTimer>
#include <typeinfo>
extern Menu *menu;
RocketInterface::RocketInterface()
{
    setPixmap(QPixmap(":/images/Images/Picture5.png"));

    setPos(1000,1000);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(60);
}
void RocketInterface::readFiles(string name)
{
    ifstream inputFile;
    inputFile.open(name);//"prueba.csv"
    string data;
    if (inputFile.is_open())
    {
            while(!inputFile.eof())
            {
                getline(inputFile,data);
                //cout << data << endl;
                convertStringToNumber(data);
            }
            inputFile.close();
     }

}

double RocketInterface::stringToInt(string number)
{
    stringstream sstr;
    sstr << number;
    double converted;
    sstr >> converted;
    return converted;

}

void RocketInterface::convertStringToNumber(string number)
{
    string str1,str2;

    for (int i = 0; i < number.length(); ++i) {
        if(number[i]!=',')
            str2=str2+number[i];
        else
        {
            str1=str2;
            str2="";
        }
        //cout << number[i] << endl;
    }
    vec1.push_back(stringToInt(str1));
    vec2.push_back(stringToInt(str2));
}

void RocketInterface::move()
{
    //readFiles("prueba.csv");
    RocketTrajectory *rocketTrayectory = new RocketTrajectory("*",2);
    scene()->addItem(rocketTrayectory);
    setPos(x()+5,y()-4);
    menu->showData->moveData();
}
