#include<stdio.h>
int main(){
	int i=1,count1=0,count2=0,count3=0,count4=0;
	char a;
	printf("请输入一个字符：");
	scanf("%d",&a);
	while((a=getchar())!='\n'){
		
		if((a>='a'&&a<='z') || (a>='A'&&a<='Z')){
			count1++;}
		else if(a==' '){
			count2++;
		}
		else if(a>='0'&&a<='9'){
			count3++;}
		else{
			count4++;
		}
	}
	printf("英文单词：%d\n",count1);
	printf("空格：%d\n",count2);
	printf("数字：%d\n",count3);
	printf("其他字符:%d\n",count4); 
	return 0;
}
