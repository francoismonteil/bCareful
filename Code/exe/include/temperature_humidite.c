#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define MAXTIMINGS	85
#define DHTPIN		8
int dht11_dat[5] = { 0, 0, 0, 0, 0 };
char temp[5];
char hum[5];
char * read_dht11_temp()
{
	int done = 0;
	while(done == 0){
		uint8_t laststate	= HIGH;
		uint8_t counter		= 0;
		uint8_t j		= 0, i;
		
	 	FILE *fic = fopen("/home/log_temp", "w");
	 
		dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;
		fprintf(fic, "0 : %d\n", dht11_dat[0]);
	 	
		pinMode( DHTPIN, OUTPUT );
		digitalWrite( DHTPIN, LOW );
		delay( 18 );
		digitalWrite( DHTPIN, HIGH );
		delayMicroseconds( 40 );
		pinMode( DHTPIN, INPUT );

		for ( i = 0; i < MAXTIMINGS; i++ )
		{
				counter = 0;
				while ( digitalRead( DHTPIN ) == laststate )
				{
					counter++;
					delayMicroseconds( 1 );
					if ( counter == 255 )
					{
						break;
					}
				}
				laststate = digitalRead( DHTPIN );
		 		fprintf(fic, "laststate : %d\n", laststate);
				if ( counter == 255 )
					break;
	 
			if ( (i >= 4) && (i % 2 == 0) )
			{
				dht11_dat[j / 8] <<= 1;
				if ( counter > 50 )
					dht11_dat[j / 8] |= 1;
				j++;
			}
		}
 	
	 	fprintf(fic, "j : %d\n", j);
	 	fprintf(fic, "dht11_dat[4] : %d\n", dht11_dat[4]);
	 	fprintf(fic, "Total dht11_dat : %d\n", (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) );
 	
		if ( (j >= 40) &&
		     (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
		{
			sprintf(temp, "%d.%d", dht11_dat[2], dht11_dat[3]);
			done = 1;
		}else  {
			done = 0;
			//fprintf(fic, "error\n");
		}
		delay(1000);
		fprintf(fic, "done : %d\n", done);
	}
	
	return (char *)temp;
}


char * read_dht11_hum()
{
	int done = 0;
	while(done == 0){
		uint8_t laststate	= HIGH;
		uint8_t counter		= 0;
		uint8_t j		= 0, i;

	 	FILE *fic = fopen("/home/log_hum", "w");
	 
		dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;
		fprintf(fic, "0 : %d\n", dht11_dat[0]);
	 	
		pinMode( DHTPIN, OUTPUT );
		digitalWrite( DHTPIN, LOW );
		delay( 18 );
		digitalWrite( DHTPIN, HIGH );
		delayMicroseconds( 40 );
		pinMode( DHTPIN, INPUT );

		for ( i = 0; i < MAXTIMINGS; i++ )
		{
			counter = 0;
			while ( digitalRead( DHTPIN ) == laststate )
			{
				counter++;
				delayMicroseconds( 1 );
				if ( counter == 255 )
				{
					break;
				}
			}
			laststate = digitalRead( DHTPIN );
	 		fprintf(fic, "laststate : %d\n", laststate);
			if ( counter == 255 )
				break;
	 
			if ( (i >= 4) && (i % 2 == 0) )
			{
				dht11_dat[j / 8] <<= 1;
				if ( counter > 50 )
					dht11_dat[j / 8] |= 1;
				j++;
			}
		}
	 	
	 	fprintf(fic, "j : %d\n", j);
	 	fprintf(fic, "dht11_dat[4] : %d\n", dht11_dat[4]);
	 	fprintf(fic, "Total dht11_dat : %d\n", (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) );
 	
		if ( (j >= 40) &&
		     (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
		{
			sprintf(hum, "%d.%d", dht11_dat[0], dht11_dat[1]);
			done = 1;
		}else  {
			done = 0;
			//fprintf(fic, "error\n");
		}
		delay(1000);
		fprintf(fic, "done : %d\n", done);
	}
	
	return (char *)hum;
}
