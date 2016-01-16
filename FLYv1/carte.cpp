#include "carte.h"


//*Constructeurs
Carte::Carte(){

}

Carte::Carte(ImageManager &IM, std::string adr1, std::string adr2, std::string adr3,int w,int h)
{

    //hb = new Hitbox(IM,adr);

    Iinf.SetImage(*(IM.GetImage(adr1)));
    Isup.SetImage(*(IM.GetImage(adr2)));
    hitbox.SetImage(*(IM.GetImage(adr3)));

    Iinf.Resize(w,h);
    Isup.Resize(w,h);
    hitbox.Resize(w,h);


}
//*/


//*Methodes
void Carte::afficher(sf::RenderWindow& App,std::string txt){
    if (txt.compare("inf") == 0)
        App.Draw(Iinf);
    else
        App.Draw(Isup);
}
//*/

//*Getters
sf::Sprite Carte::get_image(std::string txt){
    if(txt.compare("sup") == 0)
        return Isup;
    else
        return Iinf;
}


sf::Sprite Carte::get_hitbox(){
    return hitbox;
}

//*/


void Carte::set_Map(ImageManager & IM,std::string adr){
    Iinf.SetImage(*(IM.GetImage(adr)));
}
