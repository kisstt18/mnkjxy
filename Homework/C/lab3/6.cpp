#include <stdio.h>
#define PI 3.14159

int main()
{
    double r, h;
    double l, v;
    printf("请输入圆半径 r 和圆柱高 h：");
    scanf("%lf%lf", &r, &h);

    l = 2 * PI * r;
    v = PI * r * r * h;

    printf("圆周长 = %.2f\n", l);
    printf("圆柱体积 = %.2f\n", v);
    return 0;
}
