#include "ingameui.h"

InGameUI::InGameUI(){}

InGameUI::InGameUI(QPoint pos, QSize size,QWidget* parent) :QWidget(parent)
{



    mainLayout = new QVBoxLayout();
    menu = new QHBoxLayout();
    statContainer = new QVBoxLayout();
    pause = new QPushButton();

    menu->addWidget(pause);

    //Definition du widget stat


    Mort = new QLabel(QString("Mort : 0"));
    Score = new QLabel(QString("Score : 0"));

    statContainer->addWidget(Score);
    statContainer->addWidget(Mort);

    //Ajout du tableau de stat au menu
    menu->addLayout(statContainer);
    mainLayout->addLayout(menu);
    setLayout(mainLayout);

   // move(pos);
    setMaximumSize(size);


}

void InGameUI::updateMort(int scr){
    QString tmpS("Morts : ");
    tmpS += QString::number(scr);
    Mort->setText(tmpS);
}

void InGameUI::updateScore(int scr){
    QString tmpS("Score : ");
    tmpS += QString::number(scr);
    Score->setText(tmpS);
}
