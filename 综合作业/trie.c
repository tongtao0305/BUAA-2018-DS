#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义出错单词的结构
struct word{
	char string[100];
	int sum;
	int num[2000];
}wword[25001]; 
int temp=0,count=-1,count_total=0,count_words=-1,top=1;
int trie[10000000][26],selected[10000000];

//将单词插入到单词树中 
inline void insertnode(char *word){
	int i,j=1;
	for(i=0;word[i]!='\0';i++){
		if(!trie[j][word[i]-'a']){
			trie[j][word[i]-'a']=++top;
		}
		j=trie[j][word[i]-'a'];
	}
	selected[j]=1;
}
//在单词树中查找单词 
inline int searchnode(char *word){
	int i,j=1;
	for(i=0;word[i]!='\0';i++){
		if(!trie[j][word[i]-'a'])
			return 0;
		j=trie[j][word[i]-'a'];
	}
	if(selected[j]) 
		return 1;
	return 0;
}

int cmp( const void *a , const void *b ) { 
	struct word *c = (struct word *)a; 
	struct word *d = (struct word *)b; 
	if (c->sum<d->sum||(c->sum==d->sum&&strcmp(c->string,d->string)>0))
		return 1;
	else 
		return -1;
} 

int main(void){
	int i,j,k;
	char ch,s[51];
	FILE *fpdic,*fpin,*fpout;
	fpdic=fopen("dictionary.txt","r");
	fpin=fopen("article.txt","r");
	fpout=fopen("misspelling.txt","w");
	
	//将字典单词输入 
	while(fscanf(fpdic,"%s",s)!=EOF)
		insertnode(s);
	
	while((ch=fgetc(fpin))!=EOF){
		count_total++;
		if(ch>='A'&&ch<='Z'){
			s[++count]=ch-'A'+'a';
  		}
		else if(ch>='a'&&ch<='z'){
			s[++count]=ch;
		}
		else{
			if(count>-1){
				s[++count]='\0';
				if(!searchnode(s)){
					for (i=0;i<=count_words;i++)
						if (strcmp(s,wword[i].string)==0)
							break;
					if (i==count_words+1){
						count_words++;
						strcpy(wword[i].string,s);
						wword[i].sum=0;
						wword[i].num[wword[i].sum]=count_total;
					}
					else{
						wword[i].sum++;
						wword[i].num[wword[i].sum]=count_total;
					}
				}
			count=-1;
			}
		}
	}
	//快速排序并且输出 
	qsort(wword, count_words+1, sizeof(wword[0]), cmp);
	for (i=0;i<=count_words;i++){
		fprintf(fpout,"%s %d",wword[i].string,wword[i].sum+1);
		for (j=0;j<=wword[i].sum;j++)
			fprintf(fpout," %d",wword[i].num[j]-strlen(wword[i].string)-1);
		fprintf(fpout,"\n");
	}
	return 0;
}
