#include <string.h>
#include <time.h> 


void json(char * temp, char * hum, float lum){
	time_t timestamp = time(NULL);
	struct tm * t = localtime(&timestamp);

	int jour = 1+t->tm_mday;
	int mois = 1+t->tm_mon;
	int annee = 1900+t->tm_year;
	FILE *fic = fopen("/home/data", "a");

	fprintf(fic, "[\n");
		fprintf(fic, "{\n");
			fprintf(fic, "\"Date\": \"%d-%d-%d\",\n", annee, mois, jour);
			fprintf(fic, "\"Temperature\": \"%s\",\n", temp);
			fprintf(fic, "\"Humidite\": \"%s\",\n", hum);
			fprintf(fic, "\"Luminosite\": \"%f\",\n", lum);
		fprintf(fic, "}\n");
	fprintf(fic, "]\n");
}