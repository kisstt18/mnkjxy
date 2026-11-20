#include<stdio.h>
int main(){
	int m,n,t,r,s;
	printf("请输入两个正整数：");
	scanf("%d%d",&m,&n);
	s=m*n;
	if(m<n){
		t=m;m=n;n=t;
	} 
	r=m%n;
	while(r!=0){
		m=n;
		n=r;
		r=m%n;
	}
	printf("最大公约数为：%d，最小公倍数为：%d",n,s/n);
	return 0;
}
