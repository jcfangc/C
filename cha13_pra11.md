### ���µ� ������� ����˵������������ȡ�±��������д strcmp �����ķ��������޸Ĵ˺���������ָ��������������д��
***
~~~
    int strcmp(char *s, char *t)
    {
        int i;

        for (i = 0; s[i] == t[i]; i++) {
            if (s[i] == '\0') {
                return 0;
            }
        }

        return s[i] - t[i];
    }
~~~
***

<br>

�ο��𰸣�<br>
~~~
    int mystrcmp(const char *s, const char *t)
    {
        for (; *s == *t; (s++, t++)) {
            if (*s == '\0') {
                return 0;
            }
        }

        return (*s - *t);
    }
~~~