#include<stdio.h>
#include<stdlib.h>

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

int main()
{
    affichage_grille_puissance_4();
    return 0;
}