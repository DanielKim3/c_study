#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
  int num = 0;
  scanf("%d", &num);
  if(num <= 999){
    int a = num / 100;
    int b = (num - (a * 100)) / 10;
    int c = (num) % 10;
  
    int result = a + b + c;
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", result);
  } else {
    printf("백의 자리수를 넘겼습니다.\n");
  }
}
