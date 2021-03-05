//5��8
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int func_a(int a, int b);
int func_b(int n);
int func_c(int p, int q);

int func_a(int a, int b) {
	int mod = a % b;

	while(mod > 0) {
		a = b;
		b = mod;
		mod = a % b;
	}

	return b;
}

int func_b(int n) {
	int answer = 0;

	for(int i = 1; i <= n; i++) {
		if(func_c(n, i))
			answer++;
	}

	return answer;
}

int func_c(int p, int q) {
	if(p % q == 0)
		return 1;
	else
		return 0;
}

int solution(int a, int b, int c) {
    int answer = 0;

    int gcd = func_a(func_a(a, b), c);
    answer = func_b(gcd);

    return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
	int a = 24;
	int b = 9;
	int c = 15;
	int ret = solution(a, b, c);

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret);
}