### (a) 说明如何为具有 double 类型的成员 real 和 imaginary 的结构声明名为 complex 的标记。<br> (b) 利用标记 complex 来声明名为 c1，c2 和 c3 的变量。<br> (c) 编写名为 make_complex 的函数，此函数用来把两个实际参数（都是 double 类型）存储在 complex 结构中，然后返回此结构。<br> (d) 编写名为 add_complex 的函数，此函数用来把两个实际参数（都是 complex 结构）的对应成员相加，然后返回结果（另一个 complex 结构）。

<br>

参考答案：
|问题|回答|
|:-|:-|
|说明如何为具有 double 类型的成员 real 和 imaginary 的结构声明名为 complex 的标记。|struct complex {<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double real, imaginary;<br>};|
|利用标记 complex 来声明名为 c1，c2 和 c3 的变量。|struct complex c1, c2, c3;|
|编写名为 make_complex 的函数，此函数用来把两个实际参数（都是 complex 结构）存储在 complex 结构中，然后返回此结构。|struct complex make_complex(double real, double imaginary)<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;struct complex sct;<br><br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sct.real = real;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sct.imaginary = imaginary;<br><br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return sct;<br>}|
|编写名为 add_complex 的函数，此函数用来把两个实际参数（都是 complex 结构）的对应成员相加，然后返回结果（另一个 complex 结构）。|struct complex add_complex(struct complex clx_num1, struct complex clx_num2)<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;struct complex result;<br><br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.real = clx_num1.real + clx_num2.real;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.imaginary = clx_num1.imaginary + clx_num2.imaginary;<br><br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return result;<br>}|