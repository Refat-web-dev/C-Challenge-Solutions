/*-------------------------------------------------------------------------

    Make the necessary additions to the src/door_functions.c program so it 
    draws the graphs of the calculated functions in the terminal using the 
    "\*" symbol. Scale on the X-axis – 42 markers; scale on the Y-axis – 
    21. The placement and rotation of the coordinate axes are not critical.
    Save the finished code in door_functions_print.c

-------------------------------------------------------------------------*/

#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

#define WIDTH 42
#define HEIGHT 21

double versiera(double x) {
    double result = 1 / (1 + x * x);
    return isnan(result) ? -1 : result;
}

double lemniscate(double x) {
    double result = sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
    return isnan(result) ? -1 : result;
}

double hyperbola(double x) {
    double result = 1 / (x * x);
    return isnan(result) ? -1 : result;
}

void printGraph(double (*function)(double)) {
    for (int y = HEIGHT; y >= 1; y--) {
        for (int x = 0; x < WIDTH; x++) {
            double xValue = -PI + x * 2 * PI / (WIDTH - 1);
            double yValue = function(xValue);
            if (yValue != -1 && (int)(yValue * HEIGHT) == y) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    printGraph(versiera);
    printGraph(lemniscate);
    printGraph(hyperbola);

    return 0;
}
