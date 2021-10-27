#include"mascotas.h"
#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED



#endif // DATAWAREHOUSE_H_INCLUDED
/** \brief funcion que deja harcodeado trabajos en mascotas
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int tamaño array trabajos
 * \param cant int cantidad a harcodear
 * \param pId int* puntero a ID para autoinrementar trabajos
 * \return int retorna 1 si logro harcodear o 0 si no logro realizarlo
 *
 */
int harcodeartrabajos(eTrabajo trabajos[], int tam, int cant, int* pId);
/** \brief funcion que deja harcodeado mascotas y sus caracteristicas
 *
 * \param mascotas[] eMascota array mascotas
 * \param tam int tamaño array mascotas
 * \param cant int cantidad a harcodear
 * \param pId int* puntero a ID para autoincrementar mascotas
 * \return int retorna 1 si logro harcodear o 0 si no logro realizarlo
 *
 */
int harcodearMascotas(eMascota mascotas[], int tam, int cant, int* pId);
