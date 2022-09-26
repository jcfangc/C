// 修改第 8 章的编程题 16，使其包含下列函数：
// void read word(int counts [26]);
// bool equal_array (int counts1 [26]，int counts2 [26]);
// main 函数将调用 read_ word 两次，每次用于读取用户输入的一个单词。读取单词时，read_word 用 单词中的字母更新 counts 数组，详见原题的描述。（main 将声 明两个数组，每个数组用于一个单词。这些数组用于跟踪单词中每个字母出现的次数。）接下来，main 函数调用 equal_array 函数， 以前面提到的两个数组作为参数。如果两个数组中的元素相同（表明这两个单词是变位词），equal_array 返回 true，否则返回 false。


// 第 8 章编程题 16：
// 编程测试两个单词是否为变位词（相同字母的重新排列）

// Enter first word: smartest
// Enter second word: mattress
// The words are anagrams.

// Enter first word: dumbest 
// Enter second word: stumble 
// The words are not anagrams.

// 用一个循环逐个字符地读取第一个单词， 用一个 26 元的整数数组记录每个字母的出现次数。(例如，读取单词 smartest 之后，数组包含的值为 10001000000100000122000000，表明 smartest 包含一个 a、一个 e、一个 m、一个 r、两个 s 和两个 t。）用另一个循环读取第二个单词，这次每读取一个字母就把相应数组元素的值减 1。两个循环都应该忽略不是字母的那些字符，并且不区分大小写。第二个单词读取完毕后，再用一个循环来检查数组元素是否为全 0。如果是全 0，那么这两个单词就是变位词。提示：可以使用 <ctype.h> 中的函数，如 isalpha 和 telower。


#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void read_word(int[]);
_Bool equal_array(int[], int[]);

int main(void)
{
    int word_1[26] = { 0 };
    int word_2[26] = { 0 };

    printf("\n\t Enter word 1: ");
    read_word(word_1);

    printf("\n\t Enter word 2: ");
    read_word(word_2);

    if (equal_array(word_1, word_2)) {
        printf("\n\t They are anagrams. ");
    }
    else {
        printf("\n\t They are not anagrams. ");
    }

    getchar();
    printf("\n\n");
    return 0;
}

void read_word(int counts[26])
{
    char alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    char ch;

    while ((ch = getchar()) != '\n') {
        for (int i = 0; i < 26; i++) {
            if (toupper(ch) == alphabet[i]) {
                counts[i] += 1;
                break;
            }
        }
    }
}

_Bool equal_array(int counts1[26], int counts2[26])
{
    for (int i = 0; i < 26; i++) {
        if (counts1[i] != counts2[i]) {
            return false;
        }
    }
    return true;
}