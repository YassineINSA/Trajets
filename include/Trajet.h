/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Représentation d'un trajet entre deux villes, avec une gestion de l'information de base sur le départ et l'arrivée.
//
// La classe `Trajet` est une classe de base qui modélise un trajet entre deux villes : une ville de départ et une ville d'arrivée.
// Elle contient les informations essentielles pour décrire un trajet simple, comme les noms des villes de départ et d'arrivée.
// La classe sert de base pour d'autres classes plus spécialisées, comme `TrajetSimple` et `TrajetCompose`.
//
// Un objet de la classe `Trajet` contient :
// - `depart` : le nom de la ville de départ du trajet.
// - `arrivee` : le nom de la ville d'arrivée du trajet.
// - `suivant` : un pointeur vers le prochain trajet dans une séquence de trajets (si applicable)
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Attributs publiques

//----------------------------------------------------- Méthodes publiques
    const char* GetDepart () const;
    // Renvoie la ville de départ du trajet.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - La ville de départ sous forme de chaîne de caractères (const char*).
    
    const char* GetArrivee () const;
    // Renvoie la ville d'arrivée du trajet.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - La ville d'arrivée sous forme de chaîne de caractères (const char*).

    Trajet* GetSuivant () const;
    // Renvoie le trajet suivant dans la liste des trajets.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Un pointeur vers le trajet suivant si présent, sinon un pointeur nul (nullptr).
    
    void SetSuivant (Trajet * trajet);
    // Modifie le trajet suivant dans la liste des trajets.
    // Paramètres :
    //   - trajet : un pointeur vers le trajet suivant à associer à l'objet actuel.
    // Retour :
    //   - Cette méthode ne retourne rien (void).
    
    virtual void Afficher () const = 0; 			
    // Méthode Virtuelle Pure

//------------------------------------------------- Surcharge d'opérateurs
    Trajet & operator = ( const Trajet & unTrajet );
    // Utilisation illicite de l'opérateur d'affectation.


//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Utilisation illicite du constructeur de copie.

    virtual ~Trajet ( );
    // Destructeur pour libérer les ressources allouées pour un trajet.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle libère la mémoire allouée pour les chaînes de caractères représentant les villes.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Constructeur protégé pour éviter création non autorisée d'une classe abstraite
    Trajet ( const char * villeDebut, const char * villeFin);
    // Constructeur pour créer un trajet avec une ville de départ et une ville d'arrivée.
    // Paramètres :
    //   - villeDebut : la ville de départ du trajet (chaîne de caractères).
    //   - villeFin : la ville d'arrivée du trajet (chaîne de caractères).
    // Retour :
    //   - Cette méthode ne retourne rien. Elle initialise un nouvel objet `Trajet` avec les villes spécifiées.

//----------------------------------------------------- Attributs protégés
    Trajet* suivant;
    char* depart;
    char* arrivee;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H

