#include<stdio.h>
int main(){
	int i=1,t=1;
	while(i<=10){
		t*=i;
		i++;
	}
	printf("10!=%d",t);
	return 0;
}
