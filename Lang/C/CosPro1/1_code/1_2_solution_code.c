#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* func_a(char* str, int len){
    char* padZero = (char*)malloc(sizeof(char)*(len+1));
    for(int i = 0; i < len+1; ++i)
        padZero[i] = 0;  // '\0'의 ASC코드가 0. 동일한 효과!!
    int padSize = len - strlen(str);    // 보충할 자리수
    for(int i = 0; i < padSize; ++i)
        padZero[i] = '0';  //문자0! 숫자아님. 체크 
    strcat(padZero, str);  //이후 위치서부터 str값 입력
    return padZero;
}
int uMax(int a, int b){
    return a > b ? a : b;
}
int solution(char* binaryA, char* binaryB) {
    int max_length = uMax(strlen(binaryA), strlen(binaryB));
    if(max_length > strlen(binaryA))
        binaryA = func_a(binaryA, max_length);
    if(max_length > strlen(binaryB))
        binaryB = func_a(binaryB, max_length);
    
    int hamming_distance = 0;  //카운트 초기화
    for(int i = 0; i < max_length; ++i)
        if(binaryA[i] != binaryB[i])
            hamming_distance += 1;
    return hamming_distance;
}

// The following is main function to output testcase.
int main() {
    char* binaryA = "10010";
    char* binaryB = "110";
    int ret = solution(binaryA, binaryB);

    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret);
}