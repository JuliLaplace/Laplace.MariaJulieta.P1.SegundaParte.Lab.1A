#include"menu.h"
#include "validaciones.h"

char menu (){



   char opcion;

    system("cls");
    printf("*********************************************************************************************\n");
    printf("*                                        MASCOTAS                                           *\n");
    printf("*********************************************************************************************\n");


    printf("    A) ALTA MASCOTA.\n");
    printf("    B) MODIFICAR MASCOTA.\n");
    printf("        1) Tipo.\n");
    printf("        2) Vacunado.\n");
    printf("    C) BAJA MASCOTA.\n");
    printf("    D) LISTAR (Por tipo y nombre).\n");
    printf("    E) LISTAR TIPOS\n");
    printf("    F) LISTAR COLORES.\n");
    printf("    G) LISTAR SERVICIO\n");
    printf("    H) ALTA TRABAJO.\n");
    printf("    I) LISTAR TRABAJO.\n");
    printf("    J) INFORMES.\n");
    printf("    K) SALIR.\n");
    printf("*********************************************************************************************\n");
    printf("Ingrese opcion deseada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    opcion = toupper(opcion);
    return opcion;


}




char subMenuModificar(){



   char opcion;

    system("cls");
    printf("*********************************************************************************************\n");
    printf("*                                   Modificar mascota                                        *\n");
    printf("*********************************************************************************************\n");


    printf("    a) Modificar tipo de mascota.\n");
    printf("    b) Modificar vacuna de mascota.\n");
    printf("    c) Volver al menu principal.\n");
    printf("*********************************************************************************************\n");
    printf("Ingrese opcion deseada: ");
   fflush(stdin);
    scanf("%c",&opcion);

    opcion = toupper(opcion);
    return opcion;


}

int subMenuInformes(){
int opcion;



            printf("*****************************************************************************\n");
            printf("Elija la opcion con la que desea realizar un informe: \n");
            printf("1) Mostrar mascotas por color seleccionado por usuario.\n");
            printf("2) Informar promedio de mascotas vacunadas sobre el total de mascotas.\n");
            printf("3) Informar la/las mascotas de menor edad.\n");
            printf("4) Listar mascotas separadas por tipos.\n");
            printf("5) Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo.\n");
            printf("6) Mostrar el o los colores con mas cantidad de mascotas.\n");
            printf("7) Volver al menu principal.\n");
            printf("*****************************************************************************\n");
            while(utn_getNumero(&opcion,"Ingrese de las opciones anteriores, cual desea: ", "Opcion invalida. ",1,7,3)!=0){
                      printf("Error. Reintente ingresar opciones correctas: ");
                    }


return opcion;
}
