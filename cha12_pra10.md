### 修改 11.5 节的 find_middle 函数，用指针算数运算返回值。
***
原函数：
~~~
    int *find_middle(int a[], int n) {
        return &a[n / 2];
    }
~~~
***
<br>

参考答案：
~~~
    int *find_middle(int a[], int n) {
        return (a + n / 2);
    }
~~~
