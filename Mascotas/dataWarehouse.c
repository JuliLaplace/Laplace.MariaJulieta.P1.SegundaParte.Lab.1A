#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "dataWarehouse.h"

int idMascotas[10]={1000,1001,1002,1003,1004,1005,1006,1007,1008,1009};
char nombres[10][20]={
    "Morty",
    "Effy",
    "Draco",
    "Elvis",
    "Valentina",
    "Mio",
    "Luna",
    "Levi",
    "Aki",
    "Yugi"
    };
int idTipo[10]={1001,1004,1000,1002,1000,1001,1003,1003,1001,1000};
int idColor[10]={5000,5004,5001,5002,5003,5001,5003,5000,5001,5000};
int edad[10]={1,12,15,5,1,8,20,10,2,6};
char vacunado[10]={'s','n','n','n','s','n','n','s','s','n'};
int idServicios[10]={20001,20001,20000,20002,20000,20001,20000,20002,20001,20000};
eFecha fechas[10]={
    {05/12/2020},
    {10/10/2017},
    {22/04/2019},
    {01/02/2000},
    {17/9/2017},
    {31/10/2019},
    {04/03/2020},
    {20/03/2019},
     {21/01/2020},
     {04/12/2021}
    };

int harcodearMascotas(eMascota mascotas[], int tam, int cant, int* pId){
    int contador = -1;
    if(mascotas!=NULL && tam>0 && cant>=0 && cant<=tam){
        contador=0;
        for(int i=0; i<cant; i++){
            mascotas[i].id = *pId;
            (*pId)++;
            strcpy(mascotas[i].nombre, nombres[i]);
            mascotas[i].vacunado = vacunado[i];
            mascotas[i].edad = edad[i];
            mascotas[i].idColor = idColor[i];
            mascotas[i].idTipo = idTipo[i];
            mascotas[i].isEmpty =0;
            contador++;
        }
    }

    return contador;
}

int harcodeartrabajos(eTrabajo trabajos[], int tam, int cant, int* pId){
    int contador = -1;
    if(trabajos!=NULL && tam>0 && cant>=0 && cant<=tam){
        contador=0;
        for(int i=0; i<cant; i++){
            trabajos[i].id = *pId;
            (*pId)++;
            trabajos[i].idMascota =idMascotas[i];
            trabajos[i].idServicio = idServicios[i];
            trabajos[i].fecha.dia = fechas[i].dia;
            trabajos[i].fecha.mes = fechas[i].mes;
            trabajos[i].fecha.anio = fechas[i].anio;
            trabajos[i].isEmpty =0;
            contador++;
        }
    }

    return contador;
}

