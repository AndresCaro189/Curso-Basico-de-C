#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  person
{
    char name [100];
    unsigned int age;
};

int main (int argc, const char * argv[]){
    FILE * in;
    char buffer [100];

    if (argc < 2){
        printf ("Indique el nombre del archivo de entrada\n");

        return -1; 
    }
    if (!(in = fopen (argv[1], "r" ))){
        printf ("No se pudo leer el archivo %s\n", argv[1]);

        return -2;
    }

    struct person p;
    while (fread(&p, sizeof(struct person), 1, in)){
        printf("%s tiene %d anios\n", p.name, p.age);
    }
/*
    do {
       printf ("Ingrese el nombre de la persona:");
       scanf  ("%99s", p.name);
       printf ("Ingrese la edad de la persona:");
       scanf ("%d", &(p.age));
       fwrite (&p, sizeof(struct person), 1, in );
       printf("Grabada Otra s/n");
       scanf ("%1f", buffer);

    }while (buffer[0] != 'n');
 */
    fclose (in);
 
    return 0;
}