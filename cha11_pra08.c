// 编写下列函数：
// int* find_largest(int a[], int n);
// 当传入长度为 n 的数组 a 时，函数将返回指向数组最大元素的指针。

int *find_largest(int num_array[], int length_of_array)
{
    // 这个变量的地址最终会被返回，为了防止返回没有意义的地址，我们在这里给该变量设定静态的内存。
    static int biggest;
    
    // 将数列按照从小到大顺序排序
    // 可以将 pass 理解为包括当前正在排列的，已经排列好了的元素。
    // 鉴于下面的注释所提及的效果，最外层循环只需要执行一次就可以排列出数组中最大的元素于数组末端。
    // 如果需要将数组完整排序，我们只需要将循环条件从 < 2 改为 < length_of_array 即可。
    for (int pass = 1; pass < 2; pass++) {
        for (int index = 0; index < length_of_array - pass; index++) {
            // 因为较大的数在遇到较小的数时会被往后移动一位，而下一次循环的下标恰好比上一次的下标多一，则造成了较大的数在遇到比自己更大的数之前会一直往数组末尾移动的效果。
            // 这也同时意味着，最大数在一次遍历下标的循环后就会出现在数组的最末尾的位置。下次遍历下标后，次最大的元素会被排列在数组的倒数第二位（由于 length_of_array - pass 的设定）。
            int temp = num_array[index];
            if (num_array[index] > num_array[index + 1]) {
                num_array[index] = num_array[index + 1];
                num_array[index + 1] = temp;
            }
        }
    }

    biggest = num_array[length_of_array - 1];

    return &biggest;
}

// 这里我们直接借鉴了本章练习题六中，寻找最大和次最大的两个数的函数。
// 感兴趣的同学可以尝试使用其他的算法进行比较或者排列。