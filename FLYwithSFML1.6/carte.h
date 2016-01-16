#ifndef CARTE_H
#define CARTE_H
#include <SFML/Graphics.hpp>
#include <QVector>
#include "imagemanager.h"

static int carteWidth;
static int carteHeight;

class Carte
{
protected:
   //*Attributs
   sf::Sprite Isup;
   sf::Sprite Iinf;
   sf::Sprite hitbox;
   //*/




public:

    //*Constructeurs
    Carte();
    Carte(ImageManager&, std::string, std::string, std::string);
    //*/

    //*Methodes
    void afficher(sf::RenderWindow &, std::string);
    //*/

    //*Getters
    sf::Sprite get_image(std::string);
    sf::Sprite get_hitbox();
    //*/

    //*Setters
    void set_Map(ImageManager&, std::string adr);
    //*/
};

#endif // CARTE_H
