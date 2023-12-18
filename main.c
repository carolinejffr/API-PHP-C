#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	struct eleve
	{
		char prenom[16];
		char nom[16];
	};
	
	// 1ère lecture du fichier csv pour trouver la taille de l'array classe
	FILE* fptr;
	fptr = fopen("csv.txt", "r");
	char contenu[256];
	int i = 0;
	
	int nbEleve = 0;
	while(fgets(contenu, 256, fptr))
	{
		char *token = strtok(contenu, ";");
		token = strtok(NULL, ";");
		if (token != NULL)
		{
			nbEleve++;
		}
		i++;
	}
	i = 0;
	fclose(fptr);

	// 2ème lecture du fichier csv pour peupler l'array classe
	fptr = fopen("csv.txt", "r");
	char contenu2[256];

	struct eleve classe[nbEleve];
	while(fgets(contenu2, 256, fptr))
	{
		char *token = strtok(contenu2, ";");
		if (token != NULL)
		{
			strcpy(classe[i].prenom, token);
		}
		token = strtok(NULL, ";");
		if (token != NULL)
		{
			strcpy(classe[i].nom, token);
		}
		i++;
	}
	i = 0;
	fclose(fptr);
		

	int nombreEleves = sizeof(classe) / sizeof(classe[0]);

	// commandes
	if (strcmp(argv[1], "read") == 0)
	{
		if (argc == 3)
		{
			int numero = atoi(argv[2]);
			printf("%s %s\n", classe[numero].prenom, classe[numero].nom);
		}
	}
	else if (strcmp(argv[1], "readall") == 0)
	{
		for (int i = 0; i < nombreEleves; i++)
		{
			printf("%s %s\n", classe[i].prenom, classe[i].nom);
		}
	}
	if (strcmp(argv[1], "create") == 0)
	{
		if (argc == 4)
		{
			fptr = fopen("csv.txt", "a");
			fprintf(fptr, "\n%s;%s;", argv[2], argv[3]);
			fclose(fptr);
			printf("l'élève a été ajouté.");
		}
	}
	if (strcmp(argv[1], "delete") == 0)
	{
		if (argc == 4)
		{
			// TODO : supprimer
		}
	}
	else if (strcmp(argv[1], "help") == 0)
	{
		printf("-----Liste des commandes-----\n");
		printf("\"read\" : prend en paramètre 1 entier. Affiche le nom et le prénom de l'élève associé.\n");
		printf("\"readall\" : affiche tous les élèves de la classe.\n");
		printf("\"create\" : prend en paramètre un prénom et un nom. Ajoute un nouvel élève.\n");
		// printf("\"delete\" : prend en paramètre un prénom et un nom. supprime un élève.\n");
	}
}