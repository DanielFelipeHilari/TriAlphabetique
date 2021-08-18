#include <stdio.h>
#include <stdlib.h>

char** CreationTab(FILE* fichier, int nbrprenom)
{
	char** chaine = malloc(nbrprenom*sizeof(char*));
	for(int i = 0; i<nbrprenom; i++)
	{
		chaine[i] = malloc(20*sizeof(char));
	}
	int i = 0;
	int j = 0;
	chaine[i][j] = fgetc(fichier);
	printf("%c",chaine[i][j]);
	while(chaine[i][j] != EOF)
	{
		if(chaine[i][j] == ' ')
		{
			chaine[i][j] = '\0';
			i++;
			j = 0;
		}else
		{
			j++;
			chaine[i][j] = fgetc(fichier);
		}
	}
	return chaine;
}

int NombrePrenom(FILE* fichier)
{
	int nbm = 0;
	char a;
	a = fgetc(fichier);
	while(a != EOF)
	{
		if( a == ' ')
			nbm++;
		a = fgetc(fichier);	
	}
	nbm++;
	return nbm;
}

int main(int argc , char *argv[])
{
	printf("Bienvenue au programme de tri alphabetique \n");
	//char chaine[20];
	FILE* fichier = NULL; 
	fichier = fopen("liste.txt","r");
	if(fichier == NULL)
	{
		fprintf(stderr, "Ne peut pas ouvrir le fichier \n");
		exit(EXIT_FAILURE);
	}
	
	/*fgets(chaine,20,fichier);
	printf("%s \n",chaine);*/
	int n = NombrePrenom(fichier);
	printf("%d\n",n);
	rewind(fichier);
	char** tab = CreationTab(fichier,n);
	for(int i = 0;i<n;i++)
	{
		for(int j =0;j<20;j++)
		{
			printf("%c",tab[i][j]);
		}
		printf("\n");
	}
	fclose(fichier);
	
	return 0;
}
