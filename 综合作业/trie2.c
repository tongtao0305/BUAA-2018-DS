#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef long long ll;
int temp=0,count=-1,count_total=0,tot1=0,top1=1;
int trie1[10000000][26];
int selected[10000000];

//将单词插入到单词树中 
inline void insertdic(char *word){
	int i,j=1;
	for(i=0;word[i]!='\0';i++){
		if(!trie1[j][word[i]-'a']){
			trie1[j][word[i]-'a']=++top1;
		}
	j=trie1[j][word[i]-'a'];
	}
	selected[j]=1;
}
//在单词树中查找单词 
inline int find(char *word){
	int i,j=1;
	for(i=0;word[i]!='\0';i++){
		if(!trie1[j][word[i]-'a'])
			return 0;
		j=trie1[j][word[i]-'a'];
	}
	if(selected[j]) 
		return 1;
	return 0;
}

int tot=1,top=1;
struct node{
	int num;
	char s0[55];
	int s1[2001];
}b[25011];
int trie[1000000][26],p[1000000];

inline void insert(char str[]){
	int k=1,i;
	for(i=0;i<strlen(str);i++){
		int temp0=str[i]-'a';
		if(!trie[k][temp0]){
			trie[k][temp0]=++tot;
		}
	k=trie[k][temp0];
	}
	if(!p[k]){
		p[k]=top++;
		strcpy(b[p[k]].s0,str);
	}
	b[p[k]].num++;
	b[p[k]].s1[b[p[k]].num-1]=count_total-count-1;
}

int cmp( const void *ab , const void *b) { 
	struct node *c = (struct node *)ab; 
	struct node *d = (struct node *)b; 
	if(c->num == d->num) return strcmp(c->s0,d->s0); 
	else return d->num-c->num; 
}  


int main(void){
	int i;
	char ch,s[51];
	FILE *fpdic,*fpin,*fpout;
	fpdic=fopen("dictionary.txt","r");
	fpin=fopen("article.txt","r");
	fpout=fopen("misspelling.txt","w");
	
	//将字典单词输入 
	while(fscanf(fpdic,"%s",s)!=EOF)
		insertdic(s);
	
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
				if(!find(s)){
					insert(s);
				}
			count=-1;
			}
		}
	}
	qsort(b+1,tot,sizeof(b[0]),cmp);
	int j;
	for(i=1;i<top;i++){
		fprintf(fpout,"%s %d ",b[i].s0,b[i].num);
		for(j=0;j<b[i].num;j++)
			fprintf(fpout,"%d%c",b[i].s1[j],j==b[i].num-1?'\n':' ');
	}
	return 0;
}

