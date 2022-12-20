// �޸� 8.2 �ڵ� deal.c ����ʹ����ʾ���Ƶ�ȫ����

// Enter number of cards in hand: 5
// Your hand:
// Seven of clubs
// Two of spades
// Five of diamonds
// Ace of spades
// Two of hearts

// ��ʾ����ָ���ַ�����ָ���������������� rank_code ������ suit_code��

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_RANK 13
#define NUM_SUIT 4
#define SIZE 30

int main(int argc, char *argv[])
{
    // �������� һ����¼��Ƭ�Ƿ��ȡ���ļ�¼��һ��SUIT���飬һ��RANK���飬�鿨������rank��suit��card
    _Bool picked[NUM_SUIT][NUM_RANK] = { false };
    const char *suits[] = { "spades", "hearts", "clubs", "dimands" };
    const char *ranks[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    int card_count = 0;
    int rank, suit, num_hand;

    for (;;) {
        printf("\n\t Enter card number in hand: ");
        scanf(" %d", &num_hand);
        getchar();
        if (num_hand < 1 || num_hand > 52) {
            continue;
        }
        break;
    }

    char *cards[num_hand];

    // ��ʼ��ָ������
    for (int i = 0; i < num_hand; i++) {
        *(cards + i) = (char *)calloc(1, sizeof(char) * SIZE);
    }

    srand((unsigned)time(NULL));

    // ѭ����ʼ��ֱ����ȡ������
    while (card_count < num_hand) {
        // ��ȡ��Ƭ
        suit = rand() % 4;
        rank = rand() % 13;
        // ��⿨Ƭ�Ƿ��Ѿ�����ȡ
        if (picked[suit][rank] == false) {
            // ������Ƭ¼�� cards�����ǵ�Ԥ���Ŀռ�ǳ����㣬���ﲻʹ�� strncpy �� strncat��
            strcpy(cards[card_count], ranks[rank]);
            strcat(cards[card_count], " of ");
            strcat(cards[card_count], suits[suit]);
            card_count++;
        }
        else {
            continue;
        }
    }

    // ��ӡ
    printf("\n\t Your hand: ");
    for (int i = 0; i < num_hand; i++) {
        printf("\n\t %s", cards[i]);
        free(*(cards + i));
    }

    getchar();
    return 0;
}