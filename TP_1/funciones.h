#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Suma dos numeros flotantes
 *
 * \param Recibe un flotante que actua de primer sumando
 * \param Recibe un flotante que actua de segundo sumando
 * \return Devuelve el flotante que actua del total de la suma
 *
 */
float suma(float,float);


/** \brief Resta dos numeros flotantes
 *
 * \param Recibe un flotante que actua de minuendo
 * \param Recibe un flotante que actua de sustraendo
 * \return Devuelve un flotante que actua de el resto
 *
 */
float resta(float,float);

/** \brief Multiplica dos flotantes
 *
 * \param Recibe un flotante que actua de multiplicando
 * \param Recibe un flotante que actua de multiplicador
 * \return Devuelve un flotante que actua de producto
 *
 */
float multiplicacion (float, float);

/** \brief Divide dos flotantes
 *
 * \param Recibe un flotante que actua de dividendo
 * \param Recibe un flotante que actua de divisor, no puede ser 0
 * \return Devuelve un flotante que actua de cociente
 *
 */
float division(float, float);

/** \brief Realiza el factorial de un numero
 *
 * \param Recibe un flotante el cual debe ser entero y positivo
 * \return Devuelve la multiplicacion del flotante por sus numeros anteriores hasta 0
 *
 */
int factorial(float);

/** \brief Llama a todas las funciones anteriores y muestra sus resultados mediante mensajes
 *
 * \param Recibe un flotante que actua de primer sumando, minuendo, multiplicando, dividendo y numero a factorizar
 * \param Recibe un flotante que actua de segundo sumando, sustraendo, multiplicador y divisor
 *
 */
void todas(float,float);





#endif // FUNCIONES_H_INCLUDED
