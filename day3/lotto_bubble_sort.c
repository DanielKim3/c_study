// 중복이 없어야 함
// 오름차순
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int container[6];
    int min, temp;
    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        int num;
        int copy = 1;

        while (copy) {
            copy = 0;
            num = rand() % 45 + 1;
            
            for (int j = 0; j < i; j++) {
                if (container[j] == num) {
                    copy = 1;
                    break;
                }
            }
        }
        container[i] = num;
        printf("%d ", container[i]);
    }
    printf("\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5 - i; j++) {
            if (container[j] > container[j + 1]) {
                temp = container[j];
                container[j] = container[j + 1];
                container[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < 6; i++) {
        printf("for문 %d\n", container[i]);
    }
}
