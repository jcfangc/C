### 请为下列变量和函数编写声明。
***
(a) p 是指向函数的指针，并且此函数以字符型指针作为实际参数，函数返回的也是字符型指针。<br>
(b) f 是带有两个实际参数的函数：一个参数是指向结构的指针 p，且此结构标记为 t；另一参数是长整数 n。f 返回指向函数的指针，且指向的函数没有实际参数也没有返回值。<br>
(c) a 是含有 4 个元素的数组，且每个元素都是指向函数的指针，而这些函数都是没有实际参数且无返回值的。a 的元素初始指向的函数名分别是 insert / search / update 和 print。<br>
(d) b 是含有 10 个元素的数组，且每个元素都是指向函数的指针，而这些函数都有两个 int 型实际参数且返回标记为 t 的结构。
***

<br>

参考答案：<br>
|题号|相应声明|
|:-:|:-|
|(a)|char \*(\*p)(char \*);|
|(b)|void (\*f(struct t \*p, long int n))(void);|
|(c)|(void)(\*a[4])(void) = { insert, search, update, print };|
|(d)|sturct t (\*b[10])(int, int);|

<br>

书作者答案链接：http://knking.com/books/c2/answers/c18.html