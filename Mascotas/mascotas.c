#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "validaciones.h"
#include "mascotas.h"
#include"menu.h"

int inicializarMascotas(eMascota lista[], int tam)
{

    int todoOk=0;
    if(lista!=NULL && tam>0)
    {
        for(int i = 0; i<tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibre(eMascota lista[], int tam)
{
    int indice=-1;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;

}

int altaMascota(eMascota lista[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT, int* pId)
{
    int todoOk=0;
    int indice;
    eMascota auxMascota;




    if(lista!=NULL && pId!=NULL && tam>0 )
    {

        system("cls");
        printf("**************************************\n");
        printf("*            Alta Mascotas           *\n");
        printf("**************************************\n\n");

        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar disponible.\n");
        }
        else
        {
            auxMascota.id = *pId;
            (*pId)++;

            //Nombre
            printf("Ingrese nombre de su mascota: ");
            fflush(stdin);
            gets(auxMascota.nombre);
            while(strlen(auxMascota.nombre)>20|| !arrayLetras(auxMascota.nombre))
            {
                printf("Error.Nombre de mascota invalido. Reingrese nombre: ");
                fflush(stdin);
                gets(auxMascota.nombre);
            }

            //Tipos
            mostrarTipos(tipos, tamT);
            printf("**************************************\n\n");

            while(utn_getNumero(&auxMascota.idTipo,"Ingrese ID del tipo de mascota: ", "ID invalido. ",1000,1004,5)!=0)
            {
                printf("Error. Reintente ingresar tipo: \n");
                mostrarTipos(tipos, tamT);
                printf("**************************************\n\n");
            }

            //Edad
            while(utn_getNumero(&auxMascota.edad,"Ingrese edad de su mascota (de 1 anio a 50 anios): ", "Edad invalida. ",1,50,5)!=0)
            {
                printf("Error. Reintente ingresar edad. \n");
                printf("**************************************\n\n");
            }

            //Color
            mostrarColores(colores, tamC);
            printf("**************************************\n\n");
            while(utn_getNumero(&auxMascota.idColor,"Ingrese ID del color de su mascota: ", "ID de color invalido.  ",5000,5004,5)!=0)
            {
                printf("Error. Reintente ingresar color: \n");
                mostrarColores(colores, tamC);
                printf("**************************************\n\n");
            }

            //Vacunas
            printf("Su mascota se encuentra vacunada? s/n: ");
            fflush(stdin);
            scanf("%c", &auxMascota.vacunado);
            auxMascota.vacunado = tolower(auxMascota.vacunado);
            while(!validarCaracter(auxMascota.vacunado))
            {
                printf("Respuesta invalida. Su mascota se encuentra vacunada? s/n: ");
                fflush(stdin);
                scanf("%c", &auxMascota.vacunado);
            }

            auxMascota.isEmpty=0;



            lista[indice] = auxMascota;
            todoOk=1;


        }




    }

    return todoOk;

}

void mostrarMascota(eMascota unaMascota, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    char descColor[20];
    char descTipo[20];
    cargarDescripcionColor(colores, tamC, unaMascota.idColor, descColor);
    cargarDescripcionTipo(tipos, tamT, unaMascota.idTipo, descTipo);
    printf("%d     %10s     %10s    %10s           %d            %c\n",unaMascota.id,  unaMascota.nombre, descTipo, descColor, unaMascota.edad, unaMascota.vacunado);


}


int mostrarMascotas(eMascota lista[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int todoOk;
    int flag = 1;

    if (lista!= NULL && tam>0 && colores!=NULL && tamC>0 && tipos!=NULL && tamT>0)
    {
        printf("*********************************************************************************************\n");
        printf("*                                    Mascotas                                               *\n");
        printf("*********************************************************************************************\n\n");
        printf("*Id          Nombre           Tipo         Color        Edad       Vacunas                  *\n");
        printf("*********************************************************************************************\n");
        for(int i=0; i<tam; i++)
        {

            if(!lista[i].isEmpty)
            {
                mostrarMascota(lista[i], colores, tamC, tipos, tamT);
                flag = 0;
                todoOk=1;
            }

        }
        if(flag)
        {
            printf("No hay mascotas para mostrar\n");
            todoOk=0;
        }

    }


    return todoOk;

}

int bajaMascota(eMascota lista[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int todoOk;
    int idBaja;
    int indice;
    char confirma;

    if(lista!=NULL && tam>0 && colores!=NULL && tamC>0 && tipos!=NULL && tamT>0)
    {

        printf("*************************************\n");
        printf("*            Baja Mascota           *\n");
        printf("*************************************\n\n");
        if(!mostrarMascotas(lista, tam, colores, tamC, tipos, tamT))
        {
            todoOk=0;
        }else {
        printf("\nIngrese ID a dar de baja: ");
        scanf("%d", &idBaja);

        indice = buscarMascota(lista, tam, idBaja);
        if(indice == -1)
        {
            printf("El ID de la mascota ingresada no existe.\n");
        }
        else
        {
            mostrarMascota(lista[indice], colores, tamC, tipos, tamT);
            printf("\nDesea dar de baja este Id de mascota? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);

            while(confirma !='s' && confirma!='n')
            {
                printf("Dato invalido.Desea dar de baja este Id de mascota? s/n: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
            }
            if(confirma== 's')
            {
                lista[indice].isEmpty=1;
                printf("Baja exitosa.\n");
                todoOk=1;
            }
            else
            {
                printf("Baja cancelada.\n");
            }

        }
    }
}
    return todoOk;
}

int buscarMascota(eMascota lista[], int tam, int id)
{
    int indice=-1;
    if(lista!=NULL && tam>0)
    {
        for(int i = 0; i<tam; i++)
        {
            if(id == lista[i].id && lista[i].isEmpty==0)
            {
                indice = i;
                break;
            }
        }

    }


    return indice;
}

int listarMascotasPorTipoNombre(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int todoOk=0;
    eMascota auxMascota;
    if(mascotas!=NULL && tam>0 && colores!=NULL && tamC>0 && tipos!=NULL && tamT>0)
    {

        for(int i =0; i<tam-1; i++)
        {
            for(int j = i+1; j<tam; j++)
            {
                if((mascotas[i].idTipo>mascotas[j].idTipo)|| (mascotas[i].idTipo==mascotas[j].idTipo && strcmp(mascotas[i].nombre, mascotas[j].nombre)>0))
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
            }
        }
        todoOk=1;
    }




    return todoOk;

}

int cargarDescripcionMascota(eMascota mascota[], int tam, int idMascota, char descripcion[])
{
    int todoOk=0;

    if(mascota!=NULL && tam>0 && descripcion!=NULL)
    {
        for(int i =0; i<tam; i++)
        {
            if(mascota[i].id == idMascota)
            {
                strcpy(descripcion, mascota[i].nombre);
                break;
            }
        }
        todoOk=1;
    }


    return todoOk;
}


int modificarMascota(eMascota mascota[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int todoOk;

    int idModificar;
    int indice;
    char confirma;
    int auxTipo;
    char auxVacuna;


    if(mascota!=NULL && tam>0 && colores!=NULL && tamC>0 && tipos!=NULL && tamT>0)
    {


        printf("*************************************\n");
        printf("*         Modificar Mascota         *\n");

        if(!mostrarMascotas(mascota, tam, colores, tamC, tipos, tamT))
        {

            todoOk=0;
        }
        else
        {

            printf("Ingrese ID a modificar: ");
            scanf("%d", &idModificar);

            indice = buscarMascota(mascota, tam, idModificar);
            if(indice == -1)
            {
                printf("El ID de la mascota ingresada no existe.\n");
            }
            else
            {
                printf("\n\nEl Id pertenece a :");
                mostrarMascota(mascota[indice], colores, tamC, tipos, tamT);
                printf("\nDesea modificar este Id? s/n: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);

                while(confirma !='s' && confirma!='n')
                {
                    printf("Dato invalido.Desea modificar este Id de mascota? s/n: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = tolower(confirma);
                }

                if(confirma=='s')
                {

                    switch(subMenuModificar())
                    {
                    case 'A':
                        printf("\n");
                        mostrarMascota(mascota[indice], colores, tamC, tipos, tamT);
                        printf("\n");
                        mostrarTipos(tipos, tamT);
                        while(utn_getNumero(&auxTipo,"Ingrese ID del nuevo tipo de mascota que desea seleccionar: ", "ID invalido. ",1000,1004,5)!=0)
                        {
                            printf("Error en ingreso de tipo. Reintente ingresar ID de tipo: \n");
                            mostrarTipos(tipos, tamT);
                        }
                        printf("Tipo de mascota correctamente modificado.\n");
                        mascota[indice].idTipo = auxTipo;
                        printf("*************************************\n");

                        break;

                    case 'B':
                        printf("Ingrese nuevos datos de vacuna: su mascota esta vacunada? s/n: ");
                        fflush(stdin);
                        scanf("%c", &auxVacuna);
                        auxVacuna = tolower(auxVacuna);
                        while(!validarCaracter(auxVacuna))
                        {
                            printf("Respuesta invalida. Ingrese nuevos datos de vacuna: \nSu mascota esta vacunada? s/n: ");
                            fflush(stdin);
                            scanf("%c", &auxVacuna);
                        }
                        printf("Nuevos datos de vacuna cargados correctamente.\n");
                        mascota[indice].vacunado = auxVacuna;
                        break;
                    case 'C':
                        printf("******************************************************************************\n");
                        printf("                        Volviendo a menu principal.\n\n");
                        printf("******************************************************************************\n");
                        break;
                    default:
                        printf("Opcion invalida. \n\n");
                        break;
                    }


                    todoOk=1;
                }
                else
                {
                    printf("Modificacion cancelada.\n");
                }
            }

        }
    }
    return todoOk;
}
