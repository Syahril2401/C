#include <stdio.h>

int main()
{
    int N, i, j, x, y, z;
    
    scanf("%d", &N);
    
    int kamar[N];
    for(i = 0; i < N; i++){
        scanf("%d", &kamar[i]);
    }
    
    y = 0;
    
    for(j = 0; j < N; j++){
        
        z = 0;
        for(x = 0; x < j; x++){
            if(kamar[j] == kamar[x]){
                z = 1;
                break;
            }
        }
        if(z != 1){
            y++;
        }
    }
    printf("%d\n", y);
    
    return 0;
}

