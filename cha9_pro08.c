// 编写函数模拟掷骰子的游戏（两个骰子）。第一次掷的时候，如果点数之和为 7 或 11 则获胜；如果点数之和为 2、3 或 12 则落败；其他情况下的点数之和称为 “目标” ，游戏继续。在后续的投掷中，如果玩家再次掷出 “目标” 点数则获胜，掷出 7 则落败，其他情况都忽略，游戏继续进行。每局游戏结束时，程序询问用户是否再玩一次，如果用户输入的回答不是 y 或 Y ,程序会显示胜败的次数然后终止。


// You rolled: 8 
// Your point is 8 
// You rolled: 3 
// You rolled: 10 
// You rolled: 8 
// You win!


// Play again? y


// You rolled: 6 
// Your point is 6 
// You rolled: 5 
// You rolled: 12 
// You rolled: 3 
// You rolled: 7 
// You lose!


// Play again? y


// You rolled: 11 
// You win!


// Play again? n


// Wins: 2 Losses: 1


// 编写三个函数: main、roll_dice和play_game。下面给出了后两个函数的原型:
// int roll_dice (void) ;
// bool play_ game (void) ;
// roll_dice 应生成两个随机数（每个都在1和6之间)），并返回它们的和。play_game 应进行一次掷骰子游戏（调用rol1_dice确定每次掷的点数），如果玩家获胜则返回 true，如果玩家落败则返回 false_play_game 函数还要显示玩家每次掷骰子的结果。main 函数反复调用 play_game 函数，记录获胜和落败的次数，并显示 "you win” 和 “you lose" 消息。提示：使用 rand 函数生成随机数。关于如何调用 rand 和相关的 srand 函数，见 8.2 节 deal.c 程序中的例子。


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define WIN 1
#define LOSE 0

int roll_dice(void);
_Bool play_game(void);

int main(void)
{
    int win_times = 0, lose_times = 0;
    int target = 0;

    while (1) {
        if (roll_dice()) {
            ++win_times;
        }
        else {
            ++lose_times;
        }

        if (play_game()) {
            continue;
        }
        printf("\n\t WIN: %d\t LOSE: %d", win_times, lose_times);
        break;
    }

    getchar();
    printf("\n\n");
    return 0;
}

_Bool play_game(void)
{
    printf("\n\n\t Play again? (Enter y/Y or n/N) ");
    if (toupper(getchar()) == 'Y') {
        getchar(); // 吸收回车
        return true;
    }
    else {
        getchar(); // 吸收回车
        return false;
    }

}

int roll_dice(void)
{
    int dice1[6] = { 1,2,3,4,5,6 };
    int dice2[6] = { 1,2,3,4,5,6 };
    int target = 0;

    srand((unsigned)time(NULL));

    int num1 = rand() % 6;
    int num2 = rand() % 6;

    // 首轮游戏
    int sum = (dice1[num1] + dice2[num2]);
    printf("\n\t You rolled %d. ", sum);
    // 胜利条件确定
    if (sum == 7 || sum == 11) {
        printf("\n\t You win!");
        return WIN;
    }
    else if (sum == 2 || sum == 3 || sum == 12) {
        printf("\n\t You lose!");
        return LOSE;
    }
    // 非首轮游戏
    else {
        target = sum;
        printf("\n\t your point is %d. ", target);
        for (;;) {
            num1 = rand() % 6;
            num2 = rand() % 6;
            sum = (dice1[num1] + dice2[num2]);
            printf("\n\t You rolled %d. ", sum);
            // 胜利条件确定
            if (sum == target) {
                printf("\n\t You win!");
                return WIN;
            }
            else if (sum == 7) {
                printf("\n\t You lose!");
                return LOSE;
            }
            else {
                continue;
            }
        }
    }
}