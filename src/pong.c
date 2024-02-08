#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

#define HEIGHT 25
#define WIDTH 80

void drawArr(char arr[][WIDTH], int h, int w);
void initArr(char arr[][WIDTH], int h, int w, int y, int x, int plty, int plcy, int plby, int pltx, int plcx,
             int plbx, int prty, int prcy, int prby, int prtx, int prcx, int prbx);

int main() {
    int plScore = 0;
    int prScore = 0;

    char frame[HEIGHT][WIDTH];

    int x = WIDTH / 2 + 1;
    int y = HEIGHT / 2;

    int pltx = 1, plcx = 1, plbx = 1;
    int plty = HEIGHT / 2 - 1;
    int plcy = HEIGHT / 2;
    int plby = HEIGHT / 2 + 1;

    int prtx = WIDTH - 2, prcx = WIDTH - 2, prbx = WIDTH - 2;
    int prty = HEIGHT / 2 - 1;
    int prcy = HEIGHT / 2;
    int prby = HEIGHT / 2 + 1;

    char inp;

    int operationX = 1;
    int operationY = 1;

    system(CLEAR_COMMAND);

    initArr(frame, HEIGHT, WIDTH, y, x, plty, plcy, plby, pltx, plcx, plbx, prty, prcy, prby, prtx, prcx,
            prbx);
    drawArr(frame, HEIGHT, WIDTH);

    printf("right score: %d\n", plScore);
    printf("left score: %d\n", prScore);

    while (1) {
        scanf("%c", &inp);
        if (inp == ' ' || inp == '\n') {
            if (operationY == 1) {
                if (y < HEIGHT - 2) {
                    y++;
                } else {
                    operationY = 2;
                    y--;
                }
            } else {
                if (y > 1) {
                    y--;
                } else {
                    operationY = 1;
                    y++;
                }
            }
            if (operationX == 1) {
                if ((x >= prcx - 1 || x >= prtx - 1 || x >= prbx - 1) &&
                    (y == prcy || y == prty || y == prby)) {
                    operationX = 2;
                    x--;
                } else if (x <= WIDTH - 3) {
                    x++;
                } else {
                    operationX = 2;
                    prScore++;
                    if (prScore >= 3) {
                        system(CLEAR_COMMAND);
                        printf("right score: %d\n", plScore);
                        printf("left score: %d\n", prScore);
                        break;
                    }
                    x--;
                }
            } else {
                if ((x < plcx + 2 || x < pltx + 2 || x < plbx + 2) && (y == plby || y == plcy || y == plty)) {
                    operationX = 1;
                    x++;
                } else if (x > 1) {
                    x--;
                } else {
                    operationX = 1;
                    plScore++;
                    if (plScore >= 3) {
                        system(CLEAR_COMMAND);
                        printf("right score: %d\n", plScore);
                        printf("left score: %d\n", prScore);
                        break;
                    }
                    x++;
                }
            }
        } else if (inp == 'q') {
            system(CLEAR_COMMAND);
            printf("right score: %d\n", plScore);
            printf("left score: %d\n", prScore);
            break;
        } else if (inp == 'z') {
            if (plby <= HEIGHT - 3) {
                plty++;
                plcy++;
                plby++;
            }
        } else if (inp == 'a') {
            if (plty >= 2) {
                plty--;
                plcy--;
                plby--;
            }

        } else if (inp == 'm') {
            if (prby <= HEIGHT - 3) {
                prty++;
                prcy++;
                prby++;
            }
        } else if (inp == 'k') {
            if (prty >= 2) {
                prty--;
                prcy--;
                prby--;
            }
        }
        system(CLEAR_COMMAND);  // Clear the terminal

        initArr(frame, HEIGHT, WIDTH, y, x, plty, plcy, plby, pltx, plcx, plbx, prty, prcy, prby, prtx, prcx,
                prbx);
        drawArr(frame, HEIGHT, WIDTH);

        printf("right score: %d\n", plScore);
        printf("left score: %d\n", prScore);
    }
    return 0;
}

void drawArr(char arr[][WIDTH], int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int k = 0; k < w; k++) {
            printf("%c", arr[i][k]);
        }
        printf("\n");
    }
}

void initArr(char arr[][WIDTH], int h, int w, int y, int x, int plty, int plcy, int plby, int pltx, int plcx,
             int plbx, int prty, int prcy, int prby, int prtx, int prcx, int prbx) {
    for (int i = 0; i < h; i++) {
        for (int k = 0; k < w; k++) {
            if (i == h - 1) {
                arr[i][k] = '`';
            } else if (i == 0) {
                arr[i][k] = ',';
            } else if (k == 0 || k == w - 1) {
                arr[i][k] = '|';
            } else if (k == w / 2) {
                arr[i][k] = '-';
            } else if (i == y && k == x) {
                arr[i][k] = 'o';
            } else if ((i == prty || i == prcy || i == prby) && (k == prtx || k == prcx || k == prbx)) {
                arr[i][k] = ']';
            } else if ((i == plty || i == plcy || i == plby) && (k == pltx || k == plcx || k == plbx)) {
                arr[i][k] = '[';
            } else {
                arr[i][k] = ' ';
            }
        }
    }
}
