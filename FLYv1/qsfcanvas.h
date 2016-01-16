#ifndef QSFCANVAS_H
#define QSFCANVAS_H
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <QEvent>
#include <QMouseEvent>
//#include <thread>
#include <SFML/Window.hpp>
#include "qsfml.h"
#include "imagemanager.h"
#include "environment.h"
#include "animatedmanager.h"
#include "displaymanager.h"

class QSFcanvas : public Qsfml
{

    Q_OBJECT

public:
    QSFcanvas(const QPoint& Position, const QSize& Size,QWidget *parent = 0);




    ImageManager& getIM();

public slots :
    void receiveDM(DisplayManager&);
    void switchMap(int);
    void pause();
    void desableLeft();
    void desableRight();
    void updateView(int x,int y);

signals:
    void setPause();
    void turnLeft();
    void turnRight();
    void activBoost(bool);
    void sendPadPos(float);
    void sendStop(bool);
    void takeContr(bool);

private:
    ImageManager IM;
    AnimatedManager AM;
    DisplayManager DM;

    sf::Clock Time;
    time_t initialTime;
    Carte carte;

    sf::View view;

    bool leftPressed = false;
    bool rightPressed = false;
    float  axisXPos = 0;

    void OnInit();
    void OnUpdate();
    void keyPressEvent(QKeyEvent *MEvent);
    void keyReleaseEvent(QKeyEvent *);

    void gamePadEvent();

};

#endif // QSFCANVAS_H
