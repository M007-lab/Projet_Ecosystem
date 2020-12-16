CFLAGS= -Wall

BASE = Aquarium.o Milieu.o Configuration.o FactoryBestiole.o 
# BASE = Configuration.o FactoryBestiole.o AccessoireDecorateur.o CapteurDecorateur.o  
DECORATEUR = Bestiole.o  ConcreteBestiole.o  RandomInt.o RandomDouble.o AccessoireDecorateur.o CapteurDecorateur.o
ACCESOIRE = Oreille.o Yeux.o Nageoire.o Camouflage.o Carapace.o
COMPORTEMENT = BestioleSimple.o Gregaire.o Kamikaze.o Multiple.o Peureuse.o Prevoyante.o

H_BASE = Aquarium.h Milieu.h Configuration.h FactoryBestiole.h 
H_DECORATEUR = Bestiole.h  ConcreteBestiole.h RandomInt.h RandomDouble.h  Comportement.h RandomUtils.h AccessoireDecorateur.h CapteurDecorateur.h
H_COMPORTEMENT = BestioleSimple.h Gregaire.h Kamikaze.h Multiple.h Peureuse.h Prevoyante.h
H_ACCESOIRE =  Oreille.h Yeux.h Nageoire.h Camouflage.h Carapace.h

CPP_BASE = Aquarium.cpp Milieu.cpp Configuration.cpp FactoryBestiole.cpp 
CPP_DECORATEUR = Bestiole.cpp  ConcreteBestiole.cpp RandomInt.cpp RandomDouble.cpp  AccessoireDecorateur.cpp CapteurDecorateur.cpp
CPP_COMPORTEMENT = BestioleSimple.cpp Gregaire.cpp Kamikaze.cpp Multiple.cpp Peureuse.cpp Prevoyante.cpp
CPP_ACCESOIRE =  Oreille.cpp Yeux.cpp Nageoire.cpp Camouflage.cpp Carapace.cpp



main: main.o $(BASE) $(COMPORTEMENT) $(DECORATEUR) $(ACCESOIRE)
	g++ $(CFLAGS) -o main  main.o  $(BASE) $(COMPORTEMENT) $(DECORATEUR) $(ACCESOIRE) -I . -lX11 -lpthread 
# main.o: main.cpp $(H_DECORATEUR)
# 	g++ $(CFLAGS) -c main.cpp
# test : Test.o FactoryBestiole.o $(COMPORTEMENT) $(DECORATEUR) $(ACCESOIRE)
# 	g++ $(CFLAGS) -o test  Test.o FactoryBestiole.o $(COMPORTEMENT) $(DECORATEUR) $(ACCESOIRE) -I . -lX11 -lpthread

# Test.o: Test.cpp FactoryBestiole.h 
# 	g++ $(CFLAGS) -c  Test.cpp   


	
testAccessoire : testAccessoire.o  $(BASE) $(COMPORTEMENT) $(ACCESOIRE) $(DECORATEUR)
	g++ $(CFLAGS) -o  testAccessoire testAccessoire.o $(BASE) $(COMPORTEMENT) $(DECORATEUR) $(ACCESOIRE) -I . -lX11 -lpthread 
# testAccessoire.o: testAccessoire.cpp  $(H_BASE) $(H_ACCESOIRE)
# 	g++ $(CFLAGS) -c  testAccessoire.cpp   
# testCapteur : testCapteur.o $(BASE) $(COMPORTEMENT) $(DECORATEUR) $(ACCESOIRE)
# 	g++ $(CFLAGS) -o testCapteur  testCapteur.o $(BASE) $(COMPORTEMENT) $(DECORATEUR) $(ACCESOIRE) -I . -lX11 -lpthread

# testCapteur.o: testCapteur.cpp  $(H_BASE) $(H_ACCESOIRE)
# 	g++ $(CFLAGS) -c  testCapteur.cpp   
# FactoryBestiole.o : FactoryBestiole.cpp Factory.h $(H_COMPORTEMENT) $(H_DECORATEUR) $(H_ACCESOIRE)
# 	g++ $(CFLAGS)  -c FactoryBestiole.cpp -I .


%.o : %.cpp %.h
	g++ $(CFLAGS)  -c $< -I .

clean:
	$(RM) *.o; rm test


# rm main





