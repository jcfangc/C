### 18.4 节讲过，下面声明是非法的：
***
```
int f(int)[];       /* function can't return arrays */
int g(int)(int);    /* function can't return functions */
int a[10](int);     /* array elements can't be functions */
```
然而，可以通过使用指针获得相似的效果：函数可以返回指向数组第一个元素的指针，可以返回指向函数的指针，数组的元素可以是指向函数的指针。请根据这些描述修订上述每个声明。
***

<br>

参考答案：<br>
|错误声明|修订声明|
|:-|:-|
|int f(int)[];|int (*f(int))[];|
|int g(int)(int);|int (*g(int))(int);|
|int a\[10\]\(int\);|int (*a\[10\])\(int\);|

<br>

值得注意的是和 * 一起添加的小括号是不可省略的，由于括号在声明的解读中具有更加高的优先级，如果将小括号省略，原本错误的声明会依次变为：<br>
函数 f 返回数组，而数组元素是 int \* 类型；<br>
函数 g 返回，参数为 int 类型，返回值为 int \* 类型的函数；<br>
a 数组元素为，返回值为 int \* 类型，参数为 int 类型的函数。<br>
都是错误的。