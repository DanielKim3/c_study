// 중복이 없어야 함
// 오름차순
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int container[6];
  int container3[6];
  int min = 46;
  
 for(int i = 0; i < 6; i++){
    srand(time(NULL));
    int num = (int)(rand() % 45) + 1;
    sleep(1); // 1초
    container[i] = num;
  }
  
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 6; j++){
        int bools = 0;
        for(int k = 0; k < i; k++) {
            if(container[j] == container3[k]){
                bools = 1;
                break;
            }
        }
        if(container[j] < min && bools == 0){
            min = container[j];
        }
    }
    container3[i] = min;
    min = 46;
    printf("for문 %d\n", container3[i]);
  }
  return 0;
}
