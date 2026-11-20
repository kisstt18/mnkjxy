#include<stdio.h>
int main(){
	int a,b,c;
	long int u,n;
	float x,y,z;
	char c1,c2;
	
	a=3;b=478;c=-56;
	x=67.5678,y=2.4,z=-189.134;
	u=51274;n=123456;
	c1='a';
	
	printf("\n"); 
	printf("a=%2d b=%2d c=%2d\n",a,b,c);
	printf("x=8.6f,y=%8.6f,z=%9.6f\n",x,y,z);
	printf("x+y=%5.2f,y+z=%5.2f,z+x=%5.2f\n",x+y,y+z,z+x);
	printf("x=%-10f,y=%4f,z=%3f\n",x,y,z);
	printf("x=%e,y=%10.2e\n",x,y);
	printf("u=%6ld,n=%x\n",u,n);
	printf("c1=%c c1=%d(ASCII)\n",c1,c1);
	printf("%s,%5.3s\n","COMPUTER","COMPUTER");
	return 0;
}
