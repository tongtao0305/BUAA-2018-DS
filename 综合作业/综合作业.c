#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//��������ʵĽṹ
struct word{
	char string[100];
	int sum;
	int num[3000];
}wword[30000]; 

//����hash���ҽṹ 
typedef struct hashnode{
	char string[100];
	struct hashnode *link;
}node,*nodeptr;
nodeptr symtub[10000005];


int hash(const char* str)
{
   unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
   unsigned int hash = 0;
   unsigned int i    = 0;
	int len=strlen(str);

   for(i = 0; i < len; str++, i++)
   {
      hash = (hash * seed) + (*str);
   }

   return hash%10000000;
}
/*
int hash(const char* str)
{
   unsigned int hash = 5381;
   unsigned int i    = 0;
   int len=strlen(str);

   for(i = 0; i < len; str++, i++)
   {
      hash = ((hash << 5) + hash) + (*str);
   }

   return hash%10000000;
}
*/

void insertnode(char string[]){
	nodeptr n,r=symtub[hash(string)];
	n=(nodeptr)malloc(sizeof(node));
	strcpy(n->string,string);
	n->link=NULL;
	if (r==NULL)
		symtub[hash(string)]=n;
	else{
		while(r->link!=NULL)
			r=r->link;
		r->link=n;
	}
	return;
}

int searchnode(char string[]){
	nodeptr r=symtub[hash(string)];
	if (r==NULL)
		return 0;
	else {
		while (r != NULL) {
			if (strcmp(string, r->string) == 0)
				return 1;
			else
				r = r->link;
		}
	}
	return 0;
}

int cmp( const void *a , const void *b ) 
{ 
	struct word *c = (struct word *)a; 
	struct word *d = (struct word *)b; 
	if (c->sum<d->sum||(c->sum==d->sum&&strcmp(c->string,d->string)>0))
		return 1;
	else return -1;
} 

int main(void){
	int i,j,k,count_words=-1,count=-1,count_total=-1;
	char c,word[100];
	
	FILE *fpdictionary,*fpin,*fpout;
	fpdictionary=fopen("dictionary.txt","r");
	fpin=fopen("article.txt","r");
	fpout=fopen("misspelling.txt","w");
	
	//��ȡ����
	while((fscanf(fpdictionary,"%s",word))!=EOF)
		insertnode(word);
	
	while ((c = fgetc(fpin)) != EOF){
		count_total++;
		if(c>='A'&&c<='Z')
			word[++count]=c-'A'+'a';
		else if(c>='a'&&c<='z')
			word[++count]=c;
		else{
			if(count>=0){
				word[++count]='\0';
				count=-1;
				if (searchnode(word)==0){
					for (i=0;i<=count_words;i++)
						if (strcmp(word,wword[i].string)==0)
							break;
					if (i==count_words+1){
						count_words++;
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
	}

	//�������� 
	qsort(wword, count_words+1, sizeof(wword[0]), cmp);

	for (i=0;i<=count_words;i++){
		fprintf(fpout,"%s %d",wword[i].string,wword[i].sum+1);
		for (j=0;j<=wword[i].sum;j++)
			fprintf(fpout," %d",wword[i].num[j]-strlen(wword[i].string));
		fprintf(fpout,"\n");
	}
	
	return 0;
}

/*
�ֵ���С��  ������450000��
�����ı���С��������1200000��
���������������������25000��
���������Ƶ�ʣ�������2000��
������󳤶ȣ�������50���ַ�
*/
