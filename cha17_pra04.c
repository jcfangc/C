// ����������������Ч��
    // struct point { int x, y; };
    // struct rectangle { struct point upper_left, lower_right; };
    // struct rectangle *p;
// ����ϣ�� p ָ��һ�� rectangle �ṹ���˽ṹ�����Ͻ�λ�� (10, 25) ��λ���ϣ������½�λ�� (20, 15) ��λ���ϡ����дһϵ���������������һ���ṹ��������˵�����������г�ʼ����

#include <stdio.h>
#include <stdlib.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
struct rectangle *p;

int main(void)
{
    // �� p ��ָ�� һ�� rectangle �ṹ
    p = malloc(sizeof(struct rectangle));
    // ��ʼ��
    p->upper_left.x = 10;
    p->upper_left.y = 25;
    p->lower_right.x = 20;
    p->lower_right.y = 15;

    free(p);
    getchar();
    return 0;
}