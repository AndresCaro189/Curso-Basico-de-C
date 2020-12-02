#include <stdio.h>

int main (){
    int number=109;
    int *pointToNumber = &number;

    printf("%p, %d\n", pointToNumber, *pointToNumber);
}

/*Organizacion de la memoria: La memoria se organiza en forma de celdas, por medio de bytes, como por ejemplo podemos tener una
representacion de esta forma, donde cada cerda representa un byte, lo cual dentro de ella son 8 bits

–> Esto lo que significa es que dentro de una celda podemos guardar un valor numerico como maximo de 255, y si queremos guardar un
valor numerico mas grande tendremos que utilizar otro Byte. Entonces cada vez que tengamos que agregar un valor numerico mas grande
vamos a estar necesitando abarcar mas celdas, para almacenar su valor.Direcciones de memoria: Son predefinidas, con notacion hexadecimal,
lo que quiere decir que son cantidades tan grandes que se necesita utilzarlo.

–> Entonces cuando estamos asignando una variable, lo que realmente estamos es asignando un nombre, un nombre que es mas facil de
recordar que una direccion exadecimal y su valor es el que se encontrara dentro de la celda.nil: Significa null o nuloPunteros: Su
funcion es buscar un espacio de memoria donde estan las variables, puesto que si buscamos o intentamos ingresar a una variable equivocada
o que siquiera existe vamos a tener error en el codigo, los punteros solamente pueden manejar espacio de memoria lo que quiere decir que
no manejaran otro tipo de variable.–> Lo que quiere decir que al momento de crear una variable de tipo puntero, su contenido sera
unicamente la direccion de la variable asignada. --> Una de las formas de encontrar la direccion en memoria de una variable es de la
siguiente forma:

* &+ la variable --> &x
–> Esto lo podemos escribir en un prinft, dentro de ella de la siguiente forma:#include <stdio.h>int main (){ int x = 10, z; printf
(“El valor de x es: %d\n”, x); printf(“Su direccion es: %d\n”, &x); return 0;}IMPORTANTE lo tenemos que hacer con %u, para que la
direccion no salga con valores positivos o negativos, entonces quedaria asi:

printf(“Su direccion es: %u\n”, &x);

–> Entonces con esto, tenemos que la variable x se almacena en esa direccion de nuestra memoria del ordenadorGuardar direccion con
puntero: Si queremos guardar la direccion de memoria donde se almacena la variable para ello lo tenemos que hacer con el puntero, para
ello lo que tenemos que hacer es lo siguiente:

* int* --> declaramos el tipo de variable y le agregamos
enseguida un * esto lo que indicara que es una variable de direccion de memoria.

	* int* + nombre de la variable "direct" = &x;
–> entonces la variable direct de tipo direccion de memoria es la que va a encerrar la direccion de memoria de la variable X. Esto es
lo que se le llama puntero

IMPORTANTE Funciona con cualquier otro tipo de variable puede ser variable de tipo floatUso del puntero: El principal uso que tienen
los punteros en el lenguaje C, es trabajar con referencias en las funciones, lo que quiere decir, que cuando por ejemplo estamos pasandole una variable a una funcion, lo que realmente le estamos pasando es una copia, por ejemplo tenemos el siguiente ejemplo de codigo:
#include <stdio.h>
void jugar (int n){ n = n + 5; printf(“vale: %d\n”, n);}int main (){ int x = 10; jugar(x); printf(“valez: %d\n”, x);}

–> Entonces una vez que termina la funcion esa copia muere, ya no tiene mas relevancia en el codigo puesto que las funcion se cumple
cuando hasta que sea necesaria

IMPORTANTE Cuando trabajamos con puntero, trabajamos con direcciones en memoria y no con variables

Recuperar el valor de puntero: Para ello tenemos que declarar un * antes des de una variable, de forma que se recuperara la direccion
de la variable:

* int y = *n;
–> Entonces, para cambiar el valor de la celda lo hacemos de la siguiente forma:

#include <stdio.h>
void jugar (int* n)
{
int y = *n;
y = y + 5 * 3 - 1;
*n = y;
//printf(“direccion es: %u\n”, y);
}
int main ()
{
int x = 10;
jugar(&x);
printf(“valez: %d\n”, x);
return 0;
}

–> Entonces con esto lo que estamos haciendo, es cambiarle el valor a la direccion, que la direccion se guarda en *n, con la
recuperacion, es decir la sustituye, entonces ya no seria la anterior sino en este caso la direccion de x, seria el resultado
de la ecuacion.*/