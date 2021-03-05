//5차6
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numbers_int[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
char* numbers_char = "0123456789";

const int char_to_int(char ch) {
    for (int i = 0; i < 10; i++)
        if (ch == numbers_char[i])
            return numbers_int[i];
}

const char int_to_char(int val) {
    for (int i = 0; i < 10; i++)
        if (val == numbers_int[i])
            return numbers_char[i];
}

char* convert_scale(int num, int q) {
    if (num == 0) return "";
    char* s2 = convert_scale(num / q, q);
    char* s = (char*)malloc(sizeof(char) * (strlen(s2) + 2));
    strcpy(s, s2);
    s[strlen(s2)] = int_to_char(num % q);
    s[strlen(s2) + 1] = 0;
    return s;
}

int parse_decimal(char* s, int p) {
    int num = 0;
    for (int i = strlen(s) - 1, mul = 1; i >= 0; i--, mul *= p)
        num += char_to_int(s[i]) * mul;
    return num;
}

char* solution(char* s1, char* s2, int p, int q) {
    int num1 = parse_decimal(s1, p);
    int num2 = parse_decimal(s2, p);
    char* answer = convert_scale(num1 + num2, q);
    return answer;
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