### 编写下列函数：
### void swap(int* p, int* q); 
### 当传递两个变量的地址时，swap函数应该交换两个变量的值：
### swap(&i, &j); /* exchange values of i and j */

<br>

#### 参考答案：
~~~
    void swap(int *p, int *q)
    {
        int temp = *p;
        *p = *q;
        *q = temp;
    }
~~~