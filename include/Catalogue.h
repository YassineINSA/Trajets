/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H 

//--------------------------------------------------- Interfaces utilisées
#include "Collection.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Représentation d'un ensemble de trajets.
//
// Un catalogue est constitué d'une liste de trajets, qui peut être un mélange de trajets simples et composés.
// Cette classe hérite de la classe Collection, lui permettant de gérer la liste des trajets à l'aide des pointeurs "debut" et "fin",
// qui marquent respectivement le début et la fin de la liste de trajets.
// Le catalogue permet de manipuler cette liste de trajets en ajoutant de nouveaux trajets,
// en affichant la collection entière, ou en recherchant des trajets correspondant à des critères précis (par exemple, départ et arrivée).
// 
// Attributs et héritage :
// - Hérite de la classe Collection : fournit les fonctionnalités de gestion de la liste de trajets (ajout, navigation, etc.).
// - taille : un entier qui garde la trace du nombre de trajets dans le catalogue. Cet attribut est mis à jour chaque fois qu'un trajet est ajouté.
// 
// Méthodes principales :
// - Ajouter(Trajet* trajet) : permet d'ajouter un trajet à la fin du catalogue et met à jour l'attribut `taille`.
// - Afficher() : affiche tous les trajets présents dans le catalogue, un par un.
// - Rechercher(dep, arr) : recherche tous les trajets allant d'une ville de départ à une ville d'arrivée, en affichant les trajets correspondants.
// - Reccurrence(dep, arr) : méthode auxiliaire utilisée dans la recherche pour gérer la recherche de trajets multiples reliant deux villes.
//
//------------------------------------------------------------------------

class Catalogue : public Collection
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Ajouter (Trajet * trajet );
    // Ajoute un trajet à la collection et met à jour la taille du catalogue.
    // Paramètres :
    //   - trajet : un pointeur vers le trajet à ajouter à la collection.
    // Retour :
    //   - Cette méthode retourne un bool (true si l'insertion est réussi).
    
    void Afficher() const;
    // Affiche tous les trajets du catalogue. Si le catalogue est vide, affiche un message indiquant que le catalogue est vide.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle affiche les trajets du catalogue sur la sortie standard.

    void Rechercher(const char* const dep, const char* const arr) const;
    // Recherche les trajets allant de la ville de départ (dep) à la ville d'arrivée (arr).
    // Paramètres :
    //   - dep : la ville de départ du trajet recherché (chaîne de caractères).
    //   - arr : la ville d'arrivée du trajet recherché (chaîne de caractères).
    // Retour :
    //   - Cette méthode ne retourne rien. Elle affiche les trajets trouvés, ou un message si aucun trajet n'est trouvé.
    
    void Reccurrence(const char* const dep, const char* const arr, Trajet ** parcours, int & indice, bool & aucunTrajet, const char* const debut) const;
    // Méthode récursive utilisée pour rechercher des trajets composés entre deux villes. 
    // Elle construit la chaîne de trajets successifs et évite les doublons.
    // Paramètres :
    //   - dep : la ville de départ du trajet actuel (chaîne de caractères).
    //   - arr : la ville d'arrivée du trajet recherché (chaîne de caractères).
    //   - parcours : un tableau qui garde trace des trajets déjà parcourus pour éviter les doublons.
    //   - indice : l'index actuel dans le tableau des trajets trouvés.
    //   - aucunTrajet : un booléen qui indique si un trajet a été trouvé.
    //   - departInitial : la ville de départ initiale pour détecter les boucles et éviter la recherche infinie.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle affiche les trajets successifs trouvés, ou un message si aucun trajet n'est trouvé.


//------------------------------------------------- Surcharge d'opérateurs
    Catalogue & operator = ( const Catalogue & unCatalogue );
    // Utilisation illicite de l'opérateur d'affectation.

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Utilisation illicite du constructeur de copie.

    Catalogue ( );
    // Constructeur de la classe Catalogue. Initialise le catalogue avec une taille de zéro.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle initialise la taille à 0 et appelle le constructeur de la classe de base `Collection`.

    virtual ~Catalogue ( );
    // Destructeur de la classe Catalogue. Cette méthode est appelée lorsque l'objet `Catalogue` est détruit.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle libère les ressources associées à l'objet catalogue.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int taille;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H

