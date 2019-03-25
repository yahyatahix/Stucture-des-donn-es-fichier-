/*Manip. 3 :
Ecrire un programme qui contient les
fonctions remplissage et affichage d’un
fichier de bouquins et les tester (utilisation
de fwrite(&enr,sizeof(enr),1,f)/
fread(&enr,sizeof(enr),1,f)).*/

#include<stdio.h>

struct Bouquin {
	char titre[6] , auteur[6] ;
} ;
typedef struct Bouquin Bouquin ;



int main(int argc, char const *argv[])
{
	Bouquin livre;
	int nbBouquin;
	FILE * pointeur_bouquins ;
	pointeur_bouquins = fopen("/media/tahix/FUTUR/etudes/18-19/info/TP-TD/Langage_C/STD/manip3/fichierBouquin.txt", "w") ;

	fprintf(stdout, "donner le nombre de bouquins à entrer\n" );
	fscanf(stdin,"%d", &nbBouquin);
	//fprintf(stdout,"Entrer le nombre de bouquins à enregistrer : %d",nbBouquin);
	
	//livre = {"titre1", "auteur1"};
	//livre.titre = "titre1";
	//livre.auteur="auteur1";
	for (int i = 0; i < nbBouquin; ++i)
	{
		printf("entrer un livre\n");
		scanf("%s",livre.titre);
		printf("entrer l'auteur du livre que vous venez de taper :\n");
		scanf("%s",livre.auteur);
		fwrite(&livre,sizeof(livre),1,pointeur_bouquins);
		
		
	}	
	fclose(pointeur_bouquins);

	pointeur_bouquins = fopen("/media/tahix/FUTUR/etudes/18-19/info/TP-TD/Langage_C/STD/manip3/fichierBouquin.txt", "r") ;
	printf("livre \t auteur \n ");
	
	Bouquin bq ;
	while(fread(&bq,sizeof(Bouquin),1,pointeur_bouquins)){
			printf("%s\t %s\n ",bq.titre ,bq.auteur);
		}
	
	//fread(&livre,sizeof(livre),1,pointeur_bouquins);

	fclose(pointeur_bouquins);

	return 0;
}
