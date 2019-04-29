
#include<stdlib.h> // pour utiliser NULL
#include<stdio.h>
typedef struct Noeud Noeud;
struct Noeud
{
	int v;
	struct Noeud * suiv ;
};
void occurrence(Noeud * T)
{
	int nbElement , element, occ, exist;
	int Element[20], Occurrence[20];
	Noeud * P ;
	nbElement = 0;
	while(T)
	{
		
		element = T->v;
		occ = 1;

		exist = 0;
		for (int i = 0; i < nbElement; i++)
		{
			if (Element[i] == element)
			{
				exist = 1;
				break ;
			}
			else
				exist = 0;
		}
		if (exist == 0)
		{
			Element[nbElement] = element;
			nbElement ++;
			P = T->suiv;
			while(P)
			{
				if (P->v == element)
				{
					occ++;
					P = P->suiv;
				}
				else
					P = P->suiv;
			}
			Occurrence[nbElement-1] = occ;
		}

		T = T->suiv;
	}
	//printf("%d  %d\n",nbElement, Element[1] );
	for (int i = 0; i < nbElement; i++)
	{
		printf("%d existe %d fois \n",Element[i], Occurrence[i] );
	}
}

Noeud * insererDebut(Noeud * T, int i)
{
	Noeud * P ;
	if((P = (Noeud *) malloc(sizeof(Noeud))))
	{
		P -> v = i ;
		P -> suiv = T ;
		T = P ;
	}
	return T ;
}

int main(int argc, char const *argv[])
{
	Noeud * T = NULL;
	int nbNoeud;
	int e ;
	printf("entrer le nombre de noeud à enregistrer \n");
	scanf("%d",&nbNoeud);

	for (int i = 0; i < nbNoeud; ++i)
	{
		printf("entrer l'element \n");
		scanf("%d",&e);
		T = insererDebut(T, e);

	}
	occurrence(T);
	
	return 0;
}
