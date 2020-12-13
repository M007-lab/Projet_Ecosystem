SYSTEM = Aquarium.o Milieu.o Configuration.o FactoryBestiole.o RandGenerator.o 
DECORATEUR = Bestiole.o  AccesoireDecorateur.o CapteurDecorateur.o Oreille.o Yeux.o Nageoire.o Camouflage.o Carapace.o
COMPORTEMENT = BestioleSimple.o Gregaire.o Kamikaze.o Multiple.o Peureuse.o Prevoyante.o

main : main.cpp $(SYSTEM) $(COMPORTEMENT) $(DECORATEUR)
	g++ -Wall -std=c++11 -o main main.cpp $(SYSTEM) $(COMPORTEMENT) $(DECORATEUR)  -I . -lX11 -lpthread

%.o : %.cpp %.h
	g++ -Wall -std=c++11  -c $< -I .

clean:
	rm *.o; rm main

# Aquarium.o : Aquarium.h Aquarium.cpp
# 	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

# Bestiole.o : Bestiole.h Bestiole.cpp
# 	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

# Milieu.o : Milieu.h Milieu.cpp
# 	g++ -Wall -std=c++11  -c Milieu.cpp -I .

