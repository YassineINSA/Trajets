/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool TrajetCompose::Ajouter (Trajet * const trajet)
// Ajoute un trajet à la collection.
    // Paramètres :
    //   - trajet : un pointeur vers le trajet à ajouter dans la collection.
    // Retour :
    //   - Cette méthode retourne un bool (true si l'insertion est réussi, false si elle est incohérente).
{
    if ((debut == NULL && strcmp(trajet->GetDepart(), depart) == 0) || (debut != NULL && strcmp(fin->GetArrivee(), trajet->GetDepart()) == 0))
    {
    	Collection::Ajouter ( trajet );
    	return true;
    }
    return false;
} //----- Fin de Méthode


void TrajetCompose::Afficher () const
// Affiche les trajets composant un trajet composé.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien (void). Elle affiche les informations des trajets qui composent le trajet composé.
{
    Trajet * p = debut;
    if (p!=NULL)
    {
    	p->Afficher();
    	p = p->GetSuivant();
    }
    while (p!=NULL)
    {
    	cout << " - "; 
    	p->Afficher();
    	p = p->GetSuivant();
    }
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (const char * const villeDebut, const char * const villeFin) : Trajet(villeDebut, villeFin)
// Constructeur pour créer un trajet composé avec une ville de départ et une ville d'arrivée.
    // Paramètres :
    //   - villeDebut : la ville de départ du trajet composé (chaîne de caractères).
    //   - villeFin : la ville d'arrivée du trajet composé (chaîne de caractères).
    // Retour :
    //   - Cette méthode ne retourne rien. Elle initialise un objet `TrajetCompose` avec les villes spécifiées et appelle le constructeur de la classe de base `Trajet`.
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Destructeur pour libérer les ressources allouées pour un trajet composé.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle nettoie les ressources associées à l'objet `TrajetCompose`.
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

