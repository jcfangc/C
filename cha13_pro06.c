// �Ľ� 13.7 �ڵĳ��� planet.c��ʹ���ڶ������в����� planets �����е��ַ������бȽ�ʱ���Դ�Сд��

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
    char *planets[] = { "mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune", "pluto" };
    int i, j;

    // agrv[0] --> ������
    for (i = 1; i < argc; i++) {
        // �������в���ȫ��תΪСд
        for (int k = 0; k < (int)strlen(argv[i]); k++) {
            argv[i][k] = tolower(argv[i][k]);
        }
        // �Ƚ�Сд���������в��������� planets �鿴�Ƿ�����ͬ���ַ���
        for (j = 0; j < NUM_PLANETS; j++) {
            if (strcmp(argv[i], planets[j]) == 0) {
                printf("\n\t %c%s is planet %d. ", toupper(argv[i][0]), argv[i] + 1, j + 1);
                break;
            }
        }
        // j ���ֵ��ӦΪ NUM_PLANETS - 1���� j == NUM_PLANETS��˵�����������û�з���ƥ����ַ���
        if (j == NUM_PLANETS) {
            printf("\n\t %c%s is not a planet. ", toupper(argv[i][0]), argv[i] + 1);
        }
    }

    getchar();
    return 0;
}