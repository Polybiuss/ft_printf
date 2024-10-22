#include<stdio.h>
#include<stdarg.h>

int somme(int num, ...)
{
    va_list args;
    int total = 0;

    va_start(args, num);

    for (int i = 0; i < num; i++)
    {
        total += va_arg(args, int);
    }

    va_end(args);

    return total;
}

int main()
{
    printf("Somme : %d\n", somme(3, 1, 2, 3));
    printf("Somme : %d\n", somme(5, 1, 2, 3, 4, 5));
    return (0);
}