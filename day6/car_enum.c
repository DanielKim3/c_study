#include <stdio.h>

// 하나의 공간을 서로 다른 두 변수가 같이 사용하는 것
// 구조체와 거의 비슷, struct 대신 union을 사용태로 사용할 수 있다.
#define TRUE 1
enum car {SEDAN = 1, SUV = 2, TRUCK = 3, VAN = 4};

void main()
{
    enum car c = SEDAN;
    int num;
    
    while (TRUE) {
        printf("SEDAN = 1, SUV = 2, TRUCK = 3, VAN = 4\n");
        printf("번호를 입력하세요 : ");
        scanf("%d", &num);
        c = num;
        
        switch (c) {
            case 1:
                printf("%d ", SEDAN);
                printf("SEDAN\n");
                break;
            case 2:
                printf("%d ", SUV);
                printf("SUV\n");
                break;
            case 3:
                printf("%d ", TRUCK);
                printf("TRUCK\n");
                break;
            case 4:
                printf("%d ", VAN);
                printf("VAN\n");
                break;
            default:
                printf("잘못된 입력입니다.\n");
                break;
        }
    }
}
