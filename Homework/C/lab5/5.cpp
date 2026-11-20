#include<stdio.h>
int main(){
	int a=1,i=1,s=0;	
	while(i<=101){
		s=s+i*a;
		a=-a;
		i+=2;
	}
	printf("%d",s);
	return 0;
}
