#include <stdio.h>

long long calculate(long long mid){
	return mid*(mid + 1)*((2*mid) + 1)/6;
}

int main(){
	int t;
	long long m;
	scanf("%d", &t);
	for(int i = 0; i < t;i++){
		scanf("%lld", &m);
		
		long long left = 1, right = 10000000, result = 0;
		while(left <= right){
			long long mid = (right + left) / 2;
			long long sum = calculate(mid);
			if(sum >= m){
				result = mid;
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		
		printf("Case #%d: %d\n", i+1, result);
	}
	
	return 0;
}
