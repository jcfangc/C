### (a) 声明名为 c1，c2 和 c3 的结构变量，每个结构变量都拥有 double 类型的成员 real 和 imaginary。

<br>

~~~
    #include <stdio.h>

    int main(void)
    {
        // (a) 声明名为 c1，c2 和 c3 的结构变量，每个结构变量都拥有 double 类型的成员 real 和 imaginary。
        struct complex_number {
            double real, imaginary;
        } c1, c2, c3;

        getchar();
        return 0;
    }
~~~

<br>

### (b) 修改 (a) 中的声明，使 c1 的成员初始值为 0.0 和 1.0，而 c2 的成员初始值为 1.0 和 0.0。（c3 不初始化）

<br>

~~~
    #include <stdio.h>

    int main(void)
    {
        // (b) 修改 (a) 中的声明，使 c1 的成员初始值为 0.0 和 1.0，而 c2 的成员初始值为 1.0 和 0.0。（c3 不初始化）
        struct complex_number {
            double real, imaginary;
        }   c1 = { .real = 0.0, .imaginary = 1.0 },
            c2 = { .real = 1.0, .imaginary = 0.0 },
            c3;

        getchar();
        return 0;
    }
~~~

<br>

### (c) 编写语句用来把 c2 的成员复制给 c1。这项操作是否可以在一条语句中完成，还是必须要两条语句？

<br>

~~~
    #include <stdio.h>

    int main(void)
    {
        // (b) 修改 (a) 中的声明，使 c1 的成员初始值为 0.0 和 1.0，而 c2 的成员初始值为 1.0 和 0.0。（c3 不初始化）
        struct complex_number {
            double real, imaginary;
        }   c1 = { .real = 0.0, .imaginary = 1.0 },
            c2 = { .real = 1.0, .imaginary = 0.0 },
            c3;

        // (c) 编写语句用来把 c2 的成员复制给 c1。这项操作是否可以在一条语句中完成，还是必须要两条语句？
        c1 = c2;
        // 一条语句即可，因为两个同时声明的结构是兼容的，此外，使用相同的 “结构标记” 或是同样类型名声明的结构也是兼容的。
        // 尤其不能使用 == 或 != 对整体结构进行运算。

        getchar();
        return 0;
    }
~~~

<br>

### (d) 编写语句把 c1 和 c2 的对应成员进行相加，并且把结果存储在 c3 中。

<br>

~~~
    #include <stdio.h>

    int main(void)
    {
        // (b) 修改 (a) 中的声明，使 c1 的成员初始值为 0.0 和 1.0，而 c2 的成员初始值为 1.0 和 0.0。（c3 不初始化）
        struct complex_number {
            double real, imaginary;
        }   c1 = { .real = 0.0, .imaginary = 1.0 },
            c2 = { .real = 1.0, .imaginary = 0.0 },
            c3;

        // (c) 编写语句用来把 c2 的成员复制给 c1。这项操作是否可以在一条语句中完成，还是必须要两条语句？
        c1 = c2;
        // 一条语句即可，因为两个同时声明的结构是兼容的，此外，使用相同的 “结构标记” 或是同样类型名声明的结构也是兼容的。
        // 尤其不能使用 == 或 != 对整体结构进行运算。

        // (d) 编写语句把 c1 和 c2 的对应成员进行相加，并且把结果存储在 c3 中。
        c3.real = c1.real + c2.real;
        c3.imaginary = c1.imaginary + c2.imaginary;

        getchar();
        return 0;
    }
~~~

书作者答案链接：http://knking.com/books/c2/answers/c16.html