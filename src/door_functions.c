/*---------------------------------------------------------------------------------------------------

    Create an src/door_functions.c program that calculates and displays a table with three functions:
    the witch of Agnesi with diameter one, the lemniscate of Bernoulli with a unit interval in the 
    positive half-plane (Y > 0), and a quadratic hyperbola. The first column should list the values 
    of the X-axis from minus Pi through plus Pi, there should be 42 measurements at this interval; 
    the second, third, and fourth columns describe the values ​​of the functions at a point. Table 
    headers are not needed. All values must be recorded with an accuracy of 7 decimal places, it 
    is necessary to use the double type for increased accuracy. Column separator: "|". The table
    should have a total of 42 entries. Put the result of the program in src/data/door_data.txt (no 
    need to add the function of creating a file from the program, you can use output redirection). 
    If the function is not defined at any point, there must be the "-" symbol in the table.

---------------------------------------------------------------------------------------------------*/

#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

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

int main() {
    FILE* fptr = fopen("data/door_data.txt", "w");
    if (fptr == NULL) {
        fprintf(stderr, "n/a");
        return 1;
    }
    for (int i = 0; i < 42; i++) {
        double x = -PI + i * 2 * PI / 41;
        fprintf(fptr, "%.7lf", x);
        fprintf(fptr, " | ");
        if (versiera(x) != -1) {
            fprintf(fptr, "%.7lf", versiera(x));
        } else {
            fprintf(fptr, " - ");
        }
        fprintf(fptr, " | ");

        if (lemniscate(x) != -1) {
            fprintf(fptr, "%.7lf", lemniscate(x));
        } else {
            fprintf(fptr, "-");
        }
        fprintf(fptr, " | ");

        if (hyperbola(x) != -1) {
            fprintf(fptr, "%.7lf", hyperbola(x));
        } else {
            fprintf(fptr, " - ");
        }
        if (i < 41) fprintf(fptr, "\n");
    }
    fclose(fptr);
    return 0;
}
