#include "animatedsprite.h"
#include "QString"
#include "QTextStream"


/*void AnimatedSprite::dataAnalyser(int width,std::string str){
    QFile QF(QString(str.data()));
    int nbrChar = (width*width+width-1);
    matrix = new int*[width];
    for(int i; i<width; i++)
        matrix[i] = new int[width];
    if(!QF.open(QIODevice::ReadOnly)){
        std::cerr << "Impossible d'ouvrir le fichier " << str << std::endl;
        return;
    }


    QTextStream in(&QF);
    QString data = in.readLine();

    int j = 0;
    int k = 0;

    for(int i; i < nbrChar; i++){

        if(data.toStdString().data()[i] != ' '){
            matrix[k][j] = data.toStdString().data()[i];
            k++;
        }
        else if (data[i] == ' '){
            j++;
            k=0;
        }
    }
}*/

AnimatedSprite::AnimatedSprite(){}

/**
 * Constructeur d'image animé
 * @brief AnimatedSprite::AnimatedSprite
 * @param IM
 * @param adr
 * @param nbrF
 * @param width
 * @param height
 * @param centreX
 * @param centreY
 * @param vit
 */
AnimatedSprite::AnimatedSprite(ImageManager & IM, std::string adr,int nbrF,int size, int centreX, int centreY,int vit)
{
    std::string imAdr(adr);
    imAdr.append(".png");
    std::string dataAdr(adr);
    dataAdr.append(".data");
    image.SetImage(*(IM.GetImage(imAdr)));
    frame = 1;
    cpt = 0;
    vitesse  = vit;
    nbrFrame = nbrF;
    scale = size;

    image.Resize(image.GetSize().x/size,image.GetSize().y/size);
    image.SetCenter(image.GetImage()->GetWidth()/(centreX*nbrFrame),image.GetImage()->GetHeight()/centreY);
    image.SetSubRect(sf::IntRect(0,0,image.GetImage()->GetWidth()/nbrFrame,image.GetImage()->GetHeight()));
   // dataAnalyser(width,dataAdr);

}
AnimatedSprite::AnimatedSprite(ImageManager & IM, std::string adr,int nbrF,int size,int vit,bool centrer)
{
    std::string imAdr(adr);
    imAdr.append(".png");
    std::string dataAdr(adr);
    dataAdr.append(".data");
    image.SetImage(*(IM.GetImage(imAdr)));
    frame = 1;
    cpt = 0;
    vitesse  = vit;
    nbrFrame = nbrF;
    scale = size;
    image.Resize(size*nbrFrame,(image.GetSize().y/(image.GetSize().x/nbrFrame))*size);
    if(centrer){
     //   if(nbrFrame == 1)
       //     image.SetCenter(0,image.GetImage()->GetHeight()/2);
       // else
            image.SetCenter(image.GetImage()->GetWidth()/(nbrFrame)/2,image.GetImage()->GetHeight()/2);
    }
    image.SetSubRect(sf::IntRect(0,0,image.GetImage()->GetWidth()/nbrFrame,image.GetImage()->GetHeight()));
   // dataAnalyser(width,dataAdr);

}

/**
 * @brief AnimatedSprite::AnimatedSprite
 * @param as
 */
AnimatedSprite::AnimatedSprite(const AnimatedSprite & as){
    image = as.image;
    nbrFrame = as.nbrFrame;
    vitesse = as.vitesse;
    cpt = as.cpt;
    frame = as.frame;
    scale = as.scale;

}

void AnimatedSprite::affichage(sf::RenderWindow& App){
    App.Draw(image);
}


/**
 * @brief AnimatedSprite::chFrame
 * @return
 */
bool AnimatedSprite::chFrame(){

    bool res = false;

    if(cpt >= vitesse){
        if(frame >= nbrFrame){
            frame = 0;
            res = true;
        }

        frame++;
        cpt = 0;
    }
    cpt++;
    image.SetSubRect(sf::IntRect((image.GetImage()->GetWidth()/nbrFrame)*(frame-1),0,(image.GetImage()->GetWidth()/nbrFrame)*frame,image.GetImage()->GetHeight()));

    return res;

}

sf::Vector2f AnimatedSprite::TransformToLocal(const sf::Vector2f & Pt){
    return TransformToLocal(Pt);
}

void AnimatedSprite::setFrame(int i){
    frame = i%nbrFrame+1;
    image.SetSubRect(sf::IntRect((image.GetImage()->GetWidth()/nbrFrame)*(frame-1),0,(image.GetImage()->GetWidth()/nbrFrame)*frame,image.GetImage()->GetHeight()));

}

int AnimatedSprite::getFrame(){
    return frame;
}

int AnimatedSprite::getNbrFrame(){
    return nbrFrame;
}

void AnimatedSprite::Rotate(float angle){
    image.Rotate(angle/PI*180);

}

void AnimatedSprite::setAngle(float angle){
    image.SetRotation(angle/PI*180);
}

float AnimatedSprite::getAngle(){
    return image.GetRotation()/180*PI;
}

void AnimatedSprite::setPosition(int x, int y){
    image.SetPosition(x,y);
}

sf::Sprite& AnimatedSprite::getImage(){
    return image;
}

int AnimatedSprite::getScale(){
    return scale;
}

