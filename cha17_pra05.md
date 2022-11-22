### 假设 f 和 p 的声明如下所示：
***
~~~
    struct {
        union {
            char a, b;
            int c;
        } d;
        int e[4];
    } f, *p = &f;
~~~
那么下列那些语句是合法的？<br>
(a) p->b = ' ';<br>
(b) p->e[3] = 10;<br>
(c) (\*p).d.a = '\*';<br>
(d) p->d->c = 20;
***

<br>

参考答案：<br>
|语句|分析|
|:-|:-|
|(a) p->b = ' ';|p 是指向 struct 类型变量 f 的指针，p->b 表示调用 f 的成员 b，但是可以发现 f 的成员只有 e 和 d。出现了矛盾的地方，意味着这一语句是不合理的。|
|(b) p->e[3] = 10;|如上题分析所述，p->e[3] 是合理的，e 又是 int 型数组，元素都是 int 类型，所以赋值也是合理的。|
|(c) (\*p).d.a = '\*';|是合理的，a 是 d 的成员，d 又是 f 的成员，f 被 p 所指向，赋值类型也符合，所以是合理的。另外括号是必须的，才等同于右选择符。|
|(d) p->d->c = 20;|截止到 p->d 是合理的，但是 d->c 是不合理的，因为 d 并不是任何指向结构或联合的指针。|

<br>

书作者答案：http://knking.com/books/c2/answers/c17.html<br>
 (b) and (c) are legal. (a) is illegal because it tries to reference a member of d without mentioning d. (d) is illegal because it uses -> instead of . to reference the c member of d.