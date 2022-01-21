#include<stdio.h>

typedef struct node{
	datatype data;
	struct node *lchild, *rchild, *parent;
}BTNode, * BTREE;

//前序遍历二叉树 
void PREORDER(BTREE T){
	if (T!=NULL){
		VISIT(T);
		PREORDER(T->lchild);
		PREORDER(T->rchild);
	}
}

//以递归方式中序遍历二叉树 
void INORDER(BTREE T){
	if (T!=NULL){
		INORDER(T->lchild);	
		VISIT(T);
		INORDER(T->rchild);
	}
}

#define M 50
//以非递归方式中序遍历二叉树
void INORDER(BTREE T){
	BTREE STACK[M],p=T;
	int top=-1;
	if (T!=NULL)
		do{
			while(p!=NULL){
				STACK[++top]=p;
				p=p->lchild;
			}
			p=STACK[top--];
			VISIT(p);
			p=p->rchild;
		}while(!(p==NULL&&top==-1));
} 

//以递归方式后序遍历二叉树 
void POSTORDER(BTREE T){
	if (T!=NULL){
		POSTORDER(T->lchild);	
		POSTORDER(T->rchild);
		VISIT(T);	
	}
}

#define M 50
//以非递归方式后序遍历二叉树 
void POSTORDER(BTREE T){
	 BTREE STACK1[M],p=T;
	 int STACK2[M],flag,top=-1;
	 if (T!=NULL){
	 	do{
	 		while (p!=NULL){
	 			STACK[++top]=p;
	 			STACK2[top]=0;
	 			p=p->lchild;
			}
			p=STACK1[top];
			flag=STACK2[top--];
			if (flag==0){
				STACK1[++top]=p;
				STACK2[top]=1;
				p=p->rchild;
			}
			else{
				VISIY(p);
				p=NULL;
			}
		 }while(!(p==NULL&&top==-1));
	 }
}

#define M 50
//按层次遍历二叉树
void LAYERORDER(BTREE T){
	BTREE QUEUE[M],p;
	int front,rear;
	if (T!=NULL){
		QUEUE[0]=T;
		front =-1;
		rear=0;
		while(front<rear){
			p=QUEUE[++front];
			VISIT(p);
			if(p->lchild!=NULL)
				QUEUE[++rear]=p->lchild;
			if(p->rchild!=NULL)
				QUEUE[++rear]=p->rchild;
		}
	}
} 

//判断两棵二叉树是否相似
int SIMILAR(BTREE T1,BTREE T2){
	if (!T1&&!T2)
		return 1;
	if (T1&&T2
		&&SIMILAR(T1->lchild,T2->lchild)
		&&SIMILAR(T1->rchild,T2->rchild))
		return 1;
	return 0;
} 

//判断两棵二叉树是否等价
int EQUALBT(BTREE T1,BTREE T2){
	if (T1==NULL&&T2==NULL)
		return 1;
	if (T1!=NULL&&T2!=NULL&&T1->data==T2->data
		&&EQUALBT(T1->lchild,T2->lchild)
		&&EQUALBT(T1->rchild,T2->rchild))
		return 1;
	return 0;
} 
 

//二叉树的建立
void BUILDBT(BTREE T){
	char ch;
	scanf("%c",&ch);
	if (ch==' ')
		T=NULL;
	else{
		T(BTREE)malloc(sizeof(BTNode));
		T->data=ch;
		BUILDBT(T->lchild);
		BUILDBT(T->rchild); 
	}
} 

//二叉树的销毁
void DESTROYBT(BTREE T){
	if (T!=NULL){
		DESTROYBT(T->lchild);
		DESTROYBT(T->rchild);
		free(T);
	}
} 

void CLEARBT(BTREE T){
	DESTROYBT(T);
	T=NULL;
}

//二叉树的复制
BTREE COPYBT(BTREE T1){
	BTREE T2;
	if (T1==NULL)
		return NULL;
	else{
		T2=(BTREE)malloc(sizeof(BTNode));
		T2->data=T1->data;
		T2->lchild=COPYBT(T1->lchild);
		T2->rchild=COPYBT(T1->rchild);		
	}
	return T2;
} 

//求二叉树的深度
#define M 50
int DEPTHBT(BTREE T){
	BTREE STACK1[M],p=T;
	int STACK2[M];
	int curdepth,maxdepth=0,top=-1;
	if (T!=NULL){
		curdepth=1;
		do{
			while(p!=NULL){
				STACK1[++top]=p;
				STACK2[top]=curdepth;
				p=p->lchild;
				curdepth++;
			}
			p=STACK[top];
			curdepth=STACK2[top--];
			if (p->lchild==NULL&&p->rchild==NULL)
				if (curdepth>maxdepth)
					maxdepth=curdepth;
			p=p->rchild;
			curdepth++;
		}while(!(p==NULL&&top==-1));
	}
	return (maxdepth);
} 

//求节点所在的层次
#defien M 50
int LAYERBT(BTREE T,datatype item){
	BTREE STACK1[M],p=T;
	int STACK2[M],flag,top=-1;
	do{
		while(p!=NULL){
			STACK1[++top]=p;
			STACK2[top]=0;
			p=p->lchild;
		}
		p=STACK1[top];
		flag=STACK2[top--];
		if (flag==0){
			STACK1[++top]=p;
			STACK[top]=1;
			p=p->rchild;
		}
		else{
			if (p->data==item)
				return (top+2)
			p==NULL;
		}
	}while(!(p==NULL&&top==-1));
} 

//二叉树的删除
#define M 50
BTREE DELETEBT(BTREE T,datatype item){
	BTREE STACK[M],q,p=T;
	int top=-1;
	if (T->data==item){
		DESTROYBT(T);
		return NULL;
	}
	else{
		do{
			while(p!=NULL){
				if (p->data==item){
					if (q->lchild==p)
						q->lchild=NULL;
					else
						q->rchild=NULL;
					DESTROYBT(p);
					return T;
				}
				STACK[++top]=p;
				q=p;
				p=p->lchild;
			}
			p=STACK[top--];
			q=p;
			p=p->rchild;
		}while(!(p==NULL&&top==-1));
	}
} 

//交换所有结点的左右子树
#define M 50
void EXCHANGEBT(BTREE T){
	BTREE QUEUE[M],temp,p=T;
	int front,rear;
	if(T!=NULL){
		QUEUE[O]=T;
		front=-1;
		rear=0;
		while(front<rear){
			p=QUEUE[++front];
			temp=p->lchild;
			p->lchild=p->rchild;
			p->rchild=temp;
			if (p->lchild!=NULL)
				QUEUE[++rear]=p->lchild;
			if (p->rchild!=NULL)
				QUEUE[++rear]=p->rchild;
		}
	}
}

int main(void){
	return 0;
}
