#include <stdio.h>
#include <math.h>
int X(int t) {
    return t;
}
int Y(int t) {
    return 5 * cos(t);
}

void graph() {
    int n = 21;
    int half_n = (n - 1) / 2;
    printf("half_n: %d\n", half_n);
    char grid[n][n];
    int points[n][2];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            grid[r][c] = '.';
        }
    }
    for (int t = -half_n; t <= half_n; t ++) {
        int x = X(t);
        int y = Y(t);
        int r = half_n - y;
        int c = x + half_n;
        if (r >= 0 && r < n && c >= 0 && c < n) {
            grid[r][c] = '#';
        }
    }
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            printf(" %c ", grid[r][c]);
        }
        printf("\n");
    }
}
int main() {
  graph();
  return 0;
}