#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <QObject>
#include <QTimer>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QPoint>
#include "fly.h"
#include "displaymanager.h"
#define TIMER 16


class Environment : public QObject
{
    Q_OBJECT

public:
    Environment();
    Environment(int w, int h);

    void keyPressEvent(QKeyEvent *);

    void init();

    void bonusLoader(int lvl);
    void bonusPurge();

    Fly* getFly();

public slots:
    void run();
    void pause();
    void makeStop(bool);

signals:
    void sendDM(DisplayManager&);
    void sendMort(int);
    void sendScore(int);
    void newLevel(int);
    void endLvl(QString);


private:

    typedef std::pair<int,int> bpoint;

    //Attributs
    ImageManager IM;
    QMap<QString,int> playerStat;

    QTimer timer;
    QMap<int,Entite*> entityMap;

    QVector<int> cacaIdList;
    QVector<int> cacadorIdList;

    DisplayManager DM;
    int flyID;
    int width;
    int height;
    int level = 0 ;
    int stars = 0;
    bool stop=false;
    sf::Sprite hitBox;


};

#endif // ENVIRONMENT_H
