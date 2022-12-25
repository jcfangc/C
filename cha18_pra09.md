### 请利用一系列的类型定义来简化练习题 8 中的每个声明。
***
(a) char (\*x[10])(int);<br>
(b) int  (\*x(int))[5];<br>
(c) float \*(\*x(void))(int);<br>
(d) void (\*x(int, void (\*y)(int)))(int);
***

<br>

参考答案：<br>
|题号|类型定义简化后|
|:-:|:-|
|(a)|typedef char func(int);<br>typedef func \*func_ptr;<br>typedef func_ptr func_ptr_arr[10];<br>func_ptr_arr x;|
|(b)|typedef int func[5];<br>typedef func \*func_func(int);<br>func_func x;|
|(c)|typedef float \*ptr_func(int);<br>typedef ptr_func \*ptr_ptr_func(void);<br>ptr_ptr_func x;|
|(d)|typedef void func(int);<br>typedef void in_func(int);<br>typedef in_func(\*in_func_ptr);<br>typedef func(\*func_ptr(int, in_func_ptr));<br>func_ptr x;<br>in_func_ptr y;|