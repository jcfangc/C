### 下列函数假设用来计算数组 a 中元素的和以及平均值，且数组 a 长度为 n。avg 和 sum 指向函数需要修改的变量。但是，这个函数含有几个错误，请找出这些错误并且修改他们。

***
~~~
    void avg_sum(double a[], int n, double *avg, double *sum)
    {
        int i;

        sum = 0.0;
        for (i = 0; i < n; i++) {
            sum += a[i];
        }
        avg = sum / n;
    }
~~~
***

<br>

#### 参考答案：
1. sum 作为指针类型的形式参数，在函数内进行调用时用 sum = 0.0 的方式是有问题的，首先这是在尝试直接修改 sum 指向的内存地址，其次 0.0 不是 uint64 应该是不能够作为内存地址的。

2. sum += a[i] 和第一个错误类似也是没能正确使用 * 来为指针所指的原始变量赋值。

3. avg = sum / n 其原本想要表达的意思相信是要将 sum 所指向的变量除以 n 然后赋值给 avg 所指向的变量。所以这里的 sum 和 avg 都应该加上 \* 以赋值给他们所指向的变量。

修改如下：

~~~
    void avg_sum(double a[], int n, double *avg, double *sum)
    {
        int i;

        *sum = 0.0;
        for (i = 0; i < n; i++) {
            *sum += a[i];
        }
        *avg = *sum / n;
    }
~~~