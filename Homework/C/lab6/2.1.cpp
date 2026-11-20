#include<stdio.h>
#include<math.h>
int main(){
	int m,k,i;
	scanf("%d",&m);
	k=sqrt(m);
	for(i=2;i<=k;i++)
		if(m%i==0)break;
	if(i>k)
		printf("%d是一个素数。\n",m);
	return 0;
}
