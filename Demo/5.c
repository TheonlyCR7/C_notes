#include <stdio.h>

int main(){
    struct stu{
        float a;
        char b[5];
    }m;
    int i = sizeof(m);
    printf("%d", i);
    return 0;
}