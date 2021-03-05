// ������ ���� include�� ����� �� �ֽ��ϴ�.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//*** �����ذ��� ���� ������ ***
//1. �־��� ������ ���ڼ��ڸ� �켱 10������ �ٲ�
//2. �ٲ� �� ���ڸ� ���ϱ��Ͽ� �ٲ� ������ ��ȯ

char* solution(char* s1, char* s2, int p, int q) {
    int num1 = parse_decimal(s1, p);    // ���޹��� p������ ���ڼ��ڸ� parse_decimal�� ���� 10���� ���ڷ� ��ȯ
    int num2 = parse_decimal(s2, p);    // ��
    char* answer = convert_scale(num1 + num2, q);    //���ϱ� �� 10�����ڸ� ���ϴ� ������ ��ȯ�ϴ� convert_scale ȣ�� 
    return answer;
}

//1. �־��� ������ ���ڼ��ڸ� �켱 10������ �ٲ�
int parse_decimal(char* s, int p) {
    int num = 0;    // ������ 10���� ����
    for (int i = strlen(s) - 1, mul = 1; i >= 0; i--, mul *= p)    //���ڼ����� ������ ������ ���ھ� 10����ȭ, mul�� �ڸ����� p������ �ش��ϴ� 10�������� ����ϱ� ���� ��
        num += char_to_int(s[i]) * mul;    // ���ڼ��ڸ� ���ں� 10����ȭ�ؼ� p������ �ڸ����� ���Ͽ� 10����ȭ
    return num;
}

//1. �־��� ������ ���ڼ��ڸ� �켱 10������ �ٲ�
//���ڼ��ڸ� ���ڷ� ��ȯ�ϱ� ���� �غ�1 : ������ҹ�ȣ�� ������ �����ΰ� ����
int numbers_int[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
char* numbers_char = "0123456789";

const int char_to_int(char ch) {    //���ڼ��� �������ڸ� numbers_char ����� ���ؼ� ������ �� ��Ҽ����� �ش��ϴ� numbers_int��Ҹ� ��ȯ
    for (int i = 0; i < 10; i++)
        if (ch == numbers_char[i])
            return numbers_int[i];
}




//2. �ٲ� �� ���ڸ� ���ϱ��Ͽ� �ٲ� ������ ��ȯ // !!!!!!!!!!!!!!!!!!!!!!!! ����Լ�..
char* convert_scale(int num, int q) {
    if (num == 0) return "";
    char* s2 = convert_scale(num / q, q);
    char* s = (char*)malloc(sizeof(char) * (strlen(s2) + 2));
    strcpy(s, s2);
    s[strlen(s2)] = int_to_char(num % q);
    s[strlen(s2) + 1] = 0;
    return s;
}


// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
    char* s1 = "112001";
    char* s2 = "12010";
    int p = 3;
    int q = 8;
    char* ret = solution(s1, s2, p, q);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %s �Դϴ�.\n", ret);
}