#include <stdio.h>
void main()
{
   float num;
   scanf("%f", &num); 
   float container = num;
   int s_num = num / 10;
   
   float bonus_a = container * 1.1;
   float bonus_b = container * 1.05;

   switch(s_num)
   {
       case 9:
            printf("A등급, 보너스 점수포함 (10%%) : %.2f 점", bonus_a);
            break;
       case 8:
            printf("B등급, 보너스 점수포함 (5%%) : %.2f 점", bonus_b);
            break;
        case 7:
            printf("C등급, 추가 보너스 없음");
            break;
        case 6:
            printf("D등급, 추가 보너스 없음");
            break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            printf("F등급, 추가 보너스 없음, 면담 예정");
            break;
        default:
            printf("잘못된 입력입니다!");
   }
}
