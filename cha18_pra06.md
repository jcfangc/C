### ����ĺ���ϣ����ӡһ��������Ϣ��ÿ����Ϣ��ǰ����һ�����������������Ѿ��������˶��ٴΡ�������Ϣǰ����������� 1���ҳ��������ڣ���˵������ڲ��Ժ����ⲿ���κ��޸ĵ�����������ô���
***
~~~
    void print_error(const char *message)
    {
        int n = 1;
        printf("ERROR %d: %s\n", n++, message);
    }
~~~
***

<br>

�ο��𰸣�<br>
~~~
    void print_error(const char *message)
    {
        static int n = 1;
        printf("ERROR %d: %s\n", n++, message);
    }
~~~