#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num[6];
    int i, j, a;
   
    srand(time(NULL));
   
    for(i = 0; i < 6; i++) {
        int newNum = (int)(rand() % 45) + 1;
       
        for(j = 0; j < i; j++) {
            if(num[j] == newNum) {
                i--;
                break;
            }
        }
        if(i == j) {
            num[i] = newNum;
        }
    }
    
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void quickSort(int Hoare[], int low, int high) { //인덱스 처음인 0이 low, 인덱스 마지막 high
        if(low < high) {
            int pivot = Hoare[low]; //호어정렬은 피벗이 가장 왼쪽이다
            int left = low -1; //1을 먼저 더해가며 비교할려고 해서 이렇게 설정
            int right = high + 1; //1을 먼저 뺴가며 비교할려고 해서 이렇게 설정
            
            while (1) { //1은 True를 의미하며, break 되기전까지 무한반복
                
                for(; Hoare[++left] < pivot; ); //왼쪽부터 피벗보다 크거나 같은 값 나올때까지 
                
                for(; Hoare[--right] > pivot; ); //오른쪽부터 피벗보다 작거나 같은 값 나올때까지
                
                if(left >= right) //교차되면 반복 종료
                    break;
                swap(&Hoare[left], &Hoare[right]); //왼쪽이 오른쪽 보다 같거나 크면 값을 교환   
            }
            
            quickSort(Hoare, low, right); //피벗보다 작거나 같은 구간, right가 피벗임(호어)
            quickSort(Hoare, right + 1, high); //피벗 보다 큰 구간
        }
    }
   
    quickSort(num, 0, 5); //함수를 불러옴, num == &num[0]이라서 그냥 &num이라 쓰면 안되고
    //굳이 &을 쓴다면 quickSort(&num[0], 0, 5); 맞음음
   
    for(i = 0; i < 6; i++) { //quickSort를 위에 써야 호어정렬이 된다
        printf("%d ", num[i]);
    }
    printf("\n");
   
    return 0;
   
}
