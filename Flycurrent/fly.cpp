#include "fly.h"

Fly::Fly()
{
}

Fly::Fly(std::string name, double vit, int px, int py, int w, int h, int life) : Entite(name,vit,px,py,w,h,life)
{
    direction = 3;
//    emit sendPos(x,y);
    standardVelo = vit;
    boostVelo = 3*vit;

}

void Fly::move(){
    QPoint tmp(x,y);
    if(angle > PI){
        angle -= 2.*PI;
    }
    else if (angle < -PI){
        angle += 2.*PI;
    }




    if(!stop){
        chFrame();

        if(isControl)
            controledMove();
        else defaultMove();

        addX(dX*vitesse);
        addY(dY*vitesse);


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
    emit sendPos(x,y);
}

void Fly::defaultMove(){


    float pi = PI;
    boost::random::uniform_real_distribution<> dist(-pi,pi);

    vitesse = standardVelo/2.f;

    angle = dist(rand);
    dX = cos(angle);
    dY = sin(angle);


}

//Deprecated
//void Fly::bounce(sf::Sprite &sprt){
//    float tmpangle = tz.intersectAngle(sprt);

//    angle = PI + 2.*tmpangle - angle;
//    dX = cos(angle);
//    dY = sin(angle);


//}

void Fly::emitSendPos(){
    emit sendPos(x,y);
}

bool Fly::slide(sf::Image * sprt){


    float tmpangle = tz.intersectAngle(sprt);

    if(tmpangle == -100)
        return true;

    if(tmpangle > PI)
        tmpangle -= 2.*PI;
    if(tmpangle < -PI)
        tmpangle += 2.*PI;


    float comparAngle = angle - tmpangle;


    if(comparAngle > PI)
        comparAngle -= 2.*PI;
    if(comparAngle < -PI)
        comparAngle += 2.*PI;

    //TODO : revoir cette partie****
    if(comparAngle < PI/6. && comparAngle > -PI/6.)
        return true;
    //******************************


    if(comparAngle < 0 )
        angle = tmpangle - PI/2.;
    else if (comparAngle > 0 )
        angle = tmpangle + PI/2.;
    else return true;

    addX(-cos(tmpangle)*vitesse);
    addY(-sin(tmpangle)*vitesse);

    dX = cos(angle);
    dY = sin(angle);

    return false;
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

void Fly::posUpdate(float axisX, float axisY){
    takeControl((sqrt(axisX*axisX) >= 0.1f || sqrt(axisY*axisY) >= 0.1f));

    dX = axisX;
    dY = axisY;



    if(dY >= 0)
        angle =   PI/2. - atan(dX/dY);
    if(dY < 0)
        angle = -PI/2. - atan(dX/dY) ;


}

void Fly::wall(){
    vitesse = standardVelo;

    addX(-dX*vitesse);
    addY(-dY*vitesse);
}

void Fly::takeControl(bool b){
    isControl = b;
}

void Fly::Boost(bool activ){
    if(activ && vitesse < boostVelo)
        vitesse += 0.03;
    else if(vitesse > standardVelo)
        vitesse -= 0.5;
//    tz.set_rayon(vitesse);
}

void Fly::SlideMod(bool slmd){
    isInSlideMod = slmd;
}

bool Fly::isInSlidingMod(){
    return isInSlideMod;
}

float Fly::absolute(float v){
    if(v < 0)
        return v - 2.*v;
    else return v;
}
