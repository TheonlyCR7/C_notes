#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char str[3][10], temp[10];
    int i, j, k, n=3;
    printf("enter:\n");
    for(i=0; i<n; i++)
        gets(str[i]);   

    int m = 0, p = 0;
    while(m < 3){
        for(;p < 10; p ++)
            printf("%c ", str[m][p]);
        m ++;
        p = 0;
    }
}