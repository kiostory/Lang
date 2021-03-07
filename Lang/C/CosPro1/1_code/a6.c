// You may use include as below.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(char* pos) {
    // Write code here.
    int answer = 8;

    if (pos[0] == 'A' || pos[0] == 'H') answer-=4;
    else if (pos[0] == 'B' || pos[0] == 'G') answer-=2;

    if (pos[1] == '1' || pos[0] == '8') answer-=4;
    else if (pos[1] == '2' || pos[1] == '7') answer-=2;

    if ((pos[0] == 'A' || pos[0] == 'H') && (pos[1] == '1' || pos[1] == '8'))  answer=2;
    if ((pos[0] == 'B' || pos[0] == 'G') && (pos[1] == '2' || pos[1] == '7'))  answer=4;
    
    if ((pos[0] == 'A' || pos[0] == 'H') && (pos[1] == '2' || pos[1] == '7'))  answer=3;
    if ((pos[0] == 'B' || pos[0] == 'G') && (pos[1] == '1' || pos[1] == '8'))  answer=3;
    

    return answer;
}

// The following is main function to output testcase.
int main() {
    char* pos = "H7";
    int ret = solution(pos);

    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret);
}