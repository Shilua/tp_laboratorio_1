#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma(float x, float y)
{
    float resultado;
    resultado = x + y;
    return resultado;
}
float resta(float x, float y)
{
    float resultado;
    resultado = x - y;
    return resultado;
}
float multiplicacion (float x, float y)
{
    float resultado;
    resultado = x * y;
    return resultado;
}
float division (float x, float y)
{
    float resultado;

    resultado = x / y;
    return resultado;

}
int factorial(float x)
{
    long long int resultado=1;
    int i;
    for(i=x; i>0; i--)
    {
        resultado = resultado * i;
    }
    return resultado;
}
void todas(float x, float y)
{


    float sum;
    float rest;
    float multi;
    float divi;
    int factor;

    sum = suma(x,y);
    printf("El resultado de la suma es %f\n", sum);
    rest = resta(x,y);
    printf("El resultado de la resta es %f\n", rest);
    multi = multiplicacion(x,y);
    printf("El resultado de la multiplicacion es %f\n", multi);
    divi = division(x,y);
    printf("El resultado de la division es %f\n", divi);
    factor = factorial(x);
    printf("El factorial del primer operando es %lld\n", factor);
}

