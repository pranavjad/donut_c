#include <stdio.h>
#include <math.h>
int f(int x) {
    return 5 * cos(x);
}
// int[] xy_to_rc(int x, int y, int n) {
//     int half_n = (n - 1) / 2;
//     return {x + half}
// }
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
    for (int x = -half_n; x <= half_n; x ++) {
        int i = x + half_n;
        printf("%d %d %d\n", x, i, half_n);
        points[i][0] = x;
        points[i][1] = f(x);
        // printf("(%d, %d)\n", points[i][0], points[i][1]);
        // printf("(%d, %d)\n", -points[i][1] + half_n, points[i][0] + half_n);
        // printf("%d\n", points[i][1]);
        int r = half_n - points[i][1];
        int c = points[i][0] + half_n;
        if (r >= 0 && r < n && c >= 0 && c < n) {
            grid[half_n - points[i][1]][points[i][0] + half_n] = '#';
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