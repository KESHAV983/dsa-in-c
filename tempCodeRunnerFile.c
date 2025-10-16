#include <stdio.h>
#include <ctype.h>

#define MAX 100

char st[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack full\n");
    } else {
        top++;
        st[top] = x;
    }
}

char pop() {
    if (top == -1) {
        return '\0';  // changed from -1 → better to return '\0' (a char)
    } else {
        char x = st[top];
        top--;
        return x;
    }
}

int prec(char x) {
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/' || x == '%')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main() {
    char in[100], post[100];
    int i = 0, j = 0;
    char ch;

    printf("Enter infix: ");
    scanf("%s", in);  // works for inputs without spaces

    while (in[i] != '\0') {
        ch = in[i];

        if (isalnum(ch)) {  // operand
            post[j] = ch;
            j++;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && st[top] != '(') {
                post[j] = pop();
                j++;
            }
            if (top != -1 && st[top] == '(')  // extra check for safety
                pop();
        } else {  // operator
            while (top != -1 && prec(st[top]) >= prec(ch)) {
                post[j] = pop();
                j++;
            }
            push(ch);
        }
        i++;
    }

    while (top != -1) {
        post[j] = pop();
        j++;
    }

    post[j] = '\0';

    printf("Postfix: %s\n", post);

    return 0;
}
