#include <stdio.h>

// 하나의 공간을 서로 다른 두 변수가 같이 사용하는 것
// 구조체와 거의 비슷, struct 대신 union을 사용태로 사용할 수 있다.
void main()
{
    union program {
        int intVal;
        float floatVal;
        char charVal;
    };
    
    union program u;
    u.intVal = 100;
    u.floatVal = 99.99;
    u.charVal = 'A';
    
    printf("%d %d\n", u.intVal, &u.intVal);
    printf("%f %d\n", u.floatVal, &u.floatVal);
    printf("%c %d\n", u.charVal, &u.charVal);
    printf("%c %d\n", u.intVal, &u.intVal);
}
