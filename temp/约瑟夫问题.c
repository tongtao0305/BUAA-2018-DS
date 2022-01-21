#include<stdio.h>
#include<stdlib.h>
//定义链表 
struct node{
	ElemType data;
	struct node *link;
}; 
typedef struct node *Nodeptr;
typedef struct node Node;
//约瑟夫函数 
void josephu(int n,int k,int m){
	Nodeptr list,p,r;
	int i;
	list=NULL;
	for (i=0;i<n;i++){
		r=(Nodeptr)malloc(sizeof(Node));
		r->data=i;
		if(list=NULL)
			list=p=r;
		else{
			p->link=r;
			p=p->link;
		}	
	}
	p->link=list;
	r=p;
	for (p=list,i=0;i<k-1;i++,r=p,p=p->link)
	;	//寻找到开始的第k个人 
	while(p->link!=p){
		for (i=0;i<m-i;i++){
			r=p;
			p=p->link;
		}
		r->link=p->link;
		printf("%3d",p->data);
		free(p);
		p=r->link;
	}
	printf("%3d",p->data);
}

int main(void){
	int n,k,m;
	scanf("%d %d %d",&n,&m,&k);
	josephu(n,m,k);
	return 0;
}
