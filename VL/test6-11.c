# include<stdio.h>
# include<string.h>
// 算式的最长长度
# define MAX_LEN 50

int calc(int v1, char opera, int v2) {
    int res;
    switch (opera) {
        case '+':
            return v1+v2;
        case '-':
            return v1-v2;
        case '*':
            return v1*v2;
        case '/':
            return v1/v2;
        case '^':
            res = 1;
            for (int i=0; i<v2; i++) {
                res *= v1;
            }
            return res;
    }
}

int char_type(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    if (c>=48 && c<=57) return 0;
    return -1;
}

int main(void) {
    char str[MAX_LEN];
    scanf("%s", str);
    int len = strlen(str);

    char stack1[MAX_LEN] = ""; // 辅助栈
    char stack2[MAX_LEN] = ""; // 结果栈

    int stack1_top = 0;
    int stack2_top = 0;

    for (int i=0; i<strlen(str); i++) {
        if (char_type(str[i]) == 0) {
            while (char_type(str[i])==0 && i<len) {
                stack2[stack2_top++] = str[i++];
            }
            stack2[stack2_top++] = ' ';
        }
        if (str[i] == '(') {
            stack1[stack1_top++] = str[i];
        }
        if (char_type(str[i]) > 0) {
            if (stack1_top==0 || stack1[stack1_top-1]=='(' || char_type(str[i])>char_type(stack1[stack1_top-1])) {
                stack1[stack1_top++] = str[i];
            } else {
                while (char_type(stack1[stack1_top-1]) >= char_type(str[i])) {
                    stack2[stack2_top++] = stack1[--stack1_top];
                }
                stack1[stack1_top++] = str[i];
            }
        }
        if (str[i] == ')') {
            while (stack1[--stack1_top] != '(') {
                stack2[stack2_top++] = stack1[stack1_top];
            }
            stack1[stack1_top] = '\0';
        }
    }
    while (stack1_top) {
        stack2[stack2_top++] = stack1[--stack1_top];
    }

    printf("逆波兰式：%s\n", stack2);

    int calc_stack[MAX_LEN]; // 操作数栈
    int calc_stack_top=0;
    char temp[MAX_LEN]; // 用于char*到int的转换
    int temp_index = 0;
    memset(temp, 0, MAX_LEN);
    for (int i=0; i<stack2_top; i++) {
        if (char_type(stack2[i]) == 0) {
            temp[temp_index++] = stack2[i];
        } else if (stack2[i] == ' ') {
            calc_stack[calc_stack_top++] = atoi(temp);
            temp_index = 0;
            memset(temp, 0, MAX_LEN);
        } else {
            int v2 = calc_stack[--calc_stack_top];
            int v1 = calc_stack[--calc_stack_top];
            calc_stack[calc_stack_top++] = calc(v1, stack2[i], v2);
        }
    }

    printf("结果：%d\n", calc_stack[0]);
}