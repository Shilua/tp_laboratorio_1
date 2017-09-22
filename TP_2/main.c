#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define TAM 20

int encontrarK(ePersona lista[], int tam);

int main()
{
    char seguir='s';
    int opcion=0;
    char sigue;
    ePersona listaDePersonas[TAM];
    int auxInt;
    int i;
    for(i=0; i<TAM; i++)
    {
        listaDePersonas[i].estado = 0;
    }

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
                cargarPersonas(listaDePersonas, TAM);
            break;
        case 2:printf("Ingrese D.N.I de la persona que quiere borrar\n");
                scanf("%d", &auxInt);
                borrarPersonas(listaDePersonas,auxInt,TAM);
            break;
        case 3: mostrarPersonas(listaDePersonas,TAM);
            break;
        case 4: grafico(listaDePersonas,TAM);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}

int encontrarK(ePersona lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 0)
        {
            break;
        }
    }
    return i;
}
