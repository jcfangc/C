### ��ִ�����������ַ��� s1 ��ֵ��ʲô��
***
~~~
    strcpy(s1, "computer");
    strcpy(s2, "science");
    if (strcmp(s1, s2) < 0)
        strcat(s1, s2);
    else
        strcat(s2, s1);
    s1[strlen(s1) - 6] = '\0';
~~~
***

<br>

�ο��𰸣�computers<br>
~~~
    strcpy(s1, "computer");
    strcpy(s2, "science");
~~~
�����������ֱ��� s1 �� s2 �ֱ��Ⱥ󱻸��� computer\0 �� science\0 �����ݡ�
~~~
    if (strcmp(s1, s2) < 0)
        strcat(s1, s2);
    else
        strcat(s2, s1);
~~~
���ϵ� if else ���ʹ�� s1 ֮���ν��� s2 �����ݡ���ǰ s1 ������Ϊ computerscience\0��s2 ������Ϊ science��
~~~
    s1[strlen(s1) - 6] = '\0';
~~~
����������� 9���� str �������һ�����ַ���Ҳ��˸��ǵ�����ĸ c�����գ�s1 ������Ϊ computers\0cience\0����Ȼ����ʹ�� s1�����ӡ������ʱ�򣬻���ʾ s1 Ϊ computers��