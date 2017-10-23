#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string.h>
#include <conio.h>
#define TAM 50
typedef struct{
    char titulo[20];
    char genero[20];
    char duracion[5];
    char descripcion[50];
    char puntaje[5];
    char linkImagen[200];
    int estado;
}eMovie;

/**
 *  Busca un espacio libre en el array de peliculas
 *  @param movie el array de peliculas
 *  @param tam tamaño del array
 *  @return retorna 1 si hay espacio libre y -1 si no lo hay
 */
int espacioLibre(eMovie movie[], int tam);

/**
 *  Agrega una pelicula del array
 *  @param movie la estructura a ser agregada al archivo
 *  @param tam tamaño del array
 */
void agregarPelicula(eMovie movie[], int tam);

/**
 *  Borrar una pelicula del array
 *  @param movie la estructura a ser agregada al archivo
 *  @param tam tamaño del array
 */
void borrarPelicula(eMovie movie[], int tam);

/**
 *  Modifica una pelicula del array
 *  @param movie la estructura a ser agregada al archivo
 *  @param tam tamaño del array
 */
void modificarPelicula(eMovie movie[], int tam);

int cargarArchivo(eMovie movie[], int tam);

int guardarArchivo(eMovie movie[],int tam);

/*/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no

int borrarPelicula(eMovie movie);
*/
/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(eMovie movie[],int tam);

#endif // FUNCIONES_H_INCLUDED
