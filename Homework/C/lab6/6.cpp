#include<stdio.h>
int main(){
	
	double m,h,sum;
	int n,i;
	scanf("%lf %d",&m,&n);
	sum=m;
	h=m;
	for(i=1;i<=n-1;i++){
		h=h/2;
		sum+=2*h;
	}
	h/=2;
	printf("%.2f %.2f",h,sum);
	return 0;
} 
