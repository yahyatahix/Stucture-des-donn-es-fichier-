#include <stdio.h>
#include<stdlib.h>


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
	simple_t * Li = NULL ;
	simple_t * P = *L;

	while(P){
		if (P->E % 2 ==0 )
		{
			P = P->suiv;
		}
		else{
			Li = insererFin(Li, P->E);
			P = P->suiv;
			(*L)->suiv = ((*L)->suiv)->suiv;
		}

	}
	return Li;

}