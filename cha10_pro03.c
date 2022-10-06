// 把数组 num_in_rank、num_in_suit 和 card_exists 从 10.5 节的 poker.c 程序中去掉。程序改用 5 * 2 的数组来存储牌。数组的每一行表示一张牌。例如，如果数组名为 hand，则 hand[0][0] 存储第一 张牌的等级，hand[0][1] 存储第一张牌的花色。


// 接收手牌，然后分析手牌
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define RANK 0
#define SUIT 1
#define NUM_HANDS 5
#define NUM_RANK 13
#define NUM_SUIT 4

int pair = 0;
_Bool three, straight, flush, four;


void read_card(char[][2]);
void analyze_hand(char[][2]);
void print_result(void);

int main(void)
{
  char hand[NUM_HANDS][2] = { {'\0'} };

  printf("\n\t Enter 0 to stop. \n");

  for (;;) {
    read_card(hand);
    analyze_hand(hand);
    print_result();
  }

  printf("\n\n");
  return 0;
}

/************************************************************************
 * read_card 是用来录入五张牌的信息的。同时要确保不重复，不记录无效信息 *
 ************************************************************************/
void read_card(char hand[][2])
{
  // rank 数组
  const char rank[NUM_RANK] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
  // suit 数组
  const char suit[NUM_SUIT] = { 'C','D','H','S' };
  // 询问手牌
  int cards = 0;
  for (; cards < NUM_HANDS;) {
    // 得到 rank 和 suit 数据
    printf("\t Enter a hand card: ");
    for (;;) {
      char ch;
      int pass_code = 0;
      int rank_mark = -1, suit_mark = -1;
      ch = toupper(getchar());
      if (ch == '0') {
        exit(0);
      }
      if (ch == '1') {
        ch = 'T';
        getchar(); // 吃掉 0
      }
      for (int i = 0; i < NUM_RANK; i++) {
        if (ch == rank[i]) {
          rank_mark = i;
          pass_code = 1;
          break;
        }
      }
      // 如果 pass_code 没有变成 1 则说明上面这个字符不会录入到 rank 中，需要重新再尝试录入到 suit 中，不需要getchar()。
      if (pass_code) {
        ch = toupper(getchar());
      }
      for (int i = 0; i < NUM_SUIT; i++) {
        if (ch == suit[i]) {
          suit_mark = i;
          break;
        }
      }
      // 由于 pass_code 没有变成 1 则说明上面这个字符很可能会录入 suit 中，需要重新再尝试录入到 rank 中，需要getchar()。
      if (!pass_code) {
        ch = toupper(getchar());
        if (ch == '1') {
          ch = 'T';
          getchar(); // 吃掉 0
        }
        for (int i = 0; i < NUM_RANK; i++) {
          if (ch == rank[i]) {
            rank_mark = i;
            break;
          }
        }
      }
      getchar(); // 吸收换行符

      // 卡片信息是否正常
      if (suit_mark == -1 || rank_mark == -1) {
        printf("\t Bad card, try again. ");
        continue;
      }
      // 比较发现重复,牌不存在，重复以上几步
      _Bool duplicate_check = true;
      for (int i = 0; i < cards; i++) {
        if (rank[rank_mark] == hand[i][0] && suit[suit_mark] == hand[i][1]) {
          duplicate_check = false;
        }
      }
      if (duplicate_check == true) {
        hand[cards][0] = rank[rank_mark];
        hand[cards][1] = suit[suit_mark];
        break;
      }
      else if (duplicate_check == false) {
        printf("\t Duplicate card, try again. ");
        continue;
      }
    }
    // 比较发现没重复，询问下一手牌，集齐 5 张手牌信息后函数返回。
    ++cards;
  }
  return;
}

/**************************************************************************************************
 * analyze_hand 是用来判别手牌的类型的，判断了几个较为基本的牌型，分别为 对子 三张 四张 顺子 同花 *
 **************************************************************************************************/
void analyze_hand(char hand[][2])
{
  // 判断对子数量
  // 要特别注意对子的重复计数
  pair = 0;
  _Bool next = false, first = true;
  char in_pairs[NUM_HANDS] = { '\0' };
  for (int i = 0; i < (NUM_HANDS - 1); i++) {
    for (int k = 0; k < NUM_HANDS; k++) {
      if (first) {
        first = false;
        break;
      }
      if (hand[i][0] == in_pairs[k]) {
        in_pairs[k] = '\0';
        next = true;
        break;
      }
    }

    if (next) {
      next = false;
      continue;
    }
    for (int j = (i + 1); j < NUM_HANDS; j++) {
      if (hand[i][0] == hand[j][0]) {
        in_pairs[j] = hand[j][0];
        pair++;
        break;
      }
    }
  }

  // 判断是否有3连
  three = false;
  for (int i = 0; i < (NUM_HANDS - 2); i++) {
    for (int j = (i + 1); j < (NUM_HANDS - 1); j++) {
      for (int k = (j + 1); k < NUM_HANDS; k++) {
        if (hand[i][0] == hand[j][0] && hand[j][0] == hand[k][0]) {
          three = true;
        }
      }
    }
  }

  // 判断是不是四张
  four = false;
  for (int i = 0; i < (NUM_HANDS - 1); i++) {
    int same_number = 1;
    for (int j = (i + 1); j < NUM_HANDS; j++) {
      if (hand[i][0] == hand[j][0]) {
        same_number++;
      }
    }
    four = (same_number == 4 ? true : false);
    if ((same_number >= 2) && (four == false)) {
      break;
    }
    else if (four == true) {
      break;
    }
  }


  // 判断是不是顺子
  straight = true;
  const char rank[NUM_RANK] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };
  int rank_1, rank_2;

  char ran;
  char sui;
  // 按照 rank 整理手牌顺序
  for (int pass = 1; pass < NUM_HANDS; pass++) {
    for (int cards = 0; cards < NUM_HANDS - pass; cards++) {
      for (int i = 0; i < NUM_RANK; i++) {
        if (hand[cards][RANK] == rank[i]) {
          rank_1 = i;
          break;
        }
      }
      for (int i = 0; i < NUM_RANK; i++) {
        if (hand[cards + 1][RANK] == rank[i]) {
          rank_2 = i;
          break;
        }
      }
      ran = hand[cards][RANK];
      sui = hand[cards][SUIT];
      if (rank_2 < rank_1) {
        hand[cards][RANK] = hand[cards + 1][RANK];
        hand[cards][SUIT] = hand[cards + 1][SUIT];
        hand[cards + 1][RANK] = ran;
        hand[cards + 1][SUIT] = sui;
      }
    }
  }

  // 确定两两手牌之间的差是否为一
  for (int i = 0; i < NUM_HANDS - 1; i++) {
    for (int j = 0; j < NUM_RANK; j++) {
      if (hand[i][RANK] == rank[j]) {
        rank_1 = j;
        break;
      }
    }
    for (int j = 0; j < NUM_RANK; j++) {
      if (hand[i + 1][RANK] == rank[j]) {
        rank_2 = j;
        break;
      }
    }
    if ((rank_2 - rank_1) != 1) {
      straight = false;
    }
  }



  // 判断是不是同花
  flush = false;
  int suit_diversity = 0;
  // 遍历 hands 的第二列，找到每一张手牌花色，如果不相同，suit_diversity + 1，最后判断是否为零即可。
  for (int i = 0; i < (NUM_HANDS - 1); i++) {
    if (hand[i][1] != hand[i + 1][1]) {
      suit_diversity++;
    }
  }
  flush = (suit_diversity == 0 ? true : false);

  return;
}


/***********************************************************************
  * print_result 就是根据分析结果再分析，结果在 analyze_hand 中确定下来 *
  ***********************************************************************/
void print_result(void)
{
  if (straight && flush) {
    printf("\t Straight Flush \n\n");
  }
  else if (four) {
    printf("\t Four of a Kind \n\n");
  }
  // 在本程序的逻辑中 “3连” 中包含有一个 “对子” 所以这个隐含的 “对子” 要被忽略
  else if (three && (pair > 1)) {
    printf("\t Full House \n\n");
  }
  else if (flush) {
    printf("\t Flush \n\n");
  }
  else if (straight) {
    printf("\t Straight \n\n");
  }
  else if (three) {
    printf("\t Three of a Kind \n\n");
  }
  else if (pair == 2) {
    printf("\t Two Pairs \n\n");
  }
  else if (pair == 1) {
    printf("\t A Pair \n\n");
  }
  else {
    printf("\t High Card \n\n");
  }

  return;
}


// 本次程序，改编自本章编程题 2 的答案，很大程度上吸收了书本示例的思想。但通过对比书作者给出的答案还是可以发现很多不足的地方。下面是书作者答案的网站，感兴趣的朋友可以查看完整代码。

// knking.com/books/c2
// Answers to Selected Exercises in Chapter 10 of C Programming : A Modern Approach - Second Edition(knking.com)

// 通过对比，还是可以看出我的程序依旧冗余了。其中导致区别的地方在于书作者在进行判断前，或者说，正式的开始处理数据前，将数据按照一定的规律进行了重排，数据类型也转变为了整型，这为之后的分析工作免去了不少的麻烦。而我则是默默接受了信息数据的顺序和形式，哪怕重新整理能提高之后编程的效率。当然，重排数据这件事一定是要建立在 “数据顺序本身不是数据的一部分” 的基础上。

// 举个例子进行说明吧：当录入 2s 3s 2d 3d 2c 这五张手牌时，书作者将手牌数据处理成 2s 2d 2c 3s 3d 的顺序。之后再判断牌型时需要考虑的内容就少很多了。 如，判断 四张 这种牌型时，书作者设置了 run 这个变量，作用就是在顺序遍历时记录相同的牌有多少，当 run 达到 4 时，你就可以确定 四张 牌型是存在的了。而我在判断 四张 这种牌型时，由于我得到数据后没有将顺序整理，我不得不考虑接受位置乱序的影响下，不同组合可以适用的通式，确实是挺折磨人的，效率也更加底下，编写出的形式也更加复杂。

// 所谓吃一堑长一智，以后从用户收到数据的第一时刻，别急着开始分析，或许整理数据才应该是我们要做的。