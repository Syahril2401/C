#include <stdio.h>

int main () {
	int n;
	
	scanf("%d", &n);
	
	switch (n) {
		case 1:
			printf("The number is 1\n");
			break;
		case 2:
			printf("The number is 2\n");
			break;
		default:
			printf("The number is not 1 or 2\n");
			break;
	}
	
return 0;	
}
