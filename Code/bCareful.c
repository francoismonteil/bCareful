#include "temperature_humidite.c"
#include "luminosite.c"
#include "mic.c"
#include "json.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char *mainTemp;
char *mainHum;
char *mainLum;

//Thread Micro
void *mic(void *arg)
{
	if(wiringPiSetup() == -1)
		exit(0);

	while(1){
		if(ecoute() == 1){
			printf("Bébé pleure !");
			json(mainTemp, mainHum, mainLum, 1);
			sleep(60);
		}
	}
	pthread_exit(NULL);
}

//Thread lecture capteurs
void *lecture(void *arg)
{
	if(wiringPiSetup() == -1)
		exit(0);

	while(1){
		printf("Acquisition des donées\n");
		mainTemp = read_dht11_temp();
		mainHum = read_dht11_hum();
		mainLum = luminosite();

		/*printf("Temperature :%s °C \n", temp);
		printf("Humidite :%s %c \n", hum, '%');
		printf("Luminosite :%s %c \n", lum, '%');*/
		
		json(mainTemp, mainHum, mainLum, 0);

		sleep(60);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	
	if(pthread_create(&thread1, NULL, lecture, NULL) == -1){
		perror("pthread_create");
		return EXIT_FAILURE;
	}
	
	if(pthread_create(&thread2, NULL, mic, NULL) == -1){
		perror("pthread_create");
		return EXIT_FAILURE;
	}
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	return 0;
}
