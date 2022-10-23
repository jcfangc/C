### 修改 find_largest 函数，用指针算数运算（而不是取下标）来访问数组元素。
***
原函数：
~~~
    int find_largest(int a[], int n)
    {
        int i, max;

        max = a[0];
        for (i = 1; i < n; i++) {
            if (a[i] > max) {
                max = a[i];
            }
        }

        return max;
    }
~~~
***
<br>

参考答案：
~~~
    int find_largest(int a[], int n)
    {
        int(*p), (*max);

        max = a;
        for (p = a + 1; p < a + n; p++) {
            if (*p > *max) {
                max = p;
            }
        }

        return *max;
    }
~~~
