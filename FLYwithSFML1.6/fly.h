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

    QVector<QPoint>& getPos();
    void bounce(sf::Sprite&);
    bool slide(sf::Sprite&);

    bool isInSlidingMod();

    void emitSendPos();

    void setStop(bool);

public slots:

    void Left();
    void Right();
    void turn(float);
    void posUpdate(float,float);
    void Boost(bool);
    void SlideMod(bool);
    void takeControl(bool);
    void wall();


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
    float dX;
    float dY;
    bool isInSlideMod = false;

    float boostVelo ;
    float standardVelo;


    void controledMove();
    void defaultMove();

    float absolute(float v);

};

#endif // FLY_H
