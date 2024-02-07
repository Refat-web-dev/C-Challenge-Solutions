#include <stdio.h>

/*----------------------------------------------------------
   Fibonacci example:

                int fibonacci(int a) {
                    if (a <= 1) {
                        return a;
                    }
                    printf("%d\n", a);
                    return fibonacci(a - 1);
                    printf("%d", fibonacci(21));
                }
----------------------------------------------------------*/

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
