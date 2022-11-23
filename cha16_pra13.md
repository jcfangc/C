### 假设 s 是如下结构（point 是练习题 10 中声明的结构标记）
***
~~~
    struct shape {
        int shape_kind;
        struct point center;
        union {
            struct {
                int height, width;
            } rectangle;
            struct {
                int radious;
            } circle;
        } u;
    } s;
~~~
如果 shape_kind 的值为 RECTANGLE，那么 height 和 width 成员分别在存储举行的两维。如果 shape_kind 的值为 CIRCLE，那么 radious 成员存储圆形的半径。请指出下列哪些语句是合法的，并说明如何修改不合法的语句。<br>
(a) s.shape_kind = RECTANGLE;<br>
(b) s.center.x = 10;<br>
(c) s.height = 25;<br>
(d) s.u.rectangle.width = 8;<br>
(e) s.u.circle = 5;<br>
(f) s.u.radious = 5;
***

<br>

参考答案：<br>
|语句|分析|
|:-|:-|
|(a) s.shape_kind = RECTANGLE;|s 变量具有 struct shape 类型，其中 shape 是成员之一，所以选择符的使用是正确的。根据题设，RECTANGLE 的赋值应该也是正确的。所以本语句合法。|
|(b) s.center.x = 10;|和 shape 相同，center 也是 s 的成员之一。而 center 变量是 struct point 类型的，x 是 center 的成员之一。而 x 正好是 int 型变量，所以赋值也应该是合理的。|
|(c) s.height = 25;|显然 shape 结构中并没有成员 height。如果希望为 height 赋值，我们应该改为：s.u.rectangle.height = 25; 顺理成章的，height 是 rectangle 结构变量的成员，rectangle 是 u 联合变量的成员，u 是 s 结构变量的成员。|
|(d) s.u.rectangle.width = 8;|合理，分析思路类似于上一小题。|
|(e) s.u.circle = 5;|center 显然是个结构变量，无法承接整型赋值。应该该作：s.u.circle.radious = 5;|
|(f) s.u.radious = 5;|radious 不是联合 u 的成员，所以是不合理的。改法同上题。|