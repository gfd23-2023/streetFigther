#Makefile - Giovanna Fioravante Dalledone
#v.3

CC					= gcc
CFLAGS				= -Wall -Wextra -g
PKG_CONFIG			= pkg-config
PKG_CONFIG_LIBS		= allegro-5 allegro_main-5 allegro_font-5 allegro_image-5 allegro_ttf-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5
LDFLAGS				= $(shell $(PKG_CONFIG) --libs $(PKG_CONFIG_LIBS))
CFLAGS				+= $(shell $(PKG_CONFIG) --cflags $(PKG_CONFIG_LIBS))
MAIN				= street_fighter

#programa principal
$(MAIN): $(MAIN).o Joystick.o players.o scams_ryu.o world.o
	$(CC) -o $(MAIN) $(MAIN).o Joystick.o players.o scams_ryu.o world.o $(LDFLAGS) $(CFLAGS)


$(MAIN).o: $(MAIN).c Joystick.h players.h scams_ryu.h world.h
	$(CC) $(CFLAGS) -c $(MAIN).c


#TADs
Joystick.o: Joystick.c Joystick.h
	$(CC) $(CFLAGS) -c Joystick.c


players.o: players.c players.h Joystick.h
	$(CC) $(CFLAGS) -c players.c


scams_ryu.o: scams_ryu.c scams_ryu.h
	$(CC) $(CFLAGS) -c scams_ryu.c


world.o: world.c world.h
	$(CC) $(CFLAGS) -c world.c
clean:
	rm -f *.o*~ $(MAIN)
	find . -name "*.sw*" -delete
