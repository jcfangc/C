// 这个程序可以检验连个单词是不是换位词 即字母和字母数量都相同的单词
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    
    int alphabet_credit[26] = { 0 };
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    char ch;

    printf("\n\t Enter the first word: ");

    // 录入单词直至遇到换行符 同时把每个字母相应增加 1 积分
    while ((ch = getchar()) != '\n') {
        for (int i = 0; i < 26; i++) {
            if (tolower(ch) == alphabet[i]) {
                alphabet_credit[i] += 1;
            }
        }
    }

    printf("\n\t Enter the second word: ");

    // 录入单词直至遇到换行符 同时把每个字母相应减少 1 积分
    while ((ch = getchar()) != '\n') {
        for (int i = 0; i < 26; i++) {
            if (tolower(ch) == alphabet[i]) {
                alphabet_credit[i] -= 1;
            }
        }
    }

    // 检查积分表 如果存在任何字母的积分不能为零，说明在两个单词中该字母出现的次数不同，则不是换位词
    for (int i = 0; i < 26; i++) {
        if (alphabet_credit[i] != 0) {
            printf("\n\t The words are NOT anagrams.");
            getchar();
            printf("\n\n");
            return 0;
        }
    }

    printf("\n\t The words are anagrams.");
    getchar();
    printf("\n\n");
    return 0;
};