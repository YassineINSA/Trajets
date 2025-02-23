using namespace std;
#include <iostream>
#include <cstring>
#include <limits>
#include "Trajet.h"
#include "Collection.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

void ajouterTrajetSimple(Catalogue*  cat);
void ajouterTrajetCompose(Catalogue* cat);
void afficher(Catalogue*  cat);
void rechercher(Catalogue* cat);
void destroy(Catalogue* cat);


int main() {
    int choix;
    Catalogue* cat= new Catalogue();
    while (true) 
    {
        // Affichage du menu
        cout << "Menu:" << endl;
        cout << "\t1: Ajouter trajet simple" << endl;
        cout << "\t2: Ajouter trajet composé" << endl;
        cout << "\t3: Afficher tous les trajets" << endl;
        cout << "\t4: Rechercher" << endl;
        cout << "\t0: Quitter" << endl;

        // Lecture du choix de l'utilisateur
        cin >> choix;

        // Traitement selon le choix
        switch(choix) 
        {
            case 0:
            	destroy(cat);
                cout << "Au revoir" << endl;
               
                return 0; // Sortie du programme
            case 1:
                ajouterTrajetSimple(cat);
                
                break;
            case 2:
                ajouterTrajetCompose(cat);
                break;
            case 3:
                afficher(cat);
                break;
            case 4:
                rechercher(cat);
                break;
            default:
                cout << "Choix incorrect" << endl;
                break; // Revenir au menu sans faire d'autres actions
        }
    }
    
}

void ajouterTrajetSimple(Catalogue*  cat)
{
	char transport[25]; 
	char VilleDep[25]; 
	char VilleArr[25];
	
	/*strcpy (transport,"Voiture");
	strcpy (VilleDep,"Lyon");
	strcpy (VilleArr,"Paris");
	cout<<transport<<endl;
	cout<<VilleDep<<endl;
	cout<<VilleArr<<endl;*/
	
	cout << "Donnez la ville de départ : "<<endl;
    	cin >> VilleDep;
    	cout << "Donnez la ville d'arrivée : "<<endl;
    	cin >> VilleArr;
    	while (strcmp(VilleArr,VilleDep)==0)
        {
	    	cout<<"Erreur : ville de départ et de destination identiques, veuillez entrer une destination différente"<<endl;
	    	cin>>VilleArr;
        }
    	cout << "Donnez le moyen de transport : "<<endl;
    	cin >> transport;
    	TrajetSimple * ts = new TrajetSimple(transport, VilleDep, VilleArr);
    	
	cat->Ajouter(ts);
	
}

//forcer un trajet simple déjà
//bug erreur cin
void ajouterTrajetCompose(Catalogue* cat)
{
    char VilleDep[25]; 
    char VilleArr[25];
    cout << "Donnez une ville de départ du trajet composé : "<<endl;
    cin >> VilleDep;
    cout << "Donnez une ville d'arrivée finale du trajet composé : "<<endl;
    cin >> VilleArr;
    while (strcmp(VilleArr, VilleDep)==0)
    {
    	cout<<"Erreur : Villes de départ et de destination identiques, veuillez entrer une destination finale différente"<<endl;
    	cin>>VilleArr;
    }
    TrajetCompose * tc = new TrajetCompose(VilleDep, VilleArr);
    cout<<"Un trajet composé avec pour départ "<<VilleDep<<" et pour destination finale "<<VilleArr<<" a été créé, remplissons-le par des trajets simples : "<<endl;
    char VilleDebut[25];
    char VilleFin[25];
    char transport[25]; 
    strcpy(VilleDebut, VilleDep);
    cout<<endl;
    cout << "Construisons son premier trajet simple en partant de "<<VilleDebut<<endl;
    cout << "Donnez une ville d'arrivée pour ce trajet simple : "<<endl;
    cin >> VilleFin;
    while (strcmp(VilleFin,VilleArr)==0 || strcmp(VilleFin, VilleDebut)==0 )
    {
    	if (strcmp(VilleFin,VilleArr)==0)
    	{
    		cout<<"Erreur : Vous ne pouvez pas donner la destination finale directement dans le premier trajet simple. Veuillez entrer une autre arrivée (escale)"<<endl;
    		cin>>VilleFin;
    	}
    	else if (strcmp(VilleFin, VilleDebut)==0)
    	{
    		cout<<"Erreur : villes de départ et de destination du trajet simple identiques, veuillez entrer une arrivée différente"<<endl;
    		cin>>VilleFin;
    	}
    }
    cout << "Donnez le moyen de transport : "<<endl;
    cin >> transport;
    TrajetSimple * ts = new TrajetSimple(transport, VilleDebut, VilleFin);
    tc->Ajouter(ts); 
    strcpy(VilleDebut, VilleFin);
    cout<<endl;
    while (strcmp(VilleFin, VilleArr)!=0) 
    {
    	
        cout<<"Nouveau trajet simple dans ce trajet composé: "<<endl;
	cout << "Donnez une ville d'arrivée pour ce nouveau trajet simple en partant de : "<<VilleDebut<<endl;
	cin >> VilleFin;
	while (strcmp(VilleFin, VilleDebut)==0 || strcmp(VilleFin, VilleDep)==0)
        {
        	if (strcmp(VilleFin, VilleDebut)==0)
        	{
			cout<<"Erreur : villes de départ et de destination du trajet simple identiques, veuillez entrer une arrivée différente"<<endl;
			cin>>VilleFin;
		}
		else if (strcmp(VilleFin, VilleDep)==0)
		{
			cout<<"Erreur : ville de départ du trajet composé et ville de destination du trajet simple identiques, veuillez entrer une arrivée différente"<<endl;
			cin>>VilleFin;
		}
        }
	cout << "Donnez le moyen de transport : "<<endl;
	cin >> transport;
	TrajetSimple * ts = new TrajetSimple(transport, VilleDebut, VilleFin);
	tc->Ajouter(ts);
	strcpy(VilleDebut, VilleFin);
        cout<<endl;
        
    }
    cat->Ajouter(tc);
}


void afficher(Catalogue* cat)
{
	cat->Afficher();
}


void rechercher(Catalogue* cat)
{
	
	char a[25], b[25];
    	cout << "Donnez le départ à rechercher : "<<endl;
    	cin >> a;
    	cout << "Donnez l'arrivée à rechercher : "<<endl;
    	cin >> b;
    	size_t len_a=strlen(a);
    	size_t len_b=strlen(b);
    	char* depart= new char [len_a+1];
    	char* arrivee=new char [len_b+1];
    	strcpy(depart, a);
    	strcpy(arrivee, b);
    	cout<<"Les résultats obtenus sont : "<<endl;
	cat->Rechercher(depart, arrivee);
	delete [] depart;
	delete [] arrivee;
	
}

void destroy(Catalogue* cat)
{
	delete cat;
}
