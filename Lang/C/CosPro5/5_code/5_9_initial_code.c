#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int func_a(int stack[], int* stack_idx);
void func_b(int stack1[], int* stack1_idx, int stack2[], int* stack2_idx);
bool func_c(int stack_idx);

int func_a(int stack[], int* stack_idx) {
    int item = stack[*stack_idx];
    *stack_idx = *stack_idx - 1;
    return item;
}

void func_b(int stack1[], int* stack1_idx, int stack2[], int* stack2_idx) {
    while (!func_@@@(@@@)) {
        int item = func_@@@(@@@);
        *stack2_idx = *stack2_idx + 1;
        stack2[*stack2_idx] = item;
    }
}

bool func_c(int stack_idx) {
    return (stack_idx == -1);
}

int solution(int stack1[], int stack1_idx, int stack2[], int stack2_idx) {
    if (func_@@@(@@@)) {
        func_@@@(@@@);
    }
    int answer = func_@@@(@@@);
    return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
    int stack1_1[] = { 1,2,0,0,0,0,0,0,0,0 };
    int stack1_1len = 1;
    int stack2_1[] = { 3,4,0,0,0,0,0,0,0,0 };
    int stack2_1len = 1;
    int ret1 = solution(stack1_1, stack1_1len, stack2_1, stack2_1len);
    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret1);

    int stack1_2[] = { 1,2,3,0,0,0,0,0,0,0 };
    int stack1_2len = 2;
    int stack2_2[] = { 0,0,0,0,0,0,0,0,0,0 };
    int stack2_2len = -1;
    int ret2 = solution(stack1_2, stack1_2len, stack2_2, stack2_2len);
    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret2);
}