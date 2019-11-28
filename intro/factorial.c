// gcc -o factorial factorial.c && ./factorial
// #include <stdio.h>

int factorial(int value)
{
    int f = 1;

    for (int i = 1; i <= value; i++)
    {
        f *= i;
    }

    return f;
}

// int main()
// {
//     printf("%d", factorial(4));
//     return 0;
// }
