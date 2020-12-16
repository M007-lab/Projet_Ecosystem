#include "FactoryBestiole.h"
#include <memory>

FactoryBestiole::FactoryBestiole(void)
{   

    vitesse = Rand_double(0,Config::getInstance()->vitesseMax);
    age     = Rand_int(1,Config::getInstance()->ageMax); 
    alpha   = Rand_double(Config::getInstance()->alphaMin*M_PI/180,Config::getInstance()->alphaMax*M_PI/180);
    deltaY  = Rand_double(Config::getInstance()->deltaYmin,Config::getInstance()->deltaYmax);
    gammaY  = Rand_double(Config::getInstance()->gammaYmin,Config::getInstance()->gammaYmax);
    deltaO  = Rand_double(Config::getInstance()->deltaOmin,Config::getInstance()->deltaOmax);
    gammaO  = Rand_double(Config::getInstance()->gammaOmin,Config::getInstance()->gammaOmax);
    nu      = Rand_double(1,Config::getInstance()->nuMax);
    omega   = Rand_double(1,Config::getInstance()->omegaMax);
    eta     = Rand_double(1,Config::getInstance()->etaMax);
    psi     = Rand_double(Config::getInstance()->psiMin,Config::getInstance()->psiMax);
    x       = Rand_int(0,Config::getInstance()->width);
    y       = Rand_int(0,Config::getInstance()->height);
    orientation = Rand_double(0,2*M_PI);
}

ConcreteBestiole* FactoryBestiole::createBestiole(Comportement* c,unsigned char _color[3])
{   
    // if (c!=nullptr){
    //     ConcreteBestiole* ptr = new BestioleSimple(x(),y(),age(),vitesse(),orientation());
    // }
    std::cout << "X = "<< x() << "y = " << y() <<endl;
    ConcreteBestiole* ptr = new BestioleSimple(x(),y(),age(),vitesse(),orientation(),c->dupliquer(),_color);
    Rand_double rd(0,1);
    if(rd()<= Config::getInstance()->probaYeux)
        ptr = new Yeux(ptr,gammaY(),deltaY(),alpha());
    // if(rd()<= Config::getInstance()->probaOreilles)
    //     ptr = new Oreille(ptr,gammaO(),deltaO());
    // if(rd()<= Config::getInstance()->probaNageoires)
    //     ptr = new Nageoire(ptr,nu());
    // if(rd()<= Config::getInstance()->probaCarapace)
    //     ptr = new Carapace(ptr,omega(),eta());
    // if(rd()<= Config::getInstance()->probaCamouflage)
    //     ptr = new Camouflage(ptr,psi());
    std::cout << ptr->getX() << ptr->getY() <<endl;
    return ptr;
}
