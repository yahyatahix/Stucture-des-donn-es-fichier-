/*
Manip. 4 :
faire la mise à jour (ajout et modification
d’un enregistrement) du fichier des
bouquins en utilisant les possibilités de
l’accès direct (utilisation de
fseek(f,offset,when) / pos=ftell(f) en
octets).
*/

#include<stdio.h>


struct Bouquin {
	char titre[6] , auteur[6] ;
} ;
typedef struct Bouquin Bouquin ;


int main(int argc, char const *argv[])
{
	FILE * pointeur_bouquins ;
	char choixMiseJour ;
	int nbBouquinAjouter , nbBouquinDejaEntrer , nbBouquinActuel , c;
	Bouquin livreEntre , livre , livreNv;

	pointeur_bouquins =fopen("/media/tahix/FUTUR/etudes/18-19/info/TP-TD/Langage_C/STD/manip3/fichierBouquin.txt", "r") ;	
	
	fseek(pointeur_bouquins, 0, SEEK_END);
    nbBouquinDejaEntrer = ftell(pointeur_bouquins)/sizeof(livre);
    printf("nb bouquin déja entrer est : %d\n",nbBouquinDejaEntrer );

    fclose(pointeur_bouquins);

	printf("Bonjour,\n Si vous voulez ajouter un bouquin : \t Tapez A \n Si vous voulez modifier un bouquin : \t Tapez M \n ");

	choixMiseJour=fgetc(stdin);
	
	if (choixMiseJour=='A' || choixMiseJour=='a')
	{
		pointeur_bouquins =fopen("/media/tahix/FUTUR/etudes/18-19/info/TP-TD/Langage_C/STD/manip3/fichierBouquin.txt", "a") ;	

		fprintf(stdout, "donner le nombre de bouquins à ajouter :\n" );
		fscanf(stdin,"%d", &nbBouquinAjouter);
		for (int i = 0; i < nbBouquinAjouter; i++)
		{
			printf("entrer un livre\n");
			scanf("%s",livreEntre.titre);
			printf("entrer l'auteur du livre que vous venez de taper :\n");
			scanf("%s",livreEntre.auteur);
			fwrite(&livreEntre,sizeof(Bouquin), 1 ,pointeur_bouquins);
		
		
		}
		fclose(pointeur_bouquins);	

		printf("livre \t auteur \n ");
		
		pointeur_bouquins =fopen("/media/tahix/FUTUR/etudes/18-19/info/TP-TD/Langage_C/STD/manip3/fichierBouquin.txt", "r") ;		
		
		nbBouquinActuel = nbBouquinDejaEntrer + nbBouquinAjouter ;
		
		while(fread(&livre,sizeof(Bouquin),1,pointeur_bouquins)){
			printf("%s\t %s\n ",livre.titre ,livre.auteur);
		}

		fclose(pointeur_bouquins);	
	}
	
	else if (choixMiseJour == 'M' || choixMiseJour == 'm')
	{
		
		printf("entrer le titre du livre puis le auteur du livre à modifier\n");
		scanf("%s %s",livreEntre.titre,livreEntre.auteur);
		
		c = 0;
		pointeur_bouquins =fopen("/media/tahix/FUTUR/etudes/18-19/info/TP-TD/Langage_C/STD/manip3/fichierBouquin.txt", "r") ;
		
		while(fread(&livre,sizeof(Bouquin),1,pointeur_bouquins))
		{	
			printf("dkhelt la boucle\n");
			if (livreEntre.titre == livre.titre && livreEntre.auteur ==livre.auteur)
			{
				printf("entrer le titre du livre puis le auteur du livre qui remplace le bouquin %s \t %s \n", livre.titre ,livre.auteur );
				scanf("%s %s",livreNv.titre,livreNv.auteur);
				pointeur_bouquins =fopen("/media/tahix/FUTUR/etudes/18-19/info/TP-TD/Langage_C/STD/manip3/fichierBouquin.txt", "w") ;
				livre = livreNv ;
				fclose(pointeur_bouquins);
				c++;
			}

		}
		fclose(pointeur_bouquins);

		pointeur_bouquins =fopen("/media/tahix/FUTUR/etudes/18-19/info/TP-TD/Langage_C/STD/manip3/fichierBouquin.txt", "r") ;

		if(c == 0){
			printf("le bouquin que vous avez entré ne figure pas dans le fichier désolé  :/ \n");
		}
		
		else{
			printf("voila le nv fichier \n livre \t auteur \n ");
	
			while(fread(&livre,sizeof(Bouquin),1,pointeur_bouquins)){
				printf("%s\t %s\n ",livre.titre ,livre.auteur);
			}
		}
		
		fclose(pointeur_bouquins);
	}

	else{
		printf("Réxecuter le programme et érivez soit 'm' soit 'a'"); 
	}

	return 0;
}
