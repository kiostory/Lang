// You may use include as below.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// #include <math.h>    //kioeom

long long solution(long long num) {
    // Write code here.
    long long answer = 0;
/*
    long long idx=0;
    long long a=num+1;

    while(a/10 != 0){
        if(a%10 == 0) answer+=(long long)pow(10.0,idx);
        else answer+=(a%10)*(long long)pow(10.0,idx);
        ++idx;
        a/=10.0;
            printf("answer=%d\n",answer);
            printf("--------------\n");
        
    }
*/
    answer = ++num;
	long long digit = 1;
	while (answer / digit % 10 == 0) {
		answer += digit;
		digit *= 10;
	}

    return answer;
}

// The following is main function to output testcase.
int main() {
    long long num = 9949999;
    long long ret = solution(num);

    // Press Run button to receive output. 
    printf("Solution: return value of the function is %lld .\n", ret);
}