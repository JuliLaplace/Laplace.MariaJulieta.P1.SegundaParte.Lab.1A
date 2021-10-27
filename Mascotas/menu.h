#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED



#endif // MENU_H_INCLUDED

/** \brief Funcion que muestra menu principal al usuario
 *
 * \return char retorna opcion elegida en el menu por el usuario
 *
 */
char menu();
/** \brief Funcion que muestra submenu modificar al usuario
 *
 * \return char retorna opcion elegida en el menu por el usuario
 *
 */
char subMenuModificar();

/** \brief Funcion que muestra submenu de informes para que usuario elija que informe desea
 *
 * \return int retorna opcion elegida por el usuario
 *
 */
int subMenuInformes();
