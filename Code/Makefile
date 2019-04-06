ifneq ($V,1)
Q ?= @
endif

DEBUG	= -O3
DESTDIR?=exe
CC=tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-gcc

INCLUDE	= -I$(DESTDIR)/include
CFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe
LDFLAGS	= -L$(DESTDIR)/lib
LDLIBS    = -lwiringPi -lwiringPiDev -lpthread -lm -lcrypt -lrt

SRC	=	temperature_humidite.c			\

OBJ	=	$(SRC:.c=.o)

BINS	=	$(SRC:.c=)

all:	$(BINS)

temperature_humidite:	temperature_humidite.o
	$Q echo [link]
	$Q $(CC) -o $@ temperature_humidite.o $(LDFLAGS) $(LDLIBS)

.c.o:
	$Q echo [CC] $<
	$Q $(CC) -c $(CFLAGS) $< -o $@

clean:
	$Q echo "[Clean]"
	$Q rm -f $(OBJ) *~ core tags $(BINS)