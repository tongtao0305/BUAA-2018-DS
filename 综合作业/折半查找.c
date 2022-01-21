#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//定义出错单词的结构
struct word{
	char string[100];
	int sum;
	int num[3000];
}wword[30000]; 
char dictionary[450000][50];
int count_words=-1,count_wrong=-1,count_total=-1;

int cmp( const void *a , const void *b ) 
{ 
	struct word *c = (struct word *)a; 
	struct word *d = (struct word *)b; 
	
	if (c->sum<d->sum||(c->sum==d->sum&&strcmp(c->string,d->string)>0))
		return 1;
	else return -1;
	
	//if(c->sum != d->sum) return c->sum - d->sum; 
	//else return strcmp(c->string,d->string); 
} 

void lower(char word[100]) {
	int i;
	char temp[100];
	strcpy(temp, word);
	for (i = 0; i < strlen(temp); i++) {
		if (65 <= temp[i] && temp[i] <= 90)
			temp[i] += 32;
	}
	if (!isalpha(word[strlen(word) - 1])) {
		strncpy(word, temp, strlen(word) - 1);
		word[strlen(word) - 1] = '\0';
	}
	else {
		strncpy(word, temp, strlen(word));
		word[strlen(word)] = '\0';
	}
}

//折半查找 
int halfsearch(char string[]){
	int i=0,j=count_words,mid;
	while(i<=j){
		mid=(i+j)/2;
		if (strcmp(string,dictionary[mid])==0)
			return 1;
		else if (strcmp(string,dictionary[mid])>0)
			i=mid+1;
		else if (strcmp(string,dictionary[mid])<0)
			j=mid-1;
	}
	return 0;
}

int main(void){
	char c,word[100];
	int i,j,k,count=-1;
	
	FILE *fpdictionary,*fpin,*fpout;
	if ((fpdictionary=fopen("dictionary.txt","r"))==NULL){
		printf("Cannot open the dictionary!\n");
		return 0;
	}
	if ((fpin=fopen("article.txt","r"))==NULL){
		printf("Cannot open the article!\n");
		return 0;
	}	
	if ((fpout=fopen("misspelling.txt","w"))==NULL){
		printf("Cannot open the article!\n");
		return 0;
	}	
	
	//读取单词
	while((fscanf(fpdictionary,"%s",word))!=EOF)
		strcpy(dictionary[++count_words],word);

	while ((c = fgetc(fpin)) != EOF){
		count_total++;
		if (isalpha(c)) {
			word[++count] = c;
			continue;
		}
		else if (count!=-1){
			word[++count] = '\0';
			count = -1;
			lower(word);
			if (halfsearch(word)==0){
				for (i=0;i<=count_wrong;i++)
					if (strcmp(word,wword[i].string)==0)
						break;
				if (i==count_wrong+1){
					count_wrong++;
					strcpy(wword[i].string,word);
					wword[i].sum=0;
					wword[i].num[wword[i].sum]=count_total;
				}
				else{
					wword[i].sum++;
					wword[i].num[wword[i].sum]=count_total;
				}
			}
		}
	}
	//快速排序 
	qsort(wword, count_wrong+1, sizeof(wword[0]), cmp);
	
	/*
	struct word temp;
	//int flag=0;
	for (i=0;i<count_wrong;i++){
		//flag=0;
		for (j=count_wrong;j>i;j--){
			if (wword[j].sum>wword[i].sum||(wword[j].sum==wword[i].sum&&strcmp(wword[j].string,wword[i].string)<0)){
				temp=wword[j];
				wword[j]=wword[i];
				wword[i]=temp;
			//	flag=1;
			}
		}
	//	if (flag==0)
		//	break;
	}
	*/
	
	
	for (i=0;i<=count_wrong;i++){
		fprintf(fpout,"%s %d",wword[i].string,wword[i].sum+1);
		for (j=0;j<=wword[i].sum;j++)
			fprintf(fpout," %d",wword[i].num[j]-strlen(wword[i].string));
		fprintf(fpout,"\n");
	}
	
	/*
	for (i=0;i<=count_wrong;i++){
		printf("%s %d",wword[i].string,wword[i].sum+1);
		for (j=0;j<=wword[i].sum;j++)
			printf(" %d",wword[i].num[j]-strlen(wword[i].string));
		printf("\n");
	}
	*/
	
	return 0;
}
