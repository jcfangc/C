### (C99) 假定有下列宏定义：
***
~~~
    #define IDENT(x) PRAGMA(ident #x)
    #define PRAGMA(x) _Pragma(#x)
~~~
下面的代码行在宏扩展之后会变成什么样子？
~~~
    IDENT(foo)
~~~
***

<br>

参考答案：<br>
|当前代码行|替换结果|
|:-|:-|
|IDENT(foo)|PRAGMA(ident "foo")|
|PRAGMA(ident "foo")|_Pragma("ident \"foo\"")|
|_Pragma("ident \"foo\"")|#pragma idnet "foo"|