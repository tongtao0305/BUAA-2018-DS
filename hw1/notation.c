#include<stdio.h>
#include<string.h>

int main(void){
	char s[1000];
	int i,j,k,count=0,is_first=0;
	int start=-1,end=-1,pivot=-1;
	
	gets(s);
	
	for (i=0;s[i]!='\0';i++){
		if (s[i]>='1'&&s[i]<='9'){
			//标记有效数字结束位置 
			end=i;
			if (start==-1)
				//标记有效数字开始位置 
				start=i;
		}
		if (s[i]=='.')
			//标记小数点位置 
			pivot=i; 
	}
	
	if (pivot<start&&pivot!=-1){
		//如果没有整数部分
		 count=pivot-start;
	}
	else if (pivot==-1||pivot>end){
		//如果没有小数部分
		count=end-start; 
	}
	else{
		count=pivot-start-1;
	}
	
	for (i=start;i<=end;i++){
		if (is_first==0){
			putchar(s[i]);
			is_first=1;
			if (end!=start)
				printf(".");
		}
		else{
			if (s[i]>='0'&&s[i]<='9')
				putchar(s[i]);
		}
	}
	printf("e%d",count);
	
	return 0;
}
