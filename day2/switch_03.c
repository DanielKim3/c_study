#include <stdio.h>

int main() {
    int temp;
    printf("현재 온도를 입력하세요: ");
    scanf("%d", &temp);
    int temp_cal = temp / 5;
    
    if (temp_cal >= 6) {
        temp_cal = 6;
    }
    
    switch (temp_cal) {
        case 6:
            printf("너무 더워요! 반팔과 반바지를 입으세요.\n");
            break;
        case 5:
            printf("따뜻한 날씨입니다! 가벼운 옷을 입으세요.\n");
            break;
        case 3:
        case 4:
            printf("선선한 날씨입니다! 가벼운 겉옷을 챙기세요.\n");
            break;
        case 1:
        case 2:
            printf("조금 쌀쌀합니다! 따뜻한 옷을 입으세요.\n");
            break;
        case 0:
            printf("매우 춥습니다! 두꺼운 외투를 꼭 입으세요.\n");
            break;
        default:
            printf("한파 경고! 패딩과 장갑, 모자를 착용하세요.\n");
            break;
    }
    return 0;
}
