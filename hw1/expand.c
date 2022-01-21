#include<stdio.h>
#include<string.h>

int main(void){
	char last,next,s[1000];
	int i,j,k;
	
	gets(s);
	
	for (i=0;s[i]!='\0';i++){
		if (s[i]!='-'){
			printf("%c",s[i]);
		}
		else{
			last=s[i-1];
			next=s[i+1];
			if ('a'<=last&&last<='z'&&'a'<=next&&next<='z'&&last<next){
				for (j=last+1;j<next;j++)
					printf("%c",j);
			}
			else if ('A'<=last&&last<='Z'&&'A'<=next&&next<='Z'&&last<next){
				for (j=last+1;j<next;j++)
					printf("%c",j);
			}
			else if ('0'<=last&&last<='9'&&'0'<=next&&next<='9'&&last<next){
				for (j=last+1;j<next;j++)
					printf("%c",j);
			}
			else
				printf("-");
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
