### ���� s �����½ṹ��point ����ϰ�� 10 �������Ľṹ��ǣ�
***
~~~
    struct shape {
        int shape_kind;
        struct point center;
        union {
            struct {
                int height, width;
            } rectangle;
            struct {
                int radious;
            } circle;
        } u;
    } s;
~~~
��� shape_kind ��ֵΪ RECTANGLE����ô height �� width ��Ա�ֱ��ڴ洢���е���ά����� shape_kind ��ֵΪ CIRCLE����ô radious ��Ա�洢Բ�εİ뾶����ָ��������Щ����ǺϷ��ģ���˵������޸Ĳ��Ϸ�����䡣<br>
(a) s.shape_kind = RECTANGLE;<br>
(b) s.center.x = 10;<br>
(c) s.height = 25;<br>
(d) s.u.rectangle.width = 8;<br>
(e) s.u.circle = 5;<br>
(f) s.u.radious = 5;
***

<br>

�ο��𰸣�<br>
|���|����|
|:-|:-|
|(a) s.shape_kind = RECTANGLE;|s �������� struct shape ���ͣ����� shape �ǳ�Ա֮һ������ѡ�����ʹ������ȷ�ġ��������裬RECTANGLE �ĸ�ֵӦ��Ҳ����ȷ�ġ����Ա����Ϸ���|
|(b) s.center.x = 10;|�� shape ��ͬ��center Ҳ�� s �ĳ�Ա֮һ���� center ������ struct point ���͵ģ�x �� center �ĳ�Ա֮һ���� x ������ int �ͱ��������Ը�ֵҲӦ���Ǻ���ġ�|
|(c) s.height = 25;|��Ȼ shape �ṹ�в�û�г�Ա height�����ϣ��Ϊ height ��ֵ������Ӧ�ø�Ϊ��s.u.rectangle.height = 25; ˳����µģ�height �� rectangle �ṹ�����ĳ�Ա��rectangle �� u ���ϱ����ĳ�Ա��u �� s �ṹ�����ĳ�Ա��|
|(d) s.u.rectangle.width = 8;|��������˼·��������һС�⡣|
|(e) s.u.circle = 5;|center ��Ȼ�Ǹ��ṹ�������޷��н����͸�ֵ��Ӧ�ø�����s.u.circle.radious = 5;|
|(f) s.u.radious = 5;|radious �������� u �ĳ�Ա�������ǲ�����ġ��ķ�ͬ���⡣|