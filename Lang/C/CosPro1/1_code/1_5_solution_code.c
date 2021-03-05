#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int pane[103][103];  //���� �迭�ʱ�ȭ.    ó������ �ʱ�ȭ �Ǿ�������, �ι�° �����ÿ��� �ʱ�ȭ�� ���� �ʾ����� �ؾ��Ѵ�!!!!
int inRange(int i, int j, int n){
    return 0 <= i && i < n && 0 <= j && j < n;
}
//���Ÿ� ����?
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int solution(int n){
    int ci = 0, cj = 0;  //����i,j
    int num = 1;
    //pane�迭 �ʱ�ȭ
    int i, j; 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            pane[i][j] = 0;
        }
    }
//------------------------------------------------------------------
    while(inRange(ci, cj, n) && pane[ci][cj] == 0){
        for(int k = 0; k < 4; k++){
            if(!inRange(ci, cj, n) || pane[ci][cj] != 0) break;
            while(1){
                pane[ci][cj] = num++;
                int ni = ci + dy[k];
                int nj = cj + dx[k];
                if(!inRange(ni, nj, n) || pane[ni][nj] != 0){
                    ci += dy[(k + 1) % 4];
                    cj += dx[(k + 1) % 4];
                    break;
                } 
                ci = ni;
                cj = nj;
            }
        }
    }
//------------------------------------------------------------------
    int ans = 0;
    for(int i = 0; i < n; i++) ans += pane[i][i];
    return ans;
}

// The following is main function to output testcase.
int main() {
    int n1 = 3;
    int ret1 = solution(n1);

    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret1);

    int n2 = 2;
    int ret2 = solution(n2);

    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret2);
}