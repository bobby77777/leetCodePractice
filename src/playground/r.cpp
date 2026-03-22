#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100

typedef struct {
    double data[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool isFull(Stack* s) {
    return s->top == MAX_STACK_SIZE - 1;
}

bool push(Stack* s, double value) {
    if (isFull(s)) return false;
    s->data[++(s->top)] = value;
    return true;
}

bool pop(Stack* s, double* value) {
    if (isEmpty(s)) return false;
    *value = s->data[(s->top)--];
    return true;
}

bool isNumber(const char* token, bool* isInteger) {
    char* endptr;
    double val = strtod(token, &endptr);
    if (*endptr == '\0') {
        *isInteger = (strchr(token, '.') == NULL);
        return true;
    }
    return false;
}

double performOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                printf("Division by zero\n");
                exit(EXIT_FAILURE);
            }
            return a / b;
        default:
            printf("Invalid operator\n");
            exit(EXIT_FAILURE);
    }
}

void evaluatePostfix(char* expression) {
    Stack stack;
    initialize(&stack);
    char* token = strtok(expression, " ");
    
    while (token != NULL) {
        bool isInteger;
        if (isNumber(token, &isInteger)) {
            if (isInteger) {
                if (!push(&stack, atoi(token))) {
                    printf("Stack overflow\n");
                    return;
                }
            } else {
                if (!push(&stack, atof(token))) {
                    printf("Stack overflow\n");
                    return;
                }
            }
        } else if (strlen(token) == 1 && strchr("+-*/", token[0]) != NULL) {
            double a, b;
            if (!pop(&stack, &a) || !pop(&stack, &b)) {
                printf("Not enough operands\n");
                return;
            }
            push(&stack, performOperation(b, a, token[0]));
        } else {
            printf("Invalid operator\n");
            return;
        }
        token = strtok(NULL, " ");
    }

    if (stack.top != 0) {
        printf(stack.top == -1 ? "Not enough operands\n" : "Too many operands\n");
    } else {
        if (fmod(stack.data[stack.top], 1.0) == 0.0) {
            printf("%d\n", (int)stack.data[stack.top]);
        } else {
            printf("%lf\n", stack.data[stack.top]);
        }
    }
}

int main() {
    char expression[256];
    
    while (true) {
        if (fgets(expression, sizeof(expression), stdin) == NULL) {
            break;
        }

        // Remove trailing newline character
        expression[strcspn(expression, "\n")] = 0;

        if (strcmp(expression, "exit") == 0) {
            break;
        }

        evaluatePostfix(expression);
    }
    
    return 0;
}
