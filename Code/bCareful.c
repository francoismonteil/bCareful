#include "temperature_humidite.c"

int main()
{
	printf("%s", read_dht11_temp());
	return 0;
}