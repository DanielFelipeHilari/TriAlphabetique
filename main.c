#include <stdio.h>
#include <stdlib.h>


int main(int argc , char *argv[])
{
	printf("Bienvenue au programme de tri alphabetique \n");
	char chaine[20];
	FILE* fichier = NULL; 
	fichier = fopen("liste.txt","r");
	if(fichier == NULL)
	{
		fprintf(stderr, "Ne peut pas ouvrir le fichier \n");
		exit(EXIT_FAILURE);
	}
	fgets(chaine,20,fichier);
	printf("%s",chaine);
	fclose(fichier);
	
	return 0;
}
