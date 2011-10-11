#ifndef _BARCO_H_
#define _BARCO_H_
typedef struct{
    int estado; //indica si el barco está hundido o no
    int longitud; //casillas que ocupa el barco
    int popa; //casilla inicial del barco
    int proa; //casilla final del barco
}barco;

//crea una nueva instancia de barco llenando sus atributos
void Construir_barco(int popa,int proa);

//decrece el numero de barcos de jugador y
//borra el barco de la matriz
bool Destruir_barco();

//marca un golpe en el barco
void Golpe();

#endif

