#include <stdio.h>
/*----------------------------------------------------------------------
    Create a program src/quest3.c that calculates and outputs
    display the nth Fibonacci number using a recursive algorithm.
    The search for the nth Fibonacci number itself should be separated 
    into a separate function. The number is entered via standard input.
    When errors display “n/a”.


    | Input data | Output data |
    | ------ | ------ |
        | 21 | 10946 |

----------------------------------------------------------------------*/

/*----------------------------------------------------------
    
    Recursive function example:

                int recursive(int a) {
                    if (a <= 1) {
                        return a;
                    }
                    printf("%d\n", a);
                    return recursive(a - 1);
                    printf("%d", recursive(21));
                }

----------------------------------------------------------*/

/*-------------------------------------
    
    Option without recursive function

        int main() {
            int i, n;
            int t1 = 0, t2 = 1;
            int nextTerm = t1 + t2;

            scanf("%d", &n);
            for (i = 3; i <= n; ++i) {
                t1 = t2;
                t2 = nextTerm;
                nextTerm = t1 + t2;
            }
            printf("%d", nextTerm);

            return 0;
        }

-------------------------------------*/

int fibonacci(int a) {
    if (a <= 1) {
        return a;
    }
    return fibonacci(a - 1) + fibonacci(a - 2);
}

int main() {
    int n;

    if (!scanf("%d", &n)) {
        printf("n/a");
    } else {
        printf("%d", fibonacci(n));
    }

    return 0;
}