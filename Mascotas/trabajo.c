
#include"trabajo.h"



int inicializarTrabajos(eTrabajo lista[], int tam){
    int inicializarOk=0;
    if(lista!=NULL && tam>0){
        for (int i=0; i<tam; i++){
            lista[i].isEmpty=1;
        }
        inicializarOk=1;
    }
    return inicializarOk;
}

int altaTrabajo(eTrabajo lista[], int tam, eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamS, int* pId){
    int altaOk=0;
    eFecha auxFecha;
    eTrabajo auxTrabajo;
    int indiceTrabajo;
    int indiceMascota;



    if(lista!=NULL && tam>0 && pId!=NULL && colores!=NULL && tamC>0 && mascotas!=NULL && tam>0 && tipos!=NULL && tamT>0 && servicios!=NULL && tamS>0){
    system ("cls");
    printf("*******************************************************************************************\n");
    printf("                                   Alta Trabajos\n");
        indiceTrabajo = buscarLibreTrabajo(lista, tam);

        if(indiceTrabajo==-1){
            printf("No hay lugar disponible.\n");

        }else{


                    printf("\n");
                    mostrarMascotas(mascotas, tam, colores, tamC, tipos, tamT);
                    printf("\nIngrese ID de mascota a ingresar: ");
                    scanf("%d", &auxTrabajo.idMascota);
                    while(!validarIdMascotas(mascotas, tam, auxTrabajo.idMascota)) {
                        printf("ID incorrecto. Ingrese ID valido: ");
                        scanf("%d", &auxTrabajo.idMascota);
                    }


                    indiceMascota = buscarMascota(mascotas, tam, auxTrabajo.idMascota);


                        printf("\n");
                        printf("El id ingresado es el siguiente: %d. \n", auxTrabajo.idMascota);
                        printf("Pertenece a: \n");

                        mostrarMascota(mascotas[indiceMascota], colores, tamC, tipos, tamT);






                    /////////Servicios
                    printf("\n");
                    mostrarServicios(servicios, tamS);

                    while(utn_getNumero(&auxTrabajo.idServicio, "Ingrese servicio a realizar: ", "Id de servicio incorrecto. ", 20000, 20002, 5)!=0){
                        printf("Error. Reintente ingresar servicio valido:\n");
                        mostrarServicios(servicios, tamS);
                    }
                    printf("*********************************************************************************************\n");
                    printf("Servicio correctamente cargado.\n");
                    printf("*********************************************************************************************\n");

                     //fecha
                    //dia
                    while(utn_getNumero(&auxFecha.dia,"Ingrese dia de realizacion de servicio (1 - 31): ", "Dia invalido. ",1,31,5)!=0){
                        printf("Error. Reintente ingresar fecha valida: \n");
                        printf("*********************************************************************************************\n");

                    }
                    printf("*********************************************************************************************\n");
                    printf("Fecha correctamente cargada.\n");
                    printf("*********************************************************************************************\n");

                    //mes
                    while(utn_getNumero(&auxFecha.mes,"Ingrese mes de realizacion de servicio(1-12): ", "Mes invalido. ",1,12,5)!=0){
                        printf("Error. Reintente ingresar mes valido: \n");
                        printf("*********************************************************************************************\n");
                    }
                    printf("*********************************************************************************************\n");
                    printf("Mes correctamente cargado.\n");
                    printf("*********************************************************************************************\n");

                    //anio
                    while(utn_getNumero(&auxFecha.anio,"Ingrese anio de realizacion de servicio: (desde 2000 a 2021) : ", "Anio invalido. ",2000,2021,5)!=0){

                        printf("Error. Reintente ingresar anio valido: \n");
                        printf("*********************************************************************************************\n");
                    }
                    printf("*********************************************************************************************\n");
                    printf("Anio correctamente cargado.\n");
                    printf("*********************************************************************************************\n\n");


                    //ID
                     auxTrabajo.id = *pId;
                    (*pId)++;

                    lista[indiceTrabajo] =auxTrabajo;
                    lista[indiceTrabajo].fecha = auxFecha;
                    lista[indiceTrabajo].isEmpty=0;//cambio a 0 para que sepa que esta ocupado


                    altaOk=1;

            }
        }

    return altaOk;
 }

 int buscarLibreTrabajo(eTrabajo lista[], int tam){
    int indice=-1;
    if(lista!=NULL && tam>0){
        for(int i = 0; i<tam; i++){
            if(lista[i].isEmpty){
                indice=i;
                break;
            }
        }
    }
    return indice;

}


int mostrarTrabajos(eTrabajo trabajos[] , int tamT, eServicio servicios[], int tamS, eMascota mascotas[], int tamM){
    int mostrarTrabajos=0;
    int flag=0;


    if(trabajos!=NULL && tamT>0){
                        printf("***********************************************************************************\n");
                        printf("*                                  TRABAJOS                                       *\n");
                        printf("***********************************************************************************\n");
                        printf("ID Trabajo        Fecha               Servicio             Nombre                 *\n");
                        printf("***********************************************************************************\n");
            for(int i = 0; i<tamT; i++){
                    if(trabajos[i].isEmpty==0){
                        mostrarTrabajo(trabajos[i], servicios, tamS, mascotas, tamM);
                        printf("\n");
                        flag=1;
                    }
            }

            if(flag){ //marca que nunca se entro al for, y no hay mascotas
                mostrarTrabajos=1;
            }else{
                 printf("No hay trabajos realizados a mascotas que mostrar\n");
                mostrarTrabajos=0;

            }


    }
    return mostrarTrabajos;
}


void mostrarTrabajo(eTrabajo trabajo, eServicio servicio[], int tamS, eMascota mascotas[], int tamM){
    char descripcionServicio[20];
    char descripcionMascota[20];

    cargarDescripcionServicio(servicio, tamS, trabajo.idServicio, descripcionServicio);
    cargarDescripcionMascota(mascotas, tamM, trabajo.idMascota, descripcionMascota);

    printf("%d          %02d/%02d/%d       %15s    %15s\n", trabajo.id, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio, descripcionServicio, descripcionMascota);
}
