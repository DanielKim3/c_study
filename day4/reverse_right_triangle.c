#include <stdio.h>

int main()
{
    int num = 0;
    printf("정수를 입력하세요");
    scanf("%d", &num);
    if(num != 0 || num > 0) { 
        char star = '*';
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num - i; j++) {
                printf("%c", star);
            }
            printf("\n");
        }
    } else {
        printf("1 이상 숫자를 정수를 입력하세요");
    }
}
