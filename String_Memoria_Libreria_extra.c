#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
//EJERCICIO 1 

//MUESTRA SI LAS VARIABLE SON ALFANUMERICAS O NO 
    int v1='t';
    int v2='2';
    int v3='\t';
    int v4='  ';

    if (isalnum(v1)){ //funcion que se encarga de evaluar si es un caracter o no
        printf("v1 = %c y es alfanumerico \n", v1);
    }else {
        printf("v1 = %c y no es alfanumerico \n", v1);
    }

    if (isalnum(v2)){ //funcion que se encarga de evaluar si es un caracter o no
        printf("v2 = %c y es alfanumerico \n", v2);
    }else {
        printf("v2 = %c y no es alfanumerico \n", v2);
    }

    if (isalnum(v3)){ //funcion que se encarga de evaluar si es un caracter o no
        printf("v3 = %c y es alfanumerico \n", v3);
    }else {
        printf("v3 = %c y no es alfanumerico \n", v3);
    }

    if (isalnum(v4)){ //funcion que se encarga de evaluar si es un caracter o no
        printf("v4 = %c y es alfanumerico \n", v4);
    }else {
        printf("v4 = %c y no es alfanumerico\n ", v4);
    }

//EJERCICIO 2 
//isalpha (Intente  hacerlo a traves de datos por teclado y no funciona)
 int v1=2;

    if (isalpha(v1)){ //Determina si una el caracter es alfbetico o no  
        printf("El caracter es alfabetico", v1);
    }else{
        printf("No se ingreso una letra del alfabeto");
    }

}
