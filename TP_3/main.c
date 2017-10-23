#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    char seguir='s';
    int opcion=0;
    int i;
    eMovie pelicula [TAM];
    for(i=0; i<TAM; i++)
    {
        pelicula[i].estado = 0;
    }
    if(cargarArchivo(pelicula, TAM))
    {
        printf("No se pudo abrir el archivo");
    }
    else
    {
        printf("Se cargaron las peliculas con exito\n");
    }

    system("pause");


    system("cls");


    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            agregarPelicula(pelicula,TAM);
            break;
        case 2:
            borrarPelicula(pelicula,TAM);
            break;
        case 3:
            modificarPelicula(pelicula,TAM);
            break;
        case 4:
            generarPagina(pelicula,TAM);
            break;
        case 5:
            guardarArchivo(pelicula,TAM);
            seguir = 'n';
            break;
        default:
            printf("Ingrese una opcion entre 1 y 5\n");
            break;
        }
        system("pause");
    }

    return 0;
}
