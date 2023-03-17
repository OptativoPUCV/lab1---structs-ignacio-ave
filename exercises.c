#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#include "exercises.h"

//ejercicios de punteros y arreglos

/*
Ejercicio 1.
Programe la función void swap(int *a, int *b), la cual
intercambia los valores de las variables apuntadas por a y b.
*/
void swap(int *a, int *b) {
   int aux = (*a); 
   (*a) = (*b);
   (*b) = aux; 
}

/*
Ejercicio 2.
Programe la función void arrayMaxMin(int *a, int n, int *max, int *min),
la cual encuentra el máximo y el mínimo valor del arreglo a y los
almacena en las variables apuntadas por max y min.
*/
void arrayMaxMin(int *a, int n, int *max, int *min) {
   // a es un arreglo | n = total arreglos | max es maximo | min es minimo
   int aux = a[0];
   (*max) = aux;
   (*min) = aux;
   for( int k = 0 ; k < n ; k++ ){
      if((*max) < a[k]) (*max) = a[k] ; 
      if((*min) > a[k]) (*min) = a[k] ;
   }
}


/*
Ejercicio 3.
Considerando la estructura Persona, programe la función
crearPersona(...), la cual crea una nueva persona con 
los datos ingresados como parámetros y retorna un puntero 
al dato recién creado.
*/
typedef struct {
  char nombre[30];
  char rut[11];
  int edad;
} Persona;


Persona* crearPersona(char nombre[], char rut[], int edad) {
   Persona * p = (Persona *) malloc(sizeof(Persona));
   if (p == NULL) exit(EXIT_FAILURE);
   
   //asignar valores de entrada a los campos de p
   for( int k = 0 ; k < 30 && nombre[k] != '\0' ; k++ ) {
      (*p).nombre[k] = nombre[k]; 
   }
   // aqui perfectamente se podria haber usado strcpy
   for( int k = 0 ; k < 11 && rut[k]    != '\0' ; k++ ) {
      (*p).rut[k]    = rut[k]   ;
   } 

   (*p).edad = edad ;
    
   return p;
}

/*
Al momento de acceder es bueno :
   usar -> al se trata de un puntero a una struct
   usar (*variable) al trabajar con variables
*/

/*
Ejercicio 4.
Considerando la estructura "Vector", escriba 
la función Vector* crearVector(int n), la cual crea 
un vector con capacidad `n`, reserva la memoria 
correspondiente para el arreglo con `n` datos 
inicializados en 0 y luego retorna el vector creado.
*/
typedef struct {
   int *datos; // arreglo dinámico
   int capacidad; // capacidad del arreglo
} Vector;

Vector * crearVector(int n) {
   Vector * vector = (Vector *) malloc(sizeof(Vector));
   if(vector == NULL) exit(EXIT_FAILURE); 
   
   vector->datos = NULL; 
   vector->datos = (int *) calloc(n, sizeof(int));
   if( vector->datos == NULL ) exit(EXIT_FAILURE);   
   
   vector->capacidad = n ;

   return vector;
}

/*
Ejercicio 5a.
Programe la función void asignarValor(Vector * v, int i, int valor), 
la cual asigna el valor a la posición i del vector v.
*/
void asignarValor(Vector * v, int i, int valor) {
   v->datos[i] = valor; 
}

/*
Ejercicio 6.
Programe la función int obtenerValor(Vector * v, int i), 
la cual retorna el valor en la posición i del vector v.
*/
int obtenerValor(Vector * v, int i) {
   return v->datos[i];
   
   //aux = v->datos[i];
   //return aux ;
}

/*
Ejercicio 7.
Función que suma los vectores `a` y `b` y 
actualiza el vector `c` con el resultado de la suma.
*/
void sumaV(Vector * a, Vector * b, Vector * c) {

   int dim = 0 ; // Dimensiones del arreglo 
   if(a->capacidad > b->capacidad) dim = a->capacidad ;
   else dim = b-> capacidad; 
   
   c->datos = NULL;
   c->datos = (int *) realloc(c->datos, dim *sizeof(int));
   if( c->datos == NULL) exit(EXIT_FAILURE);

   for( int k = 0 ; k < dim ; k++){
      if( (a->datos[k]!='\0') && (a->datos[k]!=0) )  c->datos[k] += a->datos[k] ; 
      if((b->datos[k]!='\0')  && (b->datos[k]!=0) ) c->datos[k] += b->datos[k] ;
   }


}

/*
Ejercicio 8.
Use las operaciones implementadas de vectores para 
sumar (a1,a2)+(b1+b2). Almacene el resultado en el vector c.
*/
void sumaV2(int a1, int a2, int b1, int b2, Vector *c){ 
   Vector * a = crearVector(2);
   Vector * b = crearVector(2);
   asignarValor(a, 0, a1);
   asignarValor(a, 1, a2);
   asignarValor(b, 0, b1);
   asignarValor(b, 1, b2);
   sumaV(a, b, c);  

}
