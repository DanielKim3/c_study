#include <stdio.h>
#include <string.h>

#define MAX 1000
#define TRUE 1
#define FALSE 0

union detail {
    char hobby[100];
    char etc[100];
};

struct groups {
    int num;
    char name[100];
    int age;
    char gender;
    
    union detail d;
    int type; //1. hobby, 2. etc
    
};

// 한 사람 정보 출력
void printGroup(struct groups g) { //구조체 한개의 변수를 선언
    printf("%d/%s/%d/%c\n", g.num, g.name, g.age, g.gender);
    
    if (g.type == 1) {
        printf("%s (취미)\n", g.d.hobby);
    } else if (g.type == 2) {
        printf("%s (기타)\n", g.d.etc);
    } else {
        printf("정보 없음\n");
    }
}

// 전체 정보 출력
void printAll(struct groups g[], int count) {
    for (int i = 0; i < count; i++) {
        printGroup(g[i]);
    }
}

// 사용자로부터 한 명 정보 입력
void inputGroup(struct groups *g, int id) {  // g는 struct groups 구조체 하나를 가리키는 포인터(주소값)
    (*g).num = id; //포인터 g가 가리키는 구조체의 a값에 id값을 대입한다
    //포인터 변수 g가 가리키는 구조체 안의 변수 a이다 라고 생각하고, g->a 라고 쓰면 편하다	
    //구조체 하나에 해당하는 포인터이므로 *g라고 씀 

    //아래initData는 g를 포인터처럼 썼는데, 값을 수정해야되는 함수라, 포인터를 써야함
    //근데 이게 배열이라 g자체가 배열이름으로 포인터처럼 쓸수있어서 *을 안쓴거임  

    // 번호 할당, 읽기만 하는게 아닌 수정까지 하는것이므로 포인터사용해야 수정가능
    //다른 함수를 통해 값을 수정해야하는 경우라면 주소와 포인터를 활용해야해야!
    //다른 함수를 통해 읽기만 하는거라면 그냥 해도 됨

    printf("이름을 입력하시오: ");
    scanf("%s", (*g).name); // 이름 입력

    int trueAge;
    while (TRUE) {
        printf("나이를 입력하시오: ");
        trueAge = scanf("%d", &(*g).age); //입력값의 갯수를 반환, 따라서 1 또는 0

        if (trueAge == TRUE && (*g).age > 0 && (*g).age < 100) {
            break; // 입력 성공, 루프 탈출
        } else {
            printf("1 ~ 99 사이의 숫자만 입력하세요!\n");

            // 입력 버퍼 비우기
            while (getchar() != '\n');
        }
    }
    
    int trueGender;
    while (TRUE) {
        printf("성별을 입력하시오 (M 또는 F): ");
        trueGender = scanf(" %c", &(*g).gender); // 성별 입력 (앞에 공백!) 
        //안그러면 엔터쳤을때 개행문자가 여기에 입력됨
        
        if (trueGender == TRUE && ((*g).gender == 'M' || (*g).gender == 'F')) {
            break; //M과 F 조건문은 묶어줘야한다, 안그러면, F만 만족해도 break가 되어버림
        } else {
            printf("M 또는 F만 입력하세요!\n");
            while (getchar() != '\n');
        }
    }

    while (TRUE) {
        printf("1. 취미 입력\n2. 기타 정보 입력\n선택하세요 (1 or 2): ");
        int option;
        scanf("%d", &option); //내가 친 값이 옵션의 값이 되어 if조건문으로 간다
        
        if (option == 1) {
            printf("취미를 입력하시오: ");
            scanf("%s", g->d.hobby);
            g->type = 1;
            break;
        } else if (option == 2) {
            printf("기타 정보를 입력하시오: ");
            scanf("%s", g->d.etc);
            g->type = 2;
            break;
        } else {
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
            while (getchar() != '\n'); //안 넣으면 문자입력시 반복오류남
        }
    }
}    
// 초기 데이터 세팅 함수
void initData(struct groups g[], int *count) { 
    //void func(struct groups g[]) 은 곧 void func(struct groups *g) 이므로, 포인터같은거임
    //struct groups *g = &g[0]; 으로 구조체 배열의 첫 번째 요소의 주소를 g라는 포인터에 저장

    char* names[] = {"hong", "kim", "park"}; //포인터 배열의 크기를 대입연산자의 뒤에 쓴걸로 알아서 계산이 가능, [] 숫자생략해도 됨
    int ages[] = {30, 25, 20};
    char genders[] = {'M', 'M', 'F'};
    int types[] = {1, 2, 1};    
    char* hobbies[] = {"soccer", "", "movie"};
    char* etcs[] = {"", "music", ""};

    for (int i = 0; i < 3; i++) {
        g[i].num = i + 1;
        strcpy(g[i].name, names[i]); //strcpy 함수 //g[i].b에 names[i]를 넣는다는 뜻 //문자열에만 씀
        //g[i].b = names[i]; 가 안 되는 이유
        //g[i].b는 char 배열 (char[100])
        //names[i]는 문자열 리터럴을 가리키는 포인터인  char *
        //char b[100];          // 배열 (공간을 직접 가짐)
        //char *p = "hong";     // 포인터 (주소만 가지고 있음)
        
        //g[i].b라는 char[100] 배열에 names[i]라는 포인터 배열에 저장된 문자열을 복사한다는 의미이다
        //names[i]는 문자열의 시작 주소이고
        //strcpy는 그 시작 주소부터 '\0'이 나올 때까지 문자들을 한 글자씩 차례로 복사하는 함수이다. printf도 그렇게 출력했다
        g[i].age = ages[i];
        g[i].gender = genders[i];
        g[i].type = types[i];

        if (g[i].type == 1) {
            strcpy(g[i].d.hobby, hobbies[i]);
        } else {
            strcpy(g[i].d.etc, etcs[i]);
        }
    }

    *count = 3;
}

void runProgram() {
    struct groups g[MAX]; //구조체 MAX인 1000개 분량의 메모리를 확보했다는 의미
    int count;

    initData(g, &count);    // 초기값 설정, initData를 거치면서 count의 값은 3으로 초기화 된다! 
    //g는 구조체 배열의 이름으로써 포인터같은 역할
    printAll(g, count);     // 초기값 출력

    while (TRUE) {          // 무한 입력 루프, MAX값인 1000까지만 가능, TRUE대신 그냥 1써도 됨
        printf("\n %d번 정보 입력 \n", count + 1);
        inputGroup(&g[count], count + 1);
        count++;
        printf("\n[전체 정보 출력]\n");
        printAll(g, count); //구조체 배열 g의 시작주소인 g = &g[0];을 printAll에 대입
    }
}

int main() {
    runProgram();
    return 0;
}
