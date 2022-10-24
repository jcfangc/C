### 8.2 节有一个代码段用两个嵌套的 for 循环初始化用作单位矩阵的数组 ident。请重新编写这段代码，采用一个指针来逐个访问数组中的元素，且每次一个元素。
***
提示：因为不能使用 row 和 col 来索引变量，所以不会很容易知道在哪里存储 1。但是，可以利用数组的下列事实：第一个元素必须是 1，接着的 N 个元素都必须是 0，在接下来的元素是 1，依此类推。用变量来记录已经存储的连续的 0 的数量。当计数达到 N 时，就是存储 1 的时候了。
***
<br>

参考答案如下：
~~~
    #include <stdio.h>

    #define N 10

    void ident(int[][N]);

    int main(void)
    {
        int a[N][N], (*ptr_r)[N], (*ptr_e);

        ident(a);

        // 以第一行为例 ptr_r = &a[0] = &*(a + 0) = a
        for (ptr_r = a; ptr_r < a + N; ptr_r++) {
            printf("\n\t ");
            for (ptr_e = (*ptr_r) /* 省略了 + 0 */; ptr_e < ((*ptr_r) + N); ptr_e++) {
                printf(" %d", (*ptr_r)[(int)(ptr_e - (*ptr_r))]);
            }
        }

        getchar();
        return 0;
    }

    void ident(int arr[][N])
    {
        int(*p) = (*arr) /* &*((*arr) + 0) */, count_0;

        *p = 1;
        for (int i = 0; i < N - 1; i++) {
            for (count_0 = 0; count_0 < N; count_0++) {
                *++p = 0;
            }
            p++;
            *p = 1;
        }
    }
~~~
<br>

原书作者答案：
~~~
    #define N 10

    double ident[N][N], *p;
    int num_zeros = N;

    for (p = &ident[0][0]; p <= &ident[N-1][N-1]; p++)
    if (num_zeros == N) {
        *p = 1.0;
        num_zeros = 0;
    } else {
        *p = 0.0;
        num_zeros++;
    }
~~~
<br>

可以比较明显的看出，原作者主要利用的是行主序的内存方式进行遍历。是以循环节作为一个基本单位进行遍历的。

用边长为 5 的矩阵举个例子：

1 0 0 0 0

0 1 0 0 0

0 0 1 0 0

0 0 0 1 0

0 0 0 0 1

我将它划分为：

<font style="background: yellow">1</font>
<font style="background: green">0 0 0 0 0 1</font>
<font style="background: green">0 0 0 0 0 1</font>
<font style="background: green">0 0 0 0 0 1</font>
<font style="background: green">0 0 0 0 0 1</font>

第一个 “1” 和（行数 - 1）个循环节 “000001”。

而原书作者的代码则是这样划分的：

<font style="background: yellow">1</font>
<font style="background: green">0 0 0 0 0 <font style="background: yellow">1</font></font>
<font style="background: green">0 0 0 0 0 <font style="background: yellow">1</font></font>
<font style="background: green">0 0 0 0 0 <font style="background: yellow">1</font></font>
<font style="background: green">0 0 0 0 0 <font style="background: yellow">1</font></font>

这二者之间的更多的区别在于有没有把第一个 “1” 纳入循环。书作者的想法是我没有设想过的。他专门为 “1” 的出现设置了出现的条件，并在程序一开始就设置条件的参数在满足被触发的情况下，之后再初始化条件的参数。这样第一个 “1” 就被纳入了完整的循环遍历过程中。反观自己就是把第一个 “1” 割裂在了循环之外，我会更加欣赏原书作者的做法。