#ifndef ROCKETINTERFACE_H
#define ROCKETINTERFACE_H
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <QGraphicsPixmapItem>
#include <QObject>
using namespace std;
class RocketInterface:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    RocketInterface();
    void readFiles(string);//lee un archivo
    double stringToInt(string);
    void convertStringToNumber(string);
private:
    vector<double> vec1;
    vector<double> vec2;
public slots:
    void move();
};


#endif // ROCKETINTERFACE_H
