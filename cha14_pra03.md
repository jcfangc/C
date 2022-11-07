### 假定 DOUBLE 是如下宏：<br> #define DOUBLE(x) 2*x <br> (a) DOUBLE(1+2) 的值是多少？ <br> (b) 4 / DOUBLE(2) 的值是多少？ <br> (c) 改正 DOUBLE 的定义。

<br>

参考答案：
|序号|宏及其参数|替换列表演算|
|:-|:-|:-|
|a|DOUBLE(1+2)|2 * 1 + 2 <br> -> 2 + 2 <br> -> 4|
|b|4 / DOUBLE(2)|4 / 2 * 2 <br> -> 2 * 2 <br> -> 4|
|c|改正 DOUBLE 的定义|将实际参数都使用括号包围起来即可：<br> DOUBLE(x) (2 * (x))|