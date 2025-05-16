#include <stdio.h>
#include <math.h>

int main(){
	int testcase;
	scanf("%d", &testcase);
	
	for(int i = 0; i < testcase; i++){
		int input;
		scanf("%d", &input);
		
		long long int hasil = pow(2, input) - 1;
		printf("Case #%d: %lld\n", i+1, hasil);
	}
	return 0;
}
