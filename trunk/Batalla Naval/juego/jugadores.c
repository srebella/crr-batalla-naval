/*
 * Archivo: Jugadores.c
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 6-10-2011
 * 
 * Nota: Definicion de las funciones de la clase Jugadores
 *
 */
#include "jugadores.h"
#include "coordenadas.h"
void atacar(struct jugador* Jug,coord *c)
{
     marcar(Jug->matriz_ajena,'A',c);

}
int colocar_barco (struct jugador* Jug,coord* c)
{
    construir_barco(c,c);
    int a=marcar(Jug->matriz_propia,'B',c);
    return a;
}
int perder_vida (struct jugador *Jug)
{
    //golpe(b); ver como llega el barco b hasta aca
    Jug->vida--;//por default es igual a 8
    return 0;
}




/*int main()
{
    struct jugador *J1=malloc(sizeof(struct jugador));
    J1->matriz_propia=constructor_matriz();
    coord *c=malloc(sizeof(coord));
    c->fila=0;
    c->columna=1;
    int a=colocar_barco(J1,c);
    printf("%d",a);
    return a;
}*/
