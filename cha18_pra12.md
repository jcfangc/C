### 假设函数 f 的声明如下：
***
```
    int (*f(float (*)(long), char *))(double);
```
(a) 为函数 f 的类型编写完整描述。<br>
(b) 给出一个示例说明如何调用 f。
***

<br>

参考答案：<br>
|题号|回答|
|:-:|:-|
|a|首先 f 是一个函数，函数的参数有两个，其中一个是函数指针，该指针指向一个参数类型为 long，返回类型为 float 的函数，另一个参数是 char * 类型的。f 的返回值是一个指针，该指针指向一个函数，即为函数指针，要求该函数有着 double 类型的参数，和 int 类型的返回值。|
|b|可以推断 f 是用一个函数处理了一个字符串，或者说字符数组，根据某个函数对字符串的处理结果返回了函数指针。<br>float a_func(long);<br>char \*ptr;<br>int r_func(double);<br>int (\*r_ptr)(double);<br>r_ptr = r_func;<br>r_ptr = f(a_func, ptr);|

<br>

需要注意的是最后的赋值需要在块内进行。