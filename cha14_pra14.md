### ָ������ĳ�����Ԥ��������ʽ�������м��п��ܻᵼ�±���������ҳ���Щ����
***
~~~
    #define N = 10
    #define INC(x) x+1
    #define SUB (x,y) x - y
    #define SQR(x) ((x)*(x))
    #define CUBE(x) (SQR(x)*(x))
    #define M1(x,y) x##y
    #define M2(x,y) #x #y

    int main(void)
    {
        int a[N], i, j, k, m;

    #ifdef N
        i = j;
    #else
        j = i;
    #endif

        i = 10 * INC(j);
        i = SUB(j, k);
        i = SQR(SQR(j));
        i = CUBE(j);
        i = M1(j, k);
        puts(M2(i, j));

    #undef SQR
        i = SQR(j);
    #define SQR
        i = SQR(j);

        return 0 ;
    }
~~~
***

<br>

�ο��𰸣�
|������|�����ж�|
|:-|:-|
|#define N = 10|����Ҫ =�������滻�б���� = 10���ڳ���Ԥ�����<br>int a[N], i, j, k, m;<br>����<br>int a[= 10], i, j, k, m;<br>����Ȼ�ǲ��Եġ�|
|#define INC(x) x+1|��û��Ǹ������������滻�б����С���š������򾭹�Ԥ�����<br>i = 10 * INC(j);<br>����<br>i = 10 * j + 1;<br>����˳����ܻ��Ԥ��������ͬ��|
|#define SUB (x,y) x - y|��д��ĸ�ʽ�����⣬����������С���źͺ���֮���ǲ�Ӧ���пո�ģ����� C ��Ѳ������Ϊ�滻�б��һ���֣��ڱ�����Ԥ�����<br>i = SUB(j, k);<br>����<br>i = (j, k) x - y;<br>����Ķ��ſ��ܻᱻ��Ϊ�����������Ȼ����������ǲ���ͨ������ġ�|
|#define SQR(x) ((x)*(x))|����Ӧ����û������ġ������ں����г����˶� SQR �������壬����ζ�� SQR �����û���滻�б�ģ����³����޷�������ֵ��|
|#define CUBE(x) (SQR(x)*(x))|����Ӧ����û������ġ�Ϊ��ͬ��|
|#define M1(x,y) x##y|��Ķ�����û������ģ����Ƕ�Ӧ��Ӧ�ÿ��ܲ�̫������Ԥ����󣬴�����<br>i = M1(j, k);<br>����<br>i = jk;<br>�������ǵı����в�û����Ϊ jk �ı�����|
|#define M2(x,y) #x #y|��Ķ���Ӧ����û������ģ����Ǻ��Ӧ�ÿ��ܲ�̫������Ԥ�����<br>puts(M2(i, j));<br>���Ϊ<br>puts("i""j");��<br>puts �ĺ���ԭ��Ϊ <br>int puts(const char *s);<br>��ʱ�������ַ��������������� puts ֻ��Ҫһ���ַ������������п��ܳ��ֳ��򾯸档|
|#ifdef N  ...  #else  ...  #endif|��߲������� N �Ѿ��������ˣ����Ի����µ�һ����֧����䣬Ҳ���� i = j;|

<br>

�����ߴ𰸣�<br>
http://knking.com/books/c2/answers/c14.html