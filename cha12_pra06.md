### 用指针算数运算代替数组取下标来重新编写下面的函数。（换句话说，消除变量 i 和所有用 [] 运算符的地方。）要求改动尽可能少。
***
~~~
    int sum_array(const int a[], int n)
    {
        int i, sum;

        sum = 0;
        for (i = 0; i < n; i++) {
            sum += a[i];
        }
        return sum;
    }
~~~
***
<br>

参考答案：
~~~
    int sum_array(const int *a, int n)
    {
        int(*p), sum;

        sum = 0;
        for (p = a; p < (a + n); p++) {
            sum += *p;
        }
        return sum;
    }
~~~
<br>

原书作者答案：
~~~
    int sum_array(const int a[], int n)
    {
        int *p, sum;

        sum = 0;
        for (p = a; p < a + n; p++)
            sum += *p;
        return sum;
    }
~~~
<br>

需要注意的是，指针和数组变量只有在函数的形式参数中可以相互替代，因为其本质都是传递了指向数组开头的指针。