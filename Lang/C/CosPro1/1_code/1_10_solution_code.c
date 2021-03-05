#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int uMax(int a, int b){
    return a < b ? b : a;
}
int uMin(int a, int b){
    return a < b ? a : b;
}
int solution(int prices[], size_t prices_len) {
    int inf = 1000000001;
    int mn = inf;
    int ans = -inf;
    for(int i = 0; i < prices_len; i++){
        ans = uMax(ans, prices[i] - mn);
        mn = uMin(mn, prices[i]);
    }
    return ans;
}
// The following is main function to output testcase. The main function is correct and you shall correct solution function.
int main() {
    int prices1[3] = { 1, 2, 3 };
    int prices_len1 = 3;
    int ret1 = solution(prices1, prices_len1);

    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret1);

    int prices2[2] = { 3, 1 };
    int prices_len2 = 2;
    int ret2 = solution(prices2, prices_len2);

    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret2);
}