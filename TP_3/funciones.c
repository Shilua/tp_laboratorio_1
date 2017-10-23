#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int espacioLibre(eMovie movie[], int tam)
{
    int i;
    int flag=0;
    for(i=0; i<tam; i++)
    {
        if(movie[i].estado == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag ==0)
    {
        i=-1;
    }
    return i;
}

void agregarPelicula(eMovie movie[], int tam)
{
    int i;
    i = espacioLibre(movie,tam);
    if(i == -1)
    {
        printf("No hay espacio disponible para otra pelicula\n");
    }
    else
    {
        printf("Ingrese Titulo\n");
        fflush(stdin);
        gets(movie[i].titulo);
        printf("Ingrese Genero\n");
        fflush(stdin);
        gets(movie[i].genero);
        printf("Ingrese Duracion en minutos\n");
        fflush(stdin);
        gets(movie[i].duracion);
        printf("Ingrese Puntaje\n");
        fflush(stdin);
        gets(movie[i].puntaje);
        printf("Ingrese descripcion\n");
        fflush(stdin);
        gets(movie[i].descripcion);
        printf("Ingrese Link de la imagen\n");
        fflush(stdin);
        gets(movie[i].linkImagen);
        movie[i].estado = 1;
    }

}

void borrarPelicula(eMovie movie[], int tam)
{
    char buffer[50];
    int i;
    int flag = 0;
    char auxChar;
    printf("Ingrese el titulo de la pelicula\n");
    fflush(stdin);
    gets(buffer);

    for(i=0; i<tam; i++)
    {
        if(movie[i].estado == 1)
        {
            if(stricmp(buffer,movie[i].titulo)==0)
            {
                flag = 1;
                printf("Desea borrar la pelicula %s? s/n\n", movie[i].titulo);
                auxChar = getche();
                if(auxChar == 's')
                {
                    movie[i].estado = 0;
                    printf("\n");
                    break;
                }
                else
                {
                    printf("No se ha realizado ningun cambio\n");
                    break;
                }
            }
        }
    }
    if(flag == 0)
    {
        printf("No se ha encondrado la pelicula\n");
    }
}

void modificarPelicula(eMovie movie[],int tam)
{
    char buffer[50];
    int i;
    int flag = 0;
    char auxChar;
    printf("Ingrese el titulo de la pelicula\n");
    fflush(stdin);
    gets(buffer);

    for(i=0; i<tam; i++)
    {
        if(movie[i].estado == 1)
        {
            if(stricmp(buffer,movie[i].titulo)==0)
            {
                flag = 1;
                printf("Desea modificar la pelicula %s? s/n\n", movie[i].titulo);
                auxChar = getche();
                if(auxChar == 's')
                {
                    printf("Ingrese Titulo\n");
                    fflush(stdin);
                    gets(movie[i].titulo);
                    printf("Ingrese Genero\n");
                    fflush(stdin);
                    gets(movie[i].genero);
                    printf("Ingrese Duracion en minutos\n");
                    fflush(stdin);
                    gets(movie[i].duracion);
                    printf("Ingrese Puntaje\n");
                    fflush(stdin);
                    gets(movie[i].puntaje);
                    printf("Ingrese descripcion\n");
                    fflush(stdin);
                    gets(movie[i].descripcion);
                    printf("Ingrese Link de la imagen\n");
                    fflush(stdin);
                    gets(movie[i].linkImagen);
                    break;
                }
                else
                {
                    printf("No se ha realizado ningun cambio\n");
                    break;
                }
            }
            if(flag == 0)
            {
                printf("No se ha encondrado la pelicula\n");
            }
        }
    }
}

int cargarArchivo(eMovie movie[], int tam)
{
    int flag = 0;
    FILE* archivo;

    archivo = fopen("bin.dat", "rb");
    if(archivo==NULL)
    {
        archivo = fopen("bin.dat", "wb");
        if(archivo==NULL)
        {
            return 1;
        }

        flag=1;

    }

    if(flag ==0)
    {
        fread(movie,sizeof(eMovie),tam,archivo);
    }

    fclose(archivo);
    return 0;

}

int guardarArchivo(eMovie movie[],int tam)
{

    FILE* archivo;

    archivo = fopen("bin.dat","wb");
    if(archivo == NULL)
    {
        return 1;
    }
    fwrite(movie,sizeof(eMovie),tam,archivo);



    fclose(archivo);

    return 0;
}

void generarPagina(eMovie movie[],int tam)
{
    FILE* archivo;


    int i;

    char buffer[100000];

    strcat(buffer,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
    for(i=0; i<tam; i++)
    {
        if(movie[i].estado == 1)
        {
            strcat(buffer, "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='");
            strcat(buffer,movie[i].linkImagen);
            strcat(buffer,"' alt=''></a><h3><a href='#'>");
            strcat(buffer,movie[i].titulo);
            strcat(buffer,"</a></h3><ul><li>Genero:");
            strcat(buffer,movie[i].genero);
            strcat(buffer,"</li><li>Puntaje:");
            strcat(buffer,movie[i].puntaje);
            strcat(buffer,"</li><li>Duracion:");
            strcat(buffer,movie[i].duracion);
            strcat(buffer,"</li></ul><p>");
            strcat(buffer,movie[i].descripcion);
            strcat(buffer,"</p></article>");
        }
    }
    strcat(buffer,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");

    archivo = fopen("pelicula.html","w");



    fprintf(archivo,buffer);

    fclose(archivo);
}
