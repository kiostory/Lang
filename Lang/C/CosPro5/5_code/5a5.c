// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int enemies[], int enemies_len, int armies[], int armies_len) {
    // 여기에 코드를 작성해주세요.
    int answer = 0;

    for (int i=0;i<armies_len;i++){
        bool x=false;
        for (int j=0;j<enemies_len;j++){
            if((enemies[j] != 0 ) && (armies[i] = enemies[j])){   //같은 공격력일경우가 있는지 먼저보고
                answer++;
                enemies[j]=0;
                x=true;
            }
            if (x) break;
        }

        if (x == false){
            for (int j=0;j<enemies_len;j++){

                if((enemies[j] != 0 ) && (armies[i] > enemies[j])){ //없으면 공격력이 낮은게 있는지 보고
                    answer++;
                    enemies[j]=0;
                    x=true;
                }
                if (x) break;
            }
        }

    }
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int enemies1[] = { 1, 4, 3 };
	int enemies_len1 = 3;
	int armies1[] = { 1, 3};
    int armies_len1 = 2;
    int ret1 = solution(enemies1, enemies_len1, armies1, armies_len1);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);

    int enemies2[] = { 1, 1, 1 };
    int enemies_len2 = 3;
    int armies2[] = { 1, 2, 3, 4 };
    int armies_len2 = 4;
    int ret2 = solution(enemies2, enemies_len2, armies2, armies_len2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);
}