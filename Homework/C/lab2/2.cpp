#include<stdio.h>

int main(){
	char c1='a',c2='b',c3='c',c4='\101',c5='\x42';
	printf("\"%c\",b=%c\tabc=%d\n",c1,c2,c3);
	printf("\t\b%c %c\n",c4,c5);
	return 0;
}
