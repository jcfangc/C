// 编写下列函数：
// double inner_product(const double *a, const double *b, int n);
// a 和 b 都指向长度为 n 的数组。函数返回 a[0]*b[0]+a[1]*b[1]+...+a[n-1]*b[n-1]。要求使用指针算数运算而不是去下表来访问数组元素。



#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define N 20

// 一个往固定数组长度的数组填入数字的函数 fill_array
void fill_array(double *, int);
// 内部乘法
double inner_product(const double *, const double *, int);

int main(void)
{
    // 创造一个整型数组，长度上限是 N
    double arr_a[N], arr_b[N];

    fill_array(arr_a, N);
    printf("\n\n\t Press key to continue...");
    getchar();
    fill_array(arr_b, N);

    printf("\n\n\t Inner Product: %.2lf", inner_product(arr_a, arr_b, N));

    getchar();
    return 0;
}

void fill_array(double *arr, int len)
{
    double(*p);
    srand((unsigned)time(NULL));

    double ran_num;
    printf("\n\t ARRAY:");
    for (p = arr; p < arr + len; p++) {
        ran_num = (rand() % 10) + (double)(rand() % 100) / 100.0;
        *p = ran_num;
        printf(" %.2f", *p);
    }
}

double inner_product(const double *a, const double *b, int n)
{
    double(*p_a) = (double *)a, (*p_b) = (double *)b, (*p_st_row)[N], (*p_st_col);
    double store[3][N];
    double result = 0;

    // 把 a 数组的元素放在第一行
    for (p_st_col = (*store); p_st_col < ((*store) + n); p_st_col++) {
        (*p_st_col) = (*p_a);
        if (p_a < a + n - 1) {
            p_a++;
        }
    }

    // 把 b 数组的元素放在第二行
    for (p_st_col = (*store) + N; p_st_col < ((*store) + N + n); p_st_col++) {
        (*p_st_col) = (*p_b);
        if (p_b < b + n - 1) {
            p_b++;
        }
    }

    // 将 a b 数组相乘并记录在 store 的第三行
    double product = 1;
    for (p_st_col = (*store); p_st_col < (*store) + n; p_st_col++) {
        for (p_st_row = store; p_st_row < store + 2; p_st_row++) {
            product *= (*p_st_row)[(p_st_col - (*store))];
        }
        (*p_st_row)[(p_st_col - (*store))] = product;
        product = 1;
    }

    // 第三行结果相加
    for (p_st_row = store + 2; p_st_row < store + 3; p_st_row++) {
        for (p_st_col = *(store + 2); p_st_col < (*(store + 2) + n); p_st_col++) {
            result += (*p_st_row)[(p_st_col - (*(store + 2)))];
        }
    }

    return result;
}