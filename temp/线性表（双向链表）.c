#include<stdio.h>
#include<stdlib.h>

struct node{
	ElemType data;
	struct node *rlink,*llink;
};
typedef struct node *DNodeptr;
typedef struct node DNode;

//创建双向链表
DNodeptr initDLink(int n){
	int i;
	DNodeptr list,p;
	list=(DNodeptr)malloc(sizeof(DNode));
	read(list->data);
	list->llink=list;
	list->rlink=list;
	for (i=1;i<n;i++){
		p=(DNodeptr)malloc(sizeof(DNode));
		read(p->data);
		insertNode(list,p);
	}
	return list;
} 

//插入节点 
int insertDNode(DNodeptr list,ElemType x,ElemType item){
	int DNodeptr p,q;
	for (q=list;q!=list&&q->data!=x;q=q->rlink)
		if(q==list)
			return -1;
	p=(DNodeptr)malloc(sizeof(DNode));
	p->data=item;
	p->llink=q;
	p->rlink=q->rlink;
	q->rlink->llink=p;
	q->rlink=p;
	return 1;
}

//删除节点 
int deleteDNode(DNodeptr list,ElemType x){
	DNodeptr q;
	for (q=list;q!=list;q->data!=x;q=q->link)
	;
	if(q==list)
		return -1;
	q->llink->rlink=q->rlink;
	q->rlink->llink=q->llink;
	free(q);
	return 1;
}


int main(void){
	return 0;
} 
