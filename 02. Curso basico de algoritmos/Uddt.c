#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct client
{
    char Name[50];
    char Id[20];
    float Credit;
    char Address[100];
};

main(int argc, char const *argv[])
{
    /*Code*/
    struct  client client1 = {0};
    strcpy(client1.Name, "Camilo Valencia");
    strcpy(client1.id, "000000001");
    client1.Credit = 1000000;
    strcpy(client1.Address, "Calle 1, cr1 ciudad Bolivar")

    printf("The client name is: %s \n", client1.Name);
    printf("The client id is: %s \n", client1.id);
    printf("The client Credit is: %f \n", client1.Credit);
    printf("The client Address is: %s \n", client1.Address);

    return 0;
};