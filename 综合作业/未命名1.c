#include<stdio.h>

int main(void){
	int i,j,k,type=0,result,count_total=-1;
	char c,word[100];
	
	FILE *fpdictionary,*fpin,*fpout;
	if ((fpin=fopen("article.txt","r"))==NULL){
		printf("Cannot open the article!\n");
		return 0;
	}	

	
	while ((c = fgetc(fpin)) != EOF){
		count_total++;
		printf("%d %c\n",count_total,c);
	}	
	
	return 0;
}
