//#include<stdio.h>
//int main(){
//	
//	float score;
//	printf("请输入您的成绩：");
//	scanf("%f",&score);
//	
//	if(score<0 || score>100){
//		printf("不合理数据!");
//	}
//	else if(score>=90){
//		printf("A"); 
//	}
//	else if(score>=80){
//		printf("B"); 
//	}
//	else if(score>=70){
//		printf("C"); 
//	}
//	else if(score>=60){
//		printf("D"); 
//	}
//	else{
//		printf("E");
//	}
//}


#include<stdio.h>
int main(){
	float score;
	printf("请输入您的成绩：");
	scanf("%f",&score);
	if(score<0 || score>100){
		printf("不合理数据!");
		return 0;
	}
	switch((int)(score/10)){
		case 10:printf("A\n");break;
		case 9:printf("A\n");break;
		case 8:printf("B\n");break;
		case 7:printf("C\n");break;
		case 6:printf("D\n");break;
		default:printf("E\n");break;
	}	
	return 0;
}
















