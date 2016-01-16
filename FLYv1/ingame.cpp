#include "ingame.h"

InGame::InGame()
{
}

InGame::InGame(int width, int height)
{
    MainFrame = new QFrame();
    MainFrame->resize(width, height-50);
    env = new Environment(width,height-50);
    SFMLView = new QSFcanvas(QPoint(0,0),QSize(width,height-50),MainFrame);
    gui = new InGameUI(QPoint(0,height-50),QSize(width,50));

    setMinimumSize(width,height);

    Pause = new QMessageBox(this);
    endLevel = new QMessageBox();

    //SM = new SoundManager("Flying_pixels_short.mp3",12800);

    container = new QVBoxLayout(this);

    container->addWidget(MainFrame);
    container->addWidget(gui);
    container->setMargin(0);

    endLevel->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    Pause->setText("Pause");

    connect(env,SIGNAL(sendMort(int)),gui,SLOT(updateMort(int)));
    connect(env,SIGNAL(sendScore(int)),gui,SLOT(updateScore(int)));

    connect(SFMLView,SIGNAL(setPause()),env,SLOT(pause()));
    connect(SFMLView,SIGNAL(setPause()),this,SLOT(pausePopUp()));
    connect(Pause,SIGNAL(accepted()),env,SLOT(pause()));
    connect(Pause,SIGNAL(accepted()),SFMLView,SLOT(pause()));
    connect(gui->pause,SIGNAL(pressed()),env,SLOT(pause()));
    connect(gui->pause,SIGNAL(pressed()),SFMLView,SLOT(pause()));

    connect(env,SIGNAL(endLvl(QString)),this,SLOT(endLvlPopUp(QString)));

    connect(env,SIGNAL(sendDM(DisplayManager&)),SFMLView,SLOT(receiveDM(DisplayManager&)));
    connect(SFMLView,SIGNAL(turnLeft()),env->getFly(),SLOT(Left()));
    connect(SFMLView,SIGNAL(turnRight()),env->getFly(),SLOT(Right()));
    connect(SFMLView,SIGNAL(activBoost(bool)),env->getFly(),SLOT(Boost(bool)));
    connect(env->getFly(),SIGNAL(noLeft()),SFMLView,SLOT(desableLeft()));
    connect(env->getFly(),SIGNAL(noRight()),SFMLView,SLOT(desableRight()));
    connect(env->getFly(),SIGNAL(sendPos(int,int)),SFMLView,SLOT(updateView(int,int)));
    connect(SFMLView,SIGNAL(sendPadPos(float)),env->getFly(),SLOT(turn(float)));
    connect(SFMLView,SIGNAL(takeContr(bool)),env->getFly(),SLOT(takeControl(bool)));

    connect(SFMLView,SIGNAL(sendStop(bool)),env,SLOT(makeStop(bool)));

    connect(env,SIGNAL(newLevel(int)),SFMLView,SLOT(switchMap(int)));

}

void InGame::init(){
    env->init();

    MainFrame->show();
    SFMLView->show();
    //SM->playPause();

}

void InGame::pausePopUp(){
    if(Pause->isEnabled())
        Pause->close();
    else Pause->exec();
}

void InGame::endLvlPopUp(QString str){
    endLevel->setText(str);
    endLevel->exec();
}
