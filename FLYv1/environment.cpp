#include "environment.h"

Environment::Environment()
{
    timer.setInterval(TIMER);

}

Environment::Environment(int w,int h){
    width = w;
    height = h;
    timer.setInterval(TIMER);

    playerStat.insert("mort",0);
    playerStat.insert("score",0);
    Fly* mouche = new Fly("Fly",3.6,width/2,height/2,5,5,1);

    entityMap.insert(mouche->getID(),mouche);

    flyID = mouche->getID();

    DM.add(10,height/2,flyID);
}

void Environment::init(){
    connect(&timer,SIGNAL(timeout()),this,SLOT(run()));
    timer.start();
    std::cout << "Environment Initialisation" << std::endl;
    hitBox.SetImage(*(IM.GetImage("graphics/level" + QString::number(level).toStdString() + ".png")));
    //bonusLoader(level);
    emit newLevel(level);

}

void Environment::bonusLoader(int lvl){
    std::string tmpStr("Data/level" + QString::number(lvl).toStdString() + ".data");
    std::ifstream file(tmpStr.data(),std::ios::in);
    std::string line;
    std::string name;
    bpoint pt;
    int x;
    int y;
    while(std::getline(file,line)){
        std::stringstream sline;
        sline << line;
        sline >> name >> x >> y;
        Entite* tmp = new Entite(name,0,x,y,20,20,1);
        entityMap.insert(tmp->getID(),tmp);
        pt.first=x;
        pt.second=y;
        if(name == "caca")
            cacaIdList.append(tmp->getID());
        if(name == "cacador")
            cacadorIdList.append(tmp->getID());
        DM.add(x,y,tmp->getID());

        //std::cout <<  << std::endl;
    }
    file.close();

}

void Environment::bonusPurge(){
    if(!cacaIdList.isEmpty()){
        for(int i = 0; i < cacaIdList.size(); i++){
            DM.remove(cacaIdList[i],entityMap.value(cacaIdList[i])->get_y());
            entityMap.remove(cacaIdList[i]);
        }
        cacaIdList.clear();
    }
    if(!cacadorIdList.isEmpty()){
        for(int i = 0; i < cacadorIdList.size(); i++){
            DM.remove(cacadorIdList[i],entityMap.value(cacadorIdList[i])->get_y());
            entityMap.remove(cacadorIdList[i]);
        }
        cacadorIdList.clear();
    }
}



void Environment::run(){



    DM.remove(flyID,entityMap.value(flyID)->get_y());
   ((Fly*) entityMap.value(flyID))->move();

    if(((Fly*) entityMap.value(flyID))->get_trigger().intersection(hitBox,sf::Color::Black)){
        ((Fly*) entityMap.value(flyID))->bounce(hitBox);


        //((Fly*) entityMap.value(flyID))->setStop(stop);

      /*  entityMap.value(flyID)->set_x(10);
        entityMap.value(flyID)->set_y(height/2);
        entityMap.value(flyID)->setAngle(0);
        playerStat.insert("mort",playerStat.value("mort")+1);
        bonusPurge();
        bonusLoader(level);*/
    }
    if(((Fly*) entityMap.value(flyID))->get_trigger().intersection(hitBox,sf::Color::Red)){
        std::cout << "Bravo !!" << std::endl;
        std::cout << "level " << level << " morts :" << playerStat.value("mort") << std::endl;
        int score = 10000-playerStat.value("mort")*200;
        if(cacaIdList.isEmpty()){
            stars++;
            score+= 5000;
        }
        if(cacadorIdList.isEmpty()){
            stars++;
            score+= 5000;
        }
        if(score <= 0)
                score = 0;

        playerStat.insert("score",playerStat.value("score")+score);
        level++;
        playerStat.insert("mort",0);

        emit endLvl("Bravo!! Vous avez termine ce niveau ! \n " + QString::number(stars) + " etoiles");

        if(level <= 9){
            emit newLevel(level);
            stars = 0;
            hitBox.SetImage(*(IM.GetImage("graphics/level" +  QString::number(level).toStdString() + ".png")));

            entityMap.value(flyID)->set_x(10);
            entityMap.value(flyID)->set_y(height/2);
            entityMap.value(flyID)->setAngle(0);
            entityMap.value(flyID)->set_vitesse(4);
            bonusPurge();
            bonusLoader(level);
        }
        else {
            std::cout << playerStat.value("mort") << std::endl;
            std::cout << playerStat.value("score") << std::endl;

            exit(0);
        }
    }

    bpoint pt;
    pt.first = entityMap.value(flyID)->get_x();
    pt.second = entityMap.value(flyID)->get_y();

    for(int i = 0; i < cacaIdList.size();i++){
        if(entityMap.value(cacaIdList[i])->get_trigger().isIN(pt.first,pt.second)){
            DM.remove(cacaIdList[i],pt.second);

         /*   if(entityMap.value(bonusIdList[i])->get_nom() == "caca")
                playerStat.insert("score",playerStat.value("score")+100);
            if(entityMap.value(bonusIdList[i])->get_nom() == "cacador")
                playerStat.insert("score",playerStat.value("score")+1000);

*/
            entityMap.remove(cacaIdList[i]);
            cacaIdList.remove(i);
            cacaIdList.squeeze();

        }
    }
    for(int i = 0; i < cacadorIdList.size();i++){
        if(entityMap.value(cacadorIdList[i])->get_trigger().isIN(pt.first,pt.second)){
            DM.remove(cacadorIdList[i],pt.second);

         /*   if(entityMap.value(bonusIdList[i])->get_nom() == "caca")
                playerStat.insert("score",playerStat.value("score")+100);
            if(entityMap.value(bonusIdList[i])->get_nom() == "cacador")
                playerStat.insert("score",playerStat.value("score")+1000);

*/
            entityMap.remove(cacadorIdList[i]);
            cacadorIdList.remove(i);
            cacadorIdList.squeeze();

        }
    }


    DM.add(entityMap.value(flyID)->get_x(),entityMap.value(flyID)->get_y(),flyID);

    DM.setEM(entityMap);

    emit sendDM(DM);
    emit sendMort(playerStat.value("mort"));
    emit sendScore(playerStat.value("score"));
}

void Environment::pause(){
    if(timer.isActive())
        timer.stop();
    else timer.start();
}

void Environment::makeStop(bool b){
    stop = b;
}

Fly* Environment::getFly(){

    return (Fly*) entityMap.value(flyID);

}

