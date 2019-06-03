/*

Exercice 1​ : Arbre en langage C
Définition 1: Le niveau d’un nœud, autre que la racine, est égal au niveau de son
père plus 1. Le niveau de la racine est supposé = 1.
Définition 2: un arbre binaire est complet (ABC) si chaque nœud autre que les
feuilles possède 2 descendants et si toutes les feuilles sont au même niveau.
1) Donnez la taille (nombre de nœuds) d’un ABC en fonction du niveau de ses
feuilles k.
2) Ecrire une fonction récursive qui vérifie si un arbre binaire est un ABC.

*/
typedef struct noeud arbre;
struct noeud
{
	int  element;
	struct noeud * G;
	struct noeud * D;
} ;

int estABC(arbre * R){
	if (R)
	{
		if (R->G && R->D)
			return(estABC(R->G)*estABC(R->D))	
		else if(!R->G && !R->D)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}	

/*
Exercice 2 ​ : Arbre en langage C
On considère la fonction suivante :
void fonc(struct nœud * t)
{
Pile p ;}
Initialser_pile(&p) ;
Empiler(t) ;
While ( !pilevide(p))
{
t=depiler(&p) ;
traiter(t) ;
if (t->D) empiler(&p,t->D) ;
if (t->G) empiler(&p,t->G) ;
}
1) Donnez l’état de la pile après chaque changement de celle-ci sur l’arbre ci-dessus et en
supposant que t représente la racine de l’arbre.
2) Déduire ce que fait cette fonction et en donner une version récursive.
*/

void preordreRec1(noeud_t * Racine)
{
	if (Racine)
	{
		traiter(Racine->element);
		preordreRec1(Racine->gauche);
		preordreRec1(Racine->droit);
	}
}


/*
arbre généalogique 2012
*/

Struct Noeud { 
	char nom[20] ;
	struct Noeud *fils ; // gauche
	struct Noeud *frere ; // droite
}


void enfants(Noeud * parent){
	Noeud * Fils = parent->fils ;
	char nomPere[20] = parent->nom ;

	if (!Fils)
	{
	 	printf("%s désolé n'a pas de fils \n", nomPere);
	} 
	else{
		while(Fils){
			printf("%s est fils de %s \n", Fils->nom, nomPere);
			Fils = Fils->frere ;
		}	
	}
}
#include<stdlib.h>
#include<string.h>

void insererNVN(Noeud ** R, char NM[20], char NVN[20]){
	
	Noeud * nvn, * Frere;
	nvn->frere = NULL;
	nvn->fils = NULL;
	strcpy(nvn->nom, NVN);
	Frere = (*R->fils)->frere;

	if (R)
	{
		if (strcmp(*R->nom,NM))
		{
			if (*R->fils)
			{
				while(Frere)
					Frere = Frere->frere ;
				Frere = nvn ;
			}
			else
				Frere = nvn;
		break ;
		}
		else{
			insererNVN(&(*R)->fils, NM, NVN);
			insererNVN(&(*R)->frere, NM, NVN);
		}
	}
	
}

/*
Examen 2013
Exercice 1​ : Listes (deja envoyé)
a) Ecrire une fonction qui scinde une liste chainée L d’entiers en deux listes L et L’, la
1​ ère contiendra les entiers de rang pair et la 2​ ème contiendra les entiers de rang
impair, sans création de nouvelle liste comme le montre l’exemple ci-dessous. (​ 6 pts)
Liste initiale :
L
Résultat de la fonction :
L
L’
b) Ecrire une fonction récursive qui libère tous les éléments d’une liste chainée d’entiers
donnée. ​ (4 pts)
*/

typedef struct simple simple_t;
struct simple
{
	int E;
	struct simple * suiv ;
};
simple_t * insererFin(simple_t * L, int i)
{
	simple_t * noeud, * P ;
	if((noeud = (simple_t *) malloc(sizeof(simple_t))))
	{
		noeud -> E = i ;
		noeud -> suiv = NULL ;
		if (L == NULL)
		{
			L = noeud ;
		}
		else
		{
			P = L;
			while(P -> suiv != NULL)
			{
				P = P -> suiv ;
			}
			P -> suiv = noeud;
		}	
	return L ;	
	}	
}


simple_t * scinde(simple_t ** L){
	simple_t * L’ ;
	simple_t * P = *L;

	while(P){
		if (P->E % 2 ==0 )
		{
			P = P->suiv;
		}
		else{
			L’ = insererFin(L’, P->E)
			P = P->suiv;
			*L->suiv = (*L->suiv)->suiv;
		}

	}
	return L’;

}






