#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
	
	for (int i = 1; i <= T; i++) {
		int N, M;
		scanf("%d %d", &N, &M);
		int total_cost = 0;
		
	for (int j = 0; j < N; j++){
		int price;
		scanf("%d", &price);
		total_cost += price;
	    }
	
	if (total_cost > M) {
		printf("Case #%d: Wash dishes\n", i);
	} else {
		printf("Case #%d: No worries\n", i);
	}
}

return 0;    
}

