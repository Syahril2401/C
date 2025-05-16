#include <stdio.h>

int main() {
    int T; 
    scanf("%d", &T); 

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int N, K; 
        scanf("%d %d", &N, &K); 

        int count = 0; 
        for (int i = 0; i < N; i++) {
            int weight; 
            scanf("%d", &weight); 
            if (weight >= K) { 
                count++; 
            }
        }

        printf("Case #%d: %d\n", caseNum, count);
    }

    return 0;
}
