// 在此进行指针和数组的练习

#include <stdio.h>

#define COL 10
#define ROW 10
#define LAY 10

int main(void)
{
    int *pointer;
    int(*pointer_to_row)[COL]; // 指向一维整形数组的指针，数组列数为 COL
    int(*pointer_to_layer)[ROW][COL]; // 指向二维数组的指针，数组行数为 ROW，数组列数为 COL

    // 设立一个三维数组
    int arr[LAY][ROW][COL] = { {{0}} };

    // 将 pointer 指向 arr 的 (1，1，1)
    pointer = &arr[0][0][0]; // 因为 &arr[0][0][0] == &(*(arr[0][0] + 0))，所以亦可写作 pointer = arr[0][0];

    // 将 pointer_to_row 指向 arr 的第一层第一行
    pointer_to_row = &arr[0][0]; // 因为 &arr[0][0] == &(*(arr[0] + 0))，所以亦可写作 pointer_to_row = arr[0];

    // 将 pointer_to_layer 指向 arr 的第一层
    pointer_to_layer = &arr[0]; // 因为 &arr[0] == &(*(arr + 0))，所以亦可写作 pointer_to_layer = arr;

    // 使得第一层第三行元素都从 0 变为 1
    pointer = arr[0][1];
    for (; pointer < arr[0][2]; pointer++) { // 用行主序的思想来理解，即在到达下一行之前进行遍历。
        *pointer = 1;
    }

    // 使得第二层第五列元素都从 0 变为 1
    pointer_to_row = arr[1];
    for (; pointer_to_row < arr[1] + ROW; pointer_to_row++) {
        (*pointer_to_row)[4] = 2;
    }

    // 使得每一层中，坐标为 (8,4) 的元素为 1
    pointer_to_layer = arr;
    for (; pointer_to_layer < arr + LAY; pointer_to_layer++) {
        (*pointer_to_layer)[7][3] = 3; // *(((*pointer_to_layer)[7]) + 3) || *((*(*pointer_to_layer) + 7) + 3)
    }

    // 使得每一层中，坐标为 
    // (3, 2)(3, 3)
    // (4, 2)(4, 3) 
    // 的元素为 4
        pointer_to_layer = arr; // &arr[0]
    for (; pointer_to_layer < arr + LAY; pointer_to_layer++) { // 限制操作的层数的范围在下标 0 - (LAY-1) 之间
        pointer_to_row = ((*pointer_to_layer) + 2); // &arr[-][2]
        for (; pointer_to_row < ((*pointer_to_layer) + 4); pointer_to_row++) { // 限制操作的行数在下标 2 - 3 之间，即为行数 3 - 4 之间
            pointer = ((*pointer_to_row) + 1); // &arr[-][-][1]
            for (; pointer < ((*pointer_to_row) + 3); pointer++) { // 限制操作的列数在下标 1 - 2 之间，即为列数 2 - 3 之间
                (*pointer) = 4;
            }
        }
    }
    // 在以指针计数的循环中，每个低维的指针的数据都全部或部分来自上一维度的指针。

    // 打印数组
    for (int i = 0; i < LAY; i++) {
        printf("\n\n Layer %2d:", (i + 1));
        for (int j = 0; j < ROW; j++) {
            printf("\n\t Row %2d:", (j + 1));
            for (int k = 0; k < COL; k++) {
                printf("%4d", arr[i][j][k]);
            }
        }
    }

    getchar();
    return 0;
}

// 规律小结：
// 1. 声明一个指针，必须将指针所指变量类型的信息补充完整，尤其在和数组搭配时更是如此。
//      e.g. 声明一个指针指向三维数组的某一层时，要补充行列的信息。
//      推而广之，当指针需要指向一个 N 维度的数组时，在声明这个指针变量时，要补充好 N-1 个维度的信息，以描述这个 N 维的数组是什么样的
// 2. 当对指向更高维度的指针使用间接寻址符 * 时，此时对应的由该指针指向的地址应该就是最高维度的第一个单位的地址。换而言之，如果想要使用高维度的指针来锁定某个低维度的元素时需要补充相应的低维信息。
// 3. 根据需要进行的操作选择指针的类型。
//      如果仅需要对某行中的所有元素进行固定的操作，此时只需要零维的指针，指向行中的每个元素。
//      如果需要对某列中的所有元素进行固定操作，在行主序的 C 中，更恰当的说法应该是，“如果需要对多行中的某个固定位数的元素进行固定操作”，此时就需要可以依次指向不同行的一维的指针，并补充指针的长度信息。
//      如果需要对某层中的某些元素进行固定操作，此时则需要指向不同层的指针，指针变量类型中则需要补充低维度的信息（用于描述该层的行数列数）。