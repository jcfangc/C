// 修改 8.2 节的 deal.c 程序，使它显示出牌的全名：

// Enter number of cards in hand: 5
// Your hand:
// Seven of clubs
// Two of spades
// Five of diamonds
// Ace of spades
// Two of hearts

// 提示：用指向字符串的指针的数组来替代数组 rank_code 和数组 suit_code。

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
    // 变量声明 一个记录卡片是否抽取过的记录表，一个SUIT数组，一个RANK数组，抽卡数量，rank，suit，card
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

    // 初始化指针数组
    for (int i = 0; i < num_hand; i++) {
        *(cards + i) = (char *)calloc(1, sizeof(char) * SIZE);
    }

    srand((unsigned)time(NULL));

    // 循环开始，直到抽取完手牌
    while (card_count < num_hand) {
        // 抽取卡片
        suit = rand() % 4;
        rank = rand() % 13;
        // 检测卡片是否已经被抽取
        if (picked[suit][rank] == false) {
            // 新增卡片录入 cards，考虑到预留的空间非常充足，这里不使用 strncpy 和 strncat。
            strcpy(cards[card_count], ranks[rank]);
            strcat(cards[card_count], " of ");
            strcat(cards[card_count], suits[suit]);
            card_count++;
        }
        else {
            continue;
        }
    }

    // 打印
    printf("\n\t Your hand: ");
    for (int i = 0; i < num_hand; i++) {
        printf("\n\t %s", cards[i]);
        free(*(cards + i));
    }

    getchar();
    return 0;
}