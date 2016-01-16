#ifndef INGAME_H
#define INGAME_H
#include <QWidget>
#include <QMessageBox>
#include <qsfcanvas.h>
#include <environment.h>
#include <ingameui.h>
//#include "soundmanager.h"

class InGame : public QWidget
{
    Q_OBJECT
public:
    InGame( int width, int height);
    InGame();

    void init();
public slots :
    void pausePopUp();
    void endLvlPopUp(QString);

private:
    QVBoxLayout* container;
    QSFcanvas* SFMLView;
    Environment* env;
    InGameUI* gui;
    QMessageBox* Pause;
    QMessageBox* endLevel;
    QFrame* MainFrame;
 //   SoundManager* SM;

    int Width;
    int Height;

};

#endif // INGAME_H
