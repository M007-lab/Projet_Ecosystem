CFLAGS= -c -Wall

BASE = Aquarium.o Milieu.o Configuration.o FactoryBestiole.o RandGenerator.o 
DECORATEUR = Bestiole.o  ConcreteBestiole.o AccessoireDecorateur.o CapteurDecorateur.o Oreille.o Yeux.o Nageoire.o Camouflage.o Carapace.o
COMPORTEMENT = BestioleSimple.o Gregaire.o Kamikaze.o Multiple.o Peureuse.o Prevoyante.o
all: clean simul %.o
simul : main.o $(BASE) $(COMPORTEMENT) $(DECORATEUR)
	g++ $(CFLAGS) -o simul main.o $(BASE) $(COMPORTEMENT) $(DECORATEUR)  -I . -lX11 -lpthread

%.o : %.cpp %.h
	g++ $(CFLAGS)  -c $< -I .

clean:
	$(RM) *.o
# rm main



