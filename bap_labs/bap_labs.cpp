#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define PI2 6.2831853072 // PI * 2

bool equal(char* a, const char* b) {
    int p = -1;
    do {
        p++;
        if (a[p] != b[p])
            return false;
    } while (a[p] != '\0' && b[p] != '\0');
    return true;
}

int main(void)
{
    setlocale(LC_ALL, "Russian");

    long double x, frac, result, z, y, X, EPS;

    printf("Введите точность: ");
    scanf_s("%Lf", &EPS);

    while (1)
    {
        printf("Введите число: ");
        scanf_s("%Lf", &x);

        X = x - truncl(x / PI2) * PI2;

        frac = 1;
        result = 1;
        y = 1;
        z = -(X * X);

        do
        {
            frac *= (z / (y * (y + 1)));
            result += frac;
            y += 2;
        } while (fabsl(frac) > EPS && y <= 100);

        printf("мой    cos(%Lf)=%Lf\n", x, result);
        printf("math.h cos(%Lf)=%Lf\n\n", x, cosl(x));

        char answer[10];
        do {
            printf("Хотите продолжить? (yes/no): ");
            scanf_s("%9s", &answer, (unsigned)_countof(answer));
        } while (!equal(answer, "yes") && !equal(answer, "no"));
        if (equal(answer, "no")) break;

        /*char answer;
        do {
            printf("Хотите продолжить? (y/n): ");
            fseek(stdin, 0, SEEK_END);
            scanf_s("%c", &answer, 1);
        } while (answer != 'y' && answer != 'n');
        if (answer == 'n') break;*/

        printf("\n===================\n\n");
    }
    return 0;
}