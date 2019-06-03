
typedef struct notes notes_t;
struct notes
{
	struct notes * suiv;
	double note;
	int coef;
};

typedef struct etudiant etudiant_t;
struct etudiant
{
	struct etudiant * suiv;
	int no;
	char nom[10];
	char prenom[10];
	double moy;
	notes_t * eval;
};

etudiant_t * moyennesEtudiants( etudiant_t * L){
	int c, nbNote = 0;
	double somme = 0, moyenne = 0.0, n ;
	notes_t * P;
	etudiant_t * Q = L;
	while(L){
		P = L->eval ;
		while(P){
			n = P->note;
			c = P->coef;
			somme = somme + n * c;
			nbNote ++;
			P = P->suiv;
		}   
		moyenne = somme / nbNote ;
		L->moy = moyenne;
		L = L->suiv;
	}
	return Q;
}

