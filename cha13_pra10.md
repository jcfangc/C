### ����ĺ������ڴ����ַ�������ͬ��������ָ����������еĴ���
***
~~~
    char *duplicate(const char *p)
    {
        char *q;

        strcpy(q, p);
        return q;
    }
~~~
***

<br>

�ο��𰸣�<br>
|����|���|
|:-|:-|
|char* duplicate(const char* p)|������ȷ������Ҫ�ﵽ�Ĺ��ܣ�������һ���ַ��������պ������ص�Ӧ���Ǹ��ַ����ĸ����������ζ�ź�������ʽ����Ӧ�������� cha * �� char[] ���͵ġ����Կ�����Ŀ��Ϊ��ȷ�������Ƶ����鲻�ᱻ�޸������ const����Ҳ��û������ġ��������ķ���ֵҲ���趨Ϊ char *������������Ҫ��ɵ������������롣|
|char(*q);|�ڴ˶����� char * �͵�ָ�� q����֮����������Ϊָ�򱻸��Ƶ������ָ�롣|
|strcpy(q, p);|������ strcpy ������ p ��ָ����ַ����飬���Ƶ��� q �С�|
|return q;|���سɹ����ƺõ��ַ����鸱�� q��|

<br>

���߿����ƺ������ĺ���û��ʲô���⣬����ԭ�����߸����Ĵ�˵�������⣺The value of q is undefined, so the call of strcpy attempts to copy the string pointed to by p into some unknown area of memory. Exercise 2 in Chapter 17 discusses how to write this function correctly. ���ߵ���˼����ǣ����� q ��û�еõ���ʼ������ʱ��ָ���ڴ��еĵ�ַ��δ֪�ģ����Ե�����ʹ�� strcpy �������ʱ���ͽ�Ҫ�����Ƶ��ַ�������õ����ڴ���ĳ�������ĵ�ַ�С������� 17 ����ϰ 2 �л����������������ȷд����
�� Դ�ԣ�http://knking.com/books/c2/answers/c13.html ��