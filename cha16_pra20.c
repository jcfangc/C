// �ٶ� direction �����������£�
// enum {NORTH, SOUTH, EAST, WEST} direction;
// �� x �� y Ϊ int ���͵ı�������д switch ������ direction ��ֵ�����ֵΪ EAST ��ʹ x �� 1�����ֵΪ WEST ��ʹ x �� 1�����ֵΪ south ��ʹ y �� 1�����ֵΪ NORTH ��ʹ y �� 1��

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    enum { NORTH, SOUTH, EAST, WEST } direction;
    int x = 0, y = 0, step;

    printf("\n\t Enter number of steps: ");
    scanf(" %d", &step);
    getchar(); // '\n'

    srand((unsigned)time(NULL));
    for (int i = 0; i < step; i++) {
        // ��������
        direction = rand() % (WEST + 1);
        // ���ݷ���������
        switch (direction) {
            case NORTH:
                y--;
                printf("\n\t Gone north\n\t (%d,%d)", x, y);
                break;
            case SOUTH:
                y++;
                printf("\n\t Gone south\n\t (%d,%d)", x, y);
                break;
            case EAST:
                x++;
                printf("\n\t Gone east\n\t (%d,%d)", x, y);
                break;
            case WEST:
                x--;
                printf("\n\t Gone west\n\t (%d,%d)", x, y);
                break;
            default:
                printf("\n\t ERROR");  break;
        }
    }

    getchar();
    return 0;
}