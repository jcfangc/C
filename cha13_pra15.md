### ���� f ������ʾ��
***
~~~
    int f(char *s, char *t)
    {
        char(*p1), (*p2);

        for (p1 = s; *p1; p1++) {
            for (p2 = t; *p2; p2++) {
                if (*p1 == *p2) {
                    break;
                }
            }
            if ((*p2) == '\0') {
                break;
            }
        }
        return (p1 - s);
    }
~~~
(a) f("abcd", "babc") ��ֵ�Ƕ��٣�<br>
(b) f("abcd", "bcd") ��ֵ�Ƕ��٣�<br>
(c) �����������ַ��� s �� t ʱ������ f �ķ���ֵһ����ʲô��
***

<br>

�ο��𰸣�<br>
|���|�ش�|
|:-|:-|
|(a)|3|
|(b)|0|
|(c)|��һ��û�г����� t �е� s ����ĸ������ s �е�λ��|

�� ԭ�����ӣ�http://knking.com/books/c2/answers/c13.html ��