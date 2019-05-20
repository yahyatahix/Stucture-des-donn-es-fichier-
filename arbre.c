#include<stdlib.h>

#define MAX 50
typedef struct info info_t;
struct info
{
	int a;
};

typedef struct noeud noeud_t;
struct noeud
{
	int  element;
	struct noeud * gauche;
	struct noeud * droit;
} ;
typedef struct {
	noeud_t  * T[MAX];
	int s;
} Pile;

void initPile(Pile *P){
	P->s = -1 ;

}

int estVide(Pile P){
	return (P.s == -1 );
}

int estPleine(Pile P){
	return (P.s == MAX - 1);
}

int empiler(Pile * P, noeud_t * E){
	if (!estPleine(*P))
	{
		P -> s++ ;
		P -> T[P -> s] = E ;
		return 1 ;
	}
	return 0 ;

}

int depiler(Pile * P, noeud_t * E){
	if (!estVide(*P))
	{
		E = P -> T[P -> s];
		P -> s -- ;
		return 1;
	}
	return 0 ;
}
void traiter(int element){

}

noeud_t * instancier(int  don, noeud_t * G, noeud_t * D)
{
	noeud_t * nouv;
	if (nouv = (noeud_t *) malloc(sizeof(noeud_t)))
	{
		nouv->element = don;
		nouv->gauche = G;
		nouv->droit = D;
	}
	return (nouv);
}

int nbNoeudsRec(noeud_t * R)
{ 
	if (!R) 
		return 0;
	else 
		return (1 + nbNoeudsRec(R->gauche) + nbNoeudsRec(R->droit));
}

int nbNoeudsIter(noeud_t * R)
{
	int t=0;
	Pile *P;
	initPile(P);
	while (R || !estVide(*P))
	{ 
		while (R)
		{ 
			t++;
			empiler(P,R); 
			R = R->gauche;
		}
		depiler(P,R);
		R = R->droit;
	}
	return t;
}

int feuille(noeud_t * N)
{
	return 
		(!N->gauche && !N->droit);
}
int nbFeuillesRec(noeud_t * R)
{
	if (!R) 
		return 0;
	else 
		if (feuille(R)) 
			return 1;
	else
		return(nbFeuillesRec(R->gauche)+nbFeuillesRec(R->droit));
}

void preordreRec1(noeud_t * Racine)
{
	if (Racine)
	{
		traiter(Racine->element);
		preordreRec1(Racine->gauche);
		preordreRec1(Racine->droit);
	}
}
void preordreRec2(noeud_t * R)
{ 
	while (R)
	{
	 	traiter(R->element);
		preordreRec2(R->gauche);
		R = R->droit;
	}
}
void preordreIter(noeud_t * R)
{ 
	
	Pile *P;
	initPile(P);
	while (R || !estVide(*P))
	{ 
		while (R)
		{ 
			traiter(R->element);
			empiler(P, R);
			R = R->gauche;
		}
		depiler(P, R);
		R = R->droit;
	}
}
// recherche dans arbre simple (n'est pas un arbre  de recherche binaire)

int rechercheSimpleRec(noeud_t * R, int E)
{
	if(!R)
		return 0;
	else
	{
		if(R->element == E)
			return 1;
		else 
			rechercheSimpleRec(R->gauche, E);
			R=R->droit;
	}
}

int rechercheSimpleIter(noeud_t * R, int E)
{
	int exist = 0;
	Pile *P;
	initPile(P);
	while ( (R || !estVide(*P)) && !exist )
	{
		while(R && !exist)
		{
			exist = (R->element == E);
			empiler(P, R);
			R=R->gauche;
		}
		depiler(P, R);
		R= R-> droit;
	}
	return exist;
}

//ARBRE BINAIERE DE RECHERCHE

void insererRec(int  don, noeud_t **R)
{
	if (*R == NULL)
		*R = instancier(don,NULL,NULL);
	else 
		if (don < (*R)->element)
			insererRec(don, &((*R)->gauche));
		else
			insererRec(don, &((*R)->droit));
}
/* Version récursive */
int rechercheRec(int  don, noeud_t * R)
{
	if (R == NULL) 
		return 0;
	else if (don == R->element) 
		return 1;
	else if (don < R->element)
		return (rechercheRec(don,R->gauche));
	else 
		return (rechercheRec(don,R->droit));
}
/* Version itérative */
int rechercheIter(int don, noeud_t * R)
{
	int trouve = 0;
	while (R && !trouve)
	{ 
		if (R->element == don)
			trouve=1;
		else if (R->element < don) 
			R=R->droit;
		else 
			R = R->gauche;
	}
	return (trouve);
}


/* supprimer le nœud de clé X dans un ARB de racine R */
void remplacer(noeud_t **R1, noeud_t **R2)
{
	noeud_t *p;
	if ((*R1)->droit != NULL)
		remplacer(&((*R1)->droit),R2);
	else 
	{
		(*R2)->element = (*R1)->element;
		p = *R1;
		*R1 = (*R1)->gauche; //car *R1 = R1->droit
		free((char *)p);
	}
}
/*
Suppression d’un élément dans un ARB
Pour supprimer un nœud, 3 cas se présentent :
1)
Le nœud est terminal : on le supprime.
2)
Le nœud a au plus un descendant : on le remplace
par ce descendant.
3)
Le nœud à supprimer a deux descendants. Dans ce
cas on remplace le nœud par :
a)
b)
Le nœud le plus à droite de son sous arbre gauche. ou
Le nœud le plus à gauche de son sous arbre droit.
*/
void supprimer1(int X, noeud_t **R)
{
	noeud_t * p;
	if (*R)
	{ 
		if (X<(*R)->element)
			supprimer1(X,&((*R)->gauche));
		else if (X>(*R)->element)
			supprimer1(X,&((*R)->droit));
		else /* (*R) pointe sur l’élément à supprimer */
		{
			if ((*R)->gauche == NULL)
			{ 
				p=*R; 
				*R = (*R)->droit; 
				free((char*)p);
			}
			else if ((*R)->droit == NULL)
			{ 
				p=*R; 
				*R = (*R)->gauche; 
				free((char*)p);
			}
			else 
				remplacer(&((*R)->gauche),R);
		} 
	}
}
noeud_t * supprimer2(int X, noeud_t *R)
{
	noeud_t * p;
	if (R)
	{ 
		if (X < R->element)
			supprimer2(X, R->gauche);
		else if (X > R->element)
			supprimer2(X, R->droit);
		else /* (*R) pointe sur l’élément à supprimer */
		{
			if (R->gauche == NULL)
			{ 
				p=R; 
				R = R->droit; 
				free((noeud_t*)p);
			}
			else if (R->droit == NULL)
			{ 
				p=R; 
				R = R->gauche; 
				free((noeud_t*)p);
			}
			else 
				remplacer(&(R->gauche),&R);
		} 
	}
	return R;
}


