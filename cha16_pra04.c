#include <stdio.h>

// 说明如何为具有 double 类型的成员 real 和 imaginary 的结构定义为 Complex。
typedef struct {
    double real, imaginary;
} Complex;

Complex make_complex(double, double);
Complex add_complex(Complex, Complex);


int main(void)
{
    // 利用类型 Complex 来声明名为 c1，c2 和 c3 的变量。
    Complex c1, c2, c3;

    c1 = make_complex(1.3, 2.4);
    printf("\n\t Complex number c1: %.2lf+%.2lfi ", c1.real, c1.imaginary);
    c2 = make_complex(2.2, 3);
    printf("\n\t Complex number c2: %.2lf+%.2lfi ", c2.real, c2.imaginary);

    c3 = add_complex(c1, c2);
    printf("\n\t Complex number c3: %.2lf+%.2lfi ", c3.real, c3.imaginary);

    getchar();
    return 0;
}

// 编写名为 make_complex 的函数，此函数用来把两个实际参数（都是 double 类型）存储在 Complex 结构中，然后返回此结构。
Complex make_complex(double real, double imaginary)
{
    Complex sct;

    sct.real = real;
    sct.imaginary = imaginary;

    return sct;
}

// 编写名为 add_complex 的函数，此函数用来把两个实际参数（都是 Complex 结构）的对应成员相加，然后返回结果（另一个 Complex 结构）。
Complex add_complex(Complex clx_num1, Complex clx_num2)
{
    Complex result;

    result.real = clx_num1.real + clx_num2.real;
    result.imaginary = clx_num1.imaginary + clx_num2.imaginary;

    return result;
}

// 书作者答案链接：http://knking.com/books/c2/answers/c16.html
