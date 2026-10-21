#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

int Task0();
int Task1();
int Task1A();
int Task2();

double Home(double x_);

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Task0();
    Task1();
    Task1A();
    Task2();

    //Домашняя работа:

    double x, a;

    printf("\nВведите значение x: ");
    scanf("%lf", &x);

    a = Home(x);

    printf("\nРезультат вычислений:\n");
    printf("  x = %.5f\n", x);
    printf("  a = %.5f\n", a);

    return 0;
}

int Task0()
{
    int n;
    char c1, c2;

    printf("Введите количество символов: ");
    scanf("%d", &n);

    printf("Введите два символа через пробел: ");
    scanf(" %c %c", &c1, &c2);

    putchar('+');

    for (int i = 0; i < n; i++)
    {
        if (i < (n + 1) / 2)
            putchar(c1);
        else
            putchar(c2);

        putchar('!');
    }

    putchar('+');
    putchar('\n');

    return 0;
}

int Task1()
{
    int n, m;
    int s = 0;
    int k = 1;

    printf("\nВведите значения m и n (m >= n): ");
    scanf("%d %d", &m, &n);

    for (int i = m; i >= n; i--)
    {
        s += i;
        printf("Выполнено %d раз\n", k++);
    }

    printf("Результат: %d\n", s);

    return 0;
}

int Task1A()
{
    int m;
    double value = 1.0;

    printf("\nВведите целое число m: ");
    scanf("%d", &m);

    for (int n = 0; value <= m; n++)
    {
        printf("2^%-3d = %10.0f\n", n, value);
        value *= 2;
    }

    printf("Результат: %.1fK\n", m / 1024.0);

    return 0;
}

int Task2()
{
    double x, h, y;

    printf("\nФункция y = x^2 + 2*pi*cos(pi*x)\n");

    printf("Введите шаг табуляции: ");
    scanf("%lf", &h);

    printf("\n     x          f(x)\n");
    printf("--------------------------\n");

    for (x = 0.1; x <= 2.5 + h / 1000000.0; x += h)
    {
        y = pow(x, 2) + 2 * M_PI * cos(M_PI * x);
        printf("%8.3f   %12.6f\n", x, y);
    }

    return 0;
}

double Home(double x_)
{
    double numerator = 1.0;
    double denominator = 1.0;
    double a;

    for (int i = 1; i <= 6; i++)
    {
        numerator *= x_ - (pow(2, i) - 1);
        denominator *= x_ - pow(2, i);
    }

    a = numerator / denominator;

    return a;
}