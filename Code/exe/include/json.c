#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int compteChar(char *dir){
	FILE *fichier = fopen(dir, "r+");
	int nChar = 0;
	int c;
	while((c=fgetc(fichier)) != EOF)
	{
		nChar++;
		if(c==']'){
			break;
			printf("fin\n");
		}
	}
	return nChar;
}

int json(char * temp, char * hum, char * lum, int pleure){
	time_t timestamp = time(NULL);
	
	char dir[50] = "";
	FILE *fic;
	
	if(pleure == 1){
		sprintf(dir, "pleure.json");
		fic = fopen(dir, "w");
	}else{
		sprintf(dir, "data.json");
		fic = fopen(dir, "r+");
		int nbChars;
		if((nbChars = compteChar(dir)) == 0){
			fprintf(fic, "[\n");	
				fprintf(fic, "\t{\n");
					fprintf(fic, "\t\t\"Temperature\": %s,\n", temp);
					fprintf(fic, "\t\t\"Humidite\": %s,\n", hum);
					fprintf(fic, "\t\t\"Luminosite\": %s,\n", lum);
					fprintf(fic, "\t\t\"Timestamp\": %ld\n", timestamp);
				fprintf(fic, "\t}\n");
			fprintf(fic, "]\n");
		}else{
			fseek(fic, nbChars-3, 0);
					fprintf(fic, "},\n");
					fprintf(fic, "\t{\n");
					fprintf(fic, "\t\t\"Temperature\": %s,\n", temp);
					fprintf(fic, "\t\t\"Humidite\": %s,\n", hum);
					fprintf(fic, "\t\t\"Luminosite\": %s,\n", lum);
					fprintf(fic, "\t\t\"Timestamp\": %ld\n", timestamp);
				fprintf(fic, "\t}\n");
			fprintf(fic, "]\n");
		}
	}
			
	fclose(fic);
	
	return 1;
}
