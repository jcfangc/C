### ���� s �����½ṹ��
***
~~~
    struct {
        double a;
        union {
            char b[4];
            double c;
            int d;
        } e;
        char f[4];
    } s;
~~~
��� char ����ֵռ�� 1 ���ֽڣ�int ����ֵռ�� 4 ���ֽڣ��� double ����ֵռ�� 8 ���ֽڣ���ô C ��������Ϊ s ��������ڴ�ռ䣿�����������û���ڳ�Ա֮������ ���ն�������
***

<br>

�ο��𰸣�<br>
struct ��Ϊÿ����Ա��������Ե��ڴ棬���� union ֻ��������е�һ���������͵ĳ�Ա������ڴ��С�����ڴ档���ԣ��ܹ�������ֽ����� 8(double a) + 8(union {... double c ...} e) + 4(char f[4]) = 20

<br>

�����ߴ𰸣�http://knking.com/books/c2/answers/c16.html<br>
The a member will occupy 8 bytes, the union e will take 8 bytes (the largest member, c, is 8 bytes long), and the array f will require 4 bytes, so the total space allocated for s will be 20 bytes.