#include<stdio.h>
#include<string.h>

int MIN(int a,int b) {return a<b?a:b;}

int main(void){
	char num1[100],num2[100],*p1,*p2,*p3; 
	int len1,len2,len3,i,j,k;
	
	gets(num1);
	gets(num2);
	p1=num1;
	p2=num2;
	
	while(*p1=='0')
		p1++;
	len1=strlen(p1);
	
	while(*p2=='0')
		p2++;		
	len2=strlen(p2);
	
	if (strcmp(p1,p2)==0){
		printf("0\n");
		return 0;
	}
	else if ((len1==len2&&strcmp(p1,p2)<0)||(len1<len2)){
		printf("-");
		p3=p1;
		p1=p2;
		p2=p3;
		len3=len1;
		len1=len2;
		len2=len3;
	}

	for (i=0;i<MIN(len1,len2);i++){
		p1[len1-1-i]-=p2[len2-1-i]-'0';
	}	
	
	for (i=0;i<=len1;i++){
		if(p1[len1-1-i]<'0'){
			p1[len1-1-i]+=10;
			p1[len1-2-i]-=1;
		}
	}	
	
	while(*p1=='0')
		p1++;

	puts(p1);
	
	return 0;
}
