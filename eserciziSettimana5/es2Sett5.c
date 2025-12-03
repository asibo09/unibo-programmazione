#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int versione;
	printf("Scegliere la versione del programma:\n 1(versione senza string.h);\n 2(versione con string.h);\n");
	fflush(stdin);
	scanf("%d", &versione);

	switch (versione)
	{
	case 1:
		printf("Hai scelto la versione senza string.h\n");
		senzaLibreria();
		break;
	case 2:
		printf("Hai scelto la versione con string.h\n");
		conLibreria();
		break;
	default:
		printf("Scelta non valida.\n");
		return 1;
	}
	return 0;
}



void senzaLibreria()
{
	char str1[31];
	printf("Introdurre una stringa : ");
	scanf("%30s", str1);
	fflush(stdin);

	char str2[31];
	printf("Introdurre una stringa : ");
	scanf("%30s", str2);

	printf("%s\n", str1);
	printf("%s\n\n", str2);


	//lunghezza delle stringhe
	int len1 = 0;
	int len2 = 0;
	while (str1[len1] != '\0') {
		len1++;
	}

	while (str2[len2] != '\0') {
		len2++;
	}

	//senza libreria
	for (int i = 0; i <= len1 - len2; i++) {
		int found = 1;
		for (int j = 0; j < len2; j++) {
			if (str1[i + j] != str2[j]) {
				found = 0;
				break;
			}
		}

		if (found) {
			for (int j = i; j < i + len2; j++) {
				str1[j] = '*';
			}
		}
	}

	char output[30];
	//pulisco stringa finale
	for (int k = 0, x = 0; k < len1;k++, x++)
	{
		if (str1[x] == '*') {
			output[k] = str1[x];
			x = x + len2 - 1;
		}
		else
			output[k] = str1[x];

	}
	printf("%s\n", output);

	return 0;
}
void conLibreria()
{
	char str1[31];
	printf("Introdurre una stringa : ");
	scanf("%30s", str1);
	fflush(stdin);

	char str2[31];
	printf("Introdurre una stringa : ");
	scanf("%30s", str2);

	printf("%s\n", str1);
	printf("%s\n\n", str2);


	//lunghezza delle stringhe
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	//con libreria
	for (int i = 0; i <= len1 - len2; i++)
	{
		if (strncmp(str1 + i, str2, len2) == 0)
		{
			for (int j = i; j < i + len2; j++) {
				str1[j] = '*';
			}
		}
	}

	char output2[30];
	//pulisco stringa finale
	for (int k = 0, x = 0; k < len1;k++, x++)
	{
		if (str1[x] == '*') {
			output2[k] = str1[x];
			x = x + len2 - 1;
		}
		else
			output2[k] = str1[x];

	}
	printf("%s\n", output2);

	return 0;
}