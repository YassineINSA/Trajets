CXXFLAGS = -ansi -pedantic -Wall -std=c++11

# Constante MAP pour vérifier appels au destructeurs/constructeurs
#CXXFLAGS += -D MAP

trajets: trajets.o TrajetCompose.o TrajetSimple.o Collection.o Trajet.o Catalogue.o
	g++ $(CXXFLAGS) -o trajets trajets.o TrajetCompose.o TrajetSimple.o Collection.o Trajet.o Catalogue.o
	
trajets.o: trajets.cpp
	g++ $(CXXFLAGS) -c trajets.cpp

Catalogue.o: Catalogue.cpp Catalogue.h
	g++ $(CXXFLAGS) -c Catalogue.cpp

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h
	g++ $(CXXFLAGS) -c TrajetCompose.cpp
	
TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h
	g++ $(CXXFLAGS) -c TrajetSimple.cpp
	
Collection.o: Collection.cpp Collection.h
	g++ $(CXXFLAGS) -c Collection.cpp
	
Trajet.o: Trajet.cpp Trajet.h
	g++ $(CXXFLAGS) -c Trajet.cpp
	
# Règle 'clean' pour supprimer les fichiers générés
clean:
	rm -f *.o test
