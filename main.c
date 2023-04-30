#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarPila (Pila *pila);
int pasarArreglo (int arreglo[], int dim, Pila *pila);
void mostrarArreglo (int arreglo[], int validos);
int buscarMayor(int arreglo[], int validos);
int buscarMenorPila (Pila *pila);
void quitarMenor (Pila *pila, int menor;);
void buscarMenor2 (Pila *pila);
int cargarArreglo(int a[], int dim);
int promArr(int arreglo[], int validos);

int main()
{
    Pila pila1;
    inicpila(&pila1);
    int dim = 20;
    int arreglo[dim];
    int arreglo2[dim];
    int validos;
    int mayor;
    int menor;
    float promedio = 0;

//    cargarPila(&pila1);
//    mostrar(&pila1);
//
//    validos = pasarArreglo(arreglo, dim, &pila1);
//    mostrarArreglo(arreglo, validos);
////
////    mayor = buscarMayor(arreglo, validos);
////    printf("\n El mayor numero del arreglo es: | %d |", mayor);
////
////    menor = buscarMenorPila(&pila1);
////    quitarMenor(&pila1, menor);
////
////    buscarMenor2(&pila1);
////    mostrar(&pila1);

    validos = cargarArreglo(arreglo2, dim);
    promedio = promArr(arreglo2, validos);
    printf("%f", promedio);
}


void cargarPila (Pila *pila)
{

    char letra;

    do
    {

        leer(pila);

        printf("Presiona 's' para continuar cargando");
        fflush(stdin);
        scanf("%c", &letra);

    }
    while (letra == 's');
}

int pasarArreglo (int arreglo[], int dim, Pila *pila)
{
    Pila aux;
    inicpila(&aux);
    int i = 0;

    while(i < dim && !pilavacia (pila))
    {

        if(tope (pila) % 2 == 1)
        {

            arreglo[i] = tope (pila);
            apilar(&aux, desapilar(pila));
            i++;

        }
        else if(tope(pila) % 2 == 0)
        {

            apilar(&aux, desapilar(pila));

        }


    }

    while(!pilavacia(&aux)){

        apilar(pila, desapilar(&aux));

    }

    return i;

}

void mostrarArreglo (int arreglo[], int validos){

    int i = 0;

    while(i < validos){

        printf("| %d |", arreglo[i]);
        i++;

    }

}

int buscarMayor(int arreglo[], int validos){

    int i = 0;
    int mayor = arreglo[i];
    int aux;
    while (i<validos){

        if(mayor<arreglo[i]){

            aux = mayor;

            mayor = arreglo[i];

            arreglo[i] = aux;

        }else{

        i++;


        }

    }

    return mayor;

}

void buscarMenor2 (Pila *pila){

    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);


    apilar(&aux, desapilar(pila));

    while(!pilavacia(pila)){

        if(tope(pila) < tope(&aux)){

            apilar(&aux2, desapilar(&aux));
            apilar(&aux,desapilar(pila));

        }else{

            apilar(&aux2, desapilar(pila));

        }
    }

    while(!pilavacia(&aux2)){

        apilar(pila, desapilar(&aux2));

    }



}

int promArr(int arreglo[], int validos){

    int i = 0;
    int suma = 0;
    float promedio = 0;

    while(i<validos){

        suma = suma + arreglo[i];

        i++;

    }

    promedio = suma / validos;

    return promedio;

}

int cargarArreglo(int a[], int dim){

    int i = 0;
    int cant;

    printf("Cuantas notas va a ingresar?");
    fflush(stdin);
    scanf("%i", &cant);

    for(i=0;i<cant;i++){

        printf("Ingresa un valor");
        fflush(stdin);
        scanf("%d", a[i]);
    }

    return i;
}



