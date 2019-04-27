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
	int nbElement = 0, element, occ, exist;
	int Element[20], Occurrence[20];
	Noeud * P ;

	while(T)
	{
		
		element = T->v;
		occ = 0;

		exist = 0;
		for (int i = 0; i < nbElement; i++)
		{
			if (Element[i] == element)
				exist = 1;
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
					P->suiv;
				}
				else
					P->suiv;
			}
			Occurrence[nbElement-1] = occ;
		}

		T = T->suiv;
	}
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
		insererDebut(T, e);

	}
	occurrence(T);
	
	return 0;
}
