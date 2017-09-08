#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroA;
    float numeroB;
    float solucion;
    int flag1 = 0;
    int flag2 = 0;
    long long int resultadoFactorial;

    while(seguir=='s')
    {
        system("cls");
        if(flag1 == 0)
        {
            printf("1- Ingresar 1er operando (A=)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n", numeroA);
        }
        if(flag2 == 0)
        {
            printf("1- Ingresar 2do operando (B=)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n", numeroB);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);



        switch(opcion)
        {
            case 1:
                printf("Ingrese el 1er operando\n");
                scanf("%f", &numeroA);
                flag1 = 1;
                break;
            case 2:
                printf("Ingrese el 2do operando\n");
                scanf("%f", &numeroB);
                flag2 = 1;
                break;
            case 3:
                if(flag1 == 0 || flag2 == 0)
                {
                    printf("Primero debe ingresar los operandos en las opciones 1 y 2\n");
                }
                else
                {
                    solucion = suma(numeroA, numeroB);
                    printf("El resultado de la suma es %.2f\n", solucion);
                }
                break;
            case 4:
                if(flag1 == 0 || flag2 == 0)
                {
                    printf("Primero debe ingresar los operandos en las opciones 1 y 2\n");
                }
                else
                {

                    solucion = resta(numeroA, numeroB);
                    printf("el resultado de la resta es %.2f\n", solucion);
                }
                break;
            case 5:
                if(flag1 == 0 || flag2 == 0)
                {
                    printf("Primero debe ingresar los operandos en las opciones 1 y 2\n");

                }
                else if(numeroB == 0)
                {
                    printf("El divisor no puede ser 0 reingrese otro numero en la opcion 2\n");
                }
                else
                {
                    solucion = division(numeroA, numeroB);
                    printf("El resultado de la division es %.2f\n", solucion);
                }
                break;
            case 6:
                if(flag1 == 0 || flag2 == 0)
                {
                    printf("Primero debe ingresar los operandos en las opciones 1 y 2\n");
                }
                else
                {
                    solucion = multiplicacion(numeroA, numeroB);
                    printf("El resultado de la multiplicacion es %.2f\n", solucion);
                }
                break;
            case 7:
                if(flag1 == 0)
                {
                    printf("Primero debe ingresar el operando en la opcion 1\n");
                }
                else if(numeroA<0 || numeroA-(int)numeroA != 0.00)
                {
                    printf("Error. el operando debe ser positivo y entero, reingreselo en la opcion 1\n");
                }
                else
                {
                    resultadoFactorial = factorial(numeroA);
                    printf("El factorial de %.0f es %lld\n", numeroA, resultadoFactorial);
                }
                break;

            case 8:
                if(flag1 == 0 || flag2 == 0)
                {
                    printf("Primero debe ingresar los operandos en las opciones 1 y 2\n");

                }
                else if(numeroB == 0)
                {
                    printf("El divisor no puede ser 0 reingrese otro numero en la opcion 2\n");
                }
                else
                {
                    if(numeroA<0 || numeroA-(int)numeroA != 0.00)
                    {
                        printf("Error. el primer operando debe ser positivo y entero, reingreselo en la opcion 1\n");
                    }
                    else{
                        todas(numeroA,numeroB);
                    }
                    }
                    break;
                case 9:
                    seguir = 'n';
                    break;
            }
            system("pause");
        }
        return 0;
    }
