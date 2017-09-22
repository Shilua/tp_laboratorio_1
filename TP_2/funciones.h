#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param int tam entero para tamaño del array.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int tam);

/**
 * Carga los datos de una persona en el espacio libre que me entrega la funcion obtenerEspacioLibre
 * \param lista el array se pasa como parametro.
 * \param int tam entero para tamaño del array.
 */
void cargarPersonas(ePersona lista[], int tam);


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param int tam entero para tamaño del array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni, int tam);

/**
 * Cambia el estado de la persona a buscar por 0, dandola de baja
 * \param lista el array se pasa como parametro.
 * \param int dni numero de documento de la persona a dar de baja.
 * \param int tam entero para tamaño del array.
 */
void borrarPersonas(ePersona lista[], int dni, int tam);

/**
 * Muestra las personas cargadas ordenadas alfabeticamente.
 * \param lista el array se pasa como parametro.
 * \param int tam entero para tamaño del array.
 */
void mostrarPersonas(ePersona lista[], int tam);

/**
 * Muestra un grafico de la cantidad de personas con menos de 18 años, de 19 a 35 y mayores a 35.
 * \param lista el array se pasa como parametro.
 * \param int tam entero para tamaño del array.
 */
void grafico(ePersona lista[], int tam);

#endif // FUNCIONES_H_INCLUDED
