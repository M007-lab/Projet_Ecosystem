#include "Yeux.h"


    Yeux::Yeux(Bestiole* base, double detec, double dist, double angle) {
        this->name = "Yeux";
        this->base = base;
        this->capaciteDetection = detec;
        this->angle = angle;
        this->distance = dist;
        this->capteurDecorateurs.push_back(this);
    }


    bool Yeux::jeTeVois(const Bestiole & autre) const {
        bool jeVois = autre.getCamouflage() < this->capaciteDetection;
        bool distanceOk = this->plusProcheQue(autre, this->distance);
        bool dansArc = this->dansArcVue(autre, this->angle);
        return ( (jeVois && distanceOk && dansArc) || this->getBase()->jeTeVois(autre));
    }


    void Yeux::draw(UImg& support) {
        double angleMin = this->getOrientation() - this->angle/2;
        double angleMax = this->getOrientation() + this->angle/2;
        int x0 = this->getX() + this->distance * cos(angleMin);
        int y0 = this->getY() - this->distance * sin(angleMin);
        int x1 = this->getX() + this->distance * cos(angleMax);
        int y1 = this->getY() - this->distance * sin(angleMax);
        support.draw_line(this->getX(), this->getY(), x0, y0, this->getColor());
        support.draw_line(this->getX(), this->getY(), x1, y1, this->getColor()); // Dessine deux lignes représentant le cone de vision
        this->getBase()->draw(support);
    }

    bool Yeux::isYeux(CapteurDecorateur * capDec) {
        return instanceof<Yeux*>(capDec);
    }

    Yeux* Yeux::castYeux(CapteurDecorateur * capDec){
        Yeux* yeux = dynamic_cast<Yeux*>(capDec) ;
        return yeux;
}