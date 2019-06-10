#include "temperature_humidite.c"
#include "luminosite.c"
//#include "mic.c"
#include "json.c"

//Thread Micro

int main()
{
	if(wiringPiSetup() == -1)
		exit(0);

	printf("Acquisition des donées\n");
	char * temp = read_dht11_temp();
	char * hum = read_dht11_hum();
	float lum = luminosite();

	printf("Temperature :%s °C \n", temp);
	printf("Humidite :%s %c \n", hum, '%');
	printf("Luminosite :%f %c \n", lum, '%');

	json(temp, hum, lum);
	//printf("%d\n", read_pmo_lum());
	return 0;
}
