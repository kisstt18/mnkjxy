#include<stdio.h>
#include<math.h>
int main(){
	int a,b,c;
	double area,s;
	printf("请输入三角形的第一条边："); 
	scanf("%d",&a);
	printf("请输入三角形的第二条边："); 
	scanf("%d",&b);
	printf("请输入三角形的第三条边："); 
	scanf("%d",&c);
	s=1.0/2*(a+b+c);
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("三角形的面积为：%lf",area);
}


