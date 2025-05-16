#include <stdio.h>

void calculate_leaf_sums(int index, int current_sum, int N, int A[], int leaf_sums[], int *leaf_count) {
	if (index > N) {
		return;
	}
	
	current_sum +=  A[index - 1];
	int left_index = 2 * index;
	int right_index = 2 * index + 1;
	
	if(left_index > N && right_index > N) {
		leaf_sums[*leaf_count] = current_sum;
		(*leaf_count)++;
	} else {
	calculate_leaf_sums(left_index, current_sum, N, A, leaf_sums,leaf_count);
	calculate_leaf_sums(right_index, current_sum, N, A, leaf_sums, leaf_count);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	
	for( int case_number = 1; case_number <= T; case_number++) {
		int N;
		scanf("%d", &N);
		
		int A[N];
		for(int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		
		int leaf_sums[N];
		int leaf_count = 0;
		
		calculate_leaf_sums(1, 0, N, A, leaf_sums, &leaf_count);
		printf("Case #%d:\n", case_number);
		for(int i = 0; i < leaf_count; i++) {
			printf("%d\n", leaf_sums[i]);
		}
	}
	return 0;
}
