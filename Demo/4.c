#include <stdio.h>  
  
void insert(int arr[], int n, int key, int pos) {  
    if (pos < 0) {  
        return;  
    }  
      
    arr[pos + 1] = arr[pos];  
    insert(arr, n, key, pos - 1);  
}  
  
void insertion_sort_recursive(int arr[], int n) {  
    if (n <= 1) {  
        return;  
    }  
      
    insertion_sort_recursive(arr, n - 1);  
      
    int key = arr[n - 1];  
    int j = n - 2;  
      
    // 寻找key的正确位置  
    while (j >= 0 && arr[j] > key) {  
        arr[j + 1] = arr[j];  
        j--;  
    }  
      
    arr[j + 1] = key;  
}  
  
void insertion_sort(int arr[], int n) {  
    for (int i = 1; i < n; i++) {  
        int key = arr[i];  
        int pos = i - 1;  
          
        // 递归调用insert函数来插入元素  
        insert(arr, n, key, pos);  
    }  
}  
  
int main() {  
    int arr[] = {12, 11, 13, 5, 6};  
    int n = sizeof(arr) / sizeof(arr[0]);  
      
    // 使用递归版本的直接插入排序  
    insertion_sort(arr, n);  
      
    // 输出排序后的数组  
    for (int i = 0; i < n; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
      
    return 0;  
}