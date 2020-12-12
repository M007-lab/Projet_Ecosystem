#include "Yeux.h"

Yeux::Yeux(Bestiole* base, double detec, double dist, double angle) {
    this->name = "Yeux";
    this->base = base;
    this->capaciteDetection = detec;
    this->angle = angle;
    this->distance = dist;
}


bool Yeux::jeTeVois(const Bestiole & autre) const {
    bool voisOk = this->capaciteDetection > b.getCamouflage();
    bool distanceOk = this->dansDistanceDetection(b, this->distance);
    bool champOk = this->dansChampAngulaire(b, this->angle);
    return ( (voisOk && distanceOk && champOk) || this->getBase()->jeTeVois(b));
}

void Yeux::toString() {
    std::ostringstream stream;
    stream = std::cout << this ;
    std::string str =  stream.str();
}

void Yeux::draw(UImg& support) {
    double angleMin = this->getOrientation() - this->angle/2;
    double angleMax = this->getOrientation() + this->angle/2;
    int x1 = this->getX() + this->distance * cos(angleMin);
    int y1 = this->getY() - this->distance * sin(angleMin);
    int x2 = this->getX() + this->distance * cos(angleMax);
    int y2 = this->getY() - this->distance * sin(angleMax);
    support.draw_line(this->getX(), this->getY(), x1, y1, this->getColor());
    support.draw_line(this->getX(), this->getY(), x2, y2, this->getColor());
    // Dessine deux lignes représentant le cone de vision
    this->getBase()->draw(support);
}

std::ostream& operator<<(std::ostream& flot , const Yeux& yeux) {
    flot << this->getBase() << "," << this->getName() << "," << yeux.distance << "," << yeux.angle <<< "," << yeux.capaciteDetection << "\n";
    return flot ;
}

