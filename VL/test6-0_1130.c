#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MaxNum 100
typedef struct {
    int top;
    char data[MaxNum];
}Stack;

Stack num, opera;

int Prior(char c)
{
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else if (c >= '0' && c <= '9') return 0;
    return -1;
}
void InitStack(Stack* S)
{
    S->top = -1;
}
void PushStack(Stack* S, char data)
{
    if (S->top != MaxNum - 1)
        S->data[++(S->top)] = data;
}
char PopStack(Stack* S)
{
    char num = 0;
    if (S->top != -1) {
        num = S->data[S->top];
        S->top--;
    }
    return num;
}
void CalculateExpression(Stack* S)
{
    long tmp[MaxNum], num1 = 0, num2 = 0;
    int tmp_index = 0, temp_index = 0;
    char temp[MaxNum];
    long result = 1;
    for (int i = 0; i <= S->top; i++) {
        if (Prior(S->data[i]) == 0) {
            temp[temp_index++] = S->data[i];
        }
        else if (S->data[i] == ' ') {
            tmp[tmp_index++] = atoi(temp);
            temp_index = 0;
            memset(temp, 0, MaxNum);
        }
        else if (Prior(S->data[i]) > 0) {
            
            num1 = tmp[--tmp_index];
            num2 = tmp[--tmp_index];
            switch (S->data[i]) {
            case '+':
                tmp[tmp_index++] = num2 + num1;
                break;
            case '-':
                tmp[tmp_index++] = num2 - num1;
                break;
            case '*':
                tmp[tmp_index++] = num2 * num1;
                break;
            case '/':
                tmp[tmp_index++] = num2 / num1;
                break;
            case '^':
                result = 1;
                for (int i = 0; i < num1; i++)
                    result *= num2;
                tmp[tmp_index++] = result;
                break;

            default: break;
            }

        }

    }
    printf("%ld\n", tmp[0]);

}
int main()
{
    char s[MaxNum];
    int len;

    //FILE* fp = fopen("in.txt", "r");/*以读模式("r")打开文件user.txt*/
    //fscanf(fp, "%s", s);

    scanf("%s", s);
    len = strlen(s);
    //printf("%s %d\n", s, len);
    InitStack(&num);
    InitStack(&opera);
    for (int i = 0; i < len; i++) {
        //printf("%c\n", s[i]);
        if (Prior(s[i]) == 0) {
            while (Prior(s[i]) == 0 && i < len)
                PushStack(&num, s[i++]);
            PushStack(&num, ' ');
        }
        if (s[i] == '(')
            PushStack(&opera, s[i]);
        if (Prior(s[i]) > 0) {
            if (opera.top == -1 || opera.data[opera.top] == '(' || Prior(s[i]) > Prior(opera.data[opera.top]))
                PushStack(&opera, s[i]);
            else {
                while (Prior(s[i]) <= Prior(opera.data[opera.top]))  PushStack(&num, PopStack(&opera));
                PushStack(&opera, s[i]);
            }

        }
        if (s[i] == ')') {
            while (opera.data[opera.top] != '(') {
                PushStack(&num, PopStack(&opera));
            }
            PopStack(&opera);
        }

    }

    while (opera.top != -1) {
        PushStack(&num, PopStack(&opera));
    }
    // for (int i = 0; i <= num.top; i++)
    //     printf("%c ", num.data[i]);
    CalculateExpression(&num);
    return 0;
}