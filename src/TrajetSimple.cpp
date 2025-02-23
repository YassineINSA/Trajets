/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher() const
// Affiche le trajet simple en indiquant la ville de départ, la ville d'arrivée et le mode de transport.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien (void). Elle affiche les informations du trajet simple sur la sortie standard.
{
	cout<<"De "<< depart << " à "<< arrivee << " en "<< transport;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const char* modeTransport, const char* dep, const char* arr) : Trajet(dep, arr)
// Constructeur pour créer un trajet simple avec un mode de transport, une ville de départ et une ville d'arrivée.
    // Paramètres :
    //   - modeTransport : le mode de transport utilisé (chaîne de caractères).
    //   - dep : la ville de départ du trajet (chaîne de caractères).
    //   - arr : la ville d'arrivée du trajet (chaîne de caractères).
    // Retour :
    //   - Cette méthode ne retourne rien. Elle initialise un objet `TrajetSimple` avec les valeurs fournies pour le mode de transport, la ville de départ et la ville d'arrivée.
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
	size_t len_transp=strlen(modeTransport);
	transport = new char[len_transp+1];
	strcpy(transport, modeTransport);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Destructeur pour libérer les ressources allouées pour un trajet simple.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle libère la mémoire allouée pour le mode de transport du trajet simple.
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
	delete [] transport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

