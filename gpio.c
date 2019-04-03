#include <wiringPi.h>
#include <stdio.h>

int main(void)
{
	int DHTPin=8;
	if(wiringPiSetup()==-1)
		{return 0;}
	//le port GPIO du bouton est configuré en lecture
	pinMode(DHTPin,INPUT);
	int temp=0;
	while(1)
	{
		 //on lit la valeur de la broche GPIO
		 temp=digitalRead(DHTPin);
		 printf("Valeur :\n"+temp);
		 delay(2000);//on attend 2s entre chaque lecture.
	}
	 return 0;
}