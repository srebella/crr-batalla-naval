CC=gcc
CCOPS=-g -Wall -lm
EXE=conexion
MAIN=conexion.c
FUNC=funciones.c
FUNH=funciones.h
FUNO=funciones.o
FACHC=fachada.c
FACHH=fachada.h
FACHO=fachada.o
BUFFC=buffer.c
BUFFH=buffer.h
BUFFO=buffer.o

all: conexion.c fachada.o funciones.o buffer.o
	$(CC) $(CCOPS) -o $(EXE) $(MAIN) $(FUNO) $(FACHO) $(BUFFO)

funciones.o: $(FUNC) $(FUNH)
	$(CC) $(CCOPS) -c $(FUNC)
	
fachada.o: $(FACHC) $(FACHH)
	$(CC) $(CCOPS) -c $(FACHC)
	
buffer.o: $(BUFFC) $(BUFFH)
	$(CC) $(CCOPS) -c $(BUFFC)

.PHONY clean:
	rm $(EXE) *.o
