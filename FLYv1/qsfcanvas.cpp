#include "qsfcanvas.h"


QSFcanvas::QSFcanvas(const QPoint& Position, const QSize& Size, QWidget* parent) : Qsfml(parent, Position, Size)
{
        carte = Carte(IM,"graphics/level8.png","graphics/level8.png","graphics/level8.png",this->GetWidth(),this->GetHeight());

}






void QSFcanvas::keyPressEvent(QKeyEvent * ke){

    if(ke->key() == Qt::Key_Q){
        leftPressed = true;
        rightPressed = false;
        emit takeContr(true);
    }
    if(ke->key() == Qt::Key_D ){
        leftPressed = false;
        rightPressed = true;
        emit takeContr(true);
    }
    if(ke->key() == Qt::Key_Shift){
        emit activBoost(true);
    }


}

void QSFcanvas::keyReleaseEvent(QKeyEvent * e){
    if(e->key() == Qt::Key_Q){
        leftPressed = false;
        emit takeContr(false);
    }
    if(e->key() == Qt::Key_D){
        rightPressed = false;
        emit takeContr(false);
    }
    if(e->key() == Qt::Key_Space){
        pause();
        emit setPause();
    }
    if(e->key() == Qt::Key_Shift){
        emit activBoost(false);
    }
}

void QSFcanvas::gamePadEvent(){
    sf::Event Event;
    if (this->GetEvent(Event))
    {
        if((Event.Type == sf::Event::JoyMoved) && ((Event.JoyMove.Axis == sf::Joy::AxisX)) ){
            axisXPos = Event.JoyMove.Position/100;
          //  std::cout << this->GetInput().GetJoystickAxis(0,sf::Joy::AxisX) << std::endl;
        }
        if((Event.Type == sf::Event::JoyButtonPressed)){
            if(Event.JoyButton.Button == 4) //L1
                emit activBoost(true);
            if(Event.JoyButton.Button == 0) //Triangle
                emit sendStop(true);

        }
        if((Event.Type == sf::Event::JoyButtonReleased)){
            if(Event.JoyButton.Button == 4) //L1
                emit activBoost(false);
            if(Event.JoyButton.Button == 0) //Triangle
                emit sendStop(false);

        }
    }
    emit sendPadPos(axisXPos);


}

void QSFcanvas::OnInit(){

    setMouseTracking(true);


    view = sf::View(sf::FloatRect(0,0,600,400));

    //*Initialisation des images
    AM.add("Fly",AnimatedSprite(IM,"graphics/FLYanim",4,7*TAILLE,0,true));
    AM.add("Circle",AnimatedSprite(IM,"graphics/blackcircle",1,TAILLE,0,true));
    AM.add("caca",AnimatedSprite(IM,"graphics/CACA",1,5*10,0,false));
    AM.add("cacador",AnimatedSprite(IM,"graphics/cacador",1,5*12,0,false));
    //*/












    std::cout << "init!!!!" << std::endl;


}

void QSFcanvas::receiveDM(DisplayManager & dm){
    DM = dm;
}



void QSFcanvas::pause(){
    if(myTimer.isActive())
        myTimer.stop();
    else myTimer.start();
}

void QSFcanvas::desableLeft(){

    leftPressed = false;
}

void QSFcanvas::desableRight(){
    rightPressed = false;
}

void QSFcanvas::updateView(int x, int y){
    view.SetCenter(x,y);
}

void QSFcanvas::switchMap(int lvl){
    QString tmp("graphics/level");
    tmp += QString::number(lvl);
    tmp += ".png";
    carte.set_Map(IM,tmp.toStdString());
}

void QSFcanvas::OnUpdate()
{


    gamePadEvent();

    if(leftPressed)
        emit turnLeft();
    if(rightPressed)
        emit turnRight();


    Clear();

    SetView(view);
    carte.afficher(*this,"inf");


    DM.display(AM,*this);





}

ImageManager& QSFcanvas::getIM(){
    return IM;
}
