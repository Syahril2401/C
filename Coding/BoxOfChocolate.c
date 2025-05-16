#include <stdio.h>

#define MAX_CHILDREN 500
#define MAX_CHOCOLATES 500

int main() {
    int T; 
    scanf("%d", &T);

    for (int case_num = 1; case_num <= T; case_num++) {
        int N, M;
        scanf("%d %d", &N, &M);

        long long total_weight = 0; 
        int weight;

        for (int i = 0; i < N; i++) {
            int max_weight = 0; 
            for (int j = 0; j < M; j++) {
                scanf("%d", &weight); 
                
                if (weight > max_weight) {
                    max_weight = weight; 
                }
            }
            total_weight += max_weight; 
        }
        printf("Case #%d: %lld\n", case_num, total_weight);
    }

    return 0;
}
