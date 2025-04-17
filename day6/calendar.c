#include <stdio.h>
#include <time.h>

enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
enum day {sun, mon, tue, wed, thu, fri, sat};

enum month m;
enum day d;

int year;
int realMonth;
int futureDate;
int startDay;
int totalYearDate;

int getMonthEndDate(int year, int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) {
        return 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if (month == 2) {
        if (year % 4 == 0) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return -1; // 잘못된 월
    }
}

void inputDate() {

    while(1) {
        printf("year을 입력하시오.\n");

        if (scanf("%d", &year) == 1 && (year >= 2025 && year <= 2099)) {
            break;
        } else {
            printf("잘못된 입력값입니다. 2025부터 이후만 가능합니다.\n");
            while (getchar() != '\n');
        }
    }
    
    while(1) {
        printf("month를 입력하시오.\n");

        if (scanf("%d", &realMonth) == 1 && (realMonth >= 1 && realMonth <= 12)) {
            break;
        } else {
            printf("잘못된 입력값입니다. 1부터 12까지 정수만 입력해주세요.\n");
            while (getchar() != '\n');
        }
    }
    
    int dayInput; 
    int monthInput; 
    int yearInput;
    
    while (1) {
        printf("원하는 날짜를 입력하시오. (예: 20251215)\n");
        if (scanf("%d", &futureDate) == 1) {
            yearInput = futureDate / 10000; //연도 필터링
            monthInput = (futureDate / 100) % 100; //월 필터링
            dayInput = futureDate % 100; //일 필터링

            int endDate = getMonthEndDate(yearInput, monthInput);

            if (yearInput >= 2025 && yearInput <= 2099 &&
                monthInput >= 1 && monthInput <= 12 &&
                dayInput >= 1 && dayInput <= endDate) {
                break;
            }
        }
        printf("잘못된 형식입니다. 다시 입력해주세요.\n");
        while (getchar() != '\n');
    }
    
    m = realMonth - 1;
}

int getTotalDays(int year, int month, int day) { //day는 날짜 일수
    int totalDays = 0;
    for (int y = 2025; y < year; y++) {
        if (y % 4 == 0) {
            totalDays += 366;
        } else {
            totalDays += 365;
        }
    }

    for (int m = 1; m < month; m++) {
        totalDays += getMonthEndDate(year, m);
    }

    totalDays += day - 1;
    return totalDays; //totalDays는 계속 더해 누적합계의 일 수를 구함
}

void printYear(int year, int realMonth) {
    printf("%d\n", 100 * (year) + realMonth);
}    

void printCalHeader() {
    printf("Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");
}

void calculateStartDay(int year, int realMonth) {
    int yearDate = 0; //각 해의 총 날짜
    totalYearDate = 0; //전체 해들의 총 날짜

    for (int i = 2025; i <= year; i++) {
        yearDate = 0;
        if (i != year) {
            if (i % 4 == 0) {
                yearDate = 366;
            } else {
                yearDate = 365;
            }
        } else {
            for (int j = 1; j < realMonth; j++) {
                yearDate += getMonthEndDate(year, j);
            }
        }
        totalYearDate += yearDate;
    }

    startDay = (3 + totalYearDate) % 7;
} 

void printDateNumber(int year, int realMonth, int startDay) {
    char *blank = "      ";
    int endDate = getMonthEndDate(year, realMonth);
    
    int blankCount = startDay;
    
    while (blankCount > 0) {
        printf("%s", blank);
        
        blankCount--;
    }
    
    for (int i = 1; i <= endDate; i++) {
        printf("%2d    ", i);
        
        if ((startDay + i) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

int calculateDday(int futureDate) {
    // 현재 날짜 자동으로 계산
    time_t now = time(NULL); // 현재 시간을 초 단위로 반환
    //time_t 변수명 = time(NULL) 쓰면 초 단위 정수값을 얻을 수 있음
    //time_t는 현재 시간을 초 단위로 저장할수있는 타입
    struct tm *t = localtime(&now); // `now`의 값을 localtime으로 변환하여 `struct tm` 형태로 받음
    //struct tm 구조체의 포인터 t를 선언, localtime 함수가 반환한 주소값을 포인터 t에 저장
    //localtime(&now)는 time_t 타입의 값을 받아 struct tm 구조체 형태로 변환
    int currentDate = (t->tm_year + 1900) * 10000 + (t->tm_mon + 1) * 100 + t->tm_mday;
    //t->tm_year: tm_year는 1900년을 기준으로 한 연도를 저장 // 2025년이면 tm_year 값은 125 
    //t->tm_mon: tm_mon은 0부터 11까지의 월의 값 // 1을 더하면 실제 월
    //t->tm_mday: 일
    
    ////struct tm 구조체의 필드////

    //tm_year: 연도 (1900년 기준)
    //tm_mon: 월 (0부터 11까지, 0 = 1월)
    //tm_mday: 일 (1부터 31까지)
    //tm_hour: 시 (0부터 23까지)
    //tm_min: 분 (0부터 59까지)
    //tm_sec: 초 (0부터 59까지)
    //tm_wday: 요일 (0 = 일요일, 1 = 월요일, ..., 6 = 토요일)
    //tm_yday: 연도의 몇 번째 날인지 (0부터 시작)
    //tm_isdst: 여름 시간 여부 (1이면 여름 시간, 0이면 표준 시간)

    int fYear = futureDate / 10000;
    int fMonth = (futureDate / 100) % 100;
    int fDay = futureDate % 100;

    int cYear = currentDate / 10000;
    int cMonth = (currentDate / 100) % 100;
    int cDay = currentDate % 100;

    // 미래 날짜와 현재 날짜를 기준으로 총 일 수 계산
    int futureTotal = getTotalDays(fYear, fMonth, fDay);
    int currentTotal = getTotalDays(cYear, cMonth, cDay);

    int dday = futureTotal - currentTotal;
    printf("D-day는 %d일 남았습니다.\n", dday);
    return dday;
}

int main() {
    inputDate();
    printYear(year, realMonth); //여기서 year은 내가 입력한 해, realMonth는 내가 입력한 달
    printCalHeader();
    calculateStartDay(year, realMonth);
    printDateNumber(year, realMonth, startDay); //함수에서 계산된 해당 달의 시작 요일
    calculateDday(futureDate); //내가 입력한 날짜
    
    return 0;
}
