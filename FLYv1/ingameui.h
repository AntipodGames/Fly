#ifndef INGAMEUI_H
#define INGAMEUI_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>



class InGameUI : public QWidget
{
    Q_OBJECT

public:
    QVBoxLayout* mainLayout;
    QHBoxLayout* menu;
    QVBoxLayout* statContainer;
    QPushButton* pause;
    QLabel* Mort;
    QLabel* Score;


    InGameUI();
    InGameUI(QPoint, QSize, QWidget *parent = 0);

public slots:
    void updateMort(int scr);
    void updateScore(int scr);

};

#endif // INGAMEUI_H
