#include<stdio.h>
#include<math.h>
int main(){
	int sign =1,count=0;
	double pi=0,n=1.0,term=1.0;
	while(fabs(term)>=1e-6){
		pi=pi+term;
		count+=1;
		sign=-sign;
		n=n+2;
		term=sign/n;
	}
	pi=pi*4;
	printf("pi=%10.6f\n",pi);
	printf("count=%d\n",count);
	return 0;
}
