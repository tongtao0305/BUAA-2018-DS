#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//定义二叉树节点 
typedef struct node {
	char name[100];
	struct node *lchild, *rchild;
}BTNode, *BTREE;

/*
//按层次遍历二叉树
void LAYERORDER(BTREE T){
	BTREE QUEUE[100],p;
	int front,rear;
	if (T!=NULL){
		QUEUE[0]=T;
		front =-1;
		rear=0;
		while(front<rear){
			p=QUEUE[++front];
			printf("%s\n",p->name);
			if(p->lchild!=NULL)
				QUEUE[++rear]=p->lchild;
			if(p->rchild!=NULL)
				QUEUE[++rear]=p->rchild;
		}
	}
} 
*/

int main(void){
	FILE *fin;
	int n,rear=0,front=-1,top[3]={-1,-1,-1},i,j,k,stack_layer[3][100],flag,finish=0;
	char parent[100],lchild[100],rchild[100],name[3][100];
	BTREE root=NULL,queue[1000],stack[3][100];

	if ((fin=fopen("in.txt","r"))==NULL){
		printf("Cannot open the file!");
		return 1;
	}

	//读取数据并且建立二叉树 
	fscanf(fin,"%d",&n);
	while(n--){
		fscanf(fin,"%s %s %s",parent,lchild,rchild);
		
		//创建第一个节点 
		if (root==NULL){
			BTREE p,l,r;
			p=(BTREE)malloc(sizeof(BTNode));
			l=(BTREE)malloc(sizeof(BTNode));
			r=(BTREE)malloc(sizeof(BTNode));
			strcpy(l->name,lchild);l->lchild=NULL;l->rchild=NULL;
			strcpy(r->name,rchild);r->lchild=NULL;r->rchild=NULL;
			strcpy(p->name,parent);p->lchild=l;p->rchild=r;
			root=p;
			queue[++front]=root;
			queue[++front]=l;
			queue[++front]=r;
			continue;
		}
		
		while(strcmp(queue[rear]->name,parent)!=0)
			rear++;
		
		BTREE l,r;
		l=(BTREE)malloc(sizeof(BTNode));strcpy(l->name,lchild);l->lchild=NULL;l->rchild=NULL;queue[++front]=l;
		r=(BTREE)malloc(sizeof(BTNode));strcpy(r->name,rchild);r->lchild=NULL;r->rchild=NULL;queue[++front]=r;
		queue[rear]->lchild=l;queue[rear++]->rchild=r;
	}
	
	scanf("%s %s",name[1],name[2]);
	
	for (i=1;i<=2;i++){
		top[i]=-1;
		BTREE temp=root;
		do{
			while(temp!=NULL){
				stack[i][++top[i]]=temp;
				stack_layer[i][top[i]]=0;
				temp=temp->lchild;
			}
			temp=stack[i][top[i]];
			flag=stack_layer[i][top[i]--];
			if (flag==0){
				stack[i][++top[i]]=temp;
				stack_layer[i][top[i]]=1;
				temp=temp->rchild;
			}
			else{
				if (strcmp(temp->name,name[i])==0)
					break;
				temp=NULL;
			}
		}while(!(temp==NULL&&top[i]==-1));
	}
	
	//printf("%d %d\n",top[1],top[2]);
	
	if (top[1]<top[2]){
		printf("%s %s %d\n",name[2],name[1],top[2]-top[1]);
	}
	else if (top[1]>top[2]){
		printf("%s %s %d\n",name[1],name[2],top[1]-top[2]);
	}
	else{
		for (j=top[1];j>=0;j--){
			for (k=top[2];k>=0;k--){
				if (strcmp(stack[1][j]->name,stack[2][k]->name)==0){
					printf("%s %s %d\n",stack[1][j],name[1],top[1]-j+1);
					printf("%s %s %d\n",stack[2][k],name[2],top[2]-k+1);
					finish=1;
					break;
				}
			}
			if(finish==1)
				break;
		}
	}
	
	return 0;
}

