#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int numbers[], int i, int j) {
	int tmp = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = tmp;
}

int compare(const void* a, const void* b) {
	return *(const int*)a - *(const int*)b;
}

int* solution(int numbers[], int numbers_len) {
	int* answer;

	qsort(numbers, numbers_len, sizeof(int), compare);
	int mid = (numbers_len -1) / 2;
	swap(numbers, mid, numbers_len - 1);

	int left = mid + 1;
	int right = numbers_len - 2;    //kioeom -1���� -2�� ����
	while (left <= right) {
		swap(numbers, left, right);
		left = left + 1;
		right = right - 1;
	}

	answer = numbers;
	return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�. �Ʒ����� �߸��� �κ��� ������ ���� �ڵ常 �����ϼ���.
int main() {
	int numbers[] = { 7, 3, 4, 1, 2, 5, 6, 8, 9, 10 };
	int numbers_len = 10;
	int* ret = solution(numbers, numbers_len);

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	printf("solution �Լ��� ��ȯ ���� {");
	for (int i = 0; i < numbers_len; i++) {
		if (i != 0)
			printf(", ");
		printf("%d", ret[i]);
	}
	printf("} �Դϴ�.");
}