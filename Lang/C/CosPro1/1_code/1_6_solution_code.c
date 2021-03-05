#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(char* pos) {

	//움직임 가능한 셋트, 상대거리 이용
	int dx[] = { 1,1,-1,-1,2,2,-2,-2 };
	int dy[] = { 2,-2,-2,2,1,-1,-1,1 };
	int cx = pos[0] - 'A';  //숫자로 만들어
	int cy = pos[1] - '0' - 1;  // -1?
	int ans = 0;
	for (int i = 0; i < 8; ++i) {
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)  //in range >> 범위안에 있니?
			ans++;
	}
	return ans;
}

// The following is main function to output testcase.
int main() {
	char* pos = "A7";
	int ret = solution(pos);

	// Press Run button to receive output. 
	printf("Solution: return value of the function is %d .\n", ret);
}