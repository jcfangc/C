### 编写一个宏 NELEMS(a) 来计算一维数组中的元素个数。提示：见 8.1 节中有关 sizeof 的运算符的讨论。

<br>

参考答案：
~~~
#define NELEMS(a) ((int)(sizeof(a) / sizeof(a[0])))
~~~
题目其实有些许歧义，其本意应该只是想用这个宏计算出该数组可以容纳的元素的个数。

<br>

原书作者也对本题给出了解答，详见：http://knking.com/books/c2/answers/c14.html