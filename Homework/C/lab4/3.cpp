#include<stdio.h>
int main(){
	int a,b,c,min,i=1;
	while(i<=6)
	{
	printf("请输入三个整数：");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)
		min=b;
	else
		min=a;
	if(min>c)
		min=c;
	printf("最小数为:%d\n",min);
	i++;
	}
} 
