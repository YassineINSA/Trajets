/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Catalogue::Ajouter ( Trajet * trajet )
// Ajoute un trajet à la collection et met à jour la taille du catalogue.
    // Paramètres :
    //   - trajet : un pointeur vers le trajet à ajouter à la collection.
    // Retour :
    //   - Cette méthode retourne un bool (true si l'insertion est réussi).
{
    Collection::Ajouter ( trajet );
    taille++;
    return true;
} //----- Fin de Méthode


void Catalogue::Afficher() const
// Affiche tous les trajets du catalogue. Si le catalogue est vide, affiche un message indiquant que le catalogue est vide.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle affiche les trajets du catalogue sur la sortie standard.
{
	Trajet* traj_parcours = debut;
	if ( traj_parcours == NULL )
	{
		cout<<"catalogue vide"<<endl;
		return;
	}
	while ( traj_parcours != NULL )
	{
		traj_parcours->Afficher();
		cout<<endl;
		traj_parcours = traj_parcours->GetSuivant();
	}
	return;
}


void Catalogue::Rechercher(const char* const dep, const char* const arr) const
// Recherche les trajets allant de la ville de départ (dep) à la ville d'arrivée (arr).
    // Paramètres :
    //   - dep : la ville de départ du trajet recherché (chaîne de caractères).
    //   - arr : la ville d'arrivée du trajet recherché (chaîne de caractères).
    // Retour :
    //   - Cette méthode ne retourne rien. Elle affiche les trajets trouvés, ou un message si aucun trajet n'est trouvé.
{
	Trajet* traj_parcours = debut;
	if ( traj_parcours == NULL )
	{
		cout << "Le catalogue est vide" << endl;
		return;
	}
	Trajet ** parcours = new Trajet*[taille];
	bool aucunTrajet = true;
	int indice = 0;
	Reccurrence(dep, arr, parcours, indice, aucunTrajet, dep);
	delete[] parcours;
	return;
}


void Catalogue::Reccurrence(const char* const dep, const char* const arr, Trajet ** parcours, int & indice, bool & aucunTrajet, const char* const departInitial) const
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
{
	int i;
	bool test_doublon = false;
	Trajet * traj_parcours = debut;
	while (traj_parcours != NULL)
	{
		if (strcmp(traj_parcours->GetDepart(), dep) == 0)
		{
			for (i=0; i<indice; i++)
			{
				if (parcours[i] == traj_parcours) 
				{
					test_doublon = true;
				}
			}
			if (not test_doublon)
			{
				parcours[indice]=traj_parcours;
				indice++;
				if (strcmp(traj_parcours->GetArrivee(), arr) == 0)
				{
					for (i=0; i<indice-1; i++)
					{
						parcours[i]->Afficher();
						cout << " -> ";
					}
					parcours[indice-1]->Afficher();
					cout << endl;
					aucunTrajet = false;
				}
				else
				{
					
					Reccurrence(traj_parcours->GetArrivee(), arr, parcours, indice, aucunTrajet, departInitial);
				}
				indice--;
			}
			else
			{
				test_doublon = false;
			}
		}
		traj_parcours=traj_parcours->GetSuivant();
	}
	if (indice == 0 && aucunTrajet)
	{
		cout << "Pas de trajet trouvé" << endl;
	}
	return;
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue () : Collection()
// Constructeur de la classe Catalogue. Initialise le catalogue avec une taille de zéro.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle initialise la taille à 0 et appelle le constructeur de la classe de base `Collection`.
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    taille = 0;
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Destructeur de la classe Catalogue. Cette méthode est appelée lorsque l'objet `Catalogue` est détruit.
    // Paramètres :
    //   - Aucun paramètre.
    // Retour :
    //   - Cette méthode ne retourne rien. Elle libère les ressources associées à l'objet catalogue.
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

