#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int container[6];
    int min, temp;
    srand(time(NULL));
    
    printf("정렬 전: ");
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
    
    for (int i = 1; i < 6; i++) {
       int key = container[i];
       int j;
      for (j = i - 1; j >= 0; j--) {
        if (container[j] > key) {
            container[j + 1] = container[j];
        } else {
            break;
        }
    }
       container[j + 1] = key;
    }
  
    printf("\n");
    printf("정렬 후: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", container[i]);
    }
}
