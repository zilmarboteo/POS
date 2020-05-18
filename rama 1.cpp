#include <stdio.h>

#include <stdlib.h>

#include <io.h>

#include <conio.h>

#include <string.h>

#include <Windows.h>


void menu();
void CrearFichero(FILE * Fichero);
void OPclientes(FILE * fcliente);
void productos(FILE * fproductos);
void seccion(FILE * fseccion);
void cajas_pago(FILE * fcaja);
void turnos(FILE * fturnos);
void empleados(FILE * fempleados);
void ofertas(FILE * fofertas);
void super_mercados(FILE * fsuper);
void proveedores(FILE * fprove);
void formas_de_pago(FILE * fpago);
void pasillos(FILE * fpasillos);

//Creacion de todos los Archivos
FILE * fichero;
FILE * fcliente;
FILE * fproductos;
/*Se crearon nuevos archivos del submenu de productos*/
FILE * felectro;
FILE * fcocina;
FILE * flimp;
FILE * fcarnes;
FILE * fverduras;
FILE * trn;

FILE * fseccion;
FILE * fcaja;
FILE * fturnos;
FILE * fempleados;
FILE * fofertas;
FILE * fsuper;
FILE * fprove;
FILE * fformas;
FILE * fpasillos;
//*****************************************

struct cliente {
  char tel[8];
  char nit[50];
  char Nombre[25];
  char apellido[25];
  char dir[50];
}
cliente;

struct electro {
  char nombre;
  int precio;
}
electro;

struct cocina {
  char nomcos;
  int preciocos;
}
cocina;

struct turn {
  char name[15];
}
turn;

struct t {
  char nom[15];
}
t;

struct empleado {
  char nombreemp, apellidoemp, cod, cargo;
  int telefonoemp, direccionemp;
}
empleado;

struct supermercado {
  int opcion;
}
supermercado;

struct proveedor {
  char empresa;
  char direccion;
  char Nombre[25];
  int tel;

}
proveedor;

struct formas {
  int opcion;
  int targ, dpi, monto, recibo;
  int mont, efec, recib;
  int op;
}
formas;

//funcion main 
main() {
  int opcion;
  int exit = 0;

  while (!exit) {
    menu();
    //casos
    printf("\nOpcion: ");
    scanf("%d", & opcion);
    switch (opcion) {

    case 1:
      CrearFichero(fichero);
      break;

    case 2:
      OPclientes(fcliente);
      break;

    case 3:
      productos(fproductos);
      break;

    case 4:
      seccion(fseccion);
      break;

    case 5:
      cajas_pago(fcaja);
      break;

    case 6:
      turnos(fturnos);
      break;

    case 7:
      empleados(fempleados);
      break;

    case 8:
      ofertas(fofertas);
      break;

    case 9:
      super_mercados(fsuper);
      break;

    case 10:
      proveedores(fprove);
      break;

    case 11:
      formas_de_pago(fformas);
      break;

    case 12:
      pasillos(fpasillos);
      break;

    case 13:
      exit = 1;
      break;

    default:
      printf("\n opcion no valida");
    }
  }
  return 0;
}
//funcines void 
void menu() {

  retorno9: system("color 35");
  printf("\n\n\t\t____________________________\n");
  printf("\n\t\t   SUPERMERCADOS MAMA LUCHA:\n");
  printf("\n\t\t______________________________\n");
  printf("\n\n\n\t 1. CREAR ARCHIVO");
  printf("\n\t 2. CLIENTES");
  printf("\n\t 3. PRODUCTOS");
  printf("\n\t 4. SECCIONES");
  printf("\n\t 5. CAJAS DE PAGO");
  printf("\n\t 6. TURNOS");
  printf("\n\t 7. EMPLEADOS");
  printf("\n\t 8. OFERTAS");
  printf("\n\t 9. SUPER MERCADOS");
  printf("\n\t 10. PROVEEDORES");
  printf("\n\t 11. FORMAS DE PAGO");
  printf("\n\t 12. PASILLOS");
  printf("\n\t 13. SALIR");

}
/********************************************************************/
void CrearFichero(FILE * Fichero) {
  // crear fichero
  system("cls");
  //creando y cerrando el archivo en disco
  FILE * fichero;
  fichero = fopen("fichero.dat", "w");
  fclose(fichero);
  printf("ARCHIVO CREADO");
  getchar();
  return;
}
/********************************************************************/
void OPclientes(FILE * fcliente) {
  retorno: int opcion1;
  system("cls");
  system("color 13");
  printf("\n\n\t\t___________________\n");
  printf("\n\t\t  C L I E N T E S");
  printf("\n\t\t___________________\n");
  printf("\n\n\n\t 1. CREAR ARCHIVO");
  printf("\n\t 2. INGRESAR");
  printf("\n\t 3. BUSCAR");
  printf("\n\t 4. EDITAR");
  printf("\n\t 5. MOSTRAR TODOS LOS CLIENTES");
  printf("\n\t 6. SALIR");
  printf("\n\n\t\tSELECCIONE UNA OPCION -->  ");
  scanf("%d", & opcion1);
  system("cls");

  // Opciones para el sub-menu de clientes
  switch (opcion1) {

  case 1:
    {
      system("cls");
      //creando y cerrando el archivo en disco
      FILE * fcliente;
      fcliente = fopen("clientes.dat", "at+");
      fclose(fcliente);
      printf("ARCHIVO CREADO");
      goto retorno;
    }
    break;

  case 2:

    {
      system("cls");
      char resp = 's';
      while (resp == 's') {
        // captura de campos
        printf("NO. nit :");
        gets(cliente.nit);
        printf("NOMBRE :");
        gets(cliente.Nombre);
        printf("APELLIDO :");
        gets(cliente.apellido);
        printf("DIRECCION :");
        gets(cliente.dir);
        printf("NO. TELEFONO :");
        gets(cliente.tel);
        printf("\n");

        // grabando a disco
        FILE * fcliente;

        fcliente = fopen("clientes.dat", "at+");

        fwrite( & cliente, sizeof(cliente), 1, fcliente);
        fclose(fcliente);
        //avisando usuario
        printf("cliente insertado");
        getchar();

        printf("\nDesea crear otro contacto s/n ");
        scanf("%s", & resp);
        system("cls");
      } // FIN WHILE
      goto retorno;
      system("cls");

    }
    break;

  case 3:
    {
      system("cls");
      // cargando clave a buscar
      printf("No. NIT QUE DESEA BUSCAR: ");
      char clave;
	  gets(clave);
      //abriendo, leyendo,cargando estructura

      FILE * fcliente;

      fcliente = fopen("clientes.dat", "at+");
      //archdisco = fopen("alumnos.dat","r");

      // aqui siempre debe empezar el ciclo de lectura
      // y fread() regresa siempre cuantas estructuras leyo
      while (fread( & cliente, sizeof(cliente), 1, fcliente) == 1) {
        // desplegando estructura buscada
        if (clave == cliente.nit) {
          printf("NOMBRE =%s ", cliente.Nombre);
          printf(" APELLIDO =%s ", cliente.apellido);
          printf("\n");
        };
      }; // aqui termina while

      // no olvidar cerrar archivo y siempre fuera de while
      fclose(fcliente);
      getchar();
    }
    break;

  case 4:
    {
      system("cls");
      // cargando clave a editar
      printf("INGRESE EL No. DE NIT QUE DESEA EDITAR:");
      char clave;
	  gets(clave);

      FILE * arch1;
      FILE * arch2;
      arch1 = fopen("clientes.dat", "r+");
      arch2 = fopen("temporal.dat", "at+");
      // aqui siempre debe empezar el ciclo de lectura
      // y fread() regresa siempre cuantas estructuras leyo
      while (fread( & cliente, sizeof(cliente), 1, arch1) == 1) {
        if (clave == cliente.nit) {
          printf("INGRESE NUEVO NOMBRE :");
          gets(cliente.Nombre);
          printf("INGRESE NUEVO APELLIDO :");
          gets(cliente.apellido);
          printf("INGRESE No. DE TEL. NUEVO :");
          scanf("%d", & cliente.tel);
          fwrite( & cliente, sizeof(cliente), 1, arch2);
        } else {
          fwrite( & cliente, sizeof(cliente), 1, arch2);
        };
      }; // aqui termina while
      //cerrando archivos
      fclose(arch1);
      fclose(arch2);
      // removiendo y renombrando archivos
      remove("CLIENTES.DAT ");
      rename("TEMPORAL.DAT", "CLIENTES.DAT ");
      //avisando
      puts("REGISTRO EDITADO");
      getchar();getchar();
      return;
    }
    break;

  case 5:
    {
      system("cls");

      FILE * fcliente;

      fcliente = fopen("clientes.dat", "at+");

      //aqui siempre debe empezar el ciclo de lectura y fread() regresa siempre cuantas estructuras leyo

      while (fread( & cliente, sizeof(cliente), 1, fcliente) == 1) {
        //desplegando estructuras
        printf("NOMBRE = %s ", & cliente.Nombre);
        printf("APELLIDO = %s ", & cliente.apellido);
        printf("No. NIT = %s ", & cliente.nit);
        printf("No. TELEFONO = %d", & cliente.tel);
        printf("\n");
      }; //aqui termina while

      //no olvidar cerrar archivo y siempre fuera de while
      fclose(fcliente);
      system("pause");
      system("cls");
      return;
    }
    break;
  }; //FIN SWITCH PRINCIPAL
} // FIN VOID CLIENTE
/********************************************************************/
void productos(FILE * fproductos) {

  int opcion2;
  system("cls");
  system("color 13");
  printf("\n\n\t\t___________________\n");
  printf("\n\t\t  P R O D U C T O S");
  printf("\n\t\t___________________\n");
  printf("\n\n\n\t 1. CREAR ARCHIVO");
  printf("\n\t 2. ELECTRODOMESTICOS");
  printf("\n\t 3. UTENCILIOS DE COCINA");
  printf("\n\t 4. ARTICULOS DE LIMPIEZA");
  printf("\n\t 5. FRUTAS Y VERDURAS");
  printf("\n\t 6. SALIR");
  printf("\n\n\t\tSELECCIONE UNA OPCION -->  ");
  scanf("%d", & opcion2);
  system("cls");

  switch (opcion2) {
  case 1:
    {
      system("cls");
      //creando y cerrando el archivo en disco
      FILE * fproductos;
      fproductos = fopen("productos.dat", "at+");
      fclose(fproductos);
      printf("ARCHIVO CREADO");
      getchar();
      return;
    }
    break;

  case 2:
    {

      int respuesta;
      system("cls");
      system("color 13");
      printf("\n\n\t\t_____________________________\n");
      printf("\n\t\t E L E C T R O D O M E S T I C O S");
      printf("\n\n\t\t_______________________________\n");
      printf("\n 1. CREAR ARCHIVO\n");
      printf("2=INGRESAR NOMBRE PRODUCTO\n3=BUSCAR PRODUCTO\n4=EDITAR\n5=MOSTRAR\n6=SALIR");
      printf("\n\nINGRESE UNA OPCION -->  ");
      scanf("%d", & respuesta);
      system("cls");

      switch (respuesta) {
      case 1:
        {
          system("cls");
          //creando y cerrando el archivo en disco
          FILE * felectro;
          felectro = fopen("electrodomesticos.dat", "w");
          fclose(felectro);
          printf("ARCHIVO CREADO");
          getchar();
          return;
        }
        break;

      case 2:
        {
          system("cls");
          int a = 0;
          char r = 's';
          while (a <= 1) {

            // captura de campos
            printf("NOMBRE ELECTRODOMESTICO :");
            scanf("%s", & electro.nombre);
            getchar();
            printf("\nPRECIO :");
            scanf("%d", & electro.precio);

            // grabando a disco
            FILE * felectro;

            felectro = fopen("electrodomesticos", "at+");

            fwrite( & electro, sizeof(electro), 1, felectro);
            fclose(felectro);
            //avisando usuario
            printf("producto insertado");
            getchar();
            getchar();

            printf("Desea crear otro pruducto s/n ");
            scanf("%s", & r);

            if (r == 'n') {
              break;
              system("cls");
            } // fin if

          } // FIN WHILE
        }
        break;

      case 3:
        {
          system("cls");
          // cargando clave a buscar
          printf("NOMBRE DEL PRODUCTO A BUSCAR: ");
          char c1;scanf("%s", & c1);getchar();
          //abriendo, leyendo,cargando estructura

          FILE * felectro;

          felectro = fopen("electrodomesticos.dat", "at+");
          //archdisco = fopen("alumnos.dat","r");

          // aqui siempre debe empezar el ciclo de lectura
          // y fread() regresa siempre cuantas estructuras leyo
          while (fread( & electro, sizeof(electro), 1, felectro) == 1) {
            // desplegando estructura buscada
            if (c1 == electro.nombre) {
              printf(" PRECIO =%d ", electro.precio);
              printf("\n");
            };
          }; // aqui termina while

          // no olvidar cerrar archivo y siempre fuera de while
          fclose(felectro);
          getchar();
        }
        break;

      case 4:
        {
          system("cls");
          // cargando clave a editar
          printf("INGRESE EL NOMBRE DEL ELECTRODOMESTICO QUE DESEE EDITAR");
          char c1;scanf("%s", & c1);getchar();
          FILE * ar1;
          FILE * ar2;
          ar1 = fopen("electrodomesticos.dat", "r+");
          ar2 = fopen("temp1.dat", "at+");
          // aqui siempre debe empezar el ciclo de lectura
          // y fread() regresa siempre cuantas estructuras leyo
          while (fread( & electro, sizeof(electro), 1, ar1) == 1) {
            if (c1 == electro.nombre) {
              printf("INGRESE NUEVO NOMBRE :");
              scanf("%s", electro.nombre);
              printf("INGRESE NUEVO PRECIO :");
              scanf("%d", & electro.precio);
              fwrite( & electro, sizeof(electro), 1, ar2);
            } else {
              fwrite( & electro, sizeof(electro), 1, ar2);
            };
          }; // aqui termina while
          //cerrando archivos
          fclose(ar1);
          fclose(ar2);
          // removiendo y renombrando archivos
          remove("ELECTRODOMESTICOS.DAT ");
          rename("TEMP.DAT", "ELECTRODOMESTICOS.DAT ");
          //avisando
          puts("REGISTRO EDITADO");
          getchar();getchar();
          return;
        }
        break;

      case 5:
        {
          system("cls");

          FILE * felectro;

          felectro = fopen("electrodomesticos.dat", "at+");

          //aqui siempre debe empezar el ciclo de lectura y fread() regresa siempre cuantas estructuras leyo

          while (fread( & electro, sizeof(electro), 1, felectro) == 1) {

            //desplegando estructuras
            printf("NOMBRE = %s ", electro.nombre);
            printf("PRECIO = %d ", electro.precio);
            printf("\n");
          }; //aqui termina while

          //no olvidar cerrar archivo y siempre fuera de while
          fclose(felectro);
          system("pause");
          return;
        }
        break;

      } // FIN CASE 1 DEL CASO 2 SEGUNDO MENU
    } //FIN CASE 2 DEL MENU PRODUCTOS

    //**********************************************

  case 3:
    {

      int respuesta1;
      system("cls");
      system("color 13");
      printf("\n\n\t\t_______________________________\n");
      printf("\n\t\tU T E N S I L I O S  D E  C O C I N A ");
      printf("\n\t\t________________________________\n");
      printf("\n 1. CREAR ARCHIVO\n");
      printf("2=INGRESAR NOMBRE PRODUCTO\n3=BUSCAR PRODUCTO\n4=EDITAR\n5=MOSTRAR\n6=SALIR");
      printf("\nINGRESE UNA OPCION -->  ");
      scanf("%d", & respuesta1);
      system("cls");

      switch (respuesta1) {
      case 1:
        {
          system("cls");
          //creando y cerrando el archivo en disco
          FILE * fcocina;
          fcocina = fopen("cocina.dat", "w");
          fclose(fcocina);
          printf("ARCHIVO CREADO");
          getchar();
          return;
        }
        break;

      case 2:
        {
          system("cls");
          int b = 0;
          char re = 's';
          while (b <= 1) {

            // captura de campos
            printf("NOMBRE DEL UTENCILIO :");
            scanf("%s", & cocina.nomcos);
            getchar();
            printf("\nPRECIO :");
            scanf("%d", & cocina.preciocos);

            // grabando a disco
            FILE * fcocina;

            fcocina = fopen("cocina", "at+");

            fwrite( & cocina, sizeof(cocina), 1, fcocina);
            fclose(fcocina);
            //avisando usuario
            printf("producto insertado");
            getchar();
            getchar();

            printf("Desea crear otro pruducto s/n ");
            scanf("%s", & re);

            if (re == 'n') {
              break;
              system("cls");
            } // fin if

          } // FIN WHILE
        }
        break;

      case 3:
        {
          system("cls");
          // cargando clave a buscar
          printf("NOMBRE DEL PRODUCTO A BUSCAR: ");
          char c2;scanf("%s", & c2);getchar();
          //abriendo, leyendo,cargando estructura

          FILE * fcocina;

          fcocina = fopen("cocina.dat", "at+");
          //archdisco = fopen("alumnos.dat","r");

          // aqui siempre debe empezar el ciclo de lectura
          // y fread() regresa siempre cuantas estructuras leyo
          while (fread( & cocina, sizeof(cocina), 1, fcocina) == 1) {
            // desplegando estructura buscada
            if (c2 == cocina.nomcos) {
              printf(" PRECIO =%d ", cocina.preciocos);
              printf("\n");
            };
          }; // aqui termina while

          // no olvidar cerrar archivo y siempre fuera de while
          fclose(fcocina);
          getchar();
        }
        break;

      case 4:
        {
          system("cls");
          // cargando clave a editar
          printf("INGRESE EL NOMBRE DEL UTENSILIO DE COCINA QUE DESEE EDITAR");
          char c2;scanf("%s", & c2);getchar();
          FILE * a1;
          FILE * a2;
          a1 = fopen("cocina.dat", "r+");
          a2 = fopen("temp2.dat", "at+");
          // aqui siempre debe empezar el ciclo de lectura
          // y fread() regresa siempre cuantas estructuras leyo
          while (fread( & cocina, sizeof(cocina), 1, a2) == 1) {
            if (c2 == cocina.nomcos) {
              printf("INGRESE NUEVO NOMBRE :");
              scanf("%s", & cocina.nomcos);
              printf("INGRESE NUEVO PRECIO :");
              scanf("%d", & cocina.preciocos);
              fwrite( & cocina, sizeof(cocina), 1, a2);
            } else {
              fwrite( & cocina, sizeof(cocina), 1, a2);
            };
          }; // aqui termina while
          //cerrando archivos
          fclose(a1);
          fclose(a2);
          // removiendo y renombrando archivos
          remove("COCINA.DAT ");
          rename("TEMP1.DAT", "COCINA.DAT ");
          //avisando
          puts("REGISTRO EDITADO");
          getchar();getchar();
          return;
        }
        break;

      case 5:
        {
          system("cls");

          FILE * fcocina;

          felectro = fopen("cocina.dat", "at+");

          //aqui siempre debe empezar el ciclo de lectura y fread() regresa siempre cuantas estructuras leyo

          while (fread( & cocina, sizeof(cocina), 1, fcocina) == 1) {

            //desplegando estructuras
            printf("NOMBRE = %s ", cocina.nomcos);
            printf("PRECIO = %d ", cocina.preciocos);
            printf("\n");
          }; //aqui termina while

          //no olvidar cerrar archivo y siempre fuera de while
          fclose(fcocina);
          getchar();
          system("pause");
          return;
        }
        break;

      } // FIN case 1 DEL CASE 3
    } // FIN CASE 3

  } // FIN CASO 
} // FIN VOID PRODUCTOS
/********************************************************************/
void seccion(FILE * fseccion) {

  int cont;
  system("cls");
  system("color 13");
  printf("\n\n\t\t____________________________\n");
  printf("\n\t\t  S  E  C  C  I  I  O  N  E  S");
  printf("\n\t\t______________________________\n\n\n");
  printf("1= SECCION A ->  ELECTRODOMESTICOS \n2= SECCION B -> UTNSILIOS DE COCINA\n3= SALIR");
  printf("\nINGRESE UNA OPCION -->  ");
  scanf("%d", & cont);
  system("cls");

  switch (cont) {
  case 1:
    {

      printf("1. LICUADORAS\n");
      printf("2. PLANCHAS\n");
      printf("3. LAVADORAS\n");
      printf("4. TELEVISORES\n");
      printf("5. MICROONDAS\n");
      printf("6. EQUIPOS DE SONIDO\n");
      printf("7. CAFETERAS\n");
      printf("8. ASPIRADORAS\n");
      printf("9. REFRIGERADORES\n");
      printf("10. TOSTADORES");
      printf("\n");
      system("pause");
      return;

    }
    break;

  case 2:
    {
      printf("1. OLLA DE PRESION\n");
      printf("2. OLLAS\n");
      printf("3. CUBIERTOS\n");
      printf("4. SARTEN\n");
      printf("5. PINZAS\n");
      printf("6. VASOS Y PLATOS\n");
      printf("7. TABLA PARA CORTAR\n");
      printf("8. BATIDOR\n");
      printf("9. RALLADORES\n");
      printf("10. MOLDES PARA HORNEAR");
      printf("/n");
      system("pause");
      return;

    }
    break;
  } // fin switch
  return;
} // FIN VOID SECCION
/********************************************************************/
void cajas_pago(FILE * fcaja) {

  int opcion3;
  system("cls");
  system("color 13");
  printf("\n\n\t\t____________________________\n");
  printf("\n\t\t  B I E N V E N I D O  A  C A J A");
  printf("\n\t\t______________________________\n\n\n");
  printf("1= CAJA 1 \n2= CAJA 2 \n3= CAJA 3 \n4= SALIR");
  printf("\nINGRESE UNA OPCION -->  ");
  scanf("%d", & opcion3);
  system("cls");

  switch (opcion3) {
  case 1:
    {
      printf("\nLe atiende JOSE FLORES\n");
      getchar();
      system("pause");
      return;

    }
    break;

  case 2:
    {
      printf("\nLe atiende Sara Rodriguez\n");
      getchar();
      system("pause");
      return;
    }
    break;

  case 3:
    {
      printf("\nLe atiende Mishell Garcia");
      system("pause");
      return;
    }
    break;

  } // FIN switch
} // FIN VOID CAJA
/********************************************************************/
void turnos(FILE * fturnos) {

  int opcion4;
  system("cls");
  system("color 13");
  printf("\n\n\t\t___________________\n");
  printf("\n\t\t  T  U  R  N  O  S");
  printf("\n\t\t___________________\n");
  printf("\n\n\n\t 1. CREAR ARCHIVO");
  printf("\n\t 2.Turnos de 8:00 am a 2:00 pm ");
  printf("\n\t 3.Turnos de 2:00 pm a 8:00 pm ");
  printf("\n\t 4. SALIR");
  printf("\n\n\t\tSELECCIONE UNA OPCION -->  ");
  scanf("%d", & opcion4);
  system("cls");

  // Opciones para el sub-menu de clientes
  switch (opcion4) {
  case 1:
    {
      system("cls");
      //creando y cerrando el archivo en disco
      FILE * fturnos;
      fturnos = fopen("turnos.dat", "at+");
      fclose(fturnos);
      printf("ARCHIVO CREADO");
      getchar();
      return;
    }
    break;

  case 2:
    {
      int ct;

      printf("I N F O R M A C I O N \n");
      printf("\n1= INGRESAR TRABAJADORES \n2= MOSTRAR TRABAJADORES \n3= SALIR\n");
      printf("\nINGRESE LA OPCION QUE DESEE ->: ");
      scanf("%d", & ct);
      system("cls");
      switch (ct) {

      case 1:

        {

          system("cls");
          int c = 0;
          char contest = 's';
          while (c <= 1) {

            // captura de campos
            printf("NOMBRE :");
            scanf("%s", & turn.name);

            // grabando a disco
            FILE * fturnos;

            fturnos = fopen("turnos.dat", "at+");

            fwrite( & turn, sizeof(turn), 1, fturnos);
            fclose(fturnos);
            //avisando usuario
            printf("\nTURNO insertado\n\n");

            printf("Desea agregar otro s/n ");
            scanf("%s", & contest);

            if (contest == 'n') {
              break;
              system("cls");
            } // fin if

          } // fin while
        }
        break; // fin case 2

      case 2:
        {

          system("cls");

          FILE * fturnos;

          fturnos = fopen("turnos.dat", "at+");

          //aqui siempre debe empezar el ciclo de lectura y fread() regresa siempre cuantas estructuras leyo

          while (fread( & turn, sizeof(turn), 1, fturnos) == 1) {
            //desplegando estructuras
            printf("NOMBRE = %s ", turn.name);

            printf("\n");
          }; //aqui termina while

          //no olvidar cerrar archivo y siempre fuera de while
          fclose(fturnos);
          system("pause");
          return;
          getchar();

        }
        break; // fin case 3

      }
      break;
    } // fin switch case 2

  case 3:
    {

      int ct;

      printf("I N F O R M A C I O N \n");
      printf("\n1= INGRESAR TRABAJADORES \n2= MOSTRAR TRABAJADORES \n3= SALIR\n");
      printf("\nINGRESE LA OPCION QUE DESEE ->: ");
      scanf("%d", & ct);
      system("cls");
      switch (ct) {

      case 1:

        {

          system("cls");
          int m = 0;
          char cos = 's';
          while (m <= 1) {

            // captura de campos
            printf("NOMBRE :");
            scanf("%s", & t.nom);

            // grabando a disco
            FILE * frn;

            trn = fopen("tur.dat", "at+");

            fwrite( & t, sizeof(t), 1, trn);
            fclose(trn);
            //avisando usuario
            printf("\nTURNO insertado\n\n");

            printf("Desea agregar otro s/n ");
            scanf("%s", & m);

            if (cos == 'n') {
              break;
              system("cls");
            } // fin if

          } // fin while
        }
        break; // fin case 2

      case 2:
        {

          system("cls");

          FILE * trn;

          trn = fopen("tur.dat", "at+");

          //aqui siempre debe empezar el ciclo de lectura y fread() regresa siempre cuantas estructuras leyo

          while (fread( & t, sizeof(t), 1, trn) == 1) {
            //desplegando estructuras
            printf("NOMBRE = %s ", t.nom);

            printf("\n");
          }; //aqui termina while

          //no olvidar cerrar archivo y siempre fuera de while
          fclose(trn);
          system("pause");
          return;
          getchar();

        }
        break; // fin case 3

      }
      break;
    } // fin switch case 2

  } // fin switch
} // fin void turnos
/********************************************************************/
void empleados(FILE * fempleados) {
  retorno: int p;
  system("cls");
  system("color 13");
  printf("\n\n\t\t___________________\n");
  printf("\n\t\t  E M P L E A D O S");
  printf("\n\t\t___________________\n");
  printf("\n\n\n\t 1. CREAR ARCHIVO");
  printf("\n\t 2. INGRESAR");
  printf("\n\t 3. BUSCAR");
  printf("\n\t 4. EDITAR");
  printf("\n\t 5. MOSTRAR TODOS LOS CLIENTES");
  printf("\n\t 6. SALIR");
  printf("\n\n\t\tSELECCIONE UNA OPCION -->  ");
  scanf("%d", & p);
  system("cls");

  // Opciones para el sub-menu de clientes
  switch (p) {

  case 1:
    {
      system("cls");
      //creando y cerrando el archivo en disco
      FILE * fempleados;
      fempleados = fopen("empleados.dat", "at+");
      fclose(fempleados);
      printf("ARCHIVO CREADO");
      system("pause");
      goto retorno;
    }
    break;

  case 2:

    {

      system("cls");
      int n = 0;
      char re = 's';
      while (n <= 1) {

        // captura de campos
        printf("NOMBRE EMPLEADO :");
        scanf("%s", & empleado.nombreemp);
        getchar();
        printf("DIRECCION :");
        scanf("%s", & empleado.apellidoemp);
        printf("DIRECCION :");
        scanf("%s", & empleado.direccionemp);
        printf("NO. TELEFONO :");
        scanf("%d", & empleado.telefonoemp);
        printf("CODIGO :");
        scanf("%s", & empleado.cod);
        printf("CARGO  :");
        scanf("%s", & empleado.cargo);
        // grabando a disco
        FILE * fempleados;

        fempleados = fopen("empleados.dat", "at+");

        fwrite( & empleado, sizeof(empleado), 1, fempleados);
        fclose(fempleados);
        //avisando usuario
        printf("Empleado insertado");
        getchar();
        getchar();

        printf("Desea ingresar otro Empleado s/n ");
        scanf("%s", & re);

        if (re == 'n') {
          goto retorno;
          system("cls");
        } // fin if

      } // FIN WHILE
    }
    break;

  case 3:
    {
      system("cls");
      // cargando clave a buscar
      printf("INGRESE EL CODIGO DEL EMPLEADO: ");
      char cla;scanf("%s", & cla);getchar();
      //abriendo, leyendo,cargando estructura

      FILE * fempleados;

      fempleados = fopen("empleados.dat", "at+");
      //archdisco = fopen("alumnos.dat","r");

      // aqui siempre debe empezar el ciclo de lectura
      // y fread() regresa siempre cuantas estructuras leyo
      while (fread( & empleado, sizeof(empleado), 1, fempleados) == 1) {
        // desplegando estructura buscada
        if (cla == empleado.cod) {
          printf("NOMBRE =%s ", empleado.nombreemp);
          printf(" APELLIDO =%s ", empleado.apellidoemp);
          printf("\n");
          system("pause");
          return;
        };
      }; // aqui termina while

      // no olvidar cerrar archivo y siempre fuera de while
      fclose(fempleados);
      getchar();
    }
    break;

  case 4:
    {
      system("cls");
      // cargando clave a editar
      printf("INGRESE EL CODIGO DEL EMPLEADO QUE DESEE EDITAR");
      char c4;scanf("%s", & c4);getchar();
      FILE * ah1;
      FILE * ah2;
      ah1 = fopen("empleados.dat", "r+");
      ah2 = fopen("tep2.dat", "at+");
      // aqui siempre debe empezar el ciclo de lectura
      // y fread() regresa siempre cuantas estructuras leyo
      while (fread( & empleado, sizeof(empleado), 1, ah2) == 1) {
        if (c4 == empleado.cod) {
          printf("INGRESE NUEVO NOMBRE :");
          scanf("%s", & empleado.nombreemp);
          printf("INGRESE NUEVO APELLLIDO :");
          scanf("%s", & empleado.apellidoemp);
          printf("INGRESE NUEVA DIRECCION :");
          scanf("%s", & empleado.direccionemp);
          printf("INGRESE NUEVO No. TELEFONO :");
          scanf("%d", & empleado.telefonoemp);
          fwrite( & cocina, sizeof(cocina), 1, ah2);
        } else {
          fwrite( & empleado, sizeof(empleado), 1, ah2);
        };
      }; // aqui termina while
      //cerrando archivos
      fclose(ah1);
      fclose(ah2);
      // removiendo y renombrando archivos
      remove("EMPLEADOS.DAT ");
      rename("TEP2.DAT", "EMPLEADOS.DAT ");
      //avisando
      puts("REGISTRO EDITADO");
      getchar();getchar();
      return;
    }
    break;

  case 5:
    {
      system("cls");

      FILE * fempleados;

      fempleados = fopen("empleados.dat", "at+");

      //aqui siempre debe empezar el ciclo de lectura y fread() regresa siempre cuantas estructuras leyo

      while (fread( & empleado, sizeof(empleado), 1, fempleados) == 1) {
        //desplegando estructuras
        printf("NOMBRE = %s ", & empleado.nombreemp);
        printf("APELLIDO = %s ", & empleado.apellidoemp);
        printf("CARGO = %s ", & empleado.cargo);
        printf("No. TELEFONO = %d", & empleado.nombreemp);
        printf("\n");
      }; //aqui termina while

      //no olvidar cerrar archivo y siempre fuera de while
      fclose(fcliente);
      system("pause");
      return;
    }
    break;
  }; //FIN SWITCH PRINCIPAL	
} // FIN VOID EMPLEADOS
/********************************************************************/
void ofertas(FILE * fofertas) {
  int cont;
  system("cls");
  system("color 13");
  printf("\n\n\t\t____________________________\n");
  printf("\n\t\t  S  E  C  C  I  I  O  N  E  S");
  printf("\n\t\t______________________________\n\n\n");
  printf("1= ELECTRODOMESTICOS \n2=  UTENSILIOS DE COCINA\n3= SALIR");
  printf("\nINGRESE UNA OPCION -->  ");
  scanf("%d", & cont);
  system("cls");

  switch (cont) {
  case 1:
    {
      int prec,
      por,
      total;

      printf("****************** 10  DESCUENTO  **********************");
      printf("\n1. LICUADORAS\n");
      printf("2. PLANCHAS\n");
      printf("3. LAVADORAS\n");
      printf("4. TELEVISORES\n");

      printf("\nINGRESE EL PRECIO DEL PRODUCTO PARA VER SU DESCUENTO: ");
      scanf("%d", & prec);

      if (prec > 0) {
        por = (prec * 0.10);
        total = prec - por;

      }

      printf("EL VALOR DEL PRODUCTO CON DESCUENTO ES Q.: %d\n\n", total);

      system("pause");
      return;

    }
    break;

  case 2:
    {
      int precio,
      porcentaje,
      prectotal;

      printf("\n\n **************  -15 DESCUENTO *******************\n\n");
      printf("1. OLLA DE PRESION\n");
      printf("2. OLLAS\n");
      printf("3. CUBIERTOS\n");

      printf("\nINGRESE EL PRECIO DEL PRODUCTO PARA VER SU DESCUENTO: ");
      scanf("%d", & precio);

      if (precio > 0) {
        porcentaje = (precio * 0.15);
        prectotal = precio - porcentaje;

      }

      printf("EL VALOR DEL PRODUCTO CON DESCUENTO ES Q.: %d\n\n", prectotal);
      printf("/n");
      system("pause");
      return;

    }
    break;
  } // fin switch
  return;
} // FIN VOID OFERTAS
//*******************************************************************/
void super_mercados(FILE * fsuper) {

  fsuper = fopen("fsuper.txt", "at+");
  if (fsuper == NULL) {

    printf("\nFichero no existe!\n Por favor Creelo");
    return;
  } else {
    int op;
    int i = 0;
    char resp = 's';
    while (i <= 3) {
      printf("\n+-------------------------------------------------------------+");
      printf("\n|                     SUPERMERCADOS                           |");
      printf("\n+-------------------------------------------------------------+\n");
      printf("\n1. SUPERMERCADO MAMA LUCHA Carretera el Salvador ");
      printf("\n2. SUPERMERCADO MAMA LUCHA Zona 10");
      printf("\n3. SUPERMERCADO MAMA LUCHA Zona 11");
      printf("\nElija la opcion que desea -->  ");
      scanf("%d", & op);
      if (op == 1) {
        printf("\n\n1. SUPERMERCADO MAMA LUCHA Carretera el Salvador ");
        printf("\nKm. 20.5 Carretera a El Salvador");
        printf("\n13 Km Fraijanes");
        printf("\nAbierto hasta las 8:30 pm");
        printf("\nTelefonos\n\n\n");
      } else
      if (op == 2) {
        printf("\n2. SUPERMERCADO MAMA LUCHA Zona 10 ");
        printf("\n20 avenida 18-46, Zona 10");
        printf("\n20 Km, Guatemala");
        printf("\nAbierto hasta las 8:00 pm");
        printf("\nTelefonos\n\n\n");

      } else {
        printf("\n3. SUPERMERCADO MAMA LUCHA Mira Flores");
        printf("\n21 avenida 7-90 Zona 11 Miraflores");
        printf("\n27 Km, Guatemala");
        printf("\nAbieerto hasta las 8:00 Pm");
        printf("\nTelefonos\n\n\n");
      }

      printf("\n Desea Ver otra sucursal s/n:  ");
      scanf("%s", & resp);

      printf("\n  ");

      if (resp == 'n') {
        break;
        system("cls");
      }
    }

  }
}
/********************************************************************/
void proveedores(FILE * fprove) {

  retorno: int pt;
  system("cls");
  system("color 13");
  printf("\n\n\t\t___________________\n");
  printf("\n\t\t  P R O V E D O R E S");
  printf("\n\t\t___________________\n");
  printf("\n\n\n\t 1. CREAR ARCHIVO");
  printf("\n\t 2. INGRESAR");
  printf("\n\t 3. BUSCAR");
  printf("\n\t 4. EDITAR");
  printf("\n\t 5. MOSTRAR TODOS LOS PROVEEDORES");
  printf("\n\t 6. SALIR");
  printf("\n\n\t\tSELECCIONE UNA OPCION -->  ");
  scanf("%d", & pt);
  system("cls");

  // Opciones para el sub-menu de clientes
  switch (pt) {

  case 1:
    {
      system("cls");
      //creando y cerrando el archivo en disco
      FILE * fprove;
      fprove = fopen("proveedores.dat", "at+");
      fclose(fprove);
      printf("ARCHIVO CREADO");
      system("pause");
      goto retorno;
    }
    break;

  case 2:

    {

      system("cls");
      int v = 0;
      char sp = 's';
      while (v <= 1) {

        // captura de campos
        printf("NOMBRE Y APELLIDO DEL PROVEEDOR :");
        scanf("%s", & proveedor.Nombre);
        getchar();
        printf("EMPRESA :");
        scanf("%s", & proveedor.empresa);
        printf("DIRECCION :");
        scanf("%s", & proveedor.direccion);
        printf("NO. TELEFONO :");
        scanf("%d", & empleado.telefonoemp);
        // grabando a disco
        FILE * fprove;

        fprove = fopen("proveedores.dat", "at+");

        fwrite( & proveedor, sizeof(proveedor), 1, fprove);
        fclose(fprove);
        //avisando usuario
        printf("proveedor insertado");
        getchar();
        getchar();

        printf("Desea ingresar otro Proveedor s/n ");
        scanf("%s", & sp);

        if (sp == 'n') {
          goto retorno;
          system("cls");
        } // fin if

      } // FIN WHILE
    }
    break;

  case 3:
    {
      system("cls");
      // cargando clave a buscar
      printf("INGRESE EL NOMBRE DE LA EMPRESA: ");
      char la;scanf("%s", & la);getchar();
      //abriendo, leyendo,cargando estructura

      FILE * fprove;

      fprove = fopen("proveedores.dat", "at+");
      //archdisco = fopen("alumnos.dat","r");

      // aqui siempre debe empezar el ciclo de lectura
      // y fread() regresa siempre cuantas estructuras leyo
      while (fread( & proveedor, sizeof(proveedor), 1, fprove) == 1) {
        // desplegando estructura buscada
        if (la == proveedor.empresa) {
          printf("NOMBRE =%s ", proveedor.Nombre);
          printf(" DIRECCION =%s ", proveedor.direccion);
          printf(" No. DE TELEFONO =%d ", proveedor.tel);
          printf("\n");
          system("pause");
          return;
        };
      }; // aqui termina while

      // no olvidar cerrar archivo y siempre fuera de while
      fclose(fprove);
      getchar();
    }
    break;

  case 4:
    {
      system("cls");
      // cargando clave a editar
      printf("INGRESE EL NOMBRE DE LA EMPRESA");
      char la;scanf("%s", & la);getchar();
      FILE * h1;
      FILE * h2;
      h1 = fopen("proveedores.dat", "r+");
      h2 = fopen("p2.dat", "at+");
      // aqui siempre debe empezar el ciclo de lectura
      // y fread() regresa siempre cuantas estructuras leyo
      while (fread( & proveedor, sizeof(proveedor), 1, h2) == 1) {
        if (la == proveedor.empresa) {
          printf("INGRESE NUEVO NOMBRE :");
          scanf("%s", & proveedor.Nombre);
          printf("INGRESE NUEVA DIRECCION :");
          scanf("%s", & proveedor.direccion);
          printf("INGRESE NUEVO No. TELEFONO :");
          scanf("%d", & proveedor.tel);
          fwrite( & proveedor, sizeof(proveedor), 1, h2);
        } else {
          fwrite( & proveedor, sizeof(proveedor), 1, h2);
        };
      }; // aqui termina while
      //cerrando archivos
      fclose(h1);
      fclose(h2);
      // removiendo y renombrando archivos
      remove("PROVEEDORES.DAT ");
      rename("P2.DAT", "PROVEEDORES.DAT ");
      //avisando
      puts("REGISTRO EDITADO");
      getchar();getchar();
      return;
    }
    break;

  case 5:
    {
      system("cls");

      FILE * fprove;

      fprove = fopen("proveedores.dat", "at+");

      //aqui siempre debe empezar el ciclo de lectura y fread() regresa siempre cuantas estructuras leyo

      while (fread( & proveedor, sizeof(proveedor), 1, fprove) == 1) {
        //desplegando estructuras
        printf("NOMBRE = %s ", & proveedor.Nombre);
        printf("DIRECCION = %s ", & proveedor.direccion);
        printf("EMPRESA = %s ", & proveedor.empresa);
        printf("No. TELEFONO = %d", & proveedor.tel);
        printf("\n");
      }; //aqui termina while

      //no olvidar cerrar archivo y siempre fuera de while
      fclose(fprove);
      system("pause");
      return;
    }
    break;
  }; //FIN SWITCH PRINCIPAL

  // FIN VOID EMPLEADOS
}
/********************************************************************/
void formas_de_pago(FILE * fpago) {

  fpago = fopen("fpago.txt", "at+");
  if (fpago == NULL) {
    printf("\nFichero no existe!\n Por favor Creelo");
    return;
  } else {
    int op;
    int i = 0;
    char resp = 's';
    while (i <= 2) {
      printf("\n1.TARJETA:\n");

      printf("\n2.EFECTIVO");

      printf("\nIngrese la Opcion que Desee:\n");
      scanf("%d", & formas.op);

      if (formas.op == 1) {
        printf("\nIngrese Tarjeta:");
        scanf("%d", & formas.targ);
        printf("\nIngrese DPI:");
        scanf("%d", & formas.dpi);
        printf("\nIngrese Monto:\n");
        scanf("%d", & formas.monto);
        printf("\nImprimir Recibo\n si/no :");
        scanf("%d", & formas.recibo);

      }
      if (formas.op == 2) {

        printf("\nIngrese Monto:");
        scanf("%d", & formas.mont);
        printf("\nPresente el Efectivo");
        printf("\nImprimir Recibo\n si/no :");
        scanf("%d", & formas.recib);

      }

      printf("\nDesea hacer Otro Pago: s/n ");
      scanf("%s", & formas.opcion);
      fwrite( & formas, sizeof(struct formas), 1, fpago);
      printf("\n  ");

      if (formas.opcion == 'n') {
        break;
        system("cls");
      }
    }
  }
}
/********************************************************************/
void pasillos(FILE * fpasillos) {

  int elecc;
  retorno:
    system("cls");
  system("color 13");
  printf("\n\n\t\t___________________\n");
  printf("\n\t\t  P A S I L L O S");
  printf("\n\t\t___________________\n");
  printf(" 1. CREAR ARCHIVO\n\n");
  printf(" 2. MOSTRAR PASILLOS\n\n");
  printf("INGRESE OPCION -->  ");
  scanf("%d", & elecc);
  system("cls");

  switch (elecc) {

  case 1:
    {
      system("cls");
      //creando y cerrando el archivo en disco
      FILE * fpasillos;
      fpasillos = fopen("pasillos.dat", "w");
      fclose(fpasillos);
      printf("ARCHIVO CREADO");
      system("pause");
      return;

    }
    break;

  case 2:
    {
      system("cls");
      printf("Pasillo 1 ELECTRODOMESTICOS\n");
      printf("pasillo 2. ART. DE COSINA\n");
      printf("Pasillo 3. ART, DE LIMPIEZA\n");
      printf("Pasillo 4. CARNES\n");
      printf("Pasillo 5. VERDURAS Y FRUTAS\n");
      system("pause");
      return;
    }
    break;
  }

}
