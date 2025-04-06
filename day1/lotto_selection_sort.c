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
        int num = rand() % 45 + 1;
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
    }
    
    for (int i = 0; i < 6; i++) {
        min = i;
        for (int j = i + 1; j < 6; j++) {
            if (container[min] > container[j]) {
                min = j;
            }
        }
        temp = container[i];
        container[i] = container[min];
        container[min] = temp;

        printf("for문 %d\n", container[i]);
    }

    return 0;
}

