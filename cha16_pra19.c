// ����һ���������³�Ա�Ľṹ������Ϊ pinball_machine��
// name ���� �ַ�������� 40 ���ַ�
// year ���� ��������ʾ�������
// type ���� ö�����͵�ֵ�����ܵ�ȡֵΪ EM������ʽ�ģ��� SS����̬��·�ģ�
// players ���� ��������ʾ��ҵ������Ŀ

#define NULL_CHAR 1

typedef struct pinball_machine {
    // �ǵ�Ϊ���ַ���λ
    char name[40 + NULL_CHAR];
    int year;
    enum { EM, SS } type;
    // ���ǵ������ĿӦ���Ǹ��̶��ģ�����ʹ���������޶��� const
    const int players;
} pinball_machine;