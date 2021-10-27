#include"mascotas.h"
#include"trabajo.h"
#include"tipos.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
//1
/** \brief Funcion que flitra mascotas por color seleccionado por usuario
 *
 * \param mascotas[] eMascota array mascotas
 * \param tam int tamanio array mascotas
 * \param colores[] eColor array colores
 * \param tamC int tamanio array colores
 * \param tipos[] eTipo array tipos
 * \param tamT int tamanio array tipos
 * \return int retorna 1 si logro listarlo o 0 si no pudo realizarlo
 *
 */
int listarMascotasColor(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);

//2
/** \brief Funcion que muestra el promedio de mascotas vacunadas sobre el total de mascotas cargadas por el usuario
 *
 * \param mascotas[] eMascota array mascotas
 * \param tam int tamaño array mascotas
 * \return int retorna 1 si logro calcular el promedio o 0 si no pudo realizar la operacion
 *
 */
int promedioMascotasVacunadassobreTotal(eMascota mascotas[], int tam);


//3
/** \brief Funcion que informa cual es la/s mascota/s con menor edad
 *
 * \param mascotas[] eMascota array mascotas
 * \param tam int tamaño array mascotas
 * \param colores[] eColor array colores
 * \param tamC int tamaño array colores
 * \param tipos[] eTipo array tipos
 * \param tamT int tamaño array tipos
 * \return int retona 0 si no pudo listar mascotas, o 1 si logro su funcion
 *
 */
int informeMascotaMenorEdad(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);




//4
/** \brief funcion que ordena por cada tipo de mascota su contenido
 *
 * \param tipos[] eTipo array tipos
 * \param tamT int tamanio array tipos
 * \param mascotas[] eMascota array mascotas
 * \param tamM int tamanio array mascoas
 * \param colores[] eColor array colores
 * \param tamCol int tamanio array colores
 * \return int retorna 1 si logro imprimir la lista de tipos o 0 si no pudo realizarlo
 *
 */
int listarPorTipos(eTipo tipos[], int tamT, eMascota mascotas[], int tamM, eColor colores[], int tamCol);

//5
/** \brief funcion que lista las mascotas por tipo y color seleccionado por usuario
 *
 * \param mascotas[] eMascota array mascotas
 * \param tam int tamanio array mascotas
 * \param colores[] eColor array colores
 * \param tamC int tamanio array colores
 * \param tipos[] eTipo array tipos
 * \param tamT int tamanio array tipos
 * \return int retorna 1 si logro imprimir la lista o 0 si no logro imprimir
 *
 */
int listarMascotasTipoColor(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);


//6
/** \brief Funcion que muestra cual es el color con mas mascotas cargadas
 *
 * \param mascotas[] eMascota  array mascotas
 * \param tam int tamaño array mascotas
 * \param colores[] eColor array colores
 * \param tamC int tamaño array colores
 * \return int retorna 1 si logro cargar el/los colores con mas mascotas cargadas, o 0 si no logro realizarlo.
 *
 */
int colorConMasMascotas(eMascota mascotas[], int tam, eColor colores[], int tamC);
