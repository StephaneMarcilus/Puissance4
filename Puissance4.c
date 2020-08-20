#include<stdio.h>
#include<stdlib.h>

#define JETON_JAUNE 'O'
#define JETON_ROUGE 'X'

char grille[6][7];

void initialisation_grille()
{
	int i,j;
	for(i=0;i<6;i++) for(j=0;j<7;j++) grille[i][j]=' ';
}

void affichage_grille_puissance_4()
{
	int i,j;
	printf("+---+---+---+---+---+---+---+\n");
	for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)  printf("| %c ",grille[i][j]);
        printf("|\n+---+---+---+---+---+---+---+\n"); //Bordures horizontales interieures
    }
    for (i=1;i<=7;i++)	printf("  %d ",i); //Numéros des colonnes
}

int grille_pleine()
{
    int i,j;
    for(i=0;i<6;i++) for(j=0;j<7;j++) if(grille[i][j] == ' ') return 0;
    return 1;
}

int coup_valide(int colonne)
{
	if(colonne<=0 || colonne>7 || grille[0][colonne-1]!=' ') return 0; //Coup non valide car colonne pleine
	return 1;
}

int ligne_d_arret(int colonne)
{
	int ligne=0,i;
	if(coup_valide(colonne)) while(grille[ligne][colonne-1]==' ' && i<6){i++; ligne++;}; //for(i=0;i<6;i++) if(grille[ligne][colonne-1]==' ') ligne++; 
	return ligne;
}

void jouer_coup(int colonne,char jeton)
{
	if(coup_valide(colonne)) grille[ligne_d_arret(colonne)-1][colonne-1]=jeton;
}

int verification_4_jetons()
{
	int i,j;
	for(i=0;i<6;i++)
	{
		for(j=0;j<7-3;j++)
		{
			if(grille[i][j] != ' ' && grille[i][j]==grille[i][j+1] && grille[i][j]==grille[i][j+2] && grille[i][j]==grille[i][j+3]) return 1; //Vérification horizontale
		}
	}

	for(i=0;i<6-3;i++)
	{
		for(j=0;j<7;j++)
		{
			if(grille[i][j] != ' ' && grille[i][j]==grille[i+1][j] && grille[i][j]==grille[i+2][j] && grille[i][j]==grille[i+3][j]) return 1; //Vérification verticale
		}
	}

	for(i=0;i<6-3;i++)
	{
		for(j=0;j<7-3;j++)
		{
			if(grille[i][j] != ' ' && grille[i][j]==grille[i+1][j+1] && grille[i][j]==grille[i+2][j+2] && grille[i][j]==grille[i+3][j+3]) return 1; //Diagonale à droite
		}
	}

	for(i=0;i<6-3;i++)
	{
		for(j=3;j<7;j++)
		{
			if(grille[i][j] != ' ' && grille[i][j]==grille[i+1][j-1] && grille[i][j]==grille[i+2][j-2] && grille[i][j]==grille[i+3][j-3]) return 1; //Diagonale à gauche
		}
	}

	return 0;
}

void partie()
{
	char jeton_J1=JETON_JAUNE;
	char jeton_J2=JETON_ROUGE;
	int colonne;
	int cpt=0;

	initialisation_grille();
	affichage_grille_puissance_4();

	do
	{
		if(cpt%2==0)
		{
			printf("\n\n Joueur 1 (O). Veuillez entrer le num\202ro de la case souhait\202e : ");
			scanf("%d",&colonne);
			//system("clear"); //Linux
			system("cls"); //Windows
			if(coup_valide(colonne)) jouer_coup(colonne,jeton_J1);
			else
			{
				printf("Impossible de jouer ici, veuillez recommencer\n");
				cpt--;
			}
			affichage_grille_puissance_4();
		}
		else
		{
			printf("\n\n Joueur 2 (X). Veuillez entrer le num\202ro de la case souhait\202e : ");
			scanf("%d",&colonne);
			//system("clear"); //Linux
			system("cls"); //Windows
			if(coup_valide(colonne)) jouer_coup(colonne,jeton_J2);
			else
			{
				printf("Impossible de jouer ici, veuillez recommencer\n");
				cpt--;
			}
			affichage_grille_puissance_4();
		}
		cpt++;
	}
		while(!(grille_pleine() || verification_4_jetons()));
		if(verification_4_jetons() && cpt%2) printf("\n\n Victoire du joueur 1 ! (O)\n\n  Fin de la partie.");
		if(verification_4_jetons() && !(cpt%2)) printf("\n\n Victoire du joueur 2 ! (X)\n\n  Fin de la partie.");
		if(grille_pleine() && !(verification_4_jetons())) printf("\n\n Match nul, aucun gagnant.\n\n  Fin de la partie.");
}

int main()
{
	system("cls");
    partie();
    return 0;
}