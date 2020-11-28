#include "Yeux.h"

bool Yeux::jeTeVois(const Bestiole & autre) const {
  bool jeVois = autre.getCamouflage() < this->capaciteDetection;
  bool distanceOk = this->plusProcheQue(autre, this->distance);
  bool dansArc = this->dansArcVue(autre, this->angle);
  return ( (jeVois && distanceOk && dansArc) || this->getBase()->jeTeVois(autre));
}