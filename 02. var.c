int main ()
{
    int var;

    var=1;
    var=var+1;
    var=10+50;
}

/*Qué es una variable
Para entender el concepto de variable es conveniente repasar el de algoritmo.
Voy a tomar una definición simple:
Un algoritmo es una serie de pasos que deben ejecutarse para lograr un determinado fin.
Algo vago, ¿cierto? Veamos un ejemplo simple: imagina que tienes que realizar las compras del supermercado para la comida que vas a
preparar a la noche.
Mejor aún, imagina que tienes que decirle a otra persona que realice las compras por ti.
Hay ciertas cosas que seguro sabes que debes indicarle:
¿Qué hay que comprar? ¿Cuánta cantidad? ¿Dónde hay que ir a comprar? Y un largo etcétera.
Algunas cosas que darás por sentado serán:
Mira antes de cruzar la calle
Lleva contigo dinero o tarjeta
Cierra la puerta detrás de ti
Y algunas otras según a quién le estés dando estas instrucciones.
Todas estas indicaciones constituyen un algoritmo: un plan detallado que enumera los pasos que deben darse para lograr el objetivo.
En este caso: contar con todos los elementos 
necesarios para cocinar.
Pues bien, y… ¿dónde quedaron las variables a todo esto? Un momentín, ya estoy llegando 😃
Imagina que la lista de ingredientes es larga.
¿Cómo podría saber la persona que enviaste a comprar cuándo está finalizada su tarea?
La respuesta es clara: cuando se haya comprado el último ingrediente.
Para saber cuándo eso ha sucedido es necesario contar con dos datos:
Cuáles son todos los ingredientes
Qué ingredientes ya han sido agregados al carrito
Lo más probable es que la persona en cuestión lleve consigo una lista (una simple hoja de papel) con todos los elementos que debe
comprar y, a medida que incorpora un nuevo ítem al carrito hará una marca en dicho elemento de la lista (O tal vez lo tache, va en gustos).
El punto es que, sin esta herramienta sería difícil completar la tarea exitosamente.
Algunas personas tal vez puedan realizar esta tarea usando solo su memoria, a nuestros efectos, da lo mismo qué medio de almacenamiento 
utilicen, en algún lado está guardada esta información.
En el caso de la computadora el único lugar donde puede almacenarse información es la memoria (después podemos discutir tipos de memoria, 
como ser discos, usb, etc… pero la idea es la misma).
La memoria de la computadora, como charlamos, está organizada en base a celdas contiguas.
Cada celda se identifica por un número (Su dirección).
Dentro de cada celda es posible almacenar una combinación de 1s y 0s de un determinado tamaño (Usualmente un byte es decir, 8 dígitos 0 o 1).
Si necesitamos almacenar un dato más grande que 8 dígitos binarios necesitaremos agregar celdas.
El tema es que, para nosotros los humanos es más fácil pensar en algo como $nombre que en 0x00123bf34a.
De hecho, para la computadora es claro que 0x00113bf34a y 0x00123bf34a son dos espacios de memoria que no guardan relación alguna. 
Sin embargo, para nosotros es más fácil hablar de $nombre y $email.
Me tomé una pequeña licencia aquí para hacer más claro el ejemplo, a esta altura sabes que las variables en C no comienzan con el 
caracter $… ¿cierto?
De modo que una variable es, a fin de cuentas, un alias para una serie de posiciones de memoria contiguas… es una forma de hacernos más 
fácil la vida a nosotros… pobres humanos.*/

/*Qué son los tipos de datos
Ahora que hemos aclarado la noción de variable, demos un paso más y hablemos de tipos de datos.

Como decía en la sección anterior, las variables son espacios de memoria formados por celdas de tamaño fijo.

Para poder almacenar algún dato en una variable es necesario conocer el tamaño que éste ocupará en la memoria… ¡de otro modo sería imposible reservar ese espacio!

Y ahí empieza a tener sentido pensar en la naturaleza del dato que almacenaremos.

Empecemos por un ejemplo simple:

El número 7 en binario se escribe como 111. Mejor dicho, en un espacio de 8 bits se escribiría 00000111.

El número 255 en binario se escribe 11111111… en 8 bits no me queda espacio para agregar ningún 1 más: 255 es el número más grande que puedo almacenar en una celda de un byte.

¿Y qué pasa si necesito almacenar un número más grande? Por ejemplo 256.

Pues necesitaré un bit más, pero… no puedo simplemente agregar un bit, tengo que anexar todo un byte… es decir: 00000001 00000000.

Al igual que las variables, los tipos de datos son una forma simple de comprender cuánta memoria ocupan nuestros datos (y por ende nuestras variables).

Por otro lado, y esto ya tiene mucho que ver con el lenguaje que usemos, los tipos de datos nos dan una idea de qué operaciones puede realizarse con los datos que tenemos almacenados.

Por ejemplo, cualquiera esperaría que la suma de dos números enteros no supusiera ningún problema… sin embargo, la división de una palabra por otra no parece tener mucho sentido, ¿cierto?

Cada lenguaje define un conjunto de tipos y operaciones permitidas sobre ellos.

A estos tipos se los conoce como primitivos.

Claro que no son los únicos posibles: tú puedes definir tus propios tipos de datos.*/

/*Qué es un struct
Un struct es un mecanismo para definir nuevos tipos de datos complejos o estructurados.

Se usa cuando tienes que guardar datos correlacionados, por ejemplo, todos los referidos a una persona.

Cuando tienes que manejar muchas personas y de todas ellas quieres recabar la misma información tiene mucho sentido armar una estructura a partir de la cual puedas crear nuevas variables.

En el caso de C, los structs son un modo muy interesante de crear tus propios tipos de datos, ya sea combinando los tipos primitivos o, incluso, utilizando otros structs.
*/

/*Qué es una función
Una de las necesidades más comunes que nos encontramos a la hora de desarrollar (especialmente aplicaciones de cierta complejidad) es la de re-utilizar partes del código que hemos escrito.

Siempre es posible copiar y pegar, pero si tienes algo de experiencia rápidamente te darás cuenta de que no es precisamente una buena práctica (Y de paso, si quieres aprender algunas de las que sí lo son, este curso puede interesarte).

Una función es un pedazo de código que tiene asociado un nombre y retorna un valor al finalizar su tarea.

De esta forma, puede ser invocada cada vez que se la necesite y, una vez haya concluido, el valor de retorno será el que tome la expresión de la llamada.

Es decir, en un fragmento de este estilo:

a = f(5);

La variable a tomará el valor resultante de invocar a la función f con un argumento igual a 5.

Qué significa la palabra reservada “const”
Respecto de algo que habrás visto en los ejemplos del curso, habrás notado que utilicé la palabra reservada const, especialmente para los strings.

Esta palabra es un modificador de un tipo de datos.

Lo que indica const es que el contenido de la variable no podrá ser sobreescrito.

Este tipo de aclaración tiene especial relevancia cuando se trabaja con punteros.

La diferencia entre char * c y const char * c es que en el primer caso nada me impide hacer algo como *c = ‘B’, mientras que en el segundo obtendré un error.

Se trata en definitiva de un mecanismo de seguridad más (seguridad en el sentido de asegurarnos que nuestro programa no escribe donde no debe).*/