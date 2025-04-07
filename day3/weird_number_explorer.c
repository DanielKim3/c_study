#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contains(int num) {
    char str[20];
    sprintf(str, "%d", num); // 숫자를 문자열로 변환
    return strchr(str, '7') != NULL;
}

int main()
{
    int m, n;
    printf("정수 입력 (두 개):\n");
    scanf("%d %d", &m, &n);
    printf("===============\n");

    if (m > 0 && n > 0) {
        for (int i = m; i <= n; i++) {
            if (i % 7 == 0 || contains(i)) {
                continue;
            } else if (i % 5 == 0) {
                printf("%d은 5의 배수 입니다.\n", i);
                break;
            } else {
                printf("%d\n", i);
            }
        }
    } else {
        printf("1 이상 작성하시오.\n");
    }
    printf("\n");

    return 0;
}
