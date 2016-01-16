#include "fly.h"
#include <SFML/System/Randomizer.hpp>

Fly::Fly()
{
}

Fly::Fly(std::string name, double vit, int px, int py, int w, int h, int life) : Entite(name,vit,px,py,w,h,life)
{
    direction = 3;
    emit sendPos(x,y);
    rand.SetSeed(20);

}

void Fly::move(){
    QPoint tmp(x,y);
    if(angle >= 2*PI){
        angle -= 2*PI;
    }
    else if (angle <= -2*PI){
        angle += 2*PI;
    }

 if(!stop){
     chFrame();

  //  if(isControl)
        controledMove();
    //else defaultMove();

    if(positions.size() < 20)
        positions.append(tmp);
    else{
        QPoint tmp2;
        int d = positions.size() -1;
        for(int i = d; i > 0;i-=2){
            tmp2 = positions[i];
            positions.replace(i,tmp);
            tmp = positions[i-1];
            positions.replace(i-1,tmp2);
        }
    }
 }

}
void Fly::controledMove(){

    addX(cos(angle)*vitesse);
    addY(sin(angle)*vitesse);





    emit sendPos(x,y);
}

void Fly::defaultMove(){




    float pi= PI;

    angle = rand.Random(-pi, pi);


    addX(cos(angle)*vitesse);
    addY(sin(angle)*vitesse);




    //emit sendPos(x,y);

}

void Fly::moveBack(){
    addX(cos(angle)*-vitesse);
    addY(sin(angle)*-vitesse);
}

void Fly::bounce(sf::Sprite &sprt){
    float tmpangle = tz.intersectAngle(sprt);
    //std::cout << angle << std::endl;
   /* if(tmpangle == 42){
        if(direction == 2){
            emit noLeft();
            angle+=PI/16;
            std::cout << "noleft" << std::endl;

        }
        else if (direction == 3){
            angle-=PI/16;
;
            emit noRight();
            std::cout << "noright" << std::endl;

        }
    }*/
    angle = PI + 2*tmpangle - angle;
    //std::cout << angle << std::endl << std::endl;


}

QVector<QPoint>& Fly::getPos(){
    return positions;
}

void Fly::setStop(bool b){

    stop = b;
}

void Fly::Left(){
    direction = 2;

    angle= angle - PI/32;


}

void Fly::Right(){
    direction = 3;

    angle = angle + PI/32;


}

void Fly::turn(float ppos){

    angle = angle + PI/24*ppos;

}

void Fly::takeControl(bool b){
    isControl = b;
}

void Fly::Boost(bool activ){
    if(activ == true)
        vitesse+=5;
    else vitesse-=5;
    tz.set_rayon(vitesse);
}
