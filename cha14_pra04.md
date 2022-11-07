### 针对下面每一个宏，举例说明宏的问题，并提出修改方法。
***
（a）#define AVG(x, y) (x+y) / 2 <br>
（b）#define AREA(x, y) (x) * (y)
***



<br>

参考答案：
|序号|宏及其参数|替换列表演算|
|:-|:-|:-|
|a|#define AVG(x, y) (x+y) / 2|1. x 和 y 作为参数需要小括号保护，防止出现混乱的计算顺序。<br>2. 我们可以为所有参数设定统一的类型，保证我们得到想要的计算结果。<br>3. 保险起见，我们可以为整个替换列表添加一对小括号，防止替换列表外部出现更高优先级的运算符打乱运算顺序。<br>修改建议：#define AVG(type,x,y) (((type)(x)+(type)(y))/(type)2)|
|b|#define AREA(x, y) (x) * (y)|1. 我们可以为所有参数设定统一的类型，保证我们得到想要的计算结果。<br>2. 保险起见，我们可以为整个替换列表添加一对小括号，防止替换列表外部出现更高优先级的运算符打乱运算顺序。<br>修改建议：#define AREA(x, y) ((type)(x)*(type)(y))|

<br>

原书作者答案：

(a) One problem stems from the lack of parentheses around the replacement list. For example, the statement

a = 1/AVG(b, c);
will be replaced by

a = 1/(b+c)/2;
Even if we add the missing parentheses, though, the macro still has problems, because it needs parentheses around x and y in the replacement list. The preprocessor will turn the statement.

a = AVG(b<c, c>d);
into

a = ((b<c+c>d)/2);
which is equivalent to

a = ((b<(c+c)>d)/2);
Here's the final (corrected) version of the macro:

#define AVG(x,y) (((x)+(y))/2)
(b) The problem is the lack of parentheses around the replacement list. For example,

a = 1/AREA(b, c);
becomes

a = 1/(b)*(c);
Here's the corrected macro:

#define AREA(x,y) ((x)*(y))<br>
( 源自：http://knking.com/books/c2/answers/c14.html )
