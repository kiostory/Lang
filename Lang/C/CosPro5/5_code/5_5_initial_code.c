// ������ ���� include�� ����� �� �ֽ��ϴ�.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int enemies[], int enemies_len, int armies[], int armies_len) {
    // ���⿡ �ڵ带 �ۼ����ּ���.
    int answer = 0;
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