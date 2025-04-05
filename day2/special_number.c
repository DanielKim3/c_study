#include <stdio.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    if(num < 0 || num > 999 || num == 0){
        printf("1이상 1000 이하 작성");
    } else {
        int a = num / 100;
        int b = (num - (a * 100)) / 10;
        int c = (num) % 10;
        int sum = a + b + c;
        if(num % 3 == 0 && num % 2 == 1){
            printf("특별한 숫자 입니다.");
        } else if(sum % 7 == 0) {
           printf("특별한 숫자 입니다.");
        } else if(a > c) {
           printf("특별한 숫자 입니다.");
        } else {
           printf("평범한 숫자 입니다.");
        }
    }
    return 0;
}
