### (a) 编写宏 DISP(f, x)， 使其扩展为 printf 函数的调用，显示函数 f 在参数为 x 时的值。<br>例如：DISP(sqrt, 3.0);<br>应该扩展为：<br>printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0));
### (b) 编写宏 DISP2(f, x, y)，类似 DISP 但是应用于有两个参数的函数。<br>

<br>

参考答案：<br>
(a)
~~~
    #define DISP(f,x) printf(#f"(%g) = %g\n", (x), #f(x))
~~~

<br>

(b)
~~~
    #define DISP2(f, x, y) printf(#f"(%g, %g) = %g\n", (x), (y), #f((x),(y)))
~~~

