#include<stdio.h>
int main(){
	int i,bai,shi,ge;
	for(i=100;i<=999;i++){
		bai=i/100;
		shi=i/10%10;
		ge=i%10;
		if(bai*bai*bai+shi*shi*shi+ge*ge*ge==i)
			printf("%d是水仙花数\n",i); 
	} 
}
