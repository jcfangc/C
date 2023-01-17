### 下列哪些声明是合法的？（假设 PI 是表示 3.14159 的宏。）
***
(a) char c = 65;<br>
(b) static int i = 5, j = i * i;<br>
(c) double d = 2 * PI;<br>
(d) double angles[] = { 0, PI/2, PI, 3*PI/2 };<br>
***

<br>

参考答案：<br>
(a) 的初始化是正确的。<br>
(b) 的初始化是错误的，由于包含 static 关键字，说明 j 存在静态存储期限，而具有静态存储期限的变量的初始化式必须是常量。<br>
(c) 正确。<br>
(d) 正确。<br>

书作者答案链接：http://knking.com/books/c2/answers/c18.html