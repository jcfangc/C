### ������һϵ�е����Ͷ���������ϰ�� 8 �е�ÿ��������
***
(a) char (\*x[10])(int);<br>
(b) int  (\*x(int))[5];<br>
(c) float \*(\*x(void))(int);<br>
(d) void (\*x(int, void (\*y)(int)))(int);
***

<br>

�ο��𰸣�<br>
|���|���Ͷ���򻯺�|
|:-:|:-|
|(a)|typedef char func(int);<br>typedef func \*func_ptr;<br>typedef func_ptr func_ptr_arr[10];<br>func_ptr_arr x;|
|(b)|typedef int func[5];<br>typedef func \*func_func(int);<br>func_func x;|
|(c)|typedef float \*ptr_func(int);<br>typedef ptr_func \*ptr_ptr_func(void);<br>ptr_ptr_func x;|
|(d)|typedef void func(int);<br>typedef void in_func(int);<br>typedef in_func(\*in_func_ptr);<br>typedef func(\*func_ptr(int, in_func_ptr));<br>func_ptr x;<br>in_func_ptr y;|