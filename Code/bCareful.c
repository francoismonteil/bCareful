#include "temperature_humidite.c"
#include "luminosite.c"
#include "mic.c"
#include "json.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//Thread Micro

//Thread lecture capteurs
void *lecture(void *arg)
{
	if(wiringPiSetup() == -1)
		exit(0);

	while(1){
		delay(10000);
		printf("Acquisition des donées\n");
		char * temp = read_dht11_temp();
		char * hum = read_dht11_hum();
		char * lum = luminosite();

		printf("Temperature :%s °C \n", temp);
		printf("Humidite :%s %c \n", hum, '%');
		printf("Luminosite :%s %c \n", lum, '%');

		json(temp, hum, lum);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread1;
	
	if(pthread_create(&thread1, NULL, lecture, NULL) == -1){
		perror("pthread_create");
		return EXIT_FAILURE;
	}
	
	pthread_join(thread1, NULL);
	
	return 0;
}
