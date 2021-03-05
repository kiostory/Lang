#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int number) {
    char* answer = "";

    int number_count[10] = { 0, };
    while (number > 0) {
        number_count[number % 10]++;
        number /= 10;
    }

    int len = 0;
    for (int i = 0; i < 10; i++)
        if (number_count[i] != 0)
            len++;

    answer = (char*)malloc(2 * len * sizeof(char) + 1);
    int index = 0;
    for (int i = 0; i < 10; i++)
        if (number_count[i] != 0) {
            answer[index++] = i + '0';
            answer[index++] = number_count[i] + '0';
        }
    answer[index] = '\0';

    return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�. �Ʒ����� �߸��� �κ��� ������, ���� �ڵ常 �����ϼ���.
int main() {
    int number1 = 2433;
    char* ret1 = solution(number1);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %s �Դϴ�.\n", ret1);

    int number2 = 662244;
    char* ret2 = solution(number2);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %s �Դϴ�.\n", ret2);
}