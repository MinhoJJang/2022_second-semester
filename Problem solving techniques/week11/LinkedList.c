#include <stdio.h>

typedef struct NODE
{
    int key;
    struct NODE *next;
} NODE;

int main()
{

    NODE node1, node2, node3;
    node1.key = 100;
    node2.key = 200;
    node3.key = 300;

    printf("address of node1 = %p \n", &node1);
    printf("address of node2 = %p \n", &node2);
    printf("address of node3 = %p \n", &node3);

    return 0;
}