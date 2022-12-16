### 下列声明中，枚举常量的整数值分别是多少？
***
(a) enum {NUL, SOH, STX, ETX};<br>
(b) enum {VT = 11, FF, CR};<br>
(c) enum {SO = 14, SI, DLE, CAN = 24, EM};<br>
(d) enum {ENQ = 25, ACK, BEL, LF = 37, ETB, ESC};
***

<br>

参考答案：<br>
|题号|变量1|变量2|变量3|变量4|变量5|变量6|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|a|NUL = 0|SOH = 1|STX = 2|ETX = 3|/|/|
|b|VT = 11|FF = 12|CR = 13|/|/|/|
|c|SO = 14|SI = 15|DLE = 16|CAN = 24|EM = 25|/|
|d|ENQ = 25|ACK = 26|BEL = 27|LF = 37|ETB = 38|ESC = 39|

当没有为枚举常量指定值时，它的值比前一个常量的值大 1。