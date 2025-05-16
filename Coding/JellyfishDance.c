#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int views[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &views[i]);
    }

    int Q;
    scanf("%d", &Q);

    for (int i = 1; i <= Q; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);

        int views_total = 0;
        
        for (int j = X - 1; j < Y; j++) {s
            views_total += views[j]; 
        }

        printf("Case #%d: %d\n", i, views_total);
    }

    return 0;
}

