/*************************************************************************
                           Collection  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Collection> (fichier Collection.h) ----------------
#if ! defined ( COLLECTION_H )
#define COLLECTION_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Collection>
// Représentation d'une collection de trajets, permettant de stocker et de gérer une liste chaînée de trajets.
//
// La classe `Collection` sert à gérer un ensemble de trajets sous forme d'une liste chaînée. Elle permet d'ajouter des trajets à la collection,
// d'accéder à l'ensemble des trajets et de parcourir la liste de manière itérative. Cette classe constitue la base de la gestion des trajets 
// dans l'application, en offrant une structure flexible pour maintenir et manipuler une série de trajets.
//
// Un objet de la classe `Collection` contient :
// - `debut` : un pointeur vers le premier trajet de la collection (début de la liste chaînée).
// - `fin` : un pointeur vers le dernier trajet de la collection (fin de la liste chaînée).
//
// Les principales fonctionnalités de la classe sont :
// - Ajouter un trajet à la collection via la méthode `Ajouter`.
// - Parcourir et accéder aux trajets via les pointeurs `debut` et `fin`.
// - Gérer la mémoire de la collection en libérant les ressources associées aux trajets via le destructeur.
//
// La classe `Collection` est utilisée comme un conteneur générique pour stocker des objets `Trajet`.
//
//------------------------------------------------------------------------

class Collection 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Ajouter (Trajet * const trajet); 
    // Ajoute un trajet à la collection.
    // Paramètres :
    //   - trajet : un pointeur vers le trajet à ajouter dans la collection.
    // Retour :
    //   - Cette méthode retourne un bool (true si l'insertion est réussi).

    virtual void Afficher () const = 0; 			
    // Méthode Virtuelle Pure

//------------------------------------------------- Surcharge d'opérateurs
    Collection & operator = ( const Collection & unCollection );
    // Utilisation illicite de l'opérateur d'affectation.

//-------------------------------------------- Constructeurs - destructeur
    Collection ( const Collection & unCollection );
    // Utilisation illicite du constructeur de copie.

    virtual ~Collection ( );
    // Destructeur pour libérer les ressources allouées pour la collection.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle supprime tous les trajets dans la collection.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Constructeur protégé pour éviter création non autorisée d'une classe abstraite
    Collection ( );
    // Constructeur par défaut pour initialiser une collection vide.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle initialise une collection vide avec des pointeurs `debut` et `fin` à `NULL`.

//----------------------------------------------------- Attributs protégés
    Trajet * debut;
    Trajet * fin;
};

//-------------------------------- Autres définitions dépendantes de <Collection>

#endif // COLLECTION_H

