#ifndef FLY_H
#define FLY_H
#include "entite.h"
#include <QObject>
#include <QPoint>

class Fly : public QObject, public Entite
{
    Q_OBJECT
public:
    Fly();
    Fly(std::string name,double vit,int px,int py,int w,int h,int life);

    void move();

    void moveBack();
    QVector<QPoint>& getPos();
    void bounce(sf::Sprite&);
    void setStop(bool);

public slots:

    void Left();
    void Right();
    void turn(float);
    void Boost(bool);
    void takeControl(bool);

signals :
    void noLeft();
    void noRight();
    void sendPos(int,int);

private:
    QVector<QPoint> positions;
    int direction;
    bool stop = false;
    bool isControl = false;
    sf::View * view;
    sf::Randomizer rand;

    void controledMove();
    void defaultMove();

};

#endif // FLY_H
