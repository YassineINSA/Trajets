/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char* Trajet::GetDepart () const
// Renvoie la ville de départ du trajet.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - La ville de départ sous forme de chaîne de caractères (const char*).
{
        return depart;
}


const char* Trajet::GetArrivee () const
// Renvoie la ville d'arrivée du trajet.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - La ville d'arrivée sous forme de chaîne de caractères (const char*).
{
        return arrivee;
}

Trajet* Trajet::GetSuivant () const
// Renvoie le trajet suivant dans la liste des trajets.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Un pointeur vers le trajet suivant si présent, sinon un pointeur nul (nullptr).
{
        return suivant;
}

void Trajet::SetSuivant (Trajet * trajet) 
// Modifie le trajet suivant dans la liste des trajets.
    // Paramètres :
    //   - trajet : un pointeur vers le trajet suivant à associer à l'objet actuel.
    // Retour :
    //   - Cette méthode ne retourne rien (void).
{
        suivant = trajet;
        return;
}

//-------------------------------------------- Constructeurs - destructeur
Trajet::~Trajet ( )
// Destructeur pour libérer les ressources allouées pour un trajet.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle libère la mémoire allouée pour les chaînes de caractères représentant les villes.
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
	delete [] depart;
	delete [] arrivee;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
Trajet::Trajet ( const char * villeDebut, const char * villeFin)
// Constructeur pour créer un trajet avec une ville de départ et une ville d'arrivée.
    // Paramètres :
    //   - villeDebut : la ville de départ du trajet (chaîne de caractères).
    //   - villeFin : la ville d'arrivée du trajet (chaîne de caractères).
    // Retour :
    //   - Cette méthode ne retourne rien. Elle initialise un nouvel objet `Trajet` avec les villes spécifiées.
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    size_t len_vDeb=strlen(villeDebut);
    size_t len_vFin=strlen(villeFin);
    depart=new char[len_vDeb+1];
    arrivee=new char[len_vFin+1];
    strcpy(depart, villeDebut);
    strcpy(arrivee, villeFin);
    suivant = NULL;
} //----- Fin de Trajet
