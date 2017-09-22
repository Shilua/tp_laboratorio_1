#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

int obtenerEspacioLibre(ePersona lista[], int tam)
{
    int i;
    int flag = 0;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        i= -1;
    }
    return i;
}


void cargarPersonas(ePersona lista[], int tam)
{
    int k;
    k = obtenerEspacioLibre(lista, tam);
    if (k== -1)
    {
        printf("No hay espacio para una nueva persona\n");
    }
    else
    {
        printf("Ingrese el nombre:\n");
        fflush(stdin);
        gets(lista[k].nombre);

        printf("Ingrese dni:\n");
        scanf("%d", &lista[k].dni);

        printf("Ingrese edad:\n");
        scanf("%d", &lista[k].edad);

        lista[k].estado = 1;
    }
}

int buscarPorDni(ePersona lista[], int dni, int tam)
{
    char confirm;
    int flag = 0;
    int i;
    printf("Esta seguro de eliminar la persona del D.N.I. N: %d (s/n)\n", dni);
    confirm = getche();

    if(confirm=='s')
    {
        for(i=0; i<tam; i++)
        {
            if(dni==lista[i].dni)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            i=-1;
        }

    }
    return i;
}

void borrarPersonas(ePersona lista[], int dni, int tam)
{
    int i;
    i = buscarPorDni(lista,dni,tam);


    if (i == -1)
    {
        printf("\nEl %d no coincide con ninguno de la lista\n", dni);
    }
    else
    {
        lista[i].estado = 0;
        printf("\nLa persona cuyo D.N.I. es %d ha sido borrada de la lista\n", dni);
    }
}
void mostrarPersonas(ePersona lista[], int tam)
{
    int i, j, k;
    ePersona auxPersona;
    for(i=0; i<tam-1; i++)
    {
        if(lista[i].estado == 1)
        {

            for(j=i+1; j<tam; j++)
            {
                if (lista[j].estado == 1)
                {
                    k= stricmp(lista[i].nombre,lista[j].nombre);
                    if(k>0)
                    {
                        auxPersona = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxPersona;
                    }
                }
            }
        }
    }
    printf("Nombre\Edad\D.N.I.");
    for (i = 0; i<tam; i++)
    {
        if(lista[i].estado == 1)
        {
            printf("%s\t%d\t%d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
        }
    }
}
void grafico(ePersona lista[], int tam)
{
    int i, j;
    int flag = 0;
    int auxMenos18=0, auxHasta35=0, auxMas35=0;
    for (i=0; i<tam; i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad<=18)
            {
                auxMenos18++;
            }
            else if(lista[i].edad>=19 && lista[i].edad<=35)
            {
                auxHasta35++;
            }
            else
            {
                auxMas35++;
            }
        }
    }
    if(auxMenos18>auxHasta35 && auxMenos18>auxMas35)
    {
        j = auxMenos18;
    }
    else if(auxHasta35>auxMenos18 && auxHasta35>auxMas35)
    {
        j = auxHasta35;
    }
    else
    {
        j = auxMas35;
    }

    printf("%d--%d--%d--%d\n",auxMenos18,auxHasta35,auxMas35,j);
    for (i=j; i>0; i--)
    {
        if(i<= auxMenos18)
        {
            printf("*");
        }
        for (i=j; i>0; i--)
        {
            if(i<= auxHasta35)
            {
                flag=1;
                printf("\t*");
            }
            if(i<= auxMas35)
            {
                if(flag == 0)
                {
                    printf("\t\t*");
                }
                if (flag == 1)
                {
                    printf("\t*");
                }
                printf("\n");
            }
        }
        printf("\n<18\t19-35\t>35\n");
    }
}
