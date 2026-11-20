#include <stdio.h>
int main(){
    int x, m = 0, n = 0;
    printf("x=");
    scanf("%d", &x);
    while(n<5){
    	if(x%12==0||x%15==0){
            m+=x;
            n++;
        }
    	x--;
    }
    printf("sum=%d",m);
    return 0;
}

