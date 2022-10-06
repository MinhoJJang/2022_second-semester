#include <stdio.h>
#include <string.h>

typedef struct _EMP
{
    char name[20];
    int age;
    float salary;
    char hobby[3][10];
} EMP;

void setEmp(EMP *em, char *name, int age, float salary, char *hobby, int emIndex)
{
    em->age = age;
    strcpy(em->name, name);
    em->salary = salary;
    strcpy(em->hobby[emIndex], hobby);
}

void getEmp(EMP em)
{
    printf("Employee info: name: %s, age: %d, salary: %.2f, hobby: %s\n", em.name, em.age, em.salary, em.hobby);
}

int main()
{
    EMP em1, em2;
    setEmp(&em1, "Hong Gil Dong", 22, 95000, "Running", 0);
    getEmp(em1);

    return 0;
}