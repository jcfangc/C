### ���� 13.6 ���еķ��������� 13.4 ���е� count_space �������������Ҫ�� while ѭ���滻 for ��䡣
***
ԭ 13.4 ���е� count_space ������
~~~
    int count_space(const char s[])
    {
        int count = 0, i;

        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ') {
                count++;
            }
        }

        return count;
    }
~~~
***

<br>

�ο��𰸣�<br>
|���|�ش�|
|:-|:-|
|(a)|3|
|(b)|0|
|(c)|��һ��û�г����� t �е� s ����ĸ������ s �е�λ��|

�� ԭ�����ӣ�http://knking.com/books/c2/answers/c13.html ��