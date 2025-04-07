#include <stdio.h>
// 이중 for문 활용
// 202001부터 202504까지 출력
// 202302 ~ 202305 스킵
int year = 202;
int month;
int main() {
   for (int i = 0; i < 6; i++) {
        for(int j = 1; j < 13; j++) {
            if (i == 3 && j > 1 && j < 6) {
                continue;
            } 
            if(j < 10) {
                printf("%d%d년%d%d월 \n", year, i, month, j);
            } else {
                printf("%d%d년%d월 \n", year, i, j);
            }
            if(i == 5 && j == 4) {
                break;
            }
        }
   }
}
