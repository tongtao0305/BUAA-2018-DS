#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void){
	char string1[100],string2[100];
	FILE *fpin1,*fpin2;
	int count=0;
	 
	fpin1=fopen("tt.txt","r");
	fpin2=fopen("djz.txt","r");
	//fgets(string1,BUFSIZ,fpin1);
	//fgets(string2,BUFSIZ,fpin2);
	//printf("%s\n%s",string1,string2);
	
	while((fgets(string1,BUFSIZ,fpin1)!=EOF)&&(fgets(string2,BUFSIZ,fpin2)!=EOF)){
		if (strcmp(string1,string2)!=0){
			printf("%s %s\n",string1,string2);
			count++;
		}
	}
	
	printf("%d",count);
	
	return 0;
}
