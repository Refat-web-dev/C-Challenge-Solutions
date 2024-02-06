/*------------------------------------------------------------------------------------------
    Create an src/1948.c program that finds the largest prime divisor of any entered integer
    `a` and prints it to the screen. It is necessary to allocate a separate function for 
    calculating this value. Do not use division and the operation of taking the remainder of
    the division. However, if necessary, division can be realised by subtraction. For 
    errors, display "n/a".

    | Input | Output |
    | ------ | ------ |
    | 100 | 5 |
    | -4 | 2 |

------------------------------------------------------------------------------------------*/

#include <stdio.h>
int isRemainder(int num, int divider);
int divide(int num, int divider);

int main() {
    int a, i = 2;
    if (scanf("%d", &a)) {
        a = a < 0 ? a * -1 : a;
        while (i < a) {
            !isRemainder(a, i) ? a = divide(a, i) : i++;
        }
        printf("%d", a);
    } else {
        printf("n/a");
    }
}

int isRemainder(int num, int divider) {
    while (num >= divider) {
        num -= divider;
    }
    return num;
}

int divide(int num, int divider) {
    int res;
    for (res = 0; num >= divider; res++) {
        num -= divider;
    }
    return res;
}