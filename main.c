#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>


void cargaMatrizUsuario(int filas, int columnas, int m[filas][columnas]);
void muestraMatriz(int filas, int columnas, int m[filas][columnas]);
void cargaMatrizRandom(int filas, int columnas, int m[filas][columnas]);
void intercambioStrings (char string1[], char string2[]);
void ordenaArregloStringPorSeleccion (int dimension, char a[][dimension], int v);
void insertaOrdenado ( int dimension, char a[][dimension], int v, char dato[]);
void ordenarPorInsercion ( int dimension, char a[][dimension], int v);
int sumaMatriz(int filas, int columnas, int m[filas][columnas]);
int buscarMatriz(int filas, int columnas, int m[filas][columnas], int dato);
int buscaPosicionMenorArregloString2 (int d, char a[][d], int v, int comienzo);
int cargaArregloChar (int d, char c[][d], int v, int DIM, char label[]);
int buscarStringenArreglo(int d, char a[][d],int v, char dato []);
float promedioMatriz(int filas, int columnas, int t);

const DIM = 100;
const SDIM = 30;

int main()
{
    //Declaraci�n, carga y muestra de matriz: Ejercicio 1 y 2.
    srand(time((NULL)));
    int filas = 5;
    int columnas = 5;
    int matriz[filas][columnas];
    int dato = 5;

    //cargaMatrizUsuario(filas, columnas, matriz);
    cargaMatrizRandom(filas, columnas, matriz);
    printf("\n Listado de la Matriz \n\n");
    muestraMatriz(filas, columnas, matriz);
    printf("\n");
    //Suma y promedio: Ejercicios 4 y 5.
    int suma = sumaMatriz(filas, columnas, matriz);
    printf("\nLa suma de los elementos de la matriz es %i", suma);
    float promedio = promedioMatriz(filas, columnas, suma);
    printf("\nEl promedio de los elementos de la matriz es %.2f\n", promedio);

    //Busqueda de un dato en la matriz: Ejercicio 6.
    printf("El dato a buscar es: %d", dato);
    if(buscarMatriz(filas, columnas, matriz, dato) == 1){
        printf("\nEl dato se encuentra en la matriz\n");
        } else {
            printf("\nEl dato no se encuentra en la matriz\n");
            }

    //Declaracion, carga y muestra de matriz de palabras: STRINGS. Ejercicio 7 y 8.
    char nombre [DIM][SDIM];
    int vNombres = 0;

    vNombres = cargaArregloChar(SDIM, nombre, vNombres, DIM, "Ingrese un nombre:");
    printf("\n <<< Listado de nombres:>>>\n");
    muestraArregloString(SDIM, nombre, vNombres);
    printf("\n");

    //Buscar un string en un arreglo de strings: Ejercicio 9.
    int flag = buscarStringenArreglo(SDIM, nombre, vNombres, "juan" );
    if ( flag == 0){
        printf("El dato se encuentra");
    } else {
        printf("El dato no se encuentra");
        }

   return 0;
}

//Ejercicio 1
void cargaMatrizUsuario(int filas, int columnas, int m[filas][columnas])
{
    char opcion = 0;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            while (opcion !=27){
                printf("\n Ingrese un dato: \n");
                scanf("%d", &m[i][j]);
                j++;

                printf("\n ESC para salir o cualquier tecla para continuar\n");
                opcion = getch();
                system("cls");
            }
        }
    }
}

//Ejercicio 2
void muestraMatriz(int filas, int columnas, int m[filas][columnas])
{
   for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if (j % 10 == 0){
                printf("\n");
            }
        printf("%3i | ", m[i][j]);
        }
    }
}
//Ejercicio 3
void cargaMatrizRandom(int filas, int columnas, int m[filas][columnas])
{
   for(int i = 0; i < filas; i++){
  	for(int j = 0; j < columnas; j++){
       	m[i][j] = rand() % 20;
  	}
   }
}

//Ejercicio 4
int sumaMatriz(int filas, int columnas, int m[filas][columnas])
{
   int total = 0;

   for(int i = 0; i < filas; i++){
  	for(int j = 0; j < columnas; j++){
       	total += m[i][j];
  	}
   }
   return total;
}

//Ejercicio 5
float promedioMatriz(int filas, int columnas, int t)
{
   int sumaElementos = filas * columnas;

   float promedio = (float) t / sumaElementos;

   return promedio;
}

//Ejercicio 6
int buscarMatriz(int filas, int columnas, int m[filas][columnas], int dato)
{
   int flag = 0;
   for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(m[i][j] == dato){
                flag = 1;
            }
        }
   }
   return flag;
}
//Ejercicio 7
int cargaArregloChar (int d, char c[][d], int v, int DIM, char label[])
{
    char opcion = 0;
    char s[d];
    while ( v < DIM && opcion != 27){
        printf("\n %s \n", label);
        fflush(stdin);
        //scanf("%s", c[v]);
        gets(s);
        if (strlen(s)<d){
            strcpy(c[v],s);
            v++;
        } else {
            printf("\n Se excedio de dimension\n");
            getch();
        }

        printf("\n ESC para salir o cualquier tecla para continuar\n");
        opcion = getch();
        system("cls");
    }
    return v;
}
//Ejercicio 8.
void muestraArregloString (int d, char nombre[][30], int v)
{
    for(int i = 0; i < v; i++){
        printf("\n %s \n", nombre[i]);
    }
    printf("\n==================================");
}
//Ejercicio 9.
int buscarStringenArreglo(int d, char a[][d],int v, char dato [])
{
    int flag = 0;
    int i = 0;

        while (i < v && flag == 0){
            if (strcmp(a[i], dato) == 0){
            flag = 1;
            } else {
            i++;
            }
        }
    return flag;
}

int buscaPosicionMenorArregloString (int d, char a[][d], int v)
{
    int posMenor = -1;
    if ( v > 0 ){
        posMenor = 0;
    }
    for ( int i = 1; i < v; i++){
        if (strcmp(a[i], a[posMenor]) < 0){
            posMenor = i;
        }
    }
    return posMenor;
}
void intercambioStrings (char string1[], char string2[])
{
    char aux [100];
    strcpy(aux, string1);
    strcpy(string1, string2);
    strcpy(string2, aux);
}
int buscaPosicionMenorArregloString2 (int d, char a[][d], int v, int comienzo)
{
    int posMenor = comienzo;

    for ( int i = comienzo + 1 ; i < v; i++){
        if (strcmp(a[i], a[posMenor]) < 0){
            posMenor = i;
        }
    }
    return posMenor;
}
void ordenaArregloStringPorSeleccion (int dimension, char a[][dimension], int v)
{
    int i = 0;
    int posMenor;

    for(int i = 0; i < v - 1; i++ ){
        posMenor = buscaPosicionMenorArregloString2(dimension, a, v, i);
        intercambioStrings(a[i], a[posMenor]);
    }
}
void ordenarPorInsercion ( int dimension, char a[][dimension], int v)
{
    for ( int i = 0; i < v - 1; i++ ){
        insertaOrdenado(dimension, a, i, a[i+1]);
    }
}
void insertaOrdenado ( int dimension, char a[][dimension], int v, char dato[])
{
    int i = v;
    while ( i >= 0 && strcmp(dato, a[i]) < 0 ){
        strcpy (a[i+1], a[i]);
        i--;
    }
    strcpy (a[i+1], dato);
}
