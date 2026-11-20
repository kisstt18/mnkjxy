#include<stdio.h>

int main(){
	int i,t=1;
	for(i=1;i<=10;i++){
		t*=i;
	}
	printf("10!=%d",t);
	return 0;
}
