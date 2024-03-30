#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
    #define MAX_STRING_LENGTH 100 // 假定字符串最大长度为100  
#define FILENAME "sorted_strings.txt" // 输出文件名  
  
// 字符串比较函数，用于qsort  
int compare_strings(const void *a, const void *b) {  
    return strcmp(*(char **)a, *(char **)b);  
}  
  
int main() {  
    char **strings = NULL; // 指向字符串数组的指针  
    int num_strings = 0;   // 字符串的数量  
    int capacity = 0;      // 当前分配的数组容量  
    char input[MAX_STRING_LENGTH]; // 用于读取输入的缓冲区  
  
    printf("Enter strings (empty line to stop):\n");  
  
    // 不断读取字符串，直到用户输入空行  
    while (fgets(input, sizeof(input), stdin)) {  
        // 移除换行符  
        size_t len = strlen(input);  
        if (len > 0 && input[len - 1] == '\n') {  
            input[--len] = '\0';  
        }  

        // 如果用户输入了空行，则停止读取  
        if (len == 0) {  
            break;  
        }  

        // 分配内存并复制字符串  
        strings[num_strings] = malloc(len + 1);  
        if (!strings[num_strings]) {  
            perror("malloc failed");  
            // 释放已分配的字符串和数组  
            for (int i = 0; i < num_strings; ++i) {  
                free(strings[i]);  
            }  
            free(strings);  
            exit(EXIT_FAILURE);  
        }  
        strcpy(strings[num_strings], input);  
        num_strings++;  
    }  

    // 使用qsort对字符串进行排序  
    qsort(strings, num_strings, sizeof(char *), compare_strings);  
  
    // 将排序后的字符串写入文件  
    FILE *file = fopen(FILENAME, "w");
    if (!file) {  
        perror("fopen failed");  
        // 释放已分配的字符串和数组  
        for (int i = 0; i < num_strings; ++i) {  
            free(strings[i]);  
        }  
        free(strings);  
        exit(EXIT_FAILURE);  
    }  
  
    for (int i = 0; i < num_strings; ++i) {  
        fprintf(file, "%s\n", strings[i]);  
        free(strings[i]); // 释放每个字符串的内存  
    }  
  
    fclose(file);  
    free(strings); // 释放字符串数组的内存  
  
    printf("Sorted strings have been saved to %s\n", FILENAME);  
  
    return 0;  
}