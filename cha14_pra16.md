### (C99) �ٶ������к궨�壺
***
~~~
    #define IDENT(x) PRAGMA(ident #x)
    #define PRAGMA(x) _Pragma(#x)
~~~
����Ĵ������ں���չ֮�����ʲô���ӣ�
~~~
    IDENT(foo)
~~~
***

<br>

�ο��𰸣�<br>
|��ǰ������|�滻���|
|:-|:-|
|IDENT(foo)|PRAGMA(ident "foo")|
|PRAGMA(ident "foo")|_Pragma("ident \"foo\"")|
|_Pragma("ident \"foo\"")|#pragma idnet "foo"|