//#include<stdio.h>
//
//int main(){
//	int num=1;
//	if(num=0)
//		printf("111");
//	else if(num)
//		printf("222");
//	else if(!num)
//		printf("333");
//	else
//		printf("444");
//	printf("\n");
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int a=3,s=5;
//	switch(a){
//		case 5:
//			s+=2;
//		case 3:
//			s+=5;
//		case 8:
//			s+=7;
//		defult:
//			s+=8;
//			break;
//	}
//	printf("%d\n",s);
//	return 0;
//}


#include<stdio.h>
int main(){
	int a=-1,b=-2,c=-3,k;
	if(a<0)
		k=100;
	if(b<0)
		if(c<0)
			k=200;
		else
			k=300;
	printf("%d\n",k);
	return 0;
}










