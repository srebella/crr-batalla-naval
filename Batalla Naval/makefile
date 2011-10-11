CC=gcc
CCOPS=-g -Wall -lm
EXE=SSOO
MAIN=magia_CRR.c

#juego
PATHJUE=juego/

BARC=$(PATHJUE)/barco.c
BARH=$(PATHJUE)/barco.h
BARO=barco.o
COORC=$(PATHJUE)/coordenadas.c
COORH=$(PATHJUE)/coordenadas.h
COORO=coordenadas.o
ESPC=$(PATHJUE)/espectador.c
ESPH=$(PATHJUE)/espectador.h
ESPO=espectador.o
JUEC=$(PATHJUE)/juego.c
JUEH=$(PATHJUE)/juego.h
JUEO=Juego.o
MATC=$(PATHJUE)/matriz.c
MATH=$(PATHJUE)/matriz.h
MATO=matriz.o
#presentacion
PATHPRES=presentacion
CONC=$(PATHPRES)/conversores.c
CONH=$(PATHPRES)/conversores.h
CONO=conversores.o
MENC=$(PATHPRES)/mensajes_consola.c
MENH=$(PATHPRES)/mensajes_consola.h
MENO=mensajes_consola.o
VALC=$(PATHPRES)/validaciones.c
VALH=$(PATHPRES)/validaciones.h
VALO=validaciones.o
#conexion
PATHCON=conexion
FUNC=$(PATHCON)/funciones.c
FUNH=$(PATHCON)/funciones.h
FUNO=funciones.o
FACHC=$(PATHCON)/fachada.c
FACHH=$(PATHCON)/fachada.h
FACHO=fachada.o
BUFFC=$(PATHCON)/buffer.c
BUFFH=$(PATHCON)/buffer.h
BUFFO=buffer.o


all: magia_CRR.c barco.o espectador.o matriz.o conversores.o validaciones.o mensajes_consola.o fachada.o funciones.o buffer.o 
	$(CC) $(CCOPS) -o $(EXE) $(MAIN) $(BARO) $(ESPO) $(MATO) $(CONO) $(MENO) $(VALO) $(FUNO) $(FACHO) $(BUFFO) 

#juego
barco.o: $(BARC) $(BARH)
	$(CC) $(CCOPS) -c $(BARC)
	
espectador.o: $(ESPC) $(ESPH)
	$(CC) $(CCOPS) -c $(ESPC)

#Juego.o: $(JUEC) $(JUEH)
#	$(CC) $(CCOPS) -c $(JUEC)
	
matriz.o: $(MATC) $(MATH)
	$(CC) $(CCOPS) -c $(MATC)

#presentacion
conversores.o: $(CONC) $(CONH)
	$(CC) $(CCOPS) -c $(CONC)

mensajes_consola.o: $(MENC) $(MENH)
	$(CC) $(CCOPS) -c $(MENC)
	
validaciones.o: $(VALC) $(VALH)
	$(CC) $(CCOPS) -c $(VALC)

#conexion
funciones.o: $(FUNC) $(FUNH)
	$(CC) $(CCOPS) -c $(FUNC)
	
fachada.o: $(FACHC) $(FACHH)
	$(CC) $(CCOPS) -c $(FACHC)
	
buffer.o: $(BUFFC) $(BUFFH)
	$(CC) $(CCOPS) -c $(BUFFC)


.PHONY clean:
	rm $(EXE) *.o
