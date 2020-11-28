bool Oreille::jeTeVois(const Bestiole & autre) const {
  bool jeVois = autre.getCamouflage() < this->capaciteDetection;
  bool distanceOk = this->plusProcheQue(autre, this->distance);
  return ( (jeVois && distanceOk) || this->getBase()->jeTeVois(autre));
}