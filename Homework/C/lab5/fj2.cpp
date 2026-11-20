#include<stdio.h>
int main(){
	int i;
	double a=2,b=1,sum=0,temp;
	for(i=1;i<=20;i++){
		sum+=a/b;
		temp=a;
		a+=b;
		b=temp;
	}
	printf("sum=%.6f\n",sum);
	return 0;
}
