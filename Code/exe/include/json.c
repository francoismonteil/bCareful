#include <string.h>
#include <time.h> 


int json(char * temp, char * hum, char * lum, int pleure){
	time_t timestamp = time(NULL);
	
	char dir[50] = "";
	FILE *fic;
	
	if(pleure == 1){
		sprintf(dir, "/var/www/html/bCareful/data/pleure.json");
		fic = fopen(dir, "w");
	}
	else{
		sprintf(dir, "/var/www/html/bCareful/data/%ld.json", timestamp);
		fic = fopen(dir, "a");
	}
		
	fprintf(fic, "[\n");	
		fprintf(fic, "\t{\n");
			fprintf(fic, "\t\t\"Temperature\": %s,\n", temp);
			fprintf(fic, "\t\t\"Humidite\": %s,\n", hum);
			fprintf(fic, "\t\t\"Luminosite\": %s\n", lum);
			fprintf(fic, "\t\t\"Timestamp\": %ld\n", timestamp);
		fprintf(fic, "\t}\n");
	fprintf(fic, "]\n");
	
	fclose(fic);
	
	return 1;
}
