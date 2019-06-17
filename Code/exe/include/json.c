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
		sprintf(dir, "/var/www/html/bCareful/data/pleure.json");
		fic = fopen(dir, "w");
		fprintf(fic, "[\n");	
			fprintf(fic, "\t{\n");
				fprintf(fic, "\t\t\"Temperature\": %s,\n", temp);
				fprintf(fic, "\t\t\"Humidite\": %s,\n", hum);
				fprintf(fic, "\t\t\"Luminosite\": %s,\n", lum);
				fprintf(fic, "\t\t\"Timestamp\": %ld\n", timestamp);
			fprintf(fic, "\t}\n");
		fprintf(fic, "]\n");
	}else{
		sprintf(dir, "/var/www/html/bCareful/data/data.json");
		int nbChars;
		if((nbChars = compteChar(dir)) == 0){
			fic = fopen(dir, "w");
			fprintf(fic, "[\n");	
				fprintf(fic, "\t{\n");
					fprintf(fic, "\t\t\"Temperature\": %s,\n", temp);
					fprintf(fic, "\t\t\"Humidite\": %s,\n", hum);
					fprintf(fic, "\t\t\"Luminosite\": %s,\n", lum);
					fprintf(fic, "\t\t\"Timestamp\": %ld\n", timestamp);
				fprintf(fic, "\t}\n");
			fprintf(fic, "]\n");
		}else{
			fic = fopen(dir, "r+");
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

int iniData(){
	char dir[50] = "";
	sprintf(dir, "/var/www/html/bCareful/data/pleure.json");
	FILE *fic = fopen(dir, "w");
	fclose(fic);
	sprintf(dir, "/var/www/html/bCareful/data/data.json");
	fopen(dir, "w");
	fic = fopen(dir, "w");
	fclose(fic);
	
	return EXIT_SUCCESS;
}
