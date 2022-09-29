#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

typedef struct _point
{
    int x;
    int y;
} Point;

typedef struct _triangle
{
    Point p1;
    Point p2;
    Point p3;

} Triangle;

typedef struct _circle
{
    Point p1;
    double r;
} Circle;

void getTriangle(Triangle tr)
{
    printf("p1.x = %d\n", tr.p1.x);
    printf("p1.y = %d\n", tr.p1.y);
    printf("p2.x = %d\n", tr.p2.x);
    printf("p2.y = %d\n", tr.p2.y);
    printf("p3.x = %d\n", tr.p3.x);
    printf("p3.y = %d\n", tr.p3.y);
}

void getCircleArea(Circle cir)
{
    printf("Circle Area: %.2lf", pow(cir.r, 2.0) * M_PI);
    // pow 함수는 리눅스에서 -lm 을 사용해야한다.
}

int main()
{

    Triangle tri = {{0, 2}, {10, 2}, {5, 5}};
    getTriangle(tri);

    Circle cir = {{4, 2}, 3};
    getCircleArea(cir);
    return 0;
}