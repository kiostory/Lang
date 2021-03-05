// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//*** 문제해결을 위한 사고순서 ***
//1. 주어진 진수의 문자숫자를 우선 10진수로 바꿈
//2. 바뀐 두 숫자를 더하기하여 바꿀 진수로 변환

char* solution(char* s1, char* s2, int p, int q) {
    int num1 = parse_decimal(s1, p);    // 전달받은 p진수의 문자숫자를 parse_decimal을 통해 10진수 숫자로 변환
    int num2 = parse_decimal(s2, p);    // 상동
    char* answer = convert_scale(num1 + num2, q);    //더하기 한 10진숫자를 원하는 진수로 변환하는 convert_scale 호출 
    return answer;
}

//1. 주어진 진수의 문자숫자를 우선 10진수로 바꿈
int parse_decimal(char* s, int p) {
    int num = 0;    // 리턴할 10진수 변수
    for (int i = strlen(s) - 1, mul = 1; i >= 0; i--, mul *= p)    //문자숫자의 오른쪽 끝부터 한자씩 10진수화, mul은 자리수별 p진수에 해당하는 10진수값을 계산하기 위한 값
        num += char_to_int(s[i]) * mul;    // 문자숫자를 문자별 10진수화해서 p진수의 자리값과 곱하여 10진수화
    return num;
}

//1. 주어진 진수의 문자숫자를 우선 10진수로 바꿈
//문자숫자를 숫자로 변환하기 위한 준비1 : 같은요소번호를 리턴할 생각인것 같음
int numbers_int[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
char* numbers_char = "0123456789";

const int char_to_int(char ch) {    //문자숫자 한자한자를 numbers_char 값들과 비교해서 같으면 그 요소순서에 해당하는 numbers_int요소를 반환
    for (int i = 0; i < 10; i++)
        if (ch == numbers_char[i])
            return numbers_int[i];
}




//2. 바뀐 두 숫자를 더하기하여 바꿀 진수로 변환 // !!!!!!!!!!!!!!!!!!!!!!!! 재귀함수..
char* convert_scale(int num, int q) {
    if (num == 0) return "";
    char* s2 = convert_scale(num / q, q);
    char* s = (char*)malloc(sizeof(char) * (strlen(s2) + 2));
    strcpy(s, s2);
    s[strlen(s2)] = int_to_char(num % q);
    s[strlen(s2) + 1] = 0;
    return s;
}


// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    char* s1 = "112001";
    char* s2 = "12010";
    int p = 3;
    int q = 8;
    char* ret = solution(s1, s2, p, q);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %s 입니다.\n", ret);
}