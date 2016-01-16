#include "qsfcanvas.h"


QSFcanvas::QSFcanvas(const QPoint& Position, const QSize& Size, QWidget* parent) : Qsfml(parent, Position, Size)
{

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
    if(e->key() == Qt::Key_Enter){
        emit retry();
    }
}

void QSFcanvas::gamePadEvent(){

    /*
     * Triangle == 0
     * L1 == 4
     * L2 == 6
     * R1 == 5
     * R2 == 7
     */

    sf::Event Event;
    if (this->GetEvent(Event))
    {
        if((Event.Type == sf::Event::JoyMoved) && ((Event.JoyMove.Axis == sf::Joy::AxisX))){
            axisXPos = Event.JoyMove.Position/100;
           // std::cout << axisXPos << std::endl;
        }
        if((Event.Type == sf::Event::JoyMoved) && ((Event.JoyMove.Axis == sf::Joy::AxisY))){
            axisYPos = Event.JoyMove.Position/100;

            //std::cout << axisYPos << std::endl;
        }
        if((Event.Type == sf::Event::JoyButtonPressed)){
            if(Event.JoyButton.Button == 5){ //R1
                emit activSlide(true);
            }

//            if(Event.JoyButton.Button == 4) //L1
//                emit activBoost(true);


        }
        if((Event.Type == sf::Event::JoyButtonReleased)){
            if(Event.JoyButton.Button == 5){ //R1
                emit activSlide(false);
                padBlocked = false;
            }
            if(Event.JoyButton.Button == 4) //L1
                emit retry();


        }
        if(!padBlocked)
            emit sendPadPos(axisXPos,axisYPos);
    }



}


void QSFcanvas::initView(int x, int y,int width,int height){
    sf::Vector2f viewCenter(x,y);
    sf::Vector2f viewSize(width/2,height/2);
    view = sf::View(viewCenter,viewSize);
}

void QSFcanvas::OnInit(){

    setMouseTracking(true);



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

void QSFcanvas::blockPad(){
    padBlocked = true;
}

void QSFcanvas::switchMap(int lvl){
    QString tmp("graphics/level");
    tmp += QString::number(lvl);
    tmp += ".png";
    carte = Carte(IM,tmp.toStdString(),tmp.toStdString(),tmp.toStdString());

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
