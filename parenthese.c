#define MAX 50
typedef struct {
	char T[MAX];
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

int Empiler(Pile * P, char E){
	if (!estPleine(*P))
	{
		P -> s++ ;
		P -> T[P -> s] = E ;
		return 1 ;
	}
	return 0 ;

}

int Depiler(Pile * P, char * E){
	if (!estVide(*P))
	{
		*E = P -> T[P -> s];
		P -> s -- ;
		return 1;
	}
	return 0 ;
}

#include<stdio.h>
#include <string.h>

void expressionParenthese(char symbole1, char symbole2, char *expression);

int main(int argc, char const *argv[])
{
	char T[] = {'(',')','<','>','[',']','{','}'};
	char expression[15];
	printf("entrer l'expression parenthesé à vérifier : \n");
	gets(expression);

	for (int i = 0; i < 8 ; i = i + 2 ) 
	{
		expressionParenthese(T[i], T[i+1], expression);
	}
	return 0;
}

void expressionParenthese(char symbole1, char symbole2, char *expression)
{
	Pile P;
	initPile(&P);
	char c,x,parFermante;
	parFermante = 'f' ;
	int len = strlen(expression);

	for (int i = 0 ;i < len ; i++ ) 
	{
				
		c = expression[i];
		if(c!='\0')
		{
			if(c == symbole1 )
			{
				Empiler(&P,c);
			}
			else
				if(c == symbole2 && !estVide(P))
				{
					Depiler(&P,&x);

				}
				else if (c == symbole2 && estVide(P))
				{
					Empiler(&P,'a');
					parFermante='v';
				}
					
		}				
	}
	if(estVide(P))
		printf("l'utilisation de %c est correcte \n ",symbole1);
	else if (!estVide(P) && parFermante == 'v')
	{
		printf("l'utilisation de %c est incorrecte \n REMARQUE :le symbole %c est utilisé sans qu'il soit ouvert  \n ",symbole1,symbole2);
	}
	else 
		printf("l'utilisation de %c est incorrecte \n", symbole1);	


}
