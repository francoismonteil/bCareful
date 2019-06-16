#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define  MIC_DO_Pin   5

typedef unsigned int uint;

int ecoute(void)
{

	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
    int dat1 = 1;
    do{
		pinMode( MIC_DO_Pin, OUTPUT );
		digitalWrite( MIC_DO_Pin, LOW );
		delay( 18 );
		digitalWrite( MIC_DO_Pin, HIGH );
		delayMicroseconds( 40 );
		pinMode( MIC_DO_Pin, INPUT );
		dat1 = digitalRead(MIC_DO_Pin);
	}while(dat1 == 1);

	return 1;
}
