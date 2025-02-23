/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Représentation d'un trajet entre deux villes en utilisant un mode de transport spécifique.
//
// La classe `TrajetSimple` dérive de la classe `Trajet` et représente un trajet simple entre deux villes (une ville de départ et une ville
// d'arrivée) en utilisant un mode de transport particulier (par exemple, train, avion, voiture, etc.). Elle étend la classe de base `Trajet` en 
// ajoutant une information supplémentaire concernant le mode de transport utilisé.
//
// Un objet de la classe `TrajetSimple` contient :
// - `transport` : une chaîne de caractères représentant le mode de transport utilisé pour ce trajet (ex. "Train", "Avion", "Voiture").
// - `suivant` : un pointeur vers le prochain trajet dans une séquence de trajets (si applicable) (hérité de la classe `Trajet`).
// - `depart` : le nom de la ville de départ (hérité de la classe `Trajet`).
// - `arrivee` : le nom de la ville d'arrivée (hérité de la classe `Trajet`).
//
// Les principales fonctionnalités de la classe sont :
// - La possibilité d'afficher le trajet complet, y compris le mode de transport, en utilisant la méthode `Afficher`.
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
    char* transport;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    void Afficher() const;
    // Affiche le trajet simple en indiquant la ville de départ, la ville d'arrivée et le mode de transport.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien (void). Elle affiche les informations du trajet simple sur la sortie standard.


//------------------------------------------------- Surcharge d'opérateurs
    TrajetSimple & operator = ( const TrajetSimple & unTrajetSimple );
    // Utilisation illicite de l'opérateur d'affectation.

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple);
    // Utilisation illicite du constructeur de copie.

    TrajetSimple (const char* modeTransport, const char* dep, const char* arr) ;
    // Constructeur pour créer un trajet simple avec un mode de transport, une ville de départ et une ville d'arrivée.
    // Paramètres :
    //   - modeTransport : le mode de transport utilisé (chaîne de caractères).
    //   - dep : la ville de départ du trajet (chaîne de caractères).
    //   - arr : la ville d'arrivée du trajet (chaîne de caractères).
    // Retour :
    //   - Cette méthode ne retourne rien. Elle initialise un objet `TrajetSimple` avec les valeurs fournies pour le mode de transport, la ville de départ et la ville d'arrivée.

    virtual ~TrajetSimple ();
    // Destructeur pour libérer les ressources allouées pour un trajet simple.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle libère la mémoire allouée pour le mode de transport du trajet simple.

//------------------------------------------------------------------ PRIVE


//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

