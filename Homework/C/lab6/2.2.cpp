#include<stdio.h>
#include<math.h>
int main(){
	int m,k,i;
	printf("1-100的全部素数有:");
	for(m=2;m<=100;m++){
		k=sqrt(m);
		for(i=2;i<=k;i++){
			if(m%i==0)break;
		}	
		if(i>k){
			printf("%d ",m);
		}
	}
	return 0;
}
