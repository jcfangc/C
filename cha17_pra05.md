### ���� f �� p ������������ʾ��
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
��ô������Щ����ǺϷ��ģ�<br>
(a) p->b = ' ';<br>
(b) p->e[3] = 10;<br>
(c) (\*p).d.a = '\*';<br>
(d) p->d->c = 20;
***

<br>

�ο��𰸣�<br>
|���|����|
|:-|:-|
|(a) p->b = ' ';|p ��ָ�� struct ���ͱ��� f ��ָ�룬p->b ��ʾ���� f �ĳ�Ա b�����ǿ��Է��� f �ĳ�Աֻ�� e �� d��������ì�ܵĵط�����ζ����һ����ǲ�����ġ�|
|(b) p->e[3] = 10;|���������������p->e[3] �Ǻ���ģ�e ���� int �����飬Ԫ�ض��� int ���ͣ����Ը�ֵҲ�Ǻ���ġ�|
|(c) (\*p).d.a = '\*';|�Ǻ���ģ�a �� d �ĳ�Ա��d ���� f �ĳ�Ա��f �� p ��ָ�򣬸�ֵ����Ҳ���ϣ������Ǻ���ġ����������Ǳ���ģ��ŵ�ͬ����ѡ�����|
|(d) p->d->c = 20;|��ֹ�� p->d �Ǻ���ģ����� d->c �ǲ�����ģ���Ϊ d �������κ�ָ��ṹ�����ϵ�ָ�롣|

<br>

�����ߴ𰸣�http://knking.com/books/c2/answers/c17.html<br>
 (b) and (c) are legal. (a) is illegal because it tries to reference a member of d without mentioning d. (d) is illegal because it uses -> instead of . to reference the c member of d.