//5��5
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return *(const int*)a - *(const int*)b;
}
int solution(int enemies[], int enemies_len, int armies[], int armies_len) {
	int answer = 0;

	qsort(enemies, enemies_len, sizeof(int), compare);
	qsort(armies, armies_len, sizeof(int), compare);
	int i = 0, j = 0;
	while(i < enemies_len && j < armies_len) {
		if(enemies[i] <= armies[j]) {
			answer++;
			i++;
			j++;
		} else {
			j++;
		}
	}

	return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
	int enemies1[] = { 1, 4, 3 };
	int enemies_len1 = 3;
	int armies1[] = { 1, 3 };
	int armies_len1 = 2;
	int ret1 = solution(enemies1, enemies_len1, armies1, armies_len1);

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret1);

	int enemies2[] = { 1, 1, 1 };
	int enemies_len2 = 3;
	int armies2[] = { 1, 2, 3, 4 };
	int armies_len2 = 4;
	int ret2 = solution(enemies2, enemies_len2, armies2, armies_len2);

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret2);
}