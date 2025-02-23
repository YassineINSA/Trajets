/*************************************************************************
                           Collection  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Collection> (fichier Collection.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Collection.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Collection::Ajouter (Trajet * const trajet)
// Ajoute un trajet à la collection.
    // Paramètres :
    //   - trajet : un pointeur vers le trajet à ajouter dans la collection.
    // Retour :
    //   - Cette méthode retourne un bool (true si l'insertion est réussi).
{
    if (debut == NULL)
    {
    	debut = trajet;
    }
    else
    {
    	fin->SetSuivant(trajet);
    }
    fin = trajet;
    return true;
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Collection::~Collection ( )
// Destructeur pour libérer les ressources allouées pour la collection.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle supprime tous les trajets dans la collection.
{
#ifdef MAP
    cout << "Appel au destructeur de <Collection>" << endl;
#endif
    Trajet * trajet1 = debut;
    Trajet * trajet2 = debut;
    while (trajet2 != NULL)
    {
    	 trajet2 = trajet2->GetSuivant();
    	 delete trajet1;
    	 trajet1 = trajet2;	
    }
} //----- Fin de ~Collection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
Collection::Collection ( )
// Constructeur par défaut pour initialiser une collection vide.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle initialise une collection vide avec des pointeurs `debut` et `fin` à `NULL`.
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif
    fin = NULL;
    debut = NULL;
} //----- Fin de Collection
