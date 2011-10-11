/*   
 * Archivo: Matriz.h
 * Proyecto: CRR - Batalla naval
 * 
 * Fecha de creación: 1-10-2011
 * Última modificación: Nico
 * 
 * Nota: Estructura y funciones de la clase matriz
 * 
 */


#ifndef _MATRIZ_H_
#define _MATRIZ_H_
typedef struct{
    int altura; //cantidad de filas
    int longitud; //cantidad de columnas
    int **casillas; //matriz de (Altura x Longitud) caracteres
}matriz;

//crea una instancia de matriz
int **Constructor_mat();

//manda mensaje con todos los contenidos de sus celdas
char  devolver_celda (matriz tablero,int a, int b);
/*{
	return (tablero.casillas[fila][columna]);
}
*/

//cambia el valor de una casilla de la matriz
bool Marcar(int valor,int coord);  //necesitaria que esto devuelva False en  caso de intentar insertar un barco donde ya hay uno.



#endif

