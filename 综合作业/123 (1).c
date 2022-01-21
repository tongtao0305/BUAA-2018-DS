#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef long long ll;
struct Hash{
	char op[55];
	struct Hash *next;
	int used;
};
int used1[60000010];
struct Hash *h[60000001];
struct Hash tmp1[60000000]; 
int temp=0;
int temp2=0;
int temp1=0;
ll hash(char x[]){
	int i;
	ll ans=0;
	for(i=0;i<strlen(x);i++){
		ans=(ans*131+x[i]-'a'+1)%60000001;
	}
	return ans;
} 
int tot1=0;
inline void insert1(char str[],int x){
	if(!used1[x]){
		h[x]=&tmp1[++tot1];
		used1[x]=1;
	}
	struct Hash *root=h[x];
	while(root->used){
		root=root->next;
	}
	strcpy(root->op,str);
	root->next=&tmp1[++tot1];
	root->used=1;
}
inline int find(char str[]){
	int ha=hash(str);
	if(used1[ha]==0) return 0;
	struct Hash *root=h[ha];
	while(root->used){
		if(strcmp(root->op,str)==0) return 1;
		if(strcmp(root->op,str)>0) return 0;
		if(strcmp(root->op,str)<0) root=root->next;
	}
	return 0;
}
int tot=1;
struct node{
	int num;
	char s0[55];
	int s1[2001];
}b[25011];
int trie[1000000][26];
int p[1000000];
int top=1;
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
	b[p[k]].s1[b[p[k]].num-1]=temp2-temp1-1;
}
int cmp( const void *ab , const void *b ) 
{ 
struct node *c = (struct node *)ab; 
struct node *d = (struct node *)b; 
if(c->num == d->num) return strcmp(c->s0,d->s0); 
else return d->num-c->num; 
} 	
int main(){
	char a[55];
char s[55];
	FILE *in,*in1,*out;
	in=fopen("dictionary.txt","r");
	in1=fopen("article.txt","r");
	out=fopen("misspelling.txt","w");
	char ch;
	while(fscanf(in,"%s",a)!=EOF){
		int yx=hash(a);
		insert1(a,yx);
	}
	int i;
	temp1=0;
	temp2=0;
	while((ch=fgetc(in1))!=EOF){
		temp2++;
		if(ch>='A'&&ch<='Z'){
			s[temp1++]=ch-'A'+'a';
		}
		else if(ch>='a'&&ch<='z'){
			s[temp1++]=ch;
		}
		else{
			if(temp1>0){
				s[temp1]='\0';
				if(!find(s)){
					insert(s);
				}
				temp1=0;
			}
		}
	}
	qsort(b+1,tot,sizeof(b[0]),cmp);
	int j;
	for(i=1;i<top;i++){
		fprintf(out,"%s %d ",b[i].s0,b[i].num);
		for(j=0;j<b[i].num;j++)
		fprintf(out,"%d%c",b[i].s1[j],j==b[i].num-1?'\n':' ');
	}
	fclose(in);
	fclose(out);
	fclose(in1);
	return 0;
}




