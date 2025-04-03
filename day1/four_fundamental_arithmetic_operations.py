#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
  int a = 0;
  int b = 0;
  int c = 0;
  int result = 0;
  scanf("%d %d %d", &a, &b, &c);
  if(c == 0){
    printf("0으로 나눌 수 없다.");
  }
  result = (a + b) * c - (a - b) / c;
  printf("(%d + %d) * %d - (%d - %d) / %d = %d", a, b, c, a, b, c, result);
}
