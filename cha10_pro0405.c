// 修改 10.5 节的 poker.c 程序，使其能识别牌的另一种类别 —— “同花大顺” （同花色的 A、K、Q、J 和 10）。同花大顺的级别高于其他所有类别。
// 修改 10.5 节的 poker.c 程序，使其允许 “小 A 顺” （即 A、2、3、4 和 5）。



// c10 p4 p5
// 接收手牌，然后分析手牌
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define SUIT 1
#define RANK 0
#define NUM_HANDS 5
#define NUM_RANK 13
#define NUM_SUIT 4

int pair = 0;
_Bool three, straight, flush, four, royal_f, a_f;


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
  const char rank[NUM_RANK] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };
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
        if (rank[rank_mark] == hand[i][RANK] && suit[suit_mark] == hand[i][SUIT]) {
          duplicate_check = false;
        }
      }
      if (duplicate_check == true) {
        hand[cards][RANK] = rank[rank_mark];
        hand[cards][SUIT] = suit[suit_mark];
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
      if (hand[i][RANK] == in_pairs[k]) {
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
      if (hand[i][RANK] == hand[j][RANK]) {
        in_pairs[j] = hand[j][RANK];
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
        if (hand[i][RANK] == hand[j][RANK] && hand[j][RANK] == hand[k][RANK]) {
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
      if (hand[i][RANK] == hand[j][RANK]) {
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
  royal_f = true;
  a_f = true;
  const char rank[NUM_RANK] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };
  int rank_1, rank_2;
  const char royal_flush[NUM_HANDS] = { 'T','J','Q','K','A' };
  _Bool royal_flush_check[NUM_HANDS] = { false };
  const char a_flush[NUM_HANDS] = { '2','3','4','5','A' };
  _Bool a_flush_check[NUM_HANDS] = { false };

  // 检查是否有可能是同花大顺所属花色
  for (int k = 0; k < NUM_HANDS; k++) {
    for (int j = 0; j < NUM_HANDS; j++) {
      if (royal_flush[k] == hand[j][RANK]) {
        royal_flush_check[k] = true;
        break;
      }
    }
  }
  // 确认是不是同花大顺
  for (int i = 0; i < NUM_HANDS; i++) {
    if (!royal_flush_check[i]) {
      royal_f = false;
      break;
    }
  }

  if (!royal_f) {
    // 检查是否有可能是小 A 顺所属花色
    for (int k = 0; k < NUM_HANDS; k++) {
      for (int j = 0; j < NUM_HANDS; j++) {
        if (a_flush[k] == hand[j][RANK]) {
          a_flush_check[k] = true;
          break;
        }
      }
    }
    // 确认是不是小 a 顺
    for (int i = 0; i < NUM_HANDS; i++) {
      if (!a_flush_check[i]) {
        a_f = false;
        break;
      }
    }
  }


  if (!(a_f || royal_f)) {
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
  }

  // 判断是不是同花
  flush = false;
  int suit_diversity = 0;
  // 遍历 hands 的第二列，找到每一张手牌花色，如果不相同，suit_diversity + 1，最后判断是否为零即可。
  for (int i = 0; i < (NUM_HANDS - 1); i++) {
    if (hand[i][SUIT] != hand[i + 1][SUIT]) {
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
  if (straight && flush && royal_f) {
    printf("\t Royal Flush \n\n");
  }
  else if (straight && flush && a_f) {
    printf("\t A Flush \n\n");
  }
  else if (straight && flush) {
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


// 书作者则用回了 num_in_rank 和 num_in_suit 两个数组，也将录入的数据重排并转换成了整型。所以书作者的答案更加简洁明了，更值得大家学习。
// knking.com/books/c2