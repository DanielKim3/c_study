#include <stdio.h>

union program {
    int intVal;
    float floatVal;
    char charVal[50];
};

void main(void)
{
    union program u;

    printf("정수를 입력하세요: ");
    scanf("%d", &u.intVal);
    printf("int 값: %d, 주소: %p\n", u.intVal, (void *)&u.intVal);
    printf("실수를 입력하세요: ");
    scanf("%f", &u.floatVal);
    printf("int 값: %d, 주소: %p\n", u.intVal, (void *)&u.intVal);
    printf("float 값: %f, 주소: %p\n", u.floatVal, (void *)&u.floatVal);
    printf("문자열을 입력하세요: ");
    scanf("%s", u.charVal);
    printf("int 값: %d, 주소: %p\n", u.intVal, (void *)&u.intVal);
    printf("float 값: %f, 주소: %p\n", u.floatVal, (void *)&u.floatVal);
    printf("char 값: %s, 주소: %p\n", u.charVal, (void *)u.charVal);
}
