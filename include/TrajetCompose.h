/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Collection.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Représentation d'un itinéraire composé de plusieurs trajets entre des villes.
//
// Elle hérite de la classe Trajet pour gérer les informations de départ, d'arrivée, et du pointeur vers le trajet suivant,
// ainsi que de la classe Collection pour gérer la liste des trajets. Un trajet composé permet donc de représenter une
// chaîne de trajets.
// La classe permet de gérer la composition de l'itinéraire et d'afficher l'ensemble du parcours.
// 
// Attributs et héritage :
// - Hérite de la classe Trajet : contient les informations de départ, d'arrivée, et le pointeur suivant vers un autre trajet.
// - Hérite de la classe Collection : permet de gérer une liste de trajets, avec les pointeurs "debut" et "fin" qui marquent respectivement
//   le premier et le dernier trajet de la séquence.
// 
// Méthodes principales :
// - Afficher() : permet d'afficher le trajet composé en parcourant tous les trajets simples qu'il contient, séparés par " - ".
// - Constructeurs et destructeur : initialisation et nettoyage des ressources liées à la création et la destruction d'un trajet composé.
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet, public Collection
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Ajouter (Trajet * const trajet); 
    // Ajoute un trajet à la collection.
    // Paramètres :
    //   - trajet : un pointeur vers le trajet à ajouter dans la collection.
    // Retour :
    //   - Cette méthode retourne un bool (true si l'insertion est réussi, false si elle est incohérente).
    
    void Afficher () const;
    // Affiche les trajets composant un trajet composé.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien (void). Elle affiche les informations des trajets qui composent le trajet composé.

//------------------------------------------------- Surcharge d'opérateurs
    TrajetCompose & operator = ( const TrajetCompose & unTrajetCompose );
    // Utilisation illicite de l'opérateur d'affectation.

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( const TrajetCompose & TrajetCompose );
    // Utilisation illicite du constructeur de copie.

    TrajetCompose (const char * villeDebut, const char * villeFin);
    // Constructeur pour créer un trajet composé avec une ville de départ et une ville d'arrivée.
    // Paramètres :
    //   - villeDebut : la ville de départ du trajet composé (chaîne de caractères).
    //   - villeFin : la ville d'arrivée du trajet composé (chaîne de caractères).
    // Retour :
    //   - Cette méthode ne retourne rien. Elle initialise un objet `TrajetCompose` avec les villes spécifiées et appelle le constructeur de la classe de base `Trajet`.


    virtual ~TrajetCompose ( );
    // Destructeur pour libérer les ressources allouées pour un trajet composé.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle nettoie les ressources associées à l'objet `TrajetCompose`.


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H

