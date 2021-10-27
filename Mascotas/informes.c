#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include"validaciones.h"

//1
int listarMascotasColor(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){

int listarOk;
int idColor;
int flag=0;
char descColor[20];

    system("cls");
    printf("*******************************************************************************************\n");
    printf("                    Lista de mascotas por color         \n");
    printf("*******************************************************************************************\n");


    if(colores!= NULL && tamC>0 && mascotas!=NULL && tam>0 && tipos!=NULL && tamT>0){
    }
	mostrarColores(colores, tamC);
   	printf("*******************************************************************************************\n");

        while(utn_getNumero(&idColor,"Ingrese ID del color a elegir: ", "ID invalido.  ",5000,5004,5)!=0){
                      printf("Error en carga de ID de color. Reintente: \n");
                      mostrarColores(colores, tamC);
                    }
            cargarDescripcionColor(colores, tamC, idColor, descColor);
            printf("\n\n");
            printf("*******************************************************************************************\n");
            printf("                         Listado de Mascotas por color: %s\n         \n", descColor);
            printf("*******************************************************************************************\n");
            printf("ID           Nombre           Tipo         Color      Edad      Tiene vacunas? \n");
            printf("*******************************************************************************************\n");

        for (int i =0; i<tam; i++){
            if(mascotas[i].isEmpty==0 && mascotas[i].idColor==idColor){
                mostrarMascota(mascotas[i], colores, tamC, tipos, tamT);
                flag=1;
            }
            listarOk=1;
        }
        if(flag==0){
            printf("No hay mascotas que mostrar en el color seleccionado.\n\n");
            listarOk=0;
        }
          return listarOk;
    }

//2
int promedioMascotasVacunadassobreTotal(eMascota mascotas[], int tam){

int todoOk=0;
float promedio=0;
int contVacunados=0;
int acumuladorTotalMascotas=0;


if(mascotas!=NULL && tam>0){
        system("cls");
        printf("**************************************************************************************\n");
        printf("*      Informe promedio de mascotas vacunadas sobre total de mascotas cargadas       *\n");
        printf("**************************************************************************************\n\n");


            for(int i=0; i<tam;i++){
                if(mascotas[i].isEmpty==0){
                        acumuladorTotalMascotas+=1;
                        if(mascotas[i].vacunado=='s'){
                            contVacunados++;
                        }
                }
            }


            if(contVacunados!=0){
                promedio=(float) acumuladorTotalMascotas/(contVacunados);
                printf("El total de mascotas (vacunadas y no vacunadas) es: %d.\nEl promedio de macotas vacunadas sobre el total de mascotas es: %.2f .\n\n",acumuladorTotalMascotas, promedio);
            }else{
                printf("No se encuentran mascotas vacunadas para calcular promedio.\n\n");
            }


    todoOk=1;
}



return todoOk;
}


//3
int informeMascotaMenorEdad(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){

int todoOk=0;
int edadMenor=0;
int flag=1;


if(mascotas!=NULL && tam>0 && colores!=NULL && tamC>0 && tipos!=NULL && tamT>0){
        system("cls");
        printf("*********************************************************\n");
        printf("*      Informe mascota de menor edad                    *\n");
        printf("*********************************************************\n\n");





            //primer recorrido
            for(int i=0; i<tam;i++){
                if(mascotas[i].isEmpty==0){
                    if(flag || edadMenor>mascotas[i].edad){
                        edadMenor = mascotas[i].edad;
                        flag=0;
                    }

                }
            }

            if(flag){

                printf("No se encuentran Mascotas para informar su edad.\n\n");
            }else{
                //para ver si hay empate de edades
                printf("*      Mascota/s con menor edad :*\n");
                printf("*********************************************************************************************\n\n");
                printf("*Id          Nombre           Tipo        Color         Edad         Vacunas                *\n");
                printf("*********************************************************************************************\n");
                for(int i=0; i<tam;i++){
                    if(mascotas[i].isEmpty==0  && mascotas[i].edad == edadMenor){

                        mostrarMascota(mascotas[i], colores, tamC, tipos, tamT);
                    }
                }
            }


    todoOk=1;

}
return todoOk;
}

//4

int listarPorTipos(eTipo tipos[], int tamT, eMascota mascotas[], int tamM, eColor colores[], int tamCol){
    int listarOk=0;
    int flag;

    if(tipos!=NULL && tamT>0 && mascotas!=NULL && tamM>0 && colores!=NULL && tamCol>0){

        for(int t=0; t<tamT; t++){

            printf("*******************************************************************************************\n");
            printf("                             Tipo %s          \n", tipos[t].descripcion);
            printf("*******************************************************************************************\n");
            printf("ID           Nombre           Tipo         Color      Edad      Tiene vacunas? \n");
            printf("*******************************************************************************************\n");
            flag=0;
            for(int m=0; m<tamM; m++){
                if(mascotas[m].idTipo == tipos[t].id && mascotas[m].isEmpty==0){
                    mostrarMascota(mascotas[m], colores, tamCol, tipos, tamT);
                    flag=1;
                    listarOk=1;
                }
            }
             if(flag==0){
                printf("No se encuentran mascotas con el tipo seleccionado.\n\n");
                }
            printf("\n\n");
        }

    }

    return listarOk;
}
//5
int listarMascotasTipoColor(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){

int listarOk;
int idTipo;
int idColor;
int flag=0;
char descTipo[20];
char descColor[20];

    system("cls");
    printf("*********************************************************************************************\n");
    printf("                    Lista de mascotas por Tipo y Color        \n");
    printf("*********************************************************************************************\n");


    if(colores!= NULL && mascotas!= NULL && tipos!= NULL &&tamC>0 && tam>0 && tamT>0){
        //muestro los tipos para que usuario seleccione
        mostrarTipos(tipos, tamT);
        printf("*********************************************************************************************\n");

        while(utn_getNumero(&idTipo,"Ingrese ID del tipo a elegir: ", "ID invalido.  ",1000,1004,5)!=0){
                      printf("Error en carga de ID de tipo. Reintente:\n");
                      mostrarTipos(tipos, tamT);
                       printf("*********************************************************************************************\n");
                    }
        //muestro los colores para que usuario seleccione
        mostrarColores(colores, tamC);
        printf("*********************************************************************************************\n");
        while(utn_getNumero(&idColor,"Ingrese ID del color a elegir: ", "ID invalido.  ",5000,5004,5)!=0){
                    printf("Error en eleccion de ID de tipo. Reintente:\n");
                    mostrarColores(colores, tamC);
                    printf("*********************************************************************************************\n");
                    }
             //cargo descripciones de color y tipo
            cargarDescripcionColor(colores, tamC, idColor, descColor);
            cargarDescripcionTipo(tipos, tamT, idTipo, descTipo);

            printf("\n\n");
            printf("*********************************************************************************************\n");
            printf("                         Listado de Mascotas por tipo %s y color %s\n         \n", descTipo, descColor);
            printf("*********************************************************************************************\n");
            printf("ID           Nombre           Tipo         Color      Edad      Tiene vacunas? \n");
            printf("*********************************************************************************************\n\n");

        for (int i =0; i<tam; i++){
            if(mascotas[i].isEmpty==0 && mascotas[i].idTipo==idTipo && mascotas[i].idColor == idColor){
                mostrarMascota(mascotas[i], colores, tamC, tipos, tamT);
                flag=1;
            }
            listarOk=1;
        }
        if(flag==0){
            printf("No hay mascotas que mostrar en el tipo y color seleccionado.\n\n");
            listarOk=0;
        }
    }
return listarOk;
}

//6

int colorConMasMascotas(eMascota mascotas[], int tam, eColor colores[], int tamC){
    int todoOk=0;
    int cantidadMascotas[100]={0}; //tamaño de array de mascotas definido en main
    int mayorCantidadMascotas;
    int flag=1;


    if(mascotas!=NULL && colores!=NULL && tam>0 && tamC>0){
        system("cls");
        printf("*********************************************************\n");
        printf("*              Informe color/es con mas mascotas        *\n");
        printf("*********************************************************\n\n");

            for (int i=0; i<tamC; i++){


                for(int j=0; j<tam; j++){

                    if((!mascotas[j].isEmpty) && (mascotas[j].idColor == colores[i].id)){
                        cantidadMascotas[i]++;
                    }
                }


            }
            //recorrer vector de mascotas para tener maximo
            for(int i=0; i<tamC; i++){
                   if(flag || mayorCantidadMascotas<cantidadMascotas[i]){
                    mayorCantidadMascotas = cantidadMascotas[i];
                    flag=0;
                   }
                }
            //recorro de nuevo para saber si hay empate en cantidad de mascotas y colores
            for(int i=0; i<tamC; i++){
                   if(cantidadMascotas[i] == mayorCantidadMascotas){
                    printf("El color que mas se cargo en los datos de animales es: %s.\n", colores[i].descripcion);
                   }
                }
            printf("\n\n");
                todoOk=1;
    }




    return todoOk;
}
