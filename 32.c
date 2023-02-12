#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200001

int b[MAX_N];
int g[MAX_N];

int compare(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}

int main() {
    int t, n, m, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        for (i = 0; i < m; i++) {
            scanf("%d", &g[i]);
        }
        qsort(b, n, sizeof(int), compare);
        qsort(g, m, sizeof(int), compare);
        j = 0;
        for (i = 0; i < m; i++) {
            if (j == n)
                break;
            if (g[i] < b[j]) {
                j++;
                continue;
            }
        }
        if (j == n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
