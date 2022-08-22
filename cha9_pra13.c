// 本程序模拟了一种棋盘上的棋局，并计算了该棋局之下的得分
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define CHESS_NUM 8

// 至少要写明每行包含的列数
int evaluate_position(char[][CHESS_NUM + 1]);
void evaluation_check(char[][CHESS_NUM + 1]);

int main(void)
{
  // 这里防止字符串末尾没有 \0 导致的写入或读取异常 chess_board 每行多了一个元素来放置空字符
  char chess_board[CHESS_NUM][CHESS_NUM + 1] = { {'\0'} };
  int map_check[CHESS_NUM][CHESS_NUM] = { {0} };
  const char chessman[2][16] = {
    { 'K', 'Q', 'R', 'R', 'B', 'B', 'N', 'N', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
    { 'k', 'q', 'r', 'r', 'b', 'b', 'n', 'n', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' }
  };
  char picked_chessman;
  int existence[CHESS_NUM][CHESS_NUM] = { {0} };

  srand((unsigned)time(NULL));

  // 棋盘初始化
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      chess_board[i][j] = '*';
    }
  }
  // 生成随机棋盘
  // 挑选棋子
  for (int color = 0; color < 2; color++) {
    for (int role = 0; role < 16; role++) {
      picked_chessman = chessman[color][role];
      // 挑选棋盘坐标，放置棋子
      for (;;) {
        int row = rand() % CHESS_NUM;
        int col = rand() % CHESS_NUM;
        if (map_check[row][col] != 0) {
          continue;
        }
        else {
          // 当 map_check 相关元素为 0 时 说明该位置还没有放置棋子
          map_check[row][col] = 1;
          chess_board[row][col] = picked_chessman;
          break;
        }
      }
    }
  }

  // 棋子是否被吃掉了
  for (int i = 0; i < CHESS_NUM; i++) {
    for (int j = 0; j < CHESS_NUM; j++) {
      existence[i][j] = rand() % 2;
      if (existence[i][j] == 0) {
        chess_board[i][j] = '*';
      }
    }
  }

  // 打印棋盘
  for (int i = 0; i < CHESS_NUM; i++) {
    printf("\n\t");
    for (int j = 0; j < CHESS_NUM; j++) {
      // 默认右对齐
      printf("%3c", chess_board[i][j]);
    }
  }

  // 计算
  printf("\n\n\t Advantage: %d ", evaluate_position(chess_board));

  printf("\n");
  evaluation_check(chess_board);

  getchar();
  printf("\n\n");
  return 0;
}

int evaluate_position(char arr[][CHESS_NUM + 1])
{
  // 求和
  int white_sum = 0;
  int black_sum = 0;
  for (int j = 0; j < CHESS_NUM; j++) {
    for (int k = 0; k < CHESS_NUM; k++) {
      switch (arr[j][k]) {
      case 'K':
      case 'k': continue;
      case 'Q': white_sum += 9; break;
      case 'q': black_sum += 9; break;
      case 'R': white_sum += 5; break;
      case 'r': black_sum += 5; break;
      case 'B': white_sum += 3; break;
      case 'b': black_sum += 3; break;
      case 'N': white_sum += 3; break;
      case 'n': black_sum += 3; break;
      case 'P': white_sum += 1; break;
      case 'p': black_sum += 1; break;
      default: continue;
      }
    }
  }

  // 计算值
  int advantage = (white_sum - black_sum);

  return advantage;
}

// 这个函数用来显示棋盘上存活的黑子白子分别是什么 方便验算
void evaluation_check(char arr[][CHESS_NUM + 1])
{
  int chessman_number[2][6] = { {0} }; // K // Q // R // B // N // P 
  char chessmen[2][6] = {
    {'K','Q','R','B','N','P'},
    {'k','q','r','b','n','p'}
  };

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      switch (arr[i][j]) {
      case 'K': chessman_number[0][0] += 1; break;
      case 'k': chessman_number[1][0] += 1; break;
      case 'Q': chessman_number[0][1] += 1; break;
      case 'q': chessman_number[1][1] += 1; break;
      case 'R': chessman_number[0][2] += 1; break;
      case 'r': chessman_number[1][2] += 1; break;
      case 'B': chessman_number[0][3] += 1; break;
      case 'b': chessman_number[1][3] += 1; break;
      case 'N': chessman_number[0][4] += 1; break;
      case 'n': chessman_number[1][4] += 1; break;
      case 'P': chessman_number[0][5] += 1; break;
      case 'p': chessman_number[1][5] += 1; break;
      default: continue;
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      switch (chessman_number[i][j]) {
      case 0: continue;
      default:
        printf("\n\t %c: %d ", chessmen[i][j], chessman_number[i][j]);
      }
    }
  }
}