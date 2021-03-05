#1차4번
#pragma warning (disable : 4996)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long num) {
	num++;
	long long digit = 1;
	while (num / digit % 10 == 0) {
		num += digit;
		digit *= 10;
	}
	return num;
}

// The following is main function to output testcase.
int main() {
	long long num = 9949999;
	long long ret = solution(num);

	// Press Run button to receive output. 
	printf("Solution: return value of the function is %lld .\n", ret);  //%lld는 vs용. 보통은 I64d or I64u
}