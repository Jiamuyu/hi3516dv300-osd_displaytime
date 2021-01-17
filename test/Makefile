INCLUDE_PATH = /home/yct/fontok/include
LIB_PATH = /home/yct/fontok/lib

CCO = arm-himix200-linux-gcc

CC = $(CCO)
INCLUDE = -I$(INCLUDE_PATH)
LIB = -L$(LIB_PATH)
SERVER_OBJS = soapC.o stdsoap2.o duration.o wsaapi.o soapClient.o onvif_cilent.o


all: arm 
arm:
	$(CCO) *.c $(INCLUDE) $(LIB) -lfreetype -lSDL -lSDL_ttf -o test


clean: 
	rm -f *.o test
