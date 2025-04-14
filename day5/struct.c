#include <stdio.h>
#define DEFAULT_NUM 35
#define DEFAULT_CHAR 'a'
#define TRUE 1

// 학생정보시스템

// 1. hong/30/M/soccer
// 2. kim/25/M/music
// 3. park/20/F/movie

// scanf( ) 학생 정보를 한 건씩 입력받기
// 입력받을 떄마다 누적된 정보를 출력하기
// 예외처리 하기
// 메인 함수는 10줄 미만으로 줄이기기
// *학생정보시스템의 struct의 최대는 1,000 세트로 설정함
// 배열 쓰지 말고 포인터 쓴다.
// 메인 함수는 10줄 미만으로 줄이기 (함수화 시키기)

void main()
{
   struct student_info {
        char *name;  
        int *age;        
        char *sex;   
        char *hobby;
    };
    int i, student_count = 0;
    struct student_info si[1000];

    // for (i = 0; i < 3; i++) {
    while(TRUE) {
        printf("[%d번째 학생 입력]\n", i + 1);
        printf("이름, 나이, 성별, 취미를 입력하시오: \n");
        int result = scanf("%s %d %s %s", si[i].name, si[i].age, si[i].sex, si[i].hobby);
        student_count++;
        // printf("\n 누적 학생 정보:\n");
        for (int j = 0; j < student_count; j++) {
            printf(" - [%d] 이름: %s | 나이: %d | 성별: %s | 취미: %s\n",
            j + 1, si[j].name, si[j].age, si[j].sex, si[j].hobby);
        }
    }
}
