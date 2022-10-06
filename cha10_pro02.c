// 修改 10.5 的 poker.c 程序， 把数组 num_in_rank 和数组 num_in_suit 移到 main 函数中。main 函数将把这两个数组作为实际参数传递给 read_cards 函数和 analyse_hand 函数。


// 接收手牌，然后分析手牌
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define PASS 1
#define FAIL 0

int result;

void read_card(int[], int[]);
void analyze_hand(int[], int[]);
void print_result(void);

int main(void)
{
  int number_of_rank[13] = { 0 };
  int number_of_suit[4] = { 0 };

  printf("\n\t Enter 0 to stop. \n");

  for (;;) {
    read_card(number_of_rank, number_of_suit);
    analyze_hand(number_of_rank, number_of_suit);
    print_result();
  }

  getchar();
  printf("\n\n");
  return 0;
}

//read_card 是用来录入五张牌的信息的。同时要确保不重复，不记录无效信息
void read_card(int number_of_rank[], int number_of_suit[])
{
  // 牌库，确认手牌是否已经抽取过了
  int card_exists[4][13] = { {0} };
  // rank 数组
  const char rank[13] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
  // suit 数组
  const char suit[4] = { 'C','D','H','S' };
  // 询问手牌
  int cards = 0;
  for (; cards < 5;) {
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
      for (int i = 0; i < 13; i++) {
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
      for (int i = 0; i < 4; i++) {
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
        for (int i = 0; i < 13; i++) {
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
      if (card_exists[suit_mark][rank_mark] != 1) {
        card_exists[suit_mark][rank_mark] = 1;
        number_of_rank[rank_mark]++;
        number_of_suit[suit_mark]++;
        break;
      }
      else if (card_exists[suit_mark][rank_mark] == 1) {
        printf("\t Duplicate card, try again. ");
        continue;
      }
    }
    // 比较发现没重复，询问下一手牌，集齐 5 张手牌信息后函数返回。
    ++cards;
  }
  return;
}

// analyze_hand 是用来判别手牌的类型的，使用了 if else if 的形式，确保判别的顺序是从优到劣逐级往下的，也确保了不会发生重复
void analyze_hand(int number_of_rank[], int number_of_suit[])
{
  int condition = 0;

  // 按照手牌类别优劣次序判别手牌类型。做出判断即返回。
  // 同花顺
  for (int i = 0; i < 4; i++) {
    if (number_of_suit[i] == 5) {
      condition += PASS;
    }
  }
  for (int i = 0; i < 8; i++) {
    if (number_of_rank[i] == 1 && number_of_rank[i + 1] == 1 && number_of_rank[i + 2] == 1 && number_of_rank[i + 3] == 1 && number_of_rank[i + 4] == 1) {
      condition += PASS;
    }
  }
  if (condition == (PASS * 2)) {
    result = 1; // 让 1 代表结果是同花顺
  }
  else if (condition != (PASS * 2)) {
    condition = 0;
    // 四张
    for (int i = 0; i < 13; i++) {
      if (number_of_rank[i] == 4) {
        condition += PASS;
      }
    }
    if (condition == PASS) {
      result = 2; // 让 2 代表结果是四张
    }
    else if (condition != PASS) {
      condition = 0;
      int pair = 0;
      int trible = 0;
      // 葫芦
      for (int i = 0; i < 13; i++) {
        // 只能有一个对子
        if (!pair) {
          if (number_of_rank[i] == 2) {
            condition += PASS;
            pair++;
          }
        }
        // 只能有一个trible
        if (!trible) {
          if (number_of_rank[i] == 3) {
            condition += PASS;
            trible++;
          }
        }
      }
      if (condition == (PASS * 2)) {
        result = 3; // 让 3 代表结果是葫芦
      }
      else if (condition != (PASS * 2)) {
        condition = 0;
        // 同花
        for (int i = 0; i < 4; i++) {
          if (number_of_suit[i] == 5) {
            condition += PASS;
          }
        }
        if (condition == PASS) {
          result = 4; // 让 4 代表结果是同花
        }
        else if (condition != PASS) {
          condition = 0;
          // 顺子
          for (int i = 0; i < 8; i++) {
            if (number_of_rank[i] == 1 && number_of_rank[i + 1] == 1 && number_of_rank[i + 2] == 1 && number_of_rank[i + 3] == 1 && number_of_rank[i + 4] == 1) {
              condition += PASS;
            }
          }
          if (condition == PASS) {
            result = 5; // 让 5 代表结果是顺子
          }
          else if (condition != PASS) {
            condition = 0;
            // 三张
            for (int i = 0; i < 13; i++) {
              if (number_of_rank[i] == 3) {
                condition += PASS;
              }
            }
            if (condition == PASS) {
              result = 6; // 让 6 代表结果是三张
            }
            else if (condition != PASS) {
              condition = 0;
              // 两对
              for (int i = 0; i < 13; i++) {
                if (number_of_rank[i] == 2) {
                  condition += PASS;
                }
              }
              if (condition == (PASS * 2)) {
                result = 7; // 让 7 代表结果是两对
              }
              else if (condition != (PASS * 2)) {
                condition = 0;
                // 一对
                for (int i = 0; i < 13; i++) {
                  if (number_of_rank[i] == 2) {
                    condition += PASS;
                  }
                }
                if (condition == PASS) {
                  result = 8; // 让 8 代表结果是一对
                }
                else if (condition != PASS) {
                  result = 9; // 让 9 代表结果是其他牌
                }
              }
            }
          }
        }
      }
    }
  }
}

// print_result 就是根据 result 这一外部变量告知用户手牌类型的，而 result 的结果在 analyze_hand 中确定下来
void print_result(void)
{
  switch (result) {
  case 1: printf("\t Straight Flush \n\n");    break;
  case 2: printf("\t Four of a Kind \n\n");    break;
  case 3: printf("\t Full House \n\n");      break;
  case 4: printf("\t Flush \n\n");        break;
  case 5: printf("\t Straight \n\n");        break;
  case 6: printf("\t Three of a Kind \n\n");    break;
  case 7: printf("\t Two Pairs \n\n");      break;
  case 8: printf("\t One Pair \n\n");        break;
  case 9: printf("\t High Card \n\n");      break;
  default:; break;
  }
}

// 我在看到看到章节中有这样作为示例的程序时会自己写一次，再对照书本中的程序对照一次，看看自己有哪些不足。所以这里我就用回了我在对照练习时写的程序进行修改。但我觉得有必要谈谈我自己写的这段程序和书本上的范例相比有什么缺陷：

// 首先谈谈我印象比较深刻的部分。主要就是程序在记录手牌和判别手牌的思维方式上。示例中各种手牌类型之间的逻辑关系梳理的更加透彻，这也在一定程度上避免了算力的浪费。比方说，同花顺，就是同花的顺子，或者说正好可以凑成顺子的同花色牌，在了解了这一层的含义后，程序就可以分别判定这幅手牌是否是顺子，是否是同花色的。当需要 “同花顺” 时，只需要判断 “是顺子” “是同花色” 这两个条件是否同时成立即可。而我自己编写的相同功能部分，成功运行却明显有些冗余和笨拙。这很大程度上在于我没有梳理最终我要做出判断的选择之间有什么相同点和不同点。

// 同花顺 == 同花 + 顺子
// 四张 == 四张等级相同
// 葫芦 == 对子 + 三张
// 同花 == 手牌都是相同花色的
// 顺子 == 5 张手牌的等级连续
// 三张 == 三张手牌等级相同
// 两对 == 对子 + 对子
// 一对 == 2 张手牌等级相同
// 其他牌 == 非以上情况

// 从以上这张表格可以看出，但我们只要判断出一对、三张、顺子、同花这四种牌型，剩余的四种牌型在此基础上都可以在稍加条件甚至不加条件的情况下判断出来。比方说：四张 == (两对 && num_of_suit[i] == 4)；而两对 == (一对 && 一对)。这样提高自己写下的代码在之后编写过程中被反复利用的次数，或许能够简化代码，避免反复造轮子的窘迫和低效。

// 其次，是关于相同作用的代码的表达。这里我们可以直接对比一下我和示例同时想要表达 “连续” 这个概念来判断 “顺子” 时，是如何编写程序的。

// for (int i = 0; i < 8; i++) {
//   if (number_of_rank[i] == 1 && number_of_rank[i + 1] == 1 && number_of_rank[i + 2] == 1 && number_of_rank[i + 3] == 1 && number_of_rank[i + 4] == 1) {
//     condition += PASS;
//   }
// }

// 表达的很直白也很笨拙：现在有一个数组 number_of_rank，请遍历它，如果遇到了一个元素（i）和它之后的四个元素（i + 1, 2, 3, 4）都是 1，那就可以执行下面这个动作（condition += PASS）。解释很多余对吧？这样的编写缺点很明显 —— 当我想要确认 “连续” 的元素数量增大之后，这样（i + n）的编写方式会很吃力。所以不妨看看书上的示例是如何体面的解决了 “连续” 的确认。

// rank = 0;
// while (num_of_rank[rank] == 0) {
//   rank++;
// }
// for (; rank < NUM_RANK && num_of_rank[rank] > 0; rank++) {
//   num_consec++
// }
// if (num_consec == NUM_CARDS) {
//   straight = true;
//   return;
// }

// “连续” 的概念更加具体了，虽然不像我的代码一目了然：这里有一个数组 num_of_rank 请遍历它，直到碰见第一个非零的元素 —— 这是我们第一张手牌的等级。这张手牌或许会是 “连续” 的开始。因为等级最大到十三，在那之前如果碰到了某等级的牌数为零，那么 “连续” 的计数就应该停止了。接下来确认一下有几张手牌是连续排列的吧？是五张吗？是的话，这幅手牌就是 “顺子” 了。

// 让我喜欢这段代码的很大原因是通过观察 num_consec，你能够很直观的看到 “连续” 在一步步累计和变化。同时它也有很强的适应性，因为很多数值判断的时候都用到了文件开头的宏。当手牌上限发生变化，成为顺子的连续下限发生变化，改变宏的数值对它来说就足够在此运行了。

// 最后，我还可以说说的就是代码的美感问题了。示例中的代码给我的感觉是一块块的积木，合理的拼接将他们融为一体，产生了功能。我的代码看起来像是一块橡皮泥，是需要从头到尾一点一点的把它搓细，最后展现出它应有的功能。低效，黏腻，这就是它给我的感觉。希望我之后能有所改进吧。