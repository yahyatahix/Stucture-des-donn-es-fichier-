#include<stdio.h>
#include<stdlib.h>

typedef struct noeud noeud_t;
struct noeud
{
	int  element;
	struct noeud * gauche;
	struct noeud * droit;
} ;

int estArbreBinaire(noeud_t * R){
	int g, d, r;
	r = R->element;
	g = (R->gauche)->element;
	d = (R->droit)->element;


	if (R == NULL)
		return 1;
	else if (R->gauche != NULL && R->droit != NULL)
		if ( r < g || r > d ){
			return 0;
		}
		else{
			return (estArbreBinaire(R->gauche) * estArbreBinaire(R->droit));
		}
	}
	else if (R->gauche == NULL && R->droit == NULL)
	{
		return 1;
	}
	else if (R->gauche == NULL && R->droit != NULL)
		if ( r > d ){
			return 0;
		}
		else{
			return (estArbreBinaire(R->droit));
		}
	}
	else if (R->gauche != NULL && R->droit == NULL)
		if ( r < g  ){
			return 0;
		}
		else{
			return (estArbreBinaire(R->gauche) );
		}
	}

}

int nbNoeudsRec(noeud_t * R)
{ 
	if (!R ) 
		return 0;
	else if(R && (R->gauche || R->droit))
		return (1 + nbNoeudsRec(R->gauche) + nbNoeudsRec(R->droit));
	else if (R && !R->gauche && !R->droit)
		return 0;
}


