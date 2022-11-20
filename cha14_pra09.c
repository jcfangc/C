// 编写下列带参数的宏。
// （a）CHECK(x, y, n) 	x 和 y 都落在 0 和 n-1 之间（包括端点）时值为 1。
// （b）MEDIAN(x, y, z,) 	计算 x、y 和 z 的中值。
// （c）POLYNOMIAL(x)	计算多项式 (3(x^5) + 2(x^4) - 5(x^3) - (x^2) + 7x - 6。

#include <stdio.h>

#define CHECK(x, y, n)  ((((x) >= 0 && (x) <= ((n) - 1)) && ((y) >= 0 && (y) <= ((n) - 1))) ? 1 : 0)
#define MEDIAN(x, y, z)  (  ((x)>=(y))?(  ((y)>=(z))?(y):(  ((x)>=(z))?(z):(x)  )  ):(  ((x)>=(z))?(x):(  ((y)>=(z))?(z):(y)  )  )  )
#define POLYNOMIAL(x)  ((3*((x)*(x)*(x)*(x)*(x))) + (2*((x)*(x)*(x)*(x))) - (5*((x)*(x)*(x))) - ((x)*(x)) + (7*(x)) - 6)

int main(int argc, char *argv[])
{
    printf("\n\t X: %d, Y: %d, N: %d, CHECK(): %d", 10, 15, 20, CHECK(10, 15, 20));
    printf("\n\t X: %d, Y: %d, N: %d, CHECK(): %d", 10, 20, 15, CHECK(10, 20, 15));
    printf("\n\t X: %d, Y: %d, N: %d, CHECK(): %d", 20, 10, 15, CHECK(20, 10, 15));
    printf("\n\t X: %d, Y: %d, N: %d, CHECK(): %d", 20, 15, 10, CHECK(20, 15, 10));
    printf("\n\n");
    printf("\n\t X: %d, Y: %d, Z: %d, MEDIAN(): %d", 20, 15, 10, MEDIAN(20, 15, 10));
    printf("\n\t X: %d, Y: %d, Z: %d, MEDIAN(): %d", 20, 10, 15, MEDIAN(20, 15, 10));
    printf("\n\t X: %d, Y: %d, Z: %d, MEDIAN(): %d", 10, 20, 15, MEDIAN(20, 15, 10));
    printf("\n\t X: %d, Y: %d, Z: %d, MEDIAN(): %d", 15, 20, 10, MEDIAN(20, 15, 10));
    printf("\n\t X: %d, Y: %d, Z: %d, MEDIAN(): %d", 15, 10, 20, MEDIAN(20, 15, 10));
    printf("\n\t X: %d, Y: %d, Z: %d, MEDIAN(): %d", 10, 15, 20, MEDIAN(20, 15, 10));
    printf("\n\n");
    printf("\n\t X: %d, POLYNOMIAL(): %d", 2, POLYNOMIAL(2));

    getchar();
    return 0;
}