#include <stdio.h>

int main () {
	int n, largest;
	
	printf("Input number elements: ");
	scanf("%d", &n);
	
	int array[n];
	
	printf("Input %d elements:\n", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}
	
	largest = array[0];
	
	for(int i = 1; i < n; i++) {
		if(array[i] > largest) {
			largest = array[i];
		}
	}
	printf("Largest element is: %d\n", largest);

return 0;
}
