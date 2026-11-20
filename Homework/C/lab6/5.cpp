#include<stdio.h>
int main(){
	
	int n,i,sum=0;
	printf("请输入一个最大值：");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(i%2==0)
			 continue;
		else
			sum+=i;
	}
	printf("所有奇数之和为：%d",sum); 
	return 0;
}
