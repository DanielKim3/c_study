#include <stdio.h>

int main()
{
    int num = 0;
    printf("정수를 입력하세요");
    scanf("%d", &num);
    if(num != 0 || num > 0) { 
        int i = 0;
        while (i < num) {
            i++;
            printf("%d ", i);
        }
    } else {
        printf("1 이상 숫자를 정수를 입력하세요");
    }
}
