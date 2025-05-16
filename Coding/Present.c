#include <stdio.h>

int main() {
	int T;
	
	scanf("%d", &T);
	
	for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        
        int nilai[N];
        int max = 0;
        int count = 0; 
        
      
        for (int i = 0; i < N; i++) {
            scanf("%d", &nilai[i]);
            if (nilai[i] > max) {
                max = nilai[i]; 
                count = 1;     
            } else if (nilai[i] == max) {
                count++;    
            }
        }
        
       
        printf("Case #%d: %d\n", t, count);
    }
	
return 0;	
}
